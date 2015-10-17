#include "paint.h"
#include <windows.h>
#include <winuser.h>
#include <wingdi.h>
#include <QDebug>
#include <cmath>
#include <stack>

Paint::Paint()
{
    frontColor = RGB(255, 127, 39);
    backColor = RGB(255, 255, 255);
    lineWidth = 2;
    range = 6;
    isDrawing = false;
    direction = true;
    withInnerCircle = false;

    map = NULL;
    currentPolygen = NULL;
    lastPolygen = NULL;
    lastNode = NULL;
    mmode = rectangle;

    clipPolygen = new Polygen;
    clipPolygenDone = false;
}

Paint::~Paint()
{
    Polygen* p = map;
    Polygen* q;
    while(p!= NULL){
        q = p->next;
        delete p;
        p = q;
    }

    //delete clipPolygen;
}

void Paint::drawBoundary(HDC &hdc, Polygen* poly)
{
    if(poly == NULL)    return;

    HPEN hPen = CreatePen(PS_SOLID, lineWidth, frontColor);
    SelectObject(hdc, hPen);

    Node* s = poly->begin;
    Node* q = s;
    Node* p = s->next;
    while(true){
        POINT* m = q->itself;
        POINT* n = p->itself;
        MoveToEx(hdc, m->x, m->y, (LPPOINT) NULL);
        LineTo(hdc, n->x, n->y);
        q = p;
        p = p->next;
        if(q == s)  break;
    }
}

void Paint::drawPolygen(HDC& hdc, POINT* p)
{
    gHDC = hdc;
    if(isDrawing){
        POINT* q = lastNode->itself;
        if(isFinished(p, currentPolygen)){      // drawing polygen ends
            delete p;
            p = currentPolygen->begin->itself;
            lastNode->next = currentPolygen->begin;
            isDrawing = false;
            //resortNodeArray();
            if(!withInnerCircle){
                fill(hdc, currentPolygen, backColor);
                drawBoundary(hdc, currentPolygen);
            }
        }
        else{  // continue drawing
            Node* mNode = new Node();
            mNode->itself = p;
            mNode->next = NULL;
            lastNode->next = mNode;
            lastNode = mNode;
        }

        MoveToEx(hdc, q->x, q->y, (LPPOINT) NULL);
        LineTo(hdc, p->x, p->y);
	}
	else{
        isDrawing = true;
        Polygen* sPoly = new Polygen();
        Node* sNode = new Node();
        sNode->itself = p;
        sNode->next = NULL;
        sPoly->begin = sNode;
        sPoly->next = NULL;
        sPoly->dir = direction;
        //qDebug() << direction << " " << withInnerCircle;
        if(direction && withInnerCircle){
            currentInnerPolygen = sPoly;
            direction = false;
        }

        currentPolygen = sPoly;
        lastNode = sNode;
        if(!map){       // polygen set is null
            map = currentPolygen;
            lastPolygen = currentPolygen;
        }
        else{
            lastPolygen->next = currentPolygen;
            lastPolygen = currentPolygen;
            //qDebug() << "connect to the next one";
        }
	}
}


void Paint::drawSquare(HDC& hdc, POINT* p)
{
    gHDC = hdc;
    if(isDrawing){
        POINT* q = lastNode->itself;

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
        nodeFour->next = lastNode;
        nodeThree->itself = p;
        nodeThree->next = nodeFour;
        nodeTwo->itself = pTwo;
        nodeTwo->next = nodeThree;
        lastNode->next = nodeTwo;

        isDrawing = false;
        if(!withInnerCircle)
            fill(hdc, currentPolygen, backColor);
        //qDebug() << "finish the fill operation.";

        HPEN hPen = CreatePen(PS_SOLID, lineWidth, frontColor);
        SelectObject(hdc, hPen);
        MoveToEx(hdc, q->x, q->y, (LPPOINT) NULL);
        LineTo(hdc, q->x, p->y);
        MoveToEx(hdc, q->x, p->y, (LPPOINT) NULL);
        LineTo(hdc, p->x, p->y);
        MoveToEx(hdc, p->x, p->y, (LPPOINT) NULL);
        LineTo(hdc, p->x, q->y);
        MoveToEx(hdc,  p->x, q->y, (LPPOINT) NULL);
        LineTo(hdc, q->x, q->y);

        //resortNodeArray();  // resort the node according to the direction
    }
    else{
        isDrawing = true;
        Polygen* sPoly = new Polygen();
        Node* sNode = new Node();
        sNode->itself = p;
        sNode->next = NULL;
        sPoly->begin = sNode;
        sPoly->next = NULL;
        sPoly->dir = direction;
        if(direction && withInnerCircle){
            currentInnerPolygen = sPoly;
            direction = false;
        }

        currentPolygen = sPoly;
        lastNode = sNode;
        if(!map){       // polygen set is null
            map = currentPolygen;
            lastPolygen = currentPolygen;
        }
        else{
            lastPolygen->next = currentPolygen;
            lastPolygen = currentPolygen;
        }
    }
}

