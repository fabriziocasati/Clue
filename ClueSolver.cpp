#include "ClueSolver.h"

#include <boost/lexical_cast.hpp>

QString intToQString(int number)
{
    std::string numberString = boost::lexical_cast<std::string>(number);
    return QString::fromStdString(numberString);
}
