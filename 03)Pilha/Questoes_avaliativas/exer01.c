#include <stdio.h>
#define TAM 4

struct fila{
    int f;
    int r;
    int elementos[TAM];
};
typedef struct fila Fila;

void enqueue(Fila *q, int x);
int dequeue(Fila *q);
int isEmpty(Fila q);
int isFull(Fila q);
void imprimir(Fila q);

void enqueue(Fila *q, int x){
    if(isFull(*q)==0){
        q->r = (q->r + 1)%(TAM);
        q->elementos[q->r] = x;
        if(q->f == -1){
            q->f++;
        }
    }
    else{
        printf("Fila cheia. Nao e possivel inserir elementos. OVERFLOW\n");
    }
}

int dequeue(Fila *q){
    int res=-1;
    if(isEmpty(*q)==0){
        res = q->elementos[q->f];
        if(q->f == q->r){ //UM ELEMENTO
           q->r = -1;
           q->f = -1;
        }
        else{
            q->f = (q->f + 1)%(TAM);
        }
        return res;
    }
    else{
        printf("Pilha vazia. Nao e possivel remover. UNDERFLOW\n");
        return;
    }

}

int isEmpty(Fila q){
    if(q.r == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(Fila q){
    if(q.r > q.f && q.f==0 && q.r==TAM-1){
        return 1;
    }
    else if(q.f > q.r && q.f - q.r == 1){
        return 1;
    }
    else{
        return 0;
    }
}

void imprimir(Fila q){
    int i;
    if(isEmpty(q)==1){
        printf("Fila vazia \n");
    }
    else{
        printf("Fila: ");
        if(q.f < q.r){
            for(i=q.f; i<= q.r; i++){
                printf("%i ", q.elementos[i]);
            }
        }
        else{
            for(i=q.f; i<= TAM-1; i++){
                printf("%i ", q.elementos[i]);
            }
            for(i=0; i<= q.r; i++){
                printf("%i ", q.elementos[i]);
            }
        }

    }

}

int main(){

    Fila q1 = {-1, -1};
    Fila q2 = {-1, -1};
    Fila q3 = {-1, -1};
    enqueue(&q1, 3);
    enqueue(&q1, 5);
    enqueue(&q1, 5);
    enqueue(&q1, 8);
    enqueue(&q2, 1);
    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 7);
    enqueue(&q1, 8);
    enqueue(&q1, 12);
   
    int aux;
    while(q1.f != -1 || q2.f != -1){
        if(q1.f != -1 && q2.f != -1){
            if(q1.elementos[q1.f] < q2.elementos[q2.f]){
                aux = dequeue(&q1);
                enqueue(&q3, aux);
            }
            else{
                aux = dequeue(&q2);
                enqueue(&q3, aux);
            }
        }
        else if(q1.f==-1){
            aux = dequeue(&q2);
            enqueue(&q3, aux);
        }
        else{
            aux = dequeue(&q1);
            enqueue(&q3, aux);
        }
    }
    imprimir(q3);
}