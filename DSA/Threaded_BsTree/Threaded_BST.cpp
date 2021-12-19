#include <iostream>
using namespace std;

template <typename T>
class ThreadedBST;

template<typename T>
class Node {
    private:
        T data;
        Node<T> *left, *right;
        bool lthread, rthread;

    public:
    
        Node(T);

       
        ~Node();

    
        friend class ThreadedBST<T>;
};

template <typename T>
class ThreadedBST {
    private:
        Node<T> *ROOT;

    public:
        
        ThreadedBST();

        
        ~ThreadedBST();

        
        void create();

        
        pair<Node<T>*, Node<T>*> search(T);
 
       
        Node<T>* insertIntoTree(T);

       
        Node<T>* inSucc(Node<T> *);

        
        Node<T>* inPred(Node<T> *);

        
        Node<T>* deleteNoChild(Node<T> *, Node<T> *, Node<T> *);

       
        Node<T>* deleteOneChild(Node<T> *, Node<T> *, Node<T> *);

        
        Node<T>* deleteTwoChild(Node<T> *, Node<T> *, Node<T> *);

        
        void remove(T);

       
        void inorder();

       
        void preorder();

       
        void leafly();
};

template <typename T>
Node<T> :: Node(T val) {
    data = val;
    left = right = NULL;
    lthread = rthread = true;
}

template <typename T>
Node<T> :: ~Node() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}

template <typename T>
ThreadedBST<T> :: ThreadedBST() {
    ROOT = NULL;
}

template <typename T>
ThreadedBST<T> :: ~ThreadedBST() {
    delete ROOT;
    ROOT = NULL;
}

template <typename T>
void ThreadedBST<T> :: create() {
    T val;
    cin >> val;

    
    while (val != -1) {
        ROOT = insertIntoTree(val);
        cin >> val;
    }
}

template <typename T>
pair<Node<T>*, Node<T>*> ThreadedBST<T> :: search(T data) {
    // Parent of current node
    Node<T> *parent = NULL;
    Node<T> *curr = ROOT;

    while (curr != NULL) {
       
        if (data == curr->data) break;

       
        parent = curr;

        if (data < curr->data) {
           
            if (curr->lthread == false) curr = curr->left;
            else {
                curr = NULL;
                break;
            }
        } else {
           
            if (curr->rthread == false) curr = curr->right;
            else {
                curr = NULL;
                break;
            }
        }
    }

    return make_pair(parent, curr);
}

template <typename T>
Node<T>* ThreadedBST<T> :: insertIntoTree(T data) {
    pair<Node<T>*, Node<T>*> found = search(data);

    if (found.second && found.second->data == data) return ROOT;

    Node<T> *parent = found.first;

  
    Node<T> *tmp = new Node<T>(data);

    if (parent == NULL) {
       
        return tmp;
    } else if (data < parent->data) {
      
        tmp->left = parent->left;
        tmp->right = parent;
      
        parent->lthread = false;
        parent->left = tmp;
    } else {
      
        tmp->left = parent;
        tmp->right = parent->right;
        parent->rthread = false;
        parent->right = tmp;
    }

    return ROOT;
}

template<typename T>
Node<T>* ThreadedBST<T> :: inSucc(Node<T>* ptr) {
 
    if (ptr->rthread == true) return ptr->right;

    ptr = ptr->right;
    while (ptr->lthread == false) ptr = ptr->left;
 
    return ptr;
}

template<typename T>
Node<T>* ThreadedBST<T> :: inPred(Node<T>* ptr) {
   
    if (ptr->lthread == true) return ptr->left;
 
  
    ptr = ptr->left;
    while (ptr->rthread == false) ptr = ptr->right;

    return ptr;
}

template <typename T>
Node<T>* ThreadedBST<T> :: deleteNoChild(Node<T>* root, Node<T>* par, Node<T>* ptr) {
    
    if (par == NULL) root = NULL;
   
    else if (ptr == par->left) {
        par->lthread = true;
        par->left = ptr->left;
    } else {
        par->rthread = true;
        par->right = ptr->right;
    }
 
    
    ptr->left = ptr->right = NULL;
    delete ptr;

    return root;
}

template <typename T>
Node<T>* ThreadedBST<T> :: deleteOneChild(Node<T>* root, Node<T>* par, Node<T>* ptr) {
    Node<T>* child;
 
   
    if (ptr->lthread == false) child = ptr->left;
   
    else child = ptr->right;
 
    
    if (par == NULL) root = child;
   
    else if (ptr == par->left) par->left = child;
    else par->right = child;
 
    
    Node<T>* s = inSucc(ptr);
    Node<T>* p = inPred(ptr);
 
    
    if (ptr->lthread == false) p->right = s;
    
    else if (ptr->rthread == false) s->left = p;
 
    ptr->left = ptr->right = NULL;
    delete ptr;

    return root;
}
 
