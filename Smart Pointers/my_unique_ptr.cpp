#include <iostream>

namespace my_std {
    template<typename T>
    class unique_ptr {
        T* data;
        public:
            explicit unique_ptr(T* data) : data { data } {}
            ~unique_ptr() {
                delete data;
            }
            unique_ptr(unique_ptr const&) = delete; //deleting the copy constructor
            unique_ptr& operator = (unique_ptr const&) = delete; //deleting the equality operation
            T* operator -> () const { return data; } //defining const explicitly for non modifying function
            T& operator * () const { return *data; } //defining const explicitly for non modifying function
            T* get() const { return data; } // getting access to smart pointer state
            T* release() {
                T* result = nullptr;
                std::swap(result, data);
                return result;
            }
            explicit operator bool() const { return data; }
    };
}

int main() {
    my_std::unique_ptr<int>p1(new int(5));
    my_std::unique_ptr<int>p2(new int(6));
    std::cout<<*p2;
    return 0;
}
