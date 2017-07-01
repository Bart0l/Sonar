
//Code::Blocks IDE 16.01
//=== TDM-GCC Compiler Suite for Windows ===
//---           GCC 4.9 Series           ---
//***   Standard MinGW 32-bit Edition    ***

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

void logo (void)
{
//Wczytanie logo
    ifstream logo("ksem_logo2.bmp", ios::binary);
    if(!logo){
    cout <<endl<<"Nie mozna otworzyc logo. Sprawdz lokalizacje i podaj odpowiednia sciezke dostepu."<<endl;
    exit(0);
            }
    else cout<<endl<<"Logo zostalo wczytane."<<endl;

//Naglowek pliku (BITMAPFILEHEADER)
    char bfType[2];
    int bfSize[4];
    char bfReserved1[2];
    char bfReserved2[2];
    char bfOffBits[4];

    logo.read(bfType,2);
    logo.read((char*)&bfSize, sizeof(int));
    logo.read(bfReserved1,2);
    logo.read(bfReserved2,2);
    logo.read(bfOffBits,4);

//Naglowek logo (BITMAPINFOHEADER)
    int biSize[4];
    int biWidth[4];
    int biHeight[4];
    char biPlanes[2];
    char biBitCount[2];
    char biCompression[4];
    char biSizeImage[4];
    char biXPelsPerMeter[4];
    char biYPelsPerMeter[4];
    char biClrUsed[4];
    char biClrImportant[4];

    logo.read((char*)&biSize, sizeof(int));
    logo.read((char*)&biWidth, sizeof(int));
    logo.read((char*)&biHeight, sizeof(int));
    logo.read(biPlanes,2);
    logo.read(biBitCount,2);
    logo.read(biCompression,4);
    logo.read(biSizeImage,4);
    logo.read(biXPelsPerMeter,4);
    logo.read(biYPelsPerMeter,4);
    logo.read(biClrUsed,4);
    logo.read(biClrImportant,4);

//Sprawdzenie zgodnosci logo
if(memcmp(bfType,"BM",2)==0)
        {
    cout <<"Podane logo jest poprawnym plikiem BMP."<<endl<<endl;
        }
else {
    cout<<"Podane logo nie jest poprawnym plikiem BMP"<<endl;
    exit(0);
    }
//Dane logo
cout<<"Szerokosc logo (biWidth): "<<*biWidth<<endl; //70
cout<<"Wysokosc logo (biHeight): "<<*biHeight<<endl; //84
cout<<"Rozmiar logo (bfSize): "<<*bfSize<<endl; //17862

int szerokosc = (*biWidth * 3);
while (szerokosc % 4>0) szerokosc++; //wyrównanie pikseli do podzielnoœci przez 4

unsigned char LogoTab[*biHeight][szerokosc];

for( int i =0; i <*biHeight; i++ ){

        for( int j =0; j <szerokosc; j++ )
        {
        logo>> LogoTab[i][j];
        if((LogoTab[i][j]>250)&&(LogoTab[i][j-1])>250&&LogoTab[i][j-2]>250){
           LogoTab[i][j+1]=0;
        }
        }}
    cout<<endl<<"Tlo wynikowego logo zostalo przezroczyste."<<endl;
}
void sonar (void)
{
//Wczytanie obrazu
ifstream plik("sonar_aktywny_plakat.bmp", ios::binary);
    if(!plik){
    cout <<"Nie mozna otworzyc obrazu. Sprawdz lokalizacje i podaj odpowiednia sciezke dostepu."<<endl;
    exit(0);
            }
    else cout<<endl<<"Obraz zostal wczytany."<<endl;

//Naglowek pliku (BITMAPFILEHEADER)
    char bfType[2];
    int bfSize[4];
    char bfReserved1[2];
    char bfReserved2[2];
    char bfOffBits[4];

    plik.read(bfType,2);
    plik.read((char*)&bfSize, sizeof(int));
    plik.read(bfReserved1,2);
    plik.read(bfReserved2,2);
    plik.read(bfOffBits,4);

//Naglowek obrazu (BITMAPINFOHEADER)
    int biSize[4];
    int biWidth[4];
    int biHeight[4];
    char biPlanes[2];
    char biBitCount[2];
    char biCompression[4];
    char biSizeImage[4];
    char biXPelsPerMeter[4];
    char biYPelsPerMeter[4];
    char biClrUsed[4];
    char biClrImportant[4];

    plik.read((char*)&biSize, sizeof(int));
    plik.read((char*)&biWidth, sizeof(int));
    plik.read((char*)&biHeight, sizeof(int));
    plik.read(biPlanes,2);
    plik.read(biBitCount,2);
    plik.read(biCompression,4);
    plik.read(biSizeImage,4);
    plik.read(biXPelsPerMeter,4);
    plik.read(biYPelsPerMeter,4);
    plik.read(biClrUsed,4);
    plik.read(biClrImportant,4);

//Sprawdzenie zgodnosci pliku
if(memcmp(bfType,"BM",2)==0)
        {
    cout <<"Podany obraz jest poprawnym plikiem BMP."<<endl<<endl;
        }
else {
    cout<<"Podany obraz nie jest poprawnym plikiem BMP"<<endl;
    exit(0);
    }

//Dane obrazowe
cout<<"Szerokosc obrazu (biWidth): "<<*biWidth<<endl; //599 <-- 1800 czyli ((599+1)*3)
cout<<"Wysokosc obrazu (biHeight): "<<*biHeight<<endl; //441
cout<<"Rozmiar obrazu (bfSize): "<<*bfSize<<endl; //793854


int szerokosc = (*biWidth * 3);
while (szerokosc % 4>0) szerokosc++; //wyrównanie pikseli do podzielnoœci przez 4

unsigned char obraz[*biHeight][szerokosc];

    for( int i =0; i <*biHeight; i++ ){
        for( int j =0; j <szerokosc; j++ )
        {
        plik >> obraz[i][j];
        }
    }

//Tworzenie pliku wyjsciowegp
    fstream wyjsciowy;
    wyjsciowy.open("UTWORZONY PLIK.bmp", ios::out);
    //Naglowek pliku (BITMAPFILEHEADER)
    wyjsciowy<<bfType[2];
    wyjsciowy<<bfSize[4];
    wyjsciowy<<bfReserved1[2];
    wyjsciowy<<bfReserved2[2];
    wyjsciowy<<bfOffBits[4];
    //Naglowek obrazu (BITMAPINFOHEADER)
    wyjsciowy<<biSize[4];
    wyjsciowy<<biWidth[4];
    wyjsciowy<<biHeight[4];
    wyjsciowy<<biPlanes[2];
    wyjsciowy<<biBitCount[2];
    wyjsciowy<<biCompression[4];
    wyjsciowy<<biSizeImage[4];
    wyjsciowy<<biXPelsPerMeter[4];
    wyjsciowy<<biYPelsPerMeter[4];
    wyjsciowy<<biClrUsed[4];
    wyjsciowy<<biClrImportant[4];

    //Dane obrazowe
    //dolna czesc obrazu
     for( int i = 0; i <*biHeight-15-84; i++ ){
        for( int j =0; j <szerokosc; j++ )
        {
        wyjsciowy << obraz[i][j];
        }
     }
     //logo
     for( int i = *biHeight-15-84; i <*biHeight-15; i++ ){
            //przestrzen od prawej do logo
        for( int j =0; j <20*3; j++ )
        {
        wyjsciowy << obraz[i][j];
        }
            //logo
         for( int j =20*3; j <20*3 + 72*3; j++ )
        {
       wyjsciowy << obraz[i][j];
        }
            //przestrzen od logo do lewej
         for( int j =20*3 + 72*3; j <szerokosc; j++ )
        {
        wyjsciowy << obraz[i][j];
        }
    }
     //gorna czesc obrazu
     for( int i = *biHeight-15; i <*biHeight; i++ ){
        for( int j =0; j <szerokosc; j++ )
        {
        wyjsciowy << obraz[i][j];
        }
     }

    wyjsciowy.close ();

    cout<<endl<<"Logo zostalo umieszczone w prawym gornym roku podanego obrazka.";
}
int main()
{
    cout <<endl<< "Bartlomiej Borzyszkowski" << endl <<"Podstawy Programowania: Projekt 2." << endl << endl;
    cout << "Witaj Uzytkowniku!" << endl <<"Korzystasz z programu, ktory do obrazu dodaje kolorowe logo Katedry Systemow Elektroniki Morskiej."<<endl;

    logo();
    sonar();

    cout<<endl<<"Nowy plik BMP zostal utworzony w folderze docelowym pod nazwa 'UTWORZONY PLIK'."<<endl;
    cout<<endl<<"Dziekuje za skorzystanie z programu! ~Bartek Borzyszkowski"<<endl;

    return 0;
}
