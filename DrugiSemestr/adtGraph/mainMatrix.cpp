#include<iostream>
#include<iomanip>
#include"matrix.h"

std::ostream& operator<<(std::ostream &stream, const Matrix& source)
{
    
        for(int i = 0; i < source.height_; i++ )
    {
        stream <<"|";
        for(int j = 0; j < source.width_; j++)
        {
            stream<<std::setw(3);
            stream<<source.mat_[i][j];
            if(j<source.width_ - 1) stream<<" ";
        }
        stream<<std::setw(3);
        stream<<"|"<<std::endl;
    }
    stream << std::endl<<std::endl;
    return stream;
}
int main()
{
    
    Matrix macierz1(3,4);
    macierz1.set_element(3,2,15);
    std::cout<<macierz1;
    
    Matrix macierz2(5,6);//c-tor
    macierz1=macierz2; //ca op=
    std::cout<<macierz1;

    Matrix macierz3(4,5); //c-tor
    Matrix macierz4=std::move(macierz1);//move c-tor
    macierz4.set_element(1,1,5);
    std::cout<<macierz4;

    Matrix macierz6(3,2);
    Matrix macierz5 = macierz6;
    std::cout<<macierz5;
    
    return 0;
}