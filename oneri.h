#ifndef ONERI_H
#define ONERI_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

class Random_secim {
private:
    vector<string> oneriler;
    vector<int> oneriler_sayi;
    string kategori_secim;
    string dosya_adi;
    string veri;
    string veri2;
    string esas_secim;
    string random_eleman;
    vector<vector<string>> secim_listesi;
    vector<string>dizi1;
    int kategori_no;

public:
    Random_secim();
};

#endif
