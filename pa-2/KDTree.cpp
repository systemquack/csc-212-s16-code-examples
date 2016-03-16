#include "KDTree.h"
#include <math.h>

KDNode::KDNode(double la, double lo, const std::string &desc) {
    left = NULL;
    right = NULL;
    name = desc;
    lat = la;
    lon = lo;
}

KDNode::~KDNode() {
}

double KDNode::distance(double _la, double _lo) {
    double param = M_PI / 180.0; // required for conversion from degrees to radians
    double rad = 3956.0;  // radius of earth in miles
    double d_lat = (_la - lat) * param;
    double d_lon = (_lo - lon) * param;
    double dist = sin(d_lat/2) * sin(d_lat/2) + cos(lat*param) * cos(_la*param) * sin(d_lon/2) * sin(d_lon/2);
    dist = 2.0 * atan2(sqrt(dist), sqrt(1-dist));
    return rad * dist;
}

KDTree::KDTree() {
    root = NULL;
}

KDTree::~KDTree() {
    destroy(root);
}

void KDTree::destroy() {
    destroy(root);
    root = NULL;
}

void KDTree::destroy(KDNode *p) {
    if (p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}


void KDTree::insert(double lat, double lon, const std::string &desc) {
    
}
