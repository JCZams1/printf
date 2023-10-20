#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int printHandle(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);


int charPrints(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int stringPrints(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int percentPrints(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int fetch_flags(const char *format, int *a);
int widthFetch(const char *format, int *a, va_list list);
int precisionFetch(const char *format, int *a, va_list list);
int sizeFetch(const char *format, int *a);

int binaryPrints(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int intPrints(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int hexa_upperNum(va_list list, char buffer[],
		int calc, int width, int precSpec, int size);
int num_octal(va_list list, char buffer[],
		int calc, int width, int precSpec, int size);
int num_hexa(va_list list, char buffer[],
		int calc, int width, int precSpec, int size);
int unsignedNum(va_list list, char buffer[],
		int calc, int width, int precSpec, int size);

int pointerFunc(va_list list, char buffer[],
		int calc, int width, int precSpec, int size);

int nonPrintableAscii(va_list list, char buffer[],
		int calc, int width, int precSpec, int size);
int hexaUL(va_list list, char map_to[],
		char buffer[], int calc, char calc_ch, int width, int precSpec, int size);



int rot13String(va_list list, char buffer[],
		int calc, int width, int precSpec, int size);
int str_reverse(va_list list, char buffer[],
		int calc, int width, int precSpec, int size);


int writeNum(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int char_handleWrite(char x, char buffer[],
		int flags, int width, int precision, int size);
int pointWriter(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int numWrite(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);

int writeNum_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);

long int size_num_allocate(long int num, int size);
long int size_allocate_unsgnd(unsigned long int num, int size);
int digit_det(char);
int printableChar(char);
int hexacodeAppend(char, char[], int);

#endif
