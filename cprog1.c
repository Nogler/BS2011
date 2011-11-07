#include <stdio.h>
#include <string.h>

int fibo(int s) {
/*	if(s==0)
	return 0;
	if(s==1)
	return 1;
	if(s==2)
	return 1;
	return fibo(s-1)+fibo(s-2);*/
//	return (s>1)?(fibo(s-1)+fibo(s-2)):((s==1)?1:0);
	return (s>1)?(fibo(s-1)+fibo(s-2)):s;
	}
//fizz buzz auch noch anschauen
void main(int arc, char *arg[]) {

char c = 'a';
char *p = &c;
int i=atoi(arg[1]);
printf("Bitte Zahl eingeben:\n");
//scanf("%d",&i);
printf("mit %d: %d\n", i,fibo(i));
}
