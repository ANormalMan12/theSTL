/**
 * @file Array.h
 * @author Weiye Wang (wangweiye1205@outlook.com)
 * @brief The file contains the definition of template class Array
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
namespace theSTL{
    template<typename dataType> class Array{
        private:
        dataType* arr;
        int _size;
        int _len;
        
        public:
        enum states{yes,no=-1};
        Array(int new_size):_size(new_size),_len(0){
            arr=new dataType[_size];
        }
        ~Array(){
            delete[] arr;
        }
        int len(){return _len;}
        int size(){return _size;}
        states push_back(dataType data){
            if(_len>=_size){
                return no;
            }else{
                arr[_len++]=data;
                return yes;
            }
        }
        states insert_after(const dataType& data,int pos){
            if(pos>=len||len>=_size){
                return no;
            }else{
                for(int i=len;i>pos+1;--i){
                    arr[i]=arr[i-1];
                }
                arr[pos+1]=data;
                ++len;
                return yes;
            }
        }
        int erase(int pos){
            if(pos<0||pos>=_len){
                return -1;
            }else{
                dataType val=arr[pos];
                for(int i=pos+1;i<_len;++i){
                    arr[i-1]=arr[i];
                }
                --_len;
                return val;
            }
        }
        dataType& operator[](int pos){
            return arr[pos];
        }
    };
}