#pragma once
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <class T>
void Insercion(vector<T> sec, bool demos)
{
    int aux = 1;
    for(int i = 1; i <= sec.size(); i++)
    {
        int j = i;
        T x = sec[i];
        sec[-1] = x;
    
        while(x < sec[j-1])	
        {
            sec[j] = sec[j-1];
            j--;
        }
        if(demos)
        {
            cout << "Iteracion: " << aux << endl;
            cout << "Elementos comparados: " << sec[j] << " " << x << endl;
            aux++;
        }
    
        sec[j] = x;
    
        if(demos)
        {
            cout << "Secuencia tras comparación: ";
            for(int k = 0; k < sec.size(); k++) 
                cout << sec[k] << " ";
                
                cout << endl;
        }
    }
    sec[-1] = 0;
}

template <class T>
void BubbleSort(vector<T> sec, bool demos)
{
    
}

template <class T>
void ShellSort(vector<T> sec, bool demos)
{
    
}

template <class T>
void QuickSort(vector<T> sec, bool demos)
{
    
}

template <class T>
void MergeSort(vector<T> sec, bool demos)
{
    
}

template <class T>
void Estadisticas(vector<T> sec)
{
    
}

template <class T>
void Demostraciones(void)
{
    
    int op = -1;
    int n = 0;
    srand(time(NULL));
    cout << "Introduzca el tamaño de la secuencia a ordenar: ";
    cin >> n;
    
    vector<T> Demostracion(n,0);
    for(int i = 0; i< 25; i++)
    {
        Demostracion[i] = rand() % 30000000+50000000;
    }
    
    cout << "Introduzca qué algoritmo de ordenación desea ejecutar:" << endl;
    cout << "0.Inserción" << endl;
    cout << "1.BubbleSort" << endl;
    cout << "2.ShellSort" << endl;
    cout << "3.QuickSort" << endl;
    cout << "4.MergeSort" << endl;
    cin >> op;
    
    switch(op)
    {
        case 0:
            Insercion(Demostracion,true);
        break;
        case 1:
            BubbleSort(Demostracion,true);
        break;
        case 2:
            ShellSort(Demostracion,true);
        break;
        case 3:
            QuickSort(Demostracion,true);
        break;
        case 4:
            MergeSort(Demostracion,true);
        break;
    }
}