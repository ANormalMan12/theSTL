namespace theSTL{
    using dataType=double;
    struct oSNode{
        dataType data;
        oSNode* parent;
        oSNode* lchild;
        oSNode* rchild;
        char color;
        int size;
    };
    class oSTree{
        private:
        static const char RED='R';
        static const char BLA='B';
        
        oSNode* nul;
        oSNode* root;
        
        void del_node(oSNode* pos){
            if(pos!=nul){
                if(pos->lchild!=nul){del_node(pos->lchild);}
                if(pos->rchild!=nul){del_node(pos->rchild);}
                delete pos;
            }
        }
        void eraseFix(oSNode* x){
            while(x!=root&&x->color==BLA){
                if(x==x->parent->lchild){ //x is left child of its parent
                    oSNode* w=x->parent->rchild; 
                    //Case 1
                    if(w->color==RED){
                        w->color=BLA;
                        w->parent->color=RED;//KEY CHANGE
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
                        w->color=w->parent->color;//KEY CHANGE
                        x->parent->color=BLA;
                        w->rchild->color=BLA; 
                        left_rotate(x->parent);
                        x=root;  
                    }
                }else{ //x is right child of its parent
                    oSNode* w=x->parent->lchild;
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
        void left_rotate(oSNode* pos){
            oSNode* ano=pos->rchild;
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

            //maintain size , A is lower ,so should be updated before
            pos->size=(pos->lchild!=nul?pos->lchild->size:0)
                        +(pos->rchild!=nul?pos->rchild->size:0)+1;
            ano->size=(ano->lchild!=nul?ano->lchild->size:0)
                        +(ano->rchild!=nul?ano->rchild->size:0)+1;
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

            //maintain size
            pos->size=(pos->lchild!=nul?pos->lchild->size:0)
                        +(pos->rchild!=nul?pos->rchild->size:0)+1;
            ano->size=(ano->lchild!=nul?ano->lchild->size:0)
                        +(ano->rchild!=nul?ano->rchild->size:0)+1;
        }
        
        void preOrderRecu(oSNode* pos){
            if(pos!=nul){
                std::cout<<pos->data<<'('<<pos->size<<") ";
                preOrderRecu(pos->lchild);
                preOrderRecu(pos->rchild);
            }
        }
        void inOrderRecu(oSNode* pos){
            if(pos!=nul){
                inOrderRecu(pos->lchild);
                std::cout<<pos->data<<'('<<pos->size<<") ";
                inOrderRecu(pos->rchild);
            }
        }
        void postOrderRecu(oSNode* pos){
            if(pos!=nul){
                postOrderRecu(pos->lchild);
                postOrderRecu(pos->rchild);
                std::cout<<pos->data<<'('<<pos->size<<") ";
            }
        }
        int heightRecu(oSNode* pos){
            if(pos==nul){return 0;}
            else{
                int hL=heightRecu(pos->lchild);
                int hR=heightRecu(pos->rchild);
                return (hL>hR?hL:hR)+1;
            }
        }
        int redNumRecu(oSNode* pos){
            if(pos!=nul){
                int l=redNumRecu(pos->lchild);
                int r=redNumRecu(pos->rchild);
                return l+r+(pos->color==RED?1:0);
            }else{
                return 0;
            }
        }
        /* dataType* findKthRecu(oSNode* pos,int k){
            if(pos==nul){
                return nullptr;
            }else{
                int lm=(pos->lchild!=nul?pos->lchild->size:0)+1;
                if(k==lm){
                    return &pos->data;
                }else if(k<lm){
                    return findKthRecu(pos->lchild,k);
                }else{
                    return findKthRecu(pos->rchild,k-lm);
                }
            }
        } */
        void transplant(oSNode* pos,oSNode* nPos){
            if(pos->parent!=nul){
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
        
        oSTree(){
            nul=new oSNode;
            root=nul;
            nul->lchild=nul;
            nul->rchild=nul;
            nul->color=BLA;
            nul->size=0;
            nul->parent=nul;
        }
        ~oSTree(){del_node(root);delete nul;}
        void insert(const dataType& x){
        //------Normal binary search tree insert-----------------------
            oSNode* pos=root;
            oSNode* bef=nul;
            bool isBeforeToLeft=false;
            //find insert position
            while(pos!=nul){
                ++pos->size;
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
            pos->lchild=pos->rchild=nul;
            pos->parent=bef;
            pos->size=1;
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
                    oSNode* parBro=pos->parent->parent->rchild;
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
                    oSNode* parBro=pos->parent->parent->lchild;
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
            //resetGuard();
        }
        int height(){
            return heightRecu(root);
        }
        int redNum(){
            return redNumRecu(root);
        }
        oSNode* minNode(oSNode* pos){
            if(pos->lchild==nul){
                return pos;
            }else{
                return minNode(pos->lchild);
            }
        }
        bool eraseNode(oSNode* pos){
            /* if(pos==nul){
                cout<<"WRONG in delete"<<endl;
                return false;//break point:not found
            } */
            //begin to erase and fix
            char oColor=pos->color;
            oSNode* x=nul;
            oSNode* y;
            if(pos->lchild!=nul&&pos->rchild!=nul){
                y=minNode(pos);//Change:y=minNode(pos->rchild);
            }else{
                y=pos;
            }
            if(pos->lchild==nul){
                x=pos->rchild;
                transplant(pos,x);
            }else{
                if(pos->rchild==nul){
                    x=pos->lchild;
                    transplant(pos,x);
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
            /* if(x==nul){
                cout<<"ERROR";
            } */
            //resetGuard();//A controversial change happens here
            if(oColor==BLA){
                nul->lchild=nul;//CHANGE
                nul->rchild=nul;
                eraseFix(x);
            }
            if(pos!=nul){
                delete pos;
            }
            //resetGuard();
            return true;
        }
        bool erase(const dataType& dat){
            oSNode* pos=root;
            while(pos!=nul){
                --pos->size;//key to order maintainance
                if(fabs(pos->data-dat)<1e-10){
                    break;
                }else if(dat< pos->data){
                    pos=pos->lchild;
                }else{
                    pos=pos->rchild;
                }
            }
            return eraseNode(pos);
        }
       /*  dataType* findKth(int k){
            return findKthRecu(root,k);
        } */
        oSNode* find(const dataType& x){
            oSNode* pos=root;
            while(pos!=nul){
                if(fabs(pos->data-x)<1e-10){
                    break;
                }else if(x< pos->data){
                    pos=pos->lchild;
                }else{
                    pos=pos->rchild;
                }
            }
            if(pos==nul){
                cout<<"Wrong"<<endl;
                return nullptr;
            }
            return pos;
        }
        int rank(oSNode* p){
            int ret=p->lchild->size+1;
            while(p!=root){
                if(p==p->parent->rchild){
                    ret+=p->parent->lchild->size+1;
                }
                p=p->parent;
            }
            return ret;
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
    
        void resetGuard(){
            nul->lchild=nul;
            nul->rchild=nul;
            nul->parent=nul;
            nul->color=BLA;
        }
    };
}
/* void testOStree(){
    int T=10;
    for(int iT=0;iT<T;++iT){
        int *arr=RAND::newRandArr(10,-300,300);
        theSTL::oSTree<int> ost;
        for(int i=0;i<10;++i){
            cout<<arr[i]<<' ';
            ost.insert(arr[i]);
        }
        cout<<endl;
        
        cout<<"Preorder"<<endl;
        ost.printPreOrderTraverse();
        cout<<"Inorder"<<endl;
        ost.printInOrderTraverse();
        putchar('\n');
        delete[] arr;
        printf("1st smallest is %d\n",*ost.findKth(1));
        printf("4th smallest is %d\n",*ost.findKth(4));
        printf("7th smallest is %d\n",*ost.findKth(7));
    }
} */
/* #define SIZE 500009
double lBuf[SIZE];
struct adata{
    double angle;
    int index;
    bool operator<(adata ano){
        return angle<ano.angle;
    }
};
adata arr[2*SIZE];

void solve(){
    int n;
    scanf("%d",&n);
    double x1,y1,x2,y2;
    double low,high;
    for(int in=0;in<n;++in){
        scanf("%lf %lf %lf %lf ",&x1,&y1,&x2,&y2);
        low=atan2(y1,x1);
        high=atan2(y2,x2);
        if(low>high)swap(low,high);
        arr[in<<1].angle=low;
        arr[in<<1].index=in<<1;
        arr[(in<<1)+1].angle=high;
        arr[(in<<1)+1].index=(in<<1)+1;
        lBuf[in]=low;//record low
    }
    sort(arr,arr+2*n);
    theSTL::oSTree tr;
    long long ans=0;
    int treeSize=0;
    
    #ifdef TESTING
    cout<<"7378:"<<arr[7378].angle<<' '<<arr[7378].index<<endl;
    cout<<lBuf[arr[7378].index/2]<<endl;
    cout<<"6457:"<<arr[6457].angle<<' '<<arr[6457].index<<endl;
    cout<<lBuf[arr[6457].index/2]<<endl;
    #endif
    
    for(int k=0;k<(n<<1);++k){
        
        #ifdef TESTING
        if(k==7378){
            cout<<"Break Point happens here"<<endl;
        }else if(k==6457){
            cout<<"Wrong Erase break point here"<<endl;
        }
        #endif
        double tang=arr[k].angle;
        int ti=arr[k].index;
        if(ti&1){//if high
            tang=lBuf[ti/2];//try to find low
            theSTL::oSNode* p=tr.find(tang);
            ans+=treeSize-tr.rank(p);//getans
            --treeSize;
            tr.erase(tang);
            //tr.resetGuard();
        }else{//if low
            ++treeSize;
            tr.insert(tang);
            //tr.resetGuard();
        }
        #ifdef TESTING
        if(6450<k&&k<6700){
            if(tr.find(-3.0640939167056285)!=nullptr){
                cout<<k<<" found\n";
            }else{
                cout<<k<<' '<<arr[k].angle<<" notfound\n";
            }
        }
        #endif
        /* if(k%1000==0||(7350<k&&k<7500)){
            cout<<k<<'#'<<endl;
            tr.printPreOrderTraverse();
            tr.printInOrderTraverse();
            cout<<endl;
        } */
    }
    cout<<ans;
} */