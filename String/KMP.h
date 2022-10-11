/**
 * @file KMP.h
 * @author Weiye Wang (wangweiye1205@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include"String.h"
#include<iostream>
namespace theSTL{
    class Pattern{
        private:
        char* subS;
        int* fail;
        int len;
        public:
        Pattern(const String& s):len(s._size){
            subS=new char[len+1];
            fail=new int[len+1];
            strcpy(subS,s._str);
            fail[0]=-1;
            int i=0,j=-1;
            while(i<len){
                if(j==-1||subS[i]==subS[j]){
                    ++i;++j;
                    fail[i]=j;
                }else{
                    j=fail[j];//come back
                }
            }
        }
        ~Pattern(){
            delete[] subS;
            delete[] fail;
        }
        void print_next(){
            for(int i=0;i<len;++i){
                std::printf("%d ",fail[i]);
            }
            putchar('\n');
        }
        int find_nextsub(const std::string& primary,int begin_pos){
            int j=0;
            while(begin_pos<primary.size()&&j<len){
                if(j==-1||primary[begin_pos]==subS[j]){
                    ++begin_pos;++j;//move forward
                }else{
                    j=fail[j];//move left
                }
                if(j==len){
                    return begin_pos-len;//1st exit
                }
            }
            return -1;//2nd exit
        }
    };
}