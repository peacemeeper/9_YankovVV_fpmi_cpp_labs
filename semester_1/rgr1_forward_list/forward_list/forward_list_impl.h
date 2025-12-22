#pragma once

#include <iterator>
#include <iostream>

class ForwardList {
private:
    struct ListNode {
        int32_t data;
        ListNode* next;

        explicit ListNode(int val) : data(val), next(nullptr) {
        }
    };

public:
    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int32_t;
        using pointer = value_type*;
        using reference = value_type&;

        explicit Iterator(ListNode* pos) : current(pos) {
        }

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const Iterator& rhs) const {
            return !(*this == rhs);
        }

        reference operator*() const {
            return current->data;
        }

        pointer operator->() {
            return &current->data;
        }

    private:
        ListNode* current;
    };

    Iterator begin() {
        return Iterator(first);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator begin() const {
        return Iterator(first);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    Iterator Begin() {
        return begin();
    }

    Iterator End() {
        return end();
    }

    Iterator Begin() const {
        return begin();
    }

    Iterator End() const {
        return end();
    }

    ForwardList();
    ForwardList(const ForwardList& src);
    ForwardList(size_t n, int32_t val);
    ForwardList(std::initializer_list<int32_t> vals);
    ForwardList& operator=(const ForwardList& src);
    ~ForwardList();
    void PushFront(int32_t val);
    void PopFront();
    void Remove(int32_t val);
    void Clear();
    bool Contains(int32_t val);
    void Display(std::ostream& os);
    int32_t GetFront() const;
    size_t GetSize() const;

private:
    ListNode* first;
    size_t count;
};
