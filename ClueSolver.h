#ifndef CLUESOLVER_H
#define CLUESOLVER_H

#include <QString>

/*! Minimum required number of players in a game */
#define MIN_NUMBER_OF_PLAYERS 3

/*! Maximum allowed number of players in a game */
#define MAX_NUMBER_OF_PLAYERS 6

/*!
 * \brief Convert an integer number into a QString
 * \param number the integer number to be converted
 * \return The equivalent QString
 *
 * The given integer number is firstly converted to a std::string, and then the resulting
 * std::string is converted to a QString
 */
QString intToQString(int number);

#endif // CLUESOLVER_H
