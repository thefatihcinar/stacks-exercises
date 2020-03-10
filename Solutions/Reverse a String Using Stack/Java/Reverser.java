/*
    GEEKSFORGEEKS
        DATA STRUCTURES
            STACKS
    
    REVERSE A STRING USING STACK
    coded by Fatih Cinar
    on March 11th, 2020
*/

class Reverser
{
    public static void reverseString(StringBuffer string){

        final char TERMINATION_CHARACTER = '\0';

        Stack stack = new Stack();

        final int lengthString = string.length();

        for(int iterator = 0; iterator < lengthString; iterator++){

            stack.push(string.charAt(iterator));

        }

        for(int iterator = 0; !stack.isEmpty(); iterator++){

            string.setCharAt(iterator, stack.pop());
        }

        return;

    }
}
