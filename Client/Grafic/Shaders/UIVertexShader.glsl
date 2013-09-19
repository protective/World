#version 130

layout (location = 0) in vec4 in_Position;
layout (location = 1) in vec2 in_Texcoord;

out vec2 ex_Texcoord;

uniform mat4 ModelMatrix;
uniform mat4 ProjectionMatrix;

void main(void)
{
	//
	gl_Position =  (ProjectionMatrix * ModelMatrix) * in_Position;
	//gl_Position =  ModelMatrix * in_Position;
	ex_Texcoord = in_Texcoord;
	//in_Color;
}

