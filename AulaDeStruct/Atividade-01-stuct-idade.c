/*
2 – Crie uma struct para representar uma data (dia, mês e ano). Em seguida receba do usuário
duas datas, correspondentes ao dia do seu nascimento e a data atual (nessa ordem). Faça uma
função que, dada as duas datas, calcule e retorne quantos anos o usuário possui.
*/
#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int calcularIdade(Data nascimento, Data atual) {
    int idade = atual.ano - nascimento.ano;
    return idade;
}

int main() {
    Data nascimento, atual;
    int idade;

    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &nascimento.dia, &nascimento.mes, &nascimento.ano);

    // Receber a data atual
    printf("Digite a data atual (dia mes ano): ");
    scanf("%d %d %d", &atual.dia, &atual.mes, &atual.ano);

    idade = calcularIdade(nascimento, atual);

    printf("Voce tem %d anos.\n", idade);

    return 0;
}
