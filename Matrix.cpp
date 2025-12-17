#include "Matrix.h"
#include <vector>

using std::vector;

// Public

Matrix::Matrix(int _rows, int _cols, const double _initval = 0.){

    mat.resize(_rows);
    for (int i=0; i<mat.size(); i++){
        mat[i].resize(_cols, _initval);
    }

    rows = _rows;
    cols = _cols;
}

Matrix::Matrix(const Matrix& rhs){

        mat = rhs.mat;
        rows = rhs.get_rows();
        cols = rhs.get_cols();

}

Matrix::~Matrix(){}

Matrix& Matrix::operator=(const Matrix& rhs){

    int new_rows = rhs.get_rows();
    int new_cols = rhs.get_cols();

    mat.resize(new_rows);
    for (int i=0; i<mat.size(); i++){
        mat[i].resize(new_cols);
    }

    for (int i=0; i<new_rows; i++){
        for (int j=0; j< new_cols; j++){
            mat[i][j] = rhs(i,j);
        }
    }

    rows = new_rows;
    cols = new_cols;

    return *this;
}