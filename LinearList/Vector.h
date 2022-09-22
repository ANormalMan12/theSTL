/**
 * @file Vector.h
 * @author Weiye Wang (wangweiye1205@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include<iostream>
#include<cstring>
#include<cstdlib>
namespace theSTL{
    template<typename datatype> class Vector{
        private:
            datatype* arr;
            int _capacity;
            int _len;
        public:
        Vector():arr(nullptr),_capacity(0),_len(0){}
        Vector(newcapacity):_capacity(newcapacity),_len(0){
            arr=new datatype[_capacity];
        }
        int size(){return _capacity;}
        int len(){return _len;}
        void resize(int newcapacity){
            auto temp=arr;
            arr=new datatype[newcapacity];
            if(temp!=nullptr){
                std::memcpy(arr,temp,
                    std::min(newcapacity,_capacity)*capacityof(arr[0]);
                delete[] temp;
            }
            _capacity=newcapacity;
            if(_len>=_capacity){
                _len=_capacity;
            }
        }
        /**
         * @brief insert data after pos
         * 
         * @param data what to be inserted
         * @param pos identify where new data was put after
         */
        void insert_after(const dataType& data,int pos){
            if(pos>=_len||_len>=_capacity){
                throw{};
            }else{
                for(int i=len;i>pos+1;--i){
                    arr[i]=arr[i-1];
                }
                arr[pos+1]=data;
                ++len;
            }
        }
        /**
         * @brief erase the object at pos position
         * 
         * @param pos 
         */
        void erase(int pos){
            if(pos<0||pos>=len){
                throw{};
            }else{
                datatype val=arr[pos];
                for(int i=pos+1;i<len;++i){
                    arr[i-1]=arr[i];
                }
                --len;
            }
        }
    };
}