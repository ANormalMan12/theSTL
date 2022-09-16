#include<forward_list>

namespace mySTL{
    template<typename datatype> class Tree{
        private:
            datatype val;
            forward_list<Tree*>children;
        public:
            

    };
}