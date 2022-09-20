#include"Graph.h"
#include<iostream>

namespace test{
    using namespace std;
    void testMatrixGraphBasics(){
        cout<<"Create a Graph with 6 vertices"<<endl;
        theSTL::Graph_m mGraph{6};
        cout<<"out put the matrix now\n";
        mGraph.print_matrix(cout);
        cout<<"join these vertices:"<<endl;
        cout<<"{0,1},{0,3},{3,5},{3,2},{5,1},{2,4},"<<endl;
        mGraph.join(0,1);mGraph.join(0,3);
        mGraph.join(3,5);mGraph.join(3,2);
        mGraph.join(5,1);mGraph.join(2,4);
        cout<<"out put the matrix now\n";
        mGraph.print_matrix(cout);
    }
}