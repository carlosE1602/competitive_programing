#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stdlib.h>

using namespace std;

priority_queue<int> heapMenor, heapMaior;

void balanceia()
{
    int valor = (heapMenor.size() - heapMaior.size());
    if (abs(valor) <= 1)
        return;
    // caso nao estiver, devemos tirar o top do que tem mais elementos e colocar no outro
    if (heapMaior.size() > heapMenor.size())
    {
        heapMenor.push(-heapMaior.top());
        heapMaior.pop();
    }
    else
    {
        heapMaior.push(-heapMenor.top());
        heapMenor.pop();
    }
}

int getMediana()
{
    if (heapMenor.size() != heapMaior.size())
    {
        if (heapMenor.size() > heapMaior.size())
            return heapMenor.top();
        else
            return -heapMaior.top();
    }
    // senao retorna a media dos dois topos
    return (heapMenor.top() - heapMaior.top()) / 2;
}

void solve()
{
    int testCase, n;
    cin >> testCase >> n;

    string aux;
    int cont = 0;
    vector<int> values;
    vector<int> medianas;
    while (cont != n)
    {
        cin >> aux;
        stringstream ss(aux);

        int el;
        while (ss >> el)
        {
            if (heapMenor.size() == 0 && heapMaior.size() == 0)
            {
                heapMenor.push(el);
            }
            else
            {
                el <= heapMenor.top() ? heapMenor.push(el) : heapMaior.push(-el);
            }
            balanceia();
            cont++;
            if ((cont) % 2 != 0)
            {
                int aux = getMediana();
                medianas.push_back(aux);
            }
        }

        // cout << values.size();
    }

    cout << testCase << " " << n / 2 + 1 << "\n";
    for (int i = 0; i < medianas.size(); i++)
    {
        cout << medianas[i];
        if (i == medianas.size() - 1 || (i + 1) % 10 == 0)
            cout << "\n";
        else
            cout << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        priority_queue<int> aux;
        heapMaior = aux;
        heapMenor = aux;
        solve();
    }
}