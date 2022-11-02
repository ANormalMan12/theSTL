/**
 * @file RBTree.h
 * @author Weiye Wang (wangweiye1205@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include<iostream>
#include"TreeBase.h"


namespace theSTL{
    template<typename dataType> class rbTree: public BTreeBase<dataType>{
        private:
        static const char RED='R';
        static const char BLA='B';
        
        struct rbNode{
            dataType data;
            rbNode* parent;
            rbNode* lchild;
            rbNode* rchild;
            char color;
        };
        
        rbNode* nul;
        rbNode* root;
        
        void del_node(rbNode* pos){
            if(pos!=nul){
                if(pos->lchild!=nul){del_node(pos->lchild);}
                if(pos->rchild!=nul){del_node(pos->rchild);}
                delete pos;
            }
        }
        void eraseFix(rbNode* x){
            while(x!=root&&x->color==BLA){
                if(x==x->parent->lchild){ //x is left child of its parent
                    rbNode* w=x->parent->rchild; 
                    //Case 1
                    if(w->color==RED){
                        w->color=BLA;
                        x->parent->color=RED;
                        left_rotate(x->parent);
                        w=x->parent->rchild;
                    }
                    //Case 2
                    if(w->lchild->color==BLA&&w->rchild->color==BLA){
                        w->color=RED;
                        x=x->parent; 
                    }else{
                        //Case 3：x's brother w is BLA,w's left child is red,rchild child is BLA
                        if(w->rchild->color==BLA){
                            w->color=RED;
                            w->lchild->color=BLA;
                            right_rotate(w);
                            w=x->parent->rchild;
                        }
                        //Case 4：x's brother w is BLA,and w's rchild is red
                        w->color=x->parent->color;
                        x->parent->color=BLA;
                        w->rchild->color=BLA; 
                        left_rotate(x->parent);
                        x=root;  
                    }
                }else{ //x is right child of its parent
                    rbNode* w=x->parent->lchild;
                    if(w->color==RED){  // case 1
                        w->parent->color=RED;
                        w->color=BLA;
                        right_rotate(x->parent);
                        w=x->parent->lchild;
                    }
                    else if(w->lchild->color==BLA&&w->rchild->color==BLA){   //case 2
                        w->color=RED;
                        x=x->parent;
                    }
                    else{
                        if(w->lchild->color==BLA)    //case 3
                        {
                            w->rchild->color=BLA;
                            w->color=RED;
                            left_rotate(w);
                            w=x->parent->lchild;
                        }
                        //case 4
                        w->color=x->parent->color;
                        x->parent->color=BLA;
                        w->lchild->color=BLA;
                        right_rotate(x->parent);
                        x=root;
                    }
                }
            }
            x->color=BLA;//set x as black
        }
        void left_rotate(rbNode* pos){
            rbNode* ano=pos->rchild;
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
                ano->parent=nul;
                pos->parent=ano;
                root=ano;
            }
            //fix ano->lchild
            pos->rchild=ano->lchild;
            if(pos->rchild){
                pos->rchild->parent=pos;
            }
            ano->lchild=pos;
        }
        void right_rotate(rbNode* pos){
            rbNode* ano=pos->lchild;
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
                ano->parent=nul;
                pos->parent=ano;
                root=ano;
            }
            //fix ano->rchild
            pos->lchild=ano->rchild;
            if(pos->lchild){
                pos->lchild->parent=pos;
            }
            ano->rchild=pos;
        }
        
        void preOrderRecu(rbNode* pos){
            if(pos!=nul){
                std::cout<<pos->data<<pos->color<<' ';
                preOrderRecu(pos->lchild);
                preOrderRecu(pos->rchild);
            }
        }
        void inOrderRecu(rbNode* pos){
            if(pos!=nul){
                inOrderRecu(pos->lchild);
                std::cout<<pos->data<<pos->color<<' ';
                inOrderRecu(pos->rchild);
            }
        }
        void postOrderRecu(rbNode* pos){
            if(pos!=nul){
                postOrderRecu(pos->lchild);
                postOrderRecu(pos->rchild);
                std::cout<<pos->data<<pos->color<<' ';
            }
        }
        int heightRecu(rbNode* pos){
            if(pos==nul){return 0;}
            else{
                int hL=heightRecu(pos->lchild);
                int hR=heightRecu(pos->rchild);
                return (hL>hR?hL:hR)+1;
            }
        }
        int redNumRecu(rbNode* pos){
            if(pos!=nul){
                int l=redNumRecu(pos->lchild);
                int r=redNumRecu(pos->rchild);
                return l+r+(pos->color==RED?1:0);
            }else{
                return 0;
            }
        }
        void transplant(rbNode* pos,rbNode* nPos){
            if(pos->parent){
                if(pos->parent->lchild==pos){
                    pos->parent->lchild=nPos;
                }else{
                    pos->parent->rchild=nPos;
                }
            }else{
                root=nPos;
            }
            nPos->parent=pos->parent;
        }
        public:
        rbTree(){nul=new rbNode;root=nul;}
        ~rbTree(){del_node(root);}
        void insert(const dataType& x){
        //------Normal binary search tree insert-----------------------
            rbNode* pos=root;
            rbNode* bef=nul;
            bool isBeforeToLeft=false;
            //find insert position
            while(pos!=nul){
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
            pos=new rbNode;
            pos->data=x;
            pos->lchild=pos->rchild=nul;
            pos->parent=bef;
            //adapt changes to tree
            if(bef==nul){
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
                //because root is BLA so parent is not root here
                //so there must be a grandparent node
                if(pos->parent==pos->parent->parent->lchild){
                    rbNode* parBro=pos->parent->parent->rchild;
                    if(parBro==nul||parBro->color==BLA){
                        //self:red,par:red,parBro:BLA
                        //here we can conclude that
                        //grand node is BLA
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
                    rbNode* parBro=pos->parent->parent->lchild;
                    if(parBro==nul||parBro->color==BLA){
                        //self:red,par:red,parBro:BLA
                        //here we can conclude that
                        //grand node is BLA
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
        rbNode* minNode(rbNode* pos){
            if(pos->lchild==nul){
                return pos;
            }else{
                return minNode(pos->lchild);
            }
        }
        bool erase(const dataType& dat){
            rbNode* pos=root;
            while(pos!=nul){
                if(pos->data==dat){
                    break;
                }else if(dat< pos->data){
                    pos=pos->lchild;
                }else{
                    pos=pos->rchild;
                }
            }
            if(pos==nul){
                return false;//break point:not found
            }
            //begin to erase and fix
            char oColor=pos->color;
            rbNode* x=nul;
            rbNode* y=pos;
            if(pos->lchild==nul){
                if(pos->rchild==nul){
                    transplant(pos,nul);
                }else{
                    x=pos->rchild;
                    transplant(pos,x);
                }
            }else{
                if(pos->rchild==nul){
                    x=pos->lchild;
                    transplant(pos,pos->lchild);
                }else{
                    y=minNode(pos->rchild);
                    oColor=y->color;
                    x=y->rchild;
                    if(y->parent==pos){
                        x->parent=y;
                    }else{
                        transplant(y,y->rchild);
                        y->rchild=pos->rchild;
                        y->rchild->parent=y;
                    }
                    transplant(pos,y);
                    y->lchild=pos->lchild;
                    y->lchild->parent=y;
                    y->color=pos->color;
                }
            }
            if(oColor==BLA){
                eraseFix(x);
            }
            delete pos;
            return true;
        }
        rbNode* find(const dataType& x){
            rbNode* pos=root;
            while(pos!=nul){
                if(pos->data==x){
                    break;
                }else if(x< pos->data){
                    pos=pos->lchild;
                }else{
                    pos=pos->rchild;
                }
            }
            return pos;
        }
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
    };
}