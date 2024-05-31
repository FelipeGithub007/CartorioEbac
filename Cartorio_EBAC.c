#include <stdio.h> //biblioteca de comiunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
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
	
	printf("digite o cpf a ser registrado: "); //coletando informação do usuario 
	scanf("%s", cpf); //%s se refere as string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo "w" significa escrever
	fprintf(file,cpf); //salvo o valor da veriavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("digite o nome a ser cadastrado: ");//coletando informação do usuario 
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file, nome);
	fclose(file);//fecha o arquivo	
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("digite o sobrenome a ser cadastrado: ");//coletando informação do usuario 
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,sobrenome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");// atualizando o arquivo "a" significa escrever
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("digite o cargo a ser cadastrado: ");//coletando informação do usuario 
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
	printf("digite o cfp a ser consultado: ");//coletando informação do usuario 
	scanf("%s", cpf);//%s se refere as string
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	 while(fgets(conteudo, 200, file) != NULL) 
	 {
	 	printf("\nEssas são as informações do usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	system("pause");	
}

int deletar()
{
	 char cpf[40];
	 
	 setlocale(LC_ALL, "portuguese");
	 
	 printf("Digite o cpf do usuário a ser deletado: ");//coletando informação do usuario 
	 scanf("%s", cpf);
	 
	 remove(cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r");
	 
	 if(file == NULL)
	 {
	 	printf("\nO usuário não se encontra no sistema!\n\n");	
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


	    printf("### Cartório da EBAC ###\n\n"); //Iniciando o menu
  	    printf("escolha a opção desejada no menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n");
	    printf("\t4 - sair do programa\n");
	    printf("Opção: ");//Fim do menu
	
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
		    printf("Essa opção não está disponivel!\n");
		    break;
	    }
	}
}
