#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void heapify(int arr[], int n, int i)
{
    int largo = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    if (izquierda < n && arr[izquierda] > arr[largo])
        largo = izquierda;

    if (derecha < n && arr[derecha] > arr[largo])
        largo = derecha;

    if (largo != i)
    {
        swap(arr[i], arr[largo]);
        heapify(arr, n, largo);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main(int argc, char *argv[])
{
    cout << "Buenas ingeniero\n"
         << endl;
    if (argc < 2)
    {
        cout << "Ingrese los argumentos correctos, debe ingresar un numero despues del nombre del exe" << endl;
        return 1;
    }

    auto inicioTotal = steady_clock::now();

    int n = atoi(argv[1]);
    int *arr = new int[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    auto inicioAlgortimo = steady_clock::now();
    heapSort(arr, n);
    auto finAlgortimo = steady_clock::now();

    auto totalAlgoritmo = duration<double>(finAlgortimo - inicioAlgortimo).count();
    cout << "Tiempo de ordenamiento: " << totalAlgoritmo << " segundos" << endl;

    delete[] arr;

    auto finTotal = steady_clock::now();
    auto tiempoTotal = duration<double>(finTotal - inicioTotal).count();
    cout << "Tiempo total de ejecucion: " << tiempoTotal << " segundos" << endl;

    return 0;
}
