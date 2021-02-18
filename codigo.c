#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A struct Cadastro serve para armazenar os dados cadastrais do paciente
struct Cadastro{
    char nome [50];
    char cpf [12];
    char telf [10];
};

typedef struct Cadastro cadastro;

//A fun��o IMC tem como finalidade fazer o c�lculo do �ndice de Massa Corporea
float IMC (float peso, float altura){
    float calculo;
    calculo = peso / (altura * altura);
    return calculo;
}

//As fun��es GorduraH e GorduraM realiza o c�lculo de gordura corporal da pessoa, fizemos duas f�rmulas, pois
//a forma de calcular gordura coporal � diferente para homens e mulheres
float GorduraH (float resultimc, int idade){
    float percentgord;
    percentgord = (1.20 * resultimc) + (0.23 * idade) - (10.8 * 1) - 5.4;
    return percentgord;
}

float GorduraM (float resultimc, int idade){
    float percentgord;
    percentgord = (1.20 * resultimc) + (0.23 * idade) - (10.8 * 0) - 5.4;
    return percentgord;
}

//Assim como o c�lculo de gordura corportal, o metabolismo basal (a quantidade m�nima de energia necess�ria
//para manter as fun��es vitais) tem diferencia��o no c�lculo para homens e mulheres, dessa forma
//fizemos duas fun��es a BasalH e a BasalM
float BasalH (float peso, float altura, float idade ){
    float gasto;
    gasto = 66 + (13.8 * peso) + (5 * altura)- (6.8 * idade);
    return gasto;
}
float BasalM (float peso, float altura, float idade ){
    float gasto;
    gasto = 665 + (9.6 * peso) + (1.8 * altura)- (4.7 * idade);
    return gasto;
}

int Formapaga (char pague){

}

//Procedimento para fazer a ordena��o do vetor. Ele compara os valores e coloca em ordem crescente.
void Insercao(float v[]){
    int i, j;
    float x;
    for(j=0;j<5;j++){
        x = v[j];
        for(i=j-1;i>=0 && v[i] > x; i--){
            v[i+1] = v[i];
        }
        v[i+1] = x;
    }

}
//Algoritmo de busca, ele compara o valor do IMC, que ser� informado pelo usu�rio.
//Ele, ir� comparar em qual faixa se enquadra o IMC do paciente. Depois ordenar� em ordem crescente,
//assim, informando ao nutricionista o status ICM.
float ComparaIMC (float imc){
    float mediaimc[5];
    mediaimc[0] = 18.0;
    mediaimc[1] = 25.0;
    mediaimc[2] = 30.0;
    mediaimc[3] = 40.0;
    mediaimc[4] = imc;
    int i;
    //O inser��o � para ordenar o IMC nos indices da mediaimc, e posteriormente verificar em qual posi��o est�
    //e depois verificarmos o tipo corporal do paciente.
    Insercao(mediaimc);

    int posicao;

    //Numero maximo de posi��es.
    posicao = 5;

    //O while encontra a posi��o do IMC dentro do array ComparaIMC.
    while (posicao >= 0 && mediaimc[posicao] != imc){
        posicao = posicao - 1;}
    fflush(stdin);
    return posicao;
}

