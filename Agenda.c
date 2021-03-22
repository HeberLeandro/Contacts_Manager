#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//estrutura para agenda 
struct agenda
{
	char nome[13];
	char sobrenome[13];
	char endereco[50];
	char email[40];
	char fone[13];
};


int posicao = 0, retornoMain;

struct agenda registro[150];
FILE *fp;
// protótipos visual do menu
void chamaMenu();

//Protótipos das funções do menu
char Inserir();
char Listar();
void Pesquisar();
char Editar();
void Excluir();
int Sair();

//protótipos das funções de pesquisa
void pesquisaNome();
void pesquisaSobrenome();
void pesquisaEndereco();
void pesquisaEmail();
void pesquisaTelefone();

void Menu(void) 
{
	system("cls");
	fflush(stdin);
	
	int menu;
	
	chamaMenu();
	fflush(stdin);

	printf("Escolha a opção: \n");
	printf("(para salvar suas alterações, saía usando a opção 'Sair', no Menu)\n\n");
	printf("|-------------|------------|---------------|\n");
	printf("|  1.Inserir  |  2.Listar  |  3.Pesquisar  |\n");
	printf("|-------------|------------|---------------|\n");
	printf("|  4.Editar   |  5.Excluir |  6.Sair       |\n");
	printf("|-------------|------------|---------------|\n");
	scanf("%d",&menu);
	fflush(stdin);
	//switch para selecionar as opções do menu principal
	switch(menu)
	{
		case 1:	
			Inserir();
			break;

		case 2:
			Listar();
			break;

		case 3:
			Pesquisar();
			break;		

		case 4:
			Editar();
			break;		

		case 5:
			Excluir();
			break;		

		case 6:
			Sair();
			break;			

		default:
			printf("Opção Invalida!\n");
			break;			
	}		
}

int main(void)
{
	//Pegando os dados do Arquivo
	fp = fopen("agenda.txt", "r");

  	while( (fscanf(fp,"%13s %13s %50s %40s %13s\n", registro[posicao].nome, registro[posicao].sobrenome, registro[posicao].endereco, registro[posicao].email, registro[posicao].fone))!=EOF)
	{
  		posicao++; 
	}
  	fclose (fp);
	//acrescenando acentos e caracteres especiais no programa
	setlocale(LC_ALL, "Portuguese");
	Menu();	
	return 0;
}

//Escopo para função que chama o letreiro do menu
void chamaMenu()
{
	printf("\n\n");
	printf("\t*******************************************\n");
	printf("\t*     **        ** *****  **    * *     * *\n");
	printf("\t*    * *      * * *      * *   * *     *  *\n");
	printf("\t*   *  *    *  * ****   *  *  * *     *   *\n");
	printf("\t*  *   *  *   * *      *   * * *     *    *\n");
	printf("\t* *    **    * *****  *    ** *******     *\n");
	printf("\t*******************************************\n\n");
}

//Corpo das principais funções do menu
char Inserir()
{
	int escolha1; 

	if(posicao < 150)
	{
		do
		{
			//incerssão dos dados do contato na agenda			
			fflush(stdin);
			system("cls");
			printf("\n \tInserir \n \n");
	
			printf("Digite o Primeiro Nome: \n");
			gets(registro[posicao].nome);
			fflush(stdin);
					
			printf("\nDigete o Sobrenome: \n");
			gets(registro[posicao].sobrenome);
			fflush(stdin);
					
			printf("\nDigite o Endereço: \n");
			gets(registro[posicao].endereco);
			fflush(stdin);
					
			printf("\nDigite o Email: \n");
			gets(registro[posicao].email);
			fflush(stdin);
					
			printf("\nDigite o Telefone ([ddd] 9xxxx-xxxx): \n");
			gets(registro[posicao].fone);
			fflush(stdin);
											
			printf("\nDeseja Adicionar outro Contato?(digite sim = 1 ou não = 0)\n");
			scanf("%d",&escolha1);
				
			posicao++;					
		}

		while(posicao < 150 && escolha1 == 1 );
		{			
			printf("\n\nVoltando Para o Menu...\n\n");
			system("PAUSE");				
			Menu();
		}
	}
	
	else
	{
		//caso a a genda esteja cheia...
		system("cls");
		printf("\nA Agenda está Cheia! Você Será Redirecionado para o Menu!\n \n");
		system("PAUSE");
		Menu();	
				
	}			
}

