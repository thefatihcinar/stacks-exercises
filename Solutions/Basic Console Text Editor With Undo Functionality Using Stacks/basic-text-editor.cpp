/*
    coded by Fatih Cinar
    on December 2nd, 2019
*/

/*
    BASIC TEXT EDITOR WITH UNDO FUNCTIONALITY

    "undo" -> for undoing the last thing you did
    "new line" -> for new line
    "....." -> just write the line you want to add 
    "display" -> displays the whole buffer/text editor/stack to the console
    "exit" -> exits the program

*/

#include <iostream>

using namespace std;

// Node structure for "TextStack"
class Node
{
    public:
        string Word; // the string it contains
        Node* Next; // next node

        Node(string text);
        /* 
            Constructor Method: Creates new node 
        */
};

/*
    Stack data structure to store all the text written to the text editor
*/
class TextStack
{   
    private:
        Node* Top;  // top of the stack
    public:
        TextStack();
        /*
             Constructor Method: Creates text stacks
        */
        ~TextStack();
        /*
            Destructor function
            This function releases all the memory that has been dynamicaly allocated
        */
        void Push(string text);
        /*
             This function pushes new text element to the top of the text stack
         */

        string Pop();
        /*
            This function removes the element at the top of the stack
            IT POPS THE TOP ELEMENT FROM THE STACK
        */

        void DisplayAll();
        /*
            This function displays everything in the text stack.
        */
        void ReleaseMemory();
        /*
            This function releases all the memory that has been
            dynamically allocated
        */
    private:
        void Display(Node* wordToDisplay);
        /*
            This function prints everything in the text stack RECURSIVELY
        */
        
};

class TextEditor
{
    private:
        TextStack textStack;  // at the back-end, we will have a stack, user won't see this

    public:
        ~TextEditor();
        /*
            Destructor function
            This function releases all the memory that has been dynamicaly allocated
        */

        void Display();
        /*
            This function displays everything in the text editor
            in the desired way
        */
        void PutText(string textToPut);
        /*
            This function puts the text to the text editor
        */
        void Undo();
        /*
            This function undoes what has written most recently
        */

        
};



int main(){


    TextEditor myTextEditor;

    myTextEditor.Display();

    string tempText;

    while(true){

        cout << "Add Line: ";

        getline(cin, tempText);

        if (tempText == "new line"){

            myTextEditor.PutText("\n");

            continue;

        }
        else if (tempText == "exit"){

            myTextEditor.Display();

            break;
        }
        else if (tempText == "display"){

            myTextEditor.Display();

            continue;

        }
        else if (tempText == "undo"){

            myTextEditor.Undo();

            myTextEditor.Display();

            continue;
    
        }
        else{

            myTextEditor.PutText(tempText);

        }
            
    }
    
    return 0;
}


Node::Node(string text)
{
    /* 
                Constructor Method: Creates new node 
    */
        this->Word = text; // C++ works with deep copying
        this->Next = nullptr;
}

TextStack::TextStack()
{
    /*
        Constructor Method: Creates text stacks
    */

    this->Top = nullptr;
}

void TextStack::Push(string text)
{   
    /*
        This function pushes new text element to the top of the text stack
    */

    // O(1) constant operation

    Node* newNode = new Node(text);  // dynamic allocation of new node

    if (this->Top == nullptr)
    {   
        // if there is nothing in the stack

        this->Top = newNode;
        return;
    }
    else
    {
        // if there is at least one element in the stack

        newNode->Next = this->Top;

        this->Top = newNode;

        return;
    }
};

string TextStack::Pop()
{
    /*
        This function removes the element at the top of the stack
        IT POPS THE TOP ELEMENT FROM THE STACK
    */

    if (this->Top == nullptr)
    {
        // nothing to pop
        return "";
    }

    else
    {
        // Remember the top node for a temporary time
        Node* theTopNode = this->Top;

        string keepThis = theTopNode->Word;
        // keep this string to return

        this->Top = this->Top->Next;

        delete theTopNode;
        // release the memory 

        return keepThis; 
    }
}

void TextStack::DisplayAll()
{
    /*
        This function displays everything in the text stack.
    */
    if (this->Top == nullptr)
    {
        // if there is nothing to display
        // just display a new line
        cout << endl ;
        return;
    }
    else
    {
        // Call the private display method recursively
        // what this will do is 
        // recursive go furthest you can go, print it can then come
        // back to the top of the stack
        // basically it prints the first-put element first
        // unlike the stack data structure
        Display(this->Top);
    }
}

void TextStack::Display(Node *wordToDisplay)
{
    /*
        This function prints everything in the text stack
        But it prints the first-put element first
        and prints the most-recently-put element last
        like a normal text editor would
        using the power of recursion
    */
    if (wordToDisplay->Next == NULL) // EXIT CASE
    {
        // if this is the furthest you can go 
        // print this one and than STACK UNWINDS!
        cout << wordToDisplay->Word;

        return; // EXIT CASE

    }
    else
    {
        // else FIND THE FURHEST 
        // GO THERE
        // then stack will unwind
        Display(wordToDisplay->Next);  // first find the furhest

        cout << wordToDisplay->Word; // after finding, print
    }
}

void TextEditor::Display()
{
    /*
        This function displays everything in the text editor
        in the desired way
    */

    cout << "- - - MARS TEXT EDITOR v1.0 - - -" << endl;
    
    cout << endl;

    this->textStack.DisplayAll();

    cout << endl
         << "- - - - - - - - - - - - - - - - - " << endl;

    return;
}

void TextEditor::PutText(string textToPut)
{
    /*
        This function puts the text to the text editor
    */

    this->textStack.Push(textToPut);
}

void TextEditor::Undo()
{   
    /*
        This function undoes what has written most recently
    */
    this->textStack.Pop();
}

void TextStack::ReleaseMemory()
{
    /*
        This function releases all the memory that has been
        dynamically allocated
    */

    if(this->Top == nullptr){

        // if there is nothing in the stack
        return;

    }
    else{
        // if there is something in the stack
        Node* iterator = this->Top;
        Node* nextOne = nullptr;

        // Release one node and go furthest you can, release all one by one

        while(iterator != nullptr){
            
            nextOne = iterator->Next;
            
            delete iterator;

            iterator = nextOne;
        }

    }

}

TextStack::~TextStack(){
    /*
            Destructor function
            This function releases all the memory that has been dynamicaly allocated
    */
    // ReleaseMemory();  // we do not want to call this twice, Text Editor calls this
    return;
}


TextEditor::~TextEditor(){
    /*
        Destructor function
        This function releases all the memory that has been dynamicaly allocated
    */

    this->textStack.ReleaseMemory();
    return;
    
}


