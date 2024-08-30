//Criar 3 pilhas p1,p2,p3
/*Jogo continua while(p3.todo!=TAM*)*/
/*
Tem que ter

Max 2 aluno
(1 a 5 é onbrigatorio)
1- utilizar pilhas
2- utilizar push e pop 
3- usar pontuação de jogador (quantos movimentos feitos)
4- colcoar um Jogador novamente
5- jogabilidade, ficar bonitinho

6 - marcar o tempo ? (tem uma função clock em C )
7 - ter 3 niveis de dificuldade facil(3 discos) medio (5 discos) alta (7 discos)
*/

#include <stdio.h>
#include <time.h>
#define TAM 3

typedef struct {
    int v[TAM];
    int topo;
} Torre;

// Inicializa uma torre, definindo o topo como -1 (vazia)
void inicializarTorre(Torre *p) {
    p->topo = -1;
}

// Adiciona um disco na torre (empilha o disco)
int push(Torre *p, int x) {
    if (p->topo == TAM - 1) {
        printf("Erro: Torre cheia - OVERFLOW\n");
        return 0;
    } else {
        p->topo++;
        p->v[p->topo] = x;
        return 1;
    }
}

// Remove um disco da torre (desempilha o disco)
int pop(Torre *p) {
    if (p->topo == -1) {
        printf("Erro: Torre vazia - UNDERFLOW\n");
        return -1;
    } else {
        int x = p->v[p->topo];
        p->topo--;
        return x;
    }
}

// Mostra o estado atual das torres
void mostrarTorres(Torre *t1, Torre *t2, Torre *t3) {
    printf("\nEstado atual das torres:\n");

    // Encontra o maior topo entre as três torres
    int maior_topo = t1->topo > t2->topo ? (t1->topo > t3->topo ? t1->topo : t3->topo) : (t2->topo > t3->topo ? t2->topo : t3->topo);

    for (int i = maior_topo; i >= 0; i--) {
        // Torre 1
        if (i <= t1->topo) {
            printf("[ %d ] ", t1->v[i]);
        } else {
            printf("      ");
        }

        // Torre 2
        if (i <= t2->topo) {
            printf("[ %d ] ", t2->v[i]);
        } else {
            printf("      ");
        }

        // Torre 3
        if (i <= t3->topo) {
            printf("[ %d ] ", t3->v[i]);
        } else {
            printf("      ");
        }

        printf("\n");
    }

    printf("  T1    T2    T3\n");
}

// Move um disco de uma torre para outra e conta o número de movimentos
void moverDisco(Torre *origem, Torre *destino, int *movimentos) {
    if (origem->topo == -1) {
        printf("Erro: Torre de origem vazia, nao há disco para mover.\n");
        return;
    }

    int disco = pop(origem);

    if (destino->topo != -1 && destino->v[destino->topo] < disco) {
        printf("Erro: Movimento invalido, nao pode colocar um disco maior sobre um menor.\n");
        push(origem, disco);  // Devolve o disco para a torre de origem
    } else if (push(destino, disco)) {
        (*movimentos)++;
    }
}

int main() {
    char jogarNovamente;

    do {
        Torre t1, t2, t3;
        inicializarTorre(&t1);
        inicializarTorre(&t2);
        inicializarTorre(&t3);

        // Inicializa a torre 1 com discos
        for (int i = TAM; i >= 1; i--) {
            push(&t1, i);
        }

        int movimentos = 0;
        clock_t start_time = clock();

        // Enquanto a torre 3 não estiver completa
        while (t3.topo != TAM - 1) {
            mostrarTorres(&t1, &t2, &t3);

            printf("\nEscolha a torre de origem (1, 2, 3): ");
            int origem;
            scanf("%d", &origem);

            printf("Escolha a torre de destino (1, 2, 3): ");
            int destino;
            scanf("%d", &destino);

            Torre *torreOrigem = NULL, *torreDestino = NULL;

            if (origem < 1 || origem > 3 || destino < 1 || destino > 3) {
                printf("Erro: Torres inválidas. Escolha 1, 2 ou 3.\n");
                continue;
            }

            switch (origem) {
                case 1: torreOrigem = &t1; break;
                case 2: torreOrigem = &t2; break;
                case 3: torreOrigem = &t3; break;
            }

            switch (destino) {
                case 1: torreDestino = &t1; break;
                case 2: torreDestino = &t2; break;
                case 3: torreDestino = &t3; break;
            }

            if (torreOrigem == torreDestino) {
                printf("Erro: A torre de origem e destino nao podem ser a mesma.\n");
                continue;
            }

            moverDisco(torreOrigem, torreDestino, &movimentos);
        }

        clock_t end_time = clock();
        double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Parabens, voce venceu!\n");
        printf("Movimentos realizados: %d\n", movimentos);
        printf("Tempo de execução: %.2f segundos.\n", execution_time);

        // Perguntar ao jogador se ele deseja jogar novamente
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente); // O espaço antes do %c é importante para ignorar o enter da entrada anterior

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar!\n");

    return 0;
}
