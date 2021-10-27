#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node{
    public:
    T data  ;
    node* next = NULL ;

    node(T val){
        data =  val ;
        next = NULL ;
    }

    node(T val, node* link_Address){
        data = val ;
        next = link_Address ;
    }
};

template<typename T>
class Stack{
    node<T>* top = NULL ; 
    public:
    
    void push(T val){
        if(top == NULL){
            node<T>* Node = new node(val);
            top = Node ;
        }

        else if(top != NULL){
            top = new node(val,top);
        }
    }

    void pop(){
        if(top == NULL){return ;}
        node<T>* addr = top->next ;
        delete top ;
        top = addr ;
    }

    char at_top(){
        return top->data ;
    }

    bool empty(){
        return (top == NULL) ;
    }

    void display(){
        node<T>* point = top  ;
        while(point!=NULL){
            cout << point->data << " ";
            point = point->next ; 
        }
    }
};


void display_menu();
void display_menu(){

    cout << "\n------------------------------------------------\n";
    cout << "1  || Conversion of : Infex to Prefix   ||  \n" ;
    cout << "2  || Conversion of : Infex to Postfix  ||  \n" ;
    cout << "3  || Evaluation of : Postfix           ||  \n" ;
    cout << "4  || Evaluation of : Prefix            ||  \n" ;
    cout << "5  || EXIT                              ||  \n" ;
    cout << "\n------------------------------------------------\n" ;
    
}

bool isOperand(char c) ;
bool isOperand(char c){
    bool aplha_upper =  (c >= 'A' && c <= 'Z') ;
    bool aplha_lower =  (c >= 'a' && c <= 'z') ;
    bool digit       =  (c >= '0' && c <= '9') ;
    return aplha_upper or aplha_lower or digit ;
} 


int precedence(char ch)  ;
int precedence(char ch) 
{
    if(ch == '^')        return 3;
    else if  (ch =='*' or ch == '/' )        return 2;
    else if  (ch == '+' or ch == '-' )        return 1;
    
    return -1;
}




string infix_To_Postfix(string s);
string infix_To_Postfix(string s)
{

    Stack<char> st  ;
    string result ;

    for(auto c : s)
    {   
        if(c==' ') continue ;
        if(isOperand(c)) result.push_back(c) ; 

        else if(c == '(') st.push('(') ;
        
        else if(c== ')') 
        {
           
            while (st.at_top()!='(')
            {
                result.push_back(st.at_top()) ;
                st.pop() ;
            }

            st.pop() ;
        }

        // character is + - / * 
        else 
        {
           while( !st.empty() && precedence(c) <= precedence(st.at_top()) ){

               result.push_back(st.at_top()) ;
               st.pop() ;
           }

           st.push(c) ;
        }
    }

    // CLEAR THE REMANING ITEM IN THE STACK : AS WE ARE ABOUT TO FINISH :: 

    while(!st.empty()) 
    {
        result.push_back(st.at_top()) ;;
        st.pop();
    }

    return result ;
}

char flip_bracket(char c);
char flip_bracket(char c){
    if(c=='(') return ')' ;
    else if(c==')') return '(' ;
    return ' ' ;
}

string infix_To_Prefix(string s);
string infix_To_Prefix(string s){
    string result ;

    reverse(s.begin(),s.end()) ;
    for(auto &c : s ){ if(  c==')' or c=='(') {c=flip_bracket(c);} }

    result = infix_To_Postfix(s) ;
    reverse(result.begin(),result.end()) ;

    return result ;
}


/* -------------------------------------------------------------------------- */
/*                                 EVALUATION                                 */
/* -------------------------------------------------------------------------- */


/* -------------------- Evaluation of Prefix Expressions -------------------- */

