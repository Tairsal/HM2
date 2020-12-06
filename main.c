#include <stdio.h>
#include "myBank.h"

float a[2][ACC];

int main()
{

char act=0;
int status=1;

int counter=901;

for (int i = 0; i < ACC; ++i)
{
	a[0][i]=counter;
	a[1][i]=0;
	a[2][i]=0;
	counter++;
}

while(status)	
{
printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");

if(scanf(" %c",&act)==1){
switch(act)
{
        case 'O':
           	if (available()==1)
           	{
           		float static mon;
           		printf("Please enter amount for deposit: ");
           		if(scanf("%f",&mon)==1){
                    if(mon>0){
                       printf("New account number is: %d\n\n",(int)open_account(mon));
                    }
                    else{
                       printf("Invalid amount\n\n");
                    }
               }
               else{
                  printf("Failed to read the amount\n\n");
               }
           	}
           	else{
           		printf("There is no accounts available!\n\n");
           	}
			break;
			

        case 'B':
           printf("Please enter account number: ");
           float num;
           if(scanf("%f",&num)==1){
              if(num>=901 && num<=950){
                 if(open_close(num)==1){
                    printf("The balance of account number %d is: %.2f\n\n",(int)num,account_Balance(num));
                  }
                  else{
                     printf("This account is closed\n\n");
                  }
              }
              else{
                 printf("Invalid account number\n\n");
              }
           }
           else{
              printf("Failed to read the account number\n\n");
           }

           break;
        
        case 'D':
           printf("Please enter account number: ");
           float num1,amount;
           if(scanf("%f",&num1)==1){
              if(num1>=901 && num1<=950){
                 if(open_close(num1)==1){
                    printf("Please enter the amount to deposit: ");
                    if(scanf("%f",&amount)==1){
                       if(amount>0){
                          printf("The new balance is: %.2f\n\n",in_Balance(num1,amount));
                       }
                       else{
                          printf("Cannot deposit a negative amount\n\n");
                       }
                    }
                    else{
                       printf("Failed to read the amount\n\n");
                    }
                  }
                  else{
                     printf("This account is closed\n\n");
                  }
              }
               else{
                  printf("Invalid account number\n\n");
               }
            }
           else{
              printf("Failed to read the account number\n\n");
            }
           break;

		  case 'W':
           printf("Please enter account number: ");
           float num2,amount2;
           if(scanf("%f",&num2)==1){
              if(num2>=901 && num2<=950){
                 if(open_close(num2)==1){
                    printf("Please enter the amount to withdraw: ");
                    if(scanf("%f",&amount2)==1){
                       if(amount2>0){
                          if(account_Balance(num2)>=amount2){
                             printf("The new balance is: %.2f\n\n",out_Balance(num2,amount2));
                           }
                           else{
                              printf("Cannot withdraw more than the balance\n\n");
                           }
                        }
                        else{
                           printf("Invalid amount\n\n");
                        }
                     }
                     else{
                        printf("Failed to read the amount\n\n");
                     }
                  }
                  else{
                     printf("This account is closed\n\n");
                  }
               }
               else{
                  printf("Invalid account number\n\n");
               }
            }
            else{
               printf("Failed to read the account number\n\n");
            }
           
            break;
        case 'C':
        	  printf("Please enter account number: ");
           float num3;
           if(scanf("%f",&num3)==1){
              if(num3>=901 && num3<=950){
                 if(open_close(num3)==1){
                    printf("Closed account number %d\n\n",(int)close(num3));
                  }
                  else{
                     printf("This account is already closed\n\n");
                  }
               }
               else{
                  printf("Invalid account number\n\n");
               }
           }
           else{
              printf("Failed to read the account number\n\n");
           }
           
        	break;
        case 'I':
           printf("Please enter interest rate: ");
           int rate;
           if(scanf("%d",&rate)==1){
              if(rate>0){
                 interest(rate);
                 printf("\n");
              }
              else{
                 printf("Invalid interest rate\n\n");
              }
           }
           else{
              printf("Failed to read the interest rate\n\n");
           }

           break;
        case 'P':
        	print_Accounts();
        	break;
        case 'E':
           close_All();
           status=0;
           break;
        default:
          	printf("Invalid transaction type\n\n");
         
        
    }
	
}
}

return 0;
}
	

