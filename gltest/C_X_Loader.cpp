#include "C_X_Loader.h"
#include "CMesh.h"
#include "C_X_ReaderBase.h"
#include "C_X_ReaderMesh.h"

CMesh* Lload(string file){
	CMesh* mesh = NULL;
	list<C_X_ReaderBase*> nowReading;
	ifstream reader(file.c_str());
	string line;
	C_X_ReaderBase* Xreader = NULL;
	while (std::getline((reader), line)) {

		if (line.find("//") != string::npos){
			line = line.substr(0,line.find("//"));
		}
		
		if(line.find("{") != string::npos){
			line = trim(line);
			line = line.substr(0,line.length()-1);
			line = trim(line);
			cerr<<"+"<<line<<endl;
			
			if(line == "Mesh"){
				nowReading.push_back(new C_X_ReaderMesh());
			}else if (line =="MeshNormals"){
				C_X_ReaderNormals* temp = new C_X_ReaderNormals();
				nowReading.back()->SetReaderNormal(temp);
				nowReading.push_back(temp);
			}else
				nowReading.push_back(NULL);
			
			continue;
		}
		if(line.find("}") != string::npos){
			if(nowReading.back() && !nowReading.empty()){
				cerr<<"-"<<nowReading.back()->Name()<<endl;
				if(nowReading.back()->Name() == "Mesh")
					mesh = nowReading.back()->getMesh();
				//delete nowReading.back();
			}
			
			nowReading.pop_back();
			continue;
		}
		
		
		if(nowReading.back() != NULL && !nowReading.empty()){
			nowReading.back()->ReadLine(line);
		}
	}

	return mesh;
}
void printLog(GLuint obj)
{
	int infologLength = 0;
	int maxLength;
 
	if(glIsShader(obj))
		glGetShaderiv(obj,GL_INFO_LOG_LENGTH,&maxLength);
	else
		glGetProgramiv(obj,GL_INFO_LOG_LENGTH,&maxLength);
 
	char infoLog[maxLength];
 
	if (glIsShader(obj))
		glGetShaderInfoLog(obj, maxLength, &infologLength, infoLog);
	else
		glGetProgramInfoLog(obj, maxLength, &infologLength, infoLog);
 
	if (infologLength > 0)
		printf("%s\n",infoLog);
}

char *file2string(const char *path)
{
	FILE *fd;
	long len,
		 r;
	char *str;
 
	if (!(fd = fopen(path, "r")))
	{
		fprintf(stderr, "Can't open file '%s' for reading\n", path);
		return NULL;
	}
 
	fseek(fd, 0, SEEK_END);
	len = ftell(fd);
 
	printf("File '%s' is %ld long\n", path, len);
 
	fseek(fd, 0, SEEK_SET);
 
	if (!(str = (char*)malloc(len * sizeof(char))))
	{
		fprintf(stderr, "Can't malloc space for '%s'\n", path);
		return NULL;
	}
 
	r = fread(str, sizeof(char), len, fd);
 
	str[r - 1] = '\0'; /* Shader sources have to term with null */
 
	fclose(fd);
 
	return str;
}


int initiateShaders(string vertexShader, string fragmentShader){
	glewInit();
	if (GLEW_VERSION_2_0)
		fprintf(stderr, "INFO: OpenGL 2.0 supported, proceeding\n");
	else
	{
		fprintf(stderr, "INFO: OpenGL 2.0 not supported. Exit\n");
		return EXIT_FAILURE;
	}
	
	
		/* The vertex shader */
	const GLchar *vsSource = file2string(vertexShader.c_str());
	const GLchar *fsSource = file2string(fragmentShader.c_str());
 
	/* Compile and load the program */
 
	GLuint vs, /* Vertex Shader */
		   fs, /* Fragment Shader */
		   sp; /* Shader Program */
 
 
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vsSource, NULL);
	glCompileShader(vs);
	printLog(vs);
 
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fsSource, NULL);
	glCompileShader(fs);
	printLog(fs);
 
	free((void*)vsSource);
	free((void*)fsSource);
 
	sp = glCreateProgram();
	glAttachShader(sp, vs);
	glAttachShader(sp, fs);
	glLinkProgram(sp);
	printLog(sp);
 
	glUseProgram(sp);
	
	return EXIT_SUCCESS;
}