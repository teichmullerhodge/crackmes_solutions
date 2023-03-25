/*Solution to RaphDev's PleaseCrackMe, the original file can be found at: https://crackmes.one/crackme/612e85d833c5d41acedffa4f
Password is crackmes.one */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(void)

{
  int Flag, Digit, i; 
  size_t Len;
  char Usrname[32]; char Key[32]; char Password[24];
  
  printf("Type in your Username: ");
  scanf("%s", Usrname);
  printf("\nType in a number beetween 1 and 9: ");
  scanf("%d", &Digit);
  if (Digit < 1) {
    puts("\nError: Number is too small");
    return 0;
  }
  else if (Digit < 10) {
    i = 0;
    while(true)  {
      Len = strlen(Usrname);
      if (Len <= i) break;                //checks for the len of username.
      Key[i] = (char)Digit + Usrname[i]; //The number provided by the User is the number that's going here in this sum.
      i++;                              /*For example, if the Username is Hello and the digits is 1, the password is going to be Ifmmp.
                                        if the digit is 2, the password is Jgnnq and so on..  
                                        it's similar to Caesar Cypher but with only 10 possibilites. */
                                    }
    printf("\nType in the password: ");
    scanf("%s", Password);
    Flag = strcmp(Key,Password);
    if (Flag == 0) {
      puts("\nYou are succesfully logged in");
    }
    else {
      puts("\nWrong password");
    }
    return 0;
  }
  else {
    puts("\nError: Number is too big");
    return 0;
  }

    }
  