double evaluate_prefix(string prefix){
    
    Stack<double> st;
    reverse(prefix.begin(),prefix.end()) ;

    for(auto c : prefix){
        
        if(c==' ') continue ;
        if(isdigit(c)){ st.push((double)(c-'0')) ; }

        else
        {  
            double a = st.at_top(); st.pop();
            double b = st.at_top(); st.pop();

            if     (c=='+') { st.push(a+b) ;}
            else if(c=='-') { st.push(a-b) ;}
            else if(c=='/') { st.push(a/b) ;}
            else if(c=='*') { st.push(a*b) ;}
        }
    }

    return st.at_top();

}


double evaluate_postfix(string prefix){

    Stack<double> st;
    for(auto c : prefix){

        if(c==' ') continue ;
        if(isdigit(c)){ st.push((double)(c-'0')) ; }

        else
        {  
            double a = st.at_top(); st.pop();
            double b = st.at_top(); st.pop();

            if     (c=='+') { st.push(a+b) ;}
            else if(c=='-') { st.push(a-b) ;}
            else if(c=='/') { st.push(a/b) ;}
            else if(c=='*') { st.push(a*b) ;}
        }
    }

    return st.at_top();

}


/* -------------------------------------------------------------------------- */


int main(){

    
    string input_string ;
    string ans ;

    while (true)
    {
       int input {} ; 
       display_menu() ; // for UI DISPLAY of MENUE [ OPTIONS ] 
       cin >> input ;


        if(input == 1) 
        { 
            
            /* -------------------------------------------------------------------------- */
            /*                       Conversion of : Infex to Prefix                      */
            /* -------------------------------------------------------------------------- */

            cout << "___________________________________________\n\n" ;

            cout << "Inter the [ INFIX EXPRESSION ] : " ; 
            cin.ignore() ; getline(cin,input_string) ;
            ans =  infix_To_Prefix(input_string) ;

            cout << "___________________________________________\n\n" ;

            cout << "INFIX  : " << input_string << " \n" ;
            cout << "PREFIX : " << ans << endl ;

            cout << "___________________________________________\n" ;
            cout << "___________________________________________\n\n" ;
           
        }

        else if(input == 2){ 

            /* -------------------------------------------------------------------------- */
            /*                      Conversion of : Infex to Postfix                      */
            /* -------------------------------------------------------------------------- */

            cout << "___________________________________________\n\n" ;

            cout << "Inter the [ INFIX EXPRESSION ] : " ; 
            cin.ignore() ; getline(cin,input_string)  ;
            ans =  infix_To_Postfix(input_string) ;

            cout << "___________________________________________\n\n" ;
            cout << "INFIX : " << input_string << " \n" ;
            cout << "POSTFIX : " << ans << endl ;

            cout << "___________________________________________\n" ;
            cout << "___________________________________________\n\n" ;

        }

        else if(input == 3){
            
            /* -------------------------------------------------------------------------- */
            /*                           Evaluation of : Postfix                          */
            /* -------------------------------------------------------------------------- */

            cout << "___________________________________________\n\n" ;

            cout << "Inter the [ POSTFIX EXPRESSION ] : " ; 
            cin.ignore() ; getline(cin,input_string)  ;

            cout << "___________________________________________\n\n" ;
            cout << "POSTFIX : " << input_string << " \n" ;
            cout << "EVALUATED OUTPUT : " << evaluate_postfix(input_string) << endl ;

            cout << "___________________________________________\n" ;
            cout << "___________________________________________\n\n" ;

         }

        
        else if(input == 4){ 

            /* -------------------------------------------------------------------------- */
            /*                           Evaluation of : Prefix                           */
            /* -------------------------------------------------------------------------- */

            cout << "___________________________________________\n\n" ;

            cout << "Inter the [ PREFIX EXPRESSION ] : " ; 
            cin.ignore() ; getline(cin,input_string) ;

            cout << "___________________________________________\n\n" ;

            cout << "PREFIX  : " << input_string << " \n" ;
            cout << "EVALUATED OUTPUT  : " << evaluate_prefix(input_string) << endl ;

            cout << "___________________________________________\n" ;
            cout << "___________________________________________\n\n" ;

        }

        else if(input == 5){break ;}
    }
}
