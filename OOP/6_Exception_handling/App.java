import java.util.Scanner;

public class App
{
    public static void main(String[] args)
    {   
        Scanner input = new Scanner(System.in) ;

        System.out.println("\n");

        /* --------------------------- Arrary Out of Bound -------------------------- */

        int[] arr = new int[100] ;

        // Filling Dummy Data 
        for(int i = 0 ; i < 100 ; i++){   arr[i] = i+ i*i + i*2 ;     }
        
        System.out.print("Enter the Index  :  ");
        int index = input.nextInt() ;

        try {
            System.out.println("Element : " + arr[index]);

        } catch (ArrayIndexOutOfBoundsException e) {

            System.out.println("Index out of bounds !");
        }

        /* -------------------------------------------------------------------------- */





        int a = 0 , b = 0 ; 

        try {

            System.out.print("\nEnter Numerator  : ");
            String s1 = input.next(); 
            a =Integer.parseInt(s1);
            
            System.out.print("\nEnter Denominator : ");
            String s2 = input.next(); 
            b =Integer.parseInt(s2);

            /* -----------------------------Div by zero Excp---------------------------------- */
            System.out.println("Tring to Div N/D") ;

            try {
                int c = a/b;  
                System.out.println ("\nResult = " + c);
            }
            catch(ArithmeticException e) {
                System.out.println ("Can not be divided as Denominator is Zero -> [ 0 ] <- ");
            }
            /* -------------------------------------------------------------------------- */
            
        } catch (NumberFormatException e) {
            
            System.out.println("Input is not a number ");
        }
        input.close();

    }


}