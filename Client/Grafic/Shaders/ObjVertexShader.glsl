#version 130

in vec4 in_Position;
//in vec4 in_Color;
out vec4 ex_Color;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main(void)
{
	//
	gl_Position =  (ProjectionMatrix * ViewMatrix * ModelMatrix) * in_Position;
	ex_Color = vec4(1,0,0,1);
	//in_Color;
}

