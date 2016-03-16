#include "LList.h"
#include <math.h>
#include <iostream>

LLNode::LLNode(double la, double lo, const std::string &desc) {
    next = NULL;
    name = desc;
    lat = la;
    lon = lo;
}

LLNode::~LLNode() {
}

double LLNode::distance(double _la, double _lo) {
    double param = M_PI / 180.0; // required for conversion from degrees to radians
    double rad = 3956.0;  // radius of earth in miles
    double d_lat = (_la - lat) * param;
    double d_lon = (_lo - lon) * param;
    double dist = sin(d_lat/2) * sin(d_lat/2) + cos(lat*param) * cos(_la*param) * sin(d_lon/2) * sin(d_lon/2);
    dist = 2.0 * atan2(sqrt(dist), sqrt(1-dist));
    return rad * dist;
}

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    destroy(head);
}

void LinkedList::destroy() {
    destroy(head);
    head = NULL;
}

void LinkedList::destroy(LLNode *p) {
    if (p) {
        destroy(p->next);
        delete p;
    }
}

unsigned int LinkedList::getSize() {
    return size;
}

void LinkedList::insert(double la, double lo, const std::string &desc) {
    LLNode *p = new LLNode(la, lo, desc);
    p->next = head;
    head = p;;
    size ++;
}

unsigned int LinkedList::printNeighbors(double la, double lo, double rad, const std::string &filter) {
    unsigned int count = 0;
    std::cout << "var markers = [\n";
    LLNode *p = head;
    std::cout << "\t[\"" << "CENTER" << "\", " << la << ", " << lo << "],\n";
    while (p) {
        if (p->distance(la,lo) < rad && p->name.find(filter) != std::string::npos) {
            std::cout << "\t[\"" << p->name << "\", " << p->lat << ", " << p->lon << "],\n";
            count ++;
        }
        p = p ->next;
    }
    std::cout << "];\n";
    return count;
}
