#include "number.h"

Number::Number(QObject *parent) : QObject(parent)
{

}

Number::~Number()
{

}

int Number::getNumber()
{
    return m_number;
}

int Number::castNumberFromHexToDec(string numberInput)
{
    int base = 16;
    for(int i = numberInput.length() - 1, j = 0; i >= 0, j < numberInput.length(); i--, j++){
        m_decValue += (numberInput[j]-48)*(pow(base,i));
    }
    m_number = m_decValue;
    qDebug ("%d", m_number);
    return m_number;
}

int Number::castNumberFromDecToDec(string numberInput)
{
    int base = 10;
    for(int i = numberInput.length() - 1, j = 0; i >= 0, j < numberInput.length(); i--, j++){
        m_decValue += (numberInput[j]-48)*(pow(base,i));
    }
    m_number = m_decValue;
    qDebug ("%d", m_number);
    return m_number;
}

int Number::castNumberFromOctToDec(string numberInput)
{
    int base = 8;
    for(int i = numberInput.length() - 1, j = 0; i >= 0, j < numberInput.length(); i--, j++){
        m_decValue += (numberInput[j]-48)*(pow(base,i));
    }
    m_number = m_decValue;
    qDebug ("%d", m_number);
    return m_number;
}

int Number::castNumberFromBinToDec(string numberInput)
{
    int base = 2;
    for(int i = numberInput.length() - 1, j = 0; i >= 0, j < numberInput.length(); i--, j++){
        m_decValue += (numberInput[j]-48)*(pow(base,i));
    }
    m_number = m_decValue;
    qDebug ("%d", m_number);
    return m_number;
}

int* Number::castFromDecToHex(int number)
{

    int m_hexNumberToShow[100] = {0};
    while(number > 0){
        m_hexNumber[index] = number % 16;
        number = number / 16;
        index++;
    }
    for(int i = index - 1, j = 0; i >= 0, j < index; i--, j++)
    {
        m_hexNumberToShow[j] = m_hexNumber[i];
    }
    return m_hexNumberToShow;
}

int* Number::castFromDecToDec(int number)
{
    int m_decNumberToShow[100] = {0};
    while(number > 0){
        m_decNumberToShow[index] = number % 10;
        number = number / 10;
        index++;
    }
    for(int i = index - 1, j = 0; i >= 0, j < index; i--, j++)
    {
        m_decNumberToShow[j] = m_decNumber[i];
    }
    index = 0;
    return m_decNumberToShow;
}

int* Number::castFromDecToOct(int number)
{
    int m_octNumberToShow[100] = {0};
    while(number > 0){
        m_octNumber[index] = number % 8;
        number = number / 8;
        index++;
    }
    for(int i = index - 1, j = 0; i >= 0, j < index; i--, j++)
    {
        m_octNumberToShow[j] = m_octNumber[i];
    }
    index = 0;
    return m_octNumberToShow;
}

int* Number::castFromDecToBin(int number)
{
    int m_binNumberToShow[64] = {0};
    while(number > 0){
        m_binNumber[index] = number % 2;
        number = number / 2;
        index++;
    }
    for(int i = index - 1, j = 0; i >= 0, j < index; i--, j++)
    {
        m_binNumberToShow[j] = m_binNumber[i];
    }
    index = 0;
    return m_binNumberToShow;
}

void Number::castToDecimal(RADIX_TYPE radixType)
{
    switch (radixType) {
    case HEX_RADIX_TYPE:
        castNumberFromHexToDec(m_numberInput);
        break;
    case DEC_RADIX_TYPE:
        castNumberFromDecToDec(m_numberInput);
        break;
    case OCT_RADIX_TYPE:
        castNumberFromOctToDec(m_numberInput);
        break;
    case BIN_RADIX_TYPE:
        castNumberFromBinToDec(m_numberInput);
        break;
    default:
        break;
    }
}

void Number::setNumber(INPUT_TYPE inputType)
{
    switch(inputType){
    case HEX_INPUT_TYPE:
        castFromDecToHex(m_number);
        break;
    case DEC_INPUT_TYPE:
        castFromDecToDec(m_number);
        break;
    case OCT_INPUT_TYPE:
        castFromDecToOct(m_number);
        break;
    case BIN_INPUT_TYPE:
        castFromDecToBin(m_number);
        break;
    default:
        break;
    }
}



