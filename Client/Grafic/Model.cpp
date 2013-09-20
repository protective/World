/* 
 * File:   Model.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 16:16
 */

#include <vector>

#include "Model.h"
#include "Grafic.h"
#include "Shaders/ObjectShader.h"


Model::Model(ObjectShader* shader) {

	//glUseProgram(shader->getProgramId());
	shader->enable();
	_shader = shader;
	cerr<<"BEGIN CREATE MODEL"<<endl;
	createFromFile("../../../Mesh/box.x3d");
	_texture = textures[0];


	glGenVertexArrays(1, &_vao);
	ExitOnGLError("ERROR: Could not generate the VAO");
	glBindVertexArray(_vao);
	ExitOnGLError("ERROR: Could not bind the VAO");

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	ExitOnGLError("ERROR: Could not enable vertex attributes");


	glGenBuffers(1, &_vbo);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	ExitOnGLError("ERROR: Could not bind BUFFer");
	glBufferData(GL_ARRAY_BUFFER, _vertixCount * sizeof (Vertex), _vertices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the VBO to the VAO");

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) (sizeof (GL_FLOAT)*4));
	ExitOnGLError("ERROR: Could not set VAO attributes");

	glGenBuffers(1, &_ibo);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indicesCount * sizeof (GLfloat), _indices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the IBO to the VAO");
	glBindVertexArray(0);

	glUseProgram(0);
}


void Model::bind(){
	//Texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->get_texture());
	glUniform1i(this->getShader()->getTextureUniform(), /*GL_TEXTURE*/0);
	ExitOnGLError("ERROR: Could not set the model shader texture uniforms");

	glBindVertexArray(this->get_vao());
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");

}

void Model::unbind(){

	glBindVertexArray(0);
	glUseProgram(0);
}


void getParams(string line, vector<int>& vec){
	int old = 0;
	int c = 0;
	while (c < line.length()){
		c = line.find(" ",old+1);
		if (c > old){
			vec.push_back(strToInt(string(line,old,c-old)));
		}
		old = c;
		//cerr<<line[c]<<endl;
	}
}

void getParams(string line, vector<float>& vec){
	int old = 0;
	int c = 0;
	while (c < line.length()){
		c = line.find(" ",old+1);
		if (c > old){
			vec.push_back(strToFloat(string(line,old,c-old)));
		}
		old = c;
		//cerr<<line[c]<<endl;
	}
}



void Model::createFromFile(string filePath) {
	string line;
	ifstream myfile(filePath.c_str());
	
	vector<int> texCoordIndex;
	vector<int> coordIndex;
	
	vector<float> verticesPoints;
	vector<float> TextureCoordinate;
	
	string parsing = "";
	if (myfile.is_open()) {
		while (myfile.good()) {
			getline(myfile, line);
			if (line.find("coordIndex") != string::npos && parsing == ""){
				string line2 = string(line,line.find("\"")+1,line.rfind("\"")-line.find("\"") -1);
				getParams(line2,coordIndex);
			}
			if (line.find("texCoordIndex") != string::npos && parsing == ""){
				string line2 = string(line,line.find("\"")+1,line.rfind("\"")-line.find("\"") -1);
				getParams(line2,texCoordIndex);
			}
			if (line.find("point") != string::npos && parsing == "Coordinate"){
				string line2 = string(line,line.find("\"")+1,line.rfind("\"")-line.find("\"") -1);
				getParams(line2,verticesPoints);
			}
			if (line.find("TextureCoordinate point") != string::npos && parsing == "" ){
				string line2 = string(line,line.find("\"")+1,line.rfind("\"")-line.find("\"") -1);
				getParams(line2,TextureCoordinate);
			}
			if (line.find("Coordinate") != string::npos && parsing == ""){
				parsing = "Coordinate";
			}
			if (line.find("/>") != string::npos && parsing == "Coordinate"){
				parsing = "";
			}
			//cout << line << endl;
		}
		myfile.close();
	}
	_vertixCount = 0;
	for (int j = 0  ;j < coordIndex.size() ;j++){
		if (coordIndex[j] != -1){
			_vertixCount++;
		}
	}
	_vertices = new Vertex[_vertixCount];
	int vcount = 0;
	int gvcount = 0;
	list<int> indices;
	
	int firstIndice = 0;
	for (int j = 0  ;j < coordIndex.size() ;j++){
		
		if (coordIndex[j] != -1){
			vcount++;
			//cerr<<"vertix     "<<gvcount<<endl;
			//cerr<<"coordindex "<<coordIndex[j]<<endl;
			for (int i = 0 ; i< 3; i++){
				_vertices[gvcount].Position[i] = verticesPoints[(coordIndex[j]*3) + i]*4;
			}
			_vertices[gvcount].Position[3] = 1;
			for(int i = 0 ; i < 2;i++)
				_vertices[gvcount].Tex[i] = TextureCoordinate[(texCoordIndex[j]*2)+i];

			if (vcount >= 3){
			//	cerr<<firstIndice<<endl;
			//	cerr<<gvcount-1<<endl;
			//	cerr<<gvcount<<endl;
			//	cerr<<endl;
				indices.push_back(firstIndice);
				indices.push_back(gvcount-1);
				indices.push_back(gvcount);
			}
			gvcount++;
		}else{
			vcount = 0;
			firstIndice = gvcount;
		}
	}
	/*
	for(int i = 0 ; i < _vertixCount;i++){
		for(int j = 0; j < 4;j++)
			cerr<<_vertices[i].Position[j]<<" ";
		for(int j = 0; j < 2;j++)
			cerr<<_vertices[i].Tex[j]<<" ";
		cerr<<endl;
	}
	cerr<<endl;
	*/
	_indicesCount = indices.size();
	_indices = new GLuint[_indicesCount];
	int i = 0;
	for(list<int>::iterator it = indices.begin();it != indices.end(); it++){
		_indices[i] = *it;
		i++;
	}
	
}

Model::~Model() {
}

