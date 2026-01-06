#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define loop(x) for (int i = 0; i < x; i++)

void _skurzdziuKritimas(vector<int> &kair, vector<int> &des) // kris nuo galo vectoriaus
{
    int t = 0;
    int bvt = 0;

    int K = kair.size(), D = des.size();
    int DD = D, KK = K;
    int k = 1, d = 1; // kuris nera nugrauztas (ant k arba d dar galimna stovet)

    //cout << des[D - 1] << endl;

    int TD = ceil((des[D - 1] - d + 1) / double(K)), TK = ceil((kair[K - 1] - k + 1 )/ double(D)); // kritimo laikai

/*     cout << KK - K << ": " << TK << "    " << DD - D << ": " << TD << endl
         << endl; */

    while (!kair.empty() && !des.empty())
    {
        bvt = t;

        if (TD == TK)
        {

            t += TD;

            k += D * (t - bvt);
            d += K * (t - bvt);

            D--;
            des.pop_back();

            while (!des.empty() && des[D - 1] < d)
            {
                D--;
                des.pop_back();
            }

            K--;
            kair.pop_back();

            while (!kair.empty() && kair[K - 1] < k)
            {
                K--;
                kair.pop_back();
            }

            if (!des.empty())
                TD = ceil((des[D - 1] - d + 1) / double(K));
            if (!kair.empty())
                TK = ceil((kair[K - 1] - k + 1 )/ double(D)); 
        }
        else if (TD < TK)
        {

            t += TD;

            k += D * (t - bvt);
            d += K * (t - bvt);

            D--;
            des.pop_back();

            while (!des.empty() && des[D - 1] < d)
            {
                D--;
                des.pop_back();
            }

            if (!des.empty())
                TD = ceil((des[D - 1] - d + 1) / double(K));
            if (!kair.empty())
                TK = ceil((kair[K - 1] - k + 1 )/ double(D)); 
        }
        else
        {

            t += TK;

            k += D * (t - bvt);
            d += K * (t - bvt);

            K--;
            kair.pop_back();

            while (!kair.empty() && kair[K - 1] < k)
            {
                K--;
                kair.pop_back();
            }

            if (!des.empty())
                TD = ceil((des[D - 1] - d + 1) / double(K));
            if (!kair.empty())
                TK = ceil((kair[K - 1] - k + 1 )/ double(D)); 
        }

    }

    if (kair.empty() && des.empty())
        cout << t << "\nL";
    else if (!kair.empty())
        cout << t << "\nK";
    else
        cout << t << "\nD";
}

int main()
{
     vector<int> a(5, 10);
    for(auto i = a.begin(); i < a.end(); i++)
    {
        cout << *i;
    } 

    map<int, string> mapas;

    return 0;
    int K, D;

    cin >> K >> D;

    vector<int> kair(K), des(D);

    loop(K)
    {
        cin >> kair[i];
    }

    loop(D)
    {
        cin >> des[i];
    }

    reverse(kair.begin(), kair.end());
    reverse(des.begin(), des.end());

    _skurzdziuKritimas(kair, des);

    return 0;
}




