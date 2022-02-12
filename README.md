# FGGC-practica1
Master en Desarrollo de Software   
Asignatura: “Fundamentos de Geometría y Geometría Computacional”

Tarea 1: OpenGL - Modeling and rendering of simple 3D

1.2.	Development

For the development of this practice, the skeleton of an event-based graphic application is delivered, using Qt 5, with the graphic part made by OpenGL, and being C++ the programming language. The application not only contains the OpenGL initialization code and the capture of key events, but a class structure that allows to represent 3D objects, including axes and tetrahedron objects. It is also implemented a camera that moves on the surface of a sphere by pressing the cursor keys, and page forward and page back keys to simulate a zoom in and zoom out.

The student must study and understand the code that is delivered. Once this is done, you must add the functions that allow you to draw in fill mode and chess mode. In addition, following the hierarchy already defined, you must create the cube class and use an instance that allows you to visualize it when the key 2 is pressed.

Therefore, the following drawing modes will be available at the end:
•	Points
•	Lines
•	Fill
•	Chess
To be able to visualize in fill mode, you only have to use triangles as a drawing primitive, GL_TRIANGLES, and change the way it is displayed using the glPolygonMode instruction, so that the inside is drawn. For chess mode, it is enough to draw in solid mode but alternatively changing the fill color.
Define the following keys to activate the different modes and objects:
•	Key p: to render in point mode
•	Key l: to render in line mode
•	Key f: to render in fill mode
•	Key c: to render in chess mode
•	Key 1: to activate the tetrahedron
•	Key 2: to activate the cube
