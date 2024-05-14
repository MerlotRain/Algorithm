#ifndef __TINYCOLOR_H__
#define __TINYCOLOR_H__

#include <stdint.h>

#ifndef COLOR_WITH_ALPHA
#    warning "the color data struct will not contain alpha channel"
#endif

#define COLOR_SPACE_RGB   0
#define COLOR_SPACE_CMY   1
#define COLOR_SPACE_CMYK  2
#define COLOR_SPACE_GRAY  3
#define COLOR_SPACE_HSI   4
#define COLOR_SPACE_HSL   5
#define COLOR_SPACE_HSV   6
#define COLOR_SPACE_HWB   7
#define COLOR_SPACE_Lab   8
#define COLOR_SPACE_LabCH 9
#define COLOR_SPACE_LMS   10
#define COLOR_SPACE_Luv   11
#define COLOR_SPACE_LuvCH 12
#define COLOR_SPACE_TSL   13
#define COLOR_SPACE_XYY   14
#define COLOR_SPACE_XYZ   15
#define COLOR_SPACE_YCgCo 16
#define COLOR_SPACE_YDbDr 17
#define COLOR_SPACE_YIQ   18
#define COLOR_SPACE_YPdPr 19
#define COLOR_SPACE_YUV   20

typedef struct _tinyColor {
    uint8_t space;
    uint8_t data[8];
} tinyColor;

#define COLOR_CONVERT_(from, to)                                               \
    extern int color_convert_##from##_##to(tinyColor *color);                  \
    extern int color_convert_##to##_##from(tinyColor *color);

COLOR_CONVERT_(RGB, CMYK)
COLOR_CONVERT_(RGB, GRAY)
COLOR_CONVERT_(RGB, HSI)
COLOR_CONVERT_(RGB, HSL)
COLOR_CONVERT_(RGB, HSV)
COLOR_CONVERT_(RGB, HWB)
COLOR_CONVERT_(RGB, Lab)
COLOR_CONVERT_(RGB, LabCH)
COLOR_CONVERT_(RGB, LMS)
COLOR_CONVERT_(RGB, Luv)
COLOR_CONVERT_(RGB, LuvCH)
COLOR_CONVERT_(RGB, TSL)
COLOR_CONVERT_(RGB, XYY)
COLOR_CONVERT_(RGB, XYZ)
COLOR_CONVERT_(RGB, YCgCo)
COLOR_CONVERT_(RGB, YDbDr)
COLOR_CONVERT_(RGB, YIQ)
COLOR_CONVERT_(RGB, YPdPr)
COLOR_CONVERT_(RGB, YUV)

#define COLOR_CATEGORY_PACK_3I(n1, n2, n3)                                     \
    typedef struct {                                                           \
        uint16_t A;                                                            \
        uint16_t n1;                                                           \
        uint16_t n2;                                                           \
        uint16_t n3;                                                           \
    } color##n1##n2##n3;                                                       \
    extern int        color_component##n1##n2##n3(tinyColor         *color,    \
                                                  color##n1##n2##n3 *data);    \
    extern tinyColor *color_createFrom##n1##n2##n3(                            \
        const color##n1##n2##n3 data);

#define COLOR_CATEGORY_PACK_3F(n1, n2, n3)                                        \
    typedef struct {                                                              \
        float A;                                                                  \
        float n1;                                                                 \
        float n2;                                                                 \
        float n3;                                                                 \
    } color##n1##n2##n3##F;                                                       \
    extern int        color_component##n1##n2##n3##F(tinyColor            *color, \
                                                     color##n1##n2##n3##F *data); \
    extern tinyColor *color_createFrom##n1##n2##n3##F(                            \
        const color##n1##n2##n3##F data);

#define COLOR_CATEGORY_PACK_3(n1, n2, n3)                                      \
    COLOR_CATEGORY_PACK_3I(n1, n2, n3)                                         \
    COLOR_CATEGORY_PACK_3F(n1, n2, n3)

#define COLOR_CATEGORY_PACK_4I(n1, n2, n3, n4)                                      \
    typedef struct {                                                                \
        uint16_t A;                                                                 \
        uint16_t n1;                                                                \
        uint16_t n2;                                                                \
        uint16_t n3;                                                                \
        uint16_t n4;                                                                \
    } color##n1##n2##n3##n4;                                                        \
    extern int        color_component##n1##n2##n3##n4(tinyColor             *color, \
                                                      color##n1##n2##n3##n4 *data); \
    extern tinyColor *color_createFrom##n1##n2##n3##n4(                             \
        const color##n1##n2##n3##n4 data);

#define COLOR_CATEGORY_PACK_4F(n1, n2, n3, n4)                                 \
    typedef struct {                                                           \
        float A;                                                               \
        float n1;                                                              \
        float n2;                                                              \
        float n3;                                                              \
        float n4;                                                              \
    } color##n1##n2##n3##n4##F;                                                \
    extern int color_component##n1##n2##n3##n4##F(                             \
        tinyColor *color, color##n1##n2##n3##n4##F *data);                     \
    extern tinyColor *color_createFrom##n1##n2##n3##n4##F(                     \
        const color##n1##n2##n3##n4##F data);

#define COLOR_CATEGORY_PACK_4(n1, n2, n3, n4)                                  \
    COLOR_CATEGORY_PACK_4I(n1, n2, n3, n4)                                     \
    COLOR_CATEGORY_PACK_4F(n1, n2, n3, n4)

