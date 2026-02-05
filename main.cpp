#include <iostream>
#include "oneri.h"

using namespace std;
char devam;

int main()
{
    do{
    Random_secim deneme;
    cout<<"Devam edecek misiniz: ";
    cin>>devam;
    cin.ignore();  // Buffer'ý temizle - ÖNEMLÝ!
    }while(tolower(devam)=='e');

}
