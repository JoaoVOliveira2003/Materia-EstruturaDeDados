#include <stdio.h>;
# define TAM 5
// define uma constante que ai estar em todo codigo

typedef struct {
    int v[TAM];
    int topo;
}Pilha;


/*
Fazer 5 funçoes

pop
push
mostrar se esta vazia

*/


//para fazer um push,precisa do nome da pilha e o valor que vc quer inserir
void push(Pilha *p, int x){;
    //como vai mudar o treco coloca *
    /*
    p->topo quando tiver que alterar um dado dentro
    p.topo  quando tiver que ver um dado dentro

    Quando voce esta na main foda-se, apenas coloca . e funciona 100%
    mas quando voce insere em um escopo local tem que usar -> e .
    */

    //só insere na pilha se ela n estiver cheia

    if(p->topo == TAM-1){
        printf("Tabela cheia - OVERFLOW \n");
    }
    else{
        p->topo++;
        p->v[p->topo] = x;
        printf("Ok \n");
    }
}

void pop(Pilha *p){
    if(p-> topo ==-1){
        printf("Pilha vazia - underflow \n");
    }
    else{
        //isso daqui é gambiarra,se a pilha vai do inicio 0 até aonde esta o topo,é só mudar
        p->topo--;
        printf("Popou - tirando um \n");
    }
}


int main(){
    Pilha p1,p2,p3;
    int y;
    
    p1.topo = -1;

    push(&p1,8);
    push(&p1,2);
    push(&p1,7);
    push(&p1,6);
    pop(&p1);
    pop(&p1);
}
