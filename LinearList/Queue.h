/**
 * @file Queue.h
 * @author Weiye Wang (wangweiye1205@outlook.com)
 * @brief The file contains two kinds of definitions of queue
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include"List.h"

namespace theSTL{
    /**
     * @brief A ring queue based on array,
     * using real-datasize to initialize
     * 
     * @attention _capacity means the real size of array
     * @tparam datatype 
     */
    template<typename datatype> class Queue_ring{
        private:
            int _rear,_front;
            int _capacity;
            datatype* arr;
        public:
            Queue_ring(int capacity):_capacity(capacity+1),_rear(0),_front(0){
                arr=new datatype[_capacity];
            }
            ~Queue_ring(){
                delete[] arr;
            }
            void enqueue(datatype x){
                int nextpos=(_rear+1)%_capacity;
                if(nextpos==_front){
                    throw "Full queue";
                }else{
                    _rear=nextpos;
                    arr[_rear]=x;
                }
            }
            void dequeue(){
                if(_rear==_front){
                    throw"Empty";
                }else{
                    _front=(_front+1)%_capacity;
                }
            }
            datatype front(){
                return arr[front];
            }
            void clear(){
                _rear=_front=0;
            }
            bool empty(){
                return _rear==_front;
            }
            int dataCapacity(){
                return _capacity-1;
            }
    };
    template<typename datatype> class Queue_link{
        typedef forwardLinkedNode<datatype> Node;
        private:
            Node head;
            Node* rear,front;
        public:
            Queue_link(){
                head
            }
            ~Queue_link();
            void enqueue(datatype);
            void dequeue();
            datatype getfront();
            void clear();
            bool empty();
            int capacity();
    };
}