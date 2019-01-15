#include <iostream>
using namespace std;

#define N 15

int sum(int freq[N], int low, int high){
    int sum = 0;

        for(int k = low; k <= high; ++k){
            sum += freq[k];
        }

    return sum;
}

int minCostBST(int keys[N], int freq[N], int n) {
    int cost[n][n];

    for (int i = 0; i < n; ++i){
        cost[i][i] = freq[i];
    }

    for (int length = 2; length <= n; ++length){
        for (int i = 0; i <= n - length + 1; ++i){
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            for (int root = i; root <= j; ++root) {
                int cost_root = ( (root > i) ? cost[i][root - 1] : 0 ) + ( (root < j) ? cost[root + 1][j] : 0 ) + sum(freq, i, j);
                if (cost_root < cost[i][j]){
                    cost[i][j] = cost_root;
                    cout <<i << " "<<j<<" "<<cost_root<<endl;
                }
            }
        }
    }

    for(int i = 0;i<n;i++){
    for(int j =0;j<n;j++){
        cout<<cost[i][j] << " ";
    }
    cout<<endl;
    }
    return cost[0][n-1];
}

int main(){
    int keys[N];
    int freq[N];
    int n;

        cout << "The number of keys is:";
        cin >> n;

        for(int it = 0; it < n; ++it){
            cout << "keys[" << it << "]=";
            cin >> keys[it];
        }

        for(int it = 0; it < n; ++it){
            cout << "freq[" << it << "]=";
            cin >> freq[it];
        }

        cout << "Cost of Optimal BST is: "<< minCostBST(keys, freq, n);
}
