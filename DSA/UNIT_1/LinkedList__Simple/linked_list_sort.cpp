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

        if( index-1 > (*this).size ) { cout << " INDEX OUT OF BOUND \n" ; return ; }
        node *node_to_be_added = new node(val) ; 

        node *pointer_to_node = &head ;  
        for (int i = 0; i < index; i++)  {   pointer_to_node = pointer_to_node->next ; }

        node *address_of_forward_Node =  pointer_to_node->next ;   
        pointer_to_node->next = node_to_be_added ; 
        node_to_be_added->next = address_of_forward_Node ;       
    }


    void delete_Node_at_index(int index){

        if( index-1 > (*this).size ) { cout << " INDEX OUT OF BOUND \n" ; return ; }

        --((*this).size) ;  
        node *pointer = &head ;
        for (size_t i = 0; i < index; i++){    pointer = pointer -> next ;  }
        node *address_of_forward_Node = pointer->next->next ; // 
        delete pointer->next ;
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
