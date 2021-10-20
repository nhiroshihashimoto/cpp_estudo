#include <iostream>
#include <cstdlib> //biblioteca para incluir o system("PAUSE");

using namespace std;

int main(int argc, char **argv){
    int Numero[7];

    for (int i = 1; i <= 5; i++){
        cout << "Insira o valor para a posicao " << i << endl;
        cin >> Numero[i];
    }
    int soma = 0;

    for (int i = 1; i <= 5; i++){
        cout << "Numero digitado na posicao " << i << " foi " << Numero[i] << endl;
        soma = soma + Numero[i];
    }

    for (int i = 1; i <= 5; i++){

    }
    cout << "A soma dos numeros sao: " << soma << endl;

    return 0;
}
