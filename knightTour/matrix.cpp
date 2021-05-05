#include"matrix.h"
#include<iostream>

Matrix::Matrix(int width, int height): width_(width), height_(height), mat_(new double* [height])
{
    for(int i = 0; i < height; i++)
    {
          mat_[i]=new double[width]; 
          for(int j = 0; j < width; j++)
          {
              mat_[i][j] = 0;
          }   
    }
}
Matrix::Matrix(const Matrix &source): width_(source.width_), height_(source.height_), mat_(new double* [source.height_])
{
    for(std::size_t i = 0u; i < height_; i++)
    {
        mat_[i]=new double[width_]; 
        for(std::size_t j = 0u; j < width_; j++)
        {
            mat_[i][j] = source.mat_[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&source): width_(source.width_), height_(source.height_), mat_(new double* [source.height_])
{
    for(int i = 0u; i < height_; i++)
    {
        mat_[i] = new double [source.width_];
        for(std::size_t j = 0u; j < width_; j++)
          {
              mat_[i][j] = source.mat_[i][j];
          }   
    }
    source.width_ = 0;
    source.height_ = 0;
    for(int i = 0u; i < height_; i++)
    {
        delete[] source.mat_[i];
    }
    delete[] source.mat_;
    source.mat_=nullptr;
}

Matrix& Matrix::operator=(const Matrix &source)
{
    if(this!= &source)
    {
         for(std::size_t i = 0; i < height_; i++)
        {
            delete[] mat_[i];
        }
        delete[] mat_;

        width_=source.width_;
        height_=source.height_;
        mat_=new double*[height_];
        for(std::size_t i = 0u; i < height_; i ++)
        {
            mat_[i]=new double[width_];
            for(std::size_t j = 0u; j < width_; j++)
          {
              mat_[i][j] = source.mat_[i][j];
          }   
        }
    }
    return *this;
    
}
Matrix& Matrix::operator=(Matrix &&source)
{
    if(this!=&source)
    {
    for(std::size_t i = 0; i < height_; i++)
        {
            delete[] source.mat_[i];
        }
    delete[] mat_;
    width_=source.width_;
    height_=source.height_;
    mat_=source.mat_;
    source.width_ = 0u;
    source.height_ = 0u;
     for(int i = 0u; i < height_; i++)
    {
        delete[] mat_[i];
    }
    source.mat_=nullptr;;
    }
    return *this;
}


Matrix::~Matrix()
{
    for(std::size_t i = 0; i < height_; i++)
    {
        delete[] mat_[i];
    }
    delete[] mat_;
}

void Matrix::set_element(int height, int width, double element)
{
    mat_[height][width] = element;
}
double Matrix::get_element(int height, int width) const
{
    return mat_[height][width];
}
int Matrix::row_lenght() const
{
    return height_;
}
int Matrix::column_height() const
{
    return width_;
}