void Paint::drawPolygenWithInnerCircle(HDC &hdc, POINT *p)
{
    if(mmode == polygen){
        drawPolygen(hdc, p);
    }
    else if(mmode == rectangle){
        drawSquare(hdc, p);
    }
}

//void Paint::drawEclipse(HDC &hdc, POINT *p)

bool Paint::isFinished(POINT* p, Polygen* poly)
{
    // compare p with the start point
    POINT* s = poly->begin->itself;
    int x = s->x - p->x;
    int y = s->y - p->y;
    if(-range <= x && x <= range && -range <= y && y <= range ){
        p->x = s->x;
        p->y = s->y;
        return true;
    }
    else{
        return false;
    }
}

// resort the node according to the direction
void Paint::resortNodeArray()
{
    
}

// fill the polygen with backcolor
void Paint::fill(HDC &hdc, Polygen* p, COLORREF color)
{
    int ymin = 0;
    int ymax = 0;
    int xmin = 0;
    int xmax = 0;
    findBoundary(ymin, ymax, xmin, xmax, p);
    //qDebug() << xmin << " " << xmax << " " << ymin << " " << ymax;

    int size = (xmax - xmin + 1) * (ymax - ymin + 1);
    //qDebug() << "size " << size;
    int* map = new int [size];
    memset(map, 0, size * sizeof(int));   // 0-out; 2-edge; 1-inner
    markEdge(map, xmin, ymin, xmax-xmin+1, p);
    markCorner(map, xmin, ymin, xmax-xmin+1, ymax-ymin+1, p);
    //markEdge(hdc, map, xmin, ymin, xmax-xmin+1, p);

    HPEN hPen = CreatePen(PS_SOLID, lineWidth, color);
    SelectObject(hdc, hPen);
    scanFill(map, xmax-xmin+1, ymax-ymin+1, xmin, ymin, true, hdc, color);

    if(map != NULL){
        delete []map;
        map = NULL;
    }
}

void Paint::scanFill(int* map, int width, int height, int xmin, int ymin, bool paint, HDC &hdc, COLORREF color)
{
    //qDebug() << map[width*height-1];
    //qDebug() << "width " << width << " height " << height;
    POINT* m = new POINT;
    POINT* n = new POINT;

    for(int j = 0; j<height; j++)
    {
        bool inner = false;
        for(int i = 0; i<width; i++)
        {
            int index = j*width+i;
            if(map[index] == 0)  continue;

            if(!inner){
                if(map[index] == 2) continue;

                m->x = i+xmin;
                m->y = j+ymin;
                inner = true;
            }
            else {
                n->x = i+xmin;
                n->y = j+ymin;

                // considering the width to be over 1 pixel
                if(n->x == m->x + 1){
                    m->x = n->x;
                    continue;
                }
                else{
                    if(paint){
                        MoveToEx(hdc,  m->x, m->y, (LPPOINT) NULL);
                        LineTo(hdc, n->x, n->y);
                    }
                    fillLine(map, xmin, ymin, width, m->x, m->y, n->x, n->y);
                    inner = false;
                    if(map[index] == 2){
                        m->x = n->x;
                        inner = true;
                        continue;
                    }


                    i++;
                    while(i<width && map[j*width+i]){
                        i++;
                    }
                    i--;

                }
            }
        }
    }

    delete m;
    delete n;
}

