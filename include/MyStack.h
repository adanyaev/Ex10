// Copyright 2021 Artem Danyaev

#pragma once
#include <cstdlib>

template <class T> class MyStack {
 private:
  int size;
  T *stack;
  int current = -1;

 public:
  explicit MyStack(int s) : size(s) { stack = new T[size]; }

  MyStack(const MyStack &st) {
    stack = new T[st.size];
    for (int i = 0; i <= st.current; i++) {
      stack[i] = st.stack[i];
    }
    current = st.current;
  }

  bool isEmpty() const { return current == -1; }
  bool isFull() const { return current == size - 1; }
  void push(T elem) {
    if (!isFull()) {
      current++;
      stack[current] = elem;
    } else {
      stack = reinterpret_cast<T *>(realloc(stack, sizeof(T) * size * 2));
      size *= 2;
      current++;
      stack[current] = elem;
    }
  }

  T get() const {
    if (!isEmpty()) {
      return stack[current];
    }
  }

  T pop() {
    if (!isEmpty()) {
      current--;
      return stack[current + 1];
    }
  }
};
