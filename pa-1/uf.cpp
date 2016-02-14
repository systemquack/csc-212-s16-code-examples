#include "uf.h"
#include <assert.h>

// Constructor for an empty UF data structure with n elements
UF::UF(int n) {
    // initialize variables and allocate memory dynamically
    n_elems = n;
    id = new int[n_elems];
    // initilize each element to have its own ID
    for (int i = 0 ; i < n_elems ; i ++) {
        id[i] = i;
    }
}

// Destructor for the UF data structure
UF::~UF() {
    // need to free memory allocated by the constructor
    delete [] id;
}

// implements the Find operation
int UF::find(int e) {
    // safety check
    assert(e >= 0 && e < n_elems);
    // return ID for element e
    return id[e];
}

// checks for connectivity
bool UF::connected(int p, int q) {
    // returns True if p and q are connected, False otherwise
    return find(p) == find(q);
}

// merges sets p and q (implements the Union operation)
void UF::connect(int p, int q) {
    int id_p = find(p);
    int id_q = find(q);

    // check if p and q are already connected
    if (id_p == id_q) return;

    // change all values id[p] to id[q]
    for (int i = 0 ; i < n_elems ; i++) {
        if (id[i] == id_p) {
            id[i] = id_q;
        }
    }
}