char Listar()
{
	fflush(stdin);
	system("cls");
	printf("\n \tListar \n \n");
			
	int i;

	if(posicao > 0)
	{
			
		for(i=0;i<posicao;i++) 
		{		
			printf("\n|--------------------------------------------|\n");
			printf("\n|CONTATO %d: \n",(i+1));
			printf("\n|Nome ..: %s",   registro[i].nome);
			printf("\n|Sobrenome ..: %s",   registro[i].sobrenome);
			printf("\n|Endereço ..: %s",   registro[i].endereco);
		   	printf("\n|E-mail ..: %s",   registro[i].email); 
			printf("\n|Fone ..: %s\n",   registro[i].fone);
			printf("  |--------------------------------------------|\n");	
		}
			      
		printf(" \n\n %d Contatos salvos!\n", i);
			    
		printf("\nVocê irá retornar para o Menu, ");
	    system("PAUSE");
       	Menu();
	}

	else
	{
		printf("Sem Contatos Salvos\n");
		printf("\nVocê irá retornar para o Menu, ");
	    system("PAUSE");
    	Menu();
	}
}

void Pesquisar()
{
	int pesquisa;
	fflush(stdin);
	system("cls");
	printf("PESQUISAR");
	//menu para escolher por qual dado a pessoa deseja pesquisar o contato
	printf("\n\n Deseja pesquisar por: \n\n");
	printf("|--------------------------|\n");
	printf("| 1.NOME     | 2.SOBRENOME |\n");
	printf("| 3.ENDEREÇO | 4.EMAIL     |\n");
	printf("| 5.TELEFONE | 6.VOLTAR    |\n");
	printf("|--------------------------|\n");
	scanf("%d", &pesquisa);
	fflush(stdin);
	//switch para a seleção de qual dado a pessoa deseja pesquisar 
	switch(pesquisa)
	{
		case 1:
			pesquisaNome();
			break;

		case 2:
			pesquisaSobrenome();
			break;

		case 3:
			pesquisaEndereco();
			break;

		case 4:
			pesquisaEmail();
			break;

		case 5:
			pesquisaTelefone();
			break;

		case 6:
			Menu();
			break;

		default:
			printf("Opção Inválida!\n");
			system("PAUSE");
			Pesquisar();
			break;
	}
}
// escopo das funções de pesquisa ...
void pesquisaNome()
{
	fflush(stdin);
	system("cls");
	printf("\n \tPesquisa por Nome \n \n");

    int i = 0, achei = 0;
    char nome[13];

	printf ("Digite o nome: \n");
    gets(nome);
	fflush(stdin);
	
	for(i=0; i<posicao; i++)
	{
    	if (strcmp(registro[i].nome, nome)==0)
		{
			
			printf("\n|--------------------------------------------|\n");
			printf("\n|CONTATO %d: \n",(i+1));
			printf("\n|Nome ..: %s", registro[i].nome);
			printf("\n|Sobrenome ..: %s", registro[i].sobrenome);
			printf("\n|Endereço ..: %s", registro[i].endereco);
		   	printf("\n|E-mail ..: %s", registro[i].email); 
			printf("\n|Fone ..: %s\n", registro[i].fone);
			printf("|--------------------------------------------|\n");	   		
			achei = 1;    		
		}
	}
	
    if(achei == 0)
    {
    	printf("Não há Contatos com esse Nome !\n");
    	printf("\nVocê irá retornar para o SubMenu, Pesquisar, ");
    	system("PAUSE");
    	Pesquisar();
	}
	
    system("PAUSE");
    Menu(); 	
}

void pesquisaSobrenome()
{
	fflush(stdin);
	system("cls");
	printf("\n \tPesquisa por SobreNome \n \n");

    int i = 0, achei = 0;
    char sobrenome[13];

	printf ("Digite o SobreNome: \n");
    gets(sobrenome);
	fflush(stdin);
	
	for(i=0; i<posicao; i++)
	{
    	if (strcmp(registro[i].sobrenome, sobrenome)==0)
		{
			//printf ("\nNome ..: %s\nSobrenome ..:%s\nEndereço ..:%s\nE-mail ..: %s\nFone ..: %s\n\n", registro[i].nome, registro[i].sobrenome, registro[i].endereco, registro[i].email, registro[i].fone);    		
			printf("\n|--------------------------------------------|\n");
			printf("\n|CONTATO %d: \n",(i+1));
			printf("\n|Nome ..: %s", registro[i].nome);
			printf("\n|Sobrenome ..: %s", registro[i].sobrenome);
			printf("\n|Endereço ..: %s", registro[i].endereco);
		   	printf("\n|E-mail ..: %s", registro[i].email); 
			printf("\n|Fone ..: %s\n", registro[i].fone);
			printf("|--------------------------------------------|\n");
			achei = 1;    		
		}
	}
	
    if(achei == 0)
    {
    	printf("Não há Contatos com esse SobreNome !\n");
    	printf("\nVocê irá retornar para o SubMenu, Pesquisar, ");
    	system("PAUSE");
    	Pesquisar();
	}
	
    system("PAUSE");
    Menu();
}

