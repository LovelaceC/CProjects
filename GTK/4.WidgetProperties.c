#include <gtk/gtk.h>

static void destroy (GtkWidget *, gpointer);
static void property_changed (GObject *button, GParamSpec *property,
                              gpointer data);

int
main (int argc, char **argv)
{
  GtkWidget *window, *button;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Widget property");
  gtk_container_set_border_width (GTK_CONTAINER (window), 25);
  gtk_widget_set_size_request (window, 200, 100);

  g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);

  button = gtk_button_new_with_label ("Close");

  // When the property `relief' is changed. Call `property_changed'
  g_signal_connect (G_OBJECT (button), "notify::relief",
                    G_CALLBACK (property_changed), NULL);

  g_object_set (button, "relief", GTK_RELIEF_HALF, NULL);

  g_signal_connect_swapped (G_OBJECT (button), "clicked",
                            G_CALLBACK (gtk_widget_destroy), (gpointer)window);

  gtk_container_add (GTK_CONTAINER (window), button);
  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}

/* Stop the GTK+ main loop function when the window is destroyed. */
static void
destroy (GtkWidget *window, gpointer data)
{
  gtk_main_quit ();
}

static void
property_changed (GObject *button, GParamSpec *property, gpointer data)
{
  printf ("Property `%s' changed.\n", property->name);
}
