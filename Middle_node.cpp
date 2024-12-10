#include<iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* next;

        Node (int value){
            this->value = value;
            next = nullptr;
        }

};

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        LinkedList (int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length=1;
        }
        ~LinkedList()
        {
            Node* temp = head;
            while(head != nullptr){
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void append(int value){
            Node* newNode = new Node(value);
            tail->next = newNode;
            tail = newNode;
            length++;
        }

        Node* middleNode(){
            
                int n = (length/2);
                Node* temp = head;
                for(int i = 0; i<n; i++){
                    temp = temp->next;
                }
                return temp;
            
        }


        void printDetails(){
            cout<<"Head : "<<head->value<<endl;
            cout<<"Tail : "<<tail->value<<endl;
            cout<<"Length : "<<length<<endl;

            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->value<<endl;
                temp = temp->next;
            }
        }
};

int main()
{   
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->append(6);
    myLinkedList->append(7);
    

    cout<<"Middle Node : "<<myLinkedList->middleNode()->value<<endl;
    
    myLinkedList->printDetails();

    return 0;
}