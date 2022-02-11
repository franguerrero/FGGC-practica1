/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();


protected:
  void resizeGL(int Width1, int Height1) override;
  void paintGL() override;
  void initializeGL() override;
  void keyPressEvent(QKeyEvent *Keyevent) override;
  void mouseReleaseEvent(QMouseEvent *Event) override;
  void wheelEvent(QWheelEvent *Event) override;

  void compute_position(QMouseEvent *Event);

private:
  _window *Window;

  _axis Axis;

  int Initial_position_X;
  int Initial_position_Y;

  int Selection_position_X;
  int Selection_position_Y;

  float Window_width;
  float Window_height;

  int Device_width;
  int Device_height;

  float Scaling_factor;
  _vertex3f Translation;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
};

#endif
