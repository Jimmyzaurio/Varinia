#include <stdio.h>
#include <math.h>

#define lli long long int

#define TRES 1000
#define SEIS 1000000
#define NUEVE 1000000000
#define DOCE 1000000000000

#define LA a/SEIS
#define MA (a/TRES) % TRES
#define RA a%TRES

#define LB b/SEIS
#define MB (b/TRES) % TRES
#define RB b%TRES

int mult2(int a, int b) {
	if(b/10 == 0 || a/10 == 0)
		return a*b;
	return
		mult2(floor(a/2),  ceil(b/2)) +
		mult2( ceil(a/2), floor(b/2)) +
		mult2(floor(a/2), floor(b/2)) +
		mult2( ceil(a/2),  ceil(b/2));
}

lli mult3(lli a, lli b) {
	if(a < 1000 && b < 1000)
		return a*b;
	return
		(DOCE*mult3(LA,LB)) + (NUEVE*mult3(MA,LB)) + (SEIS*mult3(RA,LB)) +
		(NUEVE*mult3(LA,MB))+ (SEIS*mult3(MA,MB)) + (TRES*mult3(RA,MB)) +
		(SEIS*mult3(LA,RB)) + (TRES*mult3(MA,RB)) + (mult3(RA,RB));
}

int main() {
	int a,b;

	while(scanf("%d%d", &a, &b) == 2)
		printf("%lli\n", mult3(a,b)); 
	return 0;
}
