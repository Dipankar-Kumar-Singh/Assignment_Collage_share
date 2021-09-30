/**
 * App
 */
import java.util.* ;


class Employee{
    Scanner input = new Scanner(System.in) ;
    String name ; 
    int employee_id ; 
    String address ; 
    String email ; 
    long mobile_number ;

    Employee(){name = "" ; email = "" ; mobile_number = 0 ; address = "" ; employee_id = 0 ;} ;

    void getData() {
        System.out.print("Name :");
        name = input.nextLine();

        System.out.print("Employee_id : ");
        employee_id = input.nextInt() ;
        input.nextLine();

        System.out.print("Address : ");
        address = input.nextLine(); 

        System.out.print("Email : ");
        email = input.nextLine() ;

        System.out.print("Mobile_number : ");
        mobile_number = input.nextLong() ;

    }

    void display_profile() {
        System.out.println("Name : " + name);
        System.out.println("Employee ID : " + employee_id) ; 
        System.out.println("Address : " + address) ;
        System.out.println("Email :" + email) ;
        System.out.println("Phone : " + mobile_number) ;
    }
}


class Programmer extends Employee { 
    double basic_pay , DA , HRA , PF , club_fund ; 
    double gross_salary , net_salary ;

    Programmer()
    {name = "" ; email = "" ; mobile_number = 0 ; address = "" ; 
    employee_id = 0 ; basic_pay = 0 ; DA = 0 ; HRA = 0 ; PF = 0 ; club_fund = 0 ; 
    net_salary = 0 ;  gross_salary = 0 ;} ;

    public void get_basic_pay() {
        System.out.print("Enter the Baic Play: " );
        this.basic_pay = input.nextInt() ;
    }

    void calculate_paySlip() {

        System.out.println("Basic_pay :" + basic_pay);

        DA = (((double)97/100))*basic_pay ;
        HRA = (((double)10/100))*basic_pay ;
        PF =(((double)12/100))*basic_pay ;
        club_fund = (((double)0.1/100))*basic_pay ;

        gross_salary = basic_pay + DA + HRA ;
        net_salary  = gross_salary - PF - club_fund;

        // System.out.println("DA :" +DA );
        // System.out.println("HRA : " + HRA );
        // System.out.println("PF : " + PF );
    }

    public void display_salary() {
        System.out.println("----------------------------------------------------------------");
        calculate_paySlip();
        System.out.println("Gross Salary : " + gross_salary);
        System.out.println("Net salary : " + net_salary);
        System.out.println("----------------------------------------------------------------\n");
   
    }

    public void display_profile() {
        
        System.out.println("Name : " + name);
        System.out.println("Employee ID : " + employee_id) ; 
        System.out.println("Address : " + address) ;
        System.out.println("Email :" + email) ;
        System.out.println("Phone : " + mobile_number) ;
        display_salary() ; 
    }

}

class Team_Lead extends Employee {
    double basic_pay , DA , HRA , PF , club_fund ; 
    double gross_salary , net_salary ;

    Team_Lead(){name = "" ; email = "" ; mobile_number = 0 ; address = "" ; 
    employee_id = 0 ; basic_pay = 0 ; DA = 0 ; HRA = 0 ; PF = 0 ; club_fund = 0 ; 
    net_salary = 0 ;  gross_salary = 0 ;} ;

    public void get_basic_pay() {
        System.out.print("Enter the Basic Pay :     " );
        this.basic_pay = input.nextInt() ;
    }

    void calculate_paySlip() {

        System.out.println("Basic_pay :" + basic_pay);

        DA = (((double)97/100))*basic_pay ;
        HRA = (((double)10/100))*basic_pay ;
        PF =(((double)12/100))*basic_pay ;
        club_fund = (((double)0.1/100))*basic_pay ;

        gross_salary = basic_pay + DA + HRA ;
        net_salary  = gross_salary - PF - club_fund;

        // System.out.println("DA :" +DA );
        // System.out.println("HRA : " + HRA );
        // System.out.println("PF : " + PF );
    }

    public void display_salary() {
        System.out.println("----------------------------------------------------------------");
        calculate_paySlip();
        System.out.println("Gross Salary : " + gross_salary);
        System.out.println("Net salary : " + net_salary);
        System.out.println("----------------------------------------------------------------\n");
   
    }

    public void display_profile() {
        System.out.println("Name : " + name);
        System.out.println("Employee ID : " + employee_id) ; 
        System.out.println("Address : " + address) ;
        System.out.println("Email :" + email) ;
        System.out.println("Phone : " + mobile_number) ;
        display_salary() ; 
    }
    
 }

class Assistant_Project_Manager extends Employee {
    double basic_pay , DA , HRA , PF , club_fund ; 
    double gross_salary , net_salary ;

    Assistant_Project_Manager()  {name = "" ; email = "" ; mobile_number = 0 ; address = "" ; 
    employee_id = 0 ; basic_pay = 0 ; DA = 0 ; HRA = 0 ; PF = 0 ; club_fund = 0 ; 
    net_salary = 0 ;  gross_salary = 0 ;} ;

    public void get_basic_pay() {
        System.out.print("Enter the Baic : " );
        this.basic_pay = input.nextInt() ;
    }

    void calculate_paySlip() {

        System.out.println("Basic_pay :" + basic_pay);

        DA = (((double)97/100))*basic_pay ;
        HRA = (((double)10/100))*basic_pay ;
        PF =(((double)12/100))*basic_pay ;
        club_fund = (((double)0.1/100))*basic_pay ;

        gross_salary = basic_pay + DA + HRA ;
        net_salary  = gross_salary - PF - club_fund;

        // System.out.println("DA :" +DA );
        // System.out.println("HRA : " + HRA );
        // System.out.println("PF : " + PF );
    }

