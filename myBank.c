#include <stdio.h>
#define ACC 50

float a[2][ACC];


int available()//ACCOUNT ZAMIN
{
	int static ans;
	for (int i = 0; i < ACC; ++i)
	{
		if ((a[1][i])==0)
		{
			ans =1;
			break;
			
		}
		else
		{
			ans=0;
		}
	}
	return ans;
}

float open_account(double mon){
	float static num;
	for (int i = 0; i < ACC; ++i){
		if ((a[1][i])==0){
			a[2][i]=mon;
			num=(a[0][i]);
			a[1][i]=1;
			
			break;
			}
			else{
				num=0;
			}
		}
	return num;
}

int open_close(int account_number){//ACCOUNT PATUAH OR SAGUR
	int static ans;
	for (int i = 0; i < ACC; ++i)
	{
		if ((a[0][i])==account_number)
		{
			ans=a[1][i];
			break;
		}
		else{
			ans=0;
		}
	}
	return ans;
}
float account_Balance(int account_number){
	
	float static ans;
	for (int i = 0; i < ACC; i++)
	{
		if ((a[0][i])==account_number)
		{
			ans=a[2][i];
			break;
		}
		else{
			ans=0;
		}
	}
return ans;
	
}
double in_Balance(int account_number , double amount){//HAFKADA
	float static ans;
	for (int i = 0; i < ACC; ++i)
	{
		if ((a[0][i])==account_number)
		{
			 a[2][i]+= amount;
			 ans=a[2][i];
			break;
		}
		else{
			ans=0;
		}
	}
	return ans;
}

double out_Balance(int account_number , double amount){//MESHICHA
	float static ans;
	for (int i = 0; i < ACC; ++i)
	{
		if ((a[0][i])==account_number)
		{
			 a[2][i]-= amount;
			 ans=a[2][i];
			break;
		}
		else{
			ans=a[2][i];
		}
	}
	return ans;
}

float close(int account_number){
	float static ans;
	for (int i = 0; i < ACC; ++i)
	{
		if ((a[0][i])==account_number)
		{
			 a[1][i]=0;
			 a[2][i]=0;
			 ans=a[0][i];
			break;
		}
		else{
			ans=0;
		}
	}
	return ans;
}

void interest(int interest_rate){
	for (int i = 0; i < ACC; ++i)
	{
		if ((a[1][i])==1)
		{
			a[2][i]+=(float)interest_rate/100*a[2][i];
		}
	}
			
}

void print_Accounts(){
	for (int i = 0; i < ACC; ++i)
	{
		if ((a[1][i])==1)
		{
			
			printf("The balance of account number %d is: %.2f\n",(int)a[0][i],a[2][i]);
		}
	}
	printf("\n");
}

void close_All(){
	for (int i = 0; i < ACC; ++i)
	{
		a[1][i]=0;
		a[2][i]=0;
	}
}