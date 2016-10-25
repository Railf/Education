package derivativefinder;
import static derivativefinder.DerivativeFinder.input;
import static derivativefinder.DerivativeFinder.semiseparation;

//The derivative control center of the program.                                 [COMPLETE]
public class Derivative {
    
    //Derivative Caluclator (the Meat and Potatoes of the program).             [COMPLETE]
    public String derive(int coefficient, int degree){
            /*  Requires 2 parameters:
                    coefficient     Used to calculate the derivative's coefficient.
                    degree:         Used to calculate the derivative's degree.      */
        
        int dCoefficient = coefficient * degree;                    //Calculate the coefficient for the given term.
        int dDegree = degree - 1;                                   //Calculate the degree for the given term.
        String dResult = "";                                        //Initualize String variable dResult.
        if(dCoefficient != 0){                                      //If the derivative != 0, proceed.
            switch(dDegree){                                        //Base the following operations on the value of variable dDegree.
                case 0:                                             //When the degree of the derivative == 0: 
                    return Integer.toString(dCoefficient);          //return just its coefficient. Example: 10x^(0) = 10*1 = 10.
                case 1:                                             //When the degree of the derivative == 1:
                    return dCoefficient + "x";                      //return just the coefficient and "x". Example: 7x^(1) = 7x.
                default:                                            //In the general (default) case:
                    dResult = dCoefficient + "x^(" + dDegree + ")"; //derivative = dCoefficientx^(dDegree).
            }
        }
            return dResult; //Return the value of String variable, dResult, to the method invoke.
            /* NOTE:    The derivative = 0 is not formulated anywhere because I do not want a "0" being returned to the method call.
                        When dResult would = 0, return "". */
    }
    
    
    //Term Generator (the pasta and veggies of the program).                    [COMPLETE]
    public String termGen(int coefficient, int degree){
            /*  Requires 2 parameters:
                    coefficient     Used to represent the original term's coefficient.
                    degree:         Used to represent the original term's degree.      */

        String Result = ""; //Initualize String variable Result.
        
        if(coefficient != 0){                                           //If the coefficient != 0, proceed.
            switch(degree){                                             //Base the following operations on the value of variable degree.
                case 0:                                                 //When the degree of the term = 0:
                    if(coefficient == 1)                                //If the coefficient == 1, proceed.
                        return "1";                                     //Return the value of the coefficient, 1. Example: 1x^(0) = 1(1) = 1.
                    else                                                //If the coefficient != 1, proceed.
                        return Integer.toString(coefficient);           //Return its coefficient. Example: 10x^(0) = 10*1 = 10.
                case 1:                                                 //When the degree of the term = 1:
                    if(coefficient == 1)                                //If the coefficient == 1, proceed.
                        return "x";                                     //Return "x". Example: 1x^(1) = 1x = x.
                    else                                                //If the coefficient != 1, proceed.
                        return coefficient + "x";                       //return just the coefficient and "x". Example: 7x^(1) = 7x.
                default:                                                //In the general (default) case:
                    if(coefficient == 1)                                //If the coefficient == 1, proceed.
                        Result = "x^(" + degree + ")";                  //term = x^(degree).
                    else                                                //If the coefficient != 1, proceed.
                        Result = coefficient + "x^(" + degree + ")";    //term = coefficientx^(degree).
            }
        }
        
            return Result; //Return the value of String variable, Result, to the method invoke.
            /* NOTE:    The function = 0 is not formulated anywhere because I do not want a "0" being returned to the method call.
                        When Result would = 0, return "". */
    }
    
    
    //Function Analysis (the dessert of the program).                           [COMPLETE]
    public String[] functionAnalysis(){
        int numTerms = 0;                               //User-input amount of terms.
        int terms = 0;                                  //Flag variable 1, for the input == 0 and input == negative errors.
        int currentTerm = 1;                            //Flag variable 2, for maintain record of the presented term.
        int coefficient = 0;                            //User-input value for a given term's coefficient.
        int degree = 0;                                 //User-input value for a given term's degree.
        String[] derivative = new String[2];            //Initialize String array, derivative, to hold: the coefficient, the degree, and the derivative.
        derivative[0] = "";                             //Function placeholder.
        derivative[1] = "";                             //Derivative memory placeholder.
        
        
        System.out.print("     How many terms are in the function?: ");
        numTerms = input.nextInt();    //Store user-input term amount into variable, numTerms.
            
            if(numTerms == 0){ //If the user inputs zero: prompt user of the error and reprompt.
                System.out.println("\n     A function does not have zero terms.");
                System.out.println("          Example: f(x) = x^(2) + x has two terms.");
                System.out.println(semiseparation);
                System.out.print("     How many terms are in the function?: ");
                numTerms = input.nextInt();    //Store user-input term amount into variable, numTerms.
            }
        
            if(numTerms < 0){  //If the user inputs a negative number: prompt user of the error and reprompt.
                System.out.println("\n     A function cannot have a negative amount of terms.");
                System.out.println("          Example: f(x) = 4x^(2) + 2x + 5 has three terms.");
                System.out.println(semiseparation);
                System.out.print("     How many terms are in the function?: ");
                numTerms = input.nextInt();    //Store user-input term amount into variable, numTerms.
            }
        
        terms = numTerms + 1;  //Flag variable 1
            /* I found this approach to work better than using the initial numTerms variable, epecially for if(numTerms == 0).
            If the initial input is zero, the user gets an error of their input; 
            I also want the program to display the result at this point, but there would be a dual-case where ther user gets both the error and final result.
            This is my work-around approach. */
        
            while(terms > 1){                                                                       //If the input meets the requirements (not zero or negative), proceed.
                System.out.printf("\n          Term %d:\n", currentTerm);                           //Display current term.
                    System.out.print("               What is the coefficient?: ");                  //Inquire about the current term's coefficient.
                    coefficient = input.nextInt();                                                  //Store input coefficient into variable coefficient.
                    System.out.print("               What is the degree?: ");                       //Inquire about the current term's degree.
                    degree = input.nextInt();                                                       //Store input degree into variable degree.
                
                //Terms management
                if(!"".equals(termGen(coefficient, degree))){                   //If the term != 0, proceed.
                    if("".equals(derivative[0])){                               //If the current, total derivative == 0:
                        derivative[0] += termGen(coefficient, degree);          //Add result derivative to current derivative (total derivative).
                    }else{                                                      //If the current, total derivative != 0:  
                        derivative[0] += " + " + termGen(coefficient, degree);  //Add " + " and result derivative to current derivative (total derivative).
                    }
                }    
                    
                //Derivative management
                if(!"".equals(derive(coefficient, degree))){                    //If the calulated derivative != 0, proceed.
                    if("".equals(derivative[1])){                               //If the current, total derivative == 0:
                        derivative[1] += derive(coefficient, degree);           //Add result derivative to current derivative (total derivative).
                    }else{                                                      //If the current, total derivative != 0:  
                        derivative[1] += " + " + derive(coefficient, degree);   //Add " + " and result derivative to current derivative (total derivative).
                    }
                }
                currentTerm++;                                                                      //Add 1 to the currentTerm counter (go to next term).
                terms--;                                                                            //Remove 1 from the terms counter (approach terminal point).
            
                //When the user has input all coefficients and degrees: output result derivative.
                if(terms == 1){                                                         //When terms counter has reached the terminal point: proceed.
                    if("".equals(derivative[1])){                                       //If all resulting derivatives == 0, proceed.
                        derivative[1] = "0";                                            //Terminate program.
                        return derivative;
                    }else{                                                              //If all resulting derivatives != 0, proceed.
                        return derivative;                                              //Terminate program.
                    }
                }
            }
            return derivative;
    }
}
