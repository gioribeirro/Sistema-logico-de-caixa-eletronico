/* Atividade 2 - Caixa eletronico (APC)
   Parte 1 - Pseudocodigo em Portugol */

programa
{
	funcao inicio()
	{
		// variaveis
		inteiro valorSaque
		inteiro saldoDisponivel = 1000
		inteiro valorRestante
		inteiro nota100, nota50, nota20, nota10, nota5, nota2, nota1
		inteiro menorCedula = 1 // menor cedula disponivel (moeda de R$ 1)

		// leitura do valor
		escreva("=== CAIXA ELETRONICO ===\n")
		escreva("Digite o valor que deseja sacar: R$ ")
		leia(valorSaque)

		// validacoes
		se (valorSaque <= 0)
		{
			escreva("Erro: o valor do saque deve ser maior que zero.\n")
		}
		senao se (valorSaque % menorCedula != 0)
		{
			escreva("Erro: o valor ", valorSaque, " nao pode ser pago com as cedulas disponiveis.\n")
		}
		senao se (valorSaque > saldoDisponivel)
		{
			escreva("Erro: saldo insuficiente. Saldo disponivel: R$ ", saldoDisponivel, "\n")
		}
		senao
		{
			// calculo das notas, da maior para a menor
			valorRestante = valorSaque

			nota100 = valorRestante / 100
			valorRestante = valorRestante % 100

			nota50 = valorRestante / 50
			valorRestante = valorRestante % 50

			nota20 = valorRestante / 20
			valorRestante = valorRestante % 20

			nota10 = valorRestante / 10
			valorRestante = valorRestante % 10

			nota5 = valorRestante / 5
			valorRestante = valorRestante % 5

			nota2 = valorRestante / 2
			valorRestante = valorRestante % 2

			nota1 = valorRestante

			// mostra so as notas com quantidade maior que zero
			escreva("Saque aprovado! Notas entregues:\n")

			se (nota100 > 0)
			{
				escreva(nota100, " nota(s) de R$ 100\n")
			}
			se (nota50 > 0)
			{
				escreva(nota50, " nota(s) de R$ 50\n")
			}
			se (nota20 > 0)
			{
				escreva(nota20, " nota(s) de R$ 20\n")
			}
			se (nota10 > 0)
			{
				escreva(nota10, " nota(s) de R$ 10\n")
			}
			se (nota5 > 0)
			{
				escreva(nota5, " nota(s) de R$ 5\n")
			}
			se (nota2 > 0)
			{
				escreva(nota2, " nota(s) de R$ 2\n")
			}
			se (nota1 > 0)
			{
				escreva(nota1, " moeda(s) de R$ 1\n")
			}
		}
	}
}
