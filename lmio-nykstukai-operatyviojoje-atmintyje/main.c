#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

bool _tikrinimas(long long D, long long P, long long X, const vector<long long>& uzklausa)
{
    //k(P+1)

    long long pas = X*(P+1);  // tik paskutinis judes
    long long delsa = 0;

    for(auto uz : uzklausa)
    {
        if(uz <= pas+P) continue;
        else
        {
            delsa += (uz - (pas+P))*2;
        }

        if(delsa > D) return 0;
    }

    return 1;

} 

void _binarySearch(long long L, long long D, long long P, const vector<long long>& uzklausa)
{
    long long pr = 1, pb = L;

    while(pr < pb)
    {
        long long vid = (pr + pb)/2;

        if(_tikrinimas(D, P, vid, uzklausa)) pb = vid;
        else pr = vid+1;
    }
    cout << L - pb;
}

int main()
{
    long long L, P, D, N;
    cin >> L >> P >> D >> N;

    vector<long long> uzklausa(N);
    
    for(long long i = 0; i < N; i++)
    {
        cin >> uzklausa[i];
    }


    _binarySearch(L, D, P, uzklausa);

    

    return 0;  
}
