#include "vector_impl.h"

    int& operator[](size_t index) {
        return arr[index];
    }

         const int& operator[](size_t index) const {
        return arr[index];
    }


	Vector() : size_(0), capacity_(0) {}


	Vector(size_t size) :size_(size), capacity_(size) {
		arr = new int[capacity_];

		for (size_t i = 0; i < size_; ++i) {
			arr[i] = 0;
		}
	}

	
	Vector(std::initializer_list<int> list) : size_(list.size()) , capacity_(list.size()) {
		arr = new int[capacity_];

		size_t a = 0;

		for (int value : list) {
			arr[a++] = value;
		}
	}

	~Vector() {
		delete[] arr;
 	}

	void swap(Vector& another) {
		std::swap(size_, another.size_);
		std::swap(arr, another.arr);
		std::swap(capacity_, another.capacity_);
	}

	int At(size_t index) {
		if (index >= size_) {
			throw std::out_of_range("Индекс за границами вектора");
		}
		return arr[index];
	}


	const int At(size_t index) const {
		if (index > size_) {
			throw std::out_of_range("Индекс за границами вектора");
		}
		return arr[index];
	}

	size_t Size() const {
		return size_;
	}


	size_t Capacity() {
		return capacity_;
	}

	
	void  Reserve(size_t newCapacity_) {
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


	void PushBack(int value) {
		if (size_ == capacity_) {
			size_t newCapacity_;
			if (capacity_ == 0) {
				newCapacity_ = 1;
			}
			else newCapacity_ = capacity_ + capacity_ ;
			Reserve(newCapacity_);
		}
	}

	
	void PopBack() {
		if (size_ > 0) {
			size_--;
		}
	}


	void Clear() {
		size_ = 0;
	}

};

std::ostream& operator<<(std::ostream& output, const Vector& v) {
	for (size_t i = 0; i < v.Size(); ++i) {
		output << v[i] << " ";
	}
	return output;
}
