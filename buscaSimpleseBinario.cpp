//extesao deporjetos c e .c e projetos c++ e .cpp
//esta projeto e c++ ou seja .cpp
//sempre fazer um build antes
#include <stdio.h>//standart in / out
#include <stdlib.h>//standart lib biblioteca de utlidades
#include <stdbool.h> //biblioteca para os valores booleanos(true,false)
#include <time.h> //biblioteca para tempo
#include <string.h>
#include <string>
#include <iostream>
//alocacao de memoria com c++
#include <new>
//definindo constantes use #difine
#define TAM 10

using namespace std;

bool Busca_Simples(int vetor[TAM], int valorPorcurado, int *PosicaoEncontrado){
    cout << "Busca Simples";
    int cont;
    bool ValorFoiEncontrado;

    for(cont = 0; cont < TAM; cont++){
        if( vetor[cont] == valorPorcurado ){
            ValorFoiEncontrado = true;
            *PosicaoEncontrado  = cont;
        }
    }
    if(ValorFoiEncontrado){
        return true;
    }else{
        return false;
    }
}

bool Busca_Binaria(int vetor[TAM], int valorPorcurado, int *PosicaoEncontrado){
    cout << "Busca Binaria";
    //ela sempra vai procurar no meio ou seja vai dividir por 2
    //precisa da posicao inicila da esquerda
    int esquerda = 0;
    //precisa pegar a ultima posicao que e tamanho do vetor menos 1
    int direita = TAM - 1;
    int meio;
    bool ValorFoiEncontrado;
    //enqunato a posicao da esquerda for menor ou igual que a da direita
    while(esquerda <= direita ){

    //encontra o meio
    meio = (esquerda + direita)/2;

        if(valorPorcurado == vetor[meio]){
            *PosicaoEncontrado = meio;
            ValorFoiEncontrado = true;
            return true;
        }
        //se o pivo for menor que o valor procurado, ignoro os valors da esqueerda, pq esta ordenado em ordem crescente
        if(vetor[meio] < valorPorcurado){
             //comeco da esquerda sem o valor anterior
            esquerda = meio + 1;
        }else{
            direita = meio - 1;
        }
    }

    if(ValorFoiEncontrado){
        return true;
    }else{
        return false;
    }
}

int main(){

    int vetor[TAM] =  {1,23,44,56,63,72,84,90,99};
    int valorprocurado;
    int posicao,posicaoencontrado;
    int cont;
    bool valorfoiencontrado;

    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }

    printf("Qual numero deseja encontrar?\n");
    scanf("%d",&valorprocurado);

    for(cont = 0; cont < TAM; cont++){
        if (vetor[cont] == valorprocurado ){
            valorfoiencontrado = true;
            posicao = cont;
        }
    }

     if (Busca_Simples(vetor,valorprocurado,&posicaoencontrado)){

            cout << "O valor foi encontardo na posicao: " << posicaoencontrado;
        }else{
            cout << "O valor nao foi encontardo!";
        }
    if (Busca_Binaria(vetor,valorprocurado,&posicaoencontrado)){

            cout << "O valor foi encontardo na posicao: " << posicaoencontrado;
        }else{
            cout << "O valor nao foi encontardo!";
        }


    return 0;
}
