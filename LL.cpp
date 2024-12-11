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

        void prepend(int value){
            Node* newNode = new Node(value);
            if(length==0){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteLast(){
            if(length==0){
                return;
            }
            if(length==1){
                head = nullptr;
                tail = nullptr;
            }
            else{
                Node* pre = head;
                Node* temp = head;

                while(temp->next != nullptr){
                    pre = temp;
                    temp = temp->next;
                }
                delete temp;
                tail = pre;
                tail->next = nullptr;
            }
            length--;
        }

        void deleteFirst(){
            if(length==0){
                return;
            }
            if(length==1){
                head = nullptr;
                tail = nullptr;
            }
            else{
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
        }

        Node* get(int index){
            if(index<0 || index>length){
                return nullptr;
            }
            
            Node* temp = head;
            for(int i=0; i<index; i++){
                temp = temp->next;
            }
            return temp;
        }

        bool set(int index , int value){
            Node* temp = get(index);

            if(temp != nullptr){
                temp->value = value;
                return true;
            }
            else{
                return false;   
            }
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
    LinkedList* myLinkedList = new LinkedList(10);
    myLinkedList->append(5);
    myLinkedList->append(7);
    myLinkedList->append(6);
    myLinkedList->prepend(11);
    
    myLinkedList->deleteLast();
    myLinkedList->deleteFirst();

    cout<<"Get value : "<<myLinkedList->get(1)->value<<endl;

    myLinkedList->printDetails();

    return 0;
}