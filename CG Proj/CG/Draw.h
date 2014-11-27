#pragma once
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
class Draw
{
public:
	Draw(void);
	~Draw(void);

	static void plane(int lines, int columns, float width, float height);
	static void texturedPlane(int lines, int columns, float width, float height, GLuint texture);
	static void hexagonalPrism();
	static void loadTexture(const char * filename, int * width, int * height, int * size, unsigned char **pixel_data);
};