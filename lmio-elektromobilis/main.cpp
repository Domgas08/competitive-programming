#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct miestas
{
    int m;
    int e;
};

int main()
{
    int n, M, k, l;             //
    cin >> n >> M >> k >> l;

    vector<int> c(n+1);                 //kaip greit pakrauna

    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    vector<vector<int>> a (n+1);        //pasiekiamia miestai nuo i - tojo miesto

    for(int i = 0; i < M; i++)
    {
        int laik1, laik2;
        cin >> laik1 >> laik2;
        a[laik1].push_back(laik2);
        a[laik2].push_back(laik1);

    }

    vector<vector<int>> t(n+1, vector<int> (k+1, INT_MAX));         //INT_MAX reiskia dar nesilankeme toje vietoje. Visur if ziurim ar ne INT_MAX kad zinotume ar reik tikrint ta situacija ar jau jis patikrintas
                                                                    //t[m][e] saugo per kiek maziausiai laiko (tai pirmas pasitaikes t masyvo pakeitimas) galima buti mieste m su e elektros

    queue<miestas> q;
    q.push(miestas{1, 0});

    t[1][0] = 0;

    while(!q.empty())
    {
        int e = q.front().e;        //dabar turim e eletkros
        int m = q.front().m;        //esame m mieste
        q.pop();

        int ne = min(e+c[m], k);    //pakraunam viena h elektros
        if(t[m][ne] == INT_MAX)     //vaziuojam i ta pati miesta (pakraunam bet turim kitoki kieki elektros
        {
            t[m][ne] = t[m][e] + 1; //pridedam pakrovima
            q.push(miestas{m, ne}); //siunciam dar kart kad is to pacio m miesto su +1 valanda ir su atitinkamai elektros vaziuotume kur nors
        }


        if(e >= l)
        {
            for(auto nm : a[m])             //jeigu uztenka elektros vienam vaziavimui, tai vaziuojam i kitus mietus (visus variantus issiunciam
            {
                if(t[nm][e-l] == INT_MAX)   //jeigu dar nebuvom naujam mieste su tam tikru kiekiu elektros, tikrinam nauja varianta
                {
                    t[nm][e-l] = t[m][e] + 1;   //pridedam keliones ilguma +1 valanda prie laiko
                    q.push(miestas{nm, e-l});
                }
            }
        }


    }



    int ats = INT_MAX;
    for(int e = 0; e <= k; e++)     //mieste n galim buti su skirtingais energijos kiekiais, tad reik paziuret visus variantus ir pasiimt ta, kuris uztruko trumpiausiai
    {
        ats = min(ats, t[n][e]);
    }

    if(ats == INT_MAX) cout << -1;
    else cout << ats;




    return 0;
}
