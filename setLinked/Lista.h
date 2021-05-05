#ifndef LISTA_H
#define LISTA_H
struct cell
    {
        int element;
        cell *next;
    };
class Lista
{
public:
    cell *header; // głowa listy
    Lista();                         //konstruktor
    ~Lista();                        //destruktor
    void Insert(int x, cell *p); // wstawia komórkę z elementem x na pozycję next komórki o wskaźniku p
                                     // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
    void Delete(cell *p);            // usuwa komórkę o wskaźniku p
    int Retrieve(cell *p);       // zwraca element komórki o wskaźniku p
    cell *Locate(int x);         // zwraca wskaźnik do pierwszej komórki z elementem x
    cell *First() const;                   // zwraca wskaźnik do pierwszej komórki na liście
    cell *Next(cell *p) const;             // zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
    cell *Previous(cell *p);         // zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
    cell *Last() const;                    // zwraca wskaźnik do ostatniej komórki na liście

    void print(); // wyświetla wszystkie elementy listy
};
#endif