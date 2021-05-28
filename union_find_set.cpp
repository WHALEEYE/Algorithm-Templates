struct GraphNode {
  GraphNode *prt;
  long long size;
};

struct Edge {
  int v1;
  int v2;
  int weight;
};

GraphNode *find(GraphNode *a) {
  if (a == a->prt) {
    return a;
  } else {
    a->prt = find(a->prt);
    return a->prt;
  }
}

void merge(GraphNode *a, GraphNode *b) {
  find(b)->size += find(a)->size;
  find(a)->prt = find(b);
}
