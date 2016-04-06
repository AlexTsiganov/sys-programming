#include <stdio.h>
#include <X11/Xlib.h>

#ifndef lab7_km_limit
#define lab7_km_limit 20
#endif

int main(int argc, char **argv)
{
    int i = 0; // флаг выхода из цикла при лимите 20 событий
    XEvent xevent;
    Window window;
    char* mouse_buttons[] = {
        "left",
        "middle",
        "right",
    };

    // инициализация дисплея
    Display *display = XOpenDisplay(NULL);
    // указатель на окно
    window = DefaultRootWindow(display);
    //разрешили обработку событий
    XAllowEvents(display, AsyncBoth, CurrentTime);
    // настройка событий мыши
    XGrabPointer(display,
                 window,
                 1,
                 PointerMotionMask | ButtonPressMask | ButtonReleaseMask ,
                 GrabModeAsync,
                 GrabModeAsync,
                 None,
                 None,
                 CurrentTime);
    // настройка событий клавиатуры
    XGrabKeyboard(display, window, 1, GrabModeAsync,
             GrabModeAsync, CurrentTime);
    
    while(1 && i++<lab7_km_limit) 
    {
        //  информация о произошедшем событии и вывод в консоль
        XNextEvent(display, &xevent);
        if (xevent.type == MotionNotify)
            printf("Mouse move: (%d, %d)\n", xevent.xmotion.x_root, xevent.xmotion.y_root);
        else if (xevent.type == ButtonPress)
            printf("Button down: %s\n", mouse_buttons[xevent.xbutton.button - 1]);
        else if (xevent.type == ButtonRelease)
            printf("Button up: %s\n", mouse_buttons[xevent.xbutton.button - 1]);
        else if (xevent.type == KeyPress)
            printf("Key down: %d\n", xevent.xkey.keycode);
        else if (xevent.type == KeyRelease)
            printf("Key up: %d\n", xevent.xkey.keycode);
        else
            printf("Unknown event\n");
    }
    return 0;
}
