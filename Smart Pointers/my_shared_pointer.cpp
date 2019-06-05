#include <iostream>

namespace my_std{
    template<typename T>
    class shared_ptr{
        T* data;
        int* count;
        public:
            explicit shared_ptr(T* data)
            try:
                data{data},
                count{new int(1)}
                {}
            catch(...){
                delete data;
                throw;
            }

            ~shared_ptr() {
                --(*count);
                if(*count == 0){
                    std::cout<<"\nDeleting the data : "<<*data;
                    delete data;
                    delete count;
                }
            }

            shared_ptr(shared_ptr const& copy) : data{copy.data}, count{copy.count}{
                ++(*count);
            }

            shared_ptr& operator = (shared_ptr rhs){
                //Using copy and swap idom
                rhs.swap(*this);
                return *this;
            }

            shared_ptr& operator = (T* ndata){
                shared_ptr tmp(ndata);
                tmp.swap(*this);
                return *this;
            }

            void swap(shared_ptr& other) noexcept{
                    std::swap(data, other.data);
                    std::swap(count, other.count);
            }

            //const correct owned object
            T* operator -> () const {return data;}
            T& operator * () const {return *data;}

            T* get() const {return data;} //Getting access to smart pointer data
            explicit operator bool() const {return data;}
    };
}

int main(){
    my_std::shared_ptr<int> sp(new int(4));
    my_std::shared_ptr<int> sp2(sp);
    my_std::shared_ptr<int> sp3(new int(6));
    sp3 = sp2;
    std::cout<<"\n"<<*sp3;
    return 0;
}
