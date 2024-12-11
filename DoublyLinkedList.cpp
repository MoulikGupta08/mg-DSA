#include<iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* prev;
        Node* next;

        Node(int value){
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
};

class DoubleLinkedList
{
    private:
        int length;
        Node* head;
        Node* tail;
    
    public:
        DoubleLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printDetails(){
            cout<<"Head : "<<head->value<<endl;
            cout<<"Tail : "<<tail->value<<endl;
            cout<<"Length : "<<length<<endl;

            Node* temp = head;
            while(head != nullptr){
                head = head->next;
                cout<<temp->value<<endl;
                temp = head;
            }
        }
}