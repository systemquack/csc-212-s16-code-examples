#ifndef __kdtree__
#define __kdtree__
#include <string>

class KDNode {
    private:
        double lat;
        double lon;
        std::string name;
        KDNode *left;
        KDNode *right;

        double distance(double _la, double _lo);

    public:
        KDNode(double la, double lo, const std::string &desc);
        ~KDNode();

    friend class KDTree;
};

class KDTree {
    private:
        unsigned int size;
        KDNode *root;

        void destroy(KDNode *p);

    public:
        KDTree();
        ~KDTree();

        void insert(double la, double lo, const std::string &desc);
        unsigned int printNeighbors(double la, double lo, double rad, const std::string &filter);
        unsigned int getSize();
};

#endif
