#include <QString>
#include <QtTest>
#define testMatrix
#include "../../../../../SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

class MatrixTest : public QObject
{
    Q_OBJECT

public:
    MatrixTest(){}

private Q_SLOTS:
    void construtorMatrixTypeInt();
    void construtorMatrixTypeChar();
    void construtorMatrixTypeShort();
    void construtorMatrixTypeFloat();
    void construtorMatrixTypeDouble();
    void construtorMatrixTypeLongDouble();
    void construtorMatrixTypeCStringAndDouble();
    void construtorMatrixTypeStringAndDouble();
    void construtorSizedVoidMatrix();
    void construtorNULLMatrix();
    void copyconstrutor();
};

void MatrixTest::construtorMatrixTypeChar()
{
    QBENCHMARK {
        LinAlg::Matrix<char> A('a');
    }
    LinAlg::Matrix<char> A('a');
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 'a', "Falhou ao comparar o elemento da matriz com valor char");
    QVERIFY2(sizeof(A(1,1)) == sizeof(char), "Falhou ao comparar o tipo do elemento da matriz com valor char");
}

void MatrixTest::construtorMatrixTypeShort()
{
    QBENCHMARK {
        LinAlg::Matrix<short> A(1);
    }
    LinAlg::Matrix<short> A(1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1, "Falhou ao comparar o elemento da matriz com valor short");
    QVERIFY2(sizeof(A(1,1)) == sizeof(short), "Falhou ao comparar o tipo do elemento da matriz com valor short");
}

void MatrixTest::construtorMatrixTypeInt()
{
    QBENCHMARK {
        LinAlg::Matrix<int> A(1);
    }
    LinAlg::Matrix<int> A(1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1, "Falhou ao comparar o elemento da matriz com valor inteiro");
    QVERIFY2(sizeof(A(1,1)) == sizeof(int), "Falhou ao comparar o tipo do elemento da matriz com valor inteiro");
}

void MatrixTest::construtorMatrixTypeFloat()
{
    QBENCHMARK {
        LinAlg::Matrix<float> A(1.5);
    }
    LinAlg::Matrix<float> A(1.5);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.5, "Falhou ao comparar o elemento da matriz com valor float");
    QVERIFY2(sizeof(A(1,1)) == sizeof(float), "Falhou ao comparar o tipo do elemento da matriz com valor float");
}

void MatrixTest::construtorMatrixTypeDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A(1.1);
    }
    LinAlg::Matrix<double> A(1.1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.1, "Falhou ao comparar o elemento da matriz com valor double");
    QVERIFY2(sizeof(A(1,1)) == sizeof(double), "Falhou ao comparar o tipo do elemento da matriz com valor double");
}

void MatrixTest::construtorMatrixTypeLongDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<long double> A(1.1);
    }
    LinAlg::Matrix<long double> A(1.1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.1, "Falhou ao comparar o elemento da matriz com valor long double");
    QVERIFY2(sizeof(A(1,1)) == sizeof(long double), "Falhou ao comparar o tipo do elemento da matriz com valor long double");
}

void MatrixTest::construtorMatrixTypeCStringAndDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A("1,2,3,4;5,6,7,8");
    }
    LinAlg::Matrix<double> A("1,2,3,4;5,6,7,8");
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.0 && A(1,2) == 2.0 && A(1,3) == 3.0 && A(1,4) == 4.0 &&
             A(2,1) == 5.0 && A(2,2) == 6.0 && A(2,3) == 7.0 && A(2,4) == 8.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::construtorMatrixTypeStringAndDouble()
{
    std::string str = "1,2,3,4;5,6,7,8";
    QBENCHMARK {
        LinAlg::Matrix<double> A(str);
    }
    LinAlg::Matrix<double> A(str);
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.0 && A(1,2) == 2.0 && A(1,3) == 3.0 && A(1,4) == 4.0 &&
             A(2,1) == 5.0 && A(2,2) == 6.0 && A(2,3) == 7.0 && A(2,4) == 8.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::construtorSizedVoidMatrix()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A(3,3);
    }
    LinAlg::Matrix<double> A(3,3);
    QVERIFY2(A.getNumberOfColumns() == 3 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 0.0 && A(1,2) == 0.0 && A(1,3) == 0.0 &&
             A(2,1) == 0.0 && A(2,2) == 0.0 && A(2,3) == 0.0 &&
             A(3,1) == 0.0 && A(3,2) == 0.0 && A(3,3) == 0.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::construtorNULLMatrix()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A;
    }
    LinAlg::Matrix<double> A;
    QVERIFY2(A.getNumberOfColumns() == 0 && A.getNumberOfRows() == 0, "Falhou ao testar o tamanho da matriz");
}

void MatrixTest::copyconstrutor()
{
    LinAlg::Matrix<double> A = "1,2;3,4";
    QBENCHMARK {
        LinAlg::Matrix<double> B(A);
    }
    LinAlg::Matrix<double> B(A);
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1.0 && B(1,2) == 2.0 &&
             B(2,1) == 3.0 && B(2,2) == 4.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

QTEST_APPLESS_MAIN(MatrixTest)

#include "tst_matrixtest.moc"
