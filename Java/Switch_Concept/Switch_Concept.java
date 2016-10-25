/* 
    17 Mar 2015
    Ralph Wayne McCracken, III
 */ //Switch concept.

package switch_concept;
import java.util.Scanner;

public class Switch_Concept {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); //Declare input as new Scanner object.
        
        
        double product1 = 0;    //Product starting amounts...
        double product2 = 0;
        double product3 = 0;
        double product4 = 0;
        double product5 = 0;
        int productNum;         //Entered product number.
        int quantity;           //Entered product amount.

        //Prompt user for product number.
        System.out.print("Enter a product number (1-5) [0 to stop]: ");
        productNum = input.nextInt();   //Store input product number into variable, productNum.
        
        while(productNum != 0){ //Until the user inputs "0," do this:
            if(productNum >= 1 & productNum <= 5){ // 1 <= productNum <= 5
                //Prompt user for quantity sold of the entered product.
                System.out.print("     Enter the quantity sold: ");
                quantity = input.nextInt(); //Store input quantity into variable, quantity.
                switch(productNum){ //Basically, if productNum == x, then:
                    case 1: //If productNum == 1, then:
                        //product1 = product1 plus amount times its cost.
                        product1 += quantity * 2.98;
                        break;  //Leave switch statement.
                    case 2: //If productNum == 2, then:
                        //product2 = product2 plus amount times its cost.
                        product2 += quantity * 4.50; //Product2's amount times its cost.
                        break;
                    case 3: //If productNum == 3, then:
                        //product3 = product3 plus amount times its cost.
                        product3 += quantity * 9.98; //Product3's amount times its cost.
                        break;
                    case 4: //If productNum == 4, then:
                        //product4 = product4 plus amount times its cost.
                        product4 += quantity * 4.49; //Product4's amount times its cost.
                        break;
                    default: //If productNum == 5 [last available option(1-5)], then:
                        //product5 = product5 plus amount times its cost.
                        product5 += quantity * 6.87; //Product5's amount times its cost.
                        break;
                }
                //Reiteration of prompt user for product number, to satisfy while conditions (prevent infinite loop).
                System.out.print("Enter a product number (1-5) [0 to stop]: ");
                productNum = input.nextInt();
            }else{
                //Prompt user that they did not input an acceptable value (between 1 and 5).
                System.out.printf("     Product %d is not in our inventory.\n     Please enter a product number between 1 and 5.\n", productNum);
                //Reiterate the product number entry prompt, to satisfy if-statement conditions (1-5).
                System.out.print("\nEnter a product number (1-5) [0 to stop]: ");
                productNum = input.nextInt();
            }
        }
        //
        System.out.printf("\nProduct 1: $%.2f\n", product1);
        System.out.printf("Product 2: $%.2f\n", product2);
        System.out.printf("Product 3: $%.2f\n", product3);
        System.out.printf("Product 4: $%.2f\n", product4);
        System.out.printf("Product 5: $%.2f\n", product5);
    }
}
