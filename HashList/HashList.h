#pragma once
#include<..\LinearList\List.h>
namespace theSTL{
    template<typename dataType> class HashList_Linked{
        using listType=List<dataType>;
        
        private:
        size_t _size;
        listType arr*;

        public:
        HashList_Linked(size_t nsize):_size(nsize){
            arr=new listType[_size];
        }
        ~HashList_Linked(){
            delete[] arr;
        }
    };
}