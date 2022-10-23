#pragma once
//#include"../LinearList/List.h"
namespace theSTL{
    template<typename dataType> class BTreeBase{
        private:
        int _size;
        public:
        int size(){return _size;}
        virtual void insert(const dataType&)=0;
        virtual bool erase(const dataType&)=0;
        virtual dataType* find(const dataType&)=0;
        virtual void printPreOrderTraverse()=0;
        virtual void printInOrderTraverse()=0;
        virtual void printPostOrderTraverse()=0;
    };
}