
namespace theSTL{
    template<typename datatype> class Vector{
        private:
        datatype* arr;
        int _size;
        public:
        Vector():arr(nullptr),_size(0){}
        Vector(newsize):_size(newsize){
            arr=new datatype[_size];
        }
        int size(){return _size;}
        void resize(int newsize){
            _size=newsize;
            if(arr!=nullptr){delete[] arr;}
            arr=new datatype[_size];
        }
        void insert(datatype x,int pos){
            
        }
    };
}