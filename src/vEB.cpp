#include "include/vEB.h"

vEB::vEB(int size):universe(size),min(-1),max(-1){
    if(size != 2){
        num_clustures = ceil(sqrt(size));
        summary = new vEB(num_clustures);
        for(int i = 0;i < num_clustures ; i++){
            vEB * child = new vEB(num_clustures);
            clustures.push_back(child);
        }
    } else {
        num_clustures = 0;
        summary = NULL;
    }
}

int vEB::index(int i, int j){
    return (i * num_clustures) + j;
}

int vEB::high(int x){
    if(num_clustures == 0){
        return -1;
    }
    return x / num_clustures;
}

int vEB::low(int x){
    if(num_clustures == 0){
        return x;
    }
    return x % num_clustures;
}

void vEB::insert(int x){
    if(x == min | x == max){
        return;
    }
    if(x < min){
        int temp = min;
        min = x;
        x = temp;
    }
    if(min == -1){
        min = x;
        max = x;
        return;
    }
    if(x > max){
        max = x;
    }
    int h = high(x);
    if(h != -1){
        if(clustures[high(x)]->min == -1){
            summary->insert(high(x));
        }
        clustures[high(x)]->insert(low(x));
    }
}

int vEB::successor(int x){
    //cout << "searching for " << x << endl;
    //cout << "min " << min << endl;
    //cout << "max " << max << endl;
    if(x < min){
        return min;
    }
    if(x > max){
        //cout << "NOT FOUND" << endl;
        return -1;
    }
    int i = high(x);
    int j = 0;
    if(i == -1){
        return max;
    }
    //cout << "high is " << i << endl;
    //cout << "clustures size is " << num_clustures << endl;
    if(low(x) < clustures[i]->max){
        j = clustures[i]->successor(low(x));
    } else{
    //    cout << "searching for summary's succ " << i << endl;
        i = summary->successor(i);
    //   cout << "summary's successor is " << i << endl;
        j = clustures[i]->min;
    }
    return index(i,j);
}

void vEB::del(int x){
    if(x == min){
        int i = summary->min;
        if(i== -1){
            min = -1;
            max = -1;
            return;
        }
        min = index(i,clustures[i]->min);
        x = index(i,clustures[i]->min);
    }
    clustures[high(x)]->del(low(x));
    if(clustures[high(x)]->min == -1){
        summary->del(high(x));
    }
    if(x == max){
        if(summary->max == -1){
            max = min;
        } else {
            int i = summary->max;
            max = index(i,clustures[i]->max);
        }
    }
}