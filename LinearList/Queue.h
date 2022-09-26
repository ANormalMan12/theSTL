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
    enum QueueStates{FULLQUE,EMPTYQUE};
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
                throw FULLQUE;
            }else{
                arr[_rear]=x;
                _rear=nextpos;
            }
        }
        void dequeue(){
            if(_rear==_front){
                throw EMPTYQUE;
            }else{
                _front=(_front+1)%_capacity;
            }
        }
        datatype front(){
            if(_rear==_front){
                throw EMPTYQUE;
            }
            return arr[_front];
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
            Node* _rear;
        public:
            Queue_link(){
                _rear=&head;
                head.next=nullptr;
            }
            ~Queue_link(){
                Node*temp;
                while(head.next!=nullptr){
                    temp=head.next;
                    head.next=head.next->next;
                    delete temp;
                }
            }
            void enqueue(datatype x){
                _rear->next=new Node{nullptr,x};
                _rear=_rear->next;
            }
            void dequeue(){
                auto temp=head.next;
                delete temp;
                head.next=head.next->next;
                if(head.next==nullptr){
                    _rear=&head;
                }
            }
            datatype front(){
                if(head.next!=nullptr){
                    return head.next->data;
                }else{
                    throw{"Empty queue"};
                }
            }
            void clear(){
                Node*temp;
                while(head.next!=nullptr){
                    temp=_front;
                    head.next=head.next->next;
                    delete temp;
                }
            }
            bool empty(){
                return rear==&head;
            }
    };
}