void Paint::findBoundary(int& ymin, int& ymax, int& xmin, int& xmax, Polygen* p)
{
    if(p == NULL)   return;

    Node*   start = p->begin;
    Node*   n = start->next;

    POINT*  point = start->itself;
    ymin = point->y;
    ymax = ymin;
    xmin = point->x;
    xmax = xmin;

    while(n != start){

        point = n->itself;
        if(point->y < ymin){
            ymin = point->y;
        }
        else if(point->y > ymax){
            ymax = point->y;
        }

        if(point->x < xmin){
            xmin = point->x;
        }
        else if(point->x > xmax){
            xmax = point->x;
        }

        n = n->next;
    }
}

void Paint::markEdge(int* map, int xmin, int ymin, int width, Polygen* p)
//void Paint::markEdge(HDC& hdc, bool* map, int xmin, int ymin, int width, Polygen* p)
{
    //HPEN hPen = CreatePen(PS_SOLID, lineWidth, RGB(0,0,0));
    //SelectObject(hdc, hPen);

    if(p == NULL)   return;

    Node* start = p->begin;
    Node* n = start;
    POINT* m1;
    POINT* m2;

    while(true)
    {
        m1 = n->itself;
        m2 = n->next->itself;
        int x, y, dx, dy, e;
        int x0 = m1->x - xmin;
        int y0 = m1->y - ymin;
        int x1 = m2->x - xmin;
        int y1 = m2->y - ymin;
        x = x0;
        y = y0;

        dx = abs(x1 - x0);
        dy = abs(y1 - y0);

        int addX = (x1 - x0) > 0 ? 1 : -1;
        int addY = (y1 - y0) > 0 ? 1 : -1;

        if(dx >= dy){
            e = -dx;
            for(int i = 0; i<=dx; i++)
            {
                map[x + y * width] = 1;
                //MoveToEx(hdc, x, y, (LPPOINT) NULL);
                //LineTo(hdc, x+1, y);

                x+=addX;
                e = e + 2 * dy;
                if(e >= 0)
                {
                    y+=addY;
                    e = e - 2 * dx;
                }
            }
        }
        else{
            e = -dy;
            for(int i = 0; i<=dy; i++)
            {
                map[x + y * width] = 1;
                //MoveToEx(hdc, x, y, (LPPOINT) NULL);
                //LineTo(hdc, x+1, y);
                y+=addY;
                e = e + 2 * dx;
                if(e >= 0)
                {
                    x+=addX;
                    e = e - 2 * dy;
                }
            }
        }

        n = n->next;
        if(n == start)  break;
    }
}

void Paint::markCorner(int* map, int xmin, int ymin, int width, int height, Polygen* p)
{
    if(p == NULL)   return;

    Node* start = p->begin;
    Node* last = start;
    Node* current = start->next;
    POINT* q;
    int x, y, xl, xr, yb, yt;

    while(true)
    {
        q = current->itself;
        x = q->x - xmin;
        y = q->y - ymin;
        int y1 = last->itself->y - ymin;
        int y2 = current->next->itself->y - ymin;

        xl = x;
        xr = x;
        yb = y;
        yt = y;
        if(xl > 0)  xl = xl-1;
        if(xr < width-1)    xr = xr+1;
        if(yb > 0)  yb = yb-1;
        if(yt < height-1)   yt = yt+1;
        int xlt = xl;
        int xrt = xr;

        if((y1 > y && y2 > y) || (y1 < y && y2 < y)){
            map[x+y*width] = 2;
            //qDebug() << "corner" << x+xmin << " " << y+ymin;


            while(map[xlt+y*width] == 1){
                //qDebug() << "corner" << xlt+xmin << " " << y+ymin;
                map[xlt+y*width] = 2;
                xlt--;
                if(xlt < 0) break;
            }
            while(map[xrt+y*width] == 1){
                map[xrt+y*width] = 2;
                //qDebug() << "corner" << xrt+xmin << " " << y+ymin;
                xrt++;
                if(xrt > width-1) break;
            }

            int addY = y1 > y ? 1 : -1;
            int y0 = y+addY;
            while(map[x+y0*width] == 1){
                xlt = xl;
                xrt = xr;
                map[x+y0*width] = 2;
                bool flag = false;
                //if(map[xl+y0*width] == 1){
                while(map[xlt+y0*width] == 1){
                    flag = true;
                    map[xlt+y0*width] = 2;
                    //qDebug() << "corner" << xlt+xmin << " " << y0+ymin;
                    xlt--;
                    if(xlt < 0) break;
                }
                while(map[xrt+y0*width] == 1){
                    flag = true;
                    map[xrt+y0*width] = 2;
                    //qDebug() << "corner" << xrt+xmin << " " << y0+ymin;
                    xrt++;
                    if(xrt > width-1) break;
                }

                if(!flag){
                    y = y0 + addY;
                    if(y < 0 || y > height-1){
                        break;
                    }
                }
                else    break;
            }
        }

        last = current;
        current = current->next;
        if(last == start)   break;
    }
}

