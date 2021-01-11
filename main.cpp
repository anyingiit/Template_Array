#include <iostream>
#include "Array.h"


void heTest();
int main() {
    std::cout << "Hello, World!" << std::endl;
    Array<int> *array = new Array<int>();
    for (int i = 0; i < 10; ++i) {
        array->addLast(i);
        array->printAll();
    }
    array->add(1,100);
    array->printAll();
    array->addFirst(-1);
    array->printAll();
    array->remove(2);
    array->printAll();
    array->removeElement(4);
    array->printAll();
    array->removeLast();
    array->printAll();
    array->removeFirst();
    array->printAll();
    for(int i = 0; i < 4; ++i) {
        array->removeFirst();
        array->printAll();
    }
    array = nullptr;
    delete array;
    return 0;
}
