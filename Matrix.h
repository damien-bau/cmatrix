#pragma once


class Matrix {

    public:
        Matrix(int, int);

        // Operator overloads
        Matrix& operator = (const Matrix&);
        friend Matrix operator + (const Matrix&, const Matrix&);
        friend Matrix operator - (const Matrix&, const Matrix&);
        friend Matrix operator * (const Matrix&, const Matrix&);
        friend Matrix operator * (double, const Matrix&);
        friend Matrix operator * (const Matrix&, double);
        friend Matrix operator / (const Matrix&, double);
        Matrix& operator += (const Matrix&);
        Matrix& operator -= (const Matrix&);
        Matrix& operator *= (const Matrix&);
        Matrix& operator *= (double);
        Matrix& operator /= (double);
        Matrix& operator ^ (int);


        // Member functions
        Matrix transpose();
        Matrix inverse();
        Matrix identity(int);
        Matrix dotproduct(Matrix, Matrix);
        Matrix crossproduct(Matrix, Matrix);

    private:
        int rows, cols;


};