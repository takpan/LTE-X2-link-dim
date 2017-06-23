#include "mathfunctions.h"

long double binomial_coeff(int n, int k)
{
    long double sum = 0;

    for (int i = 1; i <= n; i++)
        sum += log(i);

    for (int i = 1; i <= k; i++)
        sum -= log(i);

    for (int i = 1; i <= n - k; i++)
        sum -= log(i);

    sum = exp(sum);
    return sum;
}

long double binomialProbOfExactly_k(int n, int k, double selectionProb)
{
    long double prob = 1;

    for (int i = 1; i <= k; i++)
        prob *= selectionProb;

    for (int i = 1; i <= n - k; i++)
        prob *= (1 - selectionProb);

    prob *= binomial_coeff(n, k);

    return prob;
}

float binomialProbOfAtLeast_k(int n, int k, float selectionProb)
{
    float prob = 0;

    for (int i = k; i <= n; i++)
        prob += binomialProbOfExactly_k(i, n, selectionProb);

    return prob;
}

long double vectorProbOfExactly_ki(const QVector<int> &nVector, const QVector<int> &kVector, double selectionProb)
{
    long double prob = 1;
    int c = nVector.size();

    for (int i = 0; i < c; i++)
        prob *= binomialProbOfExactly_k(nVector[i], kVector[i], selectionProb);

    return prob;
}

QVector<QVector<int> > createAllPossibleVectors(const QVector<int> &n, int usrServClass)
{
    int vectorSize = n.size();
    int totalVectors = 0;
    QVector<QVector<int> > vectors;
    QVector<int> startVector(vectorSize);
    QVector<int> nMod = n;
    nMod[usrServClass]--;

    for (int i = 0; i < vectorSize; i++)
    {
        QVector<int> currentVector2  = startVector;
        currentVector2[i] = 1;
        for (int j = i; j >= 0; j--)
        {
            QVector<int> currentVector3 = currentVector2;
            currentVector3[j]++;
            for (int k = 0; k <= nMod[j]; k++)
            {
                currentVector3[j] = k;
                totalVectors++;
                vectors.resize(totalVectors);
                vectors[totalVectors - 1] = currentVector3;
            }
        }
    }

    return vectors;
}

void congestion_k_Vectors(QVector<QVariant> n, const QVector<QVariant> &dX2, const double &cX2, int userIndex, int currentIndex, QVector<QVector<QVariant> > &congVectorsArray)
{
    int nextIndex;
    int vectorSize = n.size();
    double sumDX2;

    for (int i = n[currentIndex].toInt(); i >= 0; i--)
    {
        if (currentIndex < vectorSize - 1)
        {
            n[currentIndex] = i;
            nextIndex = currentIndex + 1;
            congestion_k_Vectors(n, dX2, cX2, userIndex, nextIndex, congVectorsArray);
        }
        else
        {
            sumDX2 = 0;
            for (int i = 0; i < vectorSize; i++)
                sumDX2 += n[i].toInt() * dX2[i].toDouble();

            sumDX2 += dX2[userIndex].toDouble();

            if (sumDX2 > cX2)
            {
                congVectorsArray.resize(congVectorsArray.size() + 1);
                congVectorsArray[congVectorsArray.size() - 1] = n;
                congVectorsArray[congVectorsArray.size() - 1].append(sumDX2);
            }
            else
            {
                n[currentIndex] = (n[currentIndex].toInt()) - 1;
                return;
            }

            n[currentIndex] = (n[currentIndex].toInt()) - 1;
        }
    }
}

void congestion_k_Vectors(const QVector<int> &n, int currentIndex, QVector<int> startVector, QVector<QVector<int> > &congVectorsArray)
{
    int nextIndex;
    int vectorSize = n.size();

    for (int i = 0; i <= n[currentIndex]; i++)
    {
        if (currentIndex < vectorSize - 1)
        {
            startVector[currentIndex] = i;
            nextIndex = currentIndex + 1;
            congestion_k_Vectors(n, nextIndex, startVector, congVectorsArray);
        }
        else
        {
            congVectorsArray.resize(congVectorsArray.size() + 1);
            congVectorsArray[congVectorsArray.size() - 1] = startVector;
            startVector[currentIndex]++;
        }
    }
}

double dotProduct(QVector<QVariant> a, QVector<QVariant> b)
{
    double result = 0;
    int size = a.size();

    for (int i = 0; i < size; i++)
        result += a[i].toDouble() * b[i].toDouble();

    return result;
}

float congestionProbability(const QVector<QVariant> &n, const QVector<QVector<QVariant> > &k, double p)
{
    long double prob = 0;
    long double probTemp;
    int size = k.size();

    for (int i = 0; i <size; i++)
    {
        QVector<QVariant> kCut = k[i];
        kCut.resize(k[i].size() - 1);
        probTemp = vectorProbOfExactly_ki(convertQVariantToInt(n), convertQVariantToInt(kCut), p);
        prob += probTemp;
    }

    return (float)prob;
}

QVector<int> convertQVariantToInt(const QVector<QVariant> &qVarVector)
{
    QVector<int> qIntVector;
    int size = qVarVector.size();

    qIntVector.resize(size);

    for (int i = 0; i < size; i++)
        qIntVector[i] = qVarVector[i].toInt();

    return qIntVector;
}

QVector<QVariant> calculateCongestionProbabilities(const QVector<QVariant> &nVector, const QVector<QVariant> &dX2Vector, const QVector<QVariant> &trunkResVector, const QVector<QVariant> &dComVector, const QVector<QVariant> &pExitVector, const double &delay,const double &cX2, bool trunkResBool)
{
    int c = nVector.size();
    double cX2arg;
    QVector<QVariant> congProb;
    QVector<QVector<QVector<QVariant> > > congVectors;

    congVectors.resize(c);
    congProb.resize(c);

    for (int i = 0; i < c; i++)
    {
        QVector<QVariant> nVectorCurrUser = nVector;
        nVectorCurrUser[i] = nVectorCurrUser[i].toInt() - 1;

        if (trunkResBool == true)
            cX2arg = cX2 - trunkResVector[i].toDouble();
        else
            cX2arg = cX2;

        congestion_k_Vectors(nVectorCurrUser, dX2Vector, cX2arg, i, 0, congVectors[i]);
    }

    for (int i = 0; i < c; i++)
    {
        float p = (pExitVector[i].toFloat()) * delay / ((dComVector[i].toFloat()) * 1000);
        QVector<QVariant> nVectorCurrUser = nVector;
        nVectorCurrUser[i] = nVectorCurrUser[i].toInt() - 1;
        congProb[i] = (double)(pExitVector[i].toFloat()) * congestionProbability(nVectorCurrUser, congVectors[i], p) ;
    }

    return congProb;
}

int digitsAfterDecimalPoint(QVariant value)
{
    int i;
    double valueDouble;
    valueDouble = value.toDouble();

    for (i = 0; valueDouble != rint(valueDouble); valueDouble *= 10, i++);

    return i;
}































