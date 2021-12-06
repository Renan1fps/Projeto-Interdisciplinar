#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
#define MAX2 15

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
    int contvendas;

}Empregado[MAX];

struct cargos{
    char nome[50];
    float valor;
}Cargos[MAX2];

void printfuncionario(struct empregado a){
    printf("\nNome : %s", a.nome);
    printf("\nIdade: %d", a.idade);
    printf("\nCPF: %s", a.cpf);
    printf("\nSalario: %.2f", a.salario);
    printf("\nCargo: %s", a.cargo);
    printf("\n-----------------------------");
}

void printfuncionariofechamento(struct empregado b){
    printf("\nNome : %s", b.nome);
    printf("\nCPF: %s", b.cpf);
    printf("\nSalario: %.2f", b.salario);
    printf("\nCargo: %s.\n", b.cargo);
    printf("\nVendas -> %f", b.vendas);
}

int main()
{
    Empregado[MAX];
    bool condicao = true;
    int valor, sair, escolha;
    int i,p;
    int N = 0,M = 0;
    char buscafuncpornome[50];
    int contaVenda = 0;
    int contVenda[MAX];
    float venda, somavenda = 0, salariofinal = 0;

    for(i=0;i<MAX;i++){
        Empregado[i].contvendas = 0;
    }


    while(condicao){

        system("clear");
        printf("\n\n\n\t\tMENU\n");
        printf("\n\nDigite o número de uma das opções abaixo. ");
        printf("\n1-Cadastrar um novo cargo na empresa. ");
        printf("\n2-Cadastrar novo funcionário. ");
        printf("\n3-Listar todos os funcionários cadastrados. ");
        printf("\n4-Buscar funcionário por nome.");
        printf("\n5-Cadastrar venda de um funcionário.");
        printf("\n6-Alterar algum dado do cadastro de um funcionário.");
        printf("\n7-Fazer o fechamento mensal.");
        printf("\n8-Sair.\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &valor);
        printf("\n");

        switch(valor){

            case 1: //cadastro de um novo cargo

                printf("\t\tCadastrar um novo cargo na empresa\n");

                if(M == MAX2){
                    printf("\nLimite de armazenamento atingido!\n");
                }
                else{
                    printf("\nDigite o nome do cargo: ");
                    setbuf(stdin, NULL);
                    scanf("%49[^\n]", Cargos[M].nome);

                    printf("\nDigite a porcentagem de comissão que será aplicado ao total de vendas do funcionário neste cargo: ");
                    scanf("%f", &Cargos[M].valor);

                    M++;
                }

                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);

                break;

            case 2: //cadastro de funcion�rios

                printf("\n\t\tCadastro\n");
                if(N == MAX){
                    printf("\nLimite de armazenamento atingido!\n");
                }
                else{
                    printf("\nCodigo de cadastro do funcionário = %d\n", N);
                    printf("\nDigite o nome do funcionário: ");
                    setbuf(stdin, NULL);
                    scanf("%49[^\n]", Empregado[N].nome);

                    printf("\nDigite a idade do funcionário: ");
                    scanf("%d", &Empregado[N].idade);

                    printf("\nDigite o cpf do funcionário: ");
                    setbuf(stdin, NULL);
                    scanf("%15[^\n]", &Empregado[N].cpf);

                    printf("\nDigite o endereço do funcionário: ");
                    setbuf(stdin, NULL);
                    scanf("%99[^\n]", &Empregado[N].endereco);

                    printf("\nDigite o salário do funcionário: ");
                    scanf("%f", &Empregado[N].salario);

                    printf("\nLista de cargos cadastrados:");

                    for(i=0;i<M;i++){
                        printf("\n-Cargo %d: %s.",i, Cargos[i].nome);
                    }
                    printf("\n\n\nCaso o cargo desejado esteja na lista digite 1, ou caso queira cadastrar um novo cargo digite 2: ");
                    scanf("%d", &escolha);


                    switch(escolha){
                        case 1:
                            setbuf(stdin, NULL);
                            printf("\nDigite o nome do cargo que deseja atribuir ao funcionário: ");
                            scanf("%49[^\n]", Empregado[N].cargo);
                            break;
                        case 2:
                            if(M == MAX2){
                                printf("\nLimite de armazenamento atingido!\n");
                            }
                            else{
                                printf("\nDigite o nome do cargo: ");
                                setbuf(stdin, NULL);
                                scanf("%49[^\n]", Cargos[M].nome);

                                printf("\nDigite o juros que será aplicado ao total de vendas do funcionario neste cargo: ");
                                scanf("%f", &Cargos[M].valor);

                                M++;
                            }
                        break;

                    }
                N++;
                }
                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);

                break;


            case 3: //Listar empregados
                printf("\t\tListagem dos empregados cadastrados:\n");

                for(int i=0; i<N; i++){
                    printfuncionario(Empregado[i]);
                }
                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);

                break;


            case 4: //Buscar empregado por nome
                setbuf(stdin, NULL);
                printf("\nDigite o nome do funcionário que gostaria de buscar: ");
                scanf("%[^\n]", buscafuncpornome);
                for(int i =0; i < N;i++){
                    if(comparaStrings(Empregado[i].nome, buscafuncpornome) == 1){
                        printfuncionario(Empregado[i]);
                    }
                }
                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);
                break;

            case 5: //cadastrar vendas
                setbuf(stdin, NULL);
                printf("\nDigite o nome do funcionário: ");
                scanf("%[^\n]", buscafuncpornome);
                for(int i =0; i < N; i++){
                    if(comparaStrings(Empregado[i].nome, buscafuncpornome) == 1){
                        setbuf(stdin, NULL);
                        printf("\nDigite o valor da venda do funcionário: ");
                        scanf("%f", &venda);
                        Empregado[i].vendas[Empregado[i].contvendas] = venda;
                        Empregado[i].contvendas++;
                        break;
                    }
                }
                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);
                break;

            case 6: //ALtera��o de dados
                setbuf(stdin, NULL);
                printf("\nDigite o nome do funcionário que gostaria de fazer alteração nos dados: ");
                scanf("%[^\n]", buscafuncpornome);
                for(int i =0; i < N;i++){
                    if(comparaStrings(Empregado[i].nome, buscafuncpornome) == 1){
                        printfuncionario(Empregado[i]);
                        printf("\n");


                        do{
                            printf("\n Escolha uma das opções a seguir:\n- Para alterar o nome, digite 1.\n- Para alterar a idade, digite 2.\n- Para alterar o CPF, digite 3.\n- Para alterar o endereço, digite 4.\n- Para alterar o salario, digite 5.\n- Para alterar o cargo, digite 6.\nEscolha uma opção: ");
                            scanf("%d", &escolha);

                            switch(escolha){
                                case 1: {
                                    printf("\nDigite o nome alterado do funcionário: ");
                                    setbuf(stdin, NULL);
                                    scanf("%49[^\n]", Empregado[i].nome);
                                    break;
                                }
                                case 2: {
                                    printf("\nDigite a idade alterada do funcionário: ");
                                    scanf("%d", &Empregado[i].idade);
                                    break;
                                }
                                case 3: {

                                    printf("\nDigite o cpf alterado do funcionário: ");
                                    setbuf(stdin, NULL);
                                    scanf("%15[^\n]", &Empregado[i].cpf);
                                    break;
                                }
                                case 4: {

                                    printf("\nDigite o endereco alterado do funcionário: ");
                                    setbuf(stdin, NULL);
                                    scanf("%99[^\n]", &Empregado[i].endereco);
                                    break;
                                }
                                case 5: {

                                    printf("\nDigite o salario alterado do funcionário: ");
                                    scanf("%f", &Empregado[i].salario);
                                    break;
                                }
                                case 6: {

                                    printf("\nLista de cargos cadastrados:");
                                    for(i=0;i<M;i++){
                                    printf("\n-Cargo %d: %s.",i,Cargos[i]);
                                    }
                                    printf("\nDigite o número do cargo que deseja atribuir ao funcionário: ");
                                    scanf("%d",&p);
                                    break;
                                }
                                default:
                                    printf("Opção inválida!\n");
                                    break;
                            }
                        printf("\nCaso queira fazer outra aleração digite um número diferente de 0: ");
                        scanf("%d", &sair);

                        }while(sair!=0);
                    }
                }

                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);

                break;

            case 7: //fechamento mensal

                printf("\n\t\tFechamento mensal");
                for(int i = 0; i < N; i++){
                    for (int p = 0; p < Empregado[i].contvendas; p++){
                        somavenda = somavenda + Empregado[i].vendas[p];
                    }
                    printfuncionariofechamento(Empregado[i]);
                    float teste = 0;
                    for(int j = 0; j < N; j++){
                        if(comparaStrings(Empregado[i].cargo, Cargos[j].nome) == 1){
                            teste = Cargos[j].valor;
                        }
                    }
                    salariofinal = Empregado[i].salario + (somavenda * teste);
                    printf("\nSalario final: %.2f", salariofinal);

                }
                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);
                break;

            case 8:

                printf("\nSair");
                condicao = false;
                break;

            default:
                printf("Opção inválida!\n");

                break;
        }
    }
    return 0;
}

