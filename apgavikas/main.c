#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;
int main()
{



    set<int> mire;
    int n, m;
    cin >> n >> m;
    vector<int> zud(n);         //i-taji rounda zudo a[i] zmogu

    vector<bool> zino(n, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> zud[i];
        zud[i]--;
    }

    for(int i = 0; i < n; i++)
    {

        vector<int> zm(n);        //itasis zmogus yra a[i] kambaryje
        vector<set<int>> kamb(m); //itajam kambaryje, set<int> zmones



        for(int j = 0; j < n; j++)
        {
            int laik;
            cin >> zm[j];
            zm[j]--;
            kamb[zm[j]].insert(j);
        }

        mire.insert(zud[i]);
        int kambarys = zm[zud[i]];

        int zinosk = 0;

        for(auto zmones : kamb[kambarys])
        {
            zino[zmones] = 1;
        }



        for(int zmones = 0; zmones < zino.size(); zmones++)
        {
            if(zino[zmones] == 1 && mire.find(zmones) == mire.end()) zinosk++;
        }

        int nezinosk = n - mire.size() - zinosk + 1;        //+1 nes pats apgavikas irgi gali balsuot



        if(zinosk > nezinosk)
        {
            cout << i+1;
            return 0;
        }
    }


    cout << n;

    return 0;
}
