#pragma once

#include<vector>


class Matrix {

    public:
        Matrix(int _rows, int _cols, const double _initval);
        Matrix();
        ~Matrix();
        Matrix(const Matrix& rhs);
        
        Matrix& operator=(const Matrix& rhs);

        // Operator overloads
        Matrix operator+(const double& rhs);
        Matrix operator-(const double& rhs);
        Matrix operator*(const double& rhs);
        Matrix operator/(const double& rhs);
        //Matrix operator^(const double& rhs);

        Matrix& operator=(const Matrix& rhs);
        Matrix operator+(const Matrix& rhs);
        Matrix operator-(const Matrix& rhs);
        Matrix operator*(const Matrix& rhs);
        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        Matrix& operator*=(const Matrix& rhs);

        std::vector<double> operator*(const std::vector<double>& rhs);

        double operator()(const int& row, int& col);
        const double operator()(const int& row, const int&col) const;


        // Member functions
        int get_rows() const;
        int get_cols() const;
        Matrix transpose();
        Matrix inverse();
        Matrix identity(int);
        Matrix dot(Matrix, Matrix);
        Matrix cross(Matrix, Matrix);

    private:

        std::vector<std::vector<double>> mat;
        int rows, cols;

};