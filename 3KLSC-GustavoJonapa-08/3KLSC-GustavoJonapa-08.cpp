#include <iostream>
#define MaxTamC 10

typedef int TipoDato;
using namespace  std;

int main() {
    int frente = 0, final = 0;
    TipoDato A[MaxTamC];

    int contador = 0;
    char respuesta;

    // Inicializar la cola
    cout << "Desea agregar elementos a la cola? (s/n): ";
    cin >> respuesta;

    while ((respuesta == 's' || respuesta == 'S') && contador < MaxTamC) {
        if ((final + 1) % MaxTamC == frente) {
            cout << "Desbordamiento de la cola" << endl;
            return 1;
        }

        cout << "Ingrese un elemento para la cola: ";
        TipoDato elemento;
        cin >> elemento;

        A[final] = elemento;
        final = (final + 1) % MaxTamC;
        contador++;

        cout << "Elemento " << contador << " agregado a la cola: " << elemento << endl;

        if (contador < MaxTamC) {
            cout << "Desea agregar más elementos a la cola? (s/n): ";
            cin >> respuesta;
        }
    }

    // Validar si la cola está vacía
    if (frente == final) {
        cout << "La cola está vacía." << endl;
        return 1;
    }

    // Obtener el primer elemento de la cola
    TipoDato primerElemento = A[frente];
    cout << "El primer elemento de la cola es: " << primerElemento << endl;

    // Eliminar un elemento de la cola
    frente = (frente + 1) % MaxTamC;

    // Imprimir elementos de la cola en el orden en que fueron ingresados
    cout << "Elementos de la cola en el orden de ingreso: " << endl;
    for (int i = frente; i != final; i = (i + 1) % MaxTamC) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}