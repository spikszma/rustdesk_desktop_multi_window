//
// Created by boyan on 2022/1/27.
//

#ifndef DESKTOP_MULTI_WINDOW_LINUX_BASE_FLUTTER_WINDOW_H_
#define DESKTOP_MULTI_WINDOW_LINUX_BASE_FLUTTER_WINDOW_H_

#include <cmath>
#include <gtk/gtk.h>
#include <string>

#include "window_channel.h"

class BaseFlutterWindow {
public:
  virtual ~BaseFlutterWindow() = default;

  virtual WindowChannel *GetWindowChannel() = 0;

  void Show();

  void Hide();

  void Focus();

  void SetFullscreen(bool fullscreen);

  void Close();

  void SetTitle(const std::string &title);

  void SetBounds(double_t x, double_t y, double_t width, double_t height);

  void Center();

  void StartDragging();

  void Minimize();

  bool IsMaximized();

  void Maximize();

  void Unmaximize();

  void ShowTitlebar(bool show);

  void findEventBox(GtkWidget *widget);

  void StartResizing(FlValue *value);

  bool isDragging = false;
  GtkWidget *event_box = nullptr;
  GdkEventButton currentPressedEvent = GdkEventButton{};

protected:
  virtual GtkWindow *GetWindow() = 0;

  bool maximized = false;
};

gboolean onWindowEventAfter(GtkWidget *text_view, GdkEvent *event,
                            BaseFlutterWindow *self);

gboolean onMousePressHook(GSignalInvocationHint *ihint, guint n_param_values,
                          const GValue *param_values, gpointer data);

#endif // DESKTOP_MULTI_WINDOW_LINUX_BASE_FLUTTER_WINDOW_H_
