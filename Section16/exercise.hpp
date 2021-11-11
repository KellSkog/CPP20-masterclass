#ifndef SECTION16_EXERCISE
#define SECTION16_EXERCISE

void show_odds(unsigned long long num);
unsigned digit_sum(unsigned num);
bool is_palindrome(unsigned long long num);

void TakesConst(const int &x);
void TakesConst(int &x);

/**
 * Searches str for c
 * returns pos if found, -1 if not found
 */
int contains_character(const char *str, unsigned size, char c);
void find_character(const char *str, unsigned int size, char c);
// int compute(int x = 3, int y = 4, int z); // error: default argument missing for parameter 3 of ‘int compute(int, int, int)’
int compute(int x = 3, int y = 4, int z = 5);
#endif // Include guard