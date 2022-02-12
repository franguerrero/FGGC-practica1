/*! \file
 * Copyright Francisco Guerrero
 * email: franciscoga@correo.ugr.es
 * 2022
 * GPL 3
 */


#include "cube.h"


/*****************************************************************************//**
 *
 * Clase cubo para la practica 1.
 * El cubo tiene 8 vertices que forman 6 caras por lo que vamos a tener 12 triangulos
 *
 *****************************************************************************/

_cube::_cube(float Size)
{
  Vertices.resize(8);

  Vertices[0]=_vertex3f(-Size/2,-Size/2,-Size/2);
  Vertices[1]=_vertex3f(Size/2,-Size/2,-Size/2);
  Vertices[2]=_vertex3f(Size/2,Size/2,-Size/2);
  Vertices[3]=_vertex3f(-Size/2,Size/2,-Size/2);
  Vertices[4]=_vertex3f(-Size/2,-Size/2,Size/2);
  Vertices[5]=_vertex3f(Size/2,-Size/2,Size/2);
  Vertices[6]=_vertex3f(Size/2,Size/2,Size/2);
  Vertices[7]=_vertex3f(-Size/2,Size/2,Size/2);

  Triangles.resize(12);

  Triangles[0]=_vertex3ui(0,2,1);
  Triangles[1]=_vertex3ui(0,3,2);
  Triangles[2]=_vertex3ui(0,4,3);
  Triangles[3]=_vertex3ui(4,7,3);

  Triangles[4]=_vertex3ui(0,1,4);
  Triangles[5]=_vertex3ui(4,1,5);
  Triangles[6]=_vertex3ui(3,7,2);
  Triangles[7]=_vertex3ui(7,6,2);

  Triangles[8]=_vertex3ui(4,5,6);
  Triangles[9]=_vertex3ui(7,4,6);
  Triangles[10]=_vertex3ui(5,1,2);
  Triangles[11]=_vertex3ui(2,6,5);
}

