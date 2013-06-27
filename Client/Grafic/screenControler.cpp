/* 
 * File:   screenControler.cpp
 * Author: karsten
 * 
 * Created on 16. juni 2013, 22:23
 */

#include "screenControler.h"
#include "../objects/CCreature.h"
#include "Grafic.h"


screenControler::screenControler() {
	
	SDL_EnableUNICODE(1);
	if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
	printf("Unable to initialize SDL: %s\n", SDL_GetError());
	//return 1;
	}
	
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 ); // *new*
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_Surface* screen = SDL_SetVideoMode(Basewidth, Basehight, 24, SDL_OPENGL | SDL_HWSURFACE); // *changed*
	if(!screen){
		cerr<<"ERROR init SDL >"<<SDL_GetError()<<endl;
		exit(1);
	}
	

	
	GLenum GlewInitResult;

	
	glewExperimental = GL_TRUE;
	GlewInitResult = glewInit();

	if (GLEW_OK != GlewInitResult) {
		fprintf(
			stderr,
			"ERROR: %s\n",
			glewGetErrorString(GlewInitResult)
		);
		exit(EXIT_FAILURE);
	}
	
	fprintf(
		stdout,
		"INFO: OpenGL Version: %s\n",
		glGetString(GL_VERSION)
	);

	glGetError();
	
	
	cerr<<"INIT Grafic"<<endl;
	cerr<<"GL Version "<<glGetString(GL_VERSION)<<endl;
	
	_projectionMatrix = CreateProjectionMatrix(
		60,
		(float)Basewidth / Basehight,
		1.0f,
		100.0f
	);
	
	_viewMatrix = IDENTITY_MATRIX;
	TranslateMatrix(&_viewMatrix, 0, 0, -20);

	_shaderProgram = initShaders();
	
	cerr<<"INIT TEST MODEL"<<endl;
	Model* md = new Model(_shaderProgram);
	_models.push_back(md);
	cerr<<"DONE INIT MODEL"<<endl;
	
	glUseProgram(_shaderProgram->getProgramId());
	glUniformMatrix4fv(_shaderProgram->getShaders()[0]->getVars()[ShaderProjectionMatrix], 1, GL_FALSE, _projectionMatrix.m);
	glUseProgram(0);
	
	cerr<<"END INIT"<<endl;
	
	textures[Textures::Icons1] = loadTexture(Textures::Icons1);
	
}

void screenControler::drawScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glLoadIdentity();

// draw quad in screen coodinates


	//mainFrame->updateUI();
	//mainFrame->draw();

	for (map<uint32_t,CObj*>::iterator it = playerObj->getObjs().begin(); it != playerObj->getObjs().end();it++){
		if (it->second->getCreature())
			it->second->getCreature()->draw();
	}

	SDL_GL_SwapBuffers();

}

screenControler::~screenControler() {
}

