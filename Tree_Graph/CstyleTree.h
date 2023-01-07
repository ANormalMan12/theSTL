#include<iostream>
namespace CSTL{
    struct BSTnode{
       int data;
       BSTnode *lchild,*rchild; 
    };
    /**
     * @brief 
     * @details There are four possible results.
     * 1.par, q are both NULL : the tree is NULL 
     * 2.par is not NULL,q is NULL : target hasn't been found,but tree isn't null
     * 3.par is null ,q isn't NULL : q points the root
     * 4.par, q are both not NULL : normal state
     * @param root root of the tree to be searched
     * @param target data to be serached
     * @param par reference to the pointer to the parent of q
     * @param q reference to the pointer to target node
     */
    void BSTsearch(BSTnode* const root,int target,BSTnode*& par,BSTnode*& q){
        par=NULL;
        q=root;
        while(q!=NULL){
            if(q->data==target){
                return ;//found the target
            }
            par=q;//update and down p
            if(target<q->data){
                q=q->lchild;
            }else{
                q=q->rchild;
            }//update and down q
        }
    }
    /**
     * @brief 
     * 
     * @param root 
     * @param data 
     */
    void BSTinsert(BSTnode*& root,int toInsertDat){
        BSTnode *par, *q;
        BSTsearch(root,toInsertDat,par,q);
        if(q==NULL){
            BSTnode* toinsert=new BSTnode;
            toinsert->data=toInsertDat;
            toinsert->lchild=toinsert->rchild=NULL;
            if(par==NULL){
                root=toinsert;
            }else{
                if(par->data >toInsertDat){
                    par->lchild=toinsert;
                }else{
                    par->rchild=toinsert;
                }
            }
        }
    }

    void BSTerase(BSTnode*& root,int toEraseDat){
        BSTnode *par,*q;
        BSTsearch(root,toEraseDat,par,q);
        if()//to do
    }
    BSTnode* buildTree(int *nodeArr, int arrSize) {
        if(arrSize<=0){
            return NULL;
        }
        BSTnode* root=new BSTnode;
        root->data=nodeArr[0];
        root->lchild=root->rchild=NULL;
        BSTnode* par;
        BSTnode* q;
        int pos=1;
        while(pos<arrSize){
            BSTinsert(root,nodeArr[pos]);
            ++pos;
        }
        return root;
    }



    /**
     * 判断这棵查找树是否平衡
     *  * @param root      [树的根节点]
     */
    bool isBalanceRecu(BSTnode* root,int* depth){
        if(root==NULL){
            *depth=0;
            return true;
        }
        bool ret=true;
        int lH,rH;
        if(!isBalanceRecu(root->lchild,&lH)){
            ret=false;
        }
        if(!isBalanceRecu(root->rchild,&rH)){
            ret=false;
        }
        if(abs(lH-rH)>1){
            ret=false;
        }
        *depth=(lH<rH?rH:lH)+1;
        return ret;
    }
    
    bool isBalance(BSTnode *root) {
        /** TODO **/
        int depth;
        return isBalanceRecu(root,&depth);
    }

    /**
     * 输出这颗查找树查找结点的平均比较次数, 结果保留2位小数
     * 具体参考样例
     * AVG（二叉查找法）= ∑_树中的k▒〖p(k)(1+λk)〗
     * @param root      [树的根节点]
     */
    long long TreeSize;
    long long AVGrecu(BSTnode* subroot,int floor){
        if(subroot==NULL){
            return 0;
        }else{
            ++TreeSize;
            long long ret=floor;//self
            if(subroot->lchild!=NULL){
                ret+=AVGrecu(subroot->lchild,floor+1);
            }
            if(subroot->rchild!=NULL){
                ret+=AVGrecu(subroot->rchild,floor+1);
            }
            return ret;
        }
    }
    void printAVG(BSTnode *root) {
        /** TODO 需要输出**/
        TreeSize=0;
        printf("%.2lf\n",((double)AVGrecu(root,1))/(double)TreeSize);
    }
}