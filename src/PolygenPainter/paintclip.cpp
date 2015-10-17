#include "paint.h"
#include <windows.h>
#include <winuser.h>
#include <wingdi.h>
#include <QDebug>
#include <cmath>

bool Paint::drawClipPolygen(HDC &hdc, POINT *p)
{

}

bool Paint::drawClipRectangle(HDC &hdc, POINT *p)
{
    if(isDrawing){
        POINT* q = clipPolygen->begin->itself;

        Node* nodeTwo = new Node();
        Node* nodeThree = new Node();
        Node* nodeFour = new Node();
        POINT* pTwo = new POINT();
        POINT* pFour = new POINT();

        pTwo->x = p->x;
        pTwo->y = q->y;
        pFour->x = q->x;
        pFour->y = p->y;
        nodeFour->itself = pFour;
        nodeFour->next = clipPolygen->begin;
        nodeThree->itself = p;
        nodeThree->next = nodeFour;
        nodeTwo->itself = pTwo;
        nodeTwo->next = nodeThree;
        clipPolygen->begin->next = nodeTwo;

        isDrawing = false;

        HPEN hPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, q->x, q->y, (LPPOINT) NULL);
        LineTo(hdc, q->x, p->y);
        MoveToEx(hdc, q->x, p->y, (LPPOINT) NULL);
        LineTo(hdc, p->x, p->y);
        MoveToEx(hdc, p->x, p->y, (LPPOINT) NULL);
        LineTo(hdc, p->x, q->y);
        MoveToEx(hdc,  p->x, q->y, (LPPOINT) NULL);
        LineTo(hdc, q->x, q->y);
    }
    else{
        isDrawing = true;
        Node* sNode = new Node();
        sNode->itself = p;
        sNode->next = NULL;
        clipPolygen->begin = sNode;
        clipPolygen->next = NULL;
    }
    return !isDrawing;
}

void Paint::clip(HDC& hdc)
{
    if(withInnerCircle)
    {
        Polygen* p = currentInnerPolygen;
        while(p != NULL)
        {
            polygenClip(p, hdc);
            p = p->next;
        }

        fillPolygenWithInnerCircle(hdc);
    }
    else
    {
        Polygen* p = currentPolygen;
        polygenClip(p, hdc);
        fill(hdc, p, backColor);
        drawBoundary(hdc, p);
    }

}

bool inside(POINT* a, int xmin, int xmax, int ymin, int ymax, int i)
{
    bool flag = false;
    switch(i)
    {
    case 0: if(xmin <= a->x)    flag = true;
            break;
    case 1: if(a->x <= xmax)    flag = true;
        break;
    case 2: if(ymin <= a->y)    flag = true;
        break;
    case 3: if(a->y <= ymax)    flag = true;
        break;
    default: break;
    }

    return flag;
}

void getIntersectPoint(POINT* p, POINT* a, POINT* b, int xmin, int xmax, int ymin, int ymax, int i)
{
    LONG k = (b->y - a->y) / (b->x - a->x);
    LONG k2 = (b->x - a->x) / (b->y - a->y);

    switch(i)
    {
    case 0: p->x = xmin;
        p->y = a->y + k * (p->x - a->x);
        break;
    case 1: p->x = xmax;
        p->y = a->y + k * (p->x - a->x);
        break;
    case 2: p->y = ymin;
        p->x = a->x + k2 * (p->y - a->y);
        break;
    case 3: p->y = ymax;
        p->x = a->x + k2 * (p->y - a->y);
        break;
    default: break;
    }
}

void addNode(POINT* p, Polygen* result, Node* lastResultNode)
{
    Node* temp = new Node;
    temp->itself = new POINT;
    temp->itself->x = p->x;
    temp->itself->y = p->y;
    if(lastResultNode == NULL)
    {
        result->begin = temp;
        lastResultNode = temp;
    }
    else
    {
        lastResultNode->next = temp;
        lastResultNode = temp;
    }
}

// Sutherland-Hodgeman算法
void Paint::polygenClip(Polygen *p, HDC &hdc)
{
    Polygen* result = new Polygen;
    Node* lastResultNode = result->begin;

    Node* start = p->begin;
    Node* m = start;
    Node* n = start->next;
    POINT* a;
    POINT* b;
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;
    bool pa, pb;
    findBoundary(ymin, ymax, xmin, xmax, clipPolygen);

    // 对每条裁剪边
    for(int i = 0; i < 4; i++)
    {

        // 对多边形每条边
        while(true)
        {
            a = m->itself;
            b = n->itself;
            pa = inside(a, xmin, xmax, ymin, ymax, i);
            pb = inside(b, xmin, xmax, ymin, ymax, i);

            if(pa && pb){
                Node* temp = new Node;
                temp->itself = new POINT;
                temp->itself->x = b->x;
                temp->itself->y = b->y;
                if(lastResultNode == NULL)
                {
                    result->begin = temp;
                    lastResultNode = temp;
                }
                else
                {
                    lastResultNode->next = temp;
                    lastResultNode = temp;
                }
            }
            else if(!pa && !pb){
                ;
            }
            else if(pa && !pb){
                POINT* interP =new POINT;
                getIntersectPoint(interP, a, b, xmin, xmax, ymin, ymax, i);
                //addNode(interP, result, lastResultNode);
                Node* temp = new Node;
                temp->itself = new POINT;
                temp->itself->x = interP->x;
                temp->itself->y = interP->y;
                if(lastResultNode == NULL)
                {
                    result->begin = temp;
                    lastResultNode = temp;
                }
                else
                {
                    lastResultNode->next = temp;
                    lastResultNode = temp;
                }
                delete interP;
            }
            else if(!pa && pb){
                POINT* interP = new POINT;
                getIntersectPoint(interP, a, b, xmin, xmax, ymin, ymax, i);
                //addNode(interP, result, lastResultNode);
                Node* temp = new Node;
                temp->itself = new POINT;
                temp->itself->x = interP->x;
                temp->itself->y = interP->y;
                if(lastResultNode == NULL)
                {
                    result->begin = temp;
                    lastResultNode = temp;
                }
                else
                {
                    lastResultNode->next = temp;
                    lastResultNode = temp;
                }
                delete interP;
                //addNode(b, result, lastResultNode);
                Node* temp2 = new Node;
                temp2->itself = new POINT;
                temp2->itself->x = b->x;
                temp2->itself->y = b->y;
                if(lastResultNode == NULL)
                {
                    result->begin = temp2;
                    lastResultNode = temp2;
                }
                else
                {
                    lastResultNode->next = temp2;
                    lastResultNode = temp2;
                }
            }

            m = n;
            n = n->next;
            if(m == start)
                break;
        }

        result->dir = p->dir;
        result->next = p->next;
        delete p;
        p = result;

        result = new Polygen;
        lastResultNode = result->begin;
        start = p->begin;
        m = start;
        n = start->next;
    }
}

/*
void Paint::polygenClip(Polygen *p, HDC& hdc)
{
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;
    findBoundary(ymin, ymax, xmin, xmax, p);
    int width = xmax-xmin+1;
    int height = ymax-ymin+1;
    int* map = new int[width*height];
    memset(map, 0, sizeof(int)*width*height);

    convertPolygenToDot(map, xmin, ymin, width, height, p);
    clipDotPolygen(map, xmin, ymin, width, height);
    drawDotPolygen(hdc, map, xmin, ymin, width, height);

    delete []map;
}*/
