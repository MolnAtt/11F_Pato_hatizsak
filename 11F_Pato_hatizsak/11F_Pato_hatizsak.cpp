
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
    // els� sor felt�lt�se: ha belef�r az els� t�rgy a h�tizs�kba, akkor bevessz�k, egy�bk�nt meg nem.
    for (size_t j = 0; j < K; j++)
        m[0][j] = suly[0] <= K ? ertek[0] : 0;
    /**/

    /**/

    // m�sodik sort�l az �sszes
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            // �ssze kell hasonl�tani az �j t�rgy adta lehet�s�geket a t�rgy n�lk�li (el�z� sor! i-1!) lehet�s�gekkel
            // m[i-1] // t�rgy n�lk�li lehet�s�g
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

