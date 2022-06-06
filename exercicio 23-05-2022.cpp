/*Escreva um programa que leia do teclado números naturais. A leitura se encerra apenas quando o  usuário entra com um número negativo.

Antes do programa sair, ele deve mostrar o seguinte relatório:
a) Total de números que foram digitados
b) Total de números pares que foram Digitados
c) Total de números ímpares que foram digitados
d) O maior número digitado
e) O menor número digitado
f) A somatória dos números digitados
g) O produtório dos números digitados
h) A a média dos números digitados
i) O maior número par
j) O menor número ímpar
k) Se o maior número digitado é primo*/


#include <iostream>
#include <locale.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<float> lista;
int i = 1;
float numero;

int main () {
	
	setlocale (LC_ALL,"");
		
	//OBTENDO OS NÚMEROS
	while (i > 0) {
		
		cout << "Digite o " << i << "º número: ";
		cin >> numero;
	
		while (!cin) {
		cout << "Valor invalido!!!, digite um valor numérico.\n\n";
		cout << "Digite o " << i << "º número: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> numero;
	}
	
		lista.push_back(numero);
	
		if (numero < 0)
			i = -1;
			
		i++;
	}
	
	lista.pop_back();
	
	cout << "\n\nRELATÓRIO FINAL:\n\n";
	cout << "a) O total de números digitados foi " << lista.size() << endl;
	
	vector<float> lista_par;
	vector<float> lista_impar;
	int n;
	
	//SEPARANDO OS NÚMEROS PARES E IMPARES
	for (int i = 0; i < lista.size(); i++) {
		
		n = lista[i] / 2;
		
		if (lista[i] != 0) {
			if ((lista[i] / 2) == n)
				lista_par.push_back(lista[i]);
			else {
				n = lista[i] / 1;
				if ((lista[i] / 1) == n)
					lista_impar.push_back(lista[i]);
			}
		}
	}
	
	cout << "b) O total de números pares que foram digitados foi " << lista_par.size() << endl;
	cout << "c) O total de números ímpares que foram digitados foi " << lista_impar.size() << endl;
	cout << "d) O maior número digitado foi " << *max_element(lista.begin(),lista.end()) << endl;
	cout << "e) O menor número digitado foi " << *min_element(lista.begin(),lista.end()) << endl;
	
	float somatoria = 0;
	float produtorio = 1;
	
	//CÁLCULO DA SOMATÓRIA E PRODUTORIO
	for (int i = 0; i < lista.size(); i++) {
		somatoria = somatoria + lista[i];	
		produtorio = produtorio *  lista[i];
	}
	
	cout << "f) A somatória dos números digitados é " << somatoria << endl;
	cout << "g) O produtório dos números digitados é " << produtorio << endl;
	cout << "h) A a média dos números digitados é " << somatoria / lista.size() << endl;
	cout << "i) O maior número par é " << *max_element(lista_par.begin(),lista_par.end()) << endl;
	cout << "j) O menor número ímpar é " << *min_element(lista_impar.begin(),lista_impar.end()) << endl;
	
	float maior_numero = *max_element(lista.begin(),lista.end());
	
	//VERIFICAÇÃO SE MAIOR NÚMERO É PRIMO
	if ( maior_numero!=2 && maior_numero!=3 && maior_numero!=5 && maior_numero!=7)
		if( (maior_numero / 2)==(n = maior_numero / 2) || (maior_numero / 3)==(n = maior_numero / 3) || (maior_numero / 5)==(n = maior_numero / 5) || (maior_numero / 7)==(n = maior_numero / 7) )
			cout << "k) O maior número não é primo" << endl;
		else
			cout << "k) O maior número é primo" << endl;
	else
		cout << "k) O maior número é primo" << endl;
		
	cout << endl;
	
	system ("pause");
	
	return 0;
}