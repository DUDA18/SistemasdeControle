#ifndef IntegrativeModel_H
#define IntegrativeModel_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"

namespace ModelHandler {
    template <class Type>
    class IntegrativeModel: public ModelHandler::Model<Type>
    {
    public:

        IntegrativeModel(LinAlg::Matrix<Type> A , LinAlg::Matrix<Type> B,
                          LinAlg::Matrix<Type> C , LinAlg::Matrix<Type> D);
        IntegrativeModel(LinAlg::Matrix<Type> Ad, LinAlg::Matrix<Type> Bd,
                          LinAlg::Matrix<Type> C , LinAlg::Matrix<Type> D,
                          Type SampleTime);
        IntegrativeModel(ModelHandler::StateSpace<Type> &SS);

        LinAlg::Matrix<Type> getA() const;
        LinAlg::Matrix<Type> getB() const;
        LinAlg::Matrix<Type> getC() const;
        LinAlg::Matrix<Type> getD() const;

        unsigned getNumberOfVariables(){}

        void setContinuous(bool Continuous);
        void setSampleTime(double SampleTime);
        void setInitialState(LinAlg::Matrix<Type> X0);
        void setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output){}
        void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output){}
        void SetObserverParameter(LinAlg::Matrix<Type> L);

        bool isContinuous()  const;
        bool isObservable()  const;
        bool isControlable() const;

        Type sim(Type u);
        Type sim(Type u, Type y){}
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> u);
        LinAlg::Matrix<Type> sim(Type lmin, Type lmax, Type step);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> u, LinAlg::Matrix<Type> y){}

        std::string print();

    private:
        bool Continuous;
        unsigned nDiscretization;
        Type SampleTime, TimeSimulation;
        LinAlg::Matrix<Type> A, B, C, D, Ad, Bd, X, initialState, L;
    };

    template<typename Type>
    std::ostream& operator<< (std::ostream& output, ModelHandler::IntegrativeModel<Type> SS);
    template<typename Type>
    std::string&  operator<< (std::string& output,  ModelHandler::IntegrativeModel<Type> SS);
}

#include "SistemasdeControle/src/modelLibs/integrativemodel.hpp"
#endif // IntegrativeModel_H
