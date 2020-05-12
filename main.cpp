// An attempt at creating the mandelbrot set from scratch.
#include <iostream>
#include <X11/Xlib.h>

using namespace std;

int main(){

    Display *dis;
    Window main, root; // Main and root window.
    int screen_number;
    unsigned long black, white;
    GC gc;

    dis = XOpenDisplay(NULL); // Start connection to xserver.
    screen_number = XDefaultScreen(dis);

    // Get white & black pixel values.
    black = XBlackPixel(dis, screen_number);
    white = XWhitePixel(dis, screen_number);

    root = XDefaultRootWindow(dis);
    main = XCreateSimpleWindow(dis, root, 0, 0, 500, 300,
                               5, white, black);

    XMapRaised(dis, main);
    XFlush(dis);

    Atom WM_DELETE_WINDOW = XInternAtom(dis, "WM_DELETE", False);
    XSetWMProtocols(dis, main, &WM_DELETE_WINDOW, 1);

    XEvent *event_ret;
        XNextEvent(dis, event_ret);
    XCloseDisplay(dis);
    return 0;
}
