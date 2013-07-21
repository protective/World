#version 130

in vec4 in_Position;
in vec2 in_Texcoord;

out vec2 ex_Texcoord;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main(void)
{
	//
	gl_Position =  (ProjectionMatrix * ViewMatrix * ModelMatrix) * in_Position;
	ex_Texcoord = in_Texcoord;
	//in_Color;
}

