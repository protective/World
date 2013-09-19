/* 
 * File:   GLutil.h
 * Author: karsten
 *
 * Created on 9. juni 2013, 11:24
 */

#ifndef GLUTIL_H
#define	GLUTIL_H
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
//#include "SDL/SDL_opengl.h"
//#include "GL/gl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <GL/glew.h>

#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//#include <GL/freeglut.h>

// #define  PI  3.14159265358979323846

typedef struct Vertex
{
	float Position[4];
	float Tex[2];
} Vertex;

typedef struct Intice
{
	uint32_t value;
} Intice;

typedef struct Matrix
{
	float m[16];
} Matrix;

static const Matrix IDENTITY_MATRIX = { {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
} };

float Cotangent(float angle);
float DegreesToRadians(float degrees);
float RadiansToDegrees(float radians);

Matrix MultiplyMatrices(const Matrix* m1, const Matrix* m2);
void RotateAboutX(Matrix* m, float angle);
void RotateAboutY(Matrix* m, float angle);
void RotateAboutZ(Matrix* m, float angle);
void ScaleMatrix(Matrix* m, float x, float y, float z);
void TranslateMatrix(Matrix* m, float x, float y, float z);
Matrix InverseMatrix(Matrix* m);
Matrix CreateProjectionMatrix(
	float fovy,
	float aspect_ratio,
	float near_plane,
	float far_plane
);

Matrix CreateOthoMatrix(float l, float r,float t,float b);

void ExitOnGLError(const char* error_message);
GLuint LoadShader(const char* filename, GLenum shader_type);

#endif	/* GLUTIL_H */

