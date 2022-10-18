#include<cstdlib>
#include<cstring>
#include<iostream>
namespace theSTL{
    /**
     * @brief A class aims 
     * 
     */
    class PatternBM{
        private:
        
        char* _pat;
        int _plen;
        
        int* _darr;
        int _dlen;
        void dF(){
            _dlen=26;
            _darr=new int[_dlen];
            for(int i=0;i<26;++i){
                _darr[i]=_plen;
            }
            for(int j=0;j<_plen -1;++j){
                _darr[_pat[j]-'a']=_plen-j-1;
            }
        }
        
        public:
            PatternBM(const char* input):_darr(nullptr){
                _plen=std::strlen(input);
                _pat=new char[_plen+1];
                strcpy(_pat,input);
                //select proper dfunc here
                dF();
            }
            ~PatternBM(){
                if(_darr!=nullptr)delete _darr;
                if(_pat !=nullptr)delete _pat;
            }
            int match(const char * m){
                int mlen=std::strlen(m);
                int pEnd,pCmp,mCmp;
                pEnd=_plen-1;
                do{
                    pCmp=_plen-1;
                    mCmp=pEnd;
                    while(pCmp>=0&&_pat[pCmp]==m[mCmp]){
                        --mCmp;--pCmp;
                    }
                    if(pCmp<0)return pEnd-_plen+1;
                    pEnd+=_darr[m[pEnd]-'a'];
                }while(pEnd<mlen);
                return -1;
            }
            void printBMarr(){
                std::cout<<_darr[0];
                for(int i=1;i<_dlen;++i){
                    std::cout<<' '<<_darr[i];
                }
                std::cout<<std::endl;
            }
    };
}