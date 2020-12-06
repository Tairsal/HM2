#ifndef myBank
//a constant definition
#define ACC 50

float a[2][50];


int available();//makom panuy

float open_account(double amount);

int open_close(int account_number);//ACCOUNT PATUAH OR SAGUR

float account_Balance(int account_number);//2

double in_Balance(int account_number , double amount);//3

double out_Balance(int account_number , double amount);//4

float close(int account_number);//5

void interest(int interest_rate);//6

double print_Accounts();//7

int close_All();//8



#endif