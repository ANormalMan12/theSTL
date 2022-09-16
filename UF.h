
using namespace std;
namespace mySTL{
    class UF{//real size is bigger
        private:
        int size;
        int *arr;
        int *weight;
        int num_sets;
        public:
        UF(int Nsize):size(Nsize),num_sets(Nsize){//in fact,realsize=1+Nsize
            arr=new int [size+1];//real size is bigger
            weight=new int [size+1];//tree root size
            for(int i=1;i<=size;++i){
                arr[i]=i;
                weight[i]=1;
            }
        }
        ~UF(){
            if(arr!=nullptr){
                delete[] arr;
            }
            if(weight!=nullptr){
                delete[] weight;
            }
        }
        int find(int i){
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
        bool isSame(int i,int j){
            return find(i)==find(j);
        }
        int countSets(){
            return num_sets;
        }
    };

    class onewayUF{
        private:
        int size;
        int *arr;
        int num_sets;
        public:
        onewayUF(int Nsize):size(Nsize),num_sets(Nsize){//in fact,realsize=1+Nsize
            arr=new int [size+1];//real size is bigger
        }
        ~onewayUF(){
            if(arr!=nullptr){
                delete[] arr;
            }
        }
        bool isroot(int index,int root){
            while(arr[index]!=index){
                if(root==arr[index]){
                    return true;
                }
                index=arr[index];
            }
        }
        void connect(int i,int j){
            
        }
        int countSets(){
            return num_sets;
        }
    };
}