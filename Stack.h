#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;
template <class T>
class stack {
private:
    int top1;
    int size;
    T* Stack;

public:
    class fullerror {};         // Handles first catch block for stack overflow
    class emtyerror {};         // Handles second catch block for stack underflow
    class toperror {};          // Handles trying to peek from stack underflow

    stack(int);    //Default constructor
    ~stack();   //Destructor
    void push(T);
    T* pop();
    T* top();
    int length();
    void empty();
    bool isempty();
};

template <class T>
stack<T>::~stack() {		//Destructor
    delete[] Stack;
}

template <class T>
stack<T>::stack(int numsize) {     //Default constructor
    Stack = new T[numsize];
    //empties the stack first
    size = numsize;
    //initializes top with -1
    top1 = -1;
}

//Function to put an item on the stack
template <class T>
void stack<T>::push(T d) {
    if (top1 >= size-1) {
        throw fullerror();
    }
    else {
        top1++;
        Stack[top1] = d;
        
    }

}

//Function to remove the last item from the stack (top item)
template<class T>
T* stack<T>::pop() {
    if (top1 <= -1) 
    {
        throw emtyerror();
    }
    else {
        
        T* retval = &Stack[top1];  
        top1--;
        return retval;
    }

}

//Function to show the top item without removing it
template<class T>
T* stack<T>::top() {
    if (top1 <= -1) {
        //string pekExeception = "ERROR: There are no item in the stack. \n";
        throw toperror();
    }
    else {
        T* retval = &Stack[top1];
        return retval;
    }

}
template<class T>
bool stack<T>::isempty() {
    if (top1 == -1) {
        return true;
    }
    return false;
}
//Function to indicate the number of items in the stack
template<class T>
int stack<T>::length() {
    return size;

}

//Function to empty the stack of all contents
template<class T>
void stack<T>::empty() {
    delete[] Stack;
}



#endif // STACK_H
