#include <stdio.h>

int main(int argc, char *argv[]) {
    /*
     * as variáveis correspondem ao saldo do caixa (inicialmente, de 10000 reais),
     * ao valor do saque e às cedulas/moedas a serem resgatadas.
     */
    int saldoDisponivel = 10000, valorSaque, nota100 = 0, nota50 = 0,
    nota20 = 0, nota10 = 0, nota5 = 0, nota2 = 0, moeda1 = 0;

    int validarNumero;
    int menorCedula = 1;

    // na apresentação do caixa eletrônico é solicitado o saque.
    printf("=== CAIXA ELETRONICO ===");
    printf("\nDigite o valor que deseja sacar: R$");
    validarNumero = scanf("%d", &valorSaque);

    /*
     * nesse primeiro bloco condicional, é realizada a validação do saque.
     * se o valor for menor que 0 ou maior que o saldo disponível do caixa, o saque não será efetuado.
     */

    if (validarNumero != 1) {
        printf("Erro: o valor digitado e invalido! Digite apenas numeros inteiros!");
    } else if (valorSaque <= 0){
        printf("Erro: o valor numerico precisa ser maior que zero!");
    } else if (valorSaque > saldoDisponivel){
        printf("Desculpe! Este valor nao esta disponivel em nosso caixa!");
    } else if (valorSaque % menorCedula != 0) {
        printf("Erro: o valor R$%d nao pode ser pago com as cedulas disponiveis!", valorSaque);
    } else {

        // após a validação, haverá o desconto do saldo disponível do caixa com o valor do saque.
        saldoDisponivel -= valorSaque;

        /*
         * nesse primeiro bloco condicional, é realizada a validação do saque.
         * o saque não será efetuado se a entrada não for um número inteiro,
         * se o valor for menor ou igual a 0, se for maior que o saldo disponível
         * do caixa ou se não puder ser pago com as cédulas disponíveis.
         */
        while (valorSaque > 0){

            if (valorSaque >= 100){
                nota100 = valorSaque/100;
                valorSaque %= 100;
            }

            if (valorSaque < 100 && valorSaque >= 50) {
                nota50 = valorSaque/50;
                valorSaque %= 50;
            }

            if (valorSaque < 50 && valorSaque >= 20){
                nota20 = valorSaque/20;
                valorSaque %= 20;
            }

            if (valorSaque < 20 && valorSaque >= 10){
                nota10 = valorSaque/10;
                valorSaque %= 10;
            }

            if (valorSaque < 10 && valorSaque >= 5){
                nota5 = valorSaque/5;
                valorSaque %= 5;
            }

            if (valorSaque < 5 && valorSaque >= 2){
                nota2 = valorSaque/2;
                valorSaque %= 2;
            }

            if (valorSaque < 2 && valorSaque >= 1){
                moeda1 = valorSaque;
                valorSaque -= valorSaque;
            }
        }

        // exibe a quantidade de cédulas/moedas convertidas do valor do saque que serão resgatadas.
        printf("Saque bem sucedido! Seguem as cedulas para saque: ");
        printf("\nCedulas de R$100: %d", nota100);
        printf("\nCedulas de R$50: %d", nota50);
        printf("\nCedulas de R$20: %d", nota20);
        printf("\nCedulas de R$10: %d", nota10);
        printf("\nCedulas de R$5: %d", nota5);
        printf("\nCedulas de R$2: %d", nota2);
        printf("\nMoedas de R$1: %d\n", moeda1);

    }

    return 0;
}
