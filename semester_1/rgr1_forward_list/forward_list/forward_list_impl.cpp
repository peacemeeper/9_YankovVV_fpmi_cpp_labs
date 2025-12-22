#include "forward_list_impl.h"
#include <stdexcept>

ForwardList::ForwardList() : first(nullptr), count(0) {}

ForwardList::ForwardList(const ForwardList& src) : first(nullptr), count(0) {
    ListNode* src_node = src.first;
    ListNode* last_node = nullptr;
    
    while (src_node != nullptr) {
        ListNode* new_node = new ListNode(src_node->data);
        
        if (first == nullptr) {
            first = new_node;
        } else {
            last_node->next = new_node;
        }
        
        last_node = new_node;
        src_node = src_node->next;
        count++;
    }
}

ForwardList::ForwardList(size_t n, int32_t val) : first(nullptr), count(0) {
    for (size_t i = 0; i < n; ++i) {
        PushFront(val);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> vals) : first(nullptr), count(0) {
    for (auto it = vals.end(); it != vals.begin(); ) {
        --it;
        PushFront(*it);
    }
}

ForwardList& ForwardList::operator=(const ForwardList& src) {
    if (this == &src) return *this;
    
    Clear();
    
    ListNode* src_node = src.first;
    ListNode* last_node = nullptr;
    
    while (src_node != nullptr) {
        ListNode* new_node = new ListNode(src_node->data);
        
        if (first == nullptr) {
            first = new_node;
        } else {
            last_node->next = new_node;
        }
        
        last_node = new_node;
        src_node = src_node->next;
        count++;
    }
    
    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::Clear() {
    while (first != nullptr) {
        ListNode* temp = first;
        first = first->next;
        delete temp;
    }
    count = 0;
}

void ForwardList::PushFront(int32_t val) {
    ListNode* new_node = new ListNode(val);
    new_node->next = first;
    first = new_node;
    count++;
}

void ForwardList::PopFront() {
    if (first == nullptr) return;
    
    ListNode* temp = first;
    first = first->next;
    delete temp;
    count--;
}

int32_t ForwardList::GetFront() const {
    if (first == nullptr) {
        throw std::runtime_error("Список пуст");
    }
    return first->data;
}

bool ForwardList::Contains(int32_t val) {
    for (Iterator it = begin(); it != end(); ++it) {
        if (*it == val) {
            return true;
        }
    }
    return false;
}

bool ForwardList::ContainsSimple(int32_t val) {
    ListNode* current = first;
    
    while (current != nullptr) {
        if (current->data == val) {
            return true;
        }
        current = current->next;
    }
    
    return false;
}

void ForwardList::Remove(int32_t val) {
    ListNode* current = first;
    ListNode* prev = nullptr;
    
    while (current != nullptr) {
        if (current->data == val) {
            if (current == first) {
                first = current->next;
            } else {
                prev->next = current->next;
            }
            
            ListNode* to_delete = current;
            current = current->next;
            delete to_delete;
            count--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

size_t ForwardList::GetSize() const {
    return count;
}

void ForwardList::Display(std::ostream& os) {
    bool first_element = true;
    
    for (Iterator it = begin(); it != end(); ++it) {
        if (!first_element) {
            os << ' ';
        }
        os << *it;
        first_element = false;
    }
}

void ForwardList::DisplaySimple(std::ostream& os) {
    ListNode* current = first;
    bool first_element = true;
    
    while (current != nullptr) {
        if (!first_element) {
            os << ' ';
        }
        os << current->data;
        first_element = false;
        current = current->next;
    }
}
