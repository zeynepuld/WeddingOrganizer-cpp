/****************************************************************************
**					   SAKARYA ÜNİVERSİTESİ
**			   BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				      PROGRAMLAMAYA GİRİŞ DERSİ
**
**				ÖDEV NUMARASI....: Proje
**				ÖĞRENCİ ADI......: Zeynep Uludağ
**				ÖĞRENCİ NUMARASI.: B241210029
**				DERS GRUBU.......: A
****************************************************************************/

#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Dugun { // dugun bilgileri burada tutulacak
public:
    int dugunNo;              
    string davetlilerDosyasi; // davetliler dosyasi adi
    string patron;            // parayi odeyecek kisi
    string tarih;             
    string saat;              
    string damatAdi;          
    string damatBabaAdi;      
    string gelinAdi;          
    string gelinAnneAdi;      
    string patronTel;         
    string damatTel;          
    int salonNo;              
    int kisiSayisi;           // toplam davetli kisi sayisi
    double toplamUcret;       // dugundeki toplam ucret
    
    Dugun() { // yapici fonksiyon
        dugunNo = 0;
        davetlilerDosyasi = "";
        patron = "";
        tarih = "";
        saat = "";
        damatAdi = "";
        damatBabaAdi = "";
        gelinAdi = "";
        gelinAnneAdi = "";
        patronTel = "";
        damatTel = "";
        salonNo = 0;
        kisiSayisi = 0;
        toplamUcret = 0.0;
    }
    
    void dosyayaYaz(ofstream &dosya) { // dosyaya yazdirma fonksiyonu
        dosya << dugunNo << "|" << davetlilerDosyasi << "|" << patron << "|" 
              << tarih << "|" << saat << "|" << damatAdi << "|" << damatBabaAdi << "|" 
              << gelinAdi << "|" << gelinAnneAdi << "|" << patronTel << "|" 
              << damatTel << "|" << salonNo << "|" << kisiSayisi << "|" 
              << toplamUcret << "\n";
    }
    
    void ekranaYaz() { // ekrana yazdirma fonksiyonu
        cout << "Dugun No         : " << dugunNo << endl;
        cout << "Davetliler Dosya : " << davetlilerDosyasi << endl;
        cout << "Patron           : " << patron << endl;
        cout << "Tarih            : " << tarih << endl;
        cout << "Saat             : " << saat << endl;
        cout << "Damat Adi        : " << damatAdi << endl;
        cout << "Damat Baba Adi   : " << damatBabaAdi << endl;
        cout << "Gelin Adi        : " << gelinAdi << endl;
        cout << "Gelin Anne Adi   : " << gelinAnneAdi << endl;
        cout << "Patron Tel       : " << patronTel << endl;
        cout << "Damat Tel        : " << damatTel << endl;
        cout << "Salon No         : " << salonNo << endl;
        cout << "Kisi Sayisi      : " << kisiSayisi << endl;
        cout << "Toplam Ucret     : " << toplamUcret << " TL" << endl;
    }
};

class Davetliler { // davetli bilgileri bu sinifta tutulacak
public:
    int dugunNo; // dugun No uzerinden iliski kurulacagi icin hangi dugune ait oldugu sorgulanacak burda
    int no;
    string adi;
    string soyadi;
    string akrabalik; // gelin ya da damat tarafi oldugu. masaya ona gore yerlesitirlecekler
    string adres;
    string telefon;
    char gelecekMi; // davetlilerden gelecek ve gelmeyecek olanlarin listesinin utuulabilmesi icin. e/h seklinde belirlenecek.
    
    Davetliler() { // davetliler yapici fonksiyonu
        dugunNo = 0;
        no = 0;
        adi = "";
        soyadi = "";
        akrabalik = "";
        adres = "";
        telefon = "";
        gelecekMi = 'h';
    }
    
    void dosyayaYaz(ofstream &dosya) { // txt dosyasina yazdirma fonksyionu
        dosya << dugunNo << "|" << no << "|" << adi << "|" << soyadi << "|" 
              << akrabalik << "|" << adres << "|" << telefon << "|" << gelecekMi << "\n";
    }
    
    void ekranaYaz() { // konsol ekranina yazdiracak fonskyion
        cout << "Dugun No    : " << dugunNo << endl;
        cout << "Davetli No  : " << no << endl;
        cout << "Adi         : " << adi << endl;
        cout << "Soyadi      : " << soyadi << endl;
        cout << "Akrabalik   : " << akrabalik << endl;
        cout << "Adres       : " << adres << endl;
        cout << "Telefon     : " << telefon << endl;
        cout << "Gelecek Mi  : " << (gelecekMi == 'e' ? "Evet" : "Hayir") << endl;
    }
};

class Masraf { // masraf bilgileri bu sinifta tutulacak
public:
    int dugunNo; // hangi dugune ait oldugu - iliski icin onemli
    string tur;   // masraf turu. yemek, aksesuar, sanatci
    string aciklama; // masraf aciklamasi
    double fiyat; // birim fiyat. toplam fiyat bulunurken adet ile carpilacak
    int adet; // adet
    
    Masraf() { // yapici fonksiyon
        dugunNo = 0;
        tur = "";
        aciklama = "";
        fiyat = 0.0;
        adet = 0;
    }
    
    void dosyayaYaz(ofstream &dosya) { // txt dosyasina yazdirma
        dosya << dugunNo << "|" << tur << "|" << aciklama << "|" << fiyat << "|" << adet << "\n";
    }
    
    double toplamHesapla() { // toplam masrafi hesaplamak icin
        return fiyat * adet;
    }
};

// MENU FONKSIYONLARI

void anaMenu() { // program baslatilginda ilk menu bu cikacak
    cout << "\n========== DUGUN ORGANIZASYONU ==========\n";
    cout << "1) Dugun Kayit Islemleri\n";
    cout << "2) Davetli Kayit Islemleri\n";
    cout << "3) Masraf ve Yemek Kayit Islemleri\n";
    cout << "4) Raporlar\n";
    cout << "5) Cikis\n";
    cout << "Seciminiz: ";
}

void dugunMenu() { // dugun islemleri icin alt menu
    cout << "\n----- DUGUN ISLEMLERI -----\n";
    cout << "1) Yeni Dugun Ekle\n";
    cout << "2) Dugun Ara\n";
    cout << "3) Dugun Guncelle\n";
    cout << "4) Dugun Sil\n";
    cout << "5) Tum Dugunleri Listele\n";
    cout << "6) DETAYLI DUGUN SORGULAMA (Coklu Dosya Okuma)\n";
    cout << "7) Ana Menuye Don\n";
    cout << "Seciminiz: ";
}

