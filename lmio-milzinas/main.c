#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>

using namespace std;


void _keistenis(const string& visas, vector<bool>& deg)
{
    auto p = visas.find('L');
    
    while(p != string::npos)
    {

        deg[p] = 1;
        int c = p-1;

        while(c >= 0 && visas[c] == 'D')     //i kaire turi but DDDDD
        {
            deg[c] = 1;
            c--;

        }

        c = p+1;

        while(c < visas.length() && visas[c] == 'K')     //i desine turi but KKKKK
        {
            deg[c] = 1;
            c++;
        }

        p = visas.find('L', p+1);
        
    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> deg(n, 0);

    string visas;
    cin >> visas;

    _keistenis(visas, deg);

    int kiek = 0;

    for(int i = 0; i < m; i++)
    {
        int sk;
        cin >> sk;
        sk--;

        if(deg[sk] == 0) kiek++;
    }
    cout << kiek;

    return 0;
}
