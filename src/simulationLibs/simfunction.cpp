#include "simfunction.h"

template<class UsedType>
simFunction<UsedType>::simFunction(UsedType (*FunctionToCall)(UsedType))
{
    this->FunctionToCall = FunctionToCall;
}

template <class UsedType>
UsedType simFunction<UsedType>::sim(UsedType input)
{
    input = ((*this->FunctionToCall)(input));
    return (input);
}

template<class UsedType>
Matrix<UsedType> simFunction<UsedType>::sim(Matrix<UsedType> X)
{
    Matrix<UsedType> Y;

    for(int i = 1; i < X.getRows(); i++)
        for(int j = 1; j < X.getRows(); j++)
            Y(i,j, sim(X(i,j)));

    return Y;
}

template<class UsedType>
Matrix<UsedType> simFunction<UsedType>::sim(UsedType lmim, UsedType lmax, UsedType step)
{
    unsigned i = 1;
    Matrix<UsedType> Y;

    for(UsedType x = lmim; x <= lmax; x+= step)
    {
        Y(i,1, sim(x));
        i++;
    }

    return Y;
}

template <class UsedType>
void simFunction<UsedType>::GenerateDataFunction()
{
    int tam  = (int)((this->lmax - this->lmin)/this->step);
    int cont = 1;
    this->Input.init(1,tam);

    for (UsedType i = this->lmin; i < this->lmax; i += this->step)
    {
        this->Input(1,cont,i);
        this->Output(1,cont,this->sim(i));
        cont++;
    }
}
template <class UsedType>
UsedType simFunction<UsedType>::normalize(UsedType input, UsedType xUp,
                              UsedType xDown, UsedType yUp, UsedType yDown)
{
    return ((input - xDown)/(xUp - xDown))*(yUp - yDown) + yDown;
}

template <class UsedType>
void simFunction<UsedType>::SetDataStep(UsedType step)
{
    this->step = step;
}

template <class UsedType>
void simFunction<UsedType>::SetDataLimits(UsedType lMin, UsedType lMax)
{
    this->lmax = lMax;
    this->lmin = lMin;
}

template <class UsedType>
void simFunction<UsedType>::SetInputData(Matrix<UsedType> input)
{
    this->Input = input;
}

template <class UsedType>
void simFunction<UsedType>::SetOutputData(Matrix<UsedType> output)
{
    this->Output = output;
}

template <class UsedType>
void simFunction<UsedType>::SetFunctionCall(UsedType (*FunctionToCall)(UsedType))
{
    this->FunctionToCall = FunctionToCall;
}

template <class UsedType>
Matrix<UsedType> simFunction<UsedType>::GetInputData()
{
    return this->Input;
}

template <class UsedType>
Matrix<UsedType> simFunction<UsedType>::GetOutputData()
{
    return this->Output;
}

template <class UsedType>
UsedType simFunction<UsedType>::GetDataStep()
{
    return this->step;
}

template <class UsedType>
UsedType simFunction<UsedType>::GetDataMinLimit()
{
    return this->lmin;
}

template <class UsedType>
UsedType simFunction<UsedType>::GetDataMaxLimit()
{
    return this->lmax;
}


//typedef double(*FunctionCall)(double);
//template <class UsedType>
//FunctionCall simFunction<UsedType>::GetFunctionCall()
//{
//    return this->FunctionToCall;
//}


template class simFunction<float>;
template class simFunction<double>;
