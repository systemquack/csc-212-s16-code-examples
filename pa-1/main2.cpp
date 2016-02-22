#include "uf.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

void print_binary(const float *array, int n) {
    unsigned char byte = 0;
    // loop over all 'n' elements in 'array'
    for (int i = 0 ; i < n ; i++) {
        // output bit 1 if wall exists
        if (array[i] != 0) {
            byte += 1;
        }
        // output number after 8 left rotations
        if (i % 8 == 7) {
            std::cout << (int) byte << " ";
            byte = 0;
        }
        // apply left shift
        byte <<= 1;
    }
    // output remaining bits when n is not multiple of 8
    if (n % 8 != 0) {
        // apply left shit (padding with zeros)
        byte <<= (7-(n%8));
        std::cout << (int) byte << " ";
    }
    // end of the line
    std::cout << std::endl;
}

void create_maze(int n_tiles) {
    // create an array for all vertical walls in an n x n maze
    float *v_walls = new float [n_tiles * (n_tiles-1)];
    float *h_walls = new float [n_tiles * (n_tiles-1)];
    // populate v_walls with codes indicating their position in the maze
    // every v_wall[k] connects nodes floor(v_wall[k]) with ceil(v_wall[k])
    for (int i = 0, k = 0 ; i < n_tiles ; i++) {
        for (int j = 0 ; j < (n_tiles-1) ; j++) {
            v_walls[k++] = (n_tiles*i) + j + 0.5;
        }
    }
    // populate h_walls with codes indicating their position in the maze
    // every -h_wall[k] connects nodes (h_wall[k]-n_tiles) with h_wall[k]
    for (int i = 0, k = 0 ; i < (n_tiles-1) ; i++) {
        for (int j = 0 ; j < n_tiles ; j++) {
            h_walls[k++] = -((n_tiles*(i+1)) + j);
        }
    }
    // pick a random seed
    std::srand((unsigned) std::time(nullptr));
    // initialize a auxiliary variables
    float *which;
    int removed_walls = 0;
    int max_rem_walls = n_tiles * n_tiles - 1;
    // record the time before creating the maze with the UF structure
    clock_t tic = clock();
    // create the maze object
    UF maze(n_tiles * n_tiles);
    // randomly remove walls (using the UF structure)
    while (removed_walls < max_rem_walls) {
        // pick a wall type randomly
        which = (std::rand() % 2) ? v_walls : h_walls;
        // pick a wall randomly
        which += ((std::rand()*std::rand()) % (n_tiles*(n_tiles-1)));
        if (! *which) continue;
        // find node indices
        int p = (*which > 0) ? std::floor(*which) : -(*which) - n_tiles;
        int q = (*which > 0) ? std::ceil(*which) : -(*which);
        // remove wall if allowed by the UF structure
        if (! maze.connected(p,q)) {
            maze.connect(p, q);
            *which = 0;
            removed_walls ++;
        }
    }
    // capture the time after exiting the loop
    clock_t toc = clock();
    // print binary codes for the walls (alternating by rows)
    std::cout << n_tiles << std::endl;
    float *vw = v_walls;
    float *hw = h_walls;
    for (int i = 0 ; i < 2*(n_tiles)-1 ; i++) {
        if (i % 2) { // horizontal
            print_binary(hw, n_tiles);
            hw = hw + n_tiles;
        } else { // vertical
            print_binary(vw, n_tiles-1);
            vw = vw + (n_tiles - 1);
        }
    }
    // this will print the time to the standard error output
    std::cerr << "Total time create_maze with N = " << n_tiles << ":\t" << (double)(toc-tic)/CLOCKS_PER_SEC << " secs.\n";
    // free memory
    delete [] h_walls;
    delete [] v_walls;
}

int main(int argc, char **argv) {
    // read n_tiles as a command line parameter
    int n_tiles = std::stoi(argv[1]);
    // create a maze
    create_maze(n_tiles);
    // return success
    return 0;
}
