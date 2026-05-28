#include "StringUtils.h"
#include <string.h>
#include <ctype.h>

bool StringUtils::checkValidCharacter(const char name[]) {
    for (int i = 0; i < (int)strlen(name); i++) {
        if (name[i] < 'A' || name[i] > 'Z') {
            if ((name[i] < 'a' || name[i] > 'z'))
                if (name[i] != ' ')
                    return false;
        }
    }
    return true;
}

void StringUtils::toUpper(char name[]) {
    for (int i = 0; i < (int)strlen(name); i++) {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] = toupper(name[i]);
        }
    }
}
