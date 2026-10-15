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

    while (veiksmas != 4)
    {
        skaitymas(veiksmas, valiuta, suma);

        if (veiksmas >= 1 && veiksmas <= 3 &&
            valiuta >= 1 && valiuta <= 3 &&
            suma >= 0)
        {
            skaiciavimas(veiksmas, valiuta, suma, rezultatas);
            rezultatu(veiksmas, valiuta, suma, rezultatas);
        }

        cout << endl;
    }

    cout << "Programa baigta!" << endl;

    return 0;
}

void skaitymas(int &veiksmas, int &valiuta, double &suma)
{
    // Pagrindinis meniu
    cout << "1. Valiutos kurso palyginimas su euru" << endl;
    cout << "2. Valiutos pirkimas" << endl;
    cout << "3. Valiutos pardavimas" << endl;
    cout << "4. Iseiti" << endl;

    // Nuskaitomas vartotojo pasirinktas veiksmas
    cout << "Pasirinkite veiksma: ";
    cin >> veiksmas;

    if (veiksmas < 1 || veiksmas > 4)// Tikrinama, ar pasirinktas veiksmas yra teisingas
    {
        cout << "Neteisingas pasirinkimas!" << endl;
    }


    else if (veiksmas >= 1 && veiksmas <= 3)// Jeigu pasirinktas palyginimas, pirkimas arba pardavimas
    {
        // Parodomas valiutu pasirinkimo meniu
        cout << "1. GBP" << endl;
        cout << "2. USD" << endl;
        cout << "3. INR" << endl;

        // Nuskaitomas pasirinktos valiutos numeris
        cout << "Pasirinkite valiuta: ";
        cin >> valiuta;

        if (valiuta < 1 || valiuta > 3)// Tikrinama, ar valiutos pasirinkimas teisingas
        {
            cout << "Neteisingas valiutos pasirinkimas!" << endl;
        }

        else if (veiksmas == 2 || veiksmas == 3)// Jeigu pasirinktas pirkimas arba pardavimas
        {
            // Nuskaitoma norima pirkti arba parduoti suma
            cout << "Iveskite suma: ";
            cin >> suma;

            if (suma < 0)// Tikrinama, ar suma nėra neigiama
            {
                cout << "Suma negali buti neigiama!" << endl;
            }
        }
    }
}


void skaiciavimas(int veiksmas, int valiuta, double suma, double &rezultatas)
{
        // Parenkamas valiutos kursas pagal valiutos pasirinkima
    double bendras = 0;
    double pirkti = 0;
    double parduoti = 0;

    if (valiuta == 1)
    {
        bendras = GBP_Bendras;
        pirkti = GBP_Pirkti;
        parduoti = GBP_Parduoti;
    }
    else if (valiuta == 2)
    {
        bendras = USD_Bendras;
        pirkti = USD_Pirkti;
        parduoti = USD_Parduoti;
    }
    else if (valiuta == 3)
    {
        bendras = INR_Bendras;
        pirkti = INR_Pirkti;
        parduoti = INR_Parduoti;
    }

    // Apskaiciuojamas rezultatas pagal pasirinkta veiksma
    if (veiksmas == 1)
    {
        rezultatas = 1 / bendras;
    }
    else if (veiksmas == 2)
    {
        rezultatas = suma * pirkti;
    }
    else if (veiksmas == 3)
    {
        rezultatas = suma / parduoti;
    }
}

void rezultatu(int veiksmas, int valiuta, double suma, double rezultatas)
{
    // Nustatomas pasirinktos valiutos pavadinimas
    string pavadinimas;

    if (valiuta == 1)
    {
        pavadinimas = "GBP";
    }
    else if (valiuta == 2)
    {
        pavadinimas = "USD";
    }
    else if (valiuta == 3)
    {
        pavadinimas = "INR";
    }

    // Nustatomas rezultato isvedimas pagal veiksma
    cout << fixed << setprecision(2);

    if (veiksmas == 1)
    {
        cout << "1 EUR = " << (valiuta == 1 ? GBP_Bendras :
                               valiuta == 2 ? USD_Bendras : INR_Bendras)
             << " " << pavadinimas << endl;

        cout << "1 " << pavadinimas << " = "
             << rezultatas << " EUR" << endl;
    }
    else if (veiksmas == 2)
    {
        cout << suma << " EUR = " << suma *
             (valiuta == 1 ? GBP_Pirkti :
              valiuta == 2 ? USD_Pirkti : INR_Pirkti)
             << " " << pavadinimas << endl;
    }
    else if (veiksmas == 3)
    {
        cout << suma << " " << pavadinimas << " = " << rezultatas << " EUR" << endl;
    }
}