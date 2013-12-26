#version 330

layout(points) in;
layout(triangle_strip) out;
layout(max_vertices = 4) out;   

uniform mat4 gVP;
uniform vec3 gCameraPos;
uniform vec3 gRight;
in float lifeTimeG[];
out vec3 TexCoord;

void main()
{
	vec3 Pos = gl_in[0].gl_Position.xyz;

	vec3 toCamera = normalize(gCameraPos - Pos);
	vec3 right = normalize(gRight);
	vec3 up = cross(right,toCamera) * -1; //vec3(0.0, 1.0, 0.0);

	right *= 7;
	up *= 7;	

	Pos -= (right * 0.5);
	Pos -= (up * 0.5);
	gl_Position = gVP * vec4(Pos, 1.0);
	TexCoord = vec3(0.01, 0.01, lifeTimeG[0]);
	EmitVertex();

	Pos += up;
	gl_Position = gVP * vec4(Pos, 1.0);
	TexCoord = vec3(0.01, 0.99, lifeTimeG[0]);
	EmitVertex();

	Pos += right;
	Pos -= up;
	gl_Position = gVP * vec4(Pos, 1.0);
	TexCoord = vec3(0.99, 0.01, lifeTimeG[0]);
	EmitVertex();

	Pos += up;
	gl_Position = gVP * vec4(Pos, 1.0);
	TexCoord = vec3(0.99,0.99, lifeTimeG[0]);
	EmitVertex();

	EndPrimitive();
}
