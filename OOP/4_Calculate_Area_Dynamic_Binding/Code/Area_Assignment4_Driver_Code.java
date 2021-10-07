import java.util.Scanner;

public class Area_Assignment4_Driver_Code {
    
    public static void main(String[] args) 
    {   
        Scanner input = new Scanner(System.in) ;
        int user_option = 0 ;

        Triangle triangle = new Triangle() ; 
        Rectangle rectangle = new Rectangle() ; 
        line(); line() ;

        /* ----------------------- Getting Triangle Dimention ----------------------- */

        System.out.println("Triangle ");
        triangle.setData();
        line() ;

        /* ----------------------- Getting Rectangle Dimention ---------------------- */

        System.out.println("Rectangle ");
        rectangle.setData() ;
        line() ;

        /* ------------------------------------ - ----------------------------------- */


        do
        {   line() ;
            showOptions() ;
            user_option = input.nextInt() ;

            switch(user_option)
            {
                case 1 :  System.out.println("Area of Triangle is " +  triangle.calculateArea()); break ;
                case 2 :  System.out.println("Area of Rectangle is " + rectangle.calculateArea()); break ;
                case 3 :  triangle.setData() ;break ;
                case 4 :  rectangle.setData();break ;
                case 5 :  triangle.information();break ;
                case 6 :  rectangle.information();break ;
                default : System.out.println("Invalid input\n\n"); ;
            }

        } while(user_option <= 6);
        
        input.close();
    }



    public static void showOptions() {
        String option =  "1 || Calculate Area of Triangle\n"
                        +"2 || Calculate Area of Rectangle\n"
                        +"3 || Reconfigure Triangle \n" 
                        +"4 || Reconfigure Rectangle\n" 
                        +"5 || Display Triangle Properies\n" 
                        +"6 || Display Rectangle Properies\n" 
                        +"7 || EXIT \n" ;

        System.out.println(option); line() ;
    }

    public static void line(){
        System.out.println("\n-------------------------------------------\n");
    }
}



abstract class Polygon{
    Scanner input = new Scanner(System.in);
    double base ;
    double height ;
    double area ;
    abstract public double calculateArea();

    public void setData(){

        System.out.print("Enter the Dimention \n\n");

        System.out.print("Base : " ) ;
        base    = input.nextDouble() ;

        System.out.print("Height  : " ) ;
        height  = input.nextDouble() ;

    }

    public void information(){
        System.out.println("Area : " + area );
        System.out.println("base : " + base);
        System.out.println("Height : " + height);
    }
}

class Triangle extends Polygon{
    @Override
    public double calculateArea(){
        area = (1.0/2)*base*height ;
        return area ;
    }
}

class Rectangle extends Polygon{
    public double calculateArea(){
        area =  ( base*height );
        return area ;
    }
}