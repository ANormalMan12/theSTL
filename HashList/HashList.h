#pragma once
#include<..\LinearList\List.h>
template<typename dataType> class HashList_Linked{
    using listType=List<dataType>;
    private:
    size_t _size;
    dataType arr*;

    public:
    HashList_Linked(size_t nsize):_size(nsize){
        arr=new dataType[_size];
    }
}