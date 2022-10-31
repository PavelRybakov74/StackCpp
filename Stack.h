#pragma once
#include <iostream>

template <typename T>
class Stack {
private:
    int s;
    int capacity;
    T* array;
public:
    Stack();
    Stack(const std::initializer_list<T>& l);
    Stack(const Stack<T>& st);
    Stack(Stack<T>&& st) noexcept;
    ~Stack();

    void push(const T& t);
    void clear() noexcept;
    T pop();
    T check_pop() const;
    int size() const noexcept;
    bool empty() const noexcept;

    bool operator==(const Stack<T>& st) const noexcept;
    bool operator!=(const Stack<T>& st) const noexcept;
    Stack& operator=(const Stack<T>& st);
    Stack& operator=(Stack<T>&& st) noexcept;
    Stack& operator<<(const T& t);
    Stack& operator>>(T& t);

    template<class U>
    friend std::ostream& operator<< (std::ostream& out, const Stack<U>& st) noexcept;
};

template<class T>
Stack<T>::Stack() {
    capacity = 10;
    s = 0;
    array = new T[capacity];
}

template<class T>
Stack<T>::Stack(const std::initializer_list<T>& l) {
    s = 0;
    capacity = l.size() * 2;
    array = new T[capacity];
    for (auto i : l) {
        push(i);
    }
}

template<class T>
Stack<T>::Stack(Stack<T>&& st) noexcept :
    s(st.s),
    capacity(st.capacity),
    array(st.array)
{
    st.array = nullptr;
    st.s = 0;
    st.capacity = 0;
}

template<class T>
Stack<T>::Stack(const Stack<T>& st) {
    s = st.s;
    capacity = s * 2;
    array = new T[s];
    for (int i = 0; i < s; i++) {
        array[i] = st.array[i];
    }
}

template<class T>
Stack<T>::~Stack() {
    if(array!=nullptr)
        delete[] array;
}

template<class T>
void Stack<T>::push(const T& t) {
    if (s == capacity) {
        capacity *= 2;
        T* arr = new T[capacity];
        for (int i = 0; i < s; i++) {
            arr[i] = array[i];
        }
        delete[] array;
        array = arr;
    }
    s++;
    array[s-1] = t;
}

template<class T>
T Stack<T>::pop() {
    if (this->empty()) throw ("ERROR pop(): Stack is empty");
    else {
        T deleted = array[s - 1];
        s--;
        return deleted;
    }
}

template<class T>
void Stack<T>::clear() noexcept{
    this->s = 0;
}

template<class T>
int Stack<T>::size() const noexcept {
    return this->s;
}

template<class T>
T Stack<T>::check_pop() const {
    if (this->empty()) throw ("ERROR check_pop(): Stack is empty");
    else {
        return array[s - 1];
    }
}

template<class T>
bool Stack<T>::empty() const noexcept {
    return (s == 0);
}

template<class T>
std::ostream& operator<< (std::ostream& out, const Stack<T>& st) noexcept{
    for (int i = 0; i < st.s; i++) {
        out << st.array[i] << " ";
    }
    return out;
}


template<class T>
Stack<T>& Stack<T>::operator>> (T& t) {
    t = pop();
    return *this;
}


template<class T>
bool Stack<T>::operator==(const Stack<T>& st) const noexcept{
    if (st.capacity != this->capacity)
        return false;
    if (st.s != this->s)
        return false;
    for (int i = 0; i < st.s; i++) {
        if (st.array[i] != this->array[i])
            return false;
    }
    return true;
}

template<class T>
bool Stack<T>::operator!=(const Stack<T>& st) const noexcept {
    if (st.capacity == this->capacity)
        return false;
    if (st.s == this->s)
        return false;
    for (int i = 0; i < st.s; i++) {
        if (st.array[i] == this->array[i])
            return false;
    }
    return true;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st) {
    if (*this == st)
        return *this;
    s = st.s;
    capacity = s * 2;
    delete[] array;
    array = new T[s];
    for (int i = 0; i < s; i++) {
        array[i] = st.array[i];
    }
    return *this;
}

template<class T>
Stack<T>& Stack<T>::operator=(Stack<T>&& st) noexcept {

    if (this != &st)
    {
        delete[] array;

        s = st.s;
        capacity = s * 2;
        array = st.array;

        st.array = nullptr;
        st.s = 0;
        st.capacity = 0;
    }
    return *this;
}

template<class T>
Stack<T>& Stack<T>::operator<<(const T& t) {
    push(t);
    return *this;
}
