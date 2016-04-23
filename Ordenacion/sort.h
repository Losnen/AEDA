#pragma once
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Inserción

template <class T>
void Insercion(vector<T>& sec, bool demos, int& cnt)
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
            cnt++;
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
void BubbleSort(vector<T>& sec, bool demos, int& cnt)
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
                cnt++;
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
void deltasort(int d, vector<T>& sec, int n, bool demos, int& cnt)
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
            cnt++;
        }
        if(sec[j] != x)
        {
            if(demos)
            {
                cout << "Comparando: " << sec[j] << " " << x << endl;
            }
            sec[j] = x;
            if(demos)
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
void ShellSort(vector<T>& sec, bool demos, float alpha, int& cnt)
{
    int del = alpha * sec.size();
    while (del >= 1)
    { 
        del = del / 2;
        deltasort(del,sec,sec.size(),demos,cnt);
    }
}

//QuickSort https://ronnyml.wordpress.com/2009/07/19/quicksort-en-c/

template <class T>
int Divide(vector<T>& sec, int ini, int fin, bool demos, int& cnt)
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
            cnt++;
        }
 
        while ((left < right) && (sec[left] <= pivot)) 
        {
            left++;
            cnt++;
        }
        
        
        if (left < right) 
        {
            
            temp = sec[left];
            sec[left] = sec[right];
            sec[right] = temp;
        }
    }
    
    if(demos)
    {
        cout << "Elementos comparados: " << sec[ini] << " " << sec[right] << endl;
    }
    temp = sec[right];
    sec[right] = sec[ini];
    sec[ini] = temp;
    
    if(demos)
    {
        cout << "Secuencia tras comparación: ";
        for(int j2=0;j2<sec.size();j2++) 
            cout << sec[j2] << " "; 
        
        cout << endl;
    }
    
    return right;
}

template <class T>
void QuickSort(vector<T>& sec, bool demos, int ini, int fin, int& cnt)
{
    int pivot;
 
    if (ini < fin) 
    {
        pivot = Divide(sec, ini, fin, demos,cnt);
        QuickSort(sec, demos, ini, pivot - 1,cnt);
        QuickSort(sec, demos, pivot + 1, fin,cnt);
    }
}

//Funciones de MergeSort

template <class T>
void mezcla(vector<T>& sec,vector<T> U,vector<T> V, bool demos, int& cnt)
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
	            cnt++;
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
void MergeSort(vector<T>& sec, bool demos, int& cnt)
{
    if(sec.size() > 1)
    {
        vector<T> U(sec.begin(),(sec.begin()+sec.size()/2));
        vector<T> V((sec.begin()+sec.size()/2), sec.end());

        MergeSort(U, demos, cnt);
        MergeSort(V, demos, cnt);
        mezcla(sec,U,V,demos, cnt);
    }
}

//Funciónes de Estadística y Desmotración

template <class T>
void Estadisticas(void)
{
    cout << "Modo estadística" << endl;
    int p = 0;
    int n = 0;
    srand(time(NULL));
    cout << "Introduzca el tamaño de la secuencia a ordenar: ";
    cin >> n;
    cout << "Introduzca el número de pruebas que se ejecutarán sobre cada método: ";
    cin >> p;
    
    vector< vector<T> > Estadistica(p, vector<T> (n,0));
    
    for(int j = 0; j < p; j++)
    {
        for(int k = 0; k < n; k++) 
            Estadistica[j][k] = rand() % 30000000+50000000;
    }
    vector<T> aux;

    vector<int> no(5,0);
    vector<int> max(5,0);
    vector<int> min(5,999999999);
    vector< vector<double> > cont(5,vector<double> (p,0.0));
    vector<double> med(5,0);

    for(int i = 0; i < p; i++)
    {
        aux = Estadistica[i];

        Insercion(aux,false,no[0]);
        aux = Estadistica[i];

        BubbleSort(aux,false, no[1]);
        aux = Estadistica[i];

        ShellSort(aux,false,0.5,no[2]);
        aux = Estadistica[i];

        QuickSort(aux,false,0,Estadistica[i].size()-1,no[3]);
        aux = Estadistica[i];
        
        MergeSort(aux,false,no[4]);
        aux = Estadistica[i];

        for(int j = 0; j < 5; j++)
        {
            if(no[j] < min[j]) 
                min[j] = no[j];
            
            if(no[j] > max[j]) 
                max[j] = no[j];
            
            cont[j][i] = no[j];
            no[j] = 0;
        }

    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < p; j++)
        {
            med[i]+= cont[i][j];
        }
        med[i] = (med[i]/p);
    }


    cout << setw(40) << "Número de comparaciones" << endl;
    cout << " " <<  setw(24) << "Mínimo"; cout << setw(15) << "Medio"; cout << " " << setw(15) << "Máximo" << endl;
    cout << "Inserción" << setw(15) << min[0]; cout << setw(15) << med[0]; cout << setw(15) << max[0] << endl;
    cout << "BubbleSort" << setw(14) << min[1]; cout << setw(15) << med[1]; cout << setw(15) << max[1] << endl;
    cout << "ShellSort" << setw(15) << min[2]; cout << setw(15) << med[2]; cout << setw(15) << max[2] << endl;
    cout << "QuickSort" << setw(15) << min[3]; cout << setw(15) << med[3]; cout << setw(15) << max[3] << endl;
    cout << "MergeSort" << setw(15) << min[4]; cout << setw(15) << med[4]; cout << setw(15) << max[4] << endl;
    cout << endl;
}

template <class T>
void Demostraciones(void)
{
    cout << "Modo demostracion" << endl;
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
    
    int flag = 0;
    switch(op)
    {
        case 0:
            Insercion(Demostracion,true,flag);
        break;
        case 1:
            BubbleSort(Demostracion,true,flag);
        break;
        case 2:
            ShellSort(Demostracion,true,0.5,flag);
        break;
        case 3:
            QuickSort(Demostracion,true,0,Demostracion.size()-1,flag);
        break;
        case 4:
            MergeSort(Demostracion,true,flag);
        break;
    }
    
    cout << "Secuencia ordenada: ";
    for(int i = 0; i < Demostracion.size(); i++) 
        cout << Demostracion[i] << " "; 
        
    cout << endl;
}