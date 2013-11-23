#version 330

uniform sampler3D gColorMap;

in vec3 TexCoord;
out vec4 FragColor;

void main()
{
	FragColor = texture(gColorMap, TexCoord);

	//if (FragColor.a < 0.5 ) {
	//	discard;
	//}
}
