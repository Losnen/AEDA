#pragma once
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Inserción

template <class T>
void Insercion(vector<T>& sec, bool demos)
{
    for(int i = 1; i < sec.size(); i++)
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
            cout << "Comparando: " << sec[j] << " " << x << endl;
        }
    
        sec[j] = x;
    
        if(demos)
        {
            cout << "Secuencia: ";
            for(int k = 0; k < sec.size(); k++) 
                cout << sec[k] << " ";
                
                cout << endl;
        }
    }
    sec[-1] = 0;
}

//BubbleSort

template <class T>
void BubbleSort(vector<T>& sec, bool demos)
{
    int x = 0;
    for (int i = 1; i < sec.size(); i++)
    { 
        for (int j = sec.size()-1; j >= i; j--)
        {
            if (sec[j] < sec[j-1])
            {
                if(demos)
                {
                    cout << "Comparando: " << sec[j] << " " << sec[j-1] << endl;
                }
                x = sec[j-1];
                sec[j-1] = sec[j];
                sec[j] = x;
                if(demos)
                {
                    cout << "Secuencia: ";
                    for(int k = 0; k < sec.size(); k++) 
                        cout << sec[k] << " ";
                        
                    cout << endl;
                }
            }
        }
    }
}

//Funciones del SellSort

template <class T>
void deltasort(int d, vector<T>& sec, int n, bool dem)
{ 
    T x = 0;
    int j = 0;

    for(int i = d; i < n; i++)
    {
        x = sec[i];
        j = i;
        while((j > (d - 1)) && ( x < sec[j-d]))
        {
            sec[j] = sec[j-d];
            j = (j-d);
        }
        if(dem && (sec[j] != x))
        {
            cout << "Comparando: " << sec[j] << " " << x << endl;
        }

        if(sec[j] != x)
        {
            sec[j] = x;
            if(dem)
            {
	            cout << "Secuencia: ";
	            for(int k=0; k < sec.size(); k++) 
	                cout << sec[k] << " "; 
	                
	           cout << endl;
            }
        }
    }
}

template <class T>
void ShellSort(vector<T>& sec, bool demos, int alpha)
{
    int del = sec.size();
    while (del > alpha)
    { 
        del = del / 2 ;
        deltasort(del,sec,sec.size(),demos);
    }
}

//QuickSort https://ronnyml.wordpress.com/2009/07/19/quicksort-en-c/

template <class T>
int Divide(vector<T>& sec, int ini, int fin, bool demos)
{
    int left;
    int right;
    int pivot;
    int temp;
 
    pivot = sec[ini];
    left = ini;
    right = fin;
 
    while (left < right) 
    {
        while (sec[right] > pivot) 
        {
            right--;
        }
 
        while ((left < right) && (sec[left] <= pivot)) 
        {
            left++;
        }
 
        if (left < right) 
        {
            temp = sec[left];
            sec[left] = sec[right];
            sec[right] = temp;
        }
    }
 
    temp = sec[right];
    sec[right] = sec[ini];
    sec[ini] = temp;
    
    return right;
}

template <class T>
void QuickSort(vector<T>& sec, bool demos, int ini, int fin)
{
    int pivot;
 
    if (ini < fin) 
    {
        pivot = Divide(sec, ini, fin, demos);
        QuickSort(sec, demos, ini, pivot - 1);
        QuickSort(sec, demos, pivot + 1, fin);
    }
}

//Funciones de MergeSort

template <class T>
void mezcla(vector<T>& sec,vector<T> U,vector<T> V, bool demos)
{
    int i = 0;
    int j = 0;

    if(demos)
    {
        cout << "Comparando: "<< endl;
        cout << "U: ";
        for(int m = 0; m < U.size(); m++) 
            cout << U[m] << " "; 
        cout << "V: ";
        for(int m = 0; m < V.size(); m++) 
            cout << V[m] << " "; 
            
        cout << endl;
    }

    for(int k = 0; k < sec.size(); k++)
    {
        if((i < U.size()) && (j < V.size()))
        {
            if(U[i] < V[j])
            {
	            sec[k] = U[i];
	            i++;
            }
            else
            {
	            sec[k] = V[j];
	            j++;

            }
        }
        else
        {
            if(i >= U.size())
            {
        	    sec[k] = V[j];
	            j++;
            }
            else
            {
	            if(j >= V.size())
	            {
	                sec[k] = U[i];
	                i++;
	            }
            }
        }
    }

    if(demos)
    {
        cout << "Secuencia: ";
        for(int m = 0; m < sec.size(); m++) 
            cout << sec[m] << " "; 
        
        cout << endl;
    }

}

template <class T>
void MergeSort(vector<T>& sec, bool demos)
{
    if(sec.size() > 1)
    {
        vector<T> U(sec.begin(),(sec.begin()+sec.size()/2));
        vector<T> V((sec.begin()+sec.size()/2), sec.end());

        MergeSort(U, demos);
        MergeSort(V, demos);
        mezcla(sec,U,V,demos);
    }
}

//Funciónes de Estadística y Desmotración

template <class T>
void Estadisticas(void)
{
    
}

template <class T>
void Demostraciones(void)
{
    
    int op = -1;
    int n = 0;
    srand(time(NULL));
    cout << "Introduzca el tamaño de la secuencia a ordenar (Numero entre: 1 y 25): ";
    cin >> n;
    
    vector<T> Demostracion(n,0);
    for(int i = 0; i < n ; i++)
    {
        Demostracion[i] = rand() % 30000000+50000000;
    }
    
    cout << "Tipos de Algoritmos: " << endl;
    cout << "0.Inserción" << endl;
    cout << "1.BubbleSort" << endl;
    cout << "2.ShellSort" << endl;
    cout << "3.QuickSort" << endl;
    cout << "4.MergeSort" << endl;
    cout << "Elija una opción (0-4): ";
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
            ShellSort(Demostracion,true,0.5);
        break;
        case 3:
            QuickSort(Demostracion,true,0,Demostracion.size()-1);
        break;
        case 4:
            MergeSort(Demostracion,true);
        break;
    }
    
    cout << "Secuencia ordenada: ";
    for(int i = 0; i < Demostracion.size(); i++) 
        cout << Demostracion[i] << " "; 
        
    cout << endl;
}