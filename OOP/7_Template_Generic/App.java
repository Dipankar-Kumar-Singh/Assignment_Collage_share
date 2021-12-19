import java.io.PrintStream;
import java.util.*;

public class App {
    
    public static final Scanner sc = new Scanner(System.in);

    public static boolean isPlandrom(String s){
        int i = 0 ; 
        int j = s.length() - 1 ; 

        while(j>=i){
            if( s.charAt(i) != s.charAt(j) ) return false;
            i++ ; j-- ;
        }

        return true ;
    }

    public static int count_palandrom(ArrayList<String> s) {
        
        int ans = 0 ;
        for( String sss : s){ if(isPlandrom(sss)) ans++ ;  }
        return ans ;
    }


    public static boolean isPrime(int num) {

        boolean flag = false;
        for (int i = 2; i <= num / 2; ++i) {
          if (num % i == 0) {
            flag = true;
            break;
          }
        }
        return !flag ;
    }

    public static int count_prime(ArrayList<Integer> list) {
        int res = 0 ;
        for(Integer i : list){ if(isPrime(i)) res++ ; }
        return res ;
    }

    public static int count_even(ArrayList<Integer> list) {
        int res = 0 ;
        for(Integer i : list){ if(i%2==0) res++ ; }
        return res ;
    }





    public static void option_input_type(){
        System.out.println("Select type OF INPUT ");
        System.out.println("1. STRINGS for checking of palandrom");
        System.out.println("2. INTEGERS");
        System.out.println("3 . EXIT \n");
    } 

    public static void option_opration(){
        System.out.println("Select type OF opration ");
        System.out.println("1. Check no of Prime");
        System.out.println("2. check no of Odd and even numbers");
    }



    public static void main(String[] args) {
            while(true) 
            {
                option_input_type() ;
                int op1 = sc.nextInt();
                if(op1 == 1){
                    ArrayList<String> list = new ArrayList<String>() ;
                    System.out.println("no of elemets ");
                    int input = sc.nextInt() ;
                    while(input>0){
                        input-- ;
                        String s = sc.next();
                        list.add(s) ;
                    }

                    System.out.print("No of Plandromes in List = " + count_palandrom(list));  
                    System.out.println("\n");
                }
                else if(op1 == 3){return;}
                else{

                        System.out.println("no of elemets ");
                        ArrayList<Integer> list = new ArrayList<Integer>() ;
                        int input = sc.nextInt() ;
                        while(input>0){
                            input-- ;
                            int i = sc.nextInt() ;

                            list.add(i) ;
                        }
                        
                        option_opration();
                        int inp = sc.nextInt();
                        if(inp == 1){
                            System.out.println("No of Prime in List = " + count_prime(list));
                        }

                        else {
                            System.out.println("no of even numbers in List = " + count_even(list));
                            System.out.println("no of odd numbers in List = " + (list.size() - count_even(list)));
                        }
                }
            }
    }

}