template <typename T>
Node<T>* ThreadedBST<T> :: deleteTwoChild(Node<T>* root, Node<T>* par, Node<T>* ptr) {
   
    Node<T>* parsucc = ptr;
    Node<T>* succ = ptr->right;
 
    
    while (succ->lthread == false) {
        parsucc = succ;
        succ = succ->left;
    }
 
    ptr->data = succ->data;
 
   
    if (succ->lthread == true && succ->rthread == true) root = deleteNoChild(root, parsucc, succ);
    else root = deleteOneChild(root, parsucc, succ);
 
    return root;
}

template <typename T>
void ThreadedBST<T> :: remove(T data) {
    pair<Node<T>*, Node<T>*> found = search(data);
    Node<T> *parent = found.first;
    Node<T> *curr = found.second;

    if (curr == NULL) return;

    if (curr->lthread == false && curr->rthread == false) {
        
        ROOT = deleteTwoChild(ROOT, parent, curr);
    } else if (curr->lthread == false) {
        
        ROOT = deleteOneChild(ROOT, parent, curr);
    } else if (curr->rthread == false) {
        
        ROOT = deleteOneChild(ROOT, parent, curr);
    } else {
        
        ROOT = deleteNoChild(ROOT, parent, curr);
    }
}

template <typename T>
void ThreadedBST<T> :: inorder() {
   
    if (ROOT == NULL) return;

  
    Node<T> *ptr = ROOT;
    while (ptr->lthread == false) ptr = ptr->left;

   
    while (ptr != NULL) 
    {
        cout << ptr->data << " ";
        ptr = inSucc(ptr);
    }

    cout << endl;
}

template <typename T>
void ThreadedBST<T> :: preorder() {
    
    if (ROOT == NULL) return;

    Node<T> *temp = ROOT;

    while (temp != NULL) {
        
        cout<<temp->data<<" ";

        while(temp->lthread == false) {		
          
            temp = temp->left;

            cout << temp->data << " ";		
        }

        while(temp->rthread == true && temp->right != NULL) {
           
            temp = temp->right;		
        }	

        temp = temp->right;		
    }

    cout << endl;
}

template <typename T>
void ThreadedBST<T> :: leafly() {
  
    if (ROOT == NULL) return;

  
    Node<T> *temp = ROOT;
    while (temp->lthread == false) temp = temp->left;

    while (temp != NULL) {
        bool leftMost = temp->left == NULL && temp->rthread == true;
        bool rightMost = temp->right == NULL && temp->lthread == true;
        bool middle = temp->lthread == true && temp->rthread == true;

       
        if (leftMost || rightMost || middle) cout << temp->data << " ";

        temp = inSucc(temp);
    }

    cout << endl;
}

int main() {
   
   
    
    ThreadedBST<int> tbt;

    cout << "\nEnter space delimited elements of the tree, -1 indicating end of input" << endl;
    tbt.create();

    bool flag = true;
    int elem;

    while(flag) {
        cout << "\nEnter your choice:" << endl;
        cout << "1. Insert an element into Tree" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Search for an element" << endl;
        cout << "4. Print Preorder Traversal" << endl;
        cout << "5. Print Inorder Traversal" << endl;
        cout << "6. Print Leaf Nodes" << endl;
        cout << "7. Exit" << endl;
        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nEnter the element to insert: ";
                cin >> elem;
                tbt.insertIntoTree(elem);
                cout << elem << " has been inserted." << endl;
                break;
            case 2:
                cout << "\nEnter the element to delete: ";
                cin >> elem;
                tbt.remove(elem);
                cout << "\nThe element if present, has been deleted" << endl;
                break;
            case 3:
                cout << "\nEnter the element to search for: ";
                cin >> elem;
                if (tbt.search(elem).second != NULL) {
                    cout << elem << " is present in the tree." << endl;
                } else {
                    cout << elem << " is not present in the tree." << endl;
                }
                break;
            case 4:
                cout << "\nPreorder traversal of this tree :" << endl;
                tbt.preorder();
                break;
            case 5:
                cout << "\nInorder traversal of this tree :" << endl;
                tbt.inorder();
                break;
            case 6:
                cout << "\nLeaf nodes of this tree :" << endl;
                tbt.leafly();
                break;
            case 7:
                cout << "\nGoodbye !!!" << endl;
                flag = !flag;
                break;
            default:
                cout << "\nPlease try again" << endl;
                break;
        }
    }

    cout << endl;

    return 0;
}