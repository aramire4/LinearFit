//Anthony Ramirez, Madision Cox, Lamonte Brooks
//Pledged
//Linear Fit

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>



vector<vector<double>> multiply(vector<vector<double>> a, vector<vector<double>> b){
    //TODO function for multiplying vectors together
        if(a[0].size() != b.size()) return null; //cannot be multiplied.
        else{
                int m = b.size(); //max pointer value
                int n = a.size(); // # result rows
                int p = b[0].size(); //# resut cols
                vector<vector<double>> c(n, vector<double>(p, 0));
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < p; j++){
                                int sum = 0;
                                for(int k = 0; k < m; k++){
                                        sum += a[i][k] * b[k][j];
                                }
                                c[i][j] = sum;
                        }
                }
                return c;
        }
}

template<class T,class F>
vector<double> fitFuncs(const vector<T> &data,const vector<F> &functions){
    int num = data.size();
    int kprime = 0;

    vector<double> fit;
    for(int i = 0; i < num; i++) fit[i] = i;

    vector<vector<double>> matrix (num, vector<double>(num, 0));

    for(int i = 0; i < num; i++){
        for(int k = 0; k < functions.size(); k++){
            //Should be the matrix of data called on the functions
            F func = functions[k];
            matrix[i][k] = func(data[i].x);

        }
    }
    vector<vector<double>> transpose (num, vector<double>(num, 0));
    //TODO need a function that multiplies matricies together for transpose

    
    for(int k = 1; k < num; k++){
        int p = 0;
        for (int i = k; i < num; i++){
            if(fabs(matrix[i][k]) > p){
                p = fabs(matrix[i][k]); 
                kprime = i;            
            }
        }
        if(p == 0) cout <<"singular matrix\n";
        std::swap(fit[k], fit[kprime]);
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


