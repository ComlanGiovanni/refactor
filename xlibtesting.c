#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_text_width(Display *display, char *text);
void center_text_in_window(Display *display, Window window, GC gc, char *text, int win_width, int win_height);

// Fonction pour obtenir la largeur du texte
int get_text_width(Display *display, char *text) {
    XFontStruct *font;
    int direction, ascent, descent;
    XCharStruct overall;

    // Charge la police par défaut
    font = XLoadQueryFont(display, "fixed");
    if (!font) {
        fprintf(stderr, "Unable to load font\n");
        return -1;
    }

    // Obtient la largeur du texte
    XTextExtents(font, text, strlen(text), &direction, &ascent, &descent, &overall);
    return overall.width;
}

// Fonction pour centrer le texte dans la fenêtre
void center_text_in_window(Display *display, Window window, GC gc, char *text, int win_width, int win_height) {
    int text_width = get_text_width(display, text);
    int x = (win_width - text_width) / 2;
    int y = win_height / 2;  // Ajuster si nécessaire pour un centrage vertical correct

    // Dessine le texte centré
    XDrawString(display, window, gc, x, y, text, strlen(text));
}

int main() {
    Display *display;
    int screen;
    Window root_window, window;
    XEvent event;
    GC gc;
    char *title = "0";
    int win_width = 800;
    int win_height = 600;

    // Initialise Xlib
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open display\n");
        return -1;
    }
    screen = DefaultScreen(display);
    root_window = RootWindow(display, screen);

    // Crée une fenêtre
    window = XCreateSimpleWindow(display, root_window, 10, 10, win_width, win_height, 1,
                                 BlackPixel(display, screen), WhitePixel(display, screen));

    // Sélectionne les événements à surveiller
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // Affiche la fenêtre
    XMapWindow(display, window);

    // Crée un contexte graphique
    gc = XCreateGC(display, window, 0, NULL);

    // Boucle d'événements
    while (1) {
        XNextEvent(display, &event);

        // Gère l'événement Expose pour dessiner dans la fenêtre
        if (event.type == Expose) {
            center_text_in_window(display, window, gc, title, win_width, win_height);
        }

        // Gère l'événement KeyPress pour quitter le programme
        if (event.type == KeyPress) {
            break;
        }
    }

    // Nettoyage
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}
