// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <iostream>

unsigned int faStr1(const char *str) {
    if (str == nullptr) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    while (*str) {
        if (isspace(*str)) {
            if (inWord && !hasDigit) {
                count++;
            }
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (isdigit(*str)) {
                hasDigit = true;
            }
        }
        str++;
    }
    if (inWord && !hasDigit) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    if (str == nullptr) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool validWord = true;
    int charIndex = 0;
    while (*str) {
        if (isspace(*str)) {
            if (inWord && validWord) {
                count++;
            }
            inWord = false;
            validWord = true;
            charIndex = 0;
        } else {
            if (!inWord) {
                inWord = true;
                validWord = true;
                charIndex = 0;
            }
            if (validWord) {
                if (charIndex == 0) {
                    if (!(*str >= 'A' && *str <= 'Z')) {
                        validWord = false;
                    }
                } else {
                    if (!(*str >= 'a' && *str <= 'z')) {
                        validWord = false;
                    }
                }
            }
            charIndex++;
        }
        str++;
    }
    if (inWord && validWord) {
        count++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    if (str == nullptr) return 0;
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    unsigned int currentLength = 0;
    bool inWord = false;
    while (*str) {
        if (isspace(*str)) {
            if (inWord) {
                totalLength += currentLength;
                wordCount++;
                currentLength = 0;
                inWord = false;
            }
        } else {
            if (!inWord) {
                inWord = true;
                currentLength = 0;
            }
            currentLength++;
        }
        str++;
    }
    if (inWord) {
        totalLength += currentLength;
        wordCount++;
    }
    if (wordCount == 0) return 0;
    double average = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(round(average));
}
