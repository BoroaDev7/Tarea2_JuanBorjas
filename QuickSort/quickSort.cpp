#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int pequeno, int alto)
{
    int pivote = arr[alto];
    int i = (pequeno - 1);

    for (int j = pequeno; j < alto; j++)
    {
        if (arr[j] <= pivote)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int pequeno, int alto)
{
    if (pequeno < alto)
    {
        int pi = partition(arr, pequeno, alto);
        quickSort(arr, pequeno, pi - 1);
        quickSort(arr, pi + 1, alto);
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
    quickSort(arr, 0, (n - 1));
    auto finAlgortimo = steady_clock::now();

    auto totalAlgoritmo = duration<double>(finAlgortimo - inicioAlgortimo).count();
    cout << "Tiempo de ordenamiento: " << totalAlgoritmo << " segundos" << endl;

    delete[] arr;

    auto finTotal = steady_clock::now();
    auto tiempoTotal = duration<double>(finTotal - inicioTotal).count();
    cout << "Tiempo total de ejecucion: " << tiempoTotal << " segundos" << endl;

    return 0;
}
