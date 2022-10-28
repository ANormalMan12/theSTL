#pragma once
#include<memory>
namespace theSTL{
    template<typename T>inline bool ascend(const T& x,const T&y){
        return x<y;
    }
    template<typename T>inline bool descend(const T& x,const T&y){
        return x>y;
    }
    template<typename T>inline void swap(T&x,T&y){T buf=x;x=y;y=buf;}
    const int shellExample[4]={4,3,2,1};
    const int shellExampleLen=4;
    template<typename T>void shell_sort(T*arr,int l,int r,bool cmp(const T&,const T&),const int*d,const int dlen){
        for(int dpos=0;dpos<dlen;++dpos){
            int h=d[dpos];
            for(int i=h;i<=r;++i){
                T tem=arr[i];
                int npos=i-h;
                for(;npos>=0&&cmp(tem,arr[npos]);npos-=h){
                    arr[npos+h]=arr[npos];//tem<npos so that it should be inserted behind
                }
                arr[npos+h]=tem;
            }
        }
    }
    template<typename T>void bubble_sort(T*arr,int l,int r,bool cmp(const T&,const T&)){
        T buf;
        int lastSwap=l-1;
        int top=r;
        while(top>l){
            lastSwap=l-1;
            for(int i=l;i<top;++i){
                if(cmp(arr[i+1],arr[i])){
                    swap(arr[i],arr[i+1]);
                    lastSwap=i;
                }
            }
            top=lastSwap;
        }
    }
    template<typename T>void insert_sort(T* arr,int l,int r,bool cmp(const T&,const T&)){
        T tembuf;
        for(int tr=l+1;tr<=r;++tr){//make [l,tr] with order
            for(int jpos=tr;jpos>0&&cmp(arr[jpos],arr[jpos-1]);--jpos){
                swap(arr[jpos],arr[jpos-1]);
            }
        }
    }
    template<typename T>void select_sort(T* arr,int l,int r,bool cmp(const T&,const T&)){
        for(int i=l;i<r;++i){
            int SmallestPos=i;//make sure i is equal or larger
            for(int j=i+1;j<=r;++j){
                if(cmp(arr[j],arr[SmallestPos])){
                    SmallestPos=j;
                }
            }
            swap(arr[SmallestPos],arr[i]);
        }
    }
    template<typename T>void merge_sort(T* arr,int l,int r,bool cmp(const T&,const T&)){
        if(l<r){
            int mid=(l+r)>>1;
            merge_sort(arr,l,mid,cmp);
            merge_sort(arr,mid+1,r,cmp);
            std::unique_ptr<T[]> buf{new T[r-l+1]};
            int buflen=0;
            int i=l,j=mid+1;
            while(true){
                if(i<=mid){
                    if(j<=r){
                        if(cmp(arr[i],arr[j])){
                            buf[buflen++]=arr[i++];
                        }else{
                            buf[buflen++]=arr[j++];
                        }
                    }else{
                        while(i<=mid){
                            buf[buflen++]=arr[i++];
                        }
                        break;
                    }
                }else{
                    while(j<=r){
                        buf[buflen++]=arr[j++];
                    }
                    break;
                }
            }
            memcpy(arr+l,(const T*)buf.get(),(r-l+1)*sizeof(T));
        }
    }
    template<typename T>void quick_sort(T* arr,int l,int r,bool cmp(const T&,const T&)){
        if(l<r){
            T pivot=arr[l];//identify the pivot
            int i=l,j=r;
            while(i<j){//put object in the right sides
                while(i<j&&cmp(pivot,arr[j])){//pivot<arr[j]
                    --j;
                }if(i<j){
                    arr[i++]=arr[j];//now the hole transfered to j
                }
                while(i<j&&cmp(arr[i],pivot)){//arr[i]<pivot
                    ++i;
                }if(i<j){
                    arr[j--]=arr[i];//now the hole transfered to i
                }
            }
            arr[i]=pivot;//now i==j,so there is no problem
            quick_sort(arr,l,i-1,cmp);
            quick_sort(arr,i+1,r,cmp);
        }
    }

}