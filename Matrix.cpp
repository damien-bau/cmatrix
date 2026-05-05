#include "Matrix.h"
#include <stdexcept>
#include <cmath>


// Constructor
Matrix::Matrix(int _rows, int _cols, const double _initval = 0.){

    mat.resize(_rows);
    for (int i=0; i<mat.size(); i++){
        mat[i].resize(_cols, _initval);
    }

    rows = _rows;
    cols = _cols;
}

// Copy constructor
Matrix::Matrix(const Matrix& rhs){

        mat = rhs.mat;
        rows = rhs.get_rows();
        cols = rhs.get_cols();

}

// Destructor
Matrix::~Matrix(){}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& rhs){

    int new_rows = rhs.get_rows();
    int new_cols = rhs.get_cols();

    mat.resize(new_rows);
    for (int i=0; i<mat.size(); i++){
        mat[i].resize(new_cols);
    }

    for (int i=0; i<new_rows; i++){
        for (int j=0; j<new_cols; j++){
            mat[i][j] = rhs(i,j);
        }
    }

    rows = new_rows;
    cols = new_cols;

    return *this;
}

// Scalar addition: matrix + constant
Matrix Matrix::operator+(const double& rhs){

    Matrix output(rows,cols,0.);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            output(i,j) = this->mat[i][j] + rhs;
        }
    }

    return output;

}

// Scalar subtraction: matrix - constant
Matrix Matrix::operator-(const double& rhs){

    Matrix output(rows,cols,0.);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            output(i,j) = this->mat[i][j] - rhs;
        }
    }

    return output;

}

// Scalar multiplication: matrix * constant
Matrix Matrix::operator*(const double& rhs){

    Matrix output(rows,cols,0.);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            output(i,j) = this->mat[i][j] * rhs;
        }
    }

    return output;
}

// Scalar division: matrix / constant
Matrix Matrix::operator/(const double& rhs){

    Matrix output(rows,cols,0.);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            output(i,j) = this->mat[i][j] / rhs;
        }
    }

    return output;
}

// Matrix addition: matrix + matrix
Matrix Matrix::operator+(const Matrix& rhs){

    // Raise error if sizes don't match
    
    Matrix output(rows,cols,0.);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            output(i,j) = this->mat[i][j] + rhs(i,j);
        }
    }

    return output;
}

Matrix Matrix::operator-(const Matrix& rhs){

    // Raise error if sizes don't match

    Matrix output(rows,cols,0.);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            output(i,j) = this->mat[i][j] - rhs(i,j);
        }
    }

    return output;
}

Matrix Matrix::operator*(const Matrix& rhs){

    // Raise error if sizes aren't compatible

    int rows = this->rows;
    int cols = rhs.get_cols();
    int n = rhs.get_rows();
    Matrix output(rows,cols,0.);


    for (int i=0; i<rows; i++){
        for (int k=0; k<n; k++){
            for (int j=0; j<cols; j++){
                output(i,j) += this->mat[i][k]*rhs(k,j);
            }
        }
    }

    return output;

}

Matrix& Matrix::operator+=(const Matrix& rhs){

    // Raise error if sizes don't match

    int rows = rhs.get_rows();
    int cols = rhs.get_cols();

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            this->mat[i][j] += rhs(i,j);
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs){

    // Raise error if sizes don't match

    int rows = rhs.get_rows();
    int cols = rhs.get_cols();

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            this->mat[i][j] -= rhs(i,j);
        }
    }

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhs){

    // Raise error if sizes aren't compatible
    Matrix output = (*this) * rhs;

    (*this) = output;
    return *this;
    
}

std::vector<double> Matrix::operator*(const std::vector<double>& rhs){

    std::vector<double> output(rhs.size(),0.);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            output[i] += this->mat[i][j] * rhs[j];
        }
    }

    return output;
}

double& Matrix::operator()(const int& row, const int& col){
    // Raise error if index out of range
    return this->mat[row][col];
}

const double& Matrix::operator()(const int&row, const int& col) const{
    // Raise error if index out of range
    return this->mat[row][col];
}

int Matrix::get_rows() const {
    return this->rows;
}

int Matrix::get_cols() const {
    return this->cols;
}

std::vector<double>& Matrix::get_row(const int& row){
    // Raise error if index out of range
    if (row < 0 || row >= this->rows){
        throw std::out_of_range("Row index out of range");
    }
    return this->mat[row];
}

const std::vector<double>& Matrix::get_row(const int& row) const{
    // Raise error if index out of range
    if (row < 0 || row >= this->rows){
        throw std::out_of_range("Row index out of range");
    }
    return this->mat[row];
}

double Matrix::determinant(){
/*
Calculates the determinant of the matrix using LU decomposition.
Only exists for square matrices.
*/

    if (this->rows != this->cols){
        throw std::runtime_error("determinant() requires a square matrix");
    }

    int n = this->rows;
    
    // Create a copy of the matrix for LU decomposition
    Matrix lu = *this;
    
    int swaps = 0;  // Track row swaps for sign of determinant
    
    // Perform LU decomposition with partial pivoting
    for (int i = 0; i < n; i++){
        
        // Find pivot (row with largest absolute value in column i)
        int max_row = i;
        double max_val = std::abs(lu(i, i));
        
        for (int k = i + 1; k < n; k++){
            if (std::abs(lu(k, i)) > max_val){
                max_val = std::abs(lu(k, i));
                max_row = k;
            }
        }
        
        // Check for singular matrix
        if (std::abs(lu(max_row, i)) < 1e-15){
            return 0.0;
        }
        
        // Swap rows if needed
        if (max_row != i){
            std::swap(lu.get_row(i), lu.get_row(max_row));
            swaps++;
        }
        
        // Eliminate column i below the diagonal
        for (int k = i + 1; k < n; k++){
            double factor = lu(k, i) / lu(i, i);
            for (int j = i; j < n; j++){
                lu(k, j) -= factor * lu(i, j);
            }
        }
    }
    
    // Calculate determinant as product of diagonal elements
    // adjusted by the sign from row swaps
    double det;
    if (swaps % 2 == 0){
        det = 1.0;
    } else {
        det = -1.0;
    }
    
    for (int i = 0; i < n; i++){
        det *= lu(i, i);
    }

    return det;
}

Matrix Matrix::transpose(){
 
    int rows = this->cols;
    int cols = this->rows;
    Matrix output(rows,cols,0.);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            output(i,j) = this->mat[j][i];
        }
    }

    return output;

}

Matrix Matrix::inverse(){
// Only exists for square matrices with det != 0
    
    if (this->rows != this->cols){
        throw std::runtime_error("inverse() requires a square matrix");
    }

    if (std::abs(determinant()) < 1e-10){
        throw std::runtime_error("inverse() requires a non-singular matrix");
    }

    int n = this->rows;

    // Gauss-Jordan elimination
    Matrix augmented(n,2*n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            augmented(i,j) = this->mat[i][j];
        }
        augmented(i,i+n) = 1.;
    }

    int i=0;
    int j=0;

    bool pivot = false;
    //implement pivot finding here for stability of algorithm

    if (pivot){

    }

}

Matrix Matrix::identity(const int size){

    Matrix output(size, size, 0.);

    for (int i=0; i<size; i++){
        output(i,i) = 1.;
    }

    return output;

}
