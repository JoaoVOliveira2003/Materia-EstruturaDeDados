#include <stdio.h>
#include <math.h>

struct coordenada{
    float x;
    float y;
};

typedef struct coordenada Ponto; /*aqui basicamente vc pega a estrutura */
                                 /*e a converte para uma um tipo de variavel(tipo int e var)*/

//Ou voce pode fazer assim:
/*
typedef struct coordenada{
    float x;
    float y;
}Ponto;
*/

struct conta{
    int agencia;
    int numero;
    //char titular[strmax];
};

struct Data {
    int dia;
    int mes;
    int ano;
};

float dist(Ponto p1,Ponto p2){
    float d;
    d=sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return d;
}

void preencher(Ponto *p){
    printf("Digite as cordenas do ponto 1(x,y)");
    scanf("%f %f", &p->x, &p->y);
}

void main(){

    //vc criou duas coisas Ponto(p1,p2)
    //que dentro de deles tem x.y

    Ponto p1,p2;
    float pitagoras;

    /*
    p1.x = 4.5;
    p1.y = 8.5;
    p2.x = 7.8;
    p2.y = 3.3;
    */
    //quando tiver nada n coloca nada
    //quando for inserir/apagar algo *
    //quando tem o & significa que vai mudar algo na memoria
    // quando tem -> muda a variavel para todo o codigo

    preencher(&p1);
    preencher(&p2);

    pitagoras = dist(p1,p2);

    printf("a distancia dos dois pontos :%0.2f",pitagoras);
}
