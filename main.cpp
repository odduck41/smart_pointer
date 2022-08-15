#include <iostream>
#include <stdexcept>

template<class T, int length = 1>
class SmartPointer;
template <typename T, int l>
std::ostream &operator<<(std::ostream &os, SmartPointer<T, l> &sp);

template<class T, int length>
class SmartPointer{
public:
    const int& size = size_;
    SmartPointer(SmartPointer& x){
        obj = new T[length];
        for (int i = 0; i < x.size; ++i) {
            obj[i] = x.obj[i];
        }
        size_ = length;
    }
    SmartPointer(){
        if(length>1){
            obj = new T[length];
        }else if(length==1){
            obj = new T;
        }
        size_ = length;
    }
    ~SmartPointer(){
        if(length>1){
            delete[] obj;
        }else if(length==1){
            delete obj;
        }
    }
    T& operator*(){
        return *obj;
    }
    T& operator[](int index){
        if (index<length){
            return obj[index];
        }
        throw std::out_of_range("You are accessing forbidden memory");
    }
    T* operator+(int index){
        if (index<length){
            return obj+index;
        }
        throw std::out_of_range("You are accessing forbidden memory");
    }
    /*T* operator~(){
        return obj;
    }*/
private:
    T* obj;
    int size_;
    friend std::ostream &operator<< <>(std::ostream &os, SmartPointer<T, length> &sp);
};
template <typename T, int l>
std::ostream &operator<<(std::ostream &os, SmartPointer<T, l> &sp){
    return os << sp.obj;
}

