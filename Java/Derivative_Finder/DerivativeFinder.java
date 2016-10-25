/*
    Started on:     25 Mar 2015
    Finished on:    21 April 2015
    Ralph Wayne McCracken, III
 */ //Derivative Finder

package derivativefinder;   //Part of derivativeFinder's package.
import java.util.Scanner;   //Import Scanner.

public class DerivativeFinder {
    
    //Global variable declaration
    public static Scanner input = new Scanner(System.in);                                                                                   //Define input as new Scanner object.
    public static Derivative derive = new Derivative();                                                                                     //Define derive as new Derivative object.
    public static final String separation = "-----------------------------------------------------------------------------------------";    //For a consistant appearance throughout.
    public static final String semiseparation = "------------------------------------------------------------";                             //Another consistant appearance variable. 
    public static final double version = 1.00;                                                                                              //Version variable because it's cool. Haha    
    
    //Main Method [START]                                                       [COMPLETE]
    public static void main(String[] args) {
        
        int menu = 0;   //Menu operator variable.
        
        //Main menu
        while(menu==0){
            
            //Main menu prompt
            System.out.printf("Derivative Finder %.2f        |FRACTIONS NOT SUPPORTED|        Ralph Wayne McCracken, III\n", version);
            System.out.println(separation);
            System.out.println("Function(1) | Product of Functions(2) | Quotient of Functions(3) | Power of a Function(4)\n");
            System.out.println("What would you like to find the derivative of?");
            System.out.print("(Type the number that corresponds to your desired category and press ENTER): ");
            menu = input.nextInt(); //Store user-input option into variable, menu.
            
            //If an incorrect option is input by the user (not between 1 - 4): notify and reprompt.
            while(menu < 1 || menu > 4){    //While the option is outside of the correct-option range:
            System.out.println(separation);
            System.out.println("You did not input a possible option.");
            System.out.print("Please type a category presented above (1 - 4): ");
            menu = input.nextInt();         //Store user-input option into variable, menu.
            }
        }
    
        //Function(1) Menu
        while(menu==1){
            function();                 //Invoke the function method, and begin its processes.
        }
        
        //Product of functions(2) Menu
        while(menu==2){
            proFunction();              //Invoke the product of functions method, and begin its processes.
        }
    
        //Quotient of functions(3) Menu
        while(menu==3){
            quoFunction();              //Invoke the quotient of functions method, and begin its processes.
        }
        
        //Power of a function(4) Menu
        while(menu==4){
            powFunction();              //Invoke the power of a function method, and begin its processes.
        }
    }

    
    //Function Method               [Menu==1]                                   [COMPLETE]
    public static void function(){
        
        System.out.println(separation);                                                 //Appearance aspect.
        System.out.println("1)   Derivative of a Function\n");                          //Menu 1 prompt.
        String[] derivative = derive.functionAnalysis();                                //Get function and derivative and store in String array, derivative.
            //derivative[0]: Function placeholder
            //derivative[1]: Derivative placeholder
        
        System.out.println(separation);                                                 //Appearance aspect 2.
        
        System.out.println("The function is:");                                         //Output the resulting function, based on the users input.
        System.out.println("f(x)  = " + derivative[0]);
        
        System.out.println("\nThe derivative of the function is (not simplified):");    //Output the resulting derivative.
        System.out.println("f'(x) = " + derivative[1]);
        
        System.exit(0);                                                                 //Terminate program.
    }
    
    
    //Product of functions Method   [Menu==2]                                   [COMPLETE]
    public static void proFunction(){
       
        System.out.println(separation);                                                 //Appearance aspect.
        System.out.println("2)   Derivative of the Product of Two Functions\n");        //Menu 2 prompt.
        System.out.println("     Function 1:");
        String[] derivative_0 = derive.functionAnalysis();                              //Get function_0 and derivative_0 and store in String array, derivative_0.
            //derivative_0[0]: Function placeholder.
            //derivative_0[1]: Derivative placeholder
        
        System.out.println(semiseparation);                                             //Appearance aspect 2.
        
        System.out.println("     Function 2:");
        String[] derivative_1 = derive.functionAnalysis();                              //Get function_1 and derivative_1 and store in String array, derivative_1.
            //derivative_1[0]: Function placeholder
            //derivative_1[1]: Derivative placeholder
        
        System.out.println(separation);                                                 //Appearance aspect 3.
        
        System.out.println("The function is:");                                         //Output the resulting function, based on the users input.
        System.out.println("f(x)  = [" + derivative_0[0] + "][" + derivative_1[0] + "]");

        System.out.println("\nThe derivative of the function is (not simplified):");    //Output the resulting derivative.
        System.out.println("f'(x) = [" + derivative_0[0] + "][" + derivative_1[1] + "]  +  [" + derivative_1[0] + "][" + derivative_0[1] + "]");
        
        System.exit(0);                                                                 //Terminate program.
    }
    
