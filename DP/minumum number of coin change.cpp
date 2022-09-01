#include<bits/stdc++.h>
using namespace std;
int totalcoin[1000][1000];
int minimumcoins(int n, int w, int coin[])
{


    totalcoin[0][0]=0;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(j==0) totalcoin[i][j]=0;
            else if(coin[i]>j)
                totalcoin[i][j]= totalcoin[i-1][j]== INT_MAX?0:totalcoin[i-1][j];
            else
                if (totalcoin[i-1][j]!=0)  totalcoin[i][j]= min(totalcoin[i-1][j], 1+ totalcoin[i][j-coin[i]]);
                else
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            cout<<totalcoin[i][j]<<"  ";
        }
        cout<<endl;
    }

    return totalcoin[n][w];

}

int main()
{
    int n, coins[100], w;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("minimumcoins.txt", "r", stdin);
    cin>>n;
    coins[0]=0;
    for(int i=1; i<=n; i++)
        cin>>coins[i];
    cin>>w;
    cout<<"Minimum coins required : "<<minimumcoins(n,w, coins)<<endl;

    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;


int minCoins(int coins[], int m, int V)
{
	int table[V+1];

	table[0] = 0;
	for (int i=1; i<=V; i++)
		table[i] = INT_MAX;
	for (int i=1; i<=V; i++)
	{
		for (int j=0; j<m; j++)
		if (coins[j] <= i)
		{
			int sub_res = table[i-coins[j]];
			if (sub_res != INT_MAX && sub_res + 1 < table[i])
				table[i] = sub_res + 1;
		}
	}

	return table[V];
}

int main()
{
	int coins[] = {9, 12, 5, 3};
	int m = sizeof(coins)/sizeof(coins[0]);
	int V = 11;
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V);
	return 0;
}
*/
