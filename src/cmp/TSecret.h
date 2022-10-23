#ifndef _CMP_TSECRET_H_
#define _CMP_TSECRET_H_

#include <enums.h>

typedef char TSecretWord[LETTERS_PER_WORD];

typedef struct TSecret {
    u16 index;
    TSecretWord word;
};

#endif
