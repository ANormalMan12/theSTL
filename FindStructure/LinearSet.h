#include <iostream>
using namespace std;

namespace theSTL{
    template<typename T>class LinearSet {
        private:
            T *arr;
            int len;
            int maximum;
            int binary_search(T x);

        public:
            struct bad_LinearSet {
                int errnum;
            };
            LinearSet(int);
            LinearSet(const LinearSet &);
            ~LinearSet();
            LinearSet &operator=(const LinearSet &);
            void insert(T x);
            void erase(T x);
            bool isSubLinearSet(const LinearSet &);
            bool isMember(T x);
            void print();
            int size();
            int capacity();
            bool isEmpty();
            void clear();
            LinearSet LinearSetunion(const LinearSet &);
            LinearSet LinearSetdifference(const LinearSet &);
            LinearSet LinearSetsymmetricdifference(const LinearSet &);
            LinearSet LinearSetintsection(const LinearSet &);

            LinearSet operator-(const LinearSet &);
            LinearSet operator&(const LinearSet &);
            LinearSet operator|(const LinearSet &);
            LinearSet &operator-=(const LinearSet &);
            LinearSet &operator&=(const LinearSet &);
            LinearSet &operator|=(const LinearSet &);
            int operator()();

            template<typename T1> friend ostream& operator<<(ostream &, const LinearSet<T1> &); //output
            template<typename T1> friend istream &operator>>(istream &, LinearSet<T1> &); //input
    };

