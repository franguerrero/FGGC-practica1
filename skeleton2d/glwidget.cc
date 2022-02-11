/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2020
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_PageUp:Scaling_factor*=1.1f;;break;
  case Qt::Key_PageDown:Scaling_factor/=1.1f;;break;


  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;

  case Qt::Key_Left:Scaling_factor-=ANGLE_STEP;break;
  case Qt::Key_Right:Scaling_factor+=ANGLE_STEP;break;
  case Qt::Key_Up:Scaling_factor-=ANGLE_STEP;break;
  case Qt::Key_Down:Scaling_factor+=ANGLE_STEP;break;

  }

  update();
}

/*****************************************************************************//**
 * Evento al soltar los botones del ratón
 *
 *
 *
 *****************************************************************************/

void _gl_widget::mouseReleaseEvent(QMouseEvent *Event)
{
  compute_position(Event);
}

/*****************************************************************************//**
 * Evento para la rueda del ratón
 *
 *
 *
 *****************************************************************************/

void _gl_widget::wheelEvent(QWheelEvent *event)
{
  int Step=event->delta()/120;

  if (Step<0){
    Scaling_factor/=1.1f;
  }
  else{
    Scaling_factor*=1.1f;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  Window_height=float(Device_height)/float(Device_width);

  glOrtho(-Window_width*Scaling_factor,Window_width*Scaling_factor,-Window_height*Scaling_factor,Window_height*Scaling_factor,-100,100);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(Translation.x,Translation.y,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  glColor3fv((GLfloat *) &MAGENTA);
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glBegin(GL_TRIANGLES);
  glVertex3f(0.5,-0.5,0);
  glVertex3f(0,0.5,0);
  glVertex3f(-0.5,-0.5,0);
  glEnd();
}

/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  Device_width=Width1;
  Device_height=Height1;
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);

  Device_width=width();
  Device_height=height();

  Window_width=1;
  Window_height=float(Device_height)/float(Device_width);

  Scaling_factor=1;
  Translation=_vertex3f(0,0,0);
}


/*****************************************************************************//**
 * Calcula las coordenadas de ventana del mundo a partir de las de dispositivo
 *
 *
 *
 *****************************************************************************/

void _gl_widget::compute_position(QMouseEvent *Event)
{
  float x= (2*Window_width*Scaling_factor*float(Event->x())/float(Device_width))-Window_width*Scaling_factor;
  float y=(2*Window_height*Scaling_factor*float(Device_height-Event->y())/float(Device_height))-Window_height*Scaling_factor;

	cout << "Device x=" << Event->x() << " y=" << Event->y() << endl;
  cout << "Window x=" << x << " y=" << y << endl;
}