void pesquisaEndereco()
{
	fflush(stdin);
	system("cls");
	printf("\n \tPesquisa por Endereço \n \n");

    int i = 0, achei = 0;
    char endereco[50];

	printf ("Digite o Endereço: \n");
    gets(endereco);
	fflush(stdin);
	
	for(i=0; i<posicao; i++)
	{
    	if (strcmp(registro[i].endereco, endereco)==0)
		{
			//printf ("\nNome ..: %s\nSobrenome ..:%s\nEndereço ..:%s\nE-mail ..: %s\nFone ..: %s\n\n", registro[i].nome, registro[i].sobrenome, registro[i].endereco, registro[i].email, registro[i].fone);    		
			printf("\n|--------------------------------------------|\n");
			printf("\n|CONTATO %d: \n",(i+1));
			printf("\n|Nome ..: %s", registro[i].nome);
			printf("\n|Sobrenome ..: %s", registro[i].sobrenome);
			printf("\n|Endereço ..: %s", registro[i].endereco);
		   	printf("\n|E-mail ..: %s", registro[i].email); 
			printf("\n|Fone ..: %s\n", registro[i].fone);
			printf("|--------------------------------------------|\n");
			achei = 1;    		
		}
	}
	
    if(achei == 0)
    {
    	printf("Não há Contatos com esse Endereço !\n");
    	printf("\nVocê irá retornar para o SubMenu, Pesquisar, ");
    	system("PAUSE");
    	Pesquisar();
	}
	
    system("PAUSE");
    Menu();
}

void pesquisaEmail()
{
	fflush(stdin);
	system("cls");
	printf("\n \tPesquisa por Email \n \n");

    int i = 0, achei = 0;
    char email[40];

	printf ("Digite o Email: \n");
    gets(email);
	fflush(stdin);
	
	for(i=0; i<posicao; i++)
	{
    	if (strcmp(registro[i].email, email)==0)
		{
			//printf ("\nNome ..: %s\nSobrenome ..:%s\nEndereço ..:%s\nE-mail ..: %s\nFone ..: %s\n\n", registro[i].nome, registro[i].sobrenome, registro[i].endereco, registro[i].email, registro[i].fone);    		
			printf("\n|--------------------------------------------|\n");
			printf("\n|CONTATO %d: \n",(i+1));
			printf("\n|Nome ..: %s", registro[i].nome);
			printf("\n|Sobrenome ..: %s", registro[i].sobrenome);
			printf("\n|Endereço ..: %s", registro[i].endereco);
		   	printf("\n|E-mail ..: %s", registro[i].email); 
			printf("\n|Fone ..: %s\n", registro[i].fone);
			printf("|--------------------------------------------|\n");
			achei = 1;    		
		}
	}
	
    if(achei == 0)
    {
    	printf("Não há Contatos com esse Email !\n");
    	printf("\nVocê irá retornar para o SubMenu, Pesquisar, ");
    	system("PAUSE");
    	Pesquisar();
	}
	
    system("PAUSE");
    Menu();	
}

