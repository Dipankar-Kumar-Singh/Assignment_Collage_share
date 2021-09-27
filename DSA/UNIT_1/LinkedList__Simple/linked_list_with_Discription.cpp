#include "bits/stdc++.h"
using namespace std ;

class node
{   public:
    int data ; node *next ;

    node(int val){
        data = val ;
        next = NULL ;
    }

    node(){
        data = 0 ;
        next = NULL ;
    }
};


class Linked_List{
    
    node head ;

    public:

    int size = 0 ; 

    Linked_List(){
        head.data = 0 ;
        head.next = NULL ;
    }

    void insert(int val){
        size++ ;
        node *m = new node(val) ;   
        if(head.next == NULL){      
            head.next = m;
            return ;
        }

        node *temp = &head ;
        while ((*temp).next!=NULL){  temp = (*temp).next ;  }

        temp->next = m ; 
        return ;
        
    }

    void insert_value_at_index(int val , int index){
        // OPRATION ..... 
        /* --------------------------------- PART A --------------------------------- */
        //  Create a node ... new node first and store the value

        if( index-1 > (*this).size ) { cout << " INDEX OUT OF BOUND \n" ; return ; }
        node *node_to_be_added = new node(val) ; // Using contructor  

        /*
        when using construcuter , c++ return memory address 
        thus our node_to_be_added is a [ pointer to node (*node_to_be_added) ] , not a node itself .. 
        AlWAYS USE new node() 
        because this will make a permanent variable // 
        if not used new node , 
        if used just node varible --> this will be a local variable inside this scope/fun {} only
        new -->  (will get written in merory untill you yourself distroys it)
        */

        /* --------------------------------- PART B --------------------------------- */
        //  then link it to existin one .....   {A}-->[our(N)]-->{B}
        //  Linking -->

        node *pointer_to_node = &head ;   // [ & --> Address]
        for (int i = 0; i < index; i++)
        {
            pointer_to_node = pointer_to_node->next ;
            // pointer_to_node pey ussi ki next wali value daal di 
        }

        /* -------------------------------------------------------------------------- */
        /*                          MAIN OPRATION --> LINKING                         */
        /* -------------------------------------------------------------------------- */
        
        node *address_of_forward_Node =  pointer_to_node->next ;    // storing adrress of B
        // address of Our node = node_to_be_added 
        pointer_to_node->next = node_to_be_added ;  // Assigning adress of our node to the previous node 
        node_to_be_added->next = address_of_forward_Node ;        // Feeding adrress of b in next pointer of our node 
        
        /* ------------------------------ OPRATION ENDS ----------------------------- */

        // NOTE --> here the special case [ index == last ] is also been handeled 
        

    }


    void delete_Node_at_index(int index){

        if( index-1 > (*this).size ) { cout << " INDEX OUT OF BOUND \n" ; return ; }
        --((*this).size) ;  // using this pointer google it ...  this pointer --> it means refering to self --> self.size
        node *pointer = &head ;
        for (size_t i = 0; i < index; i++)
        {
            pointer = pointer -> next ;
        }
        node *address_of_forward_Node = pointer->next->next ; // 
       // auto pointer_to_attach = pointer ;
        delete pointer->next ;
        //  pointer_to_attach = 
       pointer->next = address_of_forward_Node ; 

    }


    void display(){
        cout << "Linked List :  " ; 
        node *prt = &head ;
        while(prt->next != NULL)
        {   prt = prt->next  ;
            cout << prt->data << " " ;     
        }
        cout << "\n" ;   
    }
};


void display_options(){
    cout << "1. Add element to the Linked List\n" ;
    cout << "2. Add Element at perticular Index \n" ;
    cout << "3. Delete Element to at a Index \n" ;
    cout << "4. Display Linked List \n" ;
    cout << "PRESS ANY OTHER KEY TO EXIT\n " ;
    cout << "\nINPUT    :      "  ;  
}

int main(){

    
    Linked_List LL  ;

    int index {} ;
    int value{} ;

    while (true)
    {
       display_options();
       int button_pressed = 0 ; cin >> button_pressed ; 
       if(button_pressed ==1){
           cout << "\nValue : " ;
           cin >> value ; 
           LL.insert(value) ;
           cout << "Added\n\n" ; 
        }

        else if( button_pressed ==  2 ){
           cout << "\nValue : " ;
           int value ; cin >> value ; 
           cout << "\nIndex : " ;
            cin >> index ; 
           LL.insert_value_at_index(value,index) ;  
           cout << "Added\n\n" ;  
        }

        else if(button_pressed ==  3 ){
            cout << "Index of Element to be deleted " ;  
             cin >> index ; 
            LL.delete_Node_at_index(index) ;
            cout << "Deleted\n\n" ;
        }

        else if(button_pressed ==  4 ){
           LL.display() ;
        }
       
       else {
           cout << "Exiting\n" ; break ;
       }
    }
    

}
