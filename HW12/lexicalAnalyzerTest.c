#include "lexicalAnalyzerTest.h"

bool tests()
{
    return !isNumber("345E+2.3") && isNumber("24.5E+1")
        && !isNumber("35.2+2");
}