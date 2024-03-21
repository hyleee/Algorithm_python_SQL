#include <iostream>
#include <queue>
using namespace std;

int n,k;
bool visited[100001];

void bfs(int a){
    queue<pair<int,int>> q;
    q.push(make_pair(a,0)); // 위치, 이동횟수
    while(!q.empty()){
        int x =q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (x==k){
            cout<<cnt;
            break;
        }

        if(x-1>=0 && x-1<100001 && !visited[x-1]){
            visited[x-1]=true;
            q.push(make_pair(x-1,cnt+1));
        }

        if(x+1>=0 && x+1<100001 && !visited[x+1]){
            visited[x+1]=true;
            q.push(make_pair(x+1,cnt+1));
        }

        if(2*x >=0 && 2*x<100001 && !visited[2*x]){
            visited[2*x]=true;
            q.push(make_pair(2*x, cnt+1));
        }
    }
}

int main(){

    cin>>n>>k;
    visited[n]=true;
    bfs(n);
}