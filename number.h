#ifndef NUMBER_H
#define NUMBER_H
#include <QObject>
#include <QDebug>

#include <iostream>
#include <math.h>
using namespace std;

enum INPUT_TYPE{
    HEX_INPUT_TYPE = 0,
    DEC_INPUT_TYPE,
    OCT_INPUT_TYPE,
    BIN_INPUT_TYPE
};

enum RADIX_TYPE{
    HEX_RADIX_TYPE = 0,
    DEC_RADIX_TYPE,
    OCT_RADIX_TYPE,
    BIN_RADIX_TYPE
};

class Number : public QObject
{
    Q_OBJECT
public:
    explicit Number(QObject *parent = nullptr);
    ~Number();

public:
    int getNumber();
    void setNumber(INPUT_TYPE inputType);
    void castToDecimal(RADIX_TYPE radixType);

    //cast number to Decimal
    int castNumberFromHexToDec(string numberInput);
    int castNumberFromDecToDec(string numberInput);
    int castNumberFromOctToDec(string numberInput);
    int castNumberFromBinToDec(string numberInput);

    // convert Radix from Dec
    int* castFromDecToHex(int number);
    int* castFromDecToDec(int number);
    int* castFromDecToOct(int number);
    int* castFromDecToBin(int number);
private:   
    int index = 0;
    int m_decValue;
    int m_number;
    string m_numberInput;

    int m_hexNumber[100];
    int m_decNumber[100];
    int m_octNumber[100];
    int m_binNumber[64];

};


#endif // NUMBER_H
