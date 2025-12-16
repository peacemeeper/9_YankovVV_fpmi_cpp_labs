#pragma once
#include <iostream> 
#include <initializator_list>

class Vector {
int* arr;
size_t size_ = 0;
size_t capacity_ = 0;
public:
int& operator[](size_t index);
const int& operator[](size_t index);
Vector();
Vector(size_t size);
Vector(std::initializer_list<int> list);
~Vector();
void swap(Vector& another);
int At(size_t index);
const int At(size_t index) const;
size_t Size() const;
size_t Capacity();
void  Reserve(size_t newCapacity_);
void PushBack(int value);
void PopBack();
void Clear();
friend std::ostream& operator<<(std::ostream& output, const Vector& v);
};

