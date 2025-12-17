#include "vector_impl.h"

    int& Vector::operator[](size_t index) {
        return arr[index];
    }

         const int& Vector::operator[](size_t index) const {
        return arr[index];
    }


	Vector::Vector() : size_(0), capacity_(0) {}


	Vector::Vector(size_t size) :size_(size), capacity_(size) {
		arr = new int[capacity_];

		for (size_t i = 0; i < size_; ++i) {
			arr[i] = 0;
		}
	}

	
	Vector::Vector(std::initializer_list<int> list) : size_(list.size()) , capacity_(list.size()) {
		arr = new int[capacity_];

		size_t a = 0;

		for (int value : list) {
			arr[a++] = value;
		}
	}

     Vector::Vector(const Vector& other): size_(other.size_), capacity_(other.capacity_), array_(new int[size_]){
    std::copy(other.array_, other.array_ + size_, array_);
}

    Vector& Vector::operator= (const Vector& other){
    if (this == &other)
        return *this;

    size_ = other.size_;
    capacity_ = other.capacity_;
    delete[] array_;
    array_ = new int[size_];
    std::copy(other.array_, other.array_ + size_, array_);
    return *this;
}

	Vector::~Vector() {
		delete[] arr;
 	}

	void Vector::swap(Vector& another) {
		std::swap(size_, another.size_);
		std::swap(arr, another.arr);
		std::swap(capacity_, another.capacity_);
	}

	int& Vector::At(size_t index) {
		if (index >= size_) {
			throw std::out_of_range("Индекс за границами вектора");
		}
		return arr[index];
	}


	const int& Vector::At(size_t index) const {
		if (index > size_) {
			throw std::out_of_range("Индекс за границами вектора");
		}
		return arr[index];
	}

	size_t Vector::Size() const {
		return size_;
	}


	size_t Vector::Capacity() {
		return capacity_;
	}

	
	void Vector::Reserve(size_t newCapacity_) {
		if (newCapacity_ <= capacity_) {
			return;
		}
		int* newArr = new int[newCapacity_];

		for (size_t i = 0; i < size_; ++i) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		capacity_ = newCapacity_;
	}


	void Vector::PushBack(int value) {
		if (size_ == capacity_) {
			size_t newCapacity_;
			if (capacity_ == 0) {
				newCapacity_ = 1;
			}
			else newCapacity_ = capacity_ + capacity_ ;
			Reserve(newCapacity_);
		}
	}

	
	void Vector::PopBack() {
		if (size_ > 0) {
			size_--;
		}
	}


	void Vector::Clear() {
		size_ = 0;
	}

};

std::ostream& operator<<(std::ostream& output, const Vector& v) {
	for (size_t i = 0; i < v.Size(); ++i) {
		output << v[i] << " ";
	}
	return output;
}
