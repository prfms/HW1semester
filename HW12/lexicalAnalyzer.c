#include <string.h>
#include <ctype.h>

#include "lexicalAnalyzer.h"

bool isNumber(const char* string)
{
    const int stringLength = strlen(string);
    State state = Begin;
    for (int i = 0; i < stringLength + 1; ++i)
    {
        switch (state)
        {
            case Begin:
            {
                if (isdigit(string[i]))
                {
                    state = IntegerPart;
                    break;
                }
                return false;
            }
            case IntegerPart:
            {
                if (isdigit(string[i]))
                {
                    state = IntegerPart;
                    break;
                }
                if (string[i] == '.')
                {
                    state = DecimalPoint;
                    break;
                }
                if (string[i] == 'E')
                {
                    state = 4;
                    break;
                }
                return i == stringLength;
            }
            case DecimalPoint:
            {
                if (isdigit(string[i]))
                {
                    state = FractionalPart;
                    break;
                }
                return false;
            }
            case FractionalPart:
            {
                if (isdigit(string[i]))
                {
                    state = FractionalPart;
                    break;
                }
                if (string[i] == 'E')
                {
                    state = Exponent;
                    break;
                }
                return i == stringLength;
            }
            case Exponent:
            {
                if (isdigit(string[i]))
                {
                    state = ExponentSign;
                    break;
                }
                if (strchr("+-", string[i]) != NULL)
                {
                    state = ExponentDigits;
                    break;
                }
                return false;
            }
            case ExponentSign:
            {
                if (isdigit(string[i]))
                {
                    state =  ExponentSign;
                    break;
                }
                return i == stringLength;
            }
            case ExponentDigits:
            {
                if (isdigit(string[i]))
                {
                    state = ExponentSign;
                    break;
                }
                return false;
            }
        }
    }
}