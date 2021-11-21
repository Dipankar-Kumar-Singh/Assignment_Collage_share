// import java.util.*;



public class App{

    public static void main(String[] args){

      


        Bike CBZ = new Bike() ;
        Car Fortuner = new Car() ;
        Cycle MTB = new Cycle() ;

        System.out.println("Showing current state of MTB Cycle\n");
        MTB.show_info();
        System.out.println("Showing current state of car Fortuner\n");
        Fortuner.show_info() ;

        System.out.println("Showing current state of Bike CBZ \n");
        CBZ.show_info() ;

        CBZ.gearUP() ;
        CBZ.gearUP() ;
        CBZ.change_speed(20);

        CBZ.show_info();
        for(int i = 0 ; i < 10 ; i++){ CBZ.gearUP();  CBZ.change_speed(CBZ.speed + 1);}
        System.out.println("After Opration on Bike CBZ ") ;
        CBZ.show_info() ;

        System.out.println("Applying Break  on Bike. ") ;
        CBZ.apply_break() ;
        CBZ.show_info() ;

        System.out.println("Sound from Bike : ");
        CBZ.horn() ;   
        System.out.println("Sound from CAR : "); 
        Fortuner.horn() ;

        System.out.println("Sound from Cycle : "); 
        MTB.horn() ;


        




    }
}


interface Vehical {

    void change_gear(int x) ;
    void gearUP() ;
    void gearDOWN() ;

    void change_speed(int s) ;
    void apply_break() ;
    void horn() ;
    
}

class Bike implements Vehical{

    int speed = 0 ;
    public int gear = 0  ; // N Gear 
    String horn_sound = "PEEP!\n" ;
    final int top_gear = 8 ;

    public void show_info(){ show_gear();  show_speed();}
    void show_speed(){System.out.println("SPEED = " + speed + "\n" );} ;
    void show_gear(){System.out.println("GEAR = " + gear );} ;

    
    public void horn(){ System.out.println(horn_sound); }

    public void change_gear(int x){ this.gear += x ;} ;

    public void gearUP(){ if(this.gear== top_gear){ return ;}  change_gear(+1);} ;
    public void gearDOWN(){ if(this.gear == 0 ){ return ; }  change_gear(-1);} ;

    public void change_speed(int s){ speed+=s ;} ;

    public void apply_break(){this.speed = 0 ; } ;

}

class Car implements Vehical{

    int speed = 0 ;
    public int gear = 0  ; // N Gear 
    String horn_sound = "PO PO PO!\n" ;
    final int top_gear = 4 ;

    public void show_info(){ show_gear();  show_speed();}
    void show_speed(){System.out.println("SPEED = " + speed + "\n");} ;
    void show_gear(){System.out.println("GEAR = " + gear );} ;
    
    public void horn(){ System.out.println(horn_sound); }

    public void change_gear(int x){ this.gear += x ;} ;

    public void gearUP(){ if(this.gear==8){ return ;}  change_gear(+1);} ;
    public void gearDOWN(){ if(this.gear == 0 ){ return ; }  change_gear(-1);} ;

    public void change_speed(int s){ speed+=s ;} ;

    public void apply_break(){this.speed = 0 ; } ;
}

class Cycle implements Vehical{

    int speed = 0 ;
    public int gear = 0  ; // N Gear 
    String horn_sound = "TRING TRING TRING \n" ;
    int top_gear = 32 ;

    public void show_info(){ show_gear();  show_speed();}
    void show_speed(){System.out.println("SPEED = " + speed + "\n"  );} ;
    void show_gear(){System.out.println("GEAR = " + gear );} ;
    
    public void horn(){ System.out.println(horn_sound); }

    public void change_gear(int x){ this.gear += x ;} ;

    public void gearUP(){ if(this.gear== top_gear){ return ;}  change_gear(+1);} ;
    public void gearDOWN(){ if(this.gear == 0 ){ return ; }  change_gear(-1);} ;

    public void change_speed(int s){ speed+=s ;} ;

    public void apply_break(){this.speed = 0 ; } ;
}
