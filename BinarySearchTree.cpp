#include<iostream>

using namespace std;

class Node
{
    public: 
        int value;
        Node* right;
        Node* left;

        Node (int value){
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};  
class BinarySearchTree
{   public:
        Node* root;
        BinarySearchTree(int value){
            root = nullptr;
        }

        bool insert(int value){
            Node* newNode = new Node(value);
            if(root == nullptr){
                    root = newNode;
                    return true;
            }
            Node* temp = root;
            while(true){
                if(newNode->value == temp->value){
                    return false;
                }
                if(newNode->value <temp->value){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
            

        }
};

int main()
{
    BinarySearchTree* myBST = new BinarySearchTree(0);

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);

    myBST->insert(27);

    cout<<"Root : "<<myBST->root->right->left->value;
    return 0;
}