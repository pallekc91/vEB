#include "include/vEB.h"
using namespace std;

int main(){
    vEB v(500);
    v.insert(15);
    v.insert(25);
    v.insert(71);
    v.insert(4);
    v.insert(97);
    v.insert(23);
    v.insert(5);
    std::cout << v.successor(20) << std::endl;
    v.del(23);
    std::cout << v.successor(20) << std::endl;
}
