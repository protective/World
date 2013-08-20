#include "CGlobals.h"

#include "GLutil.h"
using namespace std;
float Cotangent(float angle)
{
	return (float)(1.0 / tan(angle));
}

float DegreesToRadians(float degrees)
{
	return degrees * (float)(PI / 180);
}

float RadiansToDegrees(float radians)
{
	return radians * (float)(180 / PI);
}

Matrix MultiplyMatrices(const Matrix* m1, const Matrix* m2)
{
	Matrix out = IDENTITY_MATRIX;
	unsigned int row, column, row_offset;

	for (row = 0, row_offset = row * 4; row < 4; ++row, row_offset = row * 4)
		for (column = 0; column < 4; ++column)
			out.m[row_offset + column] =
				(m1->m[row_offset + 0] * m2->m[column + 0]) +
				(m1->m[row_offset + 1] * m2->m[column + 4]) +
				(m1->m[row_offset + 2] * m2->m[column + 8]) +
				(m1->m[row_offset + 3] * m2->m[column + 12]);

	return out;
}

Matrix InverseMatrix(Matrix* m){

    double inv[16], det;
    int i;

    inv[0] = m->m[5]  * m->m[10] * m->m[15] - 
             m->m[5]  * m->m[11] * m->m[14] - 
             m->m[9]  * m->m[6]  * m->m[15] + 
             m->m[9]  * m->m[7]  * m->m[14] +
             m->m[13] * m->m[6]  * m->m[11] - 
             m->m[13] * m->m[7]  * m->m[10];

    inv[4] = -m->m[4]  * m->m[10] * m->m[15] + 
              m->m[4]  * m->m[11] * m->m[14] + 
              m->m[8]  * m->m[6]  * m->m[15] - 
              m->m[8]  * m->m[7]  * m->m[14] - 
              m->m[12] * m->m[6]  * m->m[11] + 
              m->m[12] * m->m[7]  * m->m[10];

    inv[8] = m->m[4]  * m->m[9] * m->m[15] - 
             m->m[4]  * m->m[11] * m->m[13] - 
             m->m[8]  * m->m[5] * m->m[15] + 
             m->m[8]  * m->m[7] * m->m[13] + 
             m->m[12] * m->m[5] * m->m[11] - 
             m->m[12] * m->m[7] * m->m[9];

    inv[12] = -m->m[4]  * m->m[9] * m->m[14] + 
               m->m[4]  * m->m[10] * m->m[13] +
               m->m[8]  * m->m[5] * m->m[14] - 
               m->m[8]  * m->m[6] * m->m[13] - 
               m->m[12] * m->m[5] * m->m[10] + 
               m->m[12] * m->m[6] * m->m[9];

    inv[1] = -m->m[1]  * m->m[10] * m->m[15] + 
              m->m[1]  * m->m[11] * m->m[14] + 
              m->m[9]  * m->m[2] * m->m[15] - 
              m->m[9]  * m->m[3] * m->m[14] - 
              m->m[13] * m->m[2] * m->m[11] + 
              m->m[13] * m->m[3] * m->m[10];

    inv[5] = m->m[0]  * m->m[10] * m->m[15] - 
             m->m[0]  * m->m[11] * m->m[14] - 
             m->m[8]  * m->m[2] * m->m[15] + 
             m->m[8]  * m->m[3] * m->m[14] + 
             m->m[12] * m->m[2] * m->m[11] - 
             m->m[12] * m->m[3] * m->m[10];

    inv[9] = -m->m[0]  * m->m[9] * m->m[15] + 
              m->m[0]  * m->m[11] * m->m[13] + 
              m->m[8]  * m->m[1] * m->m[15] - 
              m->m[8]  * m->m[3] * m->m[13] - 
              m->m[12] * m->m[1] * m->m[11] + 
              m->m[12] * m->m[3] * m->m[9];

    inv[13] = m->m[0]  * m->m[9] * m->m[14] - 
              m->m[0]  * m->m[10] * m->m[13] - 
              m->m[8]  * m->m[1] * m->m[14] + 
              m->m[8]  * m->m[2] * m->m[13] + 
              m->m[12] * m->m[1] * m->m[10] - 
              m->m[12] * m->m[2] * m->m[9];

    inv[2] = m->m[1]  * m->m[6] * m->m[15] - 
             m->m[1]  * m->m[7] * m->m[14] - 
             m->m[5]  * m->m[2] * m->m[15] + 
             m->m[5]  * m->m[3] * m->m[14] + 
             m->m[13] * m->m[2] * m->m[7] - 
             m->m[13] * m->m[3] * m->m[6];

    inv[6] = -m->m[0]  * m->m[6] * m->m[15] + 
              m->m[0]  * m->m[7] * m->m[14] + 
              m->m[4]  * m->m[2] * m->m[15] - 
              m->m[4]  * m->m[3] * m->m[14] - 
              m->m[12] * m->m[2] * m->m[7] + 
              m->m[12] * m->m[3] * m->m[6];

    inv[10] = m->m[0]  * m->m[5] * m->m[15] - 
              m->m[0]  * m->m[7] * m->m[13] - 
              m->m[4]  * m->m[1] * m->m[15] + 
              m->m[4]  * m->m[3] * m->m[13] + 
              m->m[12] * m->m[1] * m->m[7] - 
              m->m[12] * m->m[3] * m->m[5];

    inv[14] = -m->m[0]  * m->m[5] * m->m[14] + 
               m->m[0]  * m->m[6] * m->m[13] + 
               m->m[4]  * m->m[1] * m->m[14] - 
               m->m[4]  * m->m[2] * m->m[13] - 
               m->m[12] * m->m[1] * m->m[6] + 
               m->m[12] * m->m[2] * m->m[5];

    inv[3] = -m->m[1] * m->m[6] * m->m[11] + 
              m->m[1] * m->m[7] * m->m[10] + 
              m->m[5] * m->m[2] * m->m[11] - 
              m->m[5] * m->m[3] * m->m[10] - 
              m->m[9] * m->m[2] * m->m[7] + 
              m->m[9] * m->m[3] * m->m[6];

    inv[7] = m->m[0] * m->m[6] * m->m[11] - 
             m->m[0] * m->m[7] * m->m[10] - 
             m->m[4] * m->m[2] * m->m[11] + 
             m->m[4] * m->m[3] * m->m[10] + 
             m->m[8] * m->m[2] * m->m[7] - 
             m->m[8] * m->m[3] * m->m[6];

    inv[11] = -m->m[0] * m->m[5] * m->m[11] + 
               m->m[0] * m->m[7] * m->m[9] + 
               m->m[4] * m->m[1] * m->m[11] - 
               m->m[4] * m->m[3] * m->m[9] - 
               m->m[8] * m->m[1] * m->m[7] + 
               m->m[8] * m->m[3] * m->m[5];

    inv[15] = m->m[0] * m->m[5] * m->m[10] - 
              m->m[0] * m->m[6] * m->m[9] - 
              m->m[4] * m->m[1] * m->m[10] + 
              m->m[4] * m->m[2] * m->m[9] + 
              m->m[8] * m->m[1] * m->m[6] - 
              m->m[8] * m->m[2] * m->m[5];

    det = m->m[0] * inv[0] + m->m[1] * inv[4] + m->m[2] * inv[8] + m->m[3] * inv[12];

    if (det == 0)
		cerr<<"MATRIX ERROR"<<endl;

    det = 1.0 / det;
	Matrix out;
    for (i = 0; i < 16; i++)
        out.m[i] = inv[i] * det;

    return out;
}

