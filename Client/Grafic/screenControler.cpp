/* 
 * File:   screenControler.cpp
 * Author: karsten
 * 
 * Created on 16. juni 2013, 22:23
 */

#include "screenControler.h"
#include "../UI/UIMainFrame.h"
#include "../objects/CCreature.h"
#include "Grafic.h"


screenControler::screenControler() {
	
	SDL_EnableUNICODE(1);
	if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
	printf("Unable to initialize SDL: %s\n", SDL_GetError());
	//return 1;
	}
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1 ); // *new*
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	
	SDL_Surface* screen = SDL_SetVideoMode(Basewidth, Basehight, 24, SDL_OPENGL | SDL_HWSURFACE); // *changed*
	if(!screen){
		cerr<<"ERROR init SDL >"<<SDL_GetError()<<endl;
		exit(1);
	}
	glEnable(GL_DEPTH_TEST );

	
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
	
	_UIShaderProgram = initUIShaders();
	
	
	
	_projectionMatrix = CreateProjectionMatrix(
		60,
		(float)Basewidth / Basehight,
		1.0f,
		100.0f
	);
	Matrix _UiprojectionMatrix = CreateOthoMatrix(0,Basewidth,0,Basehight);
	
	_viewMatrix = IDENTITY_MATRIX;
	TranslateMatrix(&_viewMatrix, 0, 0, -80);

	_ObjShaderProgram = initObjShaders();
	
	textures[0] = loadTexture(Textures::Invalid);
	textures[1] = loadTexture(Textures::Invalid);
	
	cerr<<"INIT TEST MODEL"<<endl;
	Model* md = new Model(_ObjShaderProgram);
	_models.push_back(md);
	cerr<<"DONE INIT MODEL"<<endl;
	
	glUseProgram(_ObjShaderProgram->getProgramId());
	glUniformMatrix4fv(_ObjShaderProgram->getShaders()[0]->getVars()[ShaderProjectionMatrix], 1, GL_FALSE, _projectionMatrix.m);

	glUseProgram(_UIShaderProgram->getProgramId());
	glUniformMatrix4fv(_UIShaderProgram->getShaders()[0]->getVars()[ShaderProjectionMatrix], 1, GL_FALSE, _UiprojectionMatrix.m);

	//textures[Textures::Icons1] = loadTexture(Textures::Icons1);

	
	glUseProgram(0);
	
	cerr<<"END INIT"<<endl;
	
	
}

void screenControler::initScreen(){
	mainFrame = new UIMainFrame();
}

void screenControler::clickScreen(uint32_t x, uint32_t y){
	
	
	cerr<<"click X"<<x<<" Y "<<y<<endl;
	//float mouseclip[4] = {float(x) * 2 / float(Basewidth) - 1, 1 - float(y) * 2 / float(Basehight), 0, 1};
	glm::vec4 mouseclip = glm::vec4(float((float(x) * 2 / float(Basewidth) - 1)), float(1 - float(y) * 2 / float(Basehight)), 0.0f, 1.0f);
	glm::mat4 P = glm::make_mat4(_projectionMatrix.m);
	glm::mat4 C = glm::make_mat4(_viewMatrix.m);
	
	glm::vec4 mouseWorld = glm::inverse(P) * glm::inverse(C) * mouseclip;
	
	
	glm::vec4 n = glm::normalize(mouseWorld - glm::inverse(C)[3]);
	
	cerr<<n.x<<endl;
	cerr<<n.y<<endl;
	cerr<<n.z<<endl;
	cerr<<n.w<<endl;
}

void screenControler::drawScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glLoadIdentity();

// draw quad in screen coodinates

	glUseProgram(0);
	glDisable(GL_TEXTURE_2D);
	glLoadIdentity();
	mainFrame->updateUI();
	mainFrame->draw();
	glEnable(GL_TEXTURE_2D);
	//glUseProgram(_shaderProgram->getProgramId());
	for (map<uint32_t,CObj*>::iterator it = playerObj->getObjs().begin(); it != playerObj->getObjs().end();it++){
		if (it->second->getCreature())
			it->second->getCreature()->draw(it->second->getCreature());
	}

	SDL_GL_SwapBuffers();

}

screenControler::~screenControler() {
}

