#version 130

in vec2 ex_Texcoord;
out vec4 out_Color;
uniform sampler2D mytexture;
void main(void)
{
	out_Color = texture2D(mytexture, ex_Texcoord);


}

