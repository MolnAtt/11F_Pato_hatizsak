
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    
    int N, K;


    cin >> N >> K;
    vector<int> suly(N);
    vector<int> ertek(N);
    for (size_t i = 0; i < N; i++)
        cin >> suly[i];

    for (size_t i = 0; i < N; i++)
        cin >> ertek[i];

    vector<vector<int>> m(N,vector<int>(K,0));

    /**/
    // elsõ sor feltöltése: ha belefér az elsõ tárgy a hátizsákba, akkor bevesszük, egyébként meg nem.
    for (size_t j = 0; j < K; j++)
        m[0][j] = suly[0] <= K ? ertek[0] : 0;
    /**/

    /**/

    // második sortól az összes
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            // össze kell hasonlítani az új tárgy adta lehetõségeket a tárgy nélküli (elõzõ sor! i-1!) lehetõségekkel
            // m[i-1] // tárgy nélküli lehetõség
//          m[i][j] = 0 > j - suly[i] ? m[i - 1][j] : (m[i - 1][j - suly[i]] < m[i - 1][j]? m[i - 1][j]: m[i - 1][j - suly[i]]);
            
            if (0 <= j - suly[i])
            {
                //                cerr << "if: idaig eljutottam" << i << " " << j << " " << suly[i] << " j-suly[i] :" << j - suly[i];
                cerr << (m[i - 1][j] < m[i - 1][j - suly[i]]);
                if (m[i - 1][j] < m[i - 1][j - suly[i]])
                {
                    m[i][j] = m[i - 1][j - suly[i]];
                }
                else
                    m[i][j] = m[i - 1][j];
            }
            else
            {
  //              cerr << "else: idaig eljutottam" << i << j;
                m[i][j] = m[i - 1][j];
            }
        }
    }

    /**/

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cerr << m[i][j] << " ";
        }
        cerr << endl;
    }

    cout << m[N - 1][K - 1];



}

