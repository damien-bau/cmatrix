#pragma once


class Matrix {

    public:
        Matrix(int, int);

        // Operator overloads
        Matrix& operator +=(const Matrix&);
        Matrix& operator -=(const Matrix&);
        Matrix& operator *=(const Matrix&);
        Matrix& operator /=(const Matrix&);
        Matrix& operator ^(const Matrix&);


};