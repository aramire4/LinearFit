//Anthony Ramirez, Madision Cox, Lamonte Brooks
//Pledged
//Linear Fit
//Group A

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

vector<vector<double>> multiply(vector<vector<double>> a, vector<vector<double>> b){
    //TODO function for multiplying vectors together
        if(a[0].size() != b.size()) throw "cannot be multiplied.";
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

vector<vector<double>> transpose(vector<vector<double>> a){
    vector<vector<double>> ret;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            ret[i][j] = a[j][i]
        }
    }
    return ret;
}

vector<double> decomp(vector<vector<double>> &data)
{
    vector<double> p;
    //double n = sizeof(data)/ sizeof(data[0]);
    double n = data.size();

    for (int i = 0; i < n; i++)
    {
        p.push_back(i);   
    }
    for (int k = 0; k < n; k++)
    {
        int kPrime, max = 0;
       
        for (int j = k; j < n; j++)
        {
            if(fabs(data[j][k] > max))
            {
                max = fabs(data[j][k]);
                kPrime = j; 
            }
        }

        if(max==0)
        {
            throw "Error: singular matrix"; 
        }
        
        swap(p[k], p[kPrime]);
        
        for(int l = 0; l < n; l++)
        {
            swap(data[k][l], data[kPrime][l]);
        }

        for (int m = k+1; m < n; m++)
        {
            data[m][k] = (data[m][k])/(data[k][k]); //magic elves matrix math for filling in matrix
            for (int i2 = k + 1; i2 < n; i2++) //undoes summation portion
            {
                data[m][i2] = (data[m][i2]) - ((data[m][k]) * data[k][i2]); //in place
            }
        }

    }

    return p; //return permutation matrix
}

//if we're solving a third order polynomial... x = [a,b,c] constant factors such that we're the
//closest by using least squares 
   
//pi serves as representation of permutation matrix (same in decomp function ... ) 
vector<double> solve(vector<vector<double>> &L, vector<vector<double>> &U, vector<double> p, vector<double> b)
{
    //input: matrix1, matrix2, permutation matrix, product of transpose of matrix1 and array of ys

    //"undoes" decomposition and factors in b vector
    int n = L.size();
    vector<double> y(n);
    vector<double> x(n); //"let x be a ne vector of length n"
    for (int i = 0; i < n; i++)
    {
        int sum = 0; //summation identity
        for ( int j = 0; j < i ; j++) 
        {
            sum += (L[i][j] * y[j]);
        }
        
        y[i] = b[p[i]] - sum; //recursive function in imperative format
    }

    for (int i = n-1; i >= 0; i--)
    {
        
        int sum = 0; //summation  identity
        for (int j = i+1; j < n; j++)
        {
            sum += ((U[i][j]) * x[j]);
        }
        
        x[i] = (y[i] - sum) / U[i][i];
    }
   
    return x;
    
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
    
    vector<vector<double>> t = transpose(matrix);
    vector<vector<double>>multA = multiple(matrix, transpose);



    /*
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
    */
}


