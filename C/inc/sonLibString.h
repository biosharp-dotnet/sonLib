/*
 * Copyright (C) 2006-2011 by Benedict Paten (benedictpaten@gmail.com)
 *
 * Released under the MIT license, see LICENSE.txt
 */

/*
 * SonLibString.h
 *
 *  Created on: 24-May-2010
 *      Author: benedictpaten
 */

#ifndef SONLIB_STRING_H_
#define SONLIB_STRING_H_

#include "sonLibTypes.h"
#include <string.h>
#include <strings.h>

/*
 * Copies a string, if string is NULL, NULL is returned
 */
char *stString_copy(const char *string);

/*
 * Like printf, but into a new string.
 */
char *stString_print(const char *string, ...);

/*
 * Compare two strings for equality.  NULL is considered a valid value and
 * both strings being NULL returns true.
 */
inline static bool stString_eq(const char *string1, const char *string2) {
    if ((string1 == NULL) && (string2 == NULL)) {
        return true;
    } else if ((string1 == NULL) || (string2 == NULL)) {
        return false;
    } else {
        return strcmp(string1, string2) == 0;
    }
}

/*
 * Compare two strings for equality, ignoring case.  NULL is considered a valid value and
 * both strings being NULL returns true.
 */
inline static bool stString_eqcase(const char *string1, const char *string2) {
    if ((string1 == NULL) && (string2 == NULL)) {
        return true;
    } else if ((string1 == NULL) || (string2 == NULL)) {
        return false;
    } else {
        return strcasecmp(string1, string2) == 0;
    }
}

/*
 * Parses the next word from a string, updates the string pointer and returns
 * the parsed string. Delimiters are all white space characters.
 */
char *stString_getNextWord(char **string);

/*
 * Creates a new version of original string with all instances of toReplace replaced with the
 * replacement string.
 */
char *stString_replace(const char *originalString, const char *toReplace, const char *replacement);

/*
 * Joins a group of strings together into one long string, efficiently. 'strings' is the
 * array to join, length is the length of strings and pad is the padding to place
 * between each join.
 */
char *stString_join(const char *pad, const char **strings, int32_t length);

/*
 * Splits a string using stString_getNextWord into a bunch of tokens and returns them as a list.
 */
stList *stString_split(const char *string);

#endif /* SONLIBSTRING_H_ */
