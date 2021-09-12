#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/
void addEdge(vector<vector<int> >  &adj_list, int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void doBfs(int u, vector<vector<int> > adj_list) {
  vector <bool> visited;
  visited.assign(5, false);
   /*
   1 -> true
   2 -> false
   */

  queue <int> q;
  q.push(u);
  visited[u] =  true;
  while(!q.empty()) {
    int ele = q.front();
    cout << ele << " ";
    q.pop();
    for(int i=0; i<adj_list[ele].size(); i++) {
        int x = adj_list[ele][i];
        if(!visited[x]) {
            q.push(x);
            visited[x] = true;
        }
    }
  }
    cout<<endl;
}

void dfsUtil(vector<vector<int> > adj_list, vector<bool> &visited, int u) {
    stack <int> s;
    s.push(u);
    while(!s.empty()) {
       int ele = s.top();
       if(!visited[ele]) {
         cout<<ele<<" ";
          visited[ele] = true;
       }
       s.pop();
       for(int i=0; i<adj_list[ele].size(); i++) {
        int x = adj_list[ele][i];
        if(!visited[x]) {
            s.push(x);
        }
    }
    }
    cout<<endl;
}


void doDfs(vector<vector<int> > adj_list, int num_vertices) {
    vector <bool> visited;
    visited.assign(num_vertices, false);
    for(int v=0; v<num_vertices; v++) {
        if(!visited[v])
            dfsUtil(adj_list, visited, v);
    }
}

int main() {
    vector<vector<int> >  adj_list;
    /* 
    0 -> 1,4
    1 -> 2, 3 
    2 -> 1, 4, 5 --- if directed then only 2 -> 4,5
    */
   int num_vertices = 5;
   adj_list.assign(num_vertices, vector<int>());
   addEdge(adj_list,0,1);
   addEdge(adj_list,0,4);
   addEdge(adj_list,1,4);
   addEdge(adj_list,1,2);
   addEdge(adj_list,1,3);
   addEdge(adj_list,2,3);
   addEdge(adj_list,3,4);
   
   cout<<"====BFS====="<<endl;
   doBfs(0, adj_list);
   cout<<"====DFS====="<<endl;
   doDfs(adj_list, 5);
    return 0;
}