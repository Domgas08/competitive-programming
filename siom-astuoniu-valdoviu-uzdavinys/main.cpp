#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

vector<vector<char>> mapas;
int kiek = 0;


bool _galimaDet(pair<int, int> a, vector<pair<int, int>>& karal)
{
    int y1 = a.first, x1 = a.second;

    for(auto &[y2, x2] : karal)
    {
        if(x1 == x2 || y1 == y2) return 0;

        double k = double(y1-y2) / double(x1-x2);       //kx + b = y

        if(k == 1 || k == -1) return 0;
    }

    return 1;
}



void _ispausti(vector<pair<int, int>>& karal, int n)
{
    mapas.resize(n, vector<char>(n, '.'));

    for(auto &[i, j] : karal)
    {
        mapas[i][j] = 'V';
    }

}




void _karalienes(int const n, int i, vector<pair<int, int>>& karal)       //kiekviena atskiroj eilutej
{

    if(i == n)
    {
        kiek ++;
        if(mapas.empty()) _ispausti(karal, n);
        return;
    }



    for(int j = 0; j < n; j++)
    {
        if(_galimaDet(make_pair(i, j), karal))
        {
            karal.push_back(make_pair(i, j));
            _karalienes(n, i+1, karal);
            karal.pop_back();
        }

    }
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> karal;

    _karalienes(n, 0, karal);

    cout << kiek << endl;

    if(kiek == 0) return 0;

    for(auto i : mapas)
    {
        for (auto j : i) cout << j;
        cout << endl;
    }

    return 0;
}
