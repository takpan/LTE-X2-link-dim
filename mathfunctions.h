#ifndef MATHFUNCTIONS
#define MATHFUNCTIONS

//#include <QtMath>
#include <QVector>
#include <QVariant>
//#include "qmath.h"
//#include <math.h>

long double binomial_coeff(int n, int k);

long double binomialProbOfExactly_k(int n, int k, double selectionProb);

float binomialProbOfAtLeast_k(int n, int k, float selectionProb);

long double vectorProbOfExactly_ki(const QVector<int> &nVector, const QVector<int> &kVector, double selectionProb);

QVector<QVector<int> > createAllPossibleVectors(const QVector<int> &n, int usrServClass);

void congestion_k_Vectors(QVector<QVariant> n, const QVector<QVariant> &dX2, const double &cX2, int userIndex, int currentIndex, QVector<QVector<QVariant> > &congVectorsArray);

void congestion_k_Vectors(const QVector<int> &n, int currentIndex, QVector<int> startVector,QVector<QVector<int> > &congVectorsArray);

double dotProduct(QVector<QVariant> a, QVector<QVariant> b);

float congestionProbability(const QVector<QVariant> &n, const QVector<QVector<QVariant> > &k, double p);

QVector<int> convertQVariantToInt(const QVector<QVariant> &qVarVector);

QVector<QVariant> calculateCongestionProbabilities(const QVector<QVariant> &nVector, const QVector<QVariant> &dX2Vector, const QVector<QVariant> &trunkResVector, const QVector<QVariant> &dComVector, const QVector<QVariant> &pExitVector, const double &delay, const double &cX2, bool trunkResBool);

int digitsAfterDecimalPoint(QVariant value);

#endif // MATHFUNCTIONS

