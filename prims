#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; 
int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<pii> > g(n+1);
    int wt,st,en;
    for(int i=0;i<e;i++){
        cin>>wt>>st>>en;
        g[st].push_back(make_pair(wt,en));
        g[en].push_back(make_pair(wt,st));
    }
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    int cost = 0;
    vector<int> visited(n+1,0);
    pq.push(make_pair(0,1));
    pii p;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        int x = p.second;
        if(visited[x] == 1)continue;
        visited[x] = 1;
        cost+=p.first;
        int y;
        vector<pii>::iterator it;
        for(it=g[x].begin();it!=g[x].end();it++){
            y =(*it).second;
            if(visited[y] == 0){
                pq.push(*it);
            }
        }
    }
    cout<<cost<<endl;
    return 0;
}
