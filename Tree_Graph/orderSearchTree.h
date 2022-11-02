#pragma once
#include<iostream>

namespace theSTL{
    template<typename dataType> class oSTree: public BTreeBase<dataType>{
        private:
        static const char RED='R';
        static const char BLA='B';
        struct oSNode{
            dataType data;
            oSNode* parent;
            oSNode* lchild;
            oSNode* rchild;
            char color;
            int size;
        };
        oSNode* root;
        void del_node(oSNode* pos){//no need to fix
            if(pos!=nullptr){
                if(pos->lchild!=nullptr){del_node(pos->lchild);}
                if(pos->rchild!=nullptr){del_node(pos->rchild);}
                delete pos;
            }
        }
        void left_rotate(oSNode* pos){
            oSNode* ano=pos->rchild;
            //change parents
            if(pos!=root){//for pos's parent, no change happend
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
            //maintain size , A is lower ,so should be updated before
            pos->size=(pos->lchild?pos->lchild->size:0)
                        +(pos->rchild?pos->rchild->size:0)+1;
            ano->size=(ano->lchild?ano->lchild->size:0)
                        +(ano->rchild?ano->rchild->size:0)+1;
        }
        void right_rotate(oSNode* pos){
            oSNode* ano=pos->lchild;
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
            //maintain size
            pos->size=(pos->lchild?pos->lchild->size:0)
                        +(pos->rchild?pos->rchild->size:0)+1;//remember oneself
            ano->size=(ano->lchild?ano->lchild->size:0)
                        +(ano->rchild?ano->rchild->size:0)+1;
        }
        
        void preOrderRecu(oSNode* pos){
            if(pos!=nullptr){
                std::cout<<pos->data<<pos->color<<'('<<pos->size<<')'<<' ';
                preOrderRecu(pos->lchild);
                preOrderRecu(pos->rchild);
            }
        }
        void inOrderRecu(oSNode* pos){
            if(pos!=nullptr){
                inOrderRecu(pos->lchild);
                std::cout<<pos->data<<pos->color<<'('<<pos->size<<')'<<' ';
                inOrderRecu(pos->rchild);
            }
        }
        void postOrderRecu(oSNode* pos){
            if(pos!=nullptr){
                postOrderRecu(pos->lchild);
                postOrderRecu(pos->rchild);
                std::cout<<pos->data<<pos->color<<'('<<pos->size<<')'<<' ';
            }
        }
        int heightRecu(oSNode* pos){
            if(pos==nullptr){return 0;}
            else{
                int hL=heightRecu(pos->lchild);
                int hR=heightRecu(pos->rchild);
                return (hL>hR?hL:hR)+1;
            }
        }
        int redNumRecu(oSNode* pos){
            if(pos!=nullptr){
                int l=redNumRecu(pos->lchild);
                int r=redNumRecu(pos->rchild);
                return l+r+(pos->color==RED?1:0);
            }else{
                return 0;
            }
        }
        dataType* findKthRecu(oSNode* pos,int k){
            if(pos==nullptr){
                return nullptr;
            }else{
                int lm=pos->lchild->size+1;
                if(k==lm){
                    return &pos->data;
                }else if(k<lm){
                    return findKthRecu(pos->lchild,k);
                }else{
                    return findKthRecu(pos->rchild,k-lm);
                }
            }
        }
        public:
        oSTree():root(nullptr){}
        ~oSTree(){del_node(root);}
        void insert(const dataType& x){
        //------Normal binary search tree insert-----------------------
            oSNode* pos=root;
            oSNode* bef=nullptr;
            bool isBeforeToLeft=false;
            //find insert position
            while(pos!=nullptr){
                ++(pos->size);//maintain size
                if(x < pos->data){
                    bef=pos;
                    isBeforeToLeft=true;
                    pos=pos->lchild;
                }
                else if(x>= pos->data){
                    bef=pos;
                    isBeforeToLeft=false;
                    pos=pos->rchild;
                }
            }
            //set data value
            pos=new oSNode;
            pos->data=x;
            pos->lchild=pos->rchild=nullptr;
            pos->parent=bef;
            pos->size=1;//maintain size
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
                    oSNode* parBro=pos->parent->parent->rchild;
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
                    oSNode* parBro=pos->parent->parent->lchild;
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

        dataType* findKth(int k){
            return findKthRecu(root);
        }

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
    };
}