#if !defined(FUNCTIONS)
#define FUNCTIONS

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size);

void dump(char a[], unsigned int length);

void sort(char letters[], char sorted[], unsigned int indexes[], unsigned int length);

#endif // FUNCTIONS
