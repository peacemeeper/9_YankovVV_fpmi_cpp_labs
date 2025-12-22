#include "forward_list_impl.h"
#include <cstddef>
#include <cstdint>
#include <iterator>

ForwardList::ForwardList() : first(nullptr), count(0) {
}

ForwardList::ForwardList(const ForwardList& src) : first(nullptr), count(0) {
    ListNode* src_node = src.first;
    ListNode* prev_node = nullptr;
    while (src_node != nullptr) {
        ListNode* new_node = new ListNode(src_node->data);
        if (first == nullptr) {
            first = new_node;
        } else {
            prev_node->next = new_node;
        }
        prev_node = new_node;
        src_node = src_node->next;
        ++count;
    }
}

ForwardList::ForwardList(size_t n, int32_t val) : first(nullptr), count(0) {
    for (size_t i = 0; i < n; ++i) {
        PushFront(val);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> vals) : first(nullptr), count(0) {
    for (auto it = std::rbegin(vals); it != std::rend(vals); ++it) {
        PushFront(*it);
    }
}

ForwardList& ForwardList::operator=(const ForwardList& src) {
    if (this == &src) {
        return *this;
    }

    Clear();

    ListNode* src_node = src.first;
    ListNode* prev_node = nullptr;
    while (src_node != nullptr) {
        ListNode* new_node = new ListNode(src_node->data);
        if (first == nullptr) {
            first = new_node;
        } else {
            prev_node->next = new_node;
        }
        prev_node = new_node;
        src_node = src_node->next;
        ++count;
    }

    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::PushFront(int32_t val) {
    ListNode* new_node = new ListNode(val);
    new_node->next = first;
    first = new_node;
    ++count;
}

void ForwardList::PopFront() {
    if (first == nullptr) {
        return;
    }

    ListNode* old_node = first;
    first = old_node->next;
    delete old_node;
    --count;
}

void ForwardList::Remove(int32_t val) {
    ListNode* curr = first;
    ListNode* prev = nullptr;

    while (curr != nullptr) {
        ListNode* next_node = curr->next;

        if (curr->data == val) {
            if (curr == first) {
                first = next_node;
            } else {
                prev->next = next_node;
            }
            delete curr;
            --count;
        } else {
            prev = curr;
        }
        curr = next_node;
    }
}

void ForwardList::Clear() {
    while (first != nullptr) {
        PopFront();
    }
}

bool ForwardList::Contains(int32_t val) {
    for (Iterator it = begin(); it != end(); ++it) {
        if (*it == val) {
            return true;
        }
    }
    return false;
}

void ForwardList::Display(std::ostream& os) {
    for (Iterator it = begin(); it != end(); ++it) {
        os << *it;
        if (std::next(it) != end()) {
            os << ' ';
        }
    }
}

int32_t ForwardList::GetFront() const {
    if (first == nullptr) {
        throw std::runtime_error("ForwardList is empty");
    }
    return first->data;
}

size_t ForwardList::GetSize() const {
    return count;
}
