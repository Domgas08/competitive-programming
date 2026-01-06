#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <queue>
#include <set>

//0 draugas yra linas

//       1   2   3   4
// Lino  0   0   0   0
// pirmo 0   0   0   0
// antro 0   0   0   0

using namespace std;

void _darbas (vector<vector<int>> a)
{
    set<int> piesta;

    int n = a.size();
    queue<int> q;

    for(int i = 1; i < n; i++)
    {
        if(a[0][i] == 1)
        {
            q.push(i);
            piesta.insert(i);
        }
    }


    while(!q.empty())
    {
        int id = q.front();
        q.pop();

        for(int i = 0; i < n; i++)
        {
            if(a[id][i] == 1 && piesta.find(i) == piesta.end())
            {
                q.push(i);
                piesta.insert(i);
            }

        }

    }

    cout << piesta.size();

}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n+1, vector<int>(n+1, 0));   //0 - nedraugas    1 - draugas   2 - nupiesta jau

    for (int i = 0; i < m; i++)
    {
        int laik;
        cin >> laik;
        a[0][laik] = 1;
    }

    for (int i = 0; i < k; i++)
    {
        int laik1, laik2;
        cin >> laik1 >> laik2;
        a[laik1][laik2] = 1;
        a[laik2][laik1] = 1;
    }

    _darbas(a);


    return 0;
}
