#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool isBiparttill(int v, vector<int>adj[]){
    vector<int> col(v, -1);
    queue<pair<int, int> > q;
    for (int i = 0; i < v; i++) {
        if (col[i] == -1) {
            q.push({ i, 0 });
            col[i] = 0;
           
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;
                 
                for (int j : adj[v]) {
                   
                    if (col[j] == c)
                        return 0;
                    if (col[j] == -1) {
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
 return 1;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int v,e;
v=4,e=8;
vector<int> adj[v];
      adj[0] = {1,3};
      adj[1] = {0,2};
      adj[2] = {1,3};
      adj[3] = {0,2};
if(isBiparttill(v,adj)) cout<<"Graph is Bipartite!!\n";
else cout<<"Graph is not bipartite!!\n";
return 0;
}