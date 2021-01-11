#include <iostream>
using namespace std;

template <typename T>
class Array{
public:
    Array(int capacity):size(0),capacity(capacity),data(new T[capacity]){}
    Array():size(0),capacity(5),data(new T[capacity]){}

    int getSize(){
        return size;
    }
    int getCapacity(){
        return capacity;
    }
    bool isEmpty(){
        return size == 0;
    }
    void add(int index, T e){
        if (index < 0 || index > size){//这里的index为什么只能取小于或者等于size的值? 因为如果去了比size大的值, 那么这个数组就不是紧凑排列的了
            cout<<"Add failed, index["<<index<<"]illegal, mast index >= 0 or index <= size"<<endl;
        }
        if (size == capacity){
            reSize(size * 2);
        }
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }
    void addFirst(T e){
        add(0,e);
    }
    void addLast(T e){
        add(size, e);
    }
    T remove(int index){
        T dataTemp = data[index];
        if (index < 0 || index > size){//这里的index为什么只能取小于或者等于size的值? 因为如果去了比size大的值, 那么这个数组就不是紧凑排列的了
            cout<<"Add failed, index["<<index<<"]illegal, mast index >= 0 or index <= size"<<endl;
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size < capacity / 4){
            reSize(capacity /2);
        }
        return dataTemp;
    }
    T removeFirst(){
        return remove(0);
    }
    T removeLast(){
        return remove(size - 1);
    }
    int removeElement(T e){
        int index = find(e);
        if (index != -1){
            remove(index);
            return index;
        }
        return -1;
    }
    void set(int index, T newData){
        if (index < 0 || index > size){//这里的index为什么只能取小于或者等于size的值? 因为如果去了比size大的值, 那么这个数组就不是紧凑排列的了
            cout<<"Add failed, index["<<index<<"]illegal, mast index >= 0 or index <= size"<<endl;
        }
        data[index] = newData;
    }
    void setFirst(T newData){
        set(0,newData);
    }
    void setLast(T newData){
        set(size - 1, newData);
    }
    bool contains(T e){
        for (int i = 0; i < size; i++) {
            if (data[i] == e){
                return true;
            }
        }
        return false;
    }
    T get(int index){
        if (index < 0 || index > size){//这里的index为什么只能取小于或者等于size的值? 因为如果去了比size大的值, 那么这个数组就不是紧凑排列的了
            cout<<"Add failed, index["<<index<<"]illegal, mast index >= 0 or index <= size"<<endl;
        }
        return data[index];
    }
    int find(T e){
        for (int i = 0; i < size; i++) {
            if (data[i] == e){
                return i;
            }
        }
        return -1;
    }
    void printAll(){
        std::cout << "Array: size = " << size << ", capacity = " << getCapacity() << std::endl;
        std::cout << "[";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i != size - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        std::cout << std::endl;
    }
public:
    int size;
    int capacity;
    T *data;

    void reSize(int newCapacity){
        auto *newData = new T[newCapacity];
        auto *oldData = data;
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        data = newData;
        capacity = newCapacity;
        delete []oldData;
    }
};