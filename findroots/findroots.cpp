#include <iostream>
using namespace std;

double RaizCu(double);
char Ceros(int, int, int);
void DivSint(int, int, int, int, int);
void RaicesRacionales(int, int, int, int);

int j = 0;
int z = 0;
int a, b, c, d, x, p, a0, b0, c0, d0;

float x1, r1, r2;
float ra[3];
string s;
char r[3];



int rai[3] = {};
int mult[100] = {};

int main()
{
    cout << "Ingrese el valor de a, b, c y d en su respectivo orden: \n";
    cin >> a >> b >> c >> d;

    //cout << a;
    //cout << b;
    //cout << c;
    //cout << d;

    cout << "\n";

    if ((a == 0) && (b == 0) && (c == 0))
    {
        cout << "{}";
    }
    else
    {
        RaicesRacionales(a, b, c, d);
        DivSint(x1, a, b, c, d);
        Ceros(a0, b0, c0);

    }
    system("pause");

    return 0;
}

//Funcion que encuentra los multiplos de la constante d y busca los ceros racionales
void RaicesRacionales(int t, int u, int v, int w)
{
    //cout << "Estos son los multiplos de d: \n";
    if (d < 0)
    {
        for (int i = d; i <= -d; i++)
        {
            if (d % i == 0)
            {
                mult[j] = i;
                //cout << mult[j] << ",";
                j++;
                if (i + 1 == 0)
                {
                    i = i + 1;
                }
            }
        }
        //cout << "\n";
    }
    else if (d == 0)
    {
        mult[0] = 0;
    }
    else if (d > 0)
    {
        for (int i = -d; i <= d; i++)
        {
            if (d % i == 0)
            {
                mult[j] = i;
                //cout << mult[j] << ",";
                j++;
                if (i + 1 == 0)
                {
                    i = i + 1;
                }
            }
        }
        //cout << "\n";
    }

    for (int l = 0; l < j; l++)
    {
        x = mult[l];
        p = (a * x * x * x) + (b * x * x) + (c * x) + (d);

        if (p == 0)
        {
            rai[z] = x;
            z++;
        }

    }
    //cout<<"\n"<<"Las raices racionales del polinomio son: \n";
    //for(int m = 0; m < 3; m++)
    //  {
    //    cout<<rai[m]<<", ";
    //  }
}


//Funcion que encuentra las constantes de nuestro nuevo polinomio cuadratico mediante division sintetica
void DivSint(int n, int o, int q, int s, int t)
{
    //cout << "Division sintetica: \n";
    x1 = rai[0];
    a0 = a;
    //cout << "Valor nuevo de a: " << a0 << "\n";
    int it1 = x1 * a;
    b0 = it1 + b;
    //cout << "Valor nuevo de b: " << b0 << "\n";
    int it2 = b0 * x1;
    c0 = it2 + c;
    //cout << "Valor nuevo de c: " << c0 << "\n";
    int it3 = c0 * x1;
    d0 = it3 + d;
    //cout << "Comprobamos que d si sea 0: " << d0 << "\n";

}



// Funcion que ecuentra las raices reales de un polinomio cuadrado
char Ceros(int t, int u, int v)
{
    int det = (u * u) - 4 * t * v;

    if (det >= 0)
    {
        double rr = RaizCu(det);
        r1 = ((-u) + rr) / (2 * t);
        r2 = ((-u) - rr) / (2 * t);

        ra[0] = x1;
        ra[1] = r1;
        ra[2] = r2;
        //cout << "Las raices reales del polinomio son: \n";
        cout << "{";
        for (int m = 0; m < 3; m++)
        {
            cout << ra[m] << ", ";
        }
        cout << "}" << "\n";
    }
    else
    {
        //cout << "Las unica raiz real del polinomio es: \n";
        ra[0] = x1;
        cout << "{" << ra[0] << "}" << "\n";


    }
    return *ra;
}

//Funcion que encuentra la raiz cuadrada de un numero usando el metodo de Newton Raphson
double RaizCu(double a)
{
    double x = a;
    double y = 1;
    double eps = 0.000000001; // Precisión deseada
    while (x - y > eps)
    {
        x = (x + y) / 2;
        y = a / x;
    }
    return x;
}

