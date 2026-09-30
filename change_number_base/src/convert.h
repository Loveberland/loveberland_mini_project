#ifndef CONVERT_H
#define CONVERT_H

int bin_oct(const char *src, char *dest);
int bin_dec(const char *src, char *dest);
int bin_hex(const char *src, char *dest);

int oct_bin(const char *src, char *dest);
int oct_dec(const char *src, char *dest);
int oct_hex(const char *src, char *dest);

int dec_bin(const char *src, char *dest);
int dec_oct(const char *src, char *dest);
int dec_hex(const char *src, char *dest);

int hex_bin(const char *src, char *dest);
int hex_oct(const char *src, char *dest);
int hex_dec(const char *src, char *dest);

#endif