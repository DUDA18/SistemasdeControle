#ifndef __MATRIX_H_INCLUDED
#define __MATRIX_H_INCLUDED
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#define pi 3.14

using namespace std;

//! Classe Matriz, com o intuito de realizar opera��es entre matrizes entre outras fun��es.

/*!
    Biblioteca que gerencia matrizes, tais como as suas opera��es e propriedades.
*/


template <class UsedType>
class Matrix
{
private:

    int rows; //! Membro que armazena o n�mero de linhas da Matriz.
    int cols; //! Membro que armazena o n�mero de colunas da Matriz.
    UsedType **Mat; //! Ponteiro duplo aonde ser�o armazenados os dados da Matriz.

    //! Fun��o de verifica��o a interna das dimens�es da matriz.

    /*!
        A fun��o verifica se a matriz � quadrada ou n�o.
        \param Mat1 Matriz de entrada a se verificar as dimens�es.
    */
    bool sqr(Matrix<UsedType> Mat1);

    //! Fun��o de verifica��o interna da matriz.

    /*!
        A fun��o verifica se a matriz � identidade.
        \param Mat1 Matriz de entrada a se verificar se � identidade.
    */
    bool ind(Matrix<UsedType> Mat1);


public:

    //! Construtor padr�o da classe.

    /*!
        Inicia o objeto da classe com os elementos em 0.
    */
    Matrix();

    //! Construtor que toma como par�metros o n�mero de linhas e colunas

    /*!
        Inicializa a matriz com o n�mero corresponde de linhas e colunas, e inicia todos os elementos em 0.
        \param row N�mero de linhas da matriz.
        \param col N�mero de colunas da matriz.
    */
    Matrix(int row, int col);

    //! Construtor de c�pia da classe.

    /*!
        Construtor de c�pia da classe, gerencia as aplica��es de mem�ria da classe
        \param otherMatrix Recebe como par�metro uma c�pia da matriz.
    */
    Matrix(const Matrix & otherMatrix);

    //! Destrutor padr�o da classe.

    /*!
        Libera todas as mem�rias alocadas durante a execu��o de objetos da classe.
    */
    ~Matrix();//Destrutor

    //! M�todo de inicializa��o da matriz.

    /*!
        Inicializa a matriz com o respectivo n�mero de linhas e colunas.
        \param row N�mero de linhas da matriz.
        \param col N�mero de colunas da matriz.
    */
    void init(int row, int col);

    //! M�todo de inicializa��o da matriz tomando um valor de string como entrada.

    /*!
        Inicializa a matriz com uma determinada cadeia de caracteres dada como entrada.
        \param value Cadeia de caracteres que definem a matriz, separasse os elementos por v�rgula
                     e as colunas por ponto e v�rgula.
    */
    void init(string value);

    //! M�todo para se colocar valores em uma determinada posi��o da matriz.

    /*!
        Toma como entrada a posi��o da matriz e insere um determinado elemento.
        \param rol Linha a ser inserido o valor.
        \param col Linha a ser inserido o valor.
        \param number Valor a ser inseriodo.
    */
    void add(int rol, int col, UsedType number);

    //! M�todo para criar uma matriz identidade.

    /*!
        Cria uma matriz quadrada identidade.
        \param num N�mero corresponde a dimens�o da matriz, a matriz criada � quadrada.
    */
    void eye(int num);

    //! Cria uma matriz de uns.

    /*!
        Toma como par�metros a dimens�o da matriz, e cria uma matriz totalmente preenchida com o n�mero 1.
        \param row N�mero de linhas da matriz.
        \param col N�mero de colunas da matriz.
    */
    void ones(int row, int col);

    //! Cria uma matriz de zeros.

    /*!
        Toma como par�metros a dimens�o da matriz, e cria uma matriz totalmente preeenchida com o n�mero 0.
        \param row N�mero de linhas da matriz.
        \param col N�mero de colunas da matriz.
    */
    void zeros(int row, int col);

    //! Cria uma matriz com valores aleat�rios.

    /*!
        Toma como par�metros a dimens�o da matriz, e cria uma matriz preeenchida com n�meros aleat�rios.
        \param row N�mero de linhas da matriz.
        \param col N�mero de colunas da matriz.
    */
    void randU(int row, int col);

    //! Retorna o maior tamanho entre as linhas e colunas
    int length();

    //! C�lcula a m�dia dos elementos da matriz.

    /*!
        Considera uma matriz como uma amostra, retirando a m�dia aritm�tica das linhas da matriz.
    */
    Matrix Avarage();

    //! C�lcula a vari�ncia dos elemensto de uma matriz.

    /*
        C�lcula a m�dia da matriz e retorna a vari�ncia dos elementos.
    */
    Matrix Variance();

    //! C�lcula o desvio padr�o da matriz.

    /*!
        Retorna o desvio padr�o de uma matriz.
    */
    Matrix Std();

    //! Exibe a matriz.
    void print();

    //! Operador de soma de matrizes.

    /*!
        Soma matriz matriz.
        \param Mat1 Matriz a ser somada.
    */
    Matrix operator+(Matrix Mat1);

    //! Soma matriz escalar.

    /*!
        Soma a matriz a um determinado escalar.
        \param a Escalar a ser somado.
    */
    Matrix operator+(UsedType a);

    //! Subtra��o matriz matriz.

    /*!
        Subtrai de uma matriz outra matriz.
        \param Mat1 Matriz que ser� subtraida.
    */
    Matrix operator-(Matrix Mat1);

    //! Subtra��o matriz escalar.

