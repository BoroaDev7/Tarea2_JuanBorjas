#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {

            if (array[i] < array[min_idx])
                min_idx = i;
        }

        swap(&array[min_idx], &array[step]);
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
    selectionSort(arr, n);
    auto finAlgortimo = steady_clock::now();

    auto totalAlgoritmo = duration<double>(finAlgortimo - inicioAlgortimo).count();
    cout << "Tiempo de ordenamiento: " << totalAlgoritmo << " segundos" << endl;

    delete[] arr;

    auto finTotal = steady_clock::now();
    auto tiempoTotal = duration<double>(finTotal - inicioTotal).count();
    cout << "Tiempo total de ejecucion: " << tiempoTotal << " segundos" << endl;

    return 0;
}
