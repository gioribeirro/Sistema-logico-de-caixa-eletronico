#include <stdio.h>

int main(int argc, char *argv[]) {
    /*
     * as variáveis correspondem ao saldo do caixa (inicialmente, de 10000 reais),
     * ao valor do saque, ao valor restante, que deve ser repartido, e às cedulas/moedas a serem resgatadas.
     */
    int saldoDisponivel = 10000, valorSaque, valorRestante;
    int nota100 = 0, nota50 = 0, nota20 = 0, nota10 = 0, nota5 = 0, nota2 = 0, moeda1 = 0;

    int validarNumero;
    int menorCedula = 1;

    // na apresentação do caixa eletrônico é solicitado o saque.
    printf("=== CAIXA ELETRONICO ===");
    printf("\nDigite o valor que deseja sacar: R$");
    validarNumero = scanf("%d", &valorSaque);

    /*
    * nesse primeiro bloco condicional, é realizada a validação do saque.
    * o saque não será efetuado se a entrada não for um número inteiro,
    * se o valor for menor ou igual a 0, se for maior que o saldo disponível
    * do caixa ou se não puder ser pago com as cédulas disponíveis.
    */
    if (validarNumero != 1) {
        printf("Erro: o valor digitado e invalido! Digite apenas numeros inteiros!");
    } else if (valorSaque <= 0) {
        printf("Erro: o valor numerico precisa ser maior que zero!");
    } else if (valorSaque > saldoDisponivel) {
        printf("Desculpe! Este valor nao esta disponivel em nosso caixa!");
    } else if (valorSaque % menorCedula != 0) {
        printf("Erro: o valor R$%d nao pode ser pago com as cedulas disponiveis!", valorSaque);
    } else {

        /*
         * o valor é dividido a partir da maior cédula até a menor.
         * o quociente da divisão inteira é a quantidade de cédulas/moedas
         * e o resto é o valor que ainda precisa ser repartido.
         */
        saldoDisponivel -= valorSaque; // desconto do saldo do caixa com o valor do saque
        valorRestante = valorSaque;

        nota100 = valorRestante / 100;
        valorRestante = valorRestante % 100;
        nota50 = valorRestante / 50;
        valorRestante = valorRestante % 50;
        nota20 = valorRestante / 20;
        valorRestante = valorRestante % 20;
        nota10 = valorRestante / 10;
        valorRestante = valorRestante % 10;
        nota5 = valorRestante / 5;
        valorRestante = valorRestante % 5;
        nota2 = valorRestante / 2;
        valorRestante = valorRestante % 2;
        moeda1 = valorRestante;

        // exibe a quantidade de cédulas/moedas convertidas do valor do saque que serão resgatadas.
        printf("Saque aprovado! Notas entregues:\n");
        if (nota100 > 0) printf("%d nota(s) de R$100\n", nota100);
        if (nota50 > 0) printf("%d nota(s) de R$50\n", nota50);
        if (nota20 > 0) printf("%d nota(s) de R$20\n", nota20);
        if (nota10 > 0) printf("%d nota(s) de R$10\n", nota10);
        if (nota5 > 0) printf("%d nota(s) de R$5\n", nota5);
        if (nota2 > 0) printf("%d nota(s) de R$2\n", nota2);
        if (moeda1 > 0) printf("%d moeda(s) de R$1\n", moeda1);
    }
    return 0;
}
