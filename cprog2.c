#include <stdio.h>
#include <string.h>

int sub(int a) {

int b;
b=a-1;
printf("\nIn der Schlauf: %p\n\n",&a);
return b;
}

void main(int arc, char *arg[]) {

int a = 10;

sub(a);

printf("nach der Subtraktion:%p \n", &a);
}
