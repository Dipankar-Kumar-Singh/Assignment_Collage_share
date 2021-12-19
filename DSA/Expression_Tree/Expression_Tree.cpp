#include "bits/stdc++.h" 
using namespace std ;

class Node{
    public:

    char data  ;
    Node* left = NULL ;
    Node* right = NULL ;
    
    Node(char val){
        data = val ;
        left = NULL ;
        right = NULL ;
    }

    Node(char val, Node* l , Node* r){
        data = val ;
        left = l ;
        right = r ;
    }
};


class Exp_tree{

    public :

    Node* top = NULL ;
    stack<Node*> st ;

    void build_postfix(string  s){
        for(char &c : s){
            if(isalpha(c) or isdigit(c))
            {
                st.push(new Node(c)) ;
            }
            else if(c == ' ' ) continue ;
            else {
                Node* N1 = st.top() ;
                st.pop() ;
                Node* N2 = st.top() ;
                st.pop() ;
                st.push(new Node(c,N2,N1)) ;
            }
        }
        top = st.top() ;
    }

    void build_prefix(string  s){
        
        reverse(s.begin(),s.end()) ;

        for(char &c : s){
            if(isalpha(c) or isdigit(c))
            {
                st.push(new Node(c)) ;
            }
            else if(c == ' ' ) continue ;
            else {
                Node* N1 = st.top() ;
                st.pop() ;
                Node* N2 = st.top() ;
                st.pop() ;
                st.push(new Node(c,N1,N2)) ;
            }
        }
        top = st.top() ;
    }


    void traverse_Preorder(Node *N){
        if(N == NULL) return ;
        cout <<  N->data << " " ;
        traverse_Preorder(N->left) ;
        traverse_Preorder(N->right) ;
    }

    void traverse_Postorder(Node *N){
        if(N == NULL) return ;
        traverse_Postorder(N->left) ;
        traverse_Postorder(N->right) ;
        cout <<  N->data << " " ;
    }

    void traverse_inorder(Node *N){
        if(N == NULL) return ;
        traverse_inorder(N->left) ;
        cout <<  N->data << " " ;
        traverse_inorder(N->right) ;
    }

};










int main(){

    string s ;
    getline(cin,s) ;
    Exp_tree T ; 
   

    // SAMPLE 1  PREFIX // 
    string sampl_prefix_1 = "+-+7*/935/82*/625" ;
    // Prefix  : +-+7*/935/82*/625
    // Infix   : 7+9/3*5-8/2+6/2*5
    // Postfix : 793/5*+82/-62/5*+

    // sample 2 . .... //
    // Prefix form: ++7*626
    // Prefix : ++7*626
    // Infix : 7+6*2+6
    // Postfix : 762*+6+


    T.build_prefix(s) ;
    // T.build_postfix(s)  ;


    cout << "\nIN ORDER \n" ;
    T.traverse_inorder(T.top) ;
    cout << "\nPRE ORDER \n" ;
    T.traverse_Preorder(T.top) ; 
    cout << "\nPOST ORDER \n" ;
    T.traverse_Postorder(T.top) ; 








}