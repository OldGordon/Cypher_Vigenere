/***********************************************
*   
*    Comment Template
*   
*    by GrinuX ( Toni Juliá Muntaner )
*  
*    CS50 2012 / pset2 / caesar.c
*
*    Palma de Mallorca Spain
*
*************************************************/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define START_UPPER  65 // this value is used to wrap over the Uppercase letters
#define START_LOWER  97 // this value is used to wrap over the lowercase letters
#define NUM_LETTERS  26 // value used due the english alphabet 

//Prototype of the function cipher()
string cipher(int , string);

int main (int argc, string argv[])
{   
    if ((argv[1] == NULL)||(argc < 2) ) //if there's not input from user
    {   
        //if no input program exit
        printf("Usage: /home/cs50/pset2/caesar <key> \n");        
        return 1;
    }
    
    // put the string into a variable as a integer.If is character different to a number atoi return 0 
    int key = atoi(argv[1]);
    
    if ((key == 0) || (key < 0)) // Control if the input is a negative number or a letter(thanks to atoi())
    { 
        return 1;  
    }
    //get the input from the user
    string words = GetString();
    
    //we send our correct data to a function that is going to cipher the sentence  
    cipher(key,words);
    
    return 0;
}

string cipher(int k, string s)
{
    //we have to iterate our string char by char
    for ( int i = 0,  n = strlen(s); i < n ; i++)
    {   
        char letter = s[i];//Once split the string we get a char each looping        int asc_letter;// Using integer for the char's ASCII value
                
        //If our char is a letter A<>Z or a<>z keep going
        if (isalpha(letter))
        {   
            //If our char is A<>Z 
            if (isupper(letter))
            {   
                //print the character ciphered using k to wrap over the alphabet
                asc_letter = ((letter - START_UPPER + k)% NUM_LETTERS)+ START_UPPER;
                s[i] = asc_letter;
                printf("%c", s[i]);
            }
            
            //If our char is a<>z
            if (islower(letter))
            {    
                //print the character ciphered using kto wrap over the alphabet
                asc_letter = ((letter - START_LOWER + k)% NUM_LETTERS)+ START_LOWER;
                s[i] = asc_letter;
                printf("%c", s[i]);
            }
            
        }
        
        // if the character is not a letter just print it 
        else
        {
            printf("%c",s[i]);
        }
    }
    
    
    printf("\n");
    return 0;
    
}
