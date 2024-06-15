#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h> 

int main(int argc, char *argv[]) {

  // Check for valid arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <string> <filepath>\n", argv[0]);
    exit(1);
  }

  // Get the string and filepath arguments
  char *string = argv[2];
  char *filepath = argv[1];

  // Open the file in write mode (overwrite existing content)
  FILE *fp = fopen(filepath, "w");
  if (fp == NULL) {
    syslog(LOG_USER | LOG_ERR, "Error opening file: %s", filepath);
    perror("fopen");
    exit(1);
  }

  // Write the string to the file
  size_t written = fwrite(string, sizeof(char), strlen(string), fp);
  if (written != strlen(string)) {
    syslog(LOG_USER | LOG_ERR, "Error writing to file: %s", filepath);
    perror("fwrite");
    fclose(fp);
    exit(1);
  }

  // Close the file
  fclose(fp);

  // Open syslog for user level messages
  openlog(NULL, LOG_PID, LOG_USER);

  // Log the information to syslog
  syslog(LOG_DEBUG, "Writing '%s' to file: %s", string, filepath);

  // Close syslog
  closelog();

  printf("Successfully wrote string to file and logged information.\n");

  return 0;
}

  
