#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int concat(int a, int b)
{
	char s1[30], s2[30];
	sprintf(s1, "%d", a);
	sprintf(s2, "%d", b);
	strcat(s1, s2);
    return atoi(s1);
}

//Em casos onde o número é muito grande, acaba sendo ineficiente.
int verifyConcat(int A, int B)
{
	int a = A, b = B;
	int cont = 0;
	while(a > 0)
	{
		b = B;
		while(b > 0)
		{
			if(a*b + a + b == concat(a,b))
				cont++;
			b--;
		}
		a--;
	}
    return cont;
}

int verifyConcat2(int A, int B)
{
	char s[30];
	sprintf(s, "%d", B);
	if(s[strlen(s)-1] == '9') return A*strlen(s);
	
	return A*(strlen(s)-1);
	
}


int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Portuguese");
    int A = 191;
    int B = 31415926;
	//printf("%d", verifyConcat(A, B));
    printf("%d", verifyConcat2(A, B));
    return 0;
}
