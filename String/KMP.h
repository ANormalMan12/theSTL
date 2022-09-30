#include"String.h"

namespace theSTL{
    class Pattern{
        private:
        char* subS;
        int* next;
        int len;
        public:
        Pattern(String s):len(s._size){
            subS=new char[len];
            next=new int[len];
            strcpy(subS,s._str);
        }
    
    };
}