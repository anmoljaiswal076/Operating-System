Que1.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void* income_tax(void * arg)
{
	int *ptr=(int *)arg;
	void *b=ptr;
	if((*ptr)<=400000)	
	{
		*ptr =((*ptr)*1)/100;	// 1% if amount is less than or equal to 4,00,000 
	}
	else if(((*ptr)>400000)&&((*ptr)<1000000))
	{
		*ptr =((*ptr)*5)/100;	//5% if amount is greater than 4,00,000 and less than 10,00,000
	}
	else if((*ptr)>1000000)
	{
		*ptr =((*ptr)*12)/100;	// 12% if amount is greater than 10,00,000 
	}
	return b;
} 
int main()
{
int salary;
void *b;
pthread_t t;
printf("enter the salary for which income tax must be calculated : ");
scanf("%d",&salary);
pthread_create(&t,NULL,income_tax,&salary);
pthread_join(t,&b);
printf("the income tax for the entered amount is : %d  ",*(int *)b);
}
