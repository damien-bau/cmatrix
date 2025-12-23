#include "Matrix.h"


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

double Matrix::determinant(){
    
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

}

Matrix Matrix::identity(const int size){

    Matrix output(size, size, 0.);

    for (int i=0; i<size; i++){
        output(i,i) = 1.;
    }

    return output;

}