    //Quotient of functions Method  [Menu==3]                                   [COMPLETE]
    public static void quoFunction(){
        
        String separate_0 = "";                                                     //Appearance aspect variable 1.
        String separate_1 = "";                                                     //Appearance aspect variable 2.
        System.out.println(separation);                                             //Appearance aspect 1.
        System.out.println("3)   Derivative of the Quotient of Two Functions\n");   //Menu 3 prompt.
        System.out.println("     Function 1:");
        String[] derivative_0 = derive.functionAnalysis();                          //Get function_0 and derivative_0 and store in String array, derivative_0.
        //derivative_0[0]: Function placeholder
        //derivative_0[1]: Derivative placeholder
        
        System.out.println(semiseparation);                                         //Appearance aspect 2.
        
        System.out.println("     Function 2:");
        String[] derivative_1 = derive.functionAnalysis();                          //Get function_1 and derivative_1 and store in String array, derivative_1.
        //derivative_1[0]: Function placeholder
        //derivative_1[1]: Derivative placeholder
        
        System.out.println(separation);                                              //Appearance aspect 3.
        
        System.out.println("The function is:");
        if(derivative_0[0].length() > derivative_1[0].length()){                    //Make appearance variable 1's length = the longest component of the quotient.
            while(derivative_0[0].length() > separate_0.length()){
                separate_0 += "_";
            }
        }else{
            while(derivative_1[0].length() > separate_0.length()){
                separate_0 += "_";
            }
        }
        System.out.println("f(x)  = " + derivative_0[0]);                           //Output the resulting function, based on the users input.
        System.out.println("        " + separate_0);
        System.out.println("        " + derivative_1[0]);
        
        String derivativeNum = "[" + derivative_1[1] + "][" + derivative_0[0] + "]  -  [" + derivative_0[1] + "][" + derivative_1[0] + "]";
        String derivativeDem = "[" + derivative_1[0] + "]^2";
        
        if(derivativeNum.length() > derivativeDem.length()){                        //Make appearance variable 2's length = the longest component of the quotient.
            while(derivativeNum.length() > separate_1.length()){
                separate_1 += "_";
            }
        }else{
            while(derivativeDem.length() > separate_1.length()){
                separate_1 += "_";
            }
        }
        
        System.out.println("\nThe derivative of the function is (not simplified):");//Output the resulting derivative.
        System.out.println("f'(x) = " + derivativeNum);
        System.out.println("        " + separate_1);
        System.out.println("        " + derivativeDem);
        
        System.exit(0);                                                             //Terminate program.
    }
    
    //Product of functions Method   [Menu==4]                                   [COMPLETE]
    public static void powFunction(){
        
        int power = 0;                                                              //Initiate the power variable.
        int derPower = 0;                                                           //Initiate the derivative-power variable.
        System.out.println(separation);                                             //Appearance aspect 1.
        System.out.println("4)   Derivative of a Function Raised to a Power\n");    //Menu 4 prompt.
        System.out.println("     Function:");
        String[] derivative = derive.functionAnalysis();                            //Get function and derivative and store in String array, derivative.
            //derivative[0]: Function placeholder
            //derivative[1]: Derivative placeholder
        
        System.out.println(semiseparation);
        
        System.out.print("     The function is raised to what power (integer)?: "); //Get power and store in int-power variable.
        power = input.nextInt();
        derPower = power - 1;
        
        System.out.println(separation);                                             //Appearance aspect 2.
        
        System.out.println("The function is:");                                     //Output the resulting function, based on the users input.
        System.out.println("f(x)  = [" + derivative[0] + "]^(" + power + ")");
        
        if(power == 0 || derPower == 0){                                                             //Output the resulting derivative. [If power == 0, then derivative == 1. (Example: 15477^0 = 1)]
            System.out.println("\nThe derivative of the function is:");
            System.out.println("f'(x) = 0");
        }else{
            System.out.println("\nThe derivative of the function is (not simplified):");
            System.out.println("f'(x) = (" + power + ")" + "[" + derivative[0] + "]^(" + derPower + ")" + "[" + derivative[1] + "]");
        }
        
        System.exit(0);                                                             //Terminate program.
    }
}
