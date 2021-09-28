#include<bits/stdc++.h>
using namespace std;


typedef struct student {
    string name ;
    double marks ;
    int rollNumber ;
} student;

int display_options_and_get_input() ;
int display_options_and_get_input(){
    cout << "\n----------------------------------------------------------------\n" ;
    cout << "1. Create Database  \n" ;
    cout << "2. Display Database  \n" ;
    cout << "3. Bubble sort     [key = RollNumber] \n" ;
    cout << "4. Insertion sort  [key = Names     ]  \n" ;
    cout << "5. Quick sort      [key = Marks     ]  \n" ;
    cout << "6. Linear Search \n" ;
    cout << "7. Binary Search \n" ;
    cout << "8. EXIT PROGRAM \n" ;
     cout << "\n----------------------------------------------------------------\n" ;

    cout << " Input : " ;

    int op {} ; cin >> op ; 
    cout << "\n----------------------------------------------------------------\n" ;
    return op ; 
}

void display_database( student *stud , int Database_Size) ;
void display_database( student *stud, int Database_Size) {

           cout << "\tIndex\tRollNo\tName\t\tMarks\n"  ;
           for(int i = 0; i < Database_Size ; i++){
              cout << "\t" << i << "\t" << stud[i].rollNumber << "\t" << stud[i].name << "\t\t" << stud[i].marks ; 
              cout << "\n" ;
           }
}

vector<int> Linear_Search(student stud[], int Database_Size, double target_marks)
{
    vector<int> index;
    for (int i = 0; i < Database_Size; i++)
    {
        if (stud[i].marks == target_marks)
        {
            index.push_back(i);
        }
    }
    return index;
}

int Linear_Search(student *stud, int Database_Size, string target_name)
{
    for (int i = 0; i < Database_Size; i++)
    {
        if (stud[i].name == target_name)
        {
            return i;
        }
    }
    return -1;
}

int Linear_Search(student *stud, int Database_Size, int target_roll)
{
    for (int i = 0; i < Database_Size; i++)
    {
        if (stud[i].rollNumber == target_roll)
        {
            return i;
        }
    }
    return -1;
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


int Binary_Search(student *stud , int Database_Size, double target_marks)
{    //** assuming stud is sorted based on marks  ;
    int l  = 0 , r = Database_Size - 1 ; 
    while (l<=r)
    {
       int mid = l + (r - l )/2 ; 
       if(stud[mid].marks == target_marks){ return mid; }
       else if(stud[mid].marks > target_marks){  r =  mid -1 ; }
       else if(stud[mid].marks < target_marks){ l = mid + 1 ; }
    }
    return -1  ;
}


void display_single_profile(student profile ){
    cout << "\tName : " << profile.name << 
            "\tRoll : " << profile.rollNumber << 
            "\tMarks : " << profile.marks << "\n" ;
}

void insertion_sort(student stud[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 and stud[j-1].name > stud[j].name)
        {
            swap(stud[j], stud[j-1]);
            j-- ;
        }
    }
}

void bubble_sort(student *stud, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (stud[j].rollNumber > stud[j + 1].rollNumber)
            {
                swap(stud[j], stud[j + 1]);
            }
        }
    }
}


int part(int l , int r , student v[]){
    float pivot = v[l].marks ; 
    int i = l ;
    int j = r ;

    while(i<j)
    {
        while(v[i].marks<=pivot)i++ ;
        while(v[j].marks>pivot)j-- ;
        if(i<j){ swap(v[i],v[j]);}

    }

    swap(v[j],v[l]) ;
    return j;

}

void quick_sort(int l, int r, student v[])
{
    if (l < r)
    {
        int pivot = part(l, r, v);
        quick_sort(l, pivot - 1, v);
        quick_sort(pivot + 1, r, v);
    }
}





