
#include <algorithm>
#include <math.h>
#include <stdio.h>

template<class T,class F>
vector<double> fitFuncs(const vector<T> &data,const vector<F> &functions){
    int num = data.size();

    vector<vector<int>> matrix;
    vector<int> vect(num, 0);
    for(int i = 0; i < num; i++){
        vect[i] = i;
    }
    
    for(int k = 1; k < num; k++){
        int p = 0;
        for (int i = k; i < num; i++){

        }
    }


}


