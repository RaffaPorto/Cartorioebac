#include <stdio.h>// biblioteca de comunica��o com o usuario
#include <stdlib.h>// biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>// biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuudar dos string

    int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
    {
    // Inicio da cria��o de vari�veis/string
        char arquivo[40];
		char cpf[40];
    	char nome[40];
    	char sobrenome[40];
    	char cargo[40];
    //Final da cria��o de vari�veis/string
    	
    	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
    	scanf("%s", cpf); // %s refere-se a string
    	
    	strcpy(arquivo, cpf); // Rrespons�vel por copiar os valores das string
    	
    	FILE *file; // cria o arquivo 
    	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    	fprintf(file,cpf); //salvo o valor da vari�vel
    	fclose(file); //fecha o arquivo
    	
    	file = fopen(arquivo, "a");
    	fprintf(file,",");
    	fclose(file);
    	
    	printf("Digite o nome a ser cadastrado: ");
    	scanf("%s", nome);
    	
    	file = fopen(arquivo, "a");
	    fprintf(file,nome);
	    fclose(file);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,",");
	    fclose(file);
	    
	    printf("Digite o sobrenome a ser cadastrado: ");
	    scanf("%s", sobrenome);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file, sobrenome);
	    fclose(file);
	    
	    file = fopen(arquivo, "a");
    	fprintf(file,",");
    	fclose(file);
    	
    	printf("Digite o cargo a ser cadastrado: ");
    	scanf("%s",cargo);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,cargo);
	    fclose(file);
	    
	    system("pause"); 
	    
	    }
	
	int consulta()
	{
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		// Inicio da cria��o de vari�veis/string
	    char cpf[40];
	    char conteudo[200];
	    // Final da cria��o de vari�veis/string
	    
	    printf("Digite o CPF a ser consultado: "); // Coletando informa��o do usu�rio
	    scanf("%s",cpf); //%s refere-se a string
	    
	    FILE *file;
	    file = fopen(cpf,"r");
	    
	    if(file == NULL)
	    {
	    	printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	    }
	    
	    while(fgets(conteudo, 200, file) != NULL)
	    {
	    	printf("\nEssas s�o as informa��oes do usu�rio: ");
	    	printf("%s", conteudo);
	    	printf("\n\n");
	    }
	    
	    system("pause");
	
	
	}

    int deletar()
    {
    	// Inicio da cria��o de vari�veis/string
    	 char cpf[40];
    	//Final da cria��o de vari�veis/string
    	 
    	 printf("Digite o CPF do usu�rio a ser deletado: "); // Coletando informa��o do usu�rio
    	 scanf("%s",cpf); // %s refere-se a string
    	 
    	 remove(cpf);
    	 
    	 FILE *file;
    	 file = fopen(cpf, "r");
    	 
    	if(file == NULL) 
    	{
    		printf("O usu�rio n�o se encontra no sistema!\n");
    		system("pause");
    		}
    	 
    }
	
	
	
	
    int main()
    {
    int opcao=0; // Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("###Cart�rio da EBAC###\n\n" ); //Inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Escolha os nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o:");  //Fim do menu

    scanf("%d", &opcao); // Armazenando a escolha do usu�rio    

    system("cls"); //Respons�vel por limpar a tela
    
    
    switch(opcao) // Inicio da sele��o do menu
     {
       case 1:
       registro(); //chamada de fun��es
       break;
       
       case 2:
       consulta();
       break;
       
       case 3:
       deletar();
       break;	
       
       case 4:
       printf("Obrigado por ultilizar o sistema!\n");
       return 0;
	   break;	
     
       default:
       printf("Essa op��o n�o est� disponivel!");
       system("pause");
       break;
     
        }
	
   }
}



