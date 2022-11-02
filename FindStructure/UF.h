
using namespace std;
namespace theSTL{
    class UF_base{
        protected:
        int size;
        int *arr;
        int num_sets;
        public:
        virtual int find(int)=0;
        virtual void connect(int,int)=0;
        virtual bool isJoint(int,int)=0;
        virtual int countSets()=0;
    };

    class UF_weight:public UF_base{//real size is bigger
        private:
        int *weight;
        public:
        UF_weight(int Nsize):size(Nsize),num_sets(Nsize){//in fact,realsize=1+Nsize
            arr=new int [size+1];//real size is bigger
            weight=new int [size+1];//tree root size
            for(int i=1;i<=size;++i){
                arr[i]=i;
                weight[i]=1;
            }
        }
        ~UF_weight(){
            if(arr!=nullptr){
                delete[] arr;
            }
            if(weight!=nullptr){
                delete[] weight;
            }
        }
        int find(int i){//o(h) h means height here
            int now=i;
            while(arr[now]!=now){//find root node
                now=arr[now];
            }//only index at root matters
            return now;
        }
        void connect(int i,int j){
            int iroot=find(i);
            int jroot=find(j);
            if(iroot!=jroot){
                --num_sets;//one of roots has been removed
                //determine which of roots to redirect
                if(weight[iroot]==weight[jroot]){
                    arr[iroot]=jroot;
                    weight[jroot]+=1;
                }else if(weight[iroot]<weight[jroot]){
                    arr[iroot]=jroot;
                }else{
                    arr[jroot]=iroot;
                }
            }
        }
        bool isJoint(int i,int j){
            return find(i)==find(j);
        }
        int countSets(){
            return num_sets;
        }
    };


}