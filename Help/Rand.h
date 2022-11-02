#pragma once
#include<iostream>
#include<ctime>

namespace RAND{
    using namespace std;
    int getRand(int n){
        return (long long)rand()*rand()%n;
    }
    int* newRandArr(int arrlen,int lBound,int uBound){
        //remember to delete on your own
        int n=uBound-lBound+1;
        int* ret=new int [arrlen];
        std::srand((unsigned)time(0)+rand());
        for(int i=0;i<arrlen;++i){
            ret[i]=getRand(n)+lBound;
        }
        return ret;
    }
}