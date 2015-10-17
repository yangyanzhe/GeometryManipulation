#ifndef PAINT
#define PAINT

#include "windows.h"
#include <QDebug>
#include "polygen.h"

enum Mode{
    rectangle,
    eclipse,
    polygen,
    line,
    clip,
    clipPolygen,
    fill
};

class Paint
{
public:
    Paint();
    ~Paint();

public:
    COLORREF    frontColor;
    COLORREF    backColor;
    Polygen*    map;            // 多边形的集合的链表，满足多个多边形
    Polygen*    currentPolygen; // 当前的多边形
    Polygen*    lastPolygen;    // 上一个多边形
    Polygen*    currentInnerPolygen;
    Polygen*    clipPolygen;
    Node*       lastNode;
    Mode        mmode;

    int     range;              // 可以容忍的最后一个点重合误差的范围
    int     lineWidth;          // 默认为2
    bool    isDrawing;          // 判断是否还在继续绘制同一多边形
    bool    withInnerCircle;
    bool    direction;
    bool    clipPolygenDone;
    HDC     gHDC;

public:
    void drawPolygen(HDC& hdc, POINT* p);
    void drawSquare(HDC& hdc, POINT* p);
    void drawPolygenWithInnerCircle(HDC& hdc, POINT* p);
    bool drawClipPolygen(HDC& hdc, POINT* p);
    bool drawClipRectangle(HDC& hdc, POINT* p);
    void resortNodeArray();
    void drawDotPolygen(HDC& hdc, int* map, int xmin, int ymin, int width, int height);

    void fill(HDC& hdc, Polygen* p, COLORREF color);
    void fillPolygenWithInnerCircle(HDC& hdc);
    void moveLeft(HDC& hdc);
    void moveRight(HDC& hdc);
    void rotateLeft(HDC& hdc);
    void rotateRight(HDC& hdc);
    void reflectDown(HDC& hdc);
    void reflectRight(HDC& hdc);
    void drawBoundary(HDC& hdc, Polygen* poly);
    void zoomOut(HDC& hdc);
    void zoomIn(HDC& hdc);
    void clip(HDC& hdc);

private:
    //int  checkCorner(int x, int y, int width, int height, int* map);
    bool isFinished(POINT* p, Polygen* poly);
    void scanFill(int* map, int width, int height, int xmin, int ymin, bool paint, HDC& hdc, COLORREF color);
    void fillLine(int* map, int xmin, int ymin, int width, int x1, int y1, int x2, int y2);
    void findBoundary(int& ymin, int& ymax, int& xmin, int& xmax, Polygen* p);
    void markEdge(int* map, int xmin, int ymin, int width, Polygen* p);
    void markCorner(int* map, int xmin, int ymin, int width, int height, Polygen* p);
    void moveLeft(Polygen* p);
    void moveRight(Polygen* p);
    void polygenRotateLeft(Polygen* p, int x, int y);
    void polygenRotateRight(Polygen* p, int x, int y);
    void polygenReflectDown(Polygen* p, int y);
    void polygenReflectRight(Polygen* p, int x);
    void polygenZoomOut(Polygen* p, int x, int y);
    void polygenZoomIn(Polygen* p, int x, int y);
    void polygenClip(Polygen* p, HDC& hdc);
    void clipDotPolygen(int* map, int xmin, int  ymin, int width, int height);
    void convertPolygenToDot(int* map, int xmin, int ymin, int width, int height, Polygen* p);
};

#endif // PAINT