void davetliMenu() { // davetli islemleri icin alt menu
    cout << "\n----- DAVETLI ISLEMLERI -----\n";
    cout << "1) Yeni Davetli Ekle\n";
    cout << "2) Davetli Ara\n";
    cout << "3) Davetli Guncelle\n";
    cout << "4) Davetli Sil\n";
    cout << "5) Tum Davetlileri Listele\n";
    cout << "6) Ana Menuye Don\n";
    cout << "Seciminiz: ";
}

void masrafMenu() { // masraf islemleri icin alt menu
    cout << "\n----- MASRAF ve YEMEK ISLEMLERI -----\n";
    cout << "1) Yemek Ekle\n";
    cout << "2) Aksesuar Ekle\n";
    cout << "3) Sanatci Ekle\n";
    cout << "4) Tum Masraflari Listele\n";
    cout << "5) Toplam Maliyet Hesapla\n";
    cout << "6) Ana Menuye Don\n";
    cout << "Seciminiz: ";
}

void raporMenu() { // rapor islemleri icin alt menu
    cout << "\n----- RAPORLAR -----\n";
    cout << "1) Dugune Geleceklerin Listesi\n";
    cout << "2) Dugune Gelemeyeceklerin Listesi\n";
    cout << "3) Oturma Duzeni\n";
    cout << "4) Ana Menuye Don\n";
    cout << "Seciminiz: ";
}

// DUGUN ISLEMLERI

void dugunEkle() { // yeni dugun ekleme fonksiyonu
    ofstream dosya; // dugunler.txt dosyasina yazdirma icin
    dosya.open("Dugunler.txt", ios::app); // dugunler.txt dosyasina ekleme icin
    
    Dugun d; // dugun sinifi nesnesi olustur
    char devam = 'e'; // devam etmek isteyip istemedigini belirlemek icin. e evet demek
    
    do {
        cout << "\n--- Yeni Dugun Kaydi ---\n";
        cout << "Dugun No: "; cin >> d.dugunNo;
        cin.ignore();

        d.davetlilerDosyasi = "Davetliler_" + to_string(d.dugunNo) + ".txt"; // dugun icin davetliler dosyasi olusturulur
        cout << "Patron: "; getline(cin, d.patron);
        cout << "Tarih: "; getline(cin, d.tarih);
        cout << "Saat: "; getline(cin, d.saat);
        cout << "Damat Adi: "; getline(cin, d.damatAdi);
        cout << "Damadin Baba Adi: "; getline(cin, d.damatBabaAdi);
        cout << "Gelin Adi: "; getline(cin, d.gelinAdi);
        cout << "Gelinin Anne Adi: "; getline(cin, d.gelinAnneAdi);
        cout << "Patron Telefonu: "; getline(cin, d.patronTel);
        cout << "Damat Telefonu: "; getline(cin, d.damatTel);
        cout << "Salon No: "; cin >> d.salonNo;
        cout << "Kisi Sayisi: "; cin >> d.kisiSayisi;
        cout << "Toplam Ucret: "; cin >> d.toplamUcret;
        
        d.dosyayaYaz(dosya); // dugun sinifinin dosyayaYaz fonksiyonu kullaniliyr dugunler.txt dosyasina ekleme icin
        
        cout << "\nDugun kaydi eklendi!\n";
        cout << "Davetliler dosyasi: " << d.davetlilerDosyasi << endl;  // dugun icin davetliler dosyasi olusturuluyor
        cout << "Baska kayit eklemek ister misiniz? (e/h): "; cin >> devam; // e basarsa devam edecek h basarsa bir onceki menuye donulecek
    } while (devam == 'e' || devam == 'E'); // buyuk kucuk hard duyarliligi icin.
    
    dosya.close(); // dosyayi kapattim
}

void dugunAra() {
    ifstream dosya("Dugunler.txt"); // dugunler.txt dosyasindan okuma icin
    if (!dosya) { // dosya acilamiyorsa hata verir
        cout << "Dugun dosyasi bulunamadi!\n";
        return;
    }
    
    int arananNo; // aranacak dugun no
    cout << "Aramak istediginiz Dugun No: "; cin >> arananNo;
    
    string satir;
    bool bulundu = false; // dugunun bulunup bulunmadigini kontrol eder
    
    while (getline(dosya, satir)) { // dosyadaki satirlari okur
        int dugunNo;
        string patron, tarih, saat, damatAdi, damatBabaAdi, gelinAdi, gelinAnneAdi;
        string patronTel, damatTel;
        int salonNo, kisiSayisi;
        double toplamUcret;
        
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        
        while ((pos = temp.find("|")) != string::npos) { // satirin icindeki alanlari bulacak. 
            token = temp.substr(0, pos);
            switch(alan) { // dugun sinifinin ozelliklerini okuyor
                case 0: dugunNo = stoi(token); break;
                case 1: patron = token; break;
                case 2: tarih = token; break;
                case 3: saat = token; break;
                case 4: damatAdi = token; break;
                case 5: damatBabaAdi = token; break;
                case 6: gelinAdi = token; break;
                case 7: gelinAnneAdi = token; break;
                case 8: patronTel = token; break;
                case 9: damatTel = token; break;
                case 10: salonNo = stoi(token); break;
                case 11: kisiSayisi = stoi(token); break;
            }
            temp.erase(0, pos + 1); 
            alan++;
        }
        toplamUcret = stod(temp); 
        
        if (dugunNo == arananNo) { // dugunun bulunup bulunmadigini kontrol eder
            bulundu = true;
            cout << "\n===== DUGUN BILGILERI =====\n";
            cout << "Dugun No      : " << dugunNo << endl;
            cout << "Patron        : " << patron << endl;
            cout << "Tarih         : " << tarih << endl;
            cout << "Saat          : " << saat << endl;
            cout << "Damat Adi     : " << damatAdi << endl;
            cout << "Damat Baba Adi: " << damatBabaAdi << endl;
            cout << "Gelin Adi     : " << gelinAdi << endl;
            cout << "Gelin Anne Adi: " << gelinAnneAdi << endl;
            cout << "Patron Tel    : " << patronTel << endl;
            cout << "Damat Tel     : " << damatTel << endl;
            cout << "Salon No      : " << salonNo << endl;
            cout << "Kisi Sayisi   : " << kisiSayisi << endl;
            cout << "Toplam Ucret  : " << toplamUcret << " TL\n";
            break;
        }
    }
    
    if (!bulundu) { // dugun bulunmadiysa hata mesaji
        cout << "Dugun bulunamadi!\n";
    }
    
    dosya.close();
}

