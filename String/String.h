/**
 * @file String.h
 * @author Weiye Wang (wangweiye1205@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include<cstring>
class Pattern;//Extern define so that friend can be claimed
namespace theSTL{
    class String{
        friend class Pattern;
        private:
        char* _str;
        int _size;
        public:
        String():_str(nullptr),_size(0){}
        String(const char* s){
            _size=std::strlen(s);
            _str=new char[_size+1];
            std::strcpy(_str,s);
        }
        String& operator=(const char* s){
            if(_str!=nullptr){
                delete[] _str;
            }
            _size=std::strlen(s);
            _str=new char[_size+1];
            std::strcpy(_str,s);
            return *this;
        } 
        /* String& operator=(const String& anoS){
            if(_str!=nullptr){
                delete[] _str;
            }
            _size=anoS._size;
            _str=new char[_size+1];
            std::strcpy(_str,anoS._str);
            return *this;
        } */
        String& operator=(String&& anoS){
            if(_str!=nullptr){
                delete[] _str;
            }
            _size=anoS._size;
            _str=anoS._str;
            anoS._str=nullptr;
            anoS._size=0;
            return *this;
        }
        ~String(){
            if(_str!=nullptr){
                delete[] _str;
            }
        }
        bool operator==(const String& anoS)const{
            if(anoS._size==_size){
                for(int i=0;i<_size;++i){
                    if(anoS._str[i]!=_str[i]){
                        return false;//conflict
                    }
                }
                return true;//if they are the same
            }else{
                return false;//conflict
            }
        }
        int size()const{return _size;}
        /**
         * @brief The function aims to return references of String
         * but there are problems when comparison happens
         * 
         * @param pos 
         * @return char& 
         */
        char& operator[](int pos){
            return _str[pos];
        }
        char& at(int pos){
            if(pos>=0&&pos<_size){
                return _str[pos];
            }else{
                throw "RANGE ERROR";
            }
        }
    };
}