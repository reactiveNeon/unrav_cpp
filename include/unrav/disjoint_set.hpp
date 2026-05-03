#include <vector>

namespace unrav {
class DisjointSet {
   public:
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size);

        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        int root = x;
        while (parent[root] != root) {
            root = parent[root];
        }

        while (x != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }

        return root;
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }

        num_components--;
    }

    bool is_connected(int x, int y) { return find(x) == find(y); }

    int get_component_rank(int x) { return rank[find(x)]; }

    int get_size() { return parent.size(); }

    int get_num_components() { return num_components; }

   private:
    int num_components;

    std::vector<int> rank;
    std::vector<int> parent;
};
}  // namespace unrav