void ScaleMatrix(Matrix* m, float x, float y, float z)
{
	Matrix scale = IDENTITY_MATRIX;

	scale.m[0] = x;
	scale.m[5] = y;
	scale.m[10] = z;

	memcpy(m->m, MultiplyMatrices(m, &scale).m, sizeof(m->m));
}

void TranslateMatrix(Matrix* m, float x, float y, float z)
{
	Matrix translation = IDENTITY_MATRIX;
	
	translation.m[12] = x;
	translation.m[13] = y;
	translation.m[14] = z;

	memcpy(m->m, MultiplyMatrices(m, &translation).m, sizeof(m->m));
}

void RotateAboutX(Matrix* m, float angle)
{
	Matrix rotation = IDENTITY_MATRIX;
	float sine = (float)sin(angle);
	float cosine = (float)cos(angle);
	
	rotation.m[5] = cosine;
	rotation.m[6] = -sine;
	rotation.m[9] = sine;
	rotation.m[10] = cosine;

	memcpy(m->m, MultiplyMatrices(m, &rotation).m, sizeof(m->m));
}

void RotateAboutY(Matrix* m, float angle)
{
	Matrix rotation = IDENTITY_MATRIX;
	float sine = (float)sin(angle);
	float cosine = (float)cos(angle);
	
	rotation.m[0] = cosine;
	rotation.m[8] = sine;
	rotation.m[2] = -sine;
	rotation.m[10] = cosine;

	memcpy(m->m, MultiplyMatrices(m, &rotation).m, sizeof(m->m));
}

