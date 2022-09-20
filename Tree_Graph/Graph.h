#pragma once
#include<iostream>
#include<cstring>
namespace mySTL{
    class Graph_m{//vertices:0,1,2,3
        private:
            bool** mat;
            int n;
        public:
        Graph_m(int newn):n(newn){
            mat=new bool*[n-1];
            for(int i=0;i<n-1;++i){
                mat[i]=new bool[n-1-i];
                std::memset(mat[i],0,(n-1-i)*sizeof(mat[i][0]));
            }
        }
        ~Graph_m(){
            for(int i=0;i<n-1;++i){
                delete[] mat[i];
            }
            delete[] mat;
        }
        void join(int i,int j){
            if(i<j){
                mat[i][j]=true;
            }else if(i>j){
                mat[j][i]=true;
            }else{
                std::cerr<<"i==j wrong in join";
            }
        }
        void cut(int i,int j){
            if(i<j){
                mat[i][j]=false;
            }else if(i>j){
                mat[j][i]=false;
            }else{
                std::cerr<<"i==j wrong in cut";
            }
        } 
        bool isjoint(int i,int j){
            if(i==j){
                return false;
            }else if(i<j){
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
            return ret;
        }
        void print_matrix(std::ostream& out){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(isjoint(i,j)){
                        out<<"1 ";
                    }else{
                        out<<"0 ";
                    }
                }
                out<<"Degree of "<<i<<" is "<<deg(i)<<'\n';
            }
        }
    };
}