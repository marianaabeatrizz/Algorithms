#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

#define UNVISITED 0
#define VISITED 1

class Graph{
    public:

        int** matrix;
        int numEdge;
        int numVertex;
        int* Mark;

};

Graph create_graph(int n){
    Graph g;
    g.numVertex = n;
    g.numEdge = 0;
    g.Mark = new int[n];
    for(int i = 0; i < n; i++){
        g.Mark[i] = UNVISITED;
    }
    g.matrix = new int* [n];
    for(int i = 0; i < n; i++){
        g.matrix[i] = new int[n];
        for(int j = 0; j < n; j++){
            g.matrix[i][j] = 0;
        }
    }
    return g;
}

int first (Graph& g, int v){
    for(int i = 0; i <g.numVertex; i++){
        if(g.matrix[v][i] != 0){
            return i;
        }

    }
    return g.numVertex;
}

int next(Graph& g, int v, int w){
    for(int i = w + 1; i < g.numVertex; i++){
        if(g.matrix[v][i] != 0){
            return i;
        }
    }
    return g.numVertex;
}

void setEdge(Graph& g, int i, int j, int wt){
    if(wt == 0){
        throw invalid_argument("Peso deve ser diferente de 0");
    }
    if(g.matrix[i][j] == 0){
        g.numEdge++;
    }
    g.matrix[i][j] = wt;
    g.matrix[j][i] = wt;

}

void delEdge(Graph& g, int i, int j){
    if(g.matrix[i][j] != 0){
        g.numEdge--;
    }
    g.matrix[i][j] = 0;
    g.matrix[j][i] = 0;
}

void setMark(Graph& g, int v, int mark){
    g.Mark[v] = mark;
}

int getMark(Graph& g, int v){
    return g.Mark[v];

}
void previsit(Graph& g, int v){
    cout << "Visitando (pre): " << v << endl;

}
 void posvisit(Graph& g, int v){
    cout << "Visitando (pos): " << v << endl;
}


void DFS(Graph& g, int v, vector<int>& ordem) {
    ordem.push_back(v);
    setMark(g, v, VISITED);
    int w = first(g, v);
    while (w < g.numVertex) {
        if (getMark(g, w) == UNVISITED) {
            DFS(g, w, ordem);
        }
        w = next(g, v, w);
    }
}

void graphTraverseDFS(Graph& g){
    vector<int> ordem;
    for(int v = 0; v < g.numVertex; v++){
        setMark(g, v, UNVISITED);
    }
    for( int v = 0; v< g.numVertex; v++){
        if(getMark(g,v) == UNVISITED){
            DFS(g,v,ordem);
        }
    }
}

void BFS(Graph& g, int start, vector<int>& ordem) {
    queue<int> Q;
    Q.push(start);
    setMark(g, start, VISITED);

    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        ordem.push_back(v);
        int w = first(g, v);
        while (w < g.numVertex) {
            if (getMark(g, w) == UNVISITED) {
                setMark(g, w, VISITED);
                Q.push(w);
            }
            w = next(g, v, w);
        }
    }
}

void graphTraverseBFS( Graph& g){
    vector<int> ordem;
    for(int v = 0; v < g.numVertex; v++){
        setMark(g, v, UNVISITED);
    }
    for(int v = 0; v< g.numVertex; v++){
        if(getMark(g,v) == UNVISITED){
            BFS(g,v, ordem);
        }
    }
}
void resetMarks(Graph& g) {
    for (int v = 0; v < g.numVertex; v++) {
        setMark(g, v, UNVISITED);
    }
}

int main(){
    int n;
    int q;
    string operation;
    int v1, v2;
    cin >> n >> q;
    Graph g = create_graph(n); // criei o grafo fora do loop, pra não resetar o grafo
    for( int i = 0; i < q; i++){
        cin >> operation >> v1;
        if (operation == "add"){
            cin >> v2;
            setEdge(g, v1, v2, 1);
        }
        else if (operation == "BFS"){
            resetMarks(g);
            vector<int> ordem;
            BFS(g, v1, ordem);
            for (int v : ordem) {
            cout << v << " ";
            }
            cout << endl;
        }
        else{
            resetMarks(g);
            vector<int> ordem;
            DFS(g, v1, ordem);
            for (int v : ordem){
            cout << v << " ";
            }
            cout << endl;
        }   
    }
    return 0;
}
