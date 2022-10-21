#include"../LinearList/List.h"

namespace theSTL{
    template<typename dataType> class BSTree{
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

        dataType* search_node(Node* pos,dataType x){
            
        }
        bool erase_node(Node* pos,dataType x){
            while(true){
                if(pos==nullptr){
                    return false;
                }else if(pos->data==x){
                    //how to erase it properly
                    if(pos->lTree==nullptr){
                        if(pos->rTree==nullptr){
                            
                        }else{
                            
                        }
                    }else{
                        if(pos->rTree==nullptr){
                            
                        }else{
                            
                        }
                    }
                    return true;
                }else{
                    if(x < pos->data){pos=pos->lTree;}
                    else if(x > pos->data){pos=pos->rTree;}
                }
            }
        } 
        public:
        BSTree():root(nullptr){}
        ~BSTree(){if(root!=nullptr)del_node(root);}
        void insert(dataType data){
            while(pos!=nullptr){
                if(data < pos->data){pos=pos->lTree;}
                else if(data>= pos->data){pos=pos->rTree;}
            }
            pos=new Node;
            pos->data=data;
            pos->lTree=pos->rTree=nullptr;
        }
        dataType* search(dataType dat){
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
    };
}