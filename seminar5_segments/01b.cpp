#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *str = malloc(10 * sizeof(char));
strcpy(str, "Elephant");
printf("b. String in heap: %s\n", str);
free(str);
}
