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

        void prepend(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
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
                head->prev = nullptr;
            }
            length--;
        }

        Node* get(int index){
            if(index<0 || index>length){
                return nullptr;
            }
            Node* temp = head;

            if(index < length/2){
                for(int i = 0; i < index; i++){
                    temp = temp->next;
                }
            }else{
                temp = tail;
                for(int i = length-1; i>index; i--){
                    temp = temp->prev;
                }
            }
            return temp;
        }

        bool set(int index, int value){
            Node* temp = get(index);
            if(temp){
                temp->value = value;
                return true;
            }
            else{
                return false;
            }
        }

        bool insertNode(int index, int value){
            if(index<0 || index  >length){
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
            
            Node* newNode = new Node(value);
            Node* temp = get(index);
            Node* pre = get(index-1); 
            newNode->next = temp;
            temp->prev = newNode;
            pre->next = newNode;
            newNode->prev = pre;
            length++;
            return true;
        }

        void deleteNode(int index){
            if(index<0 || index>length){
                return;
            }
            if(index == 0){
                return deleteFirst();
            }
            if(index == length){
                return deleteLast();
            }
            else{
                Node* temp = get(index);
                Node* before = get(index-1);
                Node* after = get(index+1);
                before->next = after;
                after->prev = before;
                temp->next = nullptr;
                temp->prev = nullptr;
                delete temp;
                length--;
            }
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

    myDll->deleteNode(0);

    myDll->printDetails();

    return 0;
}
