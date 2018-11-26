//Anthony Ramirez, Madision Cox, Lamonte Brooks
//Pledged
//Linear Fit

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>

template<class T,class F>
vector<double> fitFuncs(const vector<T> &data,const vector<F> &functions){
    int num = data.size();
    int kprime = 0;

    vector<vector<double>> matrix (num, vector<double>(num, 0));
    for(int i = 0; i < num; i++){
        for(int k = 0; k < num; k++){
            //Should be the matrix of data called on the functions
            F func = functions[k];
            matrix[i][k] = func(data[i]);
            //TODO- should we call .x or .y on matrix
            //or does func do it?

        }
    }

    
    for(int k = 1; k < num; k++){
        int p = 0;
        for (int i = k; i < num; i++){
            if(fabs(matrix[i][k]) > p){
                p = fabs(matrix[i][k]); 
                kprime = i;            
            }
        }
        if(p == 0) cout <<"singular matrix\n";
        for(int i = 1; i < num; i++){
            std::swap(matrix[k][i], matrix[kprime][i]);
        }
        for(int i = k+1; i < num; i++){
            matrix[i][k] = matrix[i][k] / matrix[k][k];
            for(int j = k+1; j < num; j++){
                matrix[i][j] = matrix[i][j] - (matrix[i][k] * matrix[k][j]);
            }
        }
    }
    //end of pseudocode

}


