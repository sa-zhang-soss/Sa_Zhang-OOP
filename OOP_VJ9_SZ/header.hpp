#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <cmath>
// prvi
template <typename T>
T mymin(T& a, T& b) {
    return (a < b) ? a : b;
}

// drugi 
template <typename T>
class Skup {
    std::vector<T> s;
public:

    void dodaj(T n) {
        s.push_back(n);
    }
    void izbrisi() {
        s.pop_back();
    }
    void get(T n) {
        if (std::count(s.begin(), s.end(), n))
            std::cout << n <<" je u skupu" << std::endl;
        else 
            std::cout << n <<" nije u skupu" << std::endl;
    }
};

// treci 

template <typename T>
void mysort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                T tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

template<>
void mysort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tolower(arr[i]) > tolower(arr[j])) {
                char tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

// cetvrti

void file_function(std::string& filename, std::string& substring) {

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "file se nije otvorio" << std::endl;
        return;
    }
    // napuni vektor
    std::vector<std::string> rijeci;
    std::istream_iterator<std::string> start(file), end;
    rijeci.assign(start, end);
    file.close();
    // izbaci stringove
    rijeci.erase(
        std::remove_if(
            rijeci.begin(), rijeci.end(),[&substring](std::string& word) {
                return word.find(substring) != std::string::npos;
             }
        ),
        rijeci.end()
    );
    // trnsforma
    std::transform(
        rijeci.begin(), rijeci.end(), rijeci.begin(),
        [](std::string& word) {
            std::transform(word.begin(), word.end(), word.begin(), ::toupper);
            return word;
        }
    );

    for (std::string& word : rijeci) {
        std::cout << word << " ";
    }
}

// peti
struct Point {
    int x, y;

    Point(int x = 0, int y =0) : x(x), y(y){}

    double udaljenostOdOrigin() {
        return std::sqrt(x * x + y * y);
    }
};

void point_function(std::string& filename, int odredena_udaljenost, Point& zamjena) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "file se nije otvorio" << std::endl;
        return;
    }

    std::vector<Point> tocke;
    std::istream_iterator<int> start(file), end;

    while (start != end) {
        int x = *start++;
        int y = *start++;
        tocke.emplace_back(x, y);
    }
    file.close();

    std::sort(tocke.begin(), tocke.end(), [](Point& a, Point& b) {
        return a.udaljenostOdOrigin() < b.udaljenostOdOrigin();
        });

    std::replace_if(tocke.begin(), tocke.end(), [odredena_udaljenost](Point& p) {
        return std::abs(p.udaljenostOdOrigin() - odredena_udaljenost) < 1e-9;
        },
        zamjena);

    for (Point& tocka : tocke) {
        std::cout << "(" << tocka.x << ", " << tocka.y << ")" << " ";
    }
}