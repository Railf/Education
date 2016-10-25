package java_garage;
//Program calculates charges for parking.
import java.util.Scanner;

public class Garage {
    //Begin calculating charges
    public void startCharging(){
        Scanner input = new Scanner(System.in);
        
        double totalReceipts = 0.0; //Total fee collected for the day.
        double fee;                 //The charge for the current customer.
        double hours;               //Hours for the current customer.
        int custCount = 1;          //Initiate the customer counter at 1.
     
        //Read in the first customer's hours.
        System.out.printf("Enter number of hours for customer %d (or enter a negative number to quit): ", custCount);
        hours = input.nextDouble();
        
        while(hours >= 0.0 && hours <= 24.0){
            fee = calculateCharges(hours);
            totalReceipts += fee;
            
            System.out.printf("     Current charge: $%.2f, Total receipts: $%.2f\n\n", fee, totalReceipts);
            
            custCount++;    //Add one to the customer counter.
            
            //Read in the next customer's hours.
            System.out.printf("Enter number of hours for customer %d (or enter a negative number to quit): ", custCount);
            hours = input.nextDouble();
            
        }   //End while-loop.
        
        while(hours > 24.0 ){
            System.out.printf("     There are only 24 hours in a day. %.1f exceeds 24 hours.\n\n", hours);
            
            //Read in the next customer's hours.
            System.out.printf("Enter number of hours for customer %d (or enter a negative number to quit): ", custCount);
            hours = input.nextDouble();
            
        }   //End while-loop.
        
    }       //End method startCharging.
    
    //Determines fee based on time.
    public double calculateCharges(double hours){
        //Apply minimum charge of $2.00.
        double fee = 2.0;
        //Define excess hours as anything over 3.0.
        double excessTime = hours - 3.0;
        //Establish maximum hours at 24 hours.
        double maxHours = 24.0;
        //Establish maximum hours at $10.00.
        double maxFee = 10.0;
        
        //Add extra fees as customer exceeds 3 hours.
        if(hours > 3.0){
            fee += (0.5*excessTime);
            
            //Apply maximum fee if the hours reach/exceed 24, or the maximum fee is exceeded.
            if(hours == maxHours){
                fee = maxFee;
            }else if(Math.max(fee, maxFee) > maxFee){ fee = maxFee; }
            /*  This last else-if statement is for the inconsistent values that occur before the
                24-hour maximum limit but still exceed the $10.00 maximum fee (19 < hours < 24). 
                    Example:    Say the car was there for 20 hours.
                                2 + 0.5*(19.1-3) = 10.05, which exceeds the limit of $10.00.              */
        }
        
        return fee;
    }   //End method calculateCharges.
    
}       //End class Garage.
