#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(int array[], int size)
{

    for (int step = 0; step < size; ++step)
    {
        for (int i = 0; i < size - step; ++i)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
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
    bubbleSort(arr, n);
    auto finAlgortimo = steady_clock::now();

    auto totalAlgoritmo = duration<double>(finAlgortimo - inicioAlgortimo).count();
    cout << "Tiempo de ordenamiento: " << totalAlgoritmo << " segundos" << endl;

    delete[] arr;

    auto finTotal = steady_clock::now();
    auto tiempoTotal = duration<double>(finTotal - inicioTotal).count();
    cout << "Tiempo total de ejecucion: " << tiempoTotal << " segundos" << endl;

    return 0;
}
