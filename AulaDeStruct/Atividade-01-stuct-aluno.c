/*
1 – Crie uma struct que representa um aluno. A struct é formada por um número inteiro
(representando a sua matrícula) e três números decimais, representando cada uma de suas
notas. Crie uma função que recebe um Aluno e retorna a média obtida por esse aluno.
*/

#include <stdio.h>

typedef struct{
  int matricula;
  float nota1;
  float nota2;
  float nota3;
} Aluno;

void preencher(Aluno *a) {
    printf("Digite a matricula do aluno: ");
    scanf("%d", &a->matricula);
    printf("Digite a nota 1: ");
    scanf("%f", &a->nota1);
    printf("Digite a nota 2: ");
    scanf("%f", &a->nota2);
    printf("Digite a nota 3: ");
    scanf("%f", &a->nota3);
}

float media(Aluno a) {
    return (a.nota1 + a.nota2 + a.nota3) / 3.0;
}

int main() {
    Aluno a1;
    float resultado;

    preencher(&a1);
    
    resultado = media(a1);
    
    printf("O aluno %d tem a media de %.2f\n", a1.matricula, resultado);

    return 0;
}
