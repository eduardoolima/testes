#include<iostream>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

void limpa(char matriz[3][3]);
void printa_velha(char matri[3][3]);
void jogada_cpu(char matriz[3][3]);

//funçoes para verificar vencedor

int verifica_xl1(char matr[3][3]);
int verifica_ol1(char matr[3][3]);
int verifica_xl2(char matr[3][3]);
int verifica_ol2(char matr[3][3]);
int verifica_xl3(char matr[3][3]);
int verifica_ol3(char matr[3][3]);
int verifica_xc1(char matr[3][3]);
int verifica_oc1(char matr[3][3]);
int verifica_xc2(char matr[3][3]);
int verifica_oc2(char matr[3][3]);
int verifica_xc3(char matr[3][3]);
int verifica_oc3(char matr[3][3]);
int verifica_xd1(char matr[3][3]);
int verifica_od1(char matr[3][3]);
int verifica_xd2(char matr[3][3]);
int verifica_od2(char matr[3][3]);


main()
{
	char velha[3][3];
	int i, j, linha, coluna, op, nj=1,numero_elementos=0, veri_aux1=0, veri_aux2=0; 
	
	setlocale(LC_ALL,"");
	do
	{
		printf("               Menu\n");
		printf("\n 1. Jogar 1 VS 1 \n");
		printf(" 2. Jogar VS CPU\n");
		printf(" 3. Créditos\n");
		printf(" 4. Sair\n");
		printf("====================\n");
		printf("Sua opção: ");
		scanf("%d",&op);
		system("CLS");
		switch(op)
		{
			case 1:
				limpa(velha);
				numero_elementos=0;
				veri_aux1==0;
				veri_aux2==0;
				for ( i=0;i<3;i++)
				{
					for ( j=0;j<3;j++)
					{
						printa_velha(velha);
						printf("Jogador %d\n\n",nj);
						printf(" Digite a linha desejada: ");
						scanf(" %d",&linha);
						while((linha<1)||(linha>3))
						{
							printf("                Linha invalida!\n\n");
							system("pause");
							system("CLS");
							printa_velha(velha);
							printf("Jogador %d\n\n",nj);
							printf(" Digite a linha desejada: ");
							scanf(" %d",&linha);
						}
						printf("\n Digite a coluna desejada: ");
						scanf(" %d",&coluna);
						while((coluna<1)||(coluna>3))
						{
							printf("                Coluna invalida!\n\n");
							system("pause");
							system("CLS");
							printa_velha(velha);	
							printf("Jogador %d\n\n",nj);
							printf(" Digite a linha desejada: %d\n\n",linha);
							printf(" Digite a Coluna desejada: ");
							scanf(" %d",&coluna);
						}
						while(velha[linha][coluna]!=0)
						{
							printf("                Casa ocupada!\n\n");
							system("pause");
							system("CLS");
							printa_velha(velha);
							printf("Jogador %d\n\n",nj);
							printf(" Digite a linha desejada: ");
							scanf(" %d",&linha);
							printf("\n\n Digite a Coluna desejada: ");
							scanf(" %d",&coluna);
						}
						if(nj==1)
							velha[linha][coluna]='X';
						if(nj==2)
							velha[linha][coluna]='O';
						nj++;
						if(nj>2)
							nj=1;
						numero_elementos++;
						if(numero_elementos!=9)
							system("CLS");
						else
						{
							system("CLS");
							printa_velha(velha);	
						}
						if(verifica_xl1(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_ol1(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xl2(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}	
						if(verifica_ol2(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xl3(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_ol3(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xc1(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_oc1(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xc2(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_oc2(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xc3(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_oc3(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xd1(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_od1(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xd2(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_od1(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
					}		
				}
				if((numero_elementos==9)&&(veri_aux1==0)&&(veri_aux2==0))
				{
					system("CLS");
					printf("\n\n\n\n  					  VELHA!!!!\n\n\n");
				}	
				limpa(velha);
				numero_elementos=0;
				system("pause");
				system("CLS");
				nj=1;
				break;
			case 2:
				limpa(velha);
				numero_elementos=0;
				for (int i=0;i<3;i++)
				{
					for (int j=0;j<3;j++)
					{
						if(nj==2)
						{
							srand(time(NULL));
							linha = (rand() % 3)+1;
							coluna = (rand() % 3)+1;
							while(velha[linha][coluna]!=0)
							{
								srand(time(NULL));
								linha = (rand() % 3)+1;
								coluna = (rand() % 3)+1;		
							}	
							velha[linha][coluna]='O';
							printa_velha(velha);
						}
						else
						{
							printa_velha(velha);
							printf(" Digite a linha desejada: ");
							scanf("%d",&linha);
							while((linha<1)||(linha>3))
							{
								printf("                Linha invalida!\n\n");
								system("pause");
								system("CLS");
								printa_velha(velha);
								printf("Jogador %d\n\n",nj);
								printf(" Digite a linha desejada: ");
								scanf(" %d",&linha);
							}
							printf("\n Digite a coluna desejada: ");
							scanf(" %d",&coluna);
							while((coluna<1)||(coluna>3))
							{
								printf("                Coluna invalida!\n\n");
								system("pause");
								system("CLS");
								printa_velha(velha);	
								printf("Jogador %d\n\n",nj);
								printf(" Digite a linha desejada: %d\n\n",linha);
								printf(" Digite a Coluna desejada: ");
								scanf(" %d",&coluna);
							}
							while(velha[linha][coluna]!=0)
							{
								printf("                Casa ocupada!\n\n");
								system("pause");
								system("CLS");
								printa_velha(velha);
								printf("Jogador %d\n\n",nj);
								printf(" Digite a linha desejada: ");
								scanf(" %d",&linha);
								printf("\n\n Digite a Coluna desejada: ");
								scanf(" %d",&coluna);
							}
							if(nj==1)
								velha[linha][coluna]='X';		
						}
						nj++;
						if(nj>2)
							nj=1;
						numero_elementos++;
						if(numero_elementos!=9)
							system("CLS");
						else
						{
							system("CLS");
							printa_velha(velha);	
						}
						if(verifica_xl1(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_ol1(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xl2(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}	
						if(verifica_ol2(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xl3(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_ol3(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xc1(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_oc1(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xc2(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_oc2(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xc3(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_oc3(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xd1(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_od1(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
						if(verifica_xd2(velha))
						{
							i=4;j=4;
							veri_aux1++;
						}
						if(verifica_od2(velha))
						{
							i=4;j=4;
							veri_aux2++;
						}
					}		
				}
				if((numero_elementos==9)&&(veri_aux1==0)&&(veri_aux2==0))
				{
					printf("						VELHA!!!!\n\n");
				}	
				limpa(velha);
				numero_elementos=0;
				system("pause");
				system("CLS");
				nj=1;
				break;
			case 3:
				system("CLS");
				printf(" \nFeito total e unicamente por Eduardo Lima, o programador\n mais maravilhoso do multiverso!\n\n");
				system("pause");
				system("CLS");
				break;
			default:	
				if(op>4)
				{
					printf("\n\n				Opção inexistente\n\n");
					system("pause");
					system("CLS");	
				}
				break;
		}	
	}while(op!=4);	
}

void limpa(char matriz[3][3])
{
	for (int i=1;i<4;i++)
	{
		for (int j=1;j<4;j++)
		{
			matriz[i][j]=0;
		}
	}
}

void printa_velha(char matri[3][3])
{
	printf("	\n\n 	              JOGO DA VELHA\n\n\n");
	printf("	                1   2   3\n");
	printf("	              -------------\n");
	printf("	           1  | %c | %c | %c |\n",matri[1][1],matri[1][2],matri[1][3]);
	printf("	              -------------\n");
	printf("	           2  | %c | %c | %c |\n",matri[2][1],matri[2][2],matri[2][3]);
	printf("	              -------------\n");
	printf("	           3  | %c | %c | %c |\n",matri[3][1],matri[3][2],matri[3][3]);
	printf("	              -------------\n");
	printf("\n\n");	
}

int verifica_xl1(char matr[3][3])
{
	if((matr[1][1]=='X') && (matr[1][2]=='X') && (matr[1][3]=='X'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 1 Venceu!!!!!!\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_ol1(char matr[3][3])	
{

	if((matr[1][1]=='O') && (matr[1][2]=='O') && (matr[1][3]=='O'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 2 Venceu!!!!!!\n\n\n");
		return 1;
	}	
	else
	{
		return 0;
	}
}

int verifica_xl2(char matr[3][3])
{
	if((matr[2][1]=='X') && (matr[2][2]=='X') && (matr[2][3]=='X'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 1 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_ol2(char matr[3][3])
{
	if((matr[2][1]=='O') && (matr[2][2]=='O') && (matr[2][3]=='0'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 2 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_xl3(char matr[3][3])
{
	if((matr[3][1]=='X') && (matr[3][2]=='X') && (matr[3][3]=='X'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 1 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_ol3(char matr[3][3])
{
	if((matr[3][1]=='O') && (matr[3][2]=='O') && (matr[3][3]=='O'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 2 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_xc1(char matr[3][3])
{
	if((matr[1][1]=='X') && (matr[2][1]=='X') && (matr[3][1]=='X'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 1 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_oc1(char matr[3][3])
{
	if((matr[1][1]=='O') && (matr[2][1]=='O') && (matr[3][1]=='O'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 2 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_xc2(char matr[3][3])
{
if((matr[1][2]=='X') && (matr[2][2]=='X') && (matr[3][2]=='X'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 1 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}	
}

int verifica_oc2(char matr[3][3])
{
	if((matr[1][2]=='O') && (matr[2][2]=='O') && (matr[3][2]=='O'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 2 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_xc3(char matr[3][3])
{
	if((matr[1][3]=='X') && (matr[2][3]=='X') && (matr[3][3]=='X'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 1 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_oc3(char matr[3][3])
{
	if((matr[1][3]=='O') && (matr[2][3]=='O') && (matr[3][3]=='O'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 2 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_xd1(char matr[3][3])
{
	if((matr[1][1]=='X') && (matr[2][2]=='X') && (matr[3][3]=='X'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 1 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_od1(char matr[3][3])
{
	if((matr[1][1]=='O') && (matr[2][2]=='O') && (matr[3][3]=='O'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 2 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_xd2(char matr[3][3])
{
	if((matr[1][3]=='X') && (matr[2][2]=='X') && (matr[3][1]=='X'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 1 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_od2(char matr[3][3])
{
	if((matr[1][3]=='O') && (matr[2][2]=='O') && (matr[3][1]=='O'))
	{
		system("CLS");
		printa_velha(matr);
		printf("\n                  Jogador 2 Venceu!!!!!!\n\n\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

