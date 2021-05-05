#include <iostream>
// #include "Zbior.h"
#include "Lista.h"

int main()
{
    Lista list1;
    list1.Insert(1, nullptr);
    list1.Insert(10, nullptr);                  // przy nastepnym wstawianiu po nullptr sie wysypuje
    list1.Insert(2, list1.Locate(1));                          
    list1.Insert(3, list1.Locate(2));
    list1.Insert(4, list1.Locate(3));
    list1.Insert(5, list1.Locate(4));
    if(list1.Locate(20) == nullptr) std::cout<<"nie ma takiej liczby"<<list1.Locate(20)<<std::endl;

    list1.print();

    list1.Delete(list1.First());
    list1.Delete(list1.First());
    list1.Delete(list1.First());
    list1.Delete(list1.First());
    list1.Delete(list1.First());


    list1.print();
    std::cout << list1.Retrieve(list1.First()) << std::endl;      // wysypie sie - brak elementu do pobrania      

    list1.Insert(1, nullptr);
    list1.print();

    list1.Delete(list1.Locate(1));
    list1.Delete(list1.Locate(1));                                  // nie ma takiego elementu
    list1.Delete(nullptr);
    list1.print();
        

/*
    list1.Insert(3, nullptr);
    list1.Insert(2, list1.header);
    cell temp;
    temp = *list1.Locate(2);
    std::cout<<"pierwsza komorka trzymajaca 2 wskazuje na komorke: "<<temp.next<<std::endl;
    list1.Insert(4,list1.header);
    list1.Insert(5,list1.header);
    list1.Insert(8,list1.header);
    list1.Insert(7,list1.header);
    temp = *list1.Last();
    std::cout<<"ostatnia komorka listy ma wartosc: "<<temp.element<<" i wskazuje na: "<<temp.next<<std::endl;
    list1.print();
    cell temp2;
    temp2 = *list1.Previous(&temp);
    std::cout<<"przedostatnia komorka listy ma wartosc: "<<temp2.element<<" i wskazuje na: "<<temp2.next<<std::endl;
    list1.Delete(list1.Locate(8));
    list1.print();
*/

    return 0;
}

// int main()
// {
//     int tab1[] = {1,2,3,4,5};
//     Zbior set1(tab1, 5);
//     set1.wypisz();
//     set1.dodajElement(8);
//     set1.wypisz();
//     set1.dodajElement(5);
//     set1.wypisz();
//     set1.usunElement(4);
//     std::cout<<"set1: ";
//     set1.wypisz();
//     int tab2[] = {2,3,6,5};
//     Zbior set2(tab2, 4);
//     std::cout<<"set2: ";
//     set2.wypisz();
//     Zbior set3 = set1.sumaZbiorow(set2);
//     std::cout<<"suma zbiorow set1 i set2: ";
//     set3.wypisz();
//     Zbior set4 = set1.iloczynZbiorow(set2);
//     std::cout<<"iloczyn zbiorow set1 i set2: ";
//     set4.wypisz();
//     Zbior set5 = set1.roznicaZbiorow(set2);
//     std::cout<<"roznica zbiorow set1 i set2: ";
//     set5.wypisz();
//     Zbior set6(tab1,5);
//     std::cout<<"set6: ";
//     set6.wypisz();
//     if(set1.relacjaRownosci(set6)) std::cout<<"set1 i set6 sa rowne"<<std::endl;
//     else std::cout<<"set1 i set6 nie sa rowne"<<std::endl;
//     set6.usunElement(1);
//     std::cout<<"set6: ";
//     set6.wypisz();
//     if(set2.relacjaRownolicznosci(set6)) std::cout<<"set1 i set6 sa rownoliczne"<<std::endl;
//     else std::cout<<"set1 i set6 nie sa rownoliczne"<<std::endl;
//     set6.wyczysc();
//     std::cout<<"set6: ";
//     set6.wypisz();
//     Zbior set7(tab1, 5);
//     set7.usunElement(2);
//     set7.usunElement(4);
//     std::cout<<"set7: ";
//     set7.wypisz();
//     if(set1.relacjaRownolicznosci(set7)) std::cout<<"set7 zawiera sie w set1"<<std::endl;
//     else std::cout<<"set7 nie zawiera sie w set1"<<std::endl;

//     return 0;

// }