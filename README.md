# cgproject

This project is created for lab tutorial in my computer graphic course.
## Library Requiremnt
- [freeglut](http://freeglut.sourceforge.net/) is a free-software/open-source alternative to the OpenGL Utility Toolkit (GLUT) library.

## Linux Compile
```sh
gcc $(ls | grep \.c$) -lGL -lGLU -lglut -lm -o main && ./main
```