void Paint::fillPolygenWithInnerCircle(HDC &hdc)
{
    Polygen *p = currentInnerPolygen;

    int ymin = 0;
    int ymax = 0;
    int xmin = 0;
    int xmax = 0;
    findBoundary(ymin, ymax, xmin, xmax, p);
   // qDebug() << xmin << " " << xmax << " " << ymin << " " << ymax;

    int width = xmax - xmin + 1;
    int height = ymax - ymin + 1;
    int size = width * height;
    //qDebug() << "size " << size;
    int* map = new int [size];
    memset(map, 0, size * sizeof(int));   // 0-out; 2-edge; 1-inner

    markEdge(map, xmin, ymin, width, p);
    markCorner(map, xmin, ymin, width, height, p);
    while(p->next != NULL){
        if(p->next->dir == true)    break;
        p = p->next;
        markEdge(map, xmin, ymin, width, p);
        markCorner(map, xmin, ymin, width, height, p);
    }

    HPEN hPen = CreatePen(PS_SOLID, lineWidth, backColor);
    SelectObject(hdc, hPen);
    scanFill(map, xmax-xmin+1, ymax-ymin+1, xmin, ymin, true, hdc, frontColor);
    drawBoundary(hdc, currentInnerPolygen);
    p = currentInnerPolygen;
    while(p->next != NULL){
        if(p->next->dir)    break;
        p = p->next;
        drawBoundary(hdc, p);
    }

    if(map != NULL){
        delete []map;
        map = NULL;
    }
}

void Paint::convertPolygenToDot(int* map, int xmin, int ymin, int width, int height, Polygen* p)
{
    markEdge(map, xmin, ymin, width, p);
    markCorner(map, xmin, ymin, width, height, p);
    while(p->next != NULL){
        if(p->next->dir == true)    break;
        p = p->next;
        markEdge(map, xmin, ymin, width, p);
        markCorner(map, xmin, ymin, width, height, p);
    }
    scanFill(map, width, height, xmin, ymin, false, gHDC, RGB(0, 0, 0));
}

void Paint::fillLine(int* map, int xmin, int ymin, int width, int x1, int y1, int x2, int y2)
{
    int px, py, dx, dy, e;
    int px0 = x1-xmin;
    int px1 = x2-xmin;
    int py0 = y1-ymin;
    int py1 = y2-ymin;
    px = px0;
    py = py0;

    dx = abs(px1 - px0);
    dy = abs(py1 - py0);

    int addX = (px1 - px0) > 0 ? 1 : -1;
    int addY = (py1 - py0) > 0 ? 1 : -1;

    if(dx >= dy){
        e = -dx;
        for(int i = 0; i<=dx; i++)
        {
            map[px + py * width] = 3;

            px+=addX;
            e = e + 2 * dy;
            if(e >= 0)
            {
                py+=addY;
                e = e - 2 * dx;
            }
        }
    }
    else{
        e = -dy;
        for(int i = 0; i<=dy; i++)
        {
            map[px + py * width] = 3;
            py+=addY;
            e = e + 2 * dx;
            if(e >= 0)
            {
                px+=addX;
                e = e - 2 * dy;
            }
        }
    }
}

void Paint::drawDotPolygen(HDC &hdc, int* map, int xmin, int ymin, int width, int height)
{
    COLORREF color = RGB(0, 0, 0);
    //HPEN hPen = CreatePen(PS_SOLID, lineWidth, color);
    //SelectObject(hdc, hPen);

    for(int j = 0; j<height; j++)
    {
        for(int i = 0; i<width; i++)
        {
            int index = i+j*width;
            if(map[index] > 0)
            {
                SetPixel(hdc, i+xmin, j+ymin, color);
            }
        }
    }
}


void Paint::clipDotPolygen(int* map, int xmin, int  ymin, int width, int height)
{
}

