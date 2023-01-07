#pragma once
#include<iostream>
#include<string>
#include<vector>

namespace graphAPI{
    class abstractGraph{
        virtual int V()=0;
        virtual int E()=0;
        virtual void addEdge(int vx,int vy)=0;
                
    };
}