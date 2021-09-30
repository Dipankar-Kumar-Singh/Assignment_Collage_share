import java.util.Scanner;



public class project {

    
    public static void main(String[] args){
        Scanner input = new Scanner ( System.in) ;
        System.out.println("\n-----------------------------------------------------------------------\n\n");

        System.out.println("\n-------------------SET THE INFORMATION ABOUUT BOOK------------------------\n") ;

        Books book = new Books() ;
        book.setBookInformation() ;

        System.out.println("\n-------------------SET THE INFORMATION ABOUUT MAGAZINE------------------------\n") ;
       
        Magazine mag  = new Magazine() ;
        mag.setMagInformation(); 

        System.out.println("\n-------------------OPTIONS------------------------\n") ;
        
        while(true) {
            option() ;
            int op = input.nextInt() ;
            if(op==1){
                System.out.print("How manay Books to Buy : ");
                int quantity = input.nextInt() ;
                book.order_copies(quantity);
                System.out.println("thank you for shoping with us! :)") ; 
                line() ;
            }

            else if(op == 2){
                System.out.print("How manay Magazines to Buy : ");
                int quantity = input.nextInt() ;  
                mag.order_copies(quantity);
                System.out.println("thank you for shoping with us! :)") ; 
                line() ;
            } 

            else if(op == 3){
                String issue ; int quantity ;
                System.out.println("New Issue : ");
                issue = input.next() ;
                System.out.println("Quantity : ") ;
                quantity = input.nextInt() ;

                mag.recieve_new_issue(issue, quantity);

                System.out.println("Fresh Issue has been Added to the Stock ") ; 
                line();
    
            }

            else if(op == 4){

                book.information() ; line() ;
            }

            else if(op == 5){
                mag.information() ; line() ;
            }

            else if(op == 6){break;}

        }

        line(); line();
        input.close();
    }


    public static void option(){
        System.out.println("1.Buy books \n2.Buy magazines \n3.Recive new Publication [Magazine] \n4.Get Book Information \n5.Get Magazine Information\n6. EXIT \n");
        System.out.print("Input : ");
    }

    public static void line(){
        System.out.println("----------------------------------------------------------------");
    }

}


class Publication {

    String title;
    double price;
    int copies;

    Scanner input = new Scanner(System.in);

    Publication(){} ;
    Publication(String title , double price , int copies){
        this.title = title ;
        this.price = price ;
        this.copies = copies ;
    }

    public int getCopies(){
        return this.copies ;
    }

    public void setCopies(int copies){
        this.copies = copies ;
    }


    public void add_copies(int copies){
        this.copies += copies ;
    }

    public void display_Current_Sales_Statistics(int quantity){
        // System.out.println("\nTotal Sales :  " + this.price*quintity + " for " + this.title + "'s  " +quintity + "  Copies");
        System.out.println("\nTotal Sales :  " + this.price*quantity + "\n" ) ;
    }

    public void sellCopy(int quantity) { this.copies -= quantity ; display_Current_Sales_Statistics(quantity) ; }

    public void line(){
        System.out.println("----------------------------------------------------------------");
    }

    public void display_publication_data(){
        line() ;
        System.out.println("TITLE : " + this.title );
        System.out.println("PRICE : " + this.price );
        System.out.println("COPIES REMAINING IN STOCK  : " + this.copies );

    }

}

class Books extends Publication {  

    String author; 

    static int total_books = 0 ;


    public void setBookInformation(){
        System.out.print("TITLE OF THE BOOK : " );
        String t = input.nextLine();
        System.out.print("PRICE OF THE BOOK : " );
        double p = input.nextDouble();
        System.out.println("INTITIAL COPIES OF THE BOOK : ") ;
        int c = input.nextInt() ;
        System.out.println("Author of this book : " ) ;
        get_author() ;

        title = t ;
        price = p ;
        copies = c ;
        total_books += c ;
    }

    public void display_Current_Sales_Statistics(int quantity){
        
        System.out.println("\nTotal Sales of Book:  " + this.price*quantity + "\n" ) ;
    }

    public void get_author(){
        input.nextLine() ; // to consume remaig lines ;
        this.author =  input.nextLine() ;
    }

    public void order_copies(int quantity){
        if(quantity > copies){ System.out.println("Sorry , we don't have these number of Copies left" ) ; return ;}
        total_books-=quantity ;
        this.copies -= quantity ; 
    
        display_publication_data() ; 
       
        display_Current_Sales_Statistics(quantity) ;

    }  

    public void information(){
        display_publication_data() ; 
        System.out.println("Author of the book : " + this.author);
    }

}

class Magazine extends Publication { 
    
    static int total_magazine = 0 ;
    String current_issue ;
    int orderQty = 0 ;

    public void information(){
        display_publication_data() ; 
        System.out.println("total_magazine  :"  + total_magazine) ; 
        System.out.println("Current issue OF THE Mangazine :" + current_issue) ;
        
    }

    public void display_Current_Sales_Statistics(int quantity){
        
        System.out.println("\nTotal Sales of Magazine:  " + this.price*quantity + "\n" ) ;
    }

    public void get_issue(){System.out.println("CurrentIssue : " );}

    void order_copies(int quantity){
        orderQty = quantity ;
        adjustQty(quantity) ;
        display_publication_data() ; 
        display_Current_Sales_Statistics(quantity) ;
    }

    void adjustQty(int quantity){
        if(quantity > copies){ System.out.println("Sorry , we don't have these number of Copies left" ) ; return ;}
        total_magazine-=quantity ;
        copies -= quantity ; 
    }

    void recieve_new_issue(String NEW_ISSUE , int quantity){
        this.copies+=quantity ;
        total_magazine += quantity ;
        current_issue = NEW_ISSUE ;
        display_publication_data() ; 
        information();

    }


    public void setMagInformation(){
        System.out.print("TITLE OF THE Magazine : " );
        String t = input.nextLine();
        System.out.print("PRICE OF THE Magazine : " );
        double p = input.nextDouble();
        System.out.print("INTITIAL COPIES OF THE Magazine : ") ;
        int c = input.nextInt() ;
        System.out.print("Current Issue : ") ;
        input.nextLine();
        String cr = input.nextLine();

    
        title = t ;
        price = p ;
        copies = c ;
        total_magazine += c ;
        current_issue = cr ;
    }
       


    

}


