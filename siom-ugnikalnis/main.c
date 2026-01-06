#include<bits/stdc++.h>

using namespace std;

long long int circle(long long int x1, long long int y1, long long int x2, long long int y2, long long int r1, long long int r2);

struct Circle
{
    long long int x;
    long long int y;
    long long int r;
    bool v;
    bool a;
    bool k;
    bool d;

};


bool _jungias(struct Circle a, struct Circle b)
{
    double d = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));



    return (d <= a.r +b.r);

}

void _jungiamLavas(vector<vector<long long int>>& mapas, vector<struct Circle>& lavos)
{
    for(long long int i = 0; i < lavos.size(); i++)
    {
        for(long long int j = 0; j < i; j++)
        {
            if(_jungias(lavos[i], lavos[j]))
            {
                //cout << "aaa";
                mapas[i].push_back(j);
                mapas[j].push_back(i);
            }
        }
    }


}

bool LINIJA;

void _dfs(vector<bool>& buvo, vector<vector<long long int>>& mapas, long long int id, const vector<struct Circle>& lavos)
{
    if(buvo[id] == 1) return;
    buvo[id] = 1;

    if(lavos[id].d || lavos[id].a)
    {
        LINIJA = 1;
    }


    for(auto node : mapas[id])
    {
        if(buvo[node] == 0)
        {
            _dfs(buvo, mapas, node, lavos);
        }

    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long int T;
    cin >> T;



    for(long long int t = 0; t < T; t++)
    {
        long long int K, W, H;
        cin >> K >> W >> H;
        vector<Circle> lavos(K);
        vector<long long int> kairi_id, virsus_id;
        for(long long int k = 0; k < K; k++)
        {
            cin >> lavos[k].x >> lavos[k].y >> lavos[k].r;

            if(lavos[k].x - lavos[k].r <= 0)    //kaire
            {
                lavos[k].k = 1;
                kairi_id.push_back(k);
            }
            else lavos[k].k = 0;

            if(lavos[k].x + lavos[k].r >= W)        //desine
            {
                lavos[k].d = 1;
            }
            else lavos[k].d = 0;


            if(lavos[k].y + lavos[k].r >= H)        //virsus
            {
                lavos[k].v = 1;
                virsus_id.push_back(k);
            }
            else lavos[k].v = 0;

            if(lavos[k].y - lavos[k].r <= 0)        //apacia
            {
                lavos[k].a = 1;
            }
            else lavos[k].a = 0;
        }

        vector<vector<long long int>> mapas(K+1);
        _jungiamLavas(mapas, lavos);

        vector<bool> tikrinti(K, 0);

        long long int c = 0;

        for(long long int i = 0; i < kairi_id.size(); i++)                  ///is kaires puses
        {
            long long int id = kairi_id[i];
            if(tikrinti[id] == 0)
            {

                //cout << "KAIRES"  << lavos[id].d << endl;

                LINIJA = 0;
                _dfs(tikrinti, mapas, id, lavos);
                if(LINIJA) c++;
            }
        }



        for(long long int i = 0; i < virsus_id.size(); i++)                 ///is virsaus
        {
            long long int id = virsus_id[i];
            if(tikrinti[id] == 0)
            {

                //cout << "KAIRES"  << lavos[id].d << endl;

                LINIJA = 0;
                _dfs(tikrinti, mapas, id, lavos);
                if(LINIJA) c++;
            }
        }
        cout << c << '\n';




    }



    return 0;


}
