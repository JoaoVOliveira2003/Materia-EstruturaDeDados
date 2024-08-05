#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int calcularIdade(Data nascimento, Data atual) {
    int idade = atual.ano - nascimento.ano
    return idade;
}

int main() {
    Data nascimento, atual;
    int idade;

    // Receber a data de nascimento do usuário
    printf("Digite a data de nascimento (dia mês ano): ");
    scanf("%d %d %d", &nascimento.dia, &nascimento.mes, &nascimento.ano);

    // Receber a data atual
    printf("Digite a data atual (dia mês ano): ");
    scanf("%d %d %d", &atual.dia, &atual.mes, &atual.ano);

    // Calcular a idade
    idade = calcularIdade(nascimento, atual);

    // Exibir a idade
    printf("Você tem %d anos.\n", idade);

    return 0;
}
