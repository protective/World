#version 330

layout (location = 0) in vec3 Position;
layout (location = 1) in float lifeTimeV;

out float lifeTimeG;
void main()
{
    gl_Position = vec4(Position, 1.0);
	lifeTimeG = min(0.8,lifeTimeV/3000);
}

