#include <stdio.h>

int main() {

    // ===== Variáveis (parte do Eduardo) =====
    int valorSaque, saldoDisponivel = 1000, valorRestante;

    // Quantidade de cada nota
    int nota100, nota50, nota20, nota10, nota5, nota2, nota1;

    // ===== Variáveis auxiliares da validação (parte 3) =====
    int leituraOk;          // recebe o retorno do scanf (1 = leu um inteiro)
    int menorCedula = 1;    // menor cédula/moeda disponível (R$ 1 -> aceita qualquer inteiro)

    printf("=== CAIXA ELETRONICO ===\n");
    printf("Digite o valor que deseja sacar: R$ ");
    leituraOk = scanf("%d", &valorSaque);

    // ===== PARTE 3: VALIDAÇÕES =====
    // Cada condição é testada em ordem. Se alguma falhar, mostra a mensagem
    // de erro correspondente e o saque é negado (o else final só executa
    // quando TODAS as validações passam).

    if (leituraOk != 1) {
        // 1) Entrada não numérica (ex.: letras ou símbolos)
        printf("Erro: valor invalido. Digite apenas numeros inteiros.\n");

    } else if (valorSaque <= 0) {
        // 2) Zero ou negativo não faz sentido para um saque
        printf("Erro: o valor do saque deve ser maior que zero.\n");

    } else if (valorSaque % menorCedula != 0) {
        // 3) Valor precisa ser entregável com as cédulas disponíveis.
        //    Com a moeda de R$ 1 todo inteiro passa; se o grupo/professor
        //    decidir usar só cédulas de 5 para cima, basta trocar
        //    menorCedula para 5 (ou 2) lá em cima.
        printf("Erro: o valor %d nao pode ser pago com as cedulas disponiveis.\n", valorSaque);

    } else if (valorSaque > saldoDisponivel) {
        // 4) Saldo insuficiente
        printf("Erro: saldo insuficiente. Saldo disponivel: R$ %d\n", saldoDisponivel);

    } else {
        // ===== Saque APROVADO: todas as validações passaram =====

        // --- PROVISÓRIO: cálculo das notas (passo do colega, pode substituir) ---
        valorRestante = valorSaque;

        nota100 = valorRestante / 100;  valorRestante = valorRestante % 100;
        nota50  = valorRestante / 50;   valorRestante = valorRestante % 50;
        nota20  = valorRestante / 20;   valorRestante = valorRestante % 20;
        nota10  = valorRestante / 10;   valorRestante = valorRestante % 10;
        nota5   = valorRestante / 5;    valorRestante = valorRestante % 5;
        nota2   = valorRestante / 2;    valorRestante = valorRestante % 2;
        nota1   = valorRestante;

        // Exibe somente as notas com quantidade maior que zero
        printf("Saque aprovado! Notas entregues:\n");
        if (nota100 > 0) printf("%d nota(s) de R$ 100\n", nota100);
        if (nota50  > 0) printf("%d nota(s) de R$ 50\n",  nota50);
        if (nota20  > 0) printf("%d nota(s) de R$ 20\n",  nota20);
        if (nota10  > 0) printf("%d nota(s) de R$ 10\n",  nota10);
        if (nota5   > 0) printf("%d nota(s) de R$ 5\n",   nota5);
        if (nota2   > 0) printf("%d nota(s) de R$ 2\n",   nota2);
        if (nota1   > 0) printf("%d moeda(s) de R$ 1\n",  nota1);
        // --- FIM DO BLOCO PROVISÓRIO ---
    }

    return 0;
}
