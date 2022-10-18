
namespace theSTL{
    template<typename dataType>class BStree{
        private:
        dataType data;//key should be stored in data
        BStree* lChild,rChild;
        
        public:
        BStree():lChild(nullptr),rChild(nullptr){};
        ~BStree(){if(!lChild){delete lChild};
                  if(!rChild)delete rChild;}
        void insert(dataType ndata){
            if(ndata)
        }
    };
}