/**
 * @file matrix.h
 * Header for matrix.c implementation file
 * @author Justin Schwab (github.com/jgschwab)
 */
 
/** number of milliseconds in a second */
#define MILLIS_IN_SEC 1000
/** The target length of the cascade "tails" */
#define TARGET_LEN 20

#define PRINT_MATRIX(cMatrix, sMatrix, rows, cols) { \
  for(int i = 0; i < rows; i++){ \
    for(int j = 0; j < cols; j++){ \
      if(!sMatrix[i][j]){ \
        printf("  "); \
      }else{ \
        if(sMatrix[i][j] > 0) \
          printf("%s", bright); \
        if(sMatrix[i][j] < 0) \
          printf("%s", dim); \
        printf("%s", *cMatrix[i][j]); \
      } \
    } \
    printf("\n"); \
  } \
}

/**
 * Pauses for a parameterized number of milliseconds 
 * @param offset The time in milliseconds to pause
 */
void sleepFor(unsigned int offset);
