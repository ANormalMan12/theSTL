#pragma once
#include<iostream>
#include<climits>
#include<cfloat>
#include"TreeBase.h"

namespace theSTL{
    struct interval{
        double l,r;
        bool operator<(const interval& ano)const{
            return l<ano.l;
        }
        friend std::ostream& operator<<(std::ostream& out,const interval& x){
            out<<'('<<x.l<<','<<x.r<<')';
            return out;
        }
    };

    class inTree: public BTreeBase<interval>{
        using dataType=interval;
        private:
        static const char RED='R';
        static const char BLA='B';
        struct inNode{
            dataType data;
            inNode* parent;
            inNode* lchild;
            inNode* rchild;
            char color;
            double max;
        };
        inNode* root;
        void del_node(inNode* pos){
            if(pos!=nullptr){
                if(pos->lchild!=nullptr){del_node(pos->lchild);}
                if(pos->rchild!=nullptr){del_node(pos->rchild);}
                delete pos;
            }
        }
        
        void updateMax(inNode* pos){
            double lmax=pos->lchild?pos->lchild->max:DBL_MIN;
            double rmax=pos->rchild?pos->rchild->max:DBL_MIN;
            if(lmax>rmax){
                pos->max=(lmax > pos->data.r)?lmax:pos->data.r;
            }else{
                pos->max=(rmax > pos->data.r)?rmax:pos->data.r;
            }
        }
        void left_rotate(inNode* pos){
            inNode* ano=pos->rchild;
            //change parents
            if(pos!=root){
                if(pos->parent->lchild==pos){
                    pos->parent->lchild=ano;
                }else{
                    pos->parent->rchild=ano;
                }
                ano->parent=pos->parent;
                pos->parent=ano;
            }else{
                ano->parent=nullptr;
                pos->parent=ano;
                root=ano;
            }
            //fix ano->lchild
            pos->rchild=ano->lchild;
            if(pos->rchild){
                pos->rchild->parent=pos;
            }
            ano->lchild=pos;
            
            updateMax(pos);
            updateMax(ano);
        }
        void right_rotate(inNode* pos){
            inNode* ano=pos->lchild;
            //change parents
            if(pos!=root){
                if(pos->parent->lchild==pos){
                    pos->parent->lchild=ano;
                }else{
                    pos->parent->rchild=ano;
                }
                ano->parent=pos->parent;
                pos->parent=ano;
            }else{
                ano->parent=nullptr;
                pos->parent=ano;
                root=ano;
            }
            //fix ano->rchild
            pos->lchild=ano->rchild;
            if(pos->lchild){
                pos->lchild->parent=pos;
            }
            ano->rchild=pos;

            updateMax(pos);
            updateMax(ano);
        }
        
