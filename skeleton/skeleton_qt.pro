DEFINES = WINDOWS
#DEFINES += LINUX

HEADERS += \
  colors.h \
  basic_object3d.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


!linux {
LIBS += -lopengl32 
}

linux {
LIBS += -lGL
}

CONFIG += c++14
QT += opengl
QT += widgets
