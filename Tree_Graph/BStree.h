#pragma once
#include "TreeBase.h"
namespace theSTL{
    template<typename dataType> class BSTree: public BTreeBase<dataType>{
        struct Node{
            dataType data;
            Node* lTree;
            Node* rTree;
        };
        private:
        Node* root;
        void del_node(Node* pos){
            if(pos->lTree!=nullptr){del_node(pos->lTree);}
            if(pos->rTree!=nullptr){del_node(pos->rTree);}
            delete pos;
        }
        public:
        BSTree():root(nullptr){}
        ~BSTree(){if(root!=nullptr)del_node(root);}
        void insert(const dataType& data){
            
        }
        dataType* find(const dataType& dat){
            Node* pos=root;
            while(true){
                if(pos==nullptr){
                    return nullptr;
                }else if(pos->data==dat){
                    return &pos->data;
                }else{
                    if(dat < pos->data){pos=pos->lTree;}
                    else if(dat > pos->data){pos=pos->rTree;}
                }
            }
        }
        bool erase(const dataType& x){}
    };
}