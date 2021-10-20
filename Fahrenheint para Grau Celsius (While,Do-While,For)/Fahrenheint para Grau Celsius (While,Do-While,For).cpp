#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Exercicio 1
main()
{
	using namespace std;
	int entrada;

	cout << "1- Escrever Tabela com Instrucao While" << endl;
	cout << "2- Escrever Tabela com Instrucao Do-While" << endl;
	cout << "3- Escrever Tabela com Instrucao For" << endl;
	cout << "4- Sair" << endl
		 << endl;
	cin >> entrada;

	switch (entrada)
	{
	case 1:
	{
		int inter;

		cout << endl
			 << "Escrevendo Tabela com a Instrucao While: " << endl
			 << endl;
		cout << "Digite o numero de intervalos: ";

		cin >> inter;
		float varinter[inter];
		int x = 0;

		while (x < inter)
		{
			cout << endl
				 << "Digite um grau em Fahrenheint para o intervalo " << x << " da operacao: " << endl;
			cin >> varinter[x];

			if (varinter[x] > 212)
			{
				cout << "digite um numero menor ou igual a 212 fhr: ";
				cin >> varinter[x];
			}

			x++;
		}

		x = 0;

		while (x < inter)
		{
			cout << endl
				 << "Exibindo Tabela de conversao no comando While: " << endl;
			cout << "F da tabela " << x << " : " << varinter[x] << endl;

			varinter[x] = (varinter[x] - 32) / 1.8;

			cout << "C da tabela " << x << " : " << varinter[x] << endl;
			x++;
		}

		break;
	}

	case 2:
	{
		cout << endl
			 << "Escrevendo Tabela com a Instrucao Do-While: " << endl
			 << endl;
		int inter;
		cout << "Digite o numero de intervalos: ";
		cin >> inter;
		float varinter[inter];
		int x = 0;

		do
		{
			cout << endl
				 << "Digite um grau em Fahrenheint para o intervalo " << x << " da operacao: " << endl;
			cin >> varinter[x];

			if (varinter[x] > 212)
			{
				cout << "digite um numero menor ou igual a 212 fhr: ";
				cin >> varinter[x];
			}

			x++;

		} while (x < inter);

		x = 0;

		do
		{
			cout << endl
				 << "Exibindo Tabela de conversao no comando Do-While: " << endl;
			cout << "F da tabela " << x << " : " << varinter[x] << endl;
			varinter[x] = (varinter[x] - 32) / 1.8;
			cout << "C da tabela " << x << " : " << varinter[x] << endl;
			x++;
		} while (x < inter);

		break;
	}

	case 3:
	{
		cout << endl
			 << "Escrevendo Tabela com Instrucao For: " << endl
			 << endl;
		int inter, x;
		cout << "Digite o numero de intervalos: ";
		cin >> inter;
		float varinter[inter];

		for (x = 0; x < inter; x++)
		{
			cout << endl
				 << "Digite um grau em Fahrenheint para o intervalo " << x << " da operacao: " << endl;
			cin >> varinter[x];

			if (varinter[x] > 212)
			{
				cout << "digite um numero menor ou igual a 212 fhr: ";
				cin >> varinter[x];
			}
		}

		for (x = 0; x < inter; x++)
		{
			cout << endl
				 << "Exibindo Tabela de conversao no comando For: " << endl;
			cout << "F da tabela " << x << " : " << varinter[x] << endl;
			varinter[x] = (varinter[x] - 32) / 1.8;
			cout << "C da tabela " << x << " : " << varinter[x] << endl;
		}

		break;
	}

	default:
	{

		return 0;
	}
	}
	system("PAUSE");

	return 0;
}
