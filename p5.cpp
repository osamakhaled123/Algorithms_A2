#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int policeThief(char a[], int n, int k)
{
    int result = 0;
    vector<int> thiefIndicies;
    vector<int> policeIndicies;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'P')
        {
            policeIndicies.push_back(i);
        }
        else if (a[i] == 'T')
        {
            thiefIndicies.push_back(i);
        }
    }

    int t = 0, p = 0;

    while (t < thiefIndicies.size() && p < policeIndicies.size())
    {
        if (abs( thiefIndicies[t] - policeIndicies[p] ) <= k)
        {
            result++;
            t++;
            p++;
        }
        else if (thiefIndicies[t] < policeIndicies[p])
        {
            t++;
        }
        else
        {
            p++;
        }
    }

    return result;
}

int main()
{
    int n =0, k =0 ;
    cout << "Please input N and K :" << endl;
    cin >> n >> k ;
    char tmp = ' ';
    char* a = new char[n];
    for (int i=0; i<n ; i++)
    {
        cout << "please input P or T no." <<i+1<<" (Upper Case):" <<endl;
        cin >> tmp;
        if (tmp == 'T' || tmp == 'P')
        {
            a[i] = tmp;
        }
        else
        {
            cout <<"INPUT ERROR"<<endl;
            i--;
        }

        }
        cout << "OUTPUT: " <<policeThief(a,n,k)<<endl;
    delete[] a;
    return 0;
}
