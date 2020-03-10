
/*
    GEEKSFORGEEKS
        DATA STRUCTURES
            STACKS
    
    REVERSE A STRING USING STACK
    coded by Fatih Cinar
    on March 11th, 2020
*/

class Stack
{
    private int Capacity;
    private int Top;

    private char[] Container;

    private final int NOWHERE = -1;

    private void privateConstructor(int capacityGiven){

        if(capacityGiven <= 0){
            throw new RuntimeException("Invalid Capacity");
        }

        this.Capacity = capacityGiven;
        this.Top = NOWHERE;

        this.Container = new char[Capacity];

        return;
    }


    public boolean isFull(){

        final boolean FULL = true;
        final boolean NOT_FULL = false;

        if(Top == Capacity - 1){
            return FULL;
        }
        else{
            return NOT_FULL;
        }
    }

    public boolean isEmpty(){

        final boolean EMPTY = true;
        final boolean NOT_EMPTY = false;

        if(Top == NOWHERE){
            return EMPTY;
        }
        else{
            return NOT_EMPTY;
        }
    }

    public void push(char value){

        if(isFull()){
            throw new RuntimeException("Stack is FULL!");
        }
        
        Top++;

        Container[Top] = value;

        return;
    }

    public char pop(){

        final char EMPTY_CHARACTER = '\0';

        if(isEmpty()){
            return EMPTY_CHARACTER;
        }
        else{
            
            char popped = Container[Top];

            Top--;

            return popped;
        }
    }


    public Stack(){

        final int assignedCapacity = 1000;
        this.privateConstructor(assignedCapacity);
    }

    public Stack(int capacityGiven){

        this.privateConstructor(capacityGiven);
    }


}
