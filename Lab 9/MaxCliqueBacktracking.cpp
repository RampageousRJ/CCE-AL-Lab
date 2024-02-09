#include <iostream>
#include <vector>
using namespace std;

int n, m, max_size;
int graph[100][100], clique[100];

void MaxClique(int size, int pos) {
    if (pos == n) {
        if (size > max_size) {
            max_size = size;
            for (int i = 0; i < size; i++) {
                cout << clique[i]+1<< " ";
            }
            cout << endl;
        }
        return;
    }
    bool is_candidate = true;
    for (int i = 0; i < size; i++) {
        if (!graph[clique[i]][pos]) {
            is_candidate = false;
            break;
        }
    }
    if (is_candidate) {
        clique[size] = pos;
        MaxClique(size + 1, pos + 1);
    }
    if (size + n - pos > max_size) {
        MaxClique(size, pos + 1);
    }
}

int main() {
    cout<<"Enter number of vertices and edges: ";
    cin >> n >> m;
    cout<<"Enter connections: ";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u-1][v-1] = graph[v-1][u-1] = 1;
    }
    max_size = 0;
    MaxClique(0, 0);
    cout << "Maximum clique size: " << max_size << endl;
    return 0;
    // 5 6 1 2 2 4 3 4 1 3 4 5 3 5 
}