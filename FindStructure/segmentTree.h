
namespace theSTL{
    template<typename dataType> class segTree{
        private:
            dataType arr*;
            cosnt int _size;
        public:
            segTree(int nsize):_size(nsize){arr=new dataType[4*_size]};
            ~segTree(){if(arr!=nullptr)delete[] arr;}
    };
}