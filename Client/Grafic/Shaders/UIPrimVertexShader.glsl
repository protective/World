#version 330

layout (location = 0) in vec4 in_Position;

uniform mat4 ModelMatrix;
uniform mat4 ProjectionMatrix;

void main(void)
{
	gl_Position =  (ProjectionMatrix * ModelMatrix) * in_Position;
}

