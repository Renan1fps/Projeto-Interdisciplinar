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
    int vendas[100];

}Empregado[100];

void printfuncionario(struct empregado a){
    printf("\nNome : %s", a.nome);
    printf("\nIdade: %d", a.idade);
    printf("\nCPF: %s", a.cpf);
    printf("\nSalario: %s", a.salario);
    printf("\nCargo: %s", a.cargo);
}


int main()
{
    Empregado[MAX];
    const int TAMANHOARRAY = 40;
    bool condicao = true;
    int valor, sair, escolha;
    int N = 0;
    char buscafuncpornome[50];
    int contaVenda = 0;
    int valorVenda = 0;
    float venda;


    while(condicao){

        system("cls");
        printf("\n\nDigite o número de uma das opções abaixo. ");
        printf("\n1-Cadastrar novo empregado. ");
        printf("\n2-Listar todos os empregados cadastrados. ");
        printf("\n3-Buscar empregado por nome.");
        printf("\n4-Cadastrar venda de um funcionário.");
        printf("\n5-Alterar algum dado do cadastro de um funcionario.");
        printf("\n6-Fazer o fechamento mensal.");
        printf("\n7-Sair.\n");
        printf(" Escolha : ");
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
                    printfuncionario(Empregado[i]);
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
                scanf("%[^\n]", buscafuncpornome);
                for(int i =0; i < N;i++){
                    if(comparaStrings(Empregado[i].nome, buscafuncpornome) == 1){
                        printfuncionario(Empregado[i]);
                    }
                }
                break;
            }
            case 4: {
                setbuf(stdin, NULL);
                printf("\nDigite o nome do funcionário: ");
                scanf("%[^\n]", buscafuncpornome);
                for(int i =0; i < N;i++){
                    if(comparaStrings(Empregado[i].nome, buscafuncpornome) == 1){
                        setbuf(stdin, NULL);
                        printf("\nDigite o valor da venda do funcionario: ");
                        scanf("%d", &venda);
                        Empregado[i].vendas[valorVenda] = venda;
                        valorVenda++;
                        break;
                    }
                }
                break;
            }
            case 5: {
                setbuf(stdin, NULL);
                printf("\nDigite o nome do funcionário que gostaria de fazer alteração nos dados: ");
                scanf("%[^\n]", buscafuncpornome);
                for(int i =0; i < N;i++){
                    if(comparaStrings(Empregado[i].nome, buscafuncpornome) == 1){
                        printfuncionario(Empregado[i]);
                        printf("\n Escolha uma das opções a seguir:\n- Para alterar o nome, digite 1.\n- Para alterar a idade, digite 2.\n- Para alterar o CPF, digite 3.\n- Para alterar o endereço, digite 4.\n- Para alterar o salario, digite 5.\n\n- Para alterar o cargo, digite 6.\n  ");
                        scanf("%d", &escolha);
                        do{
                            switch(escolha){
                                case 1: {
                                    printf("\nDigite o nome alterado do funcionario: ");
                                    setbuf(stdin, NULL);
                                    scanf("%49[^\n]", Empregado[N].nome);
                                    break;
                                }
                                case 2: {
                                    printf("\nDigite a idade alterada do funcionario: ");
                                    scanf("%d", &Empregado[N].idade);
                                    break;
                                }
                                case 3: {

                                    printf("\nDigite o cpf alterado do funcionario: ");
                                    setbuf(stdin, NULL);
                                    scanf("%15[^\n]", &Empregado[N].cpf);
                                    break;
                                }
                                case 4: {

                                    printf("\nDigite o endereco alterado do funcionario: ");
                                    setbuf(stdin, NULL);
                                    scanf("%99[^\n]", &Empregado[N].endereco);
                                    break;
                                }
                                case 5: {

                                    printf("\nDigite o salario alterado do funcionario: ");
                                    scanf("%f", &Empregado[N].salario);
                                    break;
                                }
                                case 6: {

                                    printf("\nDigite o cargo alterado do funcionario: ");
                                    setbuf(stdin, NULL);
                                    scanf("%39[^\n]", &Empregado[N].cargo);
                                    break;
                                }
                            }
                        printf("\nCaso queira fazer outra aleração digite um número diferente de 0: ");
                        scanf("%d", &sair);

                        }while(sair!=0);
                    }
                break;

            }
            case 6: {

                printf("\nCase 6");
                break;
            }
            case 7: {

                printf("\nSair");
                condicao = false;
                break;
            }


    }

    return 0;
}

}
}
