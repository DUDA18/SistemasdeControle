#include "model.h"

template <class UsedType>
Model<UsedType>::Model()
{
}

template <class UsedType>
void Model<UsedType>::setInstance(Model<UsedType> *m)
{
    this->instance = m;
}

template <class UsedType>
void Model<UsedType>::setStep(UsedType step)
{
    this->step = step;
}

template <class UsedType>
UsedType Model<UsedType>::diff(UsedType x)
{
    return (instance->sim(x+step)-instance->sim(x))/step;
}

template <class UsedType>
void Model<UsedType>::setModelCoef(Matrix<UsedType> coef)
{
    this->ModelCoef = coef;
}

template <class UsedType>
Matrix<UsedType> Model<UsedType>::getInputMatrix()
{
    return this->Input;
}

template <class UsedType>
Matrix<UsedType> Model<UsedType>::getOutputMatrix()
{
    return this->Output;
}

template <class UsedType>
UsedType Model<UsedType>::getOutput()
{
    return this->output;
}

template <class UsedType>
Matrix<UsedType> Model<UsedType>::getLinearVectorPhi()
{
    return this->LinearVectorPhi;
}

template <class UsedType>
Matrix<UsedType> Model<UsedType>::getLinearMatrixA()
{
    return this->LinearMatrixA;
}

template <class UsedType>
Matrix<UsedType> Model<UsedType>::getLinearEqualityB()
{
    return this->LinearEqualityB;
}

template <class UsedType>
Matrix<UsedType> Model<UsedType>::getModelCoef()
{
    return this->ModelCoef;
}


template class Model<float>;
template class Model<double>;
