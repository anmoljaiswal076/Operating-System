#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
int shared=2; //shared variable
int main()
{
pthread_t thread1;
pthread_t thread2;
pthread_create(&thread1, NULL, fun1, NULL);
pthread_create(&thread2, NULL, fun2, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2,NULL);
printf("Final value of share variable:%d\n",shared);//prints the last updated value of shared variable
}

void *fun1()
{
int a;
a=shared;//thread one reads value of shared variable
printf("Thread1 reads the value of shared variable as %d:\n",shared);
a=shared+2; //thread one increments its value
printf("Local updation by Thread1:%d\n",a);
sleep(1);
shared=a; //thread one updates the value of shared variable
printf("Value of shared variable updated by Thread1 is:%d\n",shared);
}

void *fun2()
{
int b;
b=shared;//thread two reads value of shared variable
printf("Thread2 reads the value as %d\n",b);
b=shared/2; //thread two decrements its value
printf("Local updation by Thread2: %d\n",b);
sleep(1);
shared=b; //thread one updates the value of shared variable
printf("value of shared variable updated by Thread2 is:%d\n",shared);
}
