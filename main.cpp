#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

template <class T>//Creamos el template
class Matriz
{
    public://Datos publicos de mi matriz
        ~Matriz();
        T **m;//Usand el template
        int fil;
        int col;
        void definir();
        void agregar();
};
template <class T>
Matriz<T>::~Matriz() {} //Destructor

template <class T>
void Matriz<T>::definir()//Separamos memoria de manera dinamica
{
    m = new float *[fil];
    for(int i=0; i<fil; i++)
    {
        m[i] = new float [col];
    }
}

template <class T>
void Matriz<T>::agregar()//Agregamos los elementos a mi matriz
{
    for(int i=0; i<fil; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << "Dato en la posicion [" << i << "][" << j << "] --> ";
            cin >> m[i][j];
        }
    }
}


class Calculadora //Clase calcucladora que realizara y alamacenara las operaciones
{
    public:
        //Creamos un objeto de la clase Matriz y lo identificamos como float para el uso del template
        Matriz<float> m1;
        Matriz<float> m2;
        Matriz<float> m3;

        ~Calculadora();//Destructor
        void operator &();//Operador que suma y luego divide entre 3 a cada resultado
        void operator --();/*Operador que multiplica a cada elemento de una matriz por si mismos y luego se suman esos
        mismos elementos resultantes entre las 2 matrices*/
        void operator /(const Matriz<float> m3);/*Operador que divide cada elemento de la primera matriz con el de la segunda y luego ese elemento
        dividido es multiplicado por 0.5*/
        void operator !();//Funcion que multiplica mi primera matriz por un escalar
        //Operaciones
        void suma();
        void resta();
        void multiplicacion();
        void promedio();
        void mayor();
        void menor();
        void mostrar();
        void borrar();
};

Calculadora::~Calculadora() {} //Definiendo el destructor

void Calculadora::operator&()//Sobrecarga de operador
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = (m1.m[i][j] + m2.m[i][j])/3;
        }
    }
}

void Calculadora::operator --()//Sobrecarga de operador
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = ((m1.m[i][j])*(m1.m[i][j]) + (m2.m[i][j])*(m2.m[i][j]));
        }
    }
}

void Calculadora::operator /(const Matriz<float> m3)//Sobrecarga de operador con parametro
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = (m1.m[i][j] / m2.m[i][j])*0.5;
        }
    }
}

void Calculadora::operator !()//Sobrecarga de operador
{
    float e;
    cout << "\nDame un escalar --> ";
    cin >> e;
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = e*(m1.m[i][j]);
        }
    }

}

void Calculadora::suma()//Funcion suma
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = m1.m[i][j] + m2.m[i][j];
        }
    }
}

void Calculadora::resta()//Funcion resta
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = m1.m[i][j] - m2.m[i][j];
        }
    }
}

void Calculadora::multiplicacion()//Funcion multiplacion
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = 0;
            for(int k = 0; k<m1.col; k++)
            {
                m3.m[i][j] = m3.m[i][j] + (m1.m[i][k] * m2.m[k][j]);
            }
        }
    }
}

void Calculadora::promedio()//Funcion promedio
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = (m1.m[i][j] + m2.m[i][j])/2;
        }
    }
}

void Calculadora::mayor()//Funcion mayor
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = (m1.m[i][j] > m2.m[i][j])? m1.m[i][j] : m2.m[i][j];
        }
    }
}

void Calculadora::menor()//Funcion menor
{
    for(int i = 0; i<m1.fil; i++)
    {
        for(int j = 0; j<m1.col; j++)
        {
            m3.m[i][j] = (m1.m[i][j] < m2.m[i][j])? m1.m[i][j] : m2.m[i][j];
        }
    }
}

void Calculadora::mostrar()//Funcion que muestra los resultados
{
    cout << "\n";
    for(int i = 0; i<m3.fil; i++)
    {
        for(int j = 0; j<m3.col; j++)
        {
            cout << m3.m[i][j] << " ";
        }
        cout << "\n";
    }
}

void Calculadora::borrar()//Funcion que elimna el espacio de memoria almacenado
{
    for(int i=0;i<m1.fil;i++)
    {
        delete[] m1.m[i];
    }
    delete[] m1.m;
}

void matrizX()//CREADNO UNA MATRIZ X CON VECTOR
{
    vector < vector <int> > Mat(6, std::vector<int>(6, 0));
    int i ,j;
    for(i = 1  ; i <= 5 ; ++i)
    {
        for(j = 1 ; j <= 5 ; ++j)
        {
            if(i==j)
            {
                Mat[i][j] = 7;
            }
            else if(i==1 && j==5)
            {
                Mat[i][j] = 7;
            }
            else if(i==2 && j==4)
            {
                Mat[i][j] = 7;
            }
            else if(i==4 && j==2)
            {
                Mat[i][j] = 7;
            }
            else if(i==5 && j==1)
            {
                Mat[i][j] = 7;
            }
            else
            {
                Mat[i][j]=0;
            }
        }
    }

    for(i = 1  ; i <= 5 ; ++i)
    {
        for(j = 1 ; j <= 5 ; ++j)
        {
            cout << Mat[i][j] << " ";
        }cout << "\n";
    }

}

int main()
{
    int fil;
    int col;

    cout << "Dame mi numero de Filas HUMANO --> ";
    cin >> fil;
    cout << "Dame mi numero de Columnas HUMANO --> ";
    cin >> col;

    Calculadora cal;//Creando objeto de la calse calculadora

    //Creando mi primera matriz
    cal.m1.fil = fil;
    cal.m1.col = col;
    cal.m1.definir();
    //Creando mi segunda matriz
    cal.m2.fil = fil;
    cal.m2.col = col;
    cal.m2.definir();
    //Creando mi tercera matriz
    cal.m3.fil = fil;
    cal.m3.col = col;
    cal.m3.definir();

    cout << "\nDigitando valores de la primera matriz \n";
    cal.m1.agregar();

    cout << "\nDigitando valores de la segunda matriz \n";
    cal.m2.agregar();
    cout << "\nMatriz Equis X\n\n";
    matrizX();
    cout << "\nOPERACIONES \n";//Empieza las operaciones
    cout << "\nOperacion 1\n";
    cal.operator &();
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 2\n";
    cal.operator --();
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 3\n";
    cal.operator /(cal.m3);
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 4\n";
    cal.operator !();
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 5\n";
    cal.suma();
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 6\n";
    cal.resta();
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 7\n";
    cal.multiplicacion();
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 8\n";
    cal.promedio();
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 9\n";
    cal.mayor();
    cal.mostrar();
    cal.borrar();

    cout << "\nOperacion 10\n";
    cal.menor();
    cal.mostrar();
    cal.borrar();

    return 0;
}
