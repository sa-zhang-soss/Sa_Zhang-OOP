#include "header.hpp"
#include <iostream>
#include <string>

int main() {
    // prvi
    int x = 10;
    int y = 20;
    std::cout << "manji broj je: " << mymin(x, y) << std::endl;

    std::string str1 = "jabuka";
    std::string str2 = "banana";
    std::cout << "manji string je: " << mymin(str1, str2) << std::endl;
    std::cout << "-------------------------- " << std::endl;
    // drugi
    
    Skup <int> s;
    s.dodaj(1);
    s.dodaj(2);
    s.izbrisi();
    s.get(1);
    s.get(2);
    std::cout << "-------------------------- " << std::endl;
    // treci

    int arr1[] = { 2,3,5,6,8,5,1 };
    char arr2[] = { 'z','G','b','l','c','A'};
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(char);

    mysort(arr1, n1);
    mysort(arr2, n2);

    for (int i = 0; i < n1; i++) {
        std::cout << arr1[i] ;
    }
    std::cout << " " << std::endl;
    for (int i = 0; i < n2; i++) {
        std::cout << arr2[i];
    }
    std::cout << std::endl;
    std::cout << "-------------------------- " << std::endl;
    // cetvrti
    
    std::string filename = "words.txt";
    std::string substring = "faks";
    file_function(filename, substring);

    std::cout << std::endl;
    std::cout << "-------------------------- " << std::endl;
    // peti
    std::string filenamee = "tocke.txt";
    int odredena_udaljenost = 2;
    Point zamjena(1, 1);
    point_function(filenamee, odredena_udaljenost, zamjena);

    return 0;
}