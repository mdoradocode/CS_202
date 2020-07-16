#include <iostream>
#include <string.h>
#pragma once

using namespace std;

class Matrix{
    public:
    Matrix(){
        m_rows = 0;
        m_cols = 0;
        m_matrix = NULL;
    }

    Martix(int row, int col, int value = 0){
        m_rows = row;
        m_cols = col;

        for(int i = 0; i < row; i++){
            m_matrix[i] = new int[m_cols];
            for(int j = 0; j < col; j++){
                m_matrix[i][j] = value;
            }
        }

    }

    Matrix(const Matrix &obj){
        m_rows = obj.m_rows;
        m_cols = obj.m_cols;
        m_matrix = new int [m_rows];
        for(int i = 0; i < obj.m_rows; i++){
            m_matrix[i] = new int[m_cols];
            for(int j = 0; j < obj.m_cols; j++){
                m_matrix[i][j] = obj.m_matrix[i][j];
            }
        }
    }

    ~Matrix(){
        for(int i = 0; i < m_rows; i++){
            delete [] m_matrix[i];
        }
        delete [] m_matrix;
    }

    Matrix & operator=(const Matrix &obj){
        for(int i = 0; i < m_rows; i++){
            delete [] m_matrix[i];
        }
        delete [] m_matrix;
        m_rows = obj.m_rows;
        m_cols = obj.m_cols;
        m_matrix = new int [m_rows];
        for(int i = 0; i < m_rows; i++){
            m_matrix = new int[m_cols];
            for(int j = 0; j < m_cols; j++){
                m_matrix[i][j] = obj.m_matrix[i][j];
            }
        }

    }

    private:
        int m_rows;
        int m_cols;
        int ** m_matrix;
};