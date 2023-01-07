#pragma once
#include<iostream>
#include<vector>
namespace graphAlgorithm{
    using namespace std;
    struct graph{
        typedef vector<int> VI;
        VI info,next,to;
        graph(int numV,int numE){
            info.resize(numV);
            next.resize(0);//预留push)back空间，随vector维护size
            next.reserve(numE);
            to.resize(0);
            to.reserve(numE);
        }
    };
    
}