void dugunGuncelle() { // dugun ozelliklerini guncelleme fonksiyonu
    ifstream dosyaOku("Dugunler.txt");
    if (!dosyaOku) {
        cout << "Dugun dosyasi bulunamadi!\n";
        return;
    }
    
    ofstream dosyaYaz("Dugunler_temp.txt");
    
    int arananNo;
    cout << "Guncellemek istediginiz Dugun No: "; cin >> arananNo;
    cin.ignore();
    
    string satir;
    bool bulundu = false;
    
    while (getline(dosyaOku, satir)) {
        size_t pos = satir.find("|");
        int dugunNo = stoi(satir.substr(0, pos));
        
        if (dugunNo == arananNo) {
            bulundu = true;
            cout << "\n--- Yeni Bilgileri Girin ---\n";
            
            string patron, tarih, saat, damatAdi, damatBabaAdi, gelinAdi, gelinAnneAdi;
            string patronTel, damatTel;
            int salonNo, kisiSayisi;
            double toplamUcret;
            
            cout << "Patron: "; getline(cin, patron);
            cout << "Tarih: "; getline(cin, tarih);
            cout << "Saat: "; getline(cin, saat);
            cout << "Damat Adi: "; getline(cin, damatAdi);
            cout << "Damadin Baba Adi: "; getline(cin, damatBabaAdi);
            cout << "Gelin Adi: "; getline(cin, gelinAdi);
            cout << "Gelinin Anne Adi: "; getline(cin, gelinAnneAdi);
            cout << "Patron Telefonu: "; getline(cin, patronTel);
            cout << "Damat Telefonu: "; getline(cin, damatTel);
            cout << "Salon No: "; cin >> salonNo;
            cout << "Kisi Sayisi: "; cin >> kisiSayisi;
            cout << "Toplam Ucret: "; cin >> toplamUcret;
            
            dosyaYaz << dugunNo << "|" << patron << "|" << tarih << "|" << saat << "|"
                     << damatAdi << "|" << damatBabaAdi << "|" << gelinAdi << "|" << gelinAnneAdi << "|"
                     << patronTel << "|" << damatTel << "|" << salonNo << "|" << kisiSayisi << "|"
                     << toplamUcret << "\n";
            
            cout << "\nDugun guncellendi!\n";
        } else {
            dosyaYaz << satir << "\n";
        }
    }
    
    if (!bulundu) {
        cout << "Dugun bulunamadi!\n";
    }
    
    dosyaOku.close();
    dosyaYaz.close();
    
    remove("Dugunler.txt");
    rename("Dugunler_temp.txt", "Dugunler.txt");
}

void dugunSil() { // dugunNo ile secili dugunu silme fonksiyonu
    ifstream dosyaOku("Dugunler.txt");
    if (!dosyaOku) {
        cout << "Dugun dosyasi bulunamadi!\n";
        return;
    }
    
    ofstream dosyaYaz("Dugunler_temp.txt"); // dugunler.txt dosyasindan okunan dugunler temp.txt dosyasina yazilir
    
    int arananNo;
    cout << "Silmek istediginiz Dugun No: "; cin >> arananNo;
    
    string satir;
    bool bulundu = false;
    
    while (getline(dosyaOku, satir)) { // dugunler.txt dugunler okunacak ve temp.txt dosyasina yazilacak
        size_t pos = satir.find("|"); // her | isaretini gordugunde o kisma kadar olan kismi ozellik olarak alacak
        int dugunNo = stoi(satir.substr(0, pos)); // dugunNo ozelligini alacak
        
        if (dugunNo == arananNo) { // dugunNo ozelligini arayacak
            bulundu = true;
            cout << "Dugun silindi!\n";
        } else {
            dosyaYaz << satir << "\n"; 
        }
    }
    
    if (!bulundu) {
        cout << "Dugun bulunamadi!\n";
    }
    
    dosyaOku.close();
    dosyaYaz.close();
    
    remove("Dugunler.txt"); // dugunler.txt dosyasini siliyor
    rename("Dugunler_temp.txt", "Dugunler.txt"); // dosyayi yeniden adlandiriyor
}

