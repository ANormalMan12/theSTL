#include<fstream>
#include<iostream>
#pragma once
using namespace std;
namespace mySTL{
    enum fileState{notFound,pass,wrong};
    fileState fileSame(const string& fileX,const string& fileY){
        ifstream xin(fileX);
        ifstream yin(fileY);
        if(!xin.is_open()||!yin.is_open()){
            cerr<<"Files weren't found";
            return notFound;
        }
        char Xc,Yc;
        while((Xc=xin.get())==(Yc=yin.get())&&Xc!=EOF);
        xin.close();
        yin.close();
        if(Xc==Yc){
            return pass;
        }else{
            return wrong;
        }
    }
    
}