#include "include/vEB.h"
#include <unordered_set>
#include <chrono>
#include <iostream>
using namespace std;

int main(){

    chrono::time_point<chrono::steady_clock> start, stop;
    chrono::duration<double> difference_in_time;
    vEB v(5000000);
    // f.insert(8);
    // f.insert(8);
    // f.insert(50);
    // f.insert(74);
    // f.insert(59);
    // f.insert(51);
    // f.insert(73);
    // f.insert(25);
    // f.insert(79);
    // f.insert(4);
    // cout << "inserting 30  from main" << endl; 
    // f.insert(30);
    // cout << "inserting 41  from main" << endl; 
    // f.insert(41);
    // cout << f.root->children[1]->children[0]->values[0] << endl; 
    // cout << (f.root->values[0] == 8) << endl;
    // //cout << (f.root->values[1] == 59) << endl;
    // cout << (f.root->children[0]->values[0] == 50) << endl;
    // cout << (f.root->children[1]->values[0] == 74) << endl;

    // cout << (f.root->children[0]->children[0]->values[0] == 8) << endl;
    // cout << (f.root->children[0]->children[0]->values[1] == 25) << endl;
    // cout << (f.root->children[0]->children[1]->values[0] == 51) << endl;
    // cout << (f.root->children[1]->children[0]->values[0] == 73) << endl;
    // cout << (f.root->children[1]->children[1]->values[0] == 77) << endl;
    // //f.initialize();
    // // cout << f.successor(0) << endl;

    unordered_set<int> inputs;
    for (int i = 1; i <= 5000000; i++) {
		/* pick random number from 1 to 6 and output it */
        int rand_num = 1 + (rand() % 5000000);
        inputs.insert(rand_num);
		/* if counter is divisible by 5, begin new line of output */
	}
    for(auto e : inputs) {
        //cout << "insering " << e << endl;
        v.insert(e);
    }
    //cout << "f.successor(64) " << f.successor(64) << endl;
    start = chrono::steady_clock::now();
    for (int i = 1; i <= 1000000; i++) {
		/* pick random number from 1 to 6 and output it */
        int rand_num = 1 + (rand() % 5000000);
        v.successor(rand_num);
        //cout << "successor of " << rand_num << " = " << v.successor(rand_num) << endl;
		/* if counter is divisible by 5, begin new line of output */
	}
    stop = chrono::steady_clock::now();
    difference_in_time = stop - start;
    double diff_in_seconds = double(difference_in_time.count());
    cout << "time taken " << diff_in_seconds << endl;
    //cout << endl;
    //cout << f.successor(48) << endl;

}
