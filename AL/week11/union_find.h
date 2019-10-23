#ifndef UNION_FIND_H
#define UNION_FIND_H

struct subset {
    int parent;
    int rank;
};

typedef struct subset SUBSET;

int find(SUBSET subsets[], int index) {

    if(subsets[index].parent != index)
        subsets[index].parent = find(subsets, subsets[index].parent);
    
    return subsets[index].parent;
}

void union_(SUBSET subsets[], int x, int y) {
    
    int x_set = find(subsets, x);
    int y_set = find(subsets, y);

    if(subsets[x_set].rank > subsets[y_set].rank) {
        subsets[y_set].parent = x_set;

    } else if(subsets[x_set].rank < subsets[y_set].rank) {
        subsets[x_set].parent = y_set;

    } else {
        subsets[y_set].parent = x_set;
        subsets[x_set].rank++;

    }
}

#endif