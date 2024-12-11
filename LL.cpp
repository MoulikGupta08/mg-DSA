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

class LinkedList
{
    private:
        int length;
        Node* head;
        Node* tail;

    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        ~LinkedList(){
            Node* temp = head;
            while(head != nullptr){
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value){
            Node* newNode = new Node(value);
            tail->next = newNode;
            tail = newNode;
            length++;
        }

        void prepend(int value){
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            length++;
        }

        void deleteFirst(){
            if(length == 0){
                return;
            }
            if(length == 1){
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

        void deleteLast(){
            if(length == 0){
                return;
            }
            if(length == 1){
                head = nullptr;
                tail = nullptr;
            }
            else{
                Node* temp = head;
                Node* pre = head;

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

        Node* get(int index){
            if(index<0 || index>length){
                return nullptr;
            }
            else{
                Node* temp = head;
                for(int i = 0; i<index; i++){
                    temp = temp->next;
                }
                return temp;
            }
        }

        bool set(int index, int value){
            Node* temp = get(index);

            if(temp != nullptr){
                temp->value = value;
                return true;
            }
            else{
                return false;
            }
        }

        bool insertNode(int index, int value){
            if(index<0 || index>length){
                return false;
            }
            if(index == 0){
                prepend(value);
                return true;
            }
            if(index == length){
                append(value);
                return true;
            }
            else{
                Node* newNode = new Node(value);
                Node* temp = get(index-1);
                newNode->next = get(index);
                temp->next = nullptr;
                temp->next = newNode;
                return true;
            }
            length++;
        }

        void deleteNode(int index){
            if(index<0 || index>length){
                return;
            }
            if(length == 0){
                deleteFirst();
            }
            if(index == length){
                deleteLast();
            }
            else{
                Node* temp = get(index);
                Node* pre = get(index-1);

                pre->next = temp->next;
                delete temp;
            }
            length--;
        }

        void reverse(){
            Node* temp = head;
            head = tail;
            tail = temp;

            Node* after = temp->next;
            Node* before = nullptr;

            for(int i = 0; i<length; i++){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }

        void displayDetails(){
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
    LinkedList* myLinkedList = new LinkedList(1);

    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->append(6);
    myLinkedList->append(7);
    
    myLinkedList->reverse();

    myLinkedList->displayDetails();

    return 0;
}