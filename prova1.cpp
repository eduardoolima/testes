#include<iostream>
#include<string.h>

struct registro
{
	char nome[20];
	char curso[20];
	float media;
	int numero;
};

int aux=0;

void cadastrar(FILE *);
void mostrar(FILE *);
int tamanho(FILE *arq);


int main()
{
	int op;
	FILE *arq;

	if ((arq = fopen("alunos.dat", "rb+")) == NULL)
	{
		if ((arq = fopen("alunos.dat", "wb+")) == NULL)
		{
			printf("Falha ao abrir o arquivo!\n");
			system("pause");
		}
	}
	do
	{
		system("CLS");
		printf("1. Cadastrar alunos\n");
		printf("2. mostrar alunos\n");
		printf("3. Sair\n\n");
		printf("\nOpcao: ");
		scanf("%d",&op);
		printf("============================\n");
		printf("%d",sizeof(registro));
		switch(op)
		{
			case 1:
				cadastrar(arq);
				break;
			case 2:
				mostrar(arq);
				break;
			case 3:
				fclose(arq);
		}		
	}while(op!=3);
	
	
}

void cadastrar(FILE *arq)
{
	registro aluno;
	char confirma;
	float nota1, nota2;
	fflush(stdin);

	printf("Cadastrando aluno:\n\n");
	printf("\nNumero do aluno:%d\n", tamanho(arq) + 1);
	aluno.numero=tamanho(arq)+1;
	aux=aux+tamanho(arq)+1;
	printf("Nome: ");
	gets(aluno.nome);
	printf("Curso: ");
	gets(aluno.curso);
	printf("nota 1: ");
	scanf(" %f",&nota1);
	printf("nota 2: ");
	scanf(" %f",&nota2);
	aluno.media=((nota1+nota2)/2);
	printf("\nConfirma <s/n>:");
	fflush(stdin);
	scanf("%c", &confirma);

	if (toupper(confirma) == 'S')
	{
		printf("\ngravando...\n\n");
		fseek(arq, 0, SEEK_END);
		fwrite(&aluno, sizeof(registro), 1, arq);
	}
	system("pause");
}

void mostrar(FILE *arq)
{
	registro aluno;
	printf("%d",aux);
	for(aluno.numero=1;aluno.numero<=tamanho(arq);aluno.numero++)
	{
		fseek(arq, (aluno.numero - 1) * sizeof(registro), SEEK_SET);
		fread(&aluno, sizeof(registro), 5, arq);
		printf("\nNome....:%s", aluno.nome);
		printf("\nNumero..:%s", aluno.numero);
		printf("\nCurso...:%s", aluno.curso);
		printf("\nMedia...:%f\n", aluno.media);
	}

	system("pause");
}


int tamanho(FILE *arq)
{
	fseek(arq, 0, SEEK_END);
	return ftell(arq) / sizeof(registro);
}






