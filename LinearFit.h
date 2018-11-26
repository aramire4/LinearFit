
#include <algorithm>
#include <math.h>
#include <stdio.h>

template<class T,class F>
vector<double> fitFuncs(const vector<T> &data,const vector<F> &functions){
    int num = data.size();

    //vector<int> vect(num, 0);
    vector<vector<double>> matrix (num, vector<double>(num, 0));
    for(int i = 0; i < num; i++){
        for(int k = 0; k < num; k++){
            F func = functions[k];
            matrix[i][k] = func(data[i]);
            //TODO-check
        }
    }

    /*
    for(int i = 0; i < num; i++){
        vect[i] = i;
    }
    */
    
    for(int k = 1; k < num; k++){
        int p = 0;
        for (int i = k; i < num; i++){

        }
    }


}