void dugunListele() { // dugunler.txt dosyasindaki dugunlerin listesini yazdirma fonksiyonu
    ifstream dosya("Dugunler.txt");
    if (!dosya) {
        cout << "Dugun dosyasi bulunamadi veya bos!\n";
        return;
    }
    
    string satir;
    cout << "\n===== TUM DUGUNLER =====\n";
    cout << left << setw(8) << "DugunNo" << setw(15) << "Damat" << setw(15) << "Gelin" 
         << setw(12) << "Tarih" << setw(10) << "Salon" << setw(12) << "Ucret" << endl;
    cout << "--------------------------------------------------------------------\n"; 
    
    while (getline(dosya, satir)) { // dugunler.txt dugunler okunacak ve temp.txt dosyasina yazilacak
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        int dugunNo, salonNo;
        string damatAdi, gelinAdi, tarih;
        double toplamUcret;
        
        while ((pos = temp.find("|")) != string::npos) { // her | isaretini gordugunde o kisma kadar olan kismi ozellik olarak alacak
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dugunNo = stoi(token); break;
                case 2: tarih = token; break;
                case 4: damatAdi = token; break;
                case 6: gelinAdi = token; break;
                case 10: salonNo = stoi(token); break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        toplamUcret = stod(temp);
        
        cout << left << setw(8) << dugunNo << setw(15) << damatAdi << setw(15) << gelinAdi 
             << setw(12) << tarih << setw(10) << salonNo << setw(12) << toplamUcret << endl;
    }
    
    dosya.close(); // dosya kapatiliyor
}

// DETAYLI DUGUN SORGULAMA . ( coklu dosya okuma kismi )

void dugunDetayliSorgula() {
    ifstream dugunDosya("Dugunler.txt"); // dugunler.txt dosyasindan dugun bilgisi araniyor
    if (!dugunDosya) { // dugunler.txt dosyasi bulunamadiysa hata mesaji veriyor
        cout << "Dugun dosyasi bulunamadi!\n"; 
        return;
    }
    
    int arananNo; // aranacak dugun no
    cout << "\n=== COKLU DOSYA SORGULAMA ===";
    cout << "\nSorgulamak istediginiz Dugun No: "; 
    cin >> arananNo;
    
    string satir; // dugunler.txt dosyasindan okunan dugun bilgisi
    bool dugunBulundu = false; // dugun bulunursa bool true olacak
    int dugunNo;
    string patron, tarih, saat, damatAdi, damatBabaAdi, gelinAdi, gelinAnneAdi;
    string patronTel, damatTel;
    int salonNo, kisiSayisi;
    double toplamUcret;
    
    while (getline(dugunDosya, satir)) { // dugunler.txt dosyasindan dugun bilgisi okunacak
        size_t pos = 0; 
        string token;
        int alan = 0;
        string temp = satir;
        
        while ((pos = temp.find("|")) != string::npos) { // her | isaretini gordugunde o kisma kadar olan kismi ozellik olarak alacak
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dugunNo = stoi(token); break;
                case 1: patron = token; break;
                case 2: tarih = token; break;
                case 3: saat = token; break;
                case 4: damatAdi = token; break;
                case 5: damatBabaAdi = token; break;
                case 6: gelinAdi = token; break;
                case 7: gelinAnneAdi = token; break;
                case 8: patronTel = token; break;
                case 9: damatTel = token; break;
                case 10: salonNo = stoi(token); break;
                case 11: kisiSayisi = stoi(token); break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        toplamUcret = stod(temp);
        
        if (dugunNo == arananNo) { // dugunNo ozelligini ariyor
            dugunBulundu = true;
            cout << "\n============================================";
            cout << "\n[1. DOSYA: Dugunler.txt] DUGUN BILGILERI"; // dugun bilgilerini yazdiriyor
            cout << "\n============================================\n";
            cout << "Dugun No      : " << dugunNo << endl;
            cout << "Patron        : " << patron << endl;
            cout << "Tarih         : " << tarih << endl;
            cout << "Saat          : " << saat << endl;
            cout << "Damat Adi     : " << damatAdi << endl;
            cout << "Damat Baba Adi: " << damatBabaAdi << endl;
            cout << "Gelin Adi     : " << gelinAdi << endl;
            cout << "Gelin Anne Adi: " << gelinAnneAdi << endl;
            cout << "Patron Tel    : " << patronTel << endl;
            cout << "Damat Tel     : " << damatTel << endl;
            cout << "Salon No      : " << salonNo << endl;
            cout << "Kisi Sayisi   : " << kisiSayisi << endl;
            cout << "Toplam Ucret  : " << toplamUcret << " TL\n";
            break;
        }
    }
    dugunDosya.close();
    
    if (!dugunBulundu) {
        cout << "Dugun bulunamadi! Diger dosyalar sorgulanamaz.\n";
        return;
    }
    
    // davetli.txt dosyasindan davetli listesi okunacak
    // dugun bulundugunda ayni dugunNo ile davetli.txt dosyasini okur tekrardan
    ifstream davetliDosya("Davetliler.txt");
    
    cout << "\n============================================";
    cout << "\n[2. DOSYA: Davetliler.txt] DAVETLI LISTESI";
    cout << "\n============================================\n";
    
    if (!davetliDosya) {
        cout << "Davetli dosyasi bulunamadi veya bos!\n";
    } else {
        cout << left << setw(6) << "No" << setw(15) << "Adi" << setw(15) << "Soyadi" 
             << setw(12) << "Akrabalik" << setw(12) << "Gelecek" << endl;
        cout << "------------------------------------------------------------\n";
        
        int davetliSayisi = 0;
        int gelecekSayisi = 0;
        int gelemeyecekSayisi = 0;
        
        while (getline(davetliDosya, satir)) {
            size_t pos = 0;
            string token;
            int alan = 0;
            string temp = satir;
            int dNo, davetliNo;
            string adi, soyadi, akrabalik;
            char gelecekMi;
            
            while ((pos = temp.find("|")) != string::npos) {
                token = temp.substr(0, pos);
                switch(alan) {
                    case 0: dNo = stoi(token); break;
                    case 1: davetliNo = stoi(token); break;
                    case 2: adi = token; break;
                    case 3: soyadi = token; break;
                    case 4: akrabalik = token; break;
                }
                temp.erase(0, pos + 1);
                alan++;
            }
            gelecekMi = temp[0];
            
            if (dNo == arananNo) { // bir dugunun davetlisi mi diye kontrol ediliyor
                davetliSayisi++;
                if (gelecekMi == 'e') gelecekSayisi++; // davetlinin gelip gelmeyecegine gore sayaci artiriyor
                else gelemeyecekSayisi++;
                
                cout << left << setw(6) << davetliNo << setw(15) << adi << setw(15) << soyadi 
                     << setw(12) << akrabalik << setw(12) << (gelecekMi == 'e' ? "Evet" : "Hayir") << endl;
            }
        }
        
        cout << "------------------------------------------------------------\n";
        cout << "Toplam Davetli: " << davetliSayisi;
        cout << " | Gelecek: " << gelecekSayisi;
        cout << " | Gelemeyecek: " << gelemeyecekSayisi << endl; // dugun hakkinda genisletilmis bilgiler.
        
        davetliDosya.close();
    }
    
    // masraflar.txt dosyasindan masraflar getirilecek
    // ayni dugun no ile masraf.txt dosyasi okunuyor
    ifstream masrafDosya("Masraflar.txt");
    
    cout << "\n============================================";
    cout << "\n[3. DOSYA: Masraflar.txt] MASRAF LISTESI";
    cout << "\n============================================\n";
    
    if (!masrafDosya) {
        cout << "Masraf dosyasi bulunamadi veya bos!\n";
    } else {
        cout << left << setw(12) << "Tur" << setw(25) << "Aciklama" << setw(12) << "Fiyat" 
             << setw(8) << "Adet" << setw(12) << "Toplam" << endl;
        cout << "-----------------------------------------------------------------------\n";
        
        double toplamYemek = 0, toplamAksesuar = 0, toplamSanatci = 0;
        
        while (getline(masrafDosya, satir)) { // satir satir okunuyor
            size_t pos = 0;
            string token;
            int alan = 0;
            string temp = satir;
            int dNo, adet;
            string tur, aciklama;
            double fiyat;
            
            while ((pos = temp.find("|")) != string::npos) { // satirin icindeki alanlari ayiriyor
                token = temp.substr(0, pos);
                switch(alan) {
                    case 0: dNo = stoi(token); break;
                    case 1: tur = token; break;
                    case 2: aciklama = token; break;
                    case 3: fiyat = stod(token); break;
                }
                temp.erase(0, pos + 1);
                alan++;
            }
            adet = stoi(temp); // adet sayisi okunuyor
            
            if (dNo == arananNo) { // bir dugunun masrafı mi diye kontrol ediliyor
                cout << left << setw(12) << tur << setw(25) << aciklama << setw(12) << fiyat 
                     << setw(8) << adet << setw(12) << (fiyat * adet) << endl;
                
                if (tur == "YEMEK") toplamYemek += fiyat * adet;
                else if (tur == "AKSESUAR") toplamAksesuar += fiyat * adet;
                else if (tur == "SANATCI") toplamSanatci += fiyat * adet;
            } // dugun hakkinda genisletilmis bilgiler.
        }
        
        cout << "-----------------------------------------------------------------------\n";
        cout << "Yemek: " << toplamYemek << " TL | ";
        cout << "Aksesuar: " << toplamAksesuar << " TL | ";
        cout << "Sanatci: " << toplamSanatci << " TL\n";
        cout << "TOPLAM MASRAF: " << (toplamYemek + toplamAksesuar + toplamSanatci) << " TL\n";
        
        masrafDosya.close(); // dosya kapatiliyor
    }
    
    cout << "\nCoklu Dosya Sorgulama Islemi Tamamlandi......\n";
}

// DAVETLI ISLEMLERI

void davetliEkle() {
    ofstream dosya;
    dosya.open("Davetliler.txt", ios::app); // dosya aciliyor
    
    Davetliler dv; // davetliler sinifi nesnesi olusturuluyor
    char devam = 'e';
    
    cout << "Hangi Dugun icin davetli eklenecek (Dugun No): "; cin >> dv.dugunNo;
    cin.ignore();
    
    do {
        cout << "\n--- Yeni Davetli Kaydi ---\n";
        cout << "Davetli No: "; cin >> dv.no;
        cin.ignore();
        cout << "Adi: "; getline(cin, dv.adi);
        cout << "Soyadi: "; getline(cin, dv.soyadi);
        cout << "Akrabalik (gelin/damat): "; getline(cin, dv.akrabalik);
        cout << "Adres: "; getline(cin, dv.adres);
        cout << "Telefon: "; getline(cin, dv.telefon);
        cout << "Dugune Gelecek mi? (e/h): "; cin >> dv.gelecekMi;
        
        dv.dosyayaYaz(dosya);
        
        cout << "\nDavetli kaydi eklendi!\n";
        cout << "Baska kayit eklemek ister misiniz? (e/h): "; cin >> devam;
        cin.ignore();
    } while (devam == 'e' || devam == 'E');
    
    dosya.close();
}

void davetliAra() { // davetli arama islemi
    ifstream dosya("Davetliler.txt");
    if (!dosya) {
        cout << "Davetli dosyasi bulunamadi!\n";
        return;
    }
    
    int arananNo, dugunNo;
    cout << "Dugun No: "; cin >> dugunNo;
    cout << "Aramak istediginiz Davetli No: "; cin >> arananNo;
    
    string satir;
    bool bulundu = false;
    
    while (getline(dosya, satir)) {
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        int dNo, davetliNo;
        string adi, soyadi, akrabalik, adres, telefon;
        char gelecekMi;
        
        while ((pos = temp.find("|")) != string::npos) {
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dNo = stoi(token); break;
                case 1: davetliNo = stoi(token); break;
                case 2: adi = token; break;
                case 3: soyadi = token; break;
                case 4: akrabalik = token; break;
                case 5: adres = token; break;
                case 6: telefon = token; break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        gelecekMi = temp[0];
        
        if (dNo == dugunNo && davetliNo == arananNo) {
            bulundu = true;
            cout << "\n===== DAVETLI BILGILERI =====\n";
            cout << "Dugun No    : " << dNo << endl;
            cout << "Davetli No  : " << davetliNo << endl;
            cout << "Adi         : " << adi << endl;
            cout << "Soyadi      : " << soyadi << endl;
            cout << "Akrabalik   : " << akrabalik << endl;
            cout << "Adres       : " << adres << endl;
            cout << "Telefon     : " << telefon << endl;
            cout << "Gelecek Mi  : " << (gelecekMi == 'e' ? "Evet" : "Hayir") << endl;
            break;
        }
    }
    
    if (!bulundu) {
        cout << "Davetli bulunamadi!\n";
    }
    
    dosya.close();
}

void davetliGuncelle() { // secili davetlinin bilgilerini guncelleme islemi
    ifstream dosyaOku("Davetliler.txt");
    if (!dosyaOku) {
        cout << "Davetli dosyasi bulunamadi!\n";
        return;
    }
    
    ofstream dosyaYaz("Davetliler_temp.txt");
    
    int arananNo, dugunNo;
    cout << "Dugun No: "; cin >> dugunNo;
    cout << "Guncellemek istediginiz Davetli No: "; cin >> arananNo;
    cin.ignore();
    
    string satir;
    bool bulundu = false;
    
    while (getline(dosyaOku, satir)) {
        size_t pos = satir.find("|");
        int dNo = stoi(satir.substr(0, pos));
        string kalan = satir.substr(pos + 1);
        pos = kalan.find("|");
        int davetliNo = stoi(kalan.substr(0, pos));
        
        if (dNo == dugunNo && davetliNo == arananNo) {
            bulundu = true;
            cout << "\n--- Yeni Bilgileri Girin ---\n";
            
            string adi, soyadi, akrabalik, adres, telefon;
            char gelecekMi;
            
            cout << "Adi: "; getline(cin, adi);
            cout << "Soyadi: "; getline(cin, soyadi);
            cout << "Akrabalik (gelin/damat): "; getline(cin, akrabalik);
            cout << "Adres: "; getline(cin, adres);
            cout << "Telefon: "; getline(cin, telefon);
            cout << "Dugune Gelecek mi? (e/h): "; cin >> gelecekMi;
            
            dosyaYaz << dugunNo << "|" << davetliNo << "|" << adi << "|" << soyadi << "|" 
                     << akrabalik << "|" << adres << "|" << telefon << "|" << gelecekMi << "\n";
            
            cout << "\nDavetli guncellendi!\n";
        } else {
            dosyaYaz << satir << "\n";
        }
    }
    
    if (!bulundu) {
        cout << "Davetli bulunamadi!\n";
    }
    
    dosyaOku.close();
    dosyaYaz.close();
    
    remove("Davetliler.txt");
    rename("Davetliler_temp.txt", "Davetliler.txt");
}

void davetliSil() { // secili davetliyi silme islemi
    ifstream dosyaOku("Davetliler.txt");
    if (!dosyaOku) {
        cout << "Davetli dosyasi bulunamadi!\n";
        return;
    }
    
    ofstream dosyaYaz("Davetliler_temp.txt");
    
    int arananNo, dugunNo;
    cout << "Dugun No: "; cin >> dugunNo;
    cout << "Silmek istediginiz Davetli No: "; cin >> arananNo;
    
    string satir;
    bool bulundu = false;
    
    while (getline(dosyaOku, satir)) {
        size_t pos = satir.find("|");
        int dNo = stoi(satir.substr(0, pos));
        string kalan = satir.substr(pos + 1);
        pos = kalan.find("|");
        int davetliNo = stoi(kalan.substr(0, pos));
        
        if (dNo == dugunNo && davetliNo == arananNo) {
            bulundu = true;
            cout << "Davetli silindi!\n";
        } else {
            dosyaYaz << satir << "\n";
        }
    }
    
    if (!bulundu) {
        cout << "Davetli bulunamadi!\n";
    }
    
    dosyaOku.close();
    dosyaYaz.close();
    
    remove("Davetliler.txt");
    rename("Davetliler_temp.txt", "Davetliler.txt");
}

void davetliListele() { // tum davetlilerin listelenmesi islemi
    ifstream dosya("Davetliler.txt");
    if (!dosya) {
        cout << "Davetli dosyasi bulunamadi veya bos!\n";
        return;
    }
    
    int dugunNo;
    cout << "Hangi Dugun icin davetlileri listelemek istiyorsunuz (Dugun No): "; cin >> dugunNo;
    
    string satir;
    cout << "\n===== DAVETLI LISTESI (Dugun " << dugunNo << ") =====\n";
    cout << left << setw(6) << "No" << setw(15) << "Adi" << setw(15) << "Soyadi" 
         << setw(12) << "Akrabalik" << setw(12) << "Gelecek" << endl;
    cout << "------------------------------------------------------------\n";
    
    bool varMi = false;
    while (getline(dosya, satir)) {
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        int dNo, davetliNo;
        string adi, soyadi, akrabalik;
        char gelecekMi;
        
        while ((pos = temp.find("|")) != string::npos) {
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dNo = stoi(token); break;
                case 1: davetliNo = stoi(token); break;
                case 2: adi = token; break;
                case 3: soyadi = token; break;
                case 4: akrabalik = token; break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        gelecekMi = temp[0];
        
        if (dNo == dugunNo) {
            varMi = true;
            cout << left << setw(6) << davetliNo << setw(15) << adi << setw(15) << soyadi 
                 << setw(12) << akrabalik << setw(12) << (gelecekMi == 'e' ? "Evet" : "Hayir") << endl;
        }
    }
    
    if (!varMi) {
        cout << "Bu dugun icin davetli bulunamadi!\n";
    }
    
    dosya.close();
}

// MASRAF ISLEMLERI ---- yemek, aksesuar, sanatci

void yemekEkle() { // yemek ekleme islemi
    ofstream dosya;
    dosya.open("Masraflar.txt", ios::app);
    
    Masraf m; // masraf sinifi nesnesi olusturuluyor
    m.tur = "YEMEK";
    char devam = 'e';
    
    cout << "Hangi Dugun icin yemek eklenecek (Dugun No): "; cin >> m.dugunNo;
    cin.ignore();
    
    do {
        cout << "\n--- Yemek Ekle ---\n";
        cout << "Yemek Adi: "; getline(cin, m.aciklama);
        cout << "Birim Fiyati: "; cin >> m.fiyat;
        cout << "Kisi Sayisi (Adet): "; cin >> m.adet;
        
        m.dosyayaYaz(dosya); // masraf sinifinin dosyayaYaz fonksiyonu kullaniliyor m nesnesi ile
        
        cout << "Yemek eklendi! Toplam: " << m.toplamHesapla() << " TL\n";
        cout << "Baska yemek eklemek ister misiniz? (e/h): "; cin >> devam;
        cin.ignore();
    } while (devam == 'e' || devam == 'E'); // devam == 'e' veya devam == 'E' ise dongu devam ededcek
    
    dosya.close();
}

void aksesuarEkle() { // aksesuar ekleme islemi
    ofstream dosya;
    dosya.open("Masraflar.txt", ios::app);
    
    Masraf m; // masraf sinifi nesnesi olusturuluyor
    m.tur = "AKSESUAR";
    char devam = 'e';
    
    cout << "Hangi Dugun icin aksesuar eklenecek (Dugun No): "; cin >> m.dugunNo;
    cin.ignore();
    
    do {
        cout << "\n--- Aksesuar Ekle ---\n";
        cout << "Aksesuar Adi: "; getline(cin, m.aciklama);
        cout << "Birim Fiyati: "; cin >> m.fiyat;
        cout << "Adet: "; cin >> m.adet;
        
        m.dosyayaYaz(dosya); // masraf sinifinin dosyayaYaz fonksiyonu kullaniliyor m nesnesi ile
        
        cout << "Aksesuar eklendi! Toplam: " << m.toplamHesapla() << " TL\n";
        cout << "Baska aksesuar eklemek ister misiniz? (e/h): "; cin >> devam;
        cin.ignore();
    } while (devam == 'e' || devam == 'E');
    
    dosya.close();
}

void sanatciEkle() { // sanatci ekleme islemi
    ofstream dosya;
    dosya.open("Masraflar.txt", ios::app);
    
    Masraf m; // masraf sinifi nesnesi olusturuluyor
    m.tur = "SANATCI";
    m.adet = 1;
    char devam = 'e';
    
    cout << "Hangi Dugun icin sanatci eklenecek (Dugun No): "; cin >> m.dugunNo;
    cin.ignore();
    
    do {
        cout << "\n--- Sanatci Ekle ---\n";
        cout << "Sanatci Adi: "; getline(cin, m.aciklama);
        cout << "Ucret: "; cin >> m.fiyat;
        
        m.dosyayaYaz(dosya); // masraf sinifinin dosyayaYaz fonksiyonu kullaniliyor m nesnesi ile
        
        cout << "Sanatci eklendi! Ucret: " << m.fiyat << " TL\n";
        cout << "Baska sanatci eklemek ister misiniz? (e/h): "; cin >> devam;
        cin.ignore();
    } while (devam == 'e' || devam == 'E'); // devam == 'e' veya devam == 'E' ise dongu devam ediyor
    
    dosya.close();
}

void masrafListele() { // tum masraflarin listelenmesi islemi
    ifstream dosya("Masraflar.txt");
    if (!dosya) {
        cout << "Masraf dosyasi bulunamadi veya bos!\n";
        return;
    }
    
    int dugunNo;
    cout << "Hangi Dugun icin masraflari listelemek istiyorsunuz (Dugun No): "; cin >> dugunNo;
    
    string satir;
    cout << "\n===== MASRAF LISTESI (Dugun " << dugunNo << ") =====\n";
    cout << left << setw(12) << "Tur" << setw(25) << "Aciklama" << setw(12) << "Fiyat" 
         << setw(8) << "Adet" << setw(12) << "Toplam" << endl;
    cout << "-----------------------------------------------------------------------\n";
    
    bool varMi = false;
    while (getline(dosya, satir)) { // dosya satir satir okunuyor
        size_t pos = 0; 
        string token;
        int alan = 0;
        string temp = satir;
        int dNo, adet;
        string tur, aciklama;
        double fiyat;
        
        while ((pos = temp.find("|")) != string::npos) { // dosya satir satir okunuyor
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dNo = stoi(token); break;
                case 1: tur = token; break;
                case 2: aciklama = token; break;
                case 3: fiyat = stod(token); break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        adet = stoi(temp);
        
        if (dNo == dugunNo) { // dugunNo == dNo ise masraf listelenecek degilse devam ediyor
            varMi = true;
            cout << left << setw(12) << tur << setw(25) << aciklama << setw(12) << fiyat 
                 << setw(8) << adet << setw(12) << (fiyat * adet) << endl;
        }
    }
    
    if (!varMi) { // varMi == false ise masraf bulunamadi hatasi veriyor
        cout << "Bu dugun icin masraf bulunamadi!\n";
    }
    
    dosya.close();
}

void toplamMaliyetHesapla() { // dugundeki toplam maliyet hesaplanmasi islemi adetle birim fiyatin carpilmasi sonra toplami
    ifstream dosya("Masraflar.txt");
    if (!dosya) {
        cout << "Masraf dosyasi bulunamadi veya bos!\n";
        return;
    }
    
    int dugunNo;
    cout << "Hangi Dugun icin maliyet hesaplanacak (Dugun No): "; cin >> dugunNo;
    
    string satir;
    double toplamYemek = 0, toplamAksesuar = 0, toplamSanatci = 0; // hepsinin baslangic degerleri 0
    
    while (getline(dosya, satir)) {
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        int dNo, adet;
        string tur;
        double fiyat;
        
        while ((pos = temp.find("|")) != string::npos) { // dosya satir satir okunuyor
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dNo = stoi(token); break;
                case 1: tur = token; break;
                case 3: fiyat = stod(token); break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        adet = stoi(temp); // adet degeri okunuyor
        
        if (dNo == dugunNo) { // dugunNo == dNo ise masraf listelenecek degilse devam ediyor
            if (tur == "YEMEK") toplamYemek += fiyat * adet;
            else if (tur == "AKSESUAR") toplamAksesuar += fiyat * adet;
            else if (tur == "SANATCI") toplamSanatci += fiyat * adet;
        }
    }
    
    cout << "\n===== MALIYET RAPORU (Dugun " << dugunNo << ") =====\n"; // toplam maliyet ekranda listeleniyor
    cout << "Yemek Masrafi    : " << toplamYemek << " TL\n";
    cout << "Aksesuar Masrafi : " << toplamAksesuar << " TL\n";
    cout << "Sanatci Masrafi  : " << toplamSanatci << " TL\n";
    cout << "--------------------------------\n";
    cout << "TOPLAM MALIYET   : " << (toplamYemek + toplamAksesuar + toplamSanatci) << " TL\n";
    
    dosya.close();
}

// RAPORLAR

void geleceklerListesi() { // dugune gelecekler listesi
    ifstream dosya("Davetliler.txt");
    if (!dosya) {
        cout << "Davetli dosyasi bulunamadi!\n";
        return;
    }
    
    int dugunNo; 
    cout << "Hangi Dugun icin rapor istiyorsunuz (Dugun No): "; cin >> dugunNo;
    
    string satir;
    cout << "\n===== DUGUNE GELECEKLER (Dugun " << dugunNo << ") =====\n";
    cout << left << setw(6) << "No" << setw(15) << "Adi" << setw(15) << "Soyadi" 
         << setw(12) << "Akrabalik" << setw(20) << "Telefon" << endl;
    cout << "--------------------------------------------------------------------\n";
    
    int sayac = 0;
    while (getline(dosya, satir)) {
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        int dNo, davetliNo;
        string adi, soyadi, akrabalik, telefon;
        char gelecekMi;
        
        while ((pos = temp.find("|")) != string::npos) {
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dNo = stoi(token); break;
                case 1: davetliNo = stoi(token); break;
                case 2: adi = token; break;
                case 3: soyadi = token; break;
                case 4: akrabalik = token; break;
                case 6: telefon = token; break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        gelecekMi = temp[0]; // gelecekMi degeri okunuyor
        
        if (dNo == dugunNo && gelecekMi == 'e') { // dugunNo == dNo ise ve davetli gelecekse gelecekler sayacini artiyiro
            sayac++;
            cout << left << setw(6) << davetliNo << setw(15) << adi << setw(15) << soyadi 
                 << setw(12) << akrabalik << setw(20) << telefon << endl;
        }
    }
    
    cout << "\nToplam gelecek kisi sayisi: " << sayac << endl; // dugune toplam gelecek kisi sayisi ekranda listeleniyor
    dosya.close();
}

void gelemeyeceklerListesi() { // dugune gelemeyecekler listesi
    ifstream dosya("Davetliler.txt");
    if (!dosya) {
        cout << "Davetli dosyasi bulunamadi!\n";
        return;
    }
    
    int dugunNo;
    cout << "Hangi Dugun icin rapor istiyorsunuz (Dugun No): "; cin >> dugunNo; 
    
    string satir;
    cout << "\n===== DUGUNE GELEMEYECEKLER (Dugun " << dugunNo << ") =====\n";
    cout << left << setw(6) << "No" << setw(15) << "Adi" << setw(15) << "Soyadi" 
         << setw(12) << "Akrabalik" << setw(20) << "Telefon" << endl;
    cout << "--------------------------------------------------------------------\n";
    
    int sayac = 0;
    while (getline(dosya, satir)) {
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        int dNo, davetliNo;
        string adi, soyadi, akrabalik, telefon;
        char gelecekMi;
        
        while ((pos = temp.find("|")) != string::npos) {
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dNo = stoi(token); break;
                case 1: davetliNo = stoi(token); break;
                case 2: adi = token; break;
                case 3: soyadi = token; break;
                case 4: akrabalik = token; break;
                case 6: telefon = token; break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        gelecekMi = temp[0];
        
        if (dNo == dugunNo && gelecekMi == 'h') {
            sayac++;
            cout << left << setw(6) << davetliNo << setw(15) << adi << setw(15) << soyadi 
                 << setw(12) << akrabalik << setw(20) << telefon << endl;
        }
    }
    
    cout << "\nToplam gelemeyecek kisi sayisi: " << sayac << endl; // dugune toplam gelemeyecek kisi sayisi ekranda listeleniyor
    dosya.close();
}

void oturmaDuzeni() { // dugundeki masalara gore oturma duzeni. gelin tarafi ayri damat tarafi ayri
    ifstream dosya("Davetliler.txt");
    if (!dosya) {
        cout << "Davetli dosyasi bulunamadi!\n";
        return;
    }
    
    int dugunNo;
    cout << "Hangi Dugun icin oturma duzeni istiyorsunuz (Dugun No): "; cin >> dugunNo;
    
    string satir;
    int masaBasiKisi = 8; // her masada 8 kisi olacak sekilde yaptim
    
    // once damat akrabalari listeleniyor
    cout << "\n===== OTURMA DUZENI (Dugun " << dugunNo << ") =====\n";
    cout << "\n--- DAMAT AKRABALARI ---\n";
    
    dosya.clear(); 
    dosya.seekg(0);
    
    int damatSayac = 0;
    int masaNo = 1;
    
    while (getline(dosya, satir)) {
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        int dNo;
        string adi, soyadi, akrabalik;
        char gelecekMi;
        
        while ((pos = temp.find("|")) != string::npos) {
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dNo = stoi(token); break;
                case 2: adi = token; break;
                case 3: soyadi = token; break;
                case 4: akrabalik = token; break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        gelecekMi = temp[0];
        
        if (dNo == dugunNo && gelecekMi == 'e' && akrabalik == "damat") {
            if (damatSayac % masaBasiKisi == 0) {
                cout << "\nMasa " << masaNo << ":\n";
                masaNo++;
            }
            cout << "  - " << adi << " " << soyadi << endl;
            damatSayac++;
        }
    }
    
    // gelin akrabalari listeleniyor
    cout << "\n--- GELIN AKRABALARI ---\n";
    
    dosya.close();
    dosya.open("Davetliler.txt");
    
    int gelinSayac = 0;
    
    while (getline(dosya, satir)) {
        size_t pos = 0;
        string token;
        int alan = 0;
        string temp = satir;
        int dNo;
        string adi, soyadi, akrabalik;
        char gelecekMi;
        
        while ((pos = temp.find("|")) != string::npos) {
            token = temp.substr(0, pos);
            switch(alan) {
                case 0: dNo = stoi(token); break;
                case 2: adi = token; break;
                case 3: soyadi = token; break;
                case 4: akrabalik = token; break;
            }
            temp.erase(0, pos + 1);
            alan++;
        }
        gelecekMi = temp[0];
        
        if (dNo == dugunNo && gelecekMi == 'e' && akrabalik == "gelin") {
            if (gelinSayac % masaBasiKisi == 0) {
                cout << "\nMasa " << masaNo << ":\n";
                masaNo++;
            }
            cout << "  - " << adi << " " << soyadi << endl;
            gelinSayac++;
        }
    }
    
    cout << "\n--------------------------------\n";
    cout << "Toplam Masa Sayisi: " << (masaNo - 1) << endl;
    cout << "Damat Tarafi: " << damatSayac << " kisi\n";
    cout << "Gelin Tarafi: " << gelinSayac << " kisi\n";
    
    dosya.close();
}


// MAIN
int main() {
    setlocale(LC_ALL, "Turkish"); // turkce karakter kullanimi icin
    int anaSecim, altSecim;
    
    do {
        anaMenu();
        cin >> anaSecim;
        
        switch(anaSecim) {
            case 1: // kullanici dugun islemlerini secerse
                do {
                    dugunMenu();
                    cin >> altSecim;
                    switch(altSecim) {
                        case 1: dugunEkle(); break;
                        case 2: dugunAra(); break;
                        case 3: dugunGuncelle(); break;
                        case 4: dugunSil(); break;
                        case 5: dugunListele(); break;
                        case 6: dugunDetayliSorgula(); break;
                        case 7: break;
                        default: cout << "Gecersiz secim!\n";
                    }
                } while(altSecim != 7);
                break;
                
            case 2: // kullanici davetli islemlerini secerse
                do {
                    davetliMenu();
                    cin >> altSecim;
                    switch(altSecim) {
                        case 1: davetliEkle(); break;
                        case 2: davetliAra(); break;
                        case 3: davetliGuncelle(); break;
                        case 4: davetliSil(); break;
                        case 5: davetliListele(); break;
                        case 6: break;
                        default: cout << "Gecersiz secim!\n";
                    }
                } while(altSecim != 6);
                break;
                
            case 3: // kullanici masraf islemlerini secerse
                do {
                    masrafMenu();
                    cin >> altSecim;
                    switch(altSecim) {
                        case 1: yemekEkle(); break;
                        case 2: aksesuarEkle(); break;
                        case 3: sanatciEkle(); break;
                        case 4: masrafListele(); break;
                        case 5: toplamMaliyetHesapla(); break;
                        case 6: break;
                        default: cout << "Gecersiz secim!\n";
                    }
                } while(altSecim != 6);
                break;
                
            case 4: // Raporlar
                do {
                    raporMenu();
                    cin >> altSecim;
                    switch(altSecim) {
                        case 1: geleceklerListesi(); break;
                        case 2: gelemeyeceklerListesi(); break;
                        case 3: oturmaDuzeni(); break;
                        case 4: break;
                        default: cout << "Gecersiz secim!\n";
                    }
                } while(altSecim != 4);
                break;
                
            case 5:
                cout << "Cikis yapiliyor byeee yine beklerizzz!!\n";
                break;
                
            default:
                cout << "Gecersiz secim!\n";
        }
        
    } while(anaSecim != 5);
    
    return 0;
}
