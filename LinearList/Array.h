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
        int size;
        int len;
        
        public:
        enum states{yes,no=-1};
        Array(int newsize):size(newsize),len(0){
            arr=new dataType[size];
        }
        ~Array(){
            delete[] arr;
        }
        states push_back(dataType data){
            if(len>=size){
                return no;
            }else{
                arr[len++]=data;
                return yes;
            }
        }
        
        states insert_after(const dataType& data,int pos){
            if(pos>=len||len>=size){
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
            if(pos<0||pos>=len){
                return -1;
            }else{
                int val=arr[pos];
                for(int i=pos+1;i<len;++i){
                    arr[i-1]=arr[i];
                }
                --len;
                return val;
            }
        }
    };
}