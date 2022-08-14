#include <iostream>
#include <stdexcept>

template<class T, int length>
class SmartPointer{
public:
    const int& size = size_;
    SmartPointer(int val){
        if(length>1){
            obj = new T[length];
            *obj = val;
        }else if(length==1){
            obj = new T;
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
    T& operator+(int index){
        if (index<length){
            return obj+index;
        }
        throw std::out_of_range("You are accessing forbidden memory");
    }
    T* operator~(){
        return obj;
    }

private:
    T* obj;
    int size_;
};

int main(){
    SmartPointer<int, 10> a;
    std::cout<<~a;
}
