#include <iostream>

namespace my_std{&
    template<typename T>
    class shared_ptr{
        T* data;
        int* count;
        public:
            explicit shared_ptr(T* data): data{data}, count{new int(1)} {}
            ~shared_ptr() {
                --(*count);
                if(*count == 0)
                    delete data;
            }
            shared_ptr(shared_ptr const& copy) : data{copy.data}, count{copy.data}{
                ++(*count);
            }
            shared_ptr operator = (shared_ptr const& rhs){
                //Temporarily preserve the older data members
                T* olddata = data;
                int* oldcount = count;

                //Doing an exception safe transfer
                data = rhs.data;
                count = rhs.count;

                //Updating the necessary counts
                ++(*count);
                --(*oldcount);

                if (*oldcount == 0)
                    delete data;
            }
            //const correct owned object
            T* operator -> () const {return data;}
            T& operator * () const {return *data;}

            T* get() const {return data;} //Getting access to smart pointer data
            explicit operator bool() const {return data;}
    };
}
