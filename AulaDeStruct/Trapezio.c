#include <stdio.h>

// Definindo a estrutura Trapezio
typedef struct {
    int baseMaior;
    int baseMenor;
    int altura;
} Trapezio;

// Função para calcular a área do trapézio
float calculo(Trapezio t) {
    float resul;
    resul = ((t.baseMaior + t.baseMenor) * t.altura) / 2.0;
    return resul;
}

// Função para preencher os dados do trapézio
void preencher(Trapezio *t) {
    printf("Digite base maior: ");
    scanf("%d", &t->baseMaior);
    printf("Digite base menor: ");
    scanf("%d", &t->baseMenor);
    printf("Digite a altura: ");
    scanf("%d", &t->altura);
}

// Função principal
int main() {
    Trapezio t1;
    float resultado;

    preencher(&t1);

    resultado = calculo(t1);

    printf("A área do trapézio é: %.2f\n", resultado);

    return 0;
}
