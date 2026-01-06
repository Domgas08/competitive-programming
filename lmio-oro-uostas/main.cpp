#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

struct Lektuvas
{
    int t, v, id;
};

bool com (struct Lektuvas a, struct Lektuvas b)
{
    return a.v < b.v;
}

int main()
{
    int n;
    cin >> n;
    vector<Lektuvas> lek(n);
    int maxv = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> lek[i].t >> lek[i].v;
        lek[i].id = i;
        maxv = max(lek[i].v, maxv);
    }

    sort(lek.begin(), lek.end(), com);

    vector<int> kilo_db(maxv, 0), kilo_kiti(maxv, 0);

    for(int i = n-1; i >= 0; i--)
    {
        swap(kilo_db, kilo_kiti);
        for(int u = 0; u < maxv; u++)
        {
            int kyla = -1;
            int nekyla = kilo_kiti[u];  //jeigu nekyla tai pakils daugiausiai lektuvu kiek ir kyla u momentu

            if(lek[i].t+u <= lek[i].v)      //jeigu galim pakilt dabartiniu momentu tai ir kilsim, nes 
            {
                kyla = 1 + kilo_kiti[u+lek[i].t];       //kiek lektuvu gales pakilt po jo (nes uztruks lek[i].t laiko pakilt, o kyla kai u laiko momentu
            }
            kilo_db[u] = max(kyla, nekyla);
        }
        
    }

    cout << kilo_db[0];

    
    return 0;  
}
