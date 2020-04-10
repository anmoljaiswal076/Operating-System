#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main() {
    
    char *args[]={"./secondprog",NULL};
    execv(args[0],args);
    
    int n, i;
    printf("Enter an integer: ");
    scanf("%d", &n);
    for (i = 1; i <= 10; ++i) {
        printf("%d * %d = %d \n", n, i, n * i);
    }
    return 0;
}
  2nd program:
 // Fibonacci Series using Recursion 
#include <stdio.h> 
int fib(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fib(n - 1) + fib(n - 2); 
} 
  
int main() 
{ 
    int n = 9; 
    printf("%d", fib(n)); 
    getchar(); 
    return 0; 
} 

}
