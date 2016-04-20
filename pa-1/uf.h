#ifndef __uf_h__
#define __uf_h__

// class Union Find
class UF {
    private:
        // identifier for each element
        int *id;
        // number of elements
        int n_elems;

    public:
        UF(int n);
        ~UF();

        int find(int e);
        bool connected(int p, int q);
        void connect(int p, int q);        
};

#endif
