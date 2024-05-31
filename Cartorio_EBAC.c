#include <stdio.h> //biblioteca de comiunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsevel pela string

int registro()//responsavel por cadastrar usuarios no sistema
{
    // inicio das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final das variaveis/string
	
	printf("digite o cpf a ser registrado: "); //coletando informa��o do usuario 
	scanf("%s", cpf); //%s se refere as string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo "w" significa escrever
	fprintf(file,cpf); //salvo o valor da veriavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("digite o nome a ser cadastrado: ");//coletando informa��o do usuario 
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file, nome);
	fclose(file);//fecha o arquivo	
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("digite o sobrenome a ser cadastrado: ");//coletando informa��o do usuario 
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,sobrenome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("digite o cargo a ser cadastrado: ");//coletando informa��o do usuario 
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,cargo);
	fclose(file);//fecha o arquivo
	
	system("pause");	
}

int consulta()
{
    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	// inicio das variaveis/string
	char cpf[40];
	char conteudo[200];
	// final das variaveis/string
	printf("digite o cfp a ser consultado: ");//coletando informa��o do usuario 
	scanf("%s", cpf);//%s se refere as string
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	 while(fgets(conteudo, 200, file) != NULL) 
	 {
	 	printf("\nEssas s�o as informa��es do usu�rio: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	system("pause");	
}

int deletar()
{
	 char cpf[40];
	 
	 setlocale(LC_ALL, "portuguese");
	 
	 printf("Digite o cpf do usu�rio a ser deletado: ");//coletando informa��o do usuario 
	 scanf("%s", cpf);
	 
	 remove(cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r");
	 
	 if(file == NULL)
	 {
	 	printf("\nO usu�rio n�o se encontra no sistema!\n\n");	
	 }
	 system("pause");
	 
}

int main ()
{
	int opcao=0; //Definindo Variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
    	system("cls");//limpa a tela

	
	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem


	    printf("### Cart�rio da EBAC ###\n\n"); //Iniciando o menu
  	    printf("escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n");
	    printf("\t4 - sair do programa\n");
	    printf("Op��o: ");//Fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls");
	    
	    
	    switch(opcao)
	    {
	    	case 1:
			registro();
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("obrigado por utilizar o sistema");
			return(0);
			break;
					    
		    default:
		    printf("Essa op��o n�o est� disponivel!\n");
		    break;
	    }
	}
}
