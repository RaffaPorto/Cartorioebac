#include <stdio.h>// biblioteca de comunicação com o usuario
#include <stdlib.h>// biblioteca de alocação de espaço em memória
#include <locale.h>// biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuudar dos string

    int registro() // Função responsável por cadastrar os usuários no sistema
    {
    // Inicio da criação de variáveis/string
        char arquivo[40];
		char cpf[40];
    	char nome[40];
    	char sobrenome[40];
    	char cargo[40];
    //Final da criação de variáveis/string
    	
    	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
    	scanf("%s", cpf); // %s refere-se a string
    	
    	strcpy(arquivo, cpf); // Rresponsável por copiar os valores das string
    	
    	FILE *file; // cria o arquivo 
    	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    	fprintf(file,cpf); //salvo o valor da variável
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
		
		// Inicio da criação de variáveis/string
	    char cpf[40];
	    char conteudo[200];
	    // Final da criação de variáveis/string
	    
	    printf("Digite o CPF a ser consultado: "); // Coletando informação do usuário
	    scanf("%s",cpf); //%s refere-se a string
	    
	    FILE *file;
	    file = fopen(cpf,"r");
	    
	    if(file == NULL)
	    {
	    	printf("Não foi possivel abrir o arquivo, não localizado!\n");
	    }
	    
	    while(fgets(conteudo, 200, file) != NULL)
	    {
	    	printf("\nEssas são as informaçõoes do usuário: ");
	    	printf("%s", conteudo);
	    	printf("\n\n");
	    }
	    
	    system("pause");
	
	
	}

    int deletar()
    {
    	// Inicio da criação de variáveis/string
    	 char cpf[40];
    	//Final da criação de variáveis/string
    	 
    	 printf("Digite o CPF do usuário a ser deletado: "); // Coletando informação do usuário
    	 scanf("%s",cpf); // %s refere-se a string
    	 
    	 remove(cpf);
    	 
    	 FILE *file;
    	 file = fopen(cpf, "r");
    	 
    	if(file == NULL) 
    	{
    		printf("O usuário não se encontra no sistema!\n");
    		system("pause");
    		}
    	 
    }
	
	
	
	
    int main()
    {
    int opcao=0; // Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("###Cartório da EBAC###\n\n" ); //Inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Escolha os nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Opção:");  //Fim do menu

    scanf("%d", &opcao); // Armazenando a escolha do usuário    

    system("cls"); //Responsável por limpar a tela
    
    
    switch(opcao) // Inicio da seleção do menu
     {
       case 1:
       registro(); //chamada de funções
       break;
       
       case 2:
       consulta();
       break;
       
       case 3:
       deletar();
       break;	
     
       default:
       printf("Essa opção não está disponivel!");
       system("pause");
        break;
     
        }
	
   }
}



