#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>

/* Size of each input chunk to be
   read and allocate for. */
#ifndef  READALL_CHUNK
#define  READALL_CHUNK  262144
#endif

#define  READALL_OK          0  /* Success */
#define  READALL_INVALID    -1  /* Invalid parameters */
#define  READALL_ERROR      -2  /* Stream error */
#define  READALL_TOOMUCH    -3  /* Too much input */
#define  READALL_NOMEM      -4  /* Out of memory */

/* This function returns one of the READALL_ constants above.
   If the return value is zero == READALL_OK, then:
     (*dataptr) points to a dynamically allocated buffer, with
     (*sizeptr) chars read from the file.
     The buffer is allocated for one extra char, which is NUL,
     and automatically appended after the data.
   Initial values of (*dataptr) and (*sizeptr) are ignored.
*/
int readFile(FILE *in, char **dataptr, size_t *sizeptr);

#ifdef _WIN32
#  define RM_CR // if defined removes the carriage return at the second last position of the second word
#endif

#define MAX_LENGTH 100

typedef struct spair_t
{
   char* first;
   char* second;
}spair_t;

int splitData(char *data, size_t size, const char *first_sep, const char *second_sep, spair_t **pairsptr, size_t *paircntptr);


#endif // FILE_HELPER_H