    public void display_salary() {
        System.out.println("----------------------------------------------------------------");
        calculate_paySlip();
        System.out.println("Gross Salary : " + gross_salary);
        System.out.println("Net salary : " + net_salary);
        System.out.println("----------------------------------------------------------------\n");
   
    }

    public void display_profile() {
        System.out.println("Name : " + name);
        System.out.println("Employee ID : " + employee_id) ; 
        System.out.println("Address : " + address) ;
        System.out.println("Email :" + email) ;
        System.out.println("Phone : " + mobile_number) ;
        display_salary() ; 
    }
    
} 

class Project_Manager extends Employee {
    double basic_pay , DA , HRA , PF , club_fund ; 
    double gross_salary , net_salary ;

    Project_Manager() {name = "" ; email = "" ; mobile_number = 0 ; address = "" ; 
    employee_id = 0 ; basic_pay = 0 ; DA = 0 ; HRA = 0 ; PF = 0 ; club_fund = 0 ; 
    net_salary = 0 ;  gross_salary = 0 ;} ;

    public void get_basic_pay() {
        System.out.print("Enter the Baic : " );
        this.basic_pay = input.nextInt() ;
    }

    void calculate_paySlip() {

        System.out.println("Basic_pay :" + basic_pay);

        DA = (((double)97/100))*basic_pay ;
        HRA = (((double)10/100))*basic_pay ;
        PF =(((double)12/100))*basic_pay ;
        club_fund = (((double)0.1/100))*basic_pay ;

        gross_salary = basic_pay + DA + HRA ;
        net_salary  = gross_salary - PF - club_fund;

        // System.out.println("DA :" +DA );
        // System.out.println("HRA : " + HRA );
        // System.out.println("PF : " + PF );
    }

    public void display_salary() {
        System.out.println("----------------------------------------------------------------");
        calculate_paySlip();
        System.out.println("Gross Salary : " + gross_salary);
        System.out.println("Net salary : " + net_salary);
        System.out.println("----------------------------------------------------------------\n");
   
    }

    public void display_profile() {
        System.out.println("Name : " + name);
        System.out.println("Employee ID : " + employee_id) ; 
        System.out.println("Address : " + address) ;
        System.out.println("Email :" + email) ;
        System.out.println("Phone : " + mobile_number) ;
        display_salary() ; 
    }
    
} 




public class App {  
   
    App() {} ; 
    public static void main(String[] args) {

        System.out.println("hello");
        Scanner input = new Scanner(System.in); 
        System.out.println("How many Employee :  ")  ;
        int numberOfEmployees = input.nextInt();
        ArrayList<Employee> listOfEmployee = new ArrayList<Employee>() ;
        ArrayList<Programmer> listOfProgramer = new ArrayList<Programmer>() ;
        ArrayList<Team_Lead> listOfTeamLead = new ArrayList<Team_Lead>() ;
        ArrayList<Assistant_Project_Manager> listOfAssistantProjectManager = new ArrayList<Assistant_Project_Manager>() ;
        ArrayList<Project_Manager> listOfProjectManager = new ArrayList<Project_Manager>() ; 

        for (int i = 0; i < numberOfEmployees; i++) {
            System.out.println("Chose Role :" ) ;
            System.out.println("1.Programer\n2.Team Lead\n3.Project_Manager\n4.Assistant Project Manager\n5.EXIT" );
            System.out.print("Input : ");
            int inp = input.nextInt();
            if(inp == 1){
                Programmer programmer = new Programmer();
                programmer.getData() ;
                programmer.get_basic_pay() ;
                listOfProgramer.add(programmer);
                listOfEmployee.add(programmer);
            }

            else if(inp == 2){
                Team_Lead teamLead = new Team_Lead();
                teamLead.getData() ;
                teamLead.get_basic_pay();
                listOfEmployee.add(teamLead) ;
                listOfTeamLead.add(teamLead) ;
            }

            else if(inp == 3){
                Project_Manager projectManager = new Project_Manager() ;
                projectManager.getData() ; 
                projectManager.get_basic_pay() ;
                listOfEmployee.add(projectManager) ; 
                listOfProjectManager.add(projectManager) ;

            }

            else if(inp == 4){
                Assistant_Project_Manager apm = new Assistant_Project_Manager() ;
                apm.getData() ;
                apm.get_basic_pay() ;
                listOfEmployee.add(apm) ;
                listOfAssistantProjectManager.add(apm) ; 
            }

            else if(inp ==5){break;}

        } 

        while(true){
            System.out.println("Chose Opration :  ");
            System.out.println("1.Display All profiles \n2.EXIT");
            int option  = input.nextInt() ;
            if(option==1){
                System.out.println("\nProgramers:\n");
                for(Programmer profile:listOfProgramer){
                    profile.display_profile();
                 }
                
                System.out.println("\nProject Managers: \n");
                 for(Project_Manager profile : listOfProjectManager){
                     profile.display_profile() ;
                 }
                
                System.out.println("\nAssistant Managers:\n");
                 for(Assistant_Project_Manager profile : listOfAssistantProjectManager){
                    profile.display_profile() ;
                 }
                
                System.out.println("\nTeam Lead :\n");
                for(Team_Lead profile  : listOfTeamLead){
                    profile.display_profile() ;
                }
            }

            if(option==2){
                break ;
            }
        }

        for(Employee employee : listOfEmployee){
            employee.display_profile() ;
            System.out.println("\n");
        }

        input.close();

        
    }


    
}



