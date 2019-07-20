#include<iostream>
#include<algorithm>
using namespace std;

struct vertex{
     int u;
     int v;
     int w;
};

bool compare(struct vertex v1, struct vertex v2){
     if(v1.w < v2.w)
          return true;
     return false;
}


int getParent(int v, int parent[]){

   int i = v;
    while(i != parent[i])
            i = parent[i];
    return i;

    //return getParent(parent[v], parent);
}

void updateParent(int parent[], int n, int u, int v){
     parent[u] = v;
}

struct vertex *kruskal(struct vertex arr[], int n,int e){

     vertex *result = new vertex[n];

     int parent[n];

     for(int i = 0; i < n; i++)
          parent[i] = i;

     int count = 0;
    int i = 0;

    while(count < n-1){
        int u_par = getParent(arr[i].u,parent);
        int v_par = getParent(arr[i].v,parent);

        if(u_par != v_par){
            parent[u_par] = v_par;
            result[count] = arr[i];
            count++;
        }
        i++;
    }
     return result;
}

int main(){
     int n,e;
     cin >> n >> e;
     struct vertex arr[e];
     for(int i = 0; i < e; i++){
          int u,v,w;
          cin >> u >> v >> w;
          arr[i].u = u;
          arr[i].v = v;
          arr[i].w = w;
     }

     sort(arr,arr+e,compare);
     struct vertex *result = kruskal(arr,n,e);
     for(int i = 0; i < n-1; i++){
         int smallest = result[i].u < result[i].v ? result[i].u  : result[i].v;
         int largest = result[i].u  > result[i].v ? result[i].u  : result[i].v;
         std::cout << smallest << " " << largest << " " << result[i].w << '\n';
     }
     delete [] result;
     return 0;
}
