#include <iostream>
#include <gtk-4.0/gtk/gtk.h>
#include <GL/gl.h>

static void on_realize(GtkGLArea *area)
{
    gtk_gl_area_make_current (area);
    if (gtk_gl_area_get_error (area) != nullptr){
        std::cout << "Error initializing OpenGL context!\n";
    }
}


static gboolean render(GtkGLArea *area, GdkGLContext *context){

    glClearColor(0, 1, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    return TRUE;
}


static void activate(GtkApplication *app, gpointer data){
    GtkWidget *window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Window");
    gtk_window_set_default_size(GTK_WINDOW (window), 200, 200);

    GtkWidget *glArea = gtk_gl_area_new();
    g_signal_connect(glArea, "render", G_CALLBACK(render), nullptr);
    g_signal_connect(glArea, "realize", G_CALLBACK(on_realize), nullptr);

    gtk_window_set_child(GTK_WINDOW(window), glArea);

    gtk_widget_show(window);
}


int main(int argc, char** argv) {

    GtkApplication *app;

    app = gtk_application_new("vulkan.integration.test", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), nullptr);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
