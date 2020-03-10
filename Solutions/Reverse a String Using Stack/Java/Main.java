/*
    GEEKSFORGEEKS
        DATA STRUCTURES
            STACKS
    
    REVERSE A STRING USING STACK
    coded by Fatih Cinar
    on March 11th, 2020
*/


class Main
{
    public static void main(String[] args){

        StringBuffer str = new StringBuffer("fatih");
        Reverser.reverseString(str);

        System.out.println(str);
    }
}
