#include<string>
namespace theSTL{
    long long Hash(std::string x){
        int xlen=x.length();
        long long tem=1;
        long long ret=0;
        for(int i=xlen-1;i>=0;--i){
            ret+=tem*x[i];
            tem*=128;
        }
        return ret;
    }
}