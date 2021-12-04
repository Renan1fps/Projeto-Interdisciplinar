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

}Empregado[100];

void printfuncionario(struct empregado a){
    printf("\nNome : %s", a.nome);
    printf("\nIdade: %d", a.idade);
    printf("\nCPF: %s", a.cpf);
    printf("\nSalario: %.2f", a.salario);
    printf("\nCargo: %s", a.cargo);
    printf("-----------------------------")
}

void printfuncionariofechamento(struct empregado b){
    printf("\nNome : %s", b.nome);
    printf("\nCPF: %s", b.cpf);
    printf("\nSalario: %.2f", b.salario);
    printf("\nCargo: %s.\n", b.cargo);
}

int main()
{
    Empregado[MAX];
    const int TAMANHOARRAY = 40;
    bool condicao = true;
    int valor, sair, escolha;
    int i,p;
    int N = 0,M = 0;
    char buscafuncpornome[50];
    int contaVenda = 0;
    int contVenda[MAX];
    float venda,somavenda,salariofinal;
    char cargos[50][MAX2];
    float juroscargos[MAX2];



    for(i=0;i<MAX;i++){
        Empregado[i].contvendas=0;
    }


    while(condicao){

        system("cls");
        printf("\n\n\n\t\tMENU\n");
        printf("\n\nDigite o número de uma das opções abaixo. ");
        printf("\n1-Cadastrar um novo cargo na empresa. ");
        printf("\n2-Cadastrar novo empregado. ");
        printf("\n3-Listar todos os empregados cadastrados. ");
        printf("\n4-Buscar empregado por nome.");
        printf("\n5-Cadastrar venda de um funcionário.");
        printf("\n6-Alterar algum dado do cadastro de um funcionario.");
        printf("\n7-Fazer o fechamento mensal.");
        printf("\n8-Sair.\n");
        printf("\nEscolha uma opcao: ");
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
                    scanf("%49[^\n]", cargos[M]);

                    printf("\nDigite o juros que será aplicado ao total de vendas do funcionario neste cargo: ");
                    scanf("%f", &juroscargos[M]);

                    M++;
                }

                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);

                break;

            case 2: //cadastro de funcionários

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

                    printf("\nLista de cargos cadastrados:");

                    for(i=0;i<M;i++){
                        printf("\n-Cargo %d: %s.",i,cargos[i]);
                    }
                    printf("\n\n\nCaso o cargo desejado esteja na lista digite 1, ou caso queira cadastrar um novo cargo digite 2: ");
                    scanf("%d", &escolha);


                    switch(escolha){
                        case 1:
                            printf("\nDigite o numero do cargo que deseja atribuir ao funcionario: ");
                            scanf("%d",&p);
                            strcpy (Empregado[N].cargo,cargos[p]);

                            break;
                        case 2:
                            if(M == MAX2){
                                printf("\nLimite de armazenamento atingido!\n");
                            }
                            else{
                                printf("\nDigite o nome do cargo: ");
                                setbuf(stdin, NULL);
                                scanf("%49[^\n]", cargos[M]);

                                printf("\nDigite o juros que será aplicado do cargo: ");
                                scanf("%f", &juroscargos[M]);

                                strcpy (Empregado[N].cargo,cargos[M]);
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
                printf("\nDigite o nome do funcionario que gostaria de buscar: ");
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
                for(int i =0; i < N;i++){
                    if(comparaStrings(Empregado[i].nome, buscafuncpornome) == 1){
                        setbuf(stdin, NULL);
                        printf("\nDigite o valor da venda do funcionario: ");
                        scanf("%d", &venda);
                        Empregado[i].vendas[contVenda[i]] = venda;
                        contVenda[i]++;
                        break;
                    }
                }
                do{
                    printf("\nPressione 0 para sair: ");
                    scanf("%d",&sair);
                }while(sair!=0);
                break;

            case 6: //ALteração de dados
                setbuf(stdin, NULL);
                printf("\nDigite o nome do funcionário que gostaria de fazer alteração nos dados: ");
                scanf("%[^\n]", buscafuncpornome);
                for(int i =0; i < N;i++){
                    if(comparaStrings(Empregado[i].nome, buscafuncpornome) == 1){
                        printfuncionario(Empregado[i]);
                        printf("\n");


                        do{
                            printf("\n Escolha uma das opções a seguir:\n- Para alterar o nome, digite 1.\n- Para alterar a idade, digite 2.\n- Para alterar o CPF, digite 3.\n- Para alterar o endereço, digite 4.\n- Para alterar o salario, digite 5.\n- Para alterar o cargo, digite 6.\nEscolha uma opcao: ");
                            scanf("%d", &escolha);

                            switch(escolha){
                                case 1: {
                                    printf("\nDigite o nome alterado do funcionario: ");
                                    setbuf(stdin, NULL);
                                    scanf("%49[^\n]", Empregado[i].nome);
                                    break;
                                }
                                case 2: {
                                    printf("\nDigite a idade alterada do funcionario: ");
                                    scanf("%d", &Empregado[i].idade);
                                    break;
                                }
                                case 3: {

                                    printf("\nDigite o cpf alterado do funcionario: ");
                                    setbuf(stdin, NULL);
                                    scanf("%15[^\n]", &Empregado[i].cpf);
                                    break;
                                }
                                case 4: {

                                    printf("\nDigite o endereco alterado do funcionario: ");
                                    setbuf(stdin, NULL);
                                    scanf("%99[^\n]", &Empregado[i].endereco);
                                    break;
                                }
                                case 5: {

                                    printf("\nDigite o salario alterado do funcionario: ");
                                    scanf("%f", &Empregado[i].salario);
                                    break;
                                }
                                case 6: {

                                    printf("\nLista de cargos cadastrados:");
                                    for(i=0;i<M;i++){
                                    printf("\n-Cargo %d: %s.",i,cargos[i]);
                                    }
                                    printf("\nDigite o numero do cargo que deseja atribuir ao funcionario: ");
                                    scanf("%d",&p);
                                    strcpy (Empregado[i].cargo,cargos[p]);
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
                for(int i=0; i<N; i++){
                    somavenda = 0;
                    salariofinal = 0;
                    for(int j=0; j<contVenda[i]; j++){
                        somavenda= somavenda + Empregado[i].vendas[j];
                    }
                    printfuncionariofechamento(Empregado[i]);
                    salariofinal = Empregado[i].salario + (somavenda*juroscargos[M]);
                    printf("Salario final: %.2f",salariofinal);

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

