#ifndef SHAREDPTR_H
#define SHAREDPTR_H
#include <cstdio>

template<class T>
class SharedPtr
{
private:
T *ptr;
int count;
void clear(){
    if(count == 1){
        count = 0;
        delete ptr;
    }
    else
    --count;};
public:
SharedPtr():ptr(nullptr),count(0){};
SharedPtr(T *p):ptr(p),count(1){};
SharedPtr(SharedPtr<T> &old):ptr(old.ptr),count(old.count){++count;};
SharedPtr<T> &operator= (const SharedPtr<T> &old){
if(this != &old){
    clear();
ptr = old.ptr;
count = old.count;
++count;
}
return *this;
};
~SharedPtr(){clear();}
T* operator->(){return ptr;}
T& operator*(){return *ptr;}
};
#endif