int main(){

    float alt, pe, imc, gordura, metabo;
    int idade,i,teste,n, totalparticular, totalconvenio;
    char sexo,resp;

//Cria��o do arquivo
    FILE* f;
    f = fopen("Diagnostico.txt","a");

    if(f == NULL){
        printf("Erro na abertura do arquivo!");
    } else {
//sendo o correto a cria��o do arquivo, as perguntas seguintes ser�o apresentadas na tela.
            printf("Quantos pacientes serao cadastrada? \n");
            scanf("%d", &n);
            fflush(stdin);
    char pagamento[n];

            cadastro pessoa[n];

    int *p;
    p = (int*) malloc(200*sizeof(pessoa));
    if(p == NULL){
    printf("Erro memoria insuficiente!\n");
    system ("pause");
    exit(1);
    }
            for(i=0;i<n;i++){
            printf("Entre com os dados do paciente\n");
            printf("Nome:\n");
            gets(pessoa[i].nome);
            fprintf(f,"Paciente: %s\n",pessoa[i].nome);
            fflush(stdin);

            printf("CPF: \n");
            gets(pessoa[i].cpf);
            fprintf(f,"CPF: %s\n",pessoa[i].cpf);
            fflush(stdin);

            printf("Telefone: \n");
            gets(pessoa[i].telf);
            fprintf(f,"Telefone: %s\n",pessoa[i].telf);
            fflush(stdin);

            printf("Forma de pagamento P (Particular) ou C (Convenio): \n");
            scanf("%c", &pagamento[i]);
            fprintf(f,"Forma de pagamento: %c\n", pagamento[i]);
            fflush(stdin);

            printf("Sexo do paciente: M (para masculino) ou F (para feminino):\n");
            scanf("%c", &sexo);
            fprintf(f,"Sexo: %c\n",sexo);
            fflush(stdin);

            printf("Idade:\n");
            scanf("%d", &idade);
            fprintf(f,"Idade: %d\n",idade);
            fflush(stdin);

            printf("Altura:\n");
            scanf("%f", &alt);
            fprintf(f,"Altura: %f\n",alt);
            fflush(stdin);

            printf("Peso: \n");
            scanf("%f", &pe);
            fprintf(f,"Peso: %f\n",pe);
            fflush(stdin);

//A vari�vel imc receber� o resultado do c�lculo de IMC com base nas informa��es fornecidas pelo usu�rio
            printf("O seu IMC eh: \n");
            imc = IMC(pe,alt);
            printf("Seu IMC eh: %f \n", imc);
            fprintf(f,"IMC: %f\n",imc);

//A vari�vel gordura receber� o resultado da fun��o Gordura, como tem esfecifica��o de homem e mulher, usamos
//um if para chamar a fun��o correta
            if(sexo == 'M'){
                gordura = GorduraH(imc,idade);
                printf("O percentual de gordura eh de: %f \n", gordura);
                fprintf(f,"Percentual: %f\n",gordura);
            } else {
                if(sexo == 'F'){
                    gordura = GorduraM(imc,idade);
                    printf("O percentual de gordura eh de:%f \n", gordura);
                    fprintf(f,"Percentual: %f\n",gordura);
                }
            }

//Usamos um if para fazer a diferencia��o entre a f�rmula para homem e mulher no c�lculo do metabolismo basal.
            if(sexo == 'M'){
                metabo = BasalH(pe,alt,idade);
                printf("O metabolismo basal eh de:%f \n", metabo);
                fprintf(f,"Metabolismo basal: %f\n",metabo);
            } else {
                if(sexo == 'F'){
                    metabo = BasalM(pe,alt,idade);
                    printf("O metabolismo basal eh de:%f \n", metabo);
                    fprintf(f,"Metabolismo basa: %f\n",metabo);
                }
            }

//A vari�vel teste o resultado do ComparaIMC
            teste = ComparaIMC(imc);

//Os if servem para buscar o indice do vertor mediaimc, e dessa forma informar como est� o peso do paciente.
//O underline no printf e fprintf colocamos para separar os dados de um paciente do outro no arquivo.
            if (teste == 0){
                printf ("Abaixo do peso. \n");
                fprintf(f,"O(a) paciente est�: Abaixo do peso \n");
                printf("________________________________________\n");
                fprintf(f,"________________________________________\n");
            } else if (teste == 1) {
                printf ("Peso normal. \n");
                fprintf(f,"O(a) paciente est� com: Peso normal \n");
                printf("________________________________________\n");
                fprintf(f,"________________________________________\n");
            } else if (teste == 2) {
                printf ("Pre obesidade. \n");
                fprintf(f,"O(a) paciente est� com: Pr� obesidade \n");
                printf("________________________________________");
                fprintf(f,"________________________________________");
            } else if (teste == 3) {
                printf ("Obesidade. \n");
                fprintf(f,"O(a) paciente est� com: Obesidade \n");
                printf("________________________________________\n");
                fprintf(f,"________________________________________\n");
            } else if (teste == 4) {
                printf ("Obesidade morbida. \n");
                fprintf(f,"O(a) paciente est� com: Obesidade m�rbida \n");
                printf("________________________________________\n");
                fprintf(f,"________________________________________\n");
            }
            }
            totalparticular = 0;
            totalconvenio = 0;

        for(i=0;i<n;i++){
        if (pagamento[i] == 'P' && n > 1){
                totalparticular = totalparticular +1; }
        if (pagamento[i] == 'C' && n > 1){
                totalconvenio = totalconvenio +1; }}
        printf ("Pacientes pagaram com conv�nio %d, pagaram particular %d", totalconvenio, totalparticular);
        fprintf (f,"Pacientes pagaram com conv�nio %d, pagaram particular %d", totalparticular, totalconvenio);
            printf("________________________________________\n");
            fprintf(f,"________________________________________\n");

            fclose(f);
        }


        return 0;
}


