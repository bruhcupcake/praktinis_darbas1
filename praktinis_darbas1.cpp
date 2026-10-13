#include <bits/stdc++.h>

using namespace std;

const double GBP_Bendras = 0.8729;
const double GBP_Pirkti = 0.8600;
const double GBP_Parduoti = 0.9220;

const double USD_Bendras = 1.1793;
const double USD_Pirkti = 1.1460;
const double USD_Parduoti = 1.2340;

const double INR_Bendras = 104.6918;
const double INR_Pirkti = 101.3862;
const double INR_Parduoti = 107.8546;

void skaitymas(int &veiksmas, int &valiuta, double &suma);//skaito duomenis
void skaiciavimas(int veiksmas, int valiuta, double suma, double &rezultatas);//skaiciuoja duomenis
void rezultatu(int veiksmas, int valiuta, double suma, double rezultatas);//spasdina atsakyma

int main()
{
    int veiksmas, valiuta;
    double suma = 0;
    double rezultatas = 0.0;

    skaitymas(veiksmas, valiuta, suma);
    skaiciavimas(veiksmas, valiuta, suma, rezultatas);
    rezultatu(veiksmas, valiuta, suma, rezultatas);

    return 0;
}

void skaitymas(int &veiksmas, int &valiuta, double &suma)
{

}


void skaiciavimas(int veiksmas, int valiuta, double suma, double &rezultatas)
{

}

void rezultatu(int veiksmas, int valiuta, double suma, double rezultatas)
{
    
}