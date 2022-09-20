#pragma once

namespace theSTL{
    template<typename dataType> class Array{
        private:
        dataType* arr;
        int size;
        int len;
        
        public:
        enum states{yes,no=-1};
        Array(int newsize):len(newsize),len(0){
            arr=new dataType[size];
        }
        ~Array(){
            delete[] arr;
        }
        states push(dataType data){
            if(len>=size){
                return no;
            }else{
                arr[len++]=data;
                return yes;
            }
        }
        int binary_search(const dataType& aim){//return -1 when nothing has been found
            int l=0,r=len-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(aim==arr[mid]){
                    return mid;
                }else if(aim<arr[mid]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            if(l==r&&arr[l]==aim){
                return l;
            }else{
                return -1;
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