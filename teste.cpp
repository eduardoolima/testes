#include<iostream>

int main()
{
	FILE *arq;
	arq=fopen("meu arquivo de testes","w+");
	char string[10];
	printf("digite uma palavra: ");
	gets(string);
	fwrite(&string,sizeof(string),1,arq);
	return 0;
}