        void preOrderRecu(inNode* pos){
            if(pos!=nullptr){
                std::cout<<pos->data<<'('<<pos->max<<')'<<' ';
                preOrderRecu(pos->lchild);
                preOrderRecu(pos->rchild);
            }
        }
        void inOrderRecu(inNode* pos){
            if(pos!=nullptr){
                inOrderRecu(pos->lchild);
                std::cout<<pos->data<<'('<<pos->max<<')'<<' ';
                inOrderRecu(pos->rchild);
            }
        }
        void postOrderRecu(inNode* pos){
            if(pos!=nullptr){
                postOrderRecu(pos->lchild);
                postOrderRecu(pos->rchild);
                std::cout<<pos->data<<'('<<pos->max<<')'<<' ';
            }
        }
        int heightRecu(inNode* pos){
            if(pos==nullptr){return 0;}
            else{
                int hL=heightRecu(pos->lchild);
                int hR=heightRecu(pos->rchild);
                return (hL>hR?hL:hR)+1;
            }
        }
        int redNumRecu(inNode* pos){
            if(pos!=nullptr){
                int l=redNumRecu(pos->lchild);
                int r=redNumRecu(pos->rchild);
                return l+r+(pos->color==RED?1:0);
            }else{
                return 0;
            }
        }
        public:
        inTree():root(nullptr){}
        ~inTree(){del_node(root);}
        void insert(const dataType& x){
        //------Normal binary search tree insert-----------------------
            inNode* pos=root;
            inNode* bef=nullptr;
            bool isBeforeToLeft=false;
            //find insert position
            while(pos!=nullptr){
                if(pos->max < x.r){
                    pos->max=x.r;
                }
                if(x < pos->data){
                    bef=pos;
                    isBeforeToLeft=true;
                    pos=pos->lchild;
                }
                else{
                    bef=pos;
                    isBeforeToLeft=false;
                    pos=pos->rchild;
                }
            }
            //set data value
            pos=new inNode;
            pos->data=x;
            pos->lchild=pos->rchild=nullptr;
            pos->parent=bef;
            pos->max=pos->data.r;
            //adapt changes to tree
            if(bef==nullptr){
                root=pos;
                pos->color=BLA;
            }else{
                if(isBeforeToLeft){
                    bef->lchild=pos;
                }else{
                    bef->rchild=pos;
                }
                pos->color=RED;
            }
        //-----Fix so that RB continues--------------------
            while(pos!=root&&pos->parent->color==RED){
                //because root is Black so parent is not root here
                //so there must be a grandparent node
                if(pos->parent==pos->parent->parent->lchild){
                    inNode* parBro=pos->parent->parent->rchild;
                    if(parBro==nullptr||parBro->color==BLA){
                        //self:red,par:red,parBro:black
                        //here we can conclude that
                        //grand node is black
                        if(pos==pos->parent->rchild){
                            //problems haven't been solved here
                            //this turned problem into left one
                            pos=pos->parent;
                            left_rotate(pos);
                        }
                        pos->parent->color=BLA;
                        pos->parent->parent->color=RED;
                        right_rotate(pos->parent->parent);
                        //break autoly,because pos->par->color=bla
                    }else{
                        //self:red,par:red,parBro:red
                        parBro->color=pos->parent->color=BLA;
                        pos->parent->parent->color=RED;
                        pos=pos->parent->parent;
                    }
                }else{
                    //parent is right node
                    inNode* parBro=pos->parent->parent->lchild;
                    if(parBro==nullptr||parBro->color==BLA){
                        //self:red,par:red,parBro:black
                        //here we can conclude that
                        //grand node is black
                        if(pos==pos->parent->lchild){
                            //problems haven't been solved here
                            //this turned problem into left one
                            pos=pos->parent;
                            right_rotate(pos);
                        }
                        pos->parent->color=BLA;
                        pos->parent->parent->color=RED;
                        left_rotate(pos->parent->parent);
                        //break autoly,because pos->par->color=bla
                    }else{
                        //self:red,par:red,parBro:red
                        parBro->color=pos->parent->color=BLA;
                        pos->parent->parent->color=RED;
                        pos=pos->parent->parent;
                    }
                }
            }
            if(pos==root){
                pos->color=BLA;
            }
        }
        int height(){
            return heightRecu(root);
        }
        int redNum(){
            return redNumRecu(root);
        }
        //Lab05 doesn't require find and erase operations
        bool erase(const dataType& x){return false;}
        dataType* find(const dataType& x){return nullptr;}
        //Lab05 doesn't require find and erase operations
        void printPreOrderTraverse(){
            preOrderRecu(root);
            std::cout<<std::endl;
        }
        void printInOrderTraverse(){
            inOrderRecu(root);
            std::cout<<std::endl;
        }
        void printPostOrderTraverse(){
            postOrderRecu(root);
            std::cout<<std::endl;
        }
        inNode* isIntervalOccupied(interval i){
            inNode* pos=root;
            while(pos!=nullptr&&(i.l >=pos->data.r||pos->data.l >=i.r)){
                if(pos->lchild!=nullptr && i.l < pos->lchild->max){
                    pos=pos->lchild;
                }else{
                    pos=pos->rchild;
                }
            }
            return pos;
        }
        int intervalSumRecu(inNode* p,interval i){
            int val=0;
            if(p==nullptr){
                return 0;
            }else if(p->data.r <=i.l||p->data.l >=i.r){
                val=0;
            }else{
                val=1;
            }
            if(p->lchild!=nullptr&&i.l < p->lchild->max){
                val+=intervalSumRecu(p->lchild,i);
            }
            if(p->rchild!=nullptr){
                if(i.r < p->rchild->data.l){
                    val+=intervalSumRecu(p->rchild->lchild,i);
                }else{
                    val+=intervalSumRecu(p->rchild,i);
                }
            }
            return val;
        }
        int intervalSumSearch(interval i){
            return intervalSumRecu(root,i);
        }
    };
}