#define GEN_COLOR_STRUCT                                                       \
    COLOR_CATEGORY_PACK_3(R, G, B)                                             \
    COLOR_CATEGORY_PACK_3(H, S, L)                                             \
    COLOR_CATEGORY_PACK_4F(C, M, Y, K)

GEN_COLOR_STRUCT

extern tinyColor AliceBlue();
extern tinyColor AntiqueWhite();
extern tinyColor Aqua();
extern tinyColor Aquamarine();
extern tinyColor Azure();
extern tinyColor Beige();
extern tinyColor Bisque();
extern tinyColor Black();
extern tinyColor BlanchedAlmond();
extern tinyColor Blue();
extern tinyColor BlueViolet();
extern tinyColor Brown();
extern tinyColor BurlyWood();
extern tinyColor CadetBlue();
extern tinyColor Chartreuse();
extern tinyColor Chocolate();
extern tinyColor Coral();
extern tinyColor CornflowerBlue();
extern tinyColor Cornsilk();
extern tinyColor Crimson();
extern tinyColor Cyan();
extern tinyColor DarkBlue();
extern tinyColor DarkCyan();
extern tinyColor DarkGoldenrod();
extern tinyColor DarkGray();
extern tinyColor DarkGreen();
extern tinyColor DarkKhaki();
extern tinyColor DarkMagenta();
extern tinyColor DarkOliveGreen();
extern tinyColor DarkOrange();
extern tinyColor DarkOrchid();
extern tinyColor DarkRed();
extern tinyColor DarkSalmon();
extern tinyColor DarkSeaGreen();
extern tinyColor DarkSlateBlue();
extern tinyColor DarkSlateGray();
extern tinyColor DarkTurquoise();
extern tinyColor DarkViolet();
extern tinyColor DeepPink();
extern tinyColor DeepSkyBlue();
extern tinyColor DimGray();
extern tinyColor DodgerBlue();
extern tinyColor Feldspar();
extern tinyColor Firebrick();
extern tinyColor FloralWhite();
extern tinyColor ForestGreen();
extern tinyColor Fuchsia();
extern tinyColor Gainsboro();
extern tinyColor GhostWhite();
extern tinyColor Gold();
extern tinyColor Goldenrod();
extern tinyColor Gray();
extern tinyColor Green();
extern tinyColor GreenYellow();
extern tinyColor Honeydew();
extern tinyColor HotPink();
extern tinyColor IndianRed();
extern tinyColor Indigo();
extern tinyColor Ivory();
extern tinyColor Khaki();
extern tinyColor Lavender();
extern tinyColor LavenderBlush();
extern tinyColor LawnGreen();
extern tinyColor LemonChiffon();
extern tinyColor LightBlue();
extern tinyColor LightCoral();
extern tinyColor LightCyan();
extern tinyColor LightGoldenrodYellow();
extern tinyColor LightGray();
extern tinyColor LightGrey();
extern tinyColor LightGreen();
extern tinyColor LightPink();
extern tinyColor LightSalmon();
extern tinyColor LightSeaGreen();
extern tinyColor LightSkyBlue();
extern tinyColor LightSlateBlue();
extern tinyColor LightSlateGray();
extern tinyColor LightSteelBlue();
extern tinyColor LightYellow();
extern tinyColor Lime();
extern tinyColor LimeGreen();
extern tinyColor Linen();
extern tinyColor Magenta();
extern tinyColor Maroon();
extern tinyColor MediumAquamarine();
extern tinyColor MediumBlue();
extern tinyColor MediumOrchid();
extern tinyColor MediumPurple();
extern tinyColor MediumSeaGreen();
extern tinyColor MediumSlateBlue();
extern tinyColor MediumSpringGreen();
extern tinyColor MediumTurquoise();
extern tinyColor MediumVioletRed();
extern tinyColor MidnightBlue();
extern tinyColor MintCream();
extern tinyColor MistyRose();
extern tinyColor Moccasin();
extern tinyColor NavajoWhite();
extern tinyColor Navy();
extern tinyColor OldLace();
extern tinyColor Olive();
extern tinyColor OliveDrab();
extern tinyColor Orange();
extern tinyColor OrangeRed();
extern tinyColor Orchid();
extern tinyColor PaleGoldenrod();
extern tinyColor PaleGreen();
extern tinyColor PaleTurquoise();
extern tinyColor PaleVioletRed();
extern tinyColor PapayaWhip();
extern tinyColor PeachPuff();
extern tinyColor Peru();
extern tinyColor Pink();
extern tinyColor Plum();
extern tinyColor PowderBlue();
extern tinyColor Purple();
extern tinyColor Red();
extern tinyColor RosyBrown();
extern tinyColor RoyalBlue();
extern tinyColor SaddleBrown();
extern tinyColor Salmon();
extern tinyColor SandyBrown();
extern tinyColor SeaGreen();
extern tinyColor SeaShell();
extern tinyColor Sienna();
extern tinyColor Silver();
extern tinyColor SkyBlue();
extern tinyColor SlateBlue();
extern tinyColor SlateGray();
extern tinyColor Snow();
extern tinyColor SpringGreen();
extern tinyColor SteelBlue();
extern tinyColor Tan();
extern tinyColor Teal();
extern tinyColor Thistle();
extern tinyColor Tomato();
extern tinyColor Transparent();
extern tinyColor Turquoise();
extern tinyColor Violet();
extern tinyColor VioletRed();
extern tinyColor Wheat();
extern tinyColor White();
extern tinyColor WhiteSmoke();
extern tinyColor Yellow();
extern tinyColor YellowGreen();

#endif //__TINYCOLOR_H__