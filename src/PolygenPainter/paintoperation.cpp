#include "paint.h"
#include <windows.h>
#include <winuser.h>
#include <wingdi.h>
#include <QDebug>
#include <cmath>

void Paint::polygenZoomIn(Polygen* p, int x, int y)
{
    Node* start = p->begin;
    Node* n = start;
    POINT* point;

    while(true)
    {
        point = n->itself;
        LONG xt = point->x - x;
        LONG yt = point->y - y;

        point->x = xt*0.8 + x;
        point->y = yt*0.8 + y;
        n = n->next;
        if(n == start)  break;
    }
}

void Paint::polygenZoomOut(Polygen *p, int x, int y)
{
    Node* start = p->begin;
    Node* n = start;
    POINT* point;

    while(true)
    {
        point = n->itself;
        LONG xt = point->x - x;
        LONG yt = point->y - y;

        point->x = xt*1.25 + x;
        point->y = yt*1.25 + y;
        n = n->next;
        if(n == start)  break;
    }
}

void Paint::moveLeft(Polygen* p)
{
    Node* start = p->begin;
    Node* n = start;
    POINT* point;

    while(true)
    {
        point = n->itself;
        point->x -= 3;
        n = n->next;
        if(n == start)  break;
    }
}

void Paint::moveRight(Polygen* p)
{
    Node* start = p->begin;
    Node* n = start;
    POINT* point;

    while(true)
    {
        point = n->itself;
        point->x += 3;
        n = n->next;
        if(n == start)  break;
    }
}

void Paint::polygenRotateLeft(Polygen* p, int x, int y)
{
    Node* start = p->begin;
    Node* n = start;
    POINT* point;

    while(true)
    {
        point = n->itself;
        LONG xt = point->x - x;
        LONG yt = point->y - y;

        point->x = yt + x;
        point->y = -xt + y;
        n = n->next;
        if(n == start)  break;
    }
}

void Paint::polygenRotateRight(Polygen* p, int x, int y)
{
    Node* start = p->begin;
    Node* n = start;
    POINT* point;

    while(true)
    {
        point = n->itself;
        LONG xt = point->x - x;
        LONG yt = point->y - y;

        point->x = -yt + x;
        point->y = xt + y;
        n = n->next;
        if(n == start)  break;
    }
}

void Paint::polygenReflectDown(Polygen* p, int y)
{
    Node* start = p->begin;
    Node* n = start;
    POINT* point;

    while(true)
    {
        point = n->itself;
        LONG yt = point->y - y;
        point->y = -yt + y;
        n = n->next;
        if(n == start)  break;
    }
}

void Paint::polygenReflectRight(Polygen* p, int x)
{
    Node* start = p->begin;
    Node* n = start;
    POINT* point;

    while(true)
    {
        point = n->itself;
        LONG xt = point->x - x;
        point->x = -xt + x;
        n = n->next;
        if(n == start)  break;
    }
}

void Paint::moveLeft(HDC& hdc)
{
    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        while(p != NULL)
        {
            moveLeft(p);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        moveLeft(p);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }
}

void Paint::moveRight(HDC& hdc)
{
    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        while(p != NULL)
        {
            moveRight(p);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        moveRight(p);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }
}

void Paint::rotateLeft(HDC& hdc)
{
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;

    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        while(p != NULL)
        {
            polygenRotateLeft(p, (xmin+xmax)/2, (ymax+ymin)/2);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        polygenRotateLeft(p, (xmin+xmax)/2, (ymax+ymin)/2);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }
}

void Paint::rotateRight(HDC& hdc)
{
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;

    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        while(p != NULL)
        {
            polygenRotateRight(p, (xmin+xmax)/2, (ymax+ymin)/2);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        polygenRotateRight(p, (xmin+xmax)/2, (ymax+ymin)/2);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }
}

void Paint::reflectDown(HDC& hdc)
{
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;

    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        while(p != NULL)
        {
            polygenReflectDown(p, (ymax+ymin)/2);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        polygenReflectDown(p, (ymax+ymin)/2);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }
}

void Paint::reflectRight(HDC& hdc)
{
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;

    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        while(p != NULL)
        {
            polygenReflectRight(p, (xmin+xmax)/2);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        polygenReflectRight(p, (xmin+xmax)/2);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }
}

void Paint::zoomIn(HDC &hdc)
{
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;

    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        while(p != NULL)
        {
            polygenZoomIn(p, (xmin+xmax)/2, (ymin+ymax)/2);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        polygenZoomIn(p, (xmin+xmax)/2, (ymin+ymax)/2);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }
}

void Paint::zoomOut(HDC &hdc)
{
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;

    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        while(p != NULL)
        {
            polygenZoomOut(p, (xmin+xmax)/2, (ymin+ymax)/2);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        findBoundary(ymin, ymax, xmin, xmax, p);
        polygenZoomOut(p, (xmin+xmax)/2, (ymin+ymax)/2);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }
}
