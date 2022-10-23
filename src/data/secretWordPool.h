#ifndef _DATA_SECRET_WORD_POOL_H_
#define _DATA_SECRET_WORD_POOL_H_

#include <cmp/TSecret.h>

#define SECRET_WORDS_COUNT 840
#define LETTERS_PER_SECRET_WORD 5
#define SECRET_WORD_POOL_SIZE SECRET_WORDS_COUNT *LETTERS_PER_SECRET_WORD

extern const TSecretWord secretWordPool[SECRET_WORDS_COUNT];

// Address of the latest byte of the array
#define SECRET_WORD_POOL_START (TSecretWord *)(secretWordPool + 0)
#define SECRET_WORD_POOL_END (TSecretWord *)(secretWordPool + SECRET_WORDS_COUNT - 1)

#endif
