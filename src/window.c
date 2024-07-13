#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <math.h>

#define WindowWidth 500
#define WindowLenght 500

Display *dp;
Window w;

typedef struct
{
    float x, y, z;
} Point3d;
typedef struct
{
    float x, y;
} Point2d;

Point2d
planeTransform (Point3d p, float fov)
{
    Point2d rt;
    rt.x = (p.x * fov) / p.z;
    rt.y = (p.y * fov) / p.z;
    return rt;
}

// void
// rotateX (Point3d *axis, float theta)
// {
//     axis->y = axis->y * cos (theta) - axis->z * sin (theta);
//     axis->z = axis->y * sin (theta) + axis->z * cos (theta);
// }
// void
// rotateY (Point3d *axis, float theta)
// {
//     axis->x = axis->x * cos (theta) + axis->z * sin (theta);
//     axis->z = axis->z * cos (theta) - axis->x * sin (theta);
// }
// void
// rotateZ (Point3d *axis, float theta)
// {
//     axis->x = axis->x * cos (theta) - axis->y * sin (theta);
//     axis->y = axis->x * sin (theta) + axis->y * cos (theta);
// }
Point2d normalize (Point2d point) {
  Point2d rt;
  XWindowAttributes attr;
  XGetWindowAttributes(dp, w, &attr);
  rt.x = (point.x +1/2)* attr.width + attr.x;
    rt.y = (point.y +1/2)* attr.height + attr.y;

  
  return rt;
}

void
createWindow ()
{
    Point3d p[8];
p[0].x = -1; p[0].y = -1; p[0].z = -1;
p[1].x = -1; p[1].y = -1; p[1].z =  1;
p[2].x =  1; p[2].y = -1; p[2].z =  1;
p[3].x =  1; p[3].y = -1; p[3].z = -1;
p[4].x = -1; p[4].y =  1; p[0].z = -1;
p[5].x = -1; p[5].y =  1; p[1].z =  1;
p[6].x =  1; p[6].y =  1; p[2].z =  1;
p[7].x =  1; p[7].y =  1; p[3].z = -1;
    float FOV = 0.7;

    dp = XOpenDisplay (NULL);
    int screen = XDefaultScreen (dp);
    w = XCreateSimpleWindow (dp, XDefaultRootWindow (dp), 0, 0, WindowWidth,
                             WindowLenght, 5, 5, XBlackPixel (dp, screen));
    GC gc = XDefaultGC (dp, screen);
    XSetForeground (dp, gc, XWhitePixel (dp, screen));
    XSetBackground (dp, gc, XBlackPixel (dp, screen));
    XMapWindow (dp, w);
    XEvent event;
    while (1)
        {
            for ( int i = 0; i < 8; i++){
                              Point2d pt1= normalize(planeTransform(p[i], FOV));

              for( int j = 0; j < 8; j++){
                                Point2d pt2 = normalize(planeTransform(p[j], FOV));
                                XDrawLine(dp, w,gc, pt1.x, pt1.y, pt2.x, pt2.y);

              }
            }
        }
}