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

class Queue
{
    private:
        int length;
        Node* first;
        Node* last;

    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        void enqueue(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                first = newNode;
                last = newNode;
            }
            else{
                last->next = newNode;
                last = newNode;
            }
            length++;
        }
        
        int dequeue(){
            if(length == 0){
                return INT8_MIN;
            }
            else{
                Node* temp = first;
                int dequeuedValue = first->value;
                first = first->next;
                delete temp;
                length--;
                return dequeuedValue;
            }
        }
        

        void printDetails(){
            cout<<"First : "<<first->value<<endl;
            cout<<"Last : "<<last->value<<endl;
            cout<<"Length : "<<length<<endl;

            Node* temp = first;
            while(first != nullptr){
                first = first->next;
                cout<<temp->value<<endl;
                temp = first;
            }
        }
};

int main()
{
    Queue* myQueue = new Queue(0);

    myQueue->enqueue(1);
    myQueue->enqueue(2);
    myQueue->enqueue(3);
    myQueue->enqueue(4);
    
    myQueue->dequeue();
    myQueue->dequeue();

    myQueue->printDetails();

    return 0;
}