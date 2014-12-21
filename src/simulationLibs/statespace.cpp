#include "statespace.h"

template <class UsedType>
void StateSpace<UsedType>::c2dConversion()
{
    this->Ad.zeros(this->A.getRows(), this->A.getCols());
    for(int i = 0; i < nDiscretization; i++)
        Ad = Ad + (1/factorial(i))*(A^i)*(pow(SampleTime, i));
    Bd = (A^-1)*(Ad - (Ad^0))*B;
}

template <class UsedType>
void StateSpace<UsedType>::d2cConversion()
{
    Matrix<UsedType> Mat, E, Temp, Root, I, ZeroVector, IAd;

    Mat = Ad.eigenvalues();
    IAd.eye(Ad.getRows());
    for(int j = 1; j < nDiscretization; j++)
        E( 1, j+1, pow(this->SampleTime, j)/factorial(j));

    I.eye(E.getCols()-2);
    ZeroVector.zeros( E.getCols()-2, 1);

    for (unsigned i = 0; i < Mat.getRows(); i++)
    {
        E( 1, 1, 1 - Mat(1, i+1));
        Temp = E||(I|ZeroVector);
        Root = Temp.eigenvalues();
        UsedType autovalor = max(abs(Root));
        A( i+1, i+1, autovalor);
    }
    B = (((A^-1)*(Ad - IAd))^-1)*Bd;
}

template <class UsedType>
StateSpace<UsedType>::StateSpace(Matrix<UsedType> A, Matrix<UsedType> B,
                                 Matrix<UsedType> C, Matrix<UsedType> D)
{
    this->A                  =    A;
    this->B                  =    B;
    this->C                  =    C;
    this->D                  =    D;
    this->Continuous         = true;
    this->SampleTime         =  0.1;
    this->TimeSimulation     =   10;
    this->nDiscretization    =    4;
}

template <class UsedType>
void StateSpace<UsedType>::print()
{
    if(this->Continuous == true)
    {
        std::cout<<std::endl<<"A = "<<std::endl;
        this->A.print();
        std::cout<<std::endl<<"B = "<<std::endl;
        this->B.print();
    }
    else
    {
        std::cout<<std::endl<<"A = "<<std::endl;
        this->Ad.print();
        std::cout<<std::endl<<"B = "<<std::endl;
        this->Bd.print();
    }
    std::cout<<std::endl<<"C = "<<std::endl;
    this->C.print();
    cout<<endl<<"D = "<<endl;
    this->D.print();
    cout<<endl;
}

template <class UsedType>
UsedType StateSpace<UsedType>::sim(UsedType u)
{
    X = initialState;
    Matrix<UsedType> Xi1 = Ad*X+Bd*u;
    Matrix<UsedType> y  = C*X+D*u;

    return y(1,1);
}

template <class UsedType>
Matrix<UsedType> StateSpace<UsedType>::sim(Matrix<UsedType> u)
{
    Matrix<UsedType> y;
    X = initialState;
    for(unsigned i = 0; i < u.getCols(); i++)
    {
        Matrix<UsedType> Xi1 = Ad*X+Bd*u.getColumn(i+1);
        y = C*X+D*u.getColumn(i+1);
    }

    return y;
}

template <class UsedType>
UsedType StateSpace<UsedType>::factorial(unsigned n)
{
    UsedType retval = 1;

    for (int i = n; i > 1; --i)
        retval *= i;

    return retval;
}