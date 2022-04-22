#include <stdlib.h>
#include <stdio.h>

void print_out(const char* p, const int x)
{
    printf("p is \"%s\" and x is %i\n", p, x);
}

int main()
{
//1.

printf("Hello, World!\n");

//2.

char * hello = "Hello, ";
char * world = "World!";

printf("%s %s\n", hello, world); //%s means “Print a C-style string

//3.

print_out("January", 26);
print_out("Sherlock", 221);
print_out("C", 89);


return 0;

}