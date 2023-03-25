/*Solution for MODWare's PowerFul_Crackme, original .elf file can be download at this link: https://crackmes.one/crackme/6141b45933c5d4649c52ba6f
Password is crackmes.one */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char UsrInput[28];
signed long hidden = 0x626f676a61667062; //bogjafpb
signed int secret = 0x7769; //wi

/*MOV RAX, 0x626f676a61667062
  MOV qword ptr [RBP + hidden], RAX
  MOV word ptr [RBP + secret], 0x7769
  ....
  bogjafpbwi ASCII FOR HEX: 0x626f676a61667062

 
Use this function to print the string that is compared at line 62

void PrintHidden(void){

            int main(void){

    signed long hidden = 0x626f676a61667062;
    signed int secret = 0x7769;
    for(int i = 0; i < 9; i++){
    UsrInput[i + 7] = *(char *)((long)&FinalStr + i);
    printf("%c", UsrInput[i + 7]);
         }
    UsrInput[16] = *(char *)((long)&secret + 0);
    UsrInput[17] = *(char *)((long)&secret + 1);
    printf("%c",UsrInput[16]);
    printf("%c", UsrInput[17]);
    puts("");
    return 0;
            }
                } 

                    */  
int main(void){

  //PrintHidden();
  printf("The magic string: ");
  for (int i = 0; i < 10; i++) {
    scanf(" %c", UsrInput + (long)i + 18);
  }
  for (int k = 0; k < 10; k++) {
    if (k < 7) {
      UsrInput[k + 10] = UsrInput[k + 18];  //UsrInput[10] till Usrinput[16] = seven first characters
    }
    else {
      UsrInput[k] = UsrInput[k + 18]; //After that, UsrInput[7] till UsrInput[9] = 8th,9th,10th characters respectively.
    }
  }
    
 UsrInput[17] = 0;
 int r = 0;
 while(true){
    if (r > 9){
      printf("Congratulations, correct flag!\nThe flag is: WatadCTF: {%s}\n",UsrInput + 18);
      return 0;
    }
    if(UsrInput[r + 7] != *(char *)((long)&hidden + (long)r)) break;  // Compares UsrInput to: bpfajgobiw, so: UsrInput[7] = 'b', Usrinput[8] ='p' and so on...
    r++;                                                              /* To match this result the uSrInput needs to be: ajgobiwbpf, since the transformations turn 
                                                                         this string into the desired string bogjafpbwi, as the order is:
                                                                         a(10)j(11)g(12)o(13)b(14)i(15)w(16)b(7)p(8)f(9) = ajgobiwbpf
                                                                                                                                        */
    
                 }
    puts("Wrong input!");
    return 0;
}
