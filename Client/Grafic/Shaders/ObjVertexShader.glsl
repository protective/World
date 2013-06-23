#version 130

in vec3 in_Position;
//in vec4 in_Color;
out vec4 ex_Color;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main(void)
{
	//(ProjectionMatrix * ViewMatrix * ModelMatrix) *
	gl_Position =  vec4(in_Position,1);
	ex_Color = vec4(1,0,0,1);
	//in_Color;
}

