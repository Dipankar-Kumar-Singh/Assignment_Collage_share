#include<bits/stdc++.h>
using namespace std;






typedef struct student {
    string name ;
    double marks ;
    int rollNumber ;
} student;

int display_options_and_get_input() ;
int display_options_and_get_input(){
    cout << "1. Create Database  \n" ;
    cout << "2. Display Database  \n" ;
    cout << "3. Bubble sort \n" ;
    cout << "4. Insertion sort  \n" ;
    cout << "5. Linear Search \n" ;
    cout << "6. Binary Search \n" ;
    cout << "7. EXIT PROGRAM \n" ;

    cout << " Input : " ;

    int op {} ; cin >> op ; cout << "\n" ;  return op ; 
}

void display_database( student *stud , int Database_Size) ;
void display_database( student *stud, int Database_Size) {

           cout << "\tIndex\tRollNo\tName\t\tMarks\n"  ;
           for(int i = 0; i < Database_Size ; i++){
              cout << "\t" << i << "\t" << stud[i].rollNumber << "\t" << stud[i].name << "\t\t" << stud[i].marks ; 
              cout << "\n" ;
           }
}



int Linear_Search(student *stud , int Database_Size, double target_marks){
    for (int i = 0; i < Database_Size ; i++){
        if(stud[i].marks == target_marks){return i;}
    }
    return -1 ;
}

int Linear_Search(student *stud , int Database_Size, string target_name){
    for (int i = 0; i < Database_Size ; i++){
        if(stud[i].name == target_name){return i;}
    }
    return -1 ;
}

int Linear_Search(student *stud , int Database_Size, int target_roll){
    for(int i = 0; i < Database_Size ; i++){
        if(stud[i].rollNumber == target_roll){return i;}
    }
    return -1 ;
}

int Binary_Search(student *stud , int Database_Size, int target_roll){
    
    int l  = 0 , r = Database_Size - 1 ; 
    //** assuming stud is sorted based on Roll Numbers  ;

    while (l<=r)
    {
       int mid = l + (r - l )/2 ; 
       if(stud[mid].rollNumber == target_roll){ return mid; }
       else if(stud[mid].rollNumber > target_roll){  r =  mid -1 ; }
       else if(stud[mid].rollNumber < target_roll){ l = mid + 1 ; }
    }

    return -1 ;
}

int Binary_Search(student *stud , int Database_Size, string target_name){
    
    int l  = 0 , r = Database_Size - 1 ; 
    //** assuming stud is sorted based on name  ;
    while (l<=r)
    {
       int mid = l + (r - l )/2 ; 
       if(stud[mid].name == target_name){ return mid; }
       else if(stud[mid].name > target_name){  r =  mid -1 ; }
       else if(stud[mid].name < target_name){ l = mid + 1 ; }
    }
    
    return -1  ;
}


int Binary_Search(student *stud , int Database_Size, double target_marks){
    
    int l  = 0 , r = Database_Size - 1 ; 
    //** assuming stud is sorted based on marks  ;
    while (l<=r)
    {
       int mid = l + (r - l )/2 ; 
       if(stud[mid].marks == target_marks){ return mid; }
       else if(stud[mid].marks > target_marks){  r =  mid -1 ; }
       else if(stud[mid].marks < target_marks){ l = mid + 1 ; }
    }
    return -1  ;
}


int main(){

    cout << "==============WELCOME=================\n" ; 
    cout << "chose the Opration you want to prform\n" ;

    student *stud = NULL;
    // USING STUD as A POINTER TO STUDENT ARRAY // 
    // BUT WE DON't Know the size of arry yet , thus .. 
    // We are assigning it null value ;
    // later on we will create an Dynamic array [ new Student[20]] ; with new keyword [ dyanamic memory allocation]
    int Database_Size = 0 ;  

    while (true)
    {  
       int option = display_options_and_get_input() ; 
       if(option == 1){
           /* -------------- Create Database ---------- */
            cout << "Size of the Database [ No of Student ]\n " ; 
            cout << "Enter size : " ; 
            int n  ; cin >> n  ;
            Database_Size = n ;
            stud = new student[n] ; 

            for (int i = 0; i < n; i++)
            {
                cout << "\nStudent Name : " ; cin >> stud[i].name ; 
                cout << "\nStudent Marks " ; cin >> stud[i].marks ; 
                cout << "\nStudent RollNumber " ; cin >>stud[i].rollNumber ;  
            }
       }

       else if(option == 2){ display_database(stud , Database_Size) ;  }
       else if(option == 3){ cout << "UNDER CONSTRUCTION\n" ;} 
       else if(option == 4){ cout << "UNDER CONSTRUCTION\n" ;} 
       else if(option == 5){
            cout << "Linear Search By Name , RollNo , Marks ?\n" ;
            cout << "\t1.Name \t 2.Roll-No \t 3.marks\n" ;
            cout << "Input : " ;
            int option = 0 ; cin >> option ; 
            if(option ==1)
            {
                string name ; cin >> name ; 
                cout << "Found Index at : " ;
                cout << Linear_Search(stud ,Database_Size, name) ;
                cout << "\n" ; 
                
            }
            else if(option == 2)
            {    int roll ; cin >> roll ;
                 cout << "Found Index at : " ;  
                 cout << Linear_Search(stud ,Database_Size, roll) ;
                 cout << "\n" ; 
            }
            else if(option == 3)
            {    double marks ; cin >> marks ;  
                 cout << "Found Index at : " ;  
                 cout << Linear_Search(stud ,Database_Size, marks) ;
                 cout << "\n" ; 
            }   
       } 

       else if(option == 6){ 

            cout << "Search Filter : \t 1.Marks \t 2.Roll-No \t 3.Name \n" ;  
            int option = 0 ; cin >> option ;
            if(option == 1){
                
                sort(stud , stud + Database_Size , [](student a , student b){ return a.marks < b.marks ;}) ;

                double marks ; cin >> marks ; 
                int index = Binary_Search(stud ,Database_Size, marks) ;
                cout << "Found Index at : " << index << "\n" ; 
            }

            else if(option == 2){ 
                
                sort(stud , stud + Database_Size , [](student a , student b){ return a.rollNumber < b.rollNumber ;}) ;


                int RollNo ; cin >> RollNo ;
                int index = Binary_Search(stud ,Database_Size, RollNo) ;
                cout << "Found Index at : " << index << "\n" ; 
            }

            else if(option == 3){

                sort(stud , stud + Database_Size , [](student a , student b){ return a.name > b.name ;}) ;


                string name ; cin >> name ;
                int index = Binary_Search(stud ,Database_Size, name) ;
                cout << "Found Index at : " << index << "\n" ; 
            }

       } 

       else if(option == 7){break ;}
    
    }
    

}