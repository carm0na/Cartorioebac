#include <stdio.h> //biblioteca de comunicacao com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por regiao
#include <string.h> //biblioteca responsável por cuidar de strings

void registro(void)
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Você escolheu o registro de nomes!\n");
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); //cria o arquivo, w de write
    fprintf(file,"%s", cpf); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //a de atualizar
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,"%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,"%s", sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,"%s", cargo);
    fclose(file);

     
}

// não tem ponto e virgula entre as funções, apenas quando chama

void consulta(void)
{
    
    printf("Você escolheu consultar nomes!\n");
    setlocale(LC_ALL, "Portuguese");
    
    char cpf [40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("Arquivo não localizado.\n");
        return;
    }
    
    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
}

void deletar(void)
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema!.\n");
    }else
    {
        remove(cpf);
        printf("Usuário deletado!.\n");
    }
}
//MENU com switch para escolher opção
int main(void){
    
    int opcao=0;
    int laco=1;
    
    for (laco=1; laco==1;)
    {
        system("clear");
        
        setlocale(LC_ALL, "Portuguese");
        
        printf("\n### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: ");
        
        scanf("%d", &opcao);
        
        system("clear"); //equivalente ao system cls no windows
        
        switch (opcao) {
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
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
                break;
                
            default:
                printf("Opção invalida\n\n");
                break;
        }
    }
}
