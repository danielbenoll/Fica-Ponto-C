#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct ficha{
   char dia[3];
   char nome[15];
   char entrada[6];
   char saida[6];  
   char atividade[30];
};
struct ficha n[30];
char dia[3];
char enter, nome[15];
char entrada[6], saida[6], atividade[30];
int numLinhas = 0;
float valor=0, salario=0;

void menu();// este void está gerando o menu com as opções.
void inicializar();// este void vai abrir o arquivo txt e contar as variáveis e seus valores dentro do struct e levar pra variável.
void imprimir();// vai imprimir no cmd cada variável dentro do struct.
void cadastrar();// vai cadastrar mais uma linha dentro do arquivo txt.
void calcular();// vai calcular o salario de acordo com a quantidade de dias.

int main ( ) 
{
	setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

void menu(){  // este void está gerando o menu com as opções.
	//system("clear");
	int opcao = 0;
    do
    {
        printf(" \n      FICHA DE PONTO \n\n");
        printf(" \n 1. Inicializar a Estrutura" );
        printf(" \n 2. Imprimir a Estrutura" );
        printf(" \n 3. Incluir Registro no TXT" );
        printf(" \n 4. Para calcular salário." );
        printf(" \n 5. Para limpar CMD." );
        printf(" \n 6. Para sair." );
        printf(" \n\n Digite a opção desejada: ");
        scanf("%d%*c", &opcao);
        switch(opcao)
        {
            case 1:
               inicializar();
               break;
            case 2:
               imprimir();
               break;
            case 3:
               cadastrar();
               
               break;
            case 4:
               calcular();
               break;
			case 5:
				system("cls");
				break;      
            default:
               printf(" \n Encerrando");
               printf(".");
               printf(".");
               printf(".");
            break;
        }
    }
    while(opcao!=6);
}
	
void inicializar() // este void vai abrir o arquivo txt e contar as variáveis e seus valores dentro do struct e levar pra variável.
{

FILE *arq;
int i = 0; 
int linhas = 0;

arq = fopen("C:\\Users\\BIRIBIRI\\Documents\\v4\\ficha.txt","rt");
    
  if (!arq) return;{
   
        while (fscanf(arq,"%s %s %s %s %s %[\n]", dia, nome, entrada, saida, atividade, enter) != EOF) {
           
           strcpy(n[i].dia,dia);
           strcpy(n[i].nome,nome);
           strcpy(n[i].entrada,entrada);
           strcpy(n[i].saida,saida);
           strcpy(n[i].atividade,atividade);
           i++;
           linhas++;
       }
       numLinhas = linhas;
   }
   printf("\n\nInicializado com sucesso!!\n\n");
fclose (arq);
return;
}
void imprimir() // vai imprimir no cmd cada variável dentro do struct.
{
   int i;
   printf("\n");
   for (i=0; i < numLinhas; i++){
    	printf("%s %s %s %s %s \n",n[i].dia,n[i].nome,n[i].entrada,n[i].saida,n[i].atividade);
    	//system("pause");
      }
    printf("\n\nImprimido com sucesso!!\n\n");
}

void cadastrar()// vai cadastrar mais uma linha dentro do arquivo txt.
{
   int result, i = 0;
      
   FILE *arq;
   arq = fopen("C:\\Users\\BIRIBIRI\\Documents\\v4\\ficha.txt","a");
                     
   if (!arq) return;{
      printf(""); fflush (stdin);
      printf("\nDigite o dia: "); fflush (stdin);
      gets(n[i].dia);
      printf("Digite o Nome: "); fflush (stdin);
      gets(n[i].nome);
	  //scanf("%s",&n[i].nome);
      printf("Digite a hora de entrada: "); fflush (stdin);
      gets(n[i].entrada);
      //scanf("%f",&n[i].entrada);
      printf("Digite a hora da saida: "); fflush (stdin);
      gets(n[i].saida);
      //scanf("%f",&n[i].saida);
      printf("Digite a atividade: "); fflush (stdin);
      gets(n[i].atividade);
      //scanf("%f",&n[i].atividade);
         
	  /* Usando o fwrite
	  for (i = 0; i < 1; i++){
	  	 if ( !(strcmp(n[i].mat, "")==0) )
         {
            result = fwrite (&n[i], sizeof ( struct nota ), 1, arq );
            if ( result != 1 )
            {
               printf ( "Erro de escrita no arquivo. \n" );
            }
         }
	   }
	   */
	  fprintf(arq, "%s %s %s  %s  %s\n",n[i].dia,n[i].nome,n[i].entrada,n[i].saida,n[i].atividade);
   
   }
   //if (result == EOF){
   //	   printf("ERRO em gravar no ARQUIVO NOTA.TXT.");
   //}
   printf("\n\nHorário cadastrado com sucesso!!\n\n");
   fflush(arq) ;
   fclose (arq);
   return;
}

void calcular()// vai calcular o salario de acordo com a quantidade de dias.
{
	int i;
	float valor=0, salario=0;
	for (i=0; i < numLinhas; i++){
	  }
	printf("\n");
	printf("Digite o valor por dia: ");fflush (stdin);
	scanf("%f", &valor);fflush (stdin);
	salario = valor* i;fflush (stdin);
	printf("\nSeu salário é de: R$%.2f\n", salario);fflush (stdin);
}
