#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include<iostream>

class Matrix
{
    int width_;
    int height_;
    double **mat_;
    int row_count;
    int column_count;

public:
    //konstruktory
    Matrix()=delete;
    Matrix(int width, int height);
    Matrix(const Matrix &source);
    Matrix(Matrix &&source);
    Matrix& operator=(const Matrix &source);

    //dlaczego przy operatorach zwracanie const& ma sens?
    //mozna np zwrocic void
    //pozwala tworzyc lancuchy operatorow =
    //v6 = v5 = v4 = v3 = v2 = v1
    //jednak gdy operator jest typu void v2 = v1 zwraca void i uniemozliwia dalszy lancuch
    //zwracanie calego wektora jest nieoptymalne, bo wywoluje konstruktor kopiujacy
    //referencja umozliwia robienie lancuchow i nie ma straty wydajnosci
    //
    //czy w setterze tak nie robic?
    //mozna zwracac referencje na obiekt, tylko po co?
    //umozliwia to : v3.x(2).y(2).z(3); !!!!!
    //wyglada naprawde czytelnie i prosto, zamiast rozbijania tego na trzy linijki
    //ale mozna zrobic to samo tak : v3 = Vector3D(2,2,3);
    //referencje lub wskazniki nie sa niczym zlym w wycieku
    
    Matrix& operator=(Matrix &&source);
    ~Matrix();

    //deklaracja przyjazni 
    friend std::ostream& operator<<(std::ostream &stream, const Matrix& source);

    //settery i gettery
    void set_element(int width, int height, double element);
    double get_element(int width, int height) const;
    int row_lenght() const;
    int column_height() const;

    
    //na po swietach operatory do wypisania na konsole, cin nie jest obowiazkowy
};

#endif