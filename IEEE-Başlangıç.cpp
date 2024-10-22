#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

//Ana değerler
int xB=0;
int yB=0;
int xH = 0;
int yH = 0;
double km=0;
short roket=5;
double kmo = 0;
bool T;

//fonksiyonlar
void Menu() {
    cout << "Kullanim Paneli :\n----------------------------------------" << endl;
    cout << "1 = Arac Durum Paneli" << endl;
    cout << "2 = Sehat Etme Paneli" << endl;
    cout << "3 = Roket Atma Paneli" << endl;
    cout << "4 = Örneklem Toplama Paneli" << endl;
    cout << "8 = Kontrol Panelini Cagir" << endl;
    cout << "9 = Programi Kapat" << endl;
}
void Durum() {
    cout << "-----------------------\nToplam Yol :" << km <<"\nKalan Roket Sayisi :"<< roket <<"\nKordinat (X,Y) = "<< xB <<","<< yB << endl;
}
float SehatEt(int xH,int yH,int xB,int yB) {
    int xF;
    int yF;
    if (xH >= xB) {
        xF = xH - xB;
    }
    else {
        xF = xB - xH;
    }
    if (yH >= yB) {
        yF = yH - yB;
    }
    else {
        yF = yB - yH;
    }
    double kmo = sqrt((xF * xF) + (yF * yF));
    
    switch (kmo < (double)100)
    {
    case 1:
        return kmo;
    case 0:
        cout << "\n--!!100km yi astiniz. islemi tekrar deneyin!!--\n" << endl;
        break;
    default:
        cout << "bir yanlıslık var. islemi tekrar deneyin..." << endl;
        break;
    }
}
bool RoketAt(int xH, int yH, int xB, int yB) {
    if ((xH = xB) && (yH = yB))
    {
        return false;
    }
    double kmo = sqrt((xH * xH) + (yH * yH));
    if (kmo < 3 ) 
    {
        cout << "--- Menzil Hatasi!! --- Cok yakın ---";
        return false;
    }
    if ( 100 < kmo) {
        cout << "--- Menzil Hatasi!! --- Cok uzak ---";
        return false;
    }
    roket--;
    if (roket == 0)
    {
        cout << "Roket arzası!! Roket yetersiz" << endl;
        return false;
    }
    return true;
}
bool Inceleme() {
    return true;
}

/* 
void SSModu(string girdi) { // Testing code
    int mod = girdi[0] - '0';  // MOD
    int xH = girdi[1] - '0';   // X koordinatı
    int yH = girdi[2] - '0';   // Y koordinatı

    
    if (mod == 2) {
        // araç sehat
        cout << "su an " << xB << " X ve " << yB << " Y konumundasiniz!" << endl;
        kmo = SehatEt(xH, yH, xB, yB);
        cout << "\nKat edilen mesafe --------->" << kmo << endl;
        km += kmo;
        cout << "Toplam Kat edilen mesafe -->" << km << endl;
        xB = xH;
        yB = yH;
        cout << "degerler_guncellendi" << endl;
    }
    else if (mod == 3) {
        //roket atma 
        cout << "su an " << xB << " X ve " << yB << " Y konumundasiniz!" << endl;
        
        bool atıs = true;
        double kmo = sqrt((xH * xH) + (yH * yH));
        
        
        if (roket == 0)
        {
            cout << "Roket arzası!! Roket yetersiz" << endl;
            atıs =false;
        }
        else {
            if ((xH = xB) && (yH = yB))
            {
                atıs = false;
            }
            else {
                if (kmo < 3)
                {
                    cout << "--- Menzil Hatasi!! --- Cok yakın ---";
                    atıs = false;
                }
                if (100 < kmo) {
                    cout << "--- Menzil Hatasi!! --- Cok uzak ---";
                    atıs = false;
                }
            }
            roket--;
        }

        if (atıs)
        {
            cout << "\n-- ROKET ATILDI. --\n\n";
        }
        else {
            cout << "\n-- ISLEM BASARISIZ!! --\n\n";
        }
    }
    else {
        cout << "\n---->  Gecersiz islem SSModu sonlandı <----\n" << endl;
        T = false;
    }
}*/





int main()
{
    cout << "Kullanici Hosgeldin!" << endl;
    Menu();
    
    do{
        short deger;
        cout << "\n--------------->> Kod = "; 
        cin >> deger;
        cout << "\n\n--  Uygulaniyor... --\n \n"<< endl;

        //fonksiyonlar 

        if (cin.fail()) { // harf girişi hatası
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // yanlış girişi temizle
            cout << "Yanlis Deger! Lutfen bir sayi girin." << endl;
            continue;
        }


        if (deger == 9) {
            cout << "Program Kapatiliyor..." << endl;
            break;
        }
        else if (deger == 8) {
            system("cls");
            Menu(); // menü değerlerini getirir kontol paneli
        }
        else if (deger == 1) {
            Durum(); // araç durum değerleri
        }
        else if (deger == 2) {
            // araç sehat
            cout << "su an " << xB << " X ve " << yB << " Y konumundasiniz!" << endl;
            cout << "Sehat etmek icin X ve Y degerlerini gir...  X ---> " ;
            cin >> xH;
            cout << "----------------------Y degerini gir...     Y ---> " ;
            cin >> yH;
            kmo = SehatEt(xH,yH,xB,yB);
            cout << "\nKat edilen mesafe --------->"<< kmo << endl;
            km += kmo;
            cout << "Toplam Kat edilen mesafe -->" << km << endl;
            xB = xH;
            yB = yH;
            cout << "degerler_guncellendi"<<endl;
        }
        else if (deger == 3) {
            //roket atma 
            cout << "su an " << xB << " X ve " << yB << " Y konumundasiniz!" << endl;
            cout << "ROKET ATMAK icin X ve Y degerlerini gir...  X ---> ";
            cin >> xH;
            cout << "----------------------Y degerini gir...     Y ---> ";
            cin >> yH;
            bool atıs = RoketAt(xH, yH, xB, yB);
            if (atıs)
            {
                cout << "\n-- ROKET ATILDI. --\n\n";
            }
            else {
                cout << "\n-- ISLEM BASARISIZ!! --\n\n";
            }
        }
        else if (deger == 4) {
            if (Inceleme()) {
                cout << "incelme basarili. Orneklem toplandi";
            }
            else {
                cout << "inceleme basarisiz!!";
            }
        }
        /*else if (deger == 11) { // Testing code
            T = true;
            while(T)
            {
                string vir = ",";
                
                string girdi;
                cout << "\n||     sehat parametresi ve ya roket paremetresiyle 3 basamakli veri girin 2.. 3..     ||\n" << endl;
                cin >> girdi;
                bool strdgr1 = girdi[1] == vir;
                if (isdigit(girdi[0]) && strdgr1 && isdigit(girdi[2])) {
                    SSModu(girdi);
                }
                else {
                    cout << "\n---->  Gecersiz islem SSModu sonlandı <----\n" << endl;
                    break;
                }
            }
        }*/
        else {
            cout << "Yanlis Deger!\n -----> Sadece Kod 8 icindeki Kodları girin. <-----" << endl;
        }

    } while (true);

    return 0;
}