    /*!
        Subtrai um escalar de uma matriz.
        \param a Escalar a ser subtra�do.
    */
    Matrix operator-(UsedType a);

    //! Operador de igualdade de uma matriz.

    /*!
        Iguala uma matriz a outra matriz.
        \param Mat1 Matriz a ser igualada.
    */
    void operator=(Matrix Mat1);

    //! Operador de igualdade para uma string.

    /*!
        Iguala a matriz a uma string de entrada.
        \param value String a qual a matriz deve ser igualada.
        \sa void init(string value)
    */
    void operator=(string value);


    void operator=(UsedType B(int row, int col));
    //---------------------------------//

    //-----Operadores de Multiplica��o-----//
    Matrix operator*(Matrix Mat1);//Multiplica��o Matriz Matriz
    Matrix operator*(UsedType a);//Multiplica��o Escalar Matriz
    //------------------------------------//

    //-----Operadores de Multiplica��o-----//
    Matrix operator/(Matrix Mat1);//Multiplica��o Matriz Matriz
    Matrix operator/(UsedType a);//Multiplica��o Escalar Matriz
    //------------------------------------//

    //-----Operadores de Concatena��o Matrizes-----//
    Matrix operator| (Matrix Mat1);//Concatena Matrizes a Esquerda
    Matrix operator|| (Matrix Mat1);//Concatena Matrizes Abaixo
    //--------------------------------------------//

    //----Operador de Matriz Transposta-----//
    Matrix operator~();
    //-------------------------------------//

    //-----Operador de Pot�ncia de Matrizes-----//
    Matrix operator^(UsedType exp);//Eleva a matriz a um determinado expoente.
    Matrix operator> (UsedType num);//Eleva os elementos de uma matriz a um determinado
    UsedType operator() (int row,int col);//Acessa os elementos de uma matriz
    void operator() (int row, int col, UsedType value);

    void lineVector(int left, int rigth);//Cria uma matriz elementos crescentes ou decrescentes de um em um de left at� rigth
    //-----------------------------------------//

    //##########################################//

    //#####�lgebra Linear#####//
    UsedType trace();//C�lculo do tra�o de uma matriz.
    Matrix inv();//C�lculo da matriz inversa da matriz.
    Matrix pol();//C�lculo dos �ndices do polin�mio caracter�stico da matriz.
    Matrix eigenvalues();//C�lculo dos auto valores de uma matriz.
    UsedType det();//C�lculo do determinante de uma matriz.
    //##############################//



    //#####Retornando Informa��es da Matriz#####//
    int getRows();//Retorna o n�mero de linhas da matriz.
    int getCols();//Retorna o n�mero de colunas da matriz.
    void setLine(int num, Matrix<UsedType> Line);
    void setColumn(int num, Matrix<UsedType> Colummn);
    Matrix<UsedType> getLine(int num);
    Matrix<UsedType> getColumn(int num);
    UsedType getMat(int row, int col);//Retorna o elemento no �ndice ij da matriz.
    void setMat(int row, int col, UsedType num);
    //#######################################################//
//Friend functions
    template<class FriendType> friend Matrix<FriendType> operator- (FriendType a, Matrix<FriendType> Mat1);//Soma Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator- (FriendType a, Matrix<FriendType> Mat1);//Subtra��o Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator* (FriendType a, Matrix<FriendType> Mat1);//Multiplica��o Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator/ (FriendType a, Matrix<FriendType> Mat1);//divis�o Matriz Escalar

    template<class FriendType> friend Matrix<FriendType> diff(Matrix<FriendType> M, FriendType h);//C�lcula a derivada de uma matriz.

    template<class FriendType> friend FriendType max(Matrix<FriendType> M);//Retorna o maior valor de uma matriz
    template<class FriendType> friend FriendType min(Matrix<FriendType> M);//Retorna o menor valor de uma matriz
    template<class FriendType> friend FriendType norm(Matrix<FriendType> M);//Retorna o maior valor de uma matriz
    template<class FriendType> friend Matrix<FriendType> abs(Matrix<FriendType> M);//Retorna o modulo dos valores de uma matriz
    template<class FriendType> friend Matrix<FriendType> cos(Matrix<FriendType> M1);//Retorna o cosseno dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> sin(Matrix<FriendType> M1);//Retorna o seno dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> tan(Matrix<FriendType> M1);//Retorna a tangente dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> acos(Matrix<FriendType> M1);//Retorna o arco cosseno dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> asin(Matrix<FriendType> M1);//Retorna o arco seno dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> atan(Matrix<FriendType> M1);//Retorna o arco tangente dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> cosh(Matrix<FriendType> M1);//Retorna o cosseno hiperb�lico dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> sinh(Matrix<FriendType> M1);//Retorna o seno hiperb�lico dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> tanh(Matrix<FriendType> M1);//Retorna a tangente hiperb�lica dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> acosh(Matrix<FriendType> M1);//Retorna o arco cosseno hiperb�lico dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> asinh(Matrix<FriendType> M1);//Retorna o arco seno hiperb�lico dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> atanh(Matrix<FriendType> M1);//Retorna o arco tangente hiperb�lica dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> exp(Matrix<FriendType> M1);//Retorna a exponencial dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> log(Matrix<FriendType> M1);//Retorna o logaritmo neperiano dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> log10(Matrix<FriendType> M1);//Retorna o logaritmo na base 10 dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> ceil(Matrix<FriendType> M1);//arredonda para cima os elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> round(Matrix<FriendType> M1);//arredonda os elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> floor(Matrix<FriendType> M1);//arredonda para baixo os elementos de uma matriz
};

#endif // __MATRIX_H_INCLUDED
