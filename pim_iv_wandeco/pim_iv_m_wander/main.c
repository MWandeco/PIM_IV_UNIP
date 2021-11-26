#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#define SIZE 200

typedef struct Pacientes
{
    char nome[SIZE],email[SIZE],cpf[SIZE],telefone[SIZE];
    int dia,mes,ano;
    char rua[SIZE],bairro[SIZE], cidade[SIZE], estado[SIZE],CEP[SIZE],numero[SIZE];
    int diaDiag,mesDiag,anoDiag;
    char comorbidades[SIZE];
} Pacientes;

int main()
{
    char login[15] = "Wandeco";
    char senha[10] = "123456";
    char recuperaLogin[15];
    char recuperaSenha[15];
    int confirmaComorbidades;
    int resultado;
    bool logado = false;

    //Caso não exista arquivo para escrever os dados dos pacientes ele cria um
    FILE *pointerPacientes = fopen("pacientes.txt", "a");
    if(pointerPacientes == NULL)
    {
        pointerPacientes = fopen("pacientes.txt", "w");
    }
    //salva dados de pacientes e grupo de risco
    FILE *enviarDadosGoverno = fopen("grupoDeRisco.txt", "a");
    if(enviarDadosGoverno == NULL)
    {
        enviarDadosGoverno = fopen("grupoDeRisco.txt", "w");
    }

    printf("=======================================================================\n");
    printf("  Cadastrar paciente no sistema, digite seu LOGIN e sua SENHA. \n");
    printf("=======================================================================\n");
    printf("LOGIN : ");
    gets(recuperaLogin);
    if(strcmp(login,recuperaLogin) == 0)
    {
        printf("SENHA : ");
        gets(recuperaSenha);
        if(strcmp(senha,recuperaSenha) == 0 )
        {
            logado = true;
        }
        else
        {
            printf("Senha Incorreta!!");
        }
    }
    else
    {
        printf("Login Incorreto!!");
    }
    //incializa a estrutura "Pacientes"
    Pacientes p1 = {};

    if(logado == true)
    {
        FILE *pointerPacientes;
        pointerPacientes = fopen("pacientes.txt", "a");


        printf("\n=======================================================================\n");
        printf("  Bem vindo Doutor. Informe os dados do paciente. \n");
        printf("=======================================================================\n");
        printf("NOME : ");
        scanf(" %30[^\n]s",&p1.nome);
        //printf(p1.nome);

        printf("\nEMAIL : ");
        scanf(" %30[^\n]s",p1.email);
        //printf(p1.email);

        printf("\nCPF : ");
        scanf(" %30[^\n]s",&p1.cpf);
        //printf(p1.cpf);

        printf("\nTELEFONE : ");
        scanf(" %30[^\n]s",&p1.telefone);
        //printf(p1.telefone);


        printf("\n=======================================================================\n");
        printf("  Informe o local onde o paciente mora.\n");
        printf("=======================================================================\n");

        printf("RUA : ");
        scanf(" %30[^\n]s",&p1.rua);
        //printf(p1.rua);

        printf("\nNUMERO : ");
        scanf(" %30[^\n]s",&p1.numero);
        //printf(p1.numero);

        printf("\nBAIRRO : ");
        scanf(" %30[^\n]s",&p1.bairro);
        //printf(p1.bairro);

        printf("\nCIDADE : ");
        scanf(" %30[^\n]s",&p1.cidade);
        //printf(p1.cidade);

        printf("\nESTADO : ");
        scanf(" %30[^\n]s",&p1.estado);
        //printf(p1.estado);

        printf("\nCEP : ");
        scanf(" %30[^\n]s",&p1.CEP);
        //printf(p1.CEP);

        printf("\n=======================================================================\n");
        printf("  Data do diagnóstico e data de aniversário do paciente.\n");
        printf("=======================================================================\n");

        printf("DIA DO DIAGNOSTICO : ");
        fflush(stdin);
        scanf("%d",&p1.diaDiag);
        //printf("%d",p1.diaDiag);

        printf("\nMÊS DO DIAGNOSTICO (Exemplo : XX) : ");
        fflush(stdin);
        scanf("%d",&p1.mesDiag);
        //printf("%d",p1.mesDiag);

        printf("\nANO DO DIAGNOSTICO (Exemplo : XXXX): ");
        fflush(stdin);
        scanf("%d",&p1.anoDiag);
        //printf("%d",p1.anoDiag);

        printf("\nDIA DE NASCIMENTO : ");
        fflush(stdin);
        scanf("%d",&p1.dia);
        //printf("%d",p1.dia);

        printf("\nMÊS DE NASCIMENTO (XX) : ");
        fflush(stdin);
        scanf("%d",&p1.mes);
        //printf("%d",p1.mes);

        printf("\nANO DE NASCIMENTO  (XXXX): ");
        fflush(stdin);
        scanf("%d",&p1.ano);
        //printf("%d",p1.ano);


        printf("\n=======================================================================\n");
        printf("  Paciente possui alguma comorbidade?\n");
        printf("1.Sim / 2.Nao .\n");
        fflush(stdin);
        scanf("%d",&confirmaComorbidades);

        resultado = calcularIdade(p1.anoDiag,p1.ano);

        if(confirmaComorbidades == 1)
        {
            printf("Quais?\n");
            scanf(" %30[^\n]s",p1.comorbidades);
            //printf("%s",p1.comorbidades); ---> serve apenas para ver se funciona
            fprintf(enviarDadosGoverno,"{\n CEP : %s\n",p1.CEP);
            fprintf(enviarDadosGoverno,"idade : %d\n}",resultado);
            fclose(enviarDadosGoverno);

        }else if(resultado >= 65){
            fprintf(enviarDadosGoverno,"{\n CEP : %s\n",p1.CEP);
            fprintf(enviarDadosGoverno,"idade : %d\n}",resultado);
            fclose(enviarDadosGoverno);
        }

        printf("\n\n Salvando dados do paciente...");

        fprintf(pointerPacientes,"{\nnome : %s\n",p1.nome);
        fprintf(pointerPacientes,"email : %s\n",p1.email);
        fprintf(pointerPacientes,"CPF : %s\n",p1.cpf);
        fprintf(pointerPacientes,"telefone : %s\n",p1.telefone);
        fprintf(pointerPacientes,"rua : %s\n",p1.rua);
        fprintf(pointerPacientes,"numero : %s\n",p1.numero);
        fprintf(pointerPacientes,"estado : %s\n",p1.estado);
        fprintf(pointerPacientes,"bairro : %s\n",p1.bairro);
        fprintf(pointerPacientes,"CEP : %s\n",p1.CEP);
        fprintf(pointerPacientes,"dataNascimento : %d/%d/%d\n",p1.dia,p1.mes,p1.ano);
        fprintf(pointerPacientes,"dataDiagnostico : %d/%d/%d\n",p1.diaDiag,p1.mesDiag,p1.anoDiag);
        fprintf(pointerPacientes,"comorbidades : %s\n}\n",p1.comorbidades);
        fclose(pointerPacientes);

        printf("\n\n Dados salvos com sucesso!\n\n");


    }

    return 0;

}

// calcula idade do paciente
int calcularIdade(int anoDiagnostico,int anoAnivesrsario )
{
    int resultado = anoDiagnostico-anoAnivesrsario;
    return resultado;
}

