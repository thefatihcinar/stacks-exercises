/*
    GEEKSFORGEEKS
        DATA STRUCTURES
            STACKS
    
    REVERSE A STRING USING STACK

    coded by Fatih Cinar
    on March 11th, 2020
*/

#include <iostream>

using namespace std;

class Stack
{
    private:
        const int NOWHERE = -1; // EMPTY STACK POINTER

        char* Container; // The container(array) that contains characters
        int Top; // showing the top of the stack
        int Capacity; // capacity of the stack
        void privateConstructor(int stackCapacity); // Private initializations

    public:
        Stack(int stackCapacity); // Create stack with capacity
        Stack(); // Assign a capacity to the stack

        void push(char value); // push a char element to the stack
        char pop(); // pop a char from the stack
        void printStack(); // prints the elements in the stack
        bool isEmpty(); // figures out whether the stack is empty or not
        bool isFull(); // figures out whether the is full or not
        static Stack* createRandomStack(); // create random valued stack for testing

};

class Reverser
{
    /*
        This class reverses strings using Stack data structure
    */

    public:
        static void reverseString(string &oneString); // reverses a string
};




Stack* Stack::createRandomStack(){
    /*
        This method creates a stack with random length
        and random values in it 
        for testing purposes
    */

    // Factory Design Pattern

    Stack* myNewStack = new Stack();

    const int minimumNumberElements = 3; 
    const int maximumNumberElements = 7;
    const int randomNumberofElements = rand() % maximumNumberElements + minimumNumberElements; 
    
    const int range = 'z' - 'a' + 1; // number of characters in the range

    char randomCharacter; // randomly chosen charater to push to the stack

    for(int counter = 0; counter < randomNumberofElements; counter++){
        // push the elements to the stack
        // randomly chose characters to push

        randomCharacter = 'a' + rand() % range;

        myNewStack->push(randomCharacter);
    }

    return myNewStack;

}

bool Stack::isFull(){
    /*
        This method figures out whether the stack is FULL or not
    */

   enum Values
   {
       FULL = true,
       NOT_FULL = false
   };

   if(Top == Capacity - 1){
       return FULL;
   }
   else{
       return NOT_FULL;
   }
}

bool Stack::isEmpty(){
    /*
        This method figures out whether the stack is empty or not
    */

    enum Values{
       EMPTY = true,
       NON_EMPTY = false
    };

    if(Top == NOWHERE){
        return EMPTY;
    }
    else{
        return NON_EMPTY;
    }
}

void Stack::printStack(){
    /*
        This function prints all the elements inside the stack
    */

    if(isEmpty()){
        cout << "Empty Stack!" << endl;
        return;
    }
    else{
        
        // Start from the bottom of the stack 
        // and iterate till the top

        const int bottom = 0; // bottom of the stack
        for(int iterator = bottom; iterator <= Top; iterator++){
            cout << Container[iterator] << " ";
        }

        cout << endl;
        return;
    }



}

void Stack::privateConstructor(int stackCapacity){
    /*
        This private constructor makes all the job
        Public constructors are only interfaces
    */

    

    this->Top = NOWHERE; // Pointing nowhere

    // Allocate the memory for stack

    this->Container = new char[stackCapacity];

    this->Capacity = stackCapacity;

    return;
}

Stack::Stack(){
    /*
        This public constructor creates stack with the 
        assigned capacity
    */

    const int assignedCapacity = 1000;

    this->privateConstructor(assignedCapacity);

    return;
}

Stack::Stack(int stackCapacity){
    /*
        This public constructor creates the stack with 
        the desired capacity
    */  

    if(stackCapacity <= 0){
        throw "Not able to initialize the stack!\nError Code: 1 - Invalid capacity";
    }
    
    this->privateConstructor(stackCapacity);

    return;

}


void Stack::push(char value){
    /*
        This method gets a character values
        and pushes it to the top of the stack
    */

    if(isFull()){
        throw "Error Code 2 - Stack is FULL!";
    }
    
    Top++;
    // Increment the top to the new area to push


    Container[Top] = value; 
    // push the element to the new area

    return;
}

char Stack::pop(){
    /*
        This method pops the most-recently-added element 
        from the top of the stack
    */

    if(isEmpty()){
        // throw "Error Code 3: Stack is empty! Nothing to pop!";
        return '\0';
    }
    else{
        char theTopElement = Container[Top];

        Top--; // Decrement the top 
        // so that the last element is removed

        return theTopElement;

    }

}




void Reverser::reverseString(string& oneString){
    /*
        This method gets a string and reverses it 
        and saves the reversed sitauation to the string itself
    */

    // Create new stack for operations
    Stack* stack = new Stack();

    const char TERMINATION = '\0';

    // Add all the characters on the string to the stack
    for(int iterator = 0 ; oneString[iterator] != TERMINATION; iterator++){
        // add each one to the stack
        stack->push(oneString[iterator]);
    }

    char popped;
    

    // Now start popping from the stack 
    // and replace the characters in the string
    // one by one
    for(int iterator = 0; !stack->isEmpty(); iterator++ ){
        // POP FROM THE STACK
        // AS LONG AS IT IS NOT EMPTY
        popped = stack->pop();

        // and replace the string using iteator
        // and increase the iterator later one
        oneString[iterator] = popped;

    }

    return; // all configurations saved in the string
}

