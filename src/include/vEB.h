#include <iostream>
#include <cmath>
#include <vector> 
using namespace std;

class vEB {
    public:
    int universe;
    int min;
    int max;
    int num_clustures;
    vEB * summary;
    vector<vEB*> clustures;

    vEB(int size);

    int index(int i,int j);
    int high(int x);
    int low(int x);
    void insert(int x);
    int successor(int x);
    void del(int x);
};