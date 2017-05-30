/**
 * @file matrix.c
 * Initiates a matrix-style code cascade in the terminal window
 * @author Justin Schwab (github.com/jgschwab)
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"

/**
 * Starts the program
 * @param argc The number of arguments
 * @param argv The command-line arguments
 * @return The exit code
 */
int main( int argc, char * argv[] ){
  if(argc != 6){
    printf("usage: ./matrix <width> <height> <colorCode> <freq> <speed>\n");
    exit(1);
  }
  
  int cols;
  int rows;
  sscanf(argv[1], "%d", &cols);
  sscanf(argv[2], "%d", &rows);
  cols /= 2;
  
  char bright[] = "\e[92m\e[1m";
  char dim[] = "\e[0m\e[32m";
  
  int c;
  sscanf(argv[3], "%d", &c);
  
  switch(c){
    case 1:
      strcpy(bright, "\e[91m\e[1m");
      strcpy(dim, "\e[0m\e[31m");
      break;
    case 3: 
      strcpy(bright, "\e[93m\e[1m");
      strcpy(dim, "\e[0m\e[33m");
      break;
    case 4: 
      strcpy(bright, "\e[94m\e[1m");
      strcpy(dim, "\e[0m\e[34m");
      break;
    case 5: 
      strcpy(bright, "\e[95m\e[1m");
      strcpy(dim, "\e[0m\e[35m");
      break;
    case 6: 
      strcpy(bright, "\e[96m\e[1m");
      strcpy(dim, "\e[0m\e[36m");
      break;
    case 7: 
      strcpy(bright, "\e[97m\e[1m");
      strcpy(dim, "\e[0m\e[37m");
      break;
    case 9: 
      strcpy(bright, "\e[99m\e[1m");
      strcpy(dim, "\e[0m\e[39m");
      break;
  }
  
  int freq;
  sscanf(argv[4], "%d", &freq);
  
  int speed;
  sscanf(argv[5], "%d", &speed);
  
  char * chars[] = {
    "\u30A2", "\u30A4", "\u30A6", "\u30A8", "\u30AA", "\u30AB", "\u30AD",
    "\u30AF", "\u30B1", "\u30B4", "\u30B5", "\u30B8", "\u30B9", "\u30BB",
    "\u30BD", "\u30BF", "\u30C1", "\u30C6", "\u30C8", "\u30CA", "\u30CC", 
    "\u30CD", "\u30D2", "\u30D5", "\u30D8", "\u30DB", "\u30DE", "\u30E0",
    "\u30E1", "\u30E2", "\u30E4", "\u30E6", "\u30E8", "\u30E9", "\u30EA",
    "\u30EB", "\u30EC", "\u30EF", "\u30F0", "\u30F1", "\u30F2", "\u30F3", 
    "\u30F4", "\u30F5", "\u30F6"};
  int size = sizeof(chars) / sizeof(chars[0]);
  
  srand((unsigned) time(NULL));
  //printf("\e[32m%s\n", chars[rand() % size]);
  printf("\e[32m");
  typedef char **(CharMatrix[rows][cols]);
  typedef int (StyleMatrix[rows][cols]);
  
  //initialize matrix
  CharMatrix cMatrix;
  
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cMatrix[i][j] = &chars[rand() % size];
    }
  }
  
  StyleMatrix sMatrix;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      sMatrix[i][j] = 0;
    }
  }
  //PRINT_MATRIX(cMatrix, sMatrix, rows, cols);
  while(1){
    system("clear");
    PRINT_MATRIX(cMatrix, sMatrix, rows, cols);
    //propagate existing values
    for(int i = rows - 1; i > 0; i--){
      for(int j = 0; j < cols; j++){
        if(sMatrix[i - 1][j] > 0){
          //cMatrix = chars[rand() % size]);
          cMatrix[i][j] = &chars[rand() % size];
        }
        sMatrix[i][j] = sMatrix[i - 1][j];
        if(sMatrix[i - 1][j] > 0)
          sMatrix[i - 1][j] = -1;
      }
    }
    //update top line
    for(int j = 0; j < cols; j++){
      if(rand() % 100 < freq){
        cMatrix[0][j] = &chars[rand() % size];
        sMatrix[0][j] = 1;
      }else if(sMatrix[0][j] < 0){
        if(!(rand() % TARGET_LEN)){
          sMatrix[0][j] = 0;
        }
      }
    }
    sleepFor(speed);
  }
  return EXIT_SUCCESS;
}

void sleepFor(unsigned int offset){
  clock_t new_time = clock() + (CLOCKS_PER_SEC * ((double)offset / MILLIS_IN_SEC));
  while(new_time > clock()){}
}
