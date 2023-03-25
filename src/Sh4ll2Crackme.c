/*Solution to destructeur's Sh4ll2 crackme, the original .bin file can be found at: https://crackmes.one/crackme/5aef385633c5d41ac64b492f
Password is crackmes.one */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void main(int argc, char *argv[])

{
  int Result, Sum, i;
  size_t LenArgv;
  char *Value;
 

  if (argc != 2) {
    printf("Usage:<license pass code here [numbers only]>\n");
                    
    exit(0);
  }
  Sum = 0;
  i = 0;
  while(true) {
    LenArgv = strlen(argv[1]);
    if((int)LenArgv <= i) break;
    Value = *(char*)((long)i + argv[1]);
    Result = atoi(&Value);
    Sum = Sum + Result; //The program simply checks if the sum of digits in argv[1] is equal to 50, example:
    i++;                //5555555555 is a valid password, as well as 999995 and 488559164.
  }
  if (Sum == 50) {
    puts("Premium access has been activated !");
                 
    exit(0);
  }
  puts("Wrong license code");
                  
  exit(0);
}

