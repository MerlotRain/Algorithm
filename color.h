#ifndef LIB_COLOR_H
#define LIB_COLOR_H

#include <stdint.h>

typedef enum { Rgb, Hsv, Cmyk, Hsl, Lab } ColorSpec;

typedef struct {
    uint16_t alpha;
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint16_t pad;
} RGB;

typedef struct HSV {
    uint16_t alpha;
    uint16_t hue;
    uint16_t saturation;
    uint16_t value;
    uint16_t pad;
} HSV;

typedef struct {
    uint16_t alpha;
    uint16_t cyan;
    uint16_t magenta;
    uint16_t yellow;
    uint16_t black;
} CMYK;

typedef struct {
    uint16_t alpha;
    uint16_t hue;
    uint16_t saturation;
    uint16_t lightness;
    uint16_t pad;
} HSL;

typedef struct {
    uint16_t alpha;
    int16_t  luminosity;
    int16_t  a;
    int16_t  b;
    uint16_t pad;
} LAB;

typedef struct {
    ColorSpec spec;
    union {
        RGB  rgb;
        HSV  hsv;
        CMYK cmyk;
        HSL  hsl;
        LAB  lab;
    } tio;
} Color;



#endif // LIB_COLOR_H