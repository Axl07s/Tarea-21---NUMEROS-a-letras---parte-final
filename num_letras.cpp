// Autor: Axel Molineros
// Fecha: 2024-07-24
// 1) Utilice el programa de conversión de NUMEROS a LETRAS realizado en clases
// y complete hasta el número 999.999.999

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

//Define el vector
const string unidades[]={"cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez","once","doce","trece","catorce","quince","dieciséis","diecisiete","dieciocho","diecinueve"};
//Define el vector
const string decenas[]={"","diez","veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};
//Define el vector
const string centenas[]={"","ciento","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"};

// Devuelve las unidades del array de string
string GetUnidades(int num) {
    return unidades[num];
}

// Devuelve las decenas del array de string
string GetDecenas(int num) {
    int x = num / 10;
    int z = num % 10;
    if (num < 20)
        return GetUnidades(num);
    else
        return decenas[x] + (z > 0 ? " y " + GetUnidades(z) : "");
}

// Devuelve las centenas del array de string
string GetCentenas(int num) {
    int x = num / 100;
    int z = num % 100;
    if (num < 100)
        return GetDecenas(num);
    else
        return (num == 100 ? "cien" : centenas[x]) + (z > 0 ? " " + GetDecenas(z) : "");
}

// Devuelve los miles utilizando las funciones ya definidas
string GetMiles(int num) {
    int x = num / 1000;
    int z = num % 1000;
    if (num < 1000)
        return GetCentenas(num);
    else
        return (x == 1 ? "mil" : GetCentenas(x) + " mil") + (z > 0 ? " " + GetCentenas(z) : "");
}

// Devuelve los millones utilizando las funciones ya definidas
string GetMillones(int num) {
    int x = num / 1000000;
    int z = num % 1000000;
    if (num < 1000000)
        return GetMiles(num);
    else
        return GetCentenas(x) + " millones" + (z > 0 ? " " + GetMiles(z) : "");
}

// Genera 100 números aleatorios y los convierte a letras
void GenerarNumerosAleatorios() {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int num = rand() % 999999999 + 1;
        string resultado = GetMillones(num);
        cout << num << " en letras es " << resultado << endl;
    }
}

int main() {
    int num = 900;
    string resultado = GetCentenas(num);
    cout << endl << num << " en letras es " << resultado << endl;

    for (int k = 1; k < 1000; k++) {
        string aux = GetCentenas(k);
        cout << endl << k << ":" << aux;
    }

    cout << endl << "Generando 100 números aleatorios:" << endl;
    GenerarNumerosAleatorios();

    return 0;
}