void RotateAboutZ(Matrix* m, float angle)
{
	Matrix rotation = IDENTITY_MATRIX;
	float sine = (float)sin(angle);
	float cosine = (float)cos(angle);
	
	rotation.m[0] = cosine;
	rotation.m[1] = -sine;
	rotation.m[4] = sine;
	rotation.m[5] = cosine;

	memcpy(m->m, MultiplyMatrices(m, &rotation).m, sizeof(m->m));
}

Matrix CreateOthoMatrix(float l, float r,float t,float b){
	float n = 0;
	float f = 1;
	
	Matrix out = { { 0 } };
	
	out.m[0] = 2 / (r - l);
    out.m[5] = 2 / (t - b);
    out.m[10] = -2 / (f - n);
    out.m[12] = -(r + l) / (r - l);
    out.m[13] = -(t + b) / (t - b);
    out.m[14] = -(f + n) / (f - n);
    out.m[15] = 1;
	
	return out;

}

Matrix CreateProjectionMatrix(
	float fovy,
	float aspect_ratio,
	float near_plane,
	float far_plane
)
{
	Matrix out = { { 0 } };

	const float
		y_scale = Cotangent(DegreesToRadians(fovy / 2)),
		x_scale = y_scale / aspect_ratio,
		frustum_length = far_plane - near_plane;

	out.m[0] = x_scale;
	out.m[5] = y_scale;
	out.m[10] = -((far_plane + near_plane) / frustum_length);
	out.m[11] = -1;
	out.m[14] = -((2 * near_plane * far_plane) / frustum_length);
	
	return out;
}

void ExitOnGLError(const char* error_message)
{
	const GLenum ErrorValue = glGetError();

	if (ErrorValue != GL_NO_ERROR)
	{
		const char* APPEND_DETAIL_STRING = ": %s\n";
		const size_t APPEND_LENGTH = strlen(APPEND_DETAIL_STRING) + 1;
		const size_t message_length = strlen(error_message);
		char* display_message = (char*)malloc(message_length + APPEND_LENGTH);

		memcpy(display_message, error_message, message_length);
		memcpy(&display_message[message_length], APPEND_DETAIL_STRING, APPEND_LENGTH);

		fprintf(stderr, display_message, gluErrorString(ErrorValue));

		free(display_message);
		exit(EXIT_FAILURE);
	}
}

GLuint LoadShader(const char* filename, GLenum shader_type)
{
	GLuint shader_id = 0;
	FILE* file;
	long file_size = -1;
	char* glsl_source;

	if (NULL != (file = fopen(filename, "rb")) &&
		0 == fseek(file, 0, SEEK_END) &&
		-1 != (file_size = ftell(file)))
	{
		rewind(file);
		
		if (NULL != (glsl_source = (char*)malloc(file_size + 1)))
		{
			if (file_size == (long)fread(glsl_source, sizeof(char), file_size, file))
			{
				glsl_source[file_size] = '\0';

				if (0 != (shader_id = glCreateShader(shader_type)))
				{
					glShaderSource(shader_id, 1, (const char **)&glsl_source, NULL);
					glCompileShader(shader_id);
					
					
					GLint status;
					glGetShaderiv(shader_id, GL_COMPILE_STATUS, &status);

					if (status == GL_FALSE)
					{
						GLint infoLogLength;
						glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &infoLogLength);

						GLchar* strInfoLog = new GLchar[infoLogLength + 1];
						glGetShaderInfoLog(shader_id, infoLogLength, NULL, strInfoLog);

						fprintf(stderr, "Compilation error in shader %i: %s\n", shader_id, strInfoLog);
						delete[] strInfoLog;
					}else
						cerr<<"shader "<<shader_id<<" OK"<<endl;
					
					
					ExitOnGLError("Could not compile a shader");
				}
				else
					fprintf(stderr, "ERROR: Could not create a shader.\n");
			}
			else
				fprintf(stderr, "ERROR: Could not read file %s\n", filename);

			free(glsl_source);
		}
		else
			cerr<<"ERROR: Could not allocate "<<file_size<<"bytes."<<endl;

		fclose(file);
	}
	else
		fprintf(stderr, "ERROR: Could not open file %s\n", filename);

	return shader_id;
}