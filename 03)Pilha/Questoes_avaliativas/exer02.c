/*
2 – Faça um programa que recebe uma fila e inverte a sua ordem.
Sugestão: Utilize uma PILHA auxiliar para isso.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Tamanho máximo da fila

// Definição da estrutura da Fila
typedef struct {
    int elementos[MAX];
    int f;
    int r;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila* q) {
    q->f = -1;
    q->r = -1;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* q) {
    return q->f == -1;
}

// Função para verificar se a fila está cheia
int filaCheia(Fila* q) {
    return (q->r + 1) % MAX == q->f;
}

// Função para enfileirar um elemento
void enqueue(Fila* q, int valor) {
    if (filaCheia(q)) {
        printf("Fila cheia\n");
        return;
    }
    if (filaVazia(q)) {
        q->f = 0;
    }
    q->r = (q->r + 1) % MAX;
    q->elementos[q->r] = valor;
}

// Função para desenfileirar um elemento
int dequeue(Fila* q) {
    if (filaVazia(q)) {
        printf("Fila vazia\n");
        return -1;
    }
    int valor = q->elementos[q->f];
    if (q->f == q->r) {
        inicializarFila(q); // Fila está vazia agora
    } else {
        q->f = (q->f + 1) % MAX;
    }
    return valor;
}

// Função para imprimir a fila
void imprimirFila(Fila q) {
    if (filaVazia(&q)) {
        printf("Fila vazia\n");
        return;
    }
    int i = q.f;
    do {
        printf("%d ", q.elementos[i]);
        i = (i + 1) % MAX;
    } while (i != (q.r + 1) % MAX);
    printf("\n");
}

// Definição da estrutura da Pilha
typedef struct {
    int elementos[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha* p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

// Função para empilhar um elemento
void push(Pilha* p, int valor) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia\n");
        return;
    }
    p->elementos[++p->topo] = valor;
}

// Função para desempilhar um elemento
int pop(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia\n");
        return -1;
    }
    return p->elementos[p->topo--];
}

// Função para inverter a fila usando uma pilha auxiliar
void inverterFila(Fila* q) {
    Pilha p;
    inicializarPilha(&p);

    // Transferir os elementos da fila para a pilha
    while (!filaVazia(q)) {
        push(&p, dequeue(q));
    }

    // Transferir os elementos da pilha de volta para a fila
    while (!pilhaVazia(&p)) {
        enqueue(q, pop(&p));
    }
}

int main() {
    Fila q;
    inicializarFila(&q);

    // Enfileirar alguns elementos
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Fila original: ");
    imprimirFila(q);

    // Inverter a fila
    inverterFila(&q);

    printf("Fila invertida: ");
    imprimirFila(q);

    return 0;
}