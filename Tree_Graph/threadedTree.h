#include<TreeBase.h>

namespace theSTL{
    template<typename dataType>struct thNode{
        dataType dat;
        thNode *lchild,*rchild;
        bool ltag,rtag;//If true, store line. If false, store real child
    };
    template<typename dataType> class thBtree:BTreeBase<dataType>{
        using node=thNode<dataType>;
        
        private:
        node* root;
        node* head;

        void delSubTree(node* p){
            if(p!=nullptr){
                if(lchild!=nullptr){delNode(lchild);}
                if(rchild!=nullptr){delNode(rchild);}
                delete p;
            }
        }

        public:
        thBtree(){
            root=nullptr;
        }
        ~thBtree(){
            delSubTree(root);
        }
        node* pred(node* p){
            if(p->ltag||p->lchild==nullptr){
                return p->lchild;//automatically point to pred
            }else{
                p=p->lchild;
                while(p->rtag==false){
                    p=p->rchild;
                }
                return p;
            }
        }
        node* succ(node* p){
            if(p->rtag||p->rchild==nullptr){
                return p->rchild;
            }else{
                p=p->rchild;
                while(p->ltag==false){
                    p=p->lchild;
                }
                return p;
            }
        }
        void predInsert(node* p,node* q){
            if(p->ltag||p->lchild==nullptr){
                q->ltag=p->ltag;
                q->lchild=p->lchild;
                q->rchild=p;
                q->rtag=true;

                p->ltag=false;
                p->lchild=q;

                if(q->lchild==nullptr){head=q;}
            }else{
                node* r=pred(p);
                q->lchild=r;
                q->ltag=true;
                q->rchild=r->rchild;
                q->rtag=r->rtag;

                r->rchild=
            }
        }
        void succInsert(node* p,node* q){

        }
    };
}