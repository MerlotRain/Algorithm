#ifndef LIB_COLOR_H
#define LIB_COLOR_H

#include <stdint.h>

typedef enum { Rgb, Hsv, Cmyk, Hsl } ColorSpec;

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
    ColorSpec spec;
    union {
        RGB  rgb;
        HSV  hsv;
        CMYK cmyk;
        HSL  hsl;
    } tio;
} Color;

Color fromRgb(int r, int g, int b);
Color fromRgbF(float r, float g, float b);

Color fromHsv(int h, int s, int v);
Color fromHsvF(float h, float s, float v);

Color fromCmyk(int c, int m, int y, int k);
Color fromCmykF(float c, float m, float y, float k);

Color fromHsl(int h, int s, int l);
Color fromHslF(float h, float s, float l);

Color fromLab(int l, int a, int b);
Color fromLabF(float l, float a, float b);

int   red(const Color &color);
int   green(const Color &color);
int   blue(const Color &color);
float redF(const Color &color);
float greenF(const Color &color);
float blueF(const Color &color);

int hue(const Color &color); // 0 <= hue < 360
int saturation(const Color &color);
int hsvHue(const Color &color); // 0 <= hue < 360
int hsvSaturation(const Color &color);
int value(const Color &color);

float hueF(const Color &color); // 0.0 <= hueF < 360.0
float saturationF(const Color &color);
float hsvHueF(const Color &color); // 0.0 <= hueF < 360.0
float hsvSaturationF(const Color &color);
float valueF(const Color &color);

int cyan(const Color &color);
int magenta(const Color &color);
int yellow(const Color &color);
int black(const Color &color);

float cyanF(const Color &color);
float magentaF(const Color &color);
float yellowF(const Color &color);
float blackF(const Color &color);

int hslHue(const Color &color); // 0 <= hue < 360
int hslSaturation(const Color &color);
int lightness(const Color &color);

float hslHueF(const Color &color); // 0.0 <= hueF < 360.0
float hslSaturationF(const Color &color);
float lightnessF(const Color &color);

Color toRgb(const Color &color);
Color toHsv(const Color &color);
Color toCmyk(const Color &color);
Color toHsl(const Color &color);

#endif // LIB_COLOR_H