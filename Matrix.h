#pragma once

#include<vector>


class Matrix {

    public:
        Matrix(int _rows, int _cols, const double _initval);
        Matrix();
        ~Matrix();
        Matrix(const Matrix& rhs);
        
        Matrix& operator=(const Matrix& rhs);

        // Scalar operators
        Matrix operator+(const double& rhs);
        Matrix operator-(const double& rhs);
        Matrix operator*(const double& rhs);
        Matrix operator/(const double& rhs);
        Matrix& operator+=(const double& rhs);
        Matrix& operator-=(const double& rhs);
        Matrix& operator*=(const double& rhs);
        Matrix& operator/=(const double& rhs);
        //Matrix operator^(const double& rhs);

        // Matrix operators
        Matrix operator+(const Matrix& rhs);
        Matrix operator-(const Matrix& rhs);
        Matrix operator*(const Matrix& rhs);
        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        Matrix& operator*=(const Matrix& rhs);

        std::vector<double> operator*(const std::vector<double>& rhs);

        double& operator()(const int& row, const int& col);
        const double& operator()(const int& row, const int&col) const;


        // Member functions
        int get_rows() const;
        int get_cols() const;
        double determinant();
        Matrix transpose();
        Matrix inverse();
        Matrix identity(const int size);

    private:
        std::vector<std::vector<double>> mat;
        int rows, cols;

};