// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>
#include <string>

template<typename T, int size>
class TPQueue {

 private:
  T* arr;
  int count1, begin1, end1;
  int goAhead(int index){
    int result = ++index;
    if(result > size)
        result -= size +1;
    return result;
  }

 public:
  TPQueue(): begin1(0), end1(0), count1(0) {
    arr = new T[size + 1];
  }
  ~TPQueue() {
    delete[] arr;
  }
  
  bool isEmpty() const {
    return count1 == 0;
  }
  
  bool isFull() const {
    return count1 == size;
  }

  void push(const T& arr) {
    if (isFull()) {
        throw std::string("is Full!");
    } else {
        int flag = end1;
        int i = begin1;
        while(i < end1){
            if(value.prior > arr[i].prior) {
                flag = i;
                break;
            }
            i++;
        }
        int j = end1;
        while(j > flag) {
            arr[j % size] = arr[(j - 1) % size]
            j--;
        }
        arr[flag % size] = value;
        count1++;
        end1++;
    }
  }

  T pop() {
    if (isEmpty()){
        throw std::string("is Empty!");
    } else {
        T out = arr[begin1];
        count1--;
        begin1 = goAhead(begin1);
        return out;    
    }
  }
  
  T get() const {
    assert(count1 > 0);
    return arr[begin1];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
