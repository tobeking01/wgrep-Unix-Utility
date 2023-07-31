#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

     // Check for valid input
  if (argc < 2) {
    printf("Usage: wgrep searchterm in file...\n");
    return 1;
  }

  // Get the search term
  char *search_term = argv[1];

  // Iterate over each file
  for (int i = 2; i < argc; i++) {
    // Open the file
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wgrep: cannot open file %s\n", argv[i]);
      return 1;
    }

    // Read the file and print the lines that match the search term
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
      if (strstr(line, search_term) != NULL) {
        printf("%s", line);
      }
    }

    // Close the file
    fclose(fp);
  }

  // If no file is specified, read from standard input
  if (argc == 2) {
    // Read the lines from standard input and print the lines that match the search term
    char line[1024];
    while (fgets(line, sizeof(line), stdin) != NULL) {
      if (strstr(line, search_term) != NULL) {
        printf("%s", line);
      }
    }
  }

  return 0;
}
