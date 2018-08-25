/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Transport card manager

     COMP9024 18s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
//#include <math.h>

#include "cardRecord.h"
#include "cardLL.h"

void printHelp();
void CardLinkedListProcessing();
int get_int_len();
void clean_stdin();

int main(int argc, char *argv[]) {
   if (argc == 2) {

      /*** Insert your code for stage 1 here ***/
      int card_id;
      float amount;
      int total = 0;
      float avgbalance;
      int ID_array_len = strtol(argv[1], NULL, 10);   //length of ID_array
      int *ID_array;    //pointer of ID_array
      int amount_array_len = strtol(argv[1], NULL, 10);   //length of amount_array
      float *amount_array;    //pointer of amount_array
      ID_array = (int*)malloc( ID_array_len*sizeof(int) ); //build ID_array
      amount_array = (float*)malloc( amount_array_len*sizeof(int) ); //build amount_array
      //check if we build the arries successful
      if (!ID_array || !amount_array){
         exit(1);
      }
      for (int i = 0; i < ID_array_len; i++){
         printf("Enter card ID: ");
         //check if the input is number, and if the length is 8
         //in this case, "01234567" starts with 0 and length is 7
         //it can not satify the condition. On the other hand, "012345678"
         //seems starts with 0 and length is 9. In fact it equals to "12345678"
         while(scanf("%d",&card_id) == 0 || get_int_len(card_id) != 8){
            printf("Not valid. Enter a valid value: ");
            //fflush(stdin); //empty the input
	    clean_stdin();
         }
         ID_array[i] = card_id;
         printf("Enter amount: ");
         //check if the input is a float number, and if the floor and roof is -2.35 and 250
         while(scanf("%f",&amount) == 0 || amount < -2.35 || amount > 250){
            printf("Not valid. Enter a valid value: ");
            //fflush(stdin); //empty the empty
	    clean_stdin();
         }
         amount_array[i] = amount;
      }
      for (int k = 0; k < ID_array_len; k++){
         printf("-----------------\n");
         printf("Card ID: %d\n",ID_array[k]);
	 if (amount_array[k] < 0){
	     printf("Balance: -$%.2f\n",-amount_array[k]);
	 }else{printf("Balance: $%.2f\n",amount_array[k]);}
         if (amount_array[k] < 5){
            printf("Low balance\n");
         }
         printf("-----------------\n");
         total += amount_array[k];
      }
      avgbalance = total/ID_array_len;
      printf("Number of cards on file: %d\n",ID_array_len);
      printf("Average balance: $%.2f\n",avgbalance);
      free(ID_array); //free the memory
      free(amount_array); //free the memory
   } else {
      CardLinkedListProcessing();
   }
   return 0;
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int get_int_len (int value){
  int l=1;
  while(value>9){ l++; value/=10; }
  return l;
}

/* Code for Stages 2 and 3 starts here */

void CardLinkedListProcessing() {
   int op, ch;

   List list = newLL();   // create a new linked list

   while (1) {
      printf("Enter command (a,g,p,q,r, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
            /*** Insert your code for adding a card record ***/

	    break;

         case 'g':
         case 'G':
            /*** Insert your code for getting average balance ***/

	    break;

         case 'h':
         case 'H':
            printHelp();
	    break;

         case 'p':
         case 'P':
            /*** Insert your code for printing all card records ***/

	    break;

         case 'r':
         case 'R':
            /*** Insert your code for removing a card record ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" a - Add card record\n" );
   printf(" g - Get average balance\n" );
   printf(" h - Help\n");
   printf(" p - Print all records\n" );
   printf(" r - Remove card\n");
   printf(" q - Quit\n");
   printf("\n");
}
