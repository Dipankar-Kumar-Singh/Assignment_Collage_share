#include<bits/stdc++.h>
using namespace std;


#define F first
#define B second

template<typename T>
class Queue{

    public:
    static const int size = 5 ;
    T v[size] {};
    
    pair<int,int> p {-1,-1} ;
    // first  --> Front   // p.F --> Front
    // second --> Back    // p.B --> Back(second)

    // NOTE FROM DATA STR POINT OF VIEW --> 
    // FRONT IS NOT THE FRONT POINTER ... 
    // FRONT IS FIRST ELEMENT THAT THAT WAS added to the queue ...
    // SO queue.Front ==> arr[p.back+1] // and queue
    
    public:
    void init(){p = {-1,-1} ; for(int &i:v)i=0 ;}


    bool full(){  if(p.B!=-1) { return ((p.F+1)%size == p.B) ;} else { return (p.F==size-1) ; }} 
    bool empty(){return ((p.F==p.B)) ;}

    void enqueue(T data){

        if(full()) {cout << "\n ------------ [Queue Limit reached] ------------\n" ;  return ;  }

        if(empty())
        {   
            p.F++ ; 
            v[p.F] = data ; 
            return ; 
        }

        // arr has some data ; 

        else 
        {   
            p.F = (p.F + 1)%size ; 
            v[p.F] = data ;   
            
        }
    }

    T front(){ if(empty()){ cout << "\n------------Queue empty------------\n" ; return 0; }  return v[(p.B+1)%size] ;}

    T dequeue(){

        if(empty()){ cout << "\n------------Queue empty------------\n" ; return static_cast<T>(-1); }
        
        p.B = (p.B + 1)%size ;
        T val = v[p.B] ;

        if(p.B==p.F) init() ; // if last element was dequeued , reset queue

        return val ;
    }

};


int main(){

    Queue<int> q ;


    cout << "adding 5 to queue : \n" ;
    q.enqueue(5) ;
    cout << "front element : [expeceted 5 ]  = "<< q.front()  << endl ;


    cout << "adding 10 to queue : \n" ;
    q.enqueue(10) ;
    cout << "front element : [expeceted 5 as we din't removed out 5 ]  = " << q.front()  << endl ;

    
    cout << "adding 2 to queue : \n" ; q.enqueue(2) ;
    cout << "adding 4 to queue : \n" ; q.enqueue(4) ;
    cout << "adding 9 to queue : \n" ; q.enqueue(9) ;

    cout << "Queue of size 5 is alredy full , now attempting to add extra elements : \n" ;
    cout << "will not add element : \n" ;
    cout << "adding 7 to queue : \n" ; q.enqueue(7) ;

    cout << "present queue should be : 5 | 10 | 2 | 4 | 9 | \n" ;

    cout << "1 dequeue element :  " << q.dequeue()  << endl ; 
    cout << "2 dequeue element :  " << q.dequeue()  << endl ; 
    cout << "3 dequeue element :  " << q.dequeue()  << endl ; 
    cout << "4 dequeue element :  " << q.dequeue()  << endl ; 
    cout << "5 dequeue element :  " << q.dequeue()  << endl ; 
    cout << "\n6th dequeue should be : -1 [No element left] |\n and an massage of empty queue  \n\n" ; 
    cout << "6 dequeue element :  " << q.dequeue()  << endl ; 


    cout << "\n_____________________________________________\n\n" ;

    cout << "adding 2 to queue : \n" ; q.enqueue(2) ;
    cout << "adding 4 to queue : \n" ; q.enqueue(4) ;
    cout << "adding 8 to queue : \n" ; q.enqueue(8) ;
    cout << "adding 34 to queue : \n" ; q.enqueue(34) ;
    cout << "adding 7 to queue : \n" ; q.enqueue(7) ;
    cout << "1 dequeue element :  " << q.dequeue()  << endl ; 
    cout << "front element : " << q.front() << endl ; 
    cout << "adding 9 to queue : \n" ; q.enqueue(9) ;
    cout << "2nd dequeue element :  " << q.dequeue()  << endl ;
    cout << "front element : " << q.front() << endl ;  
    cout << "2nd dequeue element :  " << q.dequeue()  << endl ;
    cout << "2nd dequeue element :  " << q.dequeue()  << endl ;


    
    cout << "all feature tested ! all Ok ! \n" ;

}