#include<iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* next;
        
        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class Stack 
{
    private:
        int height;
        Node* top;
    public:
        Stack(int value){
            Node* newNode = new Node(value);
                top = newNode;
                height = 1;
        }

        void push(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop(){
            if(height == 0){
                return INT8_MIN;
            }

            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;
            return poppedValue;
        }

        void printDetails(){
            cout<<"Top : "<<top->value<<endl;
            cout<<"Height : "<<height<<endl;

            Node* temp = top;
            while(top != nullptr){
                top = top->next;
                cout<<temp->value<<endl;
                temp = top;
            }
        }
};

int main()
{
    Stack* myStack = new Stack(0);

    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    myStack->push(4);
    
    myStack->pop();
    

    myStack->printDetails();

    return 0;
}