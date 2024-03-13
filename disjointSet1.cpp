#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

    public:
    // constructor
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // find ultimate parent
    int findUParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;
        else if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            // both have same rank
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;
        else if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