void pesquisaTelefone()
{
	fflush(stdin);
	system("cls");
	printf("\n \tPesquisa por Telefone \n \n");

    int i = 0, achei = 0;
    char fone[13];

	printf ("Digite o Telefone: \n");
    gets(fone);
	fflush(stdin);
	
	for(i=0; i<posicao; i++)
	{
    	if (strcmp(registro[i].fone, fone)==0)
		{
			//printf ("\nNome ..: %s\nSobrenome ..:%s\nEndereço ..:%s\nE-mail ..: %s\nFone ..: %s\n\n", registro[i].nome, registro[i].sobrenome, registro[i].endereco, registro[i].email, registro[i].fone);    		
			printf("\n|--------------------------------------------|\n");
			printf("\n|CONTATO %d: \n",(i+1));
			printf("\n|Nome ..: %s", registro[i].nome);
			printf("\n|Sobrenome ..: %s", registro[i].sobrenome);
			printf("\n|Endereço ..: %s", registro[i].endereco);
		   	printf("\n|E-mail ..: %s", registro[i].email); 
			printf("\n|Fone ..: %s\n", registro[i].fone);
			printf("|--------------------------------------------|\n");
			achei = 1;    		
		}
	}
	
    if(achei == 0)
    {
    	printf("Não há Contatos com esse Telefone !\n");
    	printf("\nVocê irá retornar para o SubMenu, Pesquisar, ");
    	system("PAUSE");
    	Pesquisar();
	}
	
    system("PAUSE");
    Menu();
}
//até aqui

char Editar()
{
	int edit;

	fflush(stdin);
	system("cls");
	printf("\n \tEditar \n \n");
	printf("Digite o Número, na lista, do contato que você deseja Editar: \n");
	scanf("%d",&edit);		
	fflush(stdin);
	
	printf("\nEditando o Contado %d, %s \n\n",edit,registro[(edit-1)].nome);

	printf("Digite o Primeiro Nome: \n");
	gets(registro[(edit-1)].nome);
	fflush(stdin);
			
	printf("\nDigete o Sobrenome: \n");
	gets(registro[(edit-1)].sobrenome);
	fflush(stdin);
	
	printf("\nDigite o Endereço: \n");
	gets(registro[(edit-1)].endereco);
	fflush(stdin);
				
	printf("\nDigite o Email: \n");
	gets(registro[(edit-1)].email);
	fflush(stdin);
					
	printf("\nDigite o Telefone ([ddd] 9xxxx-xxxx): \n");
	gets(registro[(edit-1)].fone);
	fflush(stdin);
	
	printf(" \nContado Editado! \n\n");
	system("PAUSE");
	Menu();
}

void Excluir()
{
	system("cls");
	fflush(stdin);
	
	char nome[13];
    int j,i,achei = 0;
    
    printf("Insira o Nome do Contato que deseja Excluir: \n");
    scanf("%s",&nome);
	fflush(stdin);
	
    for(i=0; i<posicao; i++)
	{
    	if (strcmp(registro[i].nome, nome)==0)
		{
            for(j=i+1; j<posicao; j++)
			{
                strcpy(registro[j-1].nome,registro[j].nome);
                strcpy(registro[j-1].sobrenome,registro[j].sobrenome);
                strcpy(registro[j-1].endereco,registro[j].endereco);
                strcpy(registro[j-1].email,registro[j].email);
                strcpy(registro[j-1].fone,registro[j].fone);
            } 
            posicao--;
            i=posicao;
            achei = 1;
        }
    }
    
    if(achei == 0)
    {
    	printf("\nContato não encontrado!\n");
    	printf("Você irá retornar para o Menu, ");
    	system("PAUSE");
    	Menu();
	}
    printf("\nContato Apagado!\nVocê irá retornar para o Menu, ");
    
    system("PAUSE");
    Menu();	
}

int Sair()
{
	int escolha6, save, retorno;
	system("cls");
	fflush(stdin);
		
	printf("\n\t\t SAIR! \n \n");
	printf(" VOCÊ REALMENTE DESEJA SAIR?(digite sim = 1 ou não = 0) \n\n");
	scanf("%d",&escolha6);
	fflush(stdin);
	//condicional para sair e salvar os dados da memória para um arquivo		
	if(escolha6 == 1)
	{
		if ((fp = fopen("agenda.txt", "w")) == NULL)
		{
        	printf ("O arquivo Não pode ser Salvo!\n");
        	printf ("Insira dados!\n");
        	system("PAUSE");
       		Menu();        		
     	}
		
		for(save = 0; save < posicao; save++)
		{
			fwrite (registro[save].nome, sizeof(struct agenda) ,1,fp);			
		}
		
		fclose (fp);
		fflush(stdin);
        
		printf(" \nContatos Salvos ! ");
		printf("\nPrograma Encerrado ! \n");		
	}
	else if(escolha6 == 0)
	{			
		Menu();
	}
	else
	{			
		printf("\nOpção Invalida! Você será Redirecionado para o Menu!\n\n");
		system("PAUSE");
		Menu();					
	}
}