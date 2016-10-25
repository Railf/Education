package java_unique_numbers;
import java.util.Scanner;

public class Unique {
    
    // Get five unique numbers from the user.
    public void getNumbers(){
        Scanner input = new Scanner(System.in);
        
        int[] numbers = new int[5]; //Array of five elements.
        int count = 0;              //Number of uniques read.
        int entered = 0;            //Number of entered numbers.
        
        while(entered < numbers.length){
            System.out.print("Enter number (between 10 and 100): ");
            int number = input.nextInt();   //Retrieve input from user.
            
            //Validate the input (number is a number between 10 and 100, inclusive).
            if(number >= 10 && number <= 100){
                
                //Increment number of entered numbers.
                entered++;
                
                boolean containsNumber = false;
                
                for(int test = 0; test < numbers.length; test++){
                    if(numbers[test] == number){
                        containsNumber = true;
                        break;
                    }else{
                        containsNumber = false;
                    }//end if-
                }//end for
                
                if(containsNumber == true){
                    System.out.printf("     %d has already been entered.\n",
                            number);
                }else{
                    numbers[count] = number;
                    count++;
                }//end if-
                
            }else{
                System.out.println("     The number must be between 10 and 100.");
            }//end if-
            
            //Print the list of unique values.
            for(int i = 0; i < numbers.length; i++){
                if(numbers[i] > 0){
                    System.out.printf("%d ",
                            numbers[i]);
                }//end if-
            }//end for
            System.out.println("\n");
            
        }//end while
    }//end method getNumbes
}//end class Unique
