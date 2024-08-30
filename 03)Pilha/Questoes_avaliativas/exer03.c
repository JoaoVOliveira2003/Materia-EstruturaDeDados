/*
3 - Faça um programa que recebe duas filas e verifica se elas são
exatamente iguais.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para criar uma fila vazia
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Função para adicionar um elemento na fila
void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Função para remover um elemento da fila
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Função para verificar se duas filas são idênticas
int areQueuesIdentical(Queue* q1, Queue* q2) {
    Node* temp1 = q1->front;
    Node* temp2 = q2->front;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            return 0; // Filas não são idênticas
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // Se uma fila terminou antes da outra, elas não são idênticas
    if (temp1 == NULL && temp2 == NULL) {
        return 1; // Filas são idênticas
    } else {
        return 0; // Filas não são idênticas
    }
}

int main() {
    Queue* q1 = createQueue();
    Queue* q2 = createQueue();

    // Adicionando elementos à fila q1
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);
    enqueue(q1, 50);

    // Adicionando elementos à fila q2
    enqueue(q2, 10);
    enqueue(q2, 20);
    enqueue(q2, 33);
    enqueue(q2, 40);
    enqueue(q2, 50);

    // Verificando se as filas são idênticas
    if (areQueuesIdentical(q1, q2)) {
        printf("As filas sao identicas.\n");
    } else {
        printf("As filas nao sao identicas.\n");
    }

    return 0;
}
