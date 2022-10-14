#pragma once
#include<memory>
namespace theSTL{
    template<typename T>inline bool ascend(const T& x,const T&y){
        return x<y;
    }
    template<typename T>inline bool descend(const T& x,const T&y){
        return x>y;
    }
    template<typename T>void shell_sort(T*arr,int l,int r,bool cmp(const T&,const T&)){
        int h=1;
        while(h<(r-l+1)/3){
            h=3*h+1;//get array of steps
        }
        while(h>=1){
            
        }
    }
    template<typename T>void bubble_sort(T*arr,int l,int r,bool cmp(const T&,const T&)){
        T buf;
        for(int i=l;i<r;++i){
            for(int k=i;k<r;++k){
                if(cmp(arr[k],arr[k+1])){
                    buf=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=buf;
                }
            }
        }
    }
    template<typename T>void insert_sort(T* arr,int l,int r,bool cmp(const T&,const T&)){
        T tembuf;
        for(int tr=l+1;tr<=r;++tr){//make [l,tr] with order
            for(int jpos=tr;jpos>0&&cmp(arr[jpos],arr[jpos-1]);--jpos){
                tembuf=arr[jpos];
                arr[jpos]=arr[jpos-1];
                arr[jpos-1]=tembuf;
            }
        }
    }
    template<typename T>void select_sort(T* arr,int l,int r,bool cmp(const T&,const T&)){
        for(int i=l;i<r;++i){
            int SmallestPos=i;
            for(int j=i+1;j<=r;++j){
                if(cmp(arr[j],arr[SmallestPos])){
                    SmallestPos=j;
                }
            }
            T tem=arr[i];
            arr[i]=arr[SmallestPos];
            arr[SmallestPos]=tem;
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
            T wall=arr[l];//empty hole was at l
            int i=l,j=r;
            while(i<j){
                while(i<j&&cmp(wall,arr[j])){//wall<arr[j]
                    --j;
                }if(i<j){
                    arr[i++]=arr[j];//now the hole transfered to j
                }
                while(i<j&&cmp(arr[i],wall)){//arr[i]<wall
                    ++i;
                }if(i<j){
                    arr[j--]=arr[i];//now the hole transfered to i
                }
            }
            arr[i]=wall;//now i==j,so there is no problem
            quick_sort(arr,l,i-1,cmp);
            quick_sort(arr,i+1,r,cmp);
        }
    }

}