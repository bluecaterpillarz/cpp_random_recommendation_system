#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
#include "oneri.h"
using namespace std;

// String'i küçük harfe çevir
string kucuk_harfe_cevir(string str) {
    for(int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// Baþ ve sondaki boþluklarý temizle
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

Random_secim::Random_secim(){
    // Vektörleri temizle
    secim_listesi.clear();
    oneriler.clear();
    oneriler_sayi.clear();
    dizi1.clear();

    cout<<"ilgilendiginiz kategori icin ilgili sayiyi giriniz:\n1-spor\n2-film_dizi\n3-kitap\n";
    cin>>kategori_no;
    cin.ignore();

    if(kategori_no==1){
        kategori_secim="spor";
    }else if(kategori_no==2){
        kategori_secim="film_dizi";
    }else{
        kategori_secim="kitap";
    }

    dosya_adi=kategori_secim+".txt";
    ifstream dosya_oku("C:\\Users\\Toshiba\\Desktop\\"+dosya_adi);

    if(!dosya_oku.is_open()){
        cout<<"Dosya acilamadi"<<endl;
        return;
    }

    // DÜZELTME: Satýr satýr oku, ':' ile bitenleri kategori olarak iþaretle
    while (getline(dosya_oku, veri)){
        veri = trim(veri);

        // Satýr ':' ile bitiyorsa yeni kategori
        if(!veri.empty() && veri.back() == ':'){
            // Önceki kategoriyi kaydet
            if(!dizi1.empty()){
                secim_listesi.push_back(dizi1);
            }

            // Yeni kategori baþlat (: iþaretini kaldýr)
            dizi1.clear();
            dizi1.push_back(veri.substr(0, veri.length()-1));
        }
        else if(!veri.empty()){
            // Normal içerik satýrý
            dizi1.push_back(veri);
        }
    }

    // Son kategoriyi ekle
    if(!dizi1.empty()){
        secim_listesi.push_back(dizi1);
    }

    dosya_oku.close();

    // Random sayý üreteci
    random_device rd;
    mt19937 gen(rd());

    int boyut=secim_listesi.size();
    vector<string> gosterilen_elemanlar;

    cout<<"\nilginizi hangisi cekiyor:\n";

    for (int i=0; i<boyut; i++){
        int son_index = secim_listesi[i].size() - 1;

        if(son_index >= 1){  // En az 1 içerik olmalý
            uniform_int_distribution<> dis(1, son_index);
            int random_index = dis(gen);

            random_eleman = secim_listesi[i][random_index];
            gosterilen_elemanlar.push_back(random_eleman);

            cout << "  -> " << random_eleman << endl;
        }
    }

    cout<<"\nSeciminizi yazin: ";
    getline(cin, esas_secim);

    esas_secim = trim(esas_secim);
    string esas_secim_kucuk = kucuk_harfe_cevir(esas_secim);

    cout<<"\nSeciminiz: "<<esas_secim<<endl;

    bool bulundu = false;

    for (int i=0; i<secim_listesi.size() && !bulundu; i++){
        for(int j=1; j<secim_listesi[i].size(); j++){  // 0 kategori adý

            string eleman_kucuk = kucuk_harfe_cevir(secim_listesi[i][j]);

            if(eleman_kucuk == esas_secim_kucuk){
                bulundu = true;

                cout<<"\n=== "<<secim_listesi[i][0]<<" kategorisinden oneriler ===\n";

                int son_index = secim_listesi[i].size() - 1;

                for(int k=0; k<3; k++){
                    uniform_int_distribution<> dis(1, son_index);
                    int random_index = dis(gen);

                    while (find(oneriler_sayi.begin(), oneriler_sayi.end(), random_index) != oneriler_sayi.end()
                           || kucuk_harfe_cevir(secim_listesi[i][random_index]) == esas_secim_kucuk) {
                        random_index = dis(gen);
                    }

                    oneriler_sayi.push_back(random_index);
                    oneriler.push_back(secim_listesi[i][random_index]);
                }
                break;
            }
        }
    }

    if(!bulundu){
        cout<<"\n*** Secim bulunamadi! Lutfen gosterilen elemanlardan birini secin. ***\n";
    }else{
        cout<<"\nOnerilerimiz:\n";
        for(int i=0; i<oneriler.size(); i++){
            cout << (i+1) << ". " << oneriler[i] << endl;
        }
    }
}
