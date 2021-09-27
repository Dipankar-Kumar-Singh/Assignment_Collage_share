
import java.util.* ;



public class test {

    
    public static void main(String[] args) {

        // create an object of Scanner
        Scanner input = new Scanner(System.in);


        Complex c1 = new Complex(0,0) ;
        Complex c2 = new Complex(0,0) ;

        System.out.print("Enter the First Complex number  c1 ( real imag ):\n ");
        System.out.print("Real : ");
        c1.real = input.nextFloat() ;
        System.out.print("Img : ");
        c1.img = input.nextFloat() ;
        System.out.print("Your First Complex number is :   c1 = " ); c1.display();

        System.out.print("Enter the First Complex number  c2 ( real imag ):\n ");
        System.out.print("Real : ");
        c2.real = input.nextFloat() ;
        System.out.print("Img : ");
        c2.img = input.nextFloat() ;
        System.out.print("Your Second Complex number is :   c2 = " ); c2.display();

        System.out.print("Enter the Operation you want to perform  :" );

        while (true){
            System.out.println("\n1. Add [ c1 + c2 ]");
            System.out.println("2. Sub [ c1 - c2 ]");
            System.out.println("3. Mul [ c1 * c2 ]");
            System.out.println("4. Div [ c1 / c2 ]");
            System.out.println("5.  :: EXIT ::  ");
            System.out.print("Input : ");
            int option = input.nextInt() ;
            if(option==5){
                break;
            }
            else if (option == 1){
                Complex c = new Complex() ;
                c =  Complex.add(c1,c2) ;
                System.out.print("C1 = : "); c1.display(); System.out.print("C2 = : "); c2.display();
                System.out.print("C1 + C2  = ");
                c.display();
            }
            else if (option == 2){
                Complex c = new Complex( ) ;
                c = Complex.sub(c1,c2) ;
                System.out.print("C1 = : "); c1.display(); System.out.print("C2 = : "); c2.display();
                System.out.print("C1 - C2  = ");
                c.display();
            }

            else if (option == 3){
                Complex c = new Complex() ;
                c = Complex.Multiply(c1,c2) ;
                System.out.print("C1 = : "); c1.display(); System.out.print("C2 = : "); c2.display();
                System.out.print("C1 * C2  = ");
                c.display();
            }

            else if (option == 4){
                Complex c = new Complex() ;
                c = Complex.Div(c1,c2) ;
                System.out.print("C1 = : "); c1.display(); System.out.print("C2 = : "); c2.display();
                System.out.print("C1 / C2  = ");
                c.display();
            }

            else {
                System.out.println("Try again , your choice was out of range [ 1 - 5 ] : ");
            }

        }


    }
}

class Complex{
    public float  real = 0 ; public float img = 0 ;
    Complex(){
        real = 0 ; img = 0 ;
    }
    Complex(float r , float i){
        real = r  ; img = i ;
    };

    public static Complex add(Complex a , Complex b){
        Complex c = new Complex(0,0);
        c.real = a.real + b.real ;
        c.img = a.img + b.img ;
        return c ;
    }
    public static  Complex sub(Complex a , Complex b){
        Complex c = new Complex();
        c.real = a.real - b.real ;
        c.img = a.img - b.img ;
        return c ;
    }

    public static Complex Multiply(Complex a , Complex b){
        Complex c = new Complex(0,0) ;
        c.real = (a.real)*(b.real) - (a.img)*(b.img) ;
        c.img = (a.real)*(b.real) + (a.img)*(b.img) ;
        return c ;
    }

    public static Complex Div(Complex a , Complex b){
        Complex c = new Complex(0,0) ;
        c.real = ((a.real)*(b.real) + (a.img)*(b.img))/ ( (b.real*b.real) + (b.img*b.img) ) ;
        c.img = (a.real)*(b.real) - (a.img)*(b.img) / ( (b.real*b.real) + (b.img*b.img) ) ;
        return c ;
    }

    public void display( ){
        System.out.print( "( " + this.real + " ,  "); System.out.println(this.img + " i" + ")" );
    } ;
};
