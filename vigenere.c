/****************************************
*   
*    Comment Template
*   
*    by GrinuX ( Toni Juliá Muntaner )
*  
*    CS50 2012 / pset2 / vigenere.c
*
*    Palma de Mallorca Spain
*
*****************************************/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define START_UPPER  65 // this value is used to wrap over the Uppercase letters
#define START_LOWER  97 // this value is used to wrap over the lowercase letters
#define NUM_LETTERS  26 // value used due the english alphabet 


int main (int argc, string argv[])
{   
    if ((argv[1] == NULL)||(argc < 2) ) //if there's not input from user
    {   
        //if no input program exit
        printf("Usage: /home/cs50/pset2/vigenere <keyword> \n");        
        return 1;
    }
    string keyword = argv[1];//getting the key from the array of arguments
    // control if there's a key and if it's alpha
    if (keyword != NULL) 
    {
        for ( int i = 0 , n = strlen(keyword); i < n ; i++)
        {
            if (!isalpha(keyword[i]))
            {
                printf("Usage: /home/cs50/pset2/vigenere <keyword only alpha> \n");        
                return 1;
            }
        }        
    }   
    //get the input from the user
    string words = GetString();
       
    //we send our correct data to a function that is going to cipher the sentence  
    int n = strlen(words);
    int m = strlen(keyword);
    int value[n];//array containing ASCII values
    
    // words ascii values into value
    for (int i = 0 ; i < n ; i++ )
    {   
         value[i] =  words[i];
         //printf("%d...", value[i]); 
    }
    
    //keyword ascii values 
    //here I put the ascii values inside the  array itself
    for (int i = 0 ; i < m ; i++)
    {
         int index = keyword[i];
         
         if(isupper(index))//if it's uppercase a alphabet value 0..26
         {
             index = index - START_UPPER;
             keyword[i] = index;
         }
         else if (islower(index))//if lowercase the same value
         {
             index = index - START_LOWER;
             keyword[i] = index;
         }
         
    }
    
    // this loop is fot checking and printing the string already coded
    for (int i = 0, j = 0 ; i < n ; i++)
    {
           
        char letter ;
        // char key;
        if (isalpha(value[i]))
        {
            if (isupper(value[i]))// case is uppercase
            {
                letter = (((value[i]- START_UPPER) + keyword[j]) % NUM_LETTERS) + START_UPPER;
                printf("%c", letter);
                j++;
                if (j == m )
                {
                    j = 0;    
                }
            }
            if (islower(value[i]))//in case of lowercase  
            {
                letter = (((value[i]- START_LOWER) + keyword[j]) % NUM_LETTERS) + START_LOWER;
                printf("%c", letter);
                j++;
                if (j == m )
                {
                    j = 0;    
                }
            }
        }
        else
        {
            printf("%c", value[i]);// we print the result
        }
        
    }
    printf("\n");
    
    return 0;// END
}



    
    
    

