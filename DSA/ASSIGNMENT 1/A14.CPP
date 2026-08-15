#include<iostream>
using namespace std;
struct node
{
    node* left;
    int item;
    node* right;
};

class bst
{
    private:
        node *root;

    protected:
        void preorderRecursion(node* ptr)//adress of subtree
        {
            if(ptr!= nullptr)
            {
                cout<<" "<<ptr->item;
                preorderRecursion(ptr->left);
                preorderRecursion(ptr->right);
            }
        }
        void inorderRecursion(node* ptr)
        {
            if(ptr!= nullptr)
            {
                inorderRecursion(ptr->left);
                cout<<" "<<ptr->item;
                inorderRecursion(ptr->right);
            }
        }
        void postorderRecursion(node* ptr)
        {
            if(ptr!= nullptr)
            {
                postorderRecursion(ptr->left);
                postorderRecursion(ptr->right);
                cout<<" "<<ptr->item;
            }
        }
        node* delNode(node* ptr,int data)
        {
            if(ptr == nullptr)
                return ptr;
            if(data<ptr->item)
                ptr->left=delNode(ptr->left,data);
            if(data>ptr->item)
                ptr->right=delNode(ptr->right,data);
            else
            {
                //noChild
                if(ptr->left == nullptr && ptr->right == nullptr)
                {
                    delete ptr;
                    return nullptr;
                }

                //SingleChild
                if(ptr->left==nullptr || ptr->right == nullptr)
                {
                    node *child = ptr->left != nullptr?ptr->left:ptr->right;
                    delete ptr;
                    return child;
                }

                //TwoChild
                node *pred,*parpred;
                parpred = ptr;
                pred = ptr->left;
                while(ptr->right!=nullptr)
                {
                    parpred = pred;
                    pred = pred->right;
                }
                ptr->item = pred->item;
                if(parpred->right == pred)//pred is right child of parpred
                    parpred->right = delNode(pred,pred->item);
                else    //pred is left child of parpared
                    parpred->left = delNode(pred,pred->item);
            }
            return ptr;
        }
    public:
        bst()
        {
            root = nullptr;
        }

        bool isEmpty()
        {
            return root==nullptr;
        }

        void insert(int data)
        {
            node *ptr;//for traverse
            node *n = new node;
            n->left = nullptr;
            n->item = data;
            n->right = nullptr;
            if(isEmpty())
                root = n;
            else
            {
                ptr = root;
                while(ptr->item!= data)
                {
                    if(data<ptr->item)
                    {
                        if(ptr->left != nullptr)
                            ptr = ptr->left;
                        else
                        {
                            ptr->left = n;
                            break;
                        }
                    }
                    else
                    {
                        if(ptr->right != nullptr)
                            ptr = ptr->right;
                        else
                        {
                            ptr->right= n;
                            break;
                        }
                    }
                }
                if(ptr->item == data)
                    delete n;
            }
        }   

        void preorder()
        {
            //preserve right side child's address 
            preorderRecursion(root);
        }

        void inorder()
        {
            inorderRecursion(root);
        }

        void postorder()
        {
            postorderRecursion(root);
        }

        void del(int data)
        {

        }

        node *search(int data)
        {
            node *ptr = root;
            while(ptr!= nullptr)
            {
                if(ptr->item == data)
                    return ptr;
                if(data < ptr->item)
                    ptr=ptr->left;
                else
                    ptr = ptr->right;
            }
        }

        ~bst()
        {
            while(root!= nullptr)
                del(root->item);
        }
};