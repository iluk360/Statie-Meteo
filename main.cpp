#include <iostream>
#include <string>
#define MAXIM 999

using namespace std;

int N, key, i, j;
double temp[MAXIM] = {0};
bool introdus = false, ended = false;

void insertKey()
{
    int key;

    while (true)
    {
        if (ended == true) return;
        cout << "Introduce o tasta: ";
        cin >> key;

        switch (key)
        {
            case 1:
            {
                for (i = 0; i < N; i++)
                {
                    cout << "Valoarea ziua " << i + 1 << ": ";
                    cin >> temp[i];
                }
                introdus = true;
                break;
            }
            case 2:
            {
                if (introdus == true)
                {
                    for (i = 0; i < N; i++)
                    {
                        cout << "Temperatura ziua " << i + 1 << " este: " << temp[i] << "°C" << endl;
                    }
                    break;
                }
                else cout << "Nu a fost introdusa nicio valoare!" << endl << endl;
            }
            case 3:
            {
                double s = 0;
                if (introdus == true)
                {
                    for (i = 0; i < N; i++)
                    {
                        s += temp[i];
                    }
                double medie = s / N, amount = N;
                cout << "Media temperaturilor este de " << medie << ", fiind " << N << " temperatura(i) in registru." << endl << endl;
                }
                else cout << "Nu a fost introdusa nicio valoare!" << endl << endl;
                insertKey();
                break;
            }

            case 4:
            {
                if (introdus == false) {
                    cout << "Nu a fost introdusa nicio valoare!" << endl << endl;
                    break;
                }

                int maxim = temp[0];

                for (int i = 1; i < N; i++)
                {
                    if (temp[i] > maxim) maxim = temp[i];
                }

                cout << "Temperatura maxima este de " << maxim << "°C" << endl << endl;
                break;
            }

            case 5:
            {
                double newTemp[MAXIM];
                for (i = 0; i < N; i++) newTemp[i] = temp[i];
                if (N < 2 || introdus == false) {
                    cout << "Nu exista minim 2 valori in registru pentru sortare!" << endl << endl;
                    break;
                }

                for (int i = 0; i < N - 1; i++)
                {
                    for (int j = i + 1; j < N; j++)
                    {
                        if (newTemp[i] > newTemp[j])
                        {
                            swap(newTemp[i], newTemp[j]);
                        }
                    }
                }
                cout << "Valorile ordonate crescator:" << endl << endl;
                for (i = 0; i < N; i++) cout << newTemp[i] << "°C, ";
                cout << endl << endl;
                break;
            }

            case 6:
            {
                double x, v[MAXIM];
                cout << "Introduce valoarea de referinta (target): ";
                cin >> x;

                for (i = 0; i < N; i++)
                {
                    v[i] = temp[i];
                }
                cout << endl;

                for (i = 1; i < N; i++)
                {
                    double tempValue = v[i];
                    int j = i - 1;

                    while (j >= 0 && v[j] > tempValue)
                    {
                        v[j + 1] = v[j];
                        j--;
                    }
                    v[j + 1] = tempValue;
                }
                cout << endl;

                // Cautare binara
                int mij, st = 0, dr = N - 1, poz = -1;

                while (st <= dr && poz == -1)
                {
                    mij = (st + dr) / 2;

                    if (v[mij] == x)
                        poz = mij;

                    else if (v[mij] < x)
                        st = mij + 1;

                    else
                        dr = mij - 1;
                }

                if (poz != -1)
                    cout << x << " se afla pe pozitia " << poz + 1 << endl;
                else
                    cout << "Valoarea de " << x << "°C NU a fost gasita." << endl << endl;

                break;
            }

            case 7:
            {
                double target;
                if (N < 2 || introdus == false) {
                    cout << "Nu exista minim 2 valori introduse in registru pentru comparare!" << endl << endl;
                    break;
                }
                cout << "Introduce valoarea de referinta (target): ";
                cin >> target;

                cout << endl;
                for (int i = 0; i < N; i++)
                {
                    if (temp[i] > target) cout << "Temperatura din ziua " << i + 1 << " este peste valoarea cautata. (" << temp[i] << "°C)" << endl;
                }
                break;
            }

            case 8:
            {
                double target;
                if (N < 2 || introdus == false) {
                    cout << "Nu exista minim 2 valori introduse in registru pentru comparare!" << endl << endl;
                    break;
                }
                cout << "Introduce valoarea de referinta (target): ";
                cin >> target;

                cout << endl;
                for (int i = 0; i < N; i++)
                {
                    if (temp[i] < target) cout << "Temperatura din ziua " << i + 1 << " este sub valoarea cautata. (" << temp[i] << "°C)" << endl;
                }
                break;
            }

            case 9:
            {
                double target;
                cout << "Introduce temperatura minima de referinta: ";
                cin >> target;

                int maxLen = 0, currentLen = 0, startIdx = -1, tempStart = -1;

                for (int i = 0; i < N; i++)
                {
                    if (temp[i] > target)
                    {
                        if (currentLen == 0) tempStart = i;
                        currentLen++;

                        if (currentLen >= 2 && currentLen > maxLen)
                        {
                            maxLen = currentLen;
                            startIdx = tempStart;
                        }
                    }
                    else
                    {
                        currentLen = 0;
                    }
                }

                if (maxLen >= 2)
                {
                    cout << "Cea mai lunga secventa de zile consecutive cu temperaturi peste " << target << "°C este de " << maxLen << " zile:" << endl;
                    for (int i = startIdx; i < startIdx + maxLen; i++)
                    {
                        cout << "Ziua " << i + 1 << " (" << temp[i] << "°C)" << endl;
                    }
                }
                else
                {
                    cout << "Nu exista cel putin doua zile consecutive cu temperaturi peste " << target << "°C!" << endl;
                }
                break;
            }

            case 10:
            {
                cout << "Iesire din program." << endl;
                ended = true;
                return;
            }


            default:
                cout << "Tasta invalida!" << endl;
        }
    }
}


int main()
{
    cout << "Introduce perioada pe care vor fi prelucrate date: ";
    cin >> N;
    cout << endl << "Tasta 1 pentru a seta temperaturile pentru fiecare N zile." << endl;
    cout << "Tasta 2 pentru a afisa temperaturile introduse." << endl;
    cout << "Tasta 3 pentru a calcula media temperaturilor introduse." << endl;
    cout << "Tasta 4 pentru a cauta temperatura maxima." << endl;
    cout << "Tasta 5 pentru a sorta temperaturile crescator (nu afecteaza ordinea introdusa)." << endl;
    cout << "Tasta 6 pentru a cauta o temperatura (cautare binara)." << endl;
    cout << "Tasta 7 pentru a vedea toate zilele cu o temperatura PESTE cea introdusa." << endl;
    cout << "Tasta 8 pentru a vedea toate zilele cu o temperatura SUB cea introdusa." << endl;
    cout << "Tasta 9 pentru a verifica daca exista o secventa de minim 2 zile cu valori peste un anumit target." << endl;
    cout << "Tasta 10 pentru a iesi." << endl << endl;
    insertKey();
    return 0;
}

