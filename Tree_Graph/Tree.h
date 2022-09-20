#include<forward_list>

namespace theSTL{
    template<typename datatype> class Tree{
        private:
            datatype val;
            forward_list<Tree*>children;
        public:
            

    };
}