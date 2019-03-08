#ifndef CSHAPES_H
#define CSHAPES_H

#define ush uint16
#define BYTE unsigned char

#include <PluginImage.h>
#include <PluginPipeSettings.h>

// Simple shape drawing class for Bibble 5 tiles
//
// The line coordinates must be given in current mip coordinates
//

class CShapes
{
public:
    CShapes();
    CShapes(PluginImage *Img,int tileX0,int tileY0,int mip);
    CShapes(ush *tile,int tileW,int tileH,int tileX0,int tileY0,int mip,int rw,int np, int pw);

	//Init must be called after the empty consructor
    void init(ush *tile,int tileW,int tileH,int tileX0,int tileY0,int mip,int rw,int np, int pw);

	//Draw a line between (x0,y0) > (x1,y1)
    void drawLine(int x0,int y0,int x1,int y1,ush r,ush g,ush b,BYTE width);

	//Draw a 1 pixel thick line between (x0,y0) > (x1,y1)
    void drawLine1(int x0,int y0,int x1,int y1,ush r,ush g,ush b);

	//Draw a horizontal line between x0 > x1 (on y0). Faster than drawLine
    void drawHLine(int x0,int x1,int y,ush r,ush g,ush b,BYTE width);

	//Draw a vertical line between y0 > y1 (on x0). Faster than drawLine
    void drawVLine(int x,int y0,int y1,ush r,ush g,ush b,BYTE width);
	
	void drawWhVLine(int x,int y0,int y1);
	void drawWhHLine(int x0,int x1,int y);

	//Draw a rectangle
    void drawRect(int x0,int y0,int x1,int y1,ush r,ush g,ush b,BYTE width);

	//Draw a polygon or polyline. The cordonates are in the x and y arrays (size n).
    void drawPoly(int *x,int *y,int n,bool closed,ush r,ush g,ush b,BYTE width);

	//Draw a quadratic Bezier curve 0,1 endpoints, A,B control points
	void drawBezier(int x0,int y0,int xA,int yA,int xB,int yB,int x1,int y1,ush r,ush g,ush b,BYTE width);

	//Get the pixels from a rectangular area
	int getRect(int x0,int y0,int x1,int y1,ush *r,ush *g,ush *b);

	void mapPoint(int *x,int*y);
private:
    int w,h;
    int tilesize;
    int xmin,xmax,ymin,ymax;
    int rw,np,pw,mip;
    ush *ptr;
    bool in(int val,int min,int max){return (val>=min)&&(val<max);}
    int getpos(int x,int y,int c){return y*rw + x*np + c*pw;}
    int getpos(int x,int y){return y*rw + x*np;}
    int getpos2(int x,int y){return y + x*np;}
    bool test(int *x0,int *y0,int *x1,int *y1);
	int dist(int x0,int y0,int x1,int y1);
};

#endif // CSHAPES_H
