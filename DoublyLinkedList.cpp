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

        void append(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode; 
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void deleteLast(){
            if(length == 0){
                return;
            }
            if(length == 1){
                head = nullptr;
                tail = nullptr;
            }
            else{
                Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            length--;
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
};

int main()
{
    DoubleLinkedList* myDll = new DoubleLinkedList(0);

    myDll->append(1);
    myDll->append(2);
    myDll->append(3);
    myDll->append(4);

    myDll->deleteLast();
    
    myDll->printDetails();

    return 0;
}
