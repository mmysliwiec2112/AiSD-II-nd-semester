#pragma once


struct cell
    {
        int element;
        int node;
        cell *next;
    };
class Lista
{
public:
    cell *header; // głowa listy
    int size = 0;
    Lista();                         //konstruktor
    ~Lista();                        //destruktor

    Lista& operator=(const Lista& source);
    Lista& operator=(Lista&& source);
    void Insert(int x, cell *p, int node); // wstawia komórkę z elementem x na pozycję next komórki o wskaźniku p
                                     // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
    void Delete(cell *p);            // usuwa komórkę o wskaźniku p
    // void DeleteNode(int x);
    int Retrieve(cell *p);       // zwraca element komórki o wskaźniku p
    cell *Locate(int x) const;         // zwraca wskaźnik do pierwszej komórki z elementem 
    cell *Locate(int x, int y);
    cell *LocateNode(int y);
    cell *First() const;                   // zwraca wskaźnik do pierwszej komórki na liście
    cell *Next(cell *p) const;             // zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
    cell *Previous(cell *p);         // zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
    cell *Last() const;                    // zwraca wskaźnik do ostatniej komórki na liście
    void clear();

    void print(); // wyświetla wszystkie elementy listy
};
