#pragma once
#include<iostream>
namespace mySTL{
    class graph_m{//vertices:0,1,2,3
        private:
            bool mat**;
            int n;
        public:
        graph_m(int newn):n(newn){
            mat=new bool*[n-1];
            for(int i=0;i<n-1;++i){
                mat[i]=new bool[n-1-i];
                memset(mat[i],0,(n-1-i)*sizeof(mat[i][0]));
            }
        }
        ~graph_m(){
            for(int i=0;i<n-1;++i){
                delete[] mat[i];
            }
            delete[] mat;
        }
        void join(int i,int j){
            if(i<j){
                mat[i][j]=true;
            }else{
                mat[j][i]=true;
            }
        }
        void cut(int i,int j){
            if(i<j){
                mat[i][j]=false;
            }else{
                mat[j][i]=false;
            }
        } 
        bool isjoint(int i,int j){
            if(i<j){
                return mat[i][j];
            }else{
                return mat[j][i];
            }
        }
        int deg(int Vindex){
            int ret=0;//
            for(int i=0;i<Vindex;++i){
                if(mat[i][Vindex]){
                    ++ret;
                }
            }
            for(int i=Vindex+1;i<n;++i){
                if(mat[Vindex][i]){
                    ++ret;
                }
            }
            return deg;
        }
    }
}