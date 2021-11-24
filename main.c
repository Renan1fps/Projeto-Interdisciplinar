#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int comparaStrings(char nomeUm[], char nomeDois[]){
    int i = 0;
    while(nomeUm[i] == nomeDois[i] && nomeUm[i] != '\0' && nomeDois[i]  != '\0'){
        i++;
    }
    if(nomeUm[i]== '\0' && nomeDois[i]== '\0'){
        return 1;
    }else{
        return 0;
    }
}

 struct empregado{

    char nome[50];
    int idade;
    char cpf[16];
    char endereco[100];
    float salario;
    char cargo[40];

}Empregado[100];

void printfuncionario(struct empregado a){
    printf("\nNome : %s", a.nome);
    printf("\nSalário: %.1f", a.salario);
}


int main()
{
    Empregado[MAX];
    const int TAMANHOARRAY = 40;
    bool condicao = true;
    int valor, sair;
    int N = 0;
    char buscaalunopornome[50];

    while(condicao){
        printf("\n\nDigite o número de uma das opções abaixo ");
        printf("\n1-Cadastrar novo empregado ");
        printf("\n2-Listar todos os empregados cadastrados ");
        printf("\n3-Buscar empregado por nome");
        printf("\n4-Cadastrar venda de um funcionário");
        printf("\n5-Alterar algum dado do cadastro de um funcionario");
        printf("\n6-Fazer o fechamento mensal");
        printf("\n7-Sair\n");
        scanf("%d", &valor);

        switch(valor){

            case 1: //cadastro de funcionários
            {
                 printf("\n\t\tCadastro\n");

                if(N == MAX){
                    printf("\nLimite de armazenamento atingido!\n");
                }
                else{
                    printf("\nCodigo de cadastro do funcionario = %d\n", N);
                    printf("\nDigite o nome do funcionario: ");
                    setbuf(stdin, NULL);
                    scanf("%49[^\n]", Empregado[N].nome);

                    printf("\nDigite a idade do funcionario: ");
                    scanf("%d", &Empregado[N].idade);

                    printf("\nDigite o cpf do funcionario: ");
                    setbuf(stdin, NULL);
                    scanf("%15[^\n]", &Empregado[N].cpf);

                    printf("\nDigite o endereco do funcionario: ");
                    setbuf(stdin, NULL);
                    scanf("%99[^\n]", &Empregado[N].endereco);

                    printf("\nDigite ao salario do funcionario: ");
                    scanf("%f", &Empregado[N].salario);

                    printf("\nDigite o cargo do funcionario: ");
                    setbuf(stdin, NULL);
                    scanf("%39[^\n]", &Empregado[N].cargo);


                    N++;

                    do{
                        printf("\nPressione 0 para sair: ");
                        scanf("%d",&sair);
                    }while(sair!=0);
                }
                break;
            }

            case 2: {
                printf("\t\tListagem dos empregados cadastrados:\n");

                for(int i=0; i<N; i++){
                    printf("\n- Codigo funcionario: %d.\n- Nome: %s\n",i,Empregado[i].nome);
                }
                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);

                break;
            }

            case 3: {
                setbuf(stdin, NULL);
                printf("\nDigite o nome do funcionario que gostaria de buscar:");
                scanf("%[^\n]", buscaalunopornome);
                for(int i =0; i < N;i++){
                    if(comparaStrings(Empregado[i].nome, buscaalunopornome) == 1){
                        printfuncionario(Empregado[i]);
                    }
                }
                break;
            }
            case 4: {

                printf("\nCase 4");
                break;
            }
            case 5: {

                printf("\nCase 5");
                break;
            }
            case 6: {

                printf("\nCase 6");
                break;
            }
            case 7: {

                printf("\nCase 7");
                condicao = false;
                break;
            }

    }
    }

    return 0;
}