    template<typename T> int LinearSet<T>::binary_search(T x) {
        int l = 0;
        int r = len - 1;
        int m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (x == arr[m]) {
                return m;
            } else {
                if (x < arr[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return l;
    }

    template<typename T> LinearSet<T>::LinearSet(int capa) {
        if(capa<=0){
            throw bad_LinearSet{1};
        }
        maximum = capa;
        arr = new T [maximum];
        len = 0;
    }

    template<typename T> LinearSet<T>::LinearSet(const LinearSet<T> &another) {
        if(another.maximum<=0){
            throw bad_LinearSet{1};
        }
        len = another.len;
        maximum = another.maximum;
        //change
        arr = new T [maximum];
        for (int i = 0; i < another.len; ++i) {
            arr[i] = another.arr[i];
        }
    }

    template<typename T> LinearSet<T>::~LinearSet() {
        delete []arr;
    }

    template<typename T> LinearSet<T> &LinearSet<T>::operator=(const LinearSet<T> &another) {
        delete[] arr;//free the past arr
        len = another.len;
        maximum = another.maximum;
        arr = new T[maximum]; //reget area
        for (int i = 0; i < len; ++i) { //copy contents
            arr[i] = another.arr[i];
        }
        return *this;
    }

    template<typename T> void LinearSet<T>::insert(T x) {
        if (len >= maximum) {
            throw bad_LinearSet{2};
        } else {
            int pos = binary_search(x);
            for (int i = len - 1; i >= pos; --i) {
                arr[i + 1] = arr[i];
            }
            arr[pos] = x;
            ++len;
        }
    }

    template<typename T> void LinearSet<T>::erase(T x) {
        if (len == 0) {
            //throw bad_LinearSet{};
        } else {
            int pos = binary_search(x);
            if (arr[pos] == x) {
                for (int i = pos + 1; i < len; ++i) {
                    arr[i - 1] = arr[i];
                }
                --len;
            } else {
                //throw bad_LinearSet{};
            }
        }
    }

    template<typename T> bool LinearSet<T>::isSubLinearSet(const LinearSet<T> &another) {
        int nowpos = 0;
        for (int i = 0; i < another.len; ++i) {
            if (nowpos == len)
                return false;

            if (arr[nowpos] == another.arr[i]) {
                ++nowpos;
            } else if (arr[nowpos] > another.arr[i]) {
                return false;
            } else {
                while (nowpos < len && arr[nowpos] < another.arr[i]) {
                    ++nowpos;
                }
                if (nowpos == len || arr[nowpos] != another.arr[i]) {
                    return false;
                } else {
                    ++nowpos;
                }
            }
        }
        return true;
    }

    template<typename T> bool LinearSet<T>::isMember(T x) {
        return x == arr[binary_search(x)];
    }

    template<typename T> void LinearSet<T>::print() {
        cout << '{';
        for (int i = 0; i < len - 1; ++i) {
            cout << arr[i] << ',';
        }
        if (len >= 1)
            cout << arr[len - 1];
        cout << '}' << endl;
    }

    template<typename T> int LinearSet<T>::size() {
        return len;
    }

    template<typename T> int LinearSet<T>::capacity() {
        return maximum;
    }

    template<typename T> bool LinearSet<T>::isEmpty() {
        return len == 0;
    }

    template<typename T> void LinearSet<T>::clear() {
        len = 0;
    }

    template<typename T> LinearSet<T> LinearSet<T>::LinearSetunion(const LinearSet<T> &ano) {
        LinearSet ret{maximum + ano.maximum};
        int mypos = 0, anopos = 0;
        while (true) {
            if (mypos == len) {
                while (anopos != ano.len) {
                    ret.arr[ret.len++] = ano.arr[anopos++];
                }
                break;
            }
            if (anopos == ano.len) {
                while (mypos != len) {
                    ret.arr[ret.len++] = arr[mypos++];
                }
                break;
            }
            if (arr[mypos] == ano.arr[anopos]) {
                ret.arr[ret.len++] = arr[mypos];
                ++mypos, ++anopos;
            } else if (arr[mypos] < ano.arr[anopos]) {
                ret.arr[ret.len++] = arr[mypos++];
            } else {
                ret.arr[ret.len++] = ano.arr[anopos++];
            }
        }
        return ret;
    }

    template<typename T> LinearSet<T> LinearSet<T>::LinearSetdifference(const LinearSet<T> &ano) {
        LinearSet ret{maximum > ano.maximum ? maximum : ano.maximum};
        int anopos = 0;
        for (int mypos = 0; mypos < len; ++mypos) {
            while (anopos < ano.len && ano.arr[anopos] < arr[mypos])
                ++anopos;
            if (anopos == ano.len) {
                ret.arr[ret.len++] = arr[mypos];
                continue;
            } else {
                if (ano.arr[anopos] != arr[mypos]) {
                    ret.arr[ret.len++] = arr[mypos];
                }
                if (anopos != 0)
                    --anopos;
            }
        }
        return ret;
    }

    template<typename T> LinearSet<T> LinearSet<T>::LinearSetsymmetricdifference(const LinearSet<T> &ano) {
        LinearSet ret{maximum + ano.maximum};
        int mypos = 0, anopos = 0;
        while (true) {
            if (mypos == len) {
                while (anopos != ano.len) {
                    ret.arr[ret.len++] = ano.arr[anopos++];
                }
                break;
            }
            if (anopos == ano.len) {
                while (mypos != len) {
                    ret.arr[ret.len++] = arr[mypos++];
                }
                break;
            }
            if (arr[mypos] == ano.arr[anopos]) {
                ++mypos, ++anopos;
                continue;
            } else if (arr[mypos] < ano.arr[anopos]) {
                ret.arr[ret.len++] = arr[mypos++];
            } else {
                ret.arr[ret.len++] = ano.arr[anopos++];
            }
        }
        return ret;
    }

    template<typename T> LinearSet<T> LinearSet<T>::LinearSetintsection(const LinearSet<T> &ano) {
        LinearSet ret{maximum + ano.maximum};
        int mypos = 0, anopos = 0;
        while (mypos != len && anopos != ano.len) {
            if (arr[mypos] == ano.arr[anopos]) {
                ret.arr[ret.len++] = arr[mypos];
                ++mypos, ++anopos;
            } else if (arr[mypos] < ano.arr[anopos]) {
                mypos++;
            } else {
                anopos++;
            }
        }
        return ret;
    }

    template<typename T> LinearSet<T> LinearSet<T>::operator-(const LinearSet<T> &ano) {
        LinearSet ret{maximum > ano.maximum ? maximum : ano.maximum};
        int anopos = 0;
        for (int mypos = 0; mypos < len; ++mypos) {
            while (anopos < ano.len && ano.arr[anopos] < arr[mypos])
                ++anopos;
            if (anopos == ano.len) {
                ret.arr[ret.len++] = arr[mypos];
                continue;
            } else {
                if (ano.arr[anopos] != arr[mypos]) {
                    ret.arr[ret.len++] = arr[mypos];
                }
                if (anopos != 0)
                    --anopos;
            }
        }
        return ret;
    }

    template<typename T> LinearSet<T> LinearSet<T>::operator&(const LinearSet<T> &ano) {
        LinearSet ret{maximum + ano.maximum};
        int mypos = 0, anopos = 0;
        while (mypos != len && anopos != ano.len) {
            if (arr[mypos] == ano.arr[anopos]) {
                ret.arr[ret.len++] = arr[mypos];
                ++mypos, ++anopos;
            } else if (arr[mypos] < ano.arr[anopos]) {
                mypos++;
            } else {
                anopos++;
            }
        }
        return ret;
    }

    template<typename T> LinearSet<T> LinearSet<T>::operator|(const LinearSet<T> &ano) {
        LinearSet ret{maximum + ano.maximum};
        int mypos = 0, anopos = 0;
        while (true) {
            if (mypos == len) {
                while (anopos != ano.len) {
                    ret.arr[ret.len++] = ano.arr[anopos++];
                }
                break;
            }
            if (anopos == ano.len) {
                while (mypos != len) {
                    ret.arr[ret.len++] = arr[mypos++];
                }
                break;
            }
            if (arr[mypos] == ano.arr[anopos]) {
                ret.arr[ret.len++] = arr[mypos];
                ++mypos, ++anopos;
            } else if (arr[mypos] < ano.arr[anopos]) {
                ret.arr[ret.len++] = arr[mypos++];
            } else {
                ret.arr[ret.len++] = ano.arr[anopos++];
            }
        }
        return ret;
    }

    template<typename T> LinearSet<T> &LinearSet<T>::operator-=(const LinearSet<T> &ano) {
        LinearSet ret{this->LinearSetdifference(ano)};
        *this = ret;
        return *this;
    }

    template<typename T> LinearSet<T> &LinearSet<T>::operator&=(const LinearSet<T> &ano) {
        LinearSet ret{this->LinearSetintsection(ano)};
        *this = ret;
        return *this;
    }

    template<typename T> LinearSet<T> &LinearSet<T>::operator|=(const LinearSet<T> &ano) {
        LinearSet ret{this->LinearSetunion(ano)};
        *this = ret;
        return *this;
    }

    template<typename T> int LinearSet<T>::operator()() {
        return this->size();
    }

    template<typename T1> ostream &operator<<(ostream &out, const LinearSet<T1> &the_LinearSet) {
        out << '{';
        for (int i = 0; i < the_LinearSet.len - 1; ++i) {
            out << the_LinearSet.arr[i] << ',';
        }
        if (the_LinearSet.len >= 1)
            out << the_LinearSet.arr[the_LinearSet.len - 1];
        out << '}' << endl;
        return out;
    }

    template<typename T1> istream &operator>>(istream &in, LinearSet<T1> &myLinearSet) {
        int N;
        in >> N;
        T1 tem;
        for (int iN = 0; iN < N; ++iN) {
            in >> tem;
            if (!myLinearSet.isMember(tem))
                myLinearSet.insert(tem);
        }
        return in;
    }
}