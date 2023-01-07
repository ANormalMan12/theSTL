#include<iostream>

namespace theSTL{
    template<typename elemType> class priorityQ{
        private:
            int _capacity;
            int _size;
            elemType* arr;
        public:
        priorityQ(int capacity){
            arr=new elemType[capacity];
            _capacity=capacity;
            _size=0;
        }
        ~priorityQ(){
            delete[] arr;
        }
        int size(){return _size;}
        int capacity(){return _capacity;}
        void push(const elemType& input){
            arr[_size++]=
        }
        elemType& top(){
            
        }
    };
}