#ifndef ARX_H
#define ARX_H
#include "SistemasdeControle/headers/modelLibs/model.h"

template <class UsedType>
class ARX : public Model<UsedType>
{
private:
    unsigned nInputpar  , nOutputpar  , delay,
             qdtInputVar, qdtOutputVar, nSample,
             maxnInOut,sampleTime;
public:
    ARX(unsigned nInputpar , unsigned nOutputpar,
        unsigned delay = 0,
        unsigned qdtInputVar = 1, unsigned qdtOutputVar = 1, float sampleTime = 0.1);
    ARX(const ARX<UsedType>& OtherArxModel);

    void setLinearVector(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> PastOutput);
    void setLinearModel (LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output);

    unsigned getNumberOfInputs();
    unsigned getNumberOfOutputs();
    unsigned getNumberOfInputDelays();
    unsigned getNumberOfOutputDelays();

    float getSampleTime();

    void print();
    UsedType sim(UsedType input);
    UsedType sim(UsedType input, UsedType output);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> Input);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output);
    LinAlg::Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // ARX_H