int main(){

    cout << "\n\n==============WELCOME=================\n" ; 
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
            cout << "\n" ;
            for (int i = 0; i < n; i++)
            {
                cout << "\tStudent Name : " ; cin >> stud[i].name ; 
                cout << "\tStudent Marks " ; cin >> stud[i].marks ; 
                cout << "\tStudent RollNumber " ; cin >>stud[i].rollNumber ;  
                cout << "\n" ;
            }
       }

       else if(option == 2){ display_database(stud , Database_Size) ;  }
       else if(option == 3)
       {    cout << "\n****************************************************************\n" ;
            cout << "\nBefore sort : \n\n" ; display_database(stud , Database_Size) ; 
            bubble_sort(stud, Database_Size) ;
            cout << "\n****************************************************************\n" ; 
            cout << "\nAfter sort : \n\n" ; display_database(stud , Database_Size) ;
            cout << "\nUsed Bubble Sort  [ key  = [ Roll Number ]  ] \n"  ;

            cout << "\n****************************************************************\n" ;
       }

       else if (option == 4)
       {
           cout << "\n****************************************************************\n" ;
           cout << "\tPerforming Insertion Sort [ key = [ Name ] ]" ;
           cout << "\n****************************************************************\n" ;
           cout << "Before Sort : \n\n" ; display_database(stud , Database_Size) ; 
           cout << "\n****************************************************************\n" ;
           insertion_sort(stud, Database_Size) ;
           cout << "After Sort : \n\n" ; display_database(stud ,Database_Size) ;
           cout << "\n****************************************************************\n" ;
       }

       else if(option == 5){
           cout << "\n****************************************************************\n" ;
           cout << "\tPerforming Quick Sort [ key = [ MARKS ] ]" ;
           cout << "\n****************************************************************\n" ;
           cout << "Before Sort : \n\n" ; display_database(stud , Database_Size) ; 
           cout << "\n****************************************************************\n" ;
           quick_sort(0, Database_Size-1,stud) ;
           cout << "After Sort : \n\n" ; display_database(stud ,Database_Size) ;
           cout << "\n****************************************************************\n" ;
       }

       else if (option == 6)
       {
           cout << "\n\nSearch Filter  \t\t|||\t1.Name\t|||\t2.Roll-No\t|||\t3.Marks\t|||\n\n";
           cout << "Input : ";
           int option = 0;
           cin >> option;
           if (option == 1)
           {
               string name;
               cout << "Enter Name : ";
               cin >> name;
               cout << "Found Index at : ";
               int index = Linear_Search(stud, Database_Size, name);
               cout << "Index: " << index << "   ||   ";
               display_single_profile(stud[index]);
               cout << "\n\n";
           }
           else if (option == 2)
           {
               int roll;
               cout << "Enter Roll Number : ";
               cin >> roll;
               cout << "Found Index at : ";
               int index = Linear_Search(stud, Database_Size, roll);
               cout << "Index: " << index << "   ||   ";
               display_single_profile(stud[index]);
               cout << "\n\n";
           }
           else if (option == 3)
           {
               double marks;
               cout << "Enter Marks : ";
               cin >> marks;
               vector<int> index = Linear_Search(stud, Database_Size, marks);
               cout << "\n\n";
               if (index.empty())
               {
                   cout << "\t\tNo element found\n";
               }
               else if (!index.empty())
               {
                   for (int i = 0; i < index.size(); i++)
                   {
                       display_single_profile(stud[index[i]]);
                   }
                   cout << "\n\n";
               }
           }
       }

       else if (option == 7)
       {

           cout << "\n\n\t\t\t\tSearch Filter\n|||\t1.Marks\t|||\t2.Roll-No\t|||\t3.Name\t|||\n\n";
           int option = 0;
           cin >> option;
           if (option == 1)
           {

               sort(stud, stud + Database_Size, [](student a, student b)
                    { return a.marks < b.marks; });

               double marks;
               cout << "Enter Marks : ";
               cin >> marks;
               int index = Binary_Search(stud, Database_Size, marks);
               cout << "Found Index at : " << index << "\n";
               display_single_profile(stud[index]);
           }

           else if (option == 2)
           {

               sort(stud, stud + Database_Size, [](student a, student b)
                    { return a.rollNumber < b.rollNumber; });

               int RollNo;
               cout << "Enter Roll No : ";
               cin >> RollNo;
               int index = Binary_Search(stud, Database_Size, RollNo);
               cout << "Found Index at : " << index << "\n";
               display_single_profile(stud[index]);
           }

           else if (option == 3)
           {

               sort(stud, stud + Database_Size, [](student a, student b)
                    { return a.name < b.name; });

               string name;
               cout << "Enter Name : ";
               cin >> name;
               int index = Binary_Search(stud, Database_Size, name);
               cout << "Found Index at : " << index << "\n";
               display_single_profile(stud[index]);
           }
       }

       else if(option == 8){break ;}

       else { cout << "Invalid option !! :( \n\n" ;}
    
    }
    

}