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
#include "Shaders/UIShader.h"


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
	
	//INIT UI shader
	glm::mat4 _UiprojectionMatrix = glm::make_mat4(CreateOthoMatrix(0,Basewidth,0,Basehight).m);
	_UIShaderProgram = new UIShader();
	cerr<<(_UIShaderProgram->init()?"UI Shader Fail":"UI Shader OK")<<endl;
	_UIShaderProgram->enable();
	_UIShaderProgram->setProjectionMatrix(&_UiprojectionMatrix);

	
	//INIT object shader
	_projectionMatrix = glm::make_mat4(CreateProjectionMatrix(60,(float)Basewidth / Basehight,1.0f,100.0f).m);
	_viewMatrix = glm::lookAt(glm::vec3(-30,20,-60),glm::vec3(-30,20,0),glm::vec3(0,-1,0));
	_ObjShaderProgram = new ObjectShader();
	cerr<<(_ObjShaderProgram->init()?"Object Shader Fail":"Object Shader OK")<<endl;
	_ObjShaderProgram->enable();
	_ObjShaderProgram->setProjectionMatrix(&_projectionMatrix);
	_ObjShaderProgram->setViewMatrix(&_viewMatrix);
	textures[0] = loadTexture(Textures::Invalid);
	textures[1] = loadTexture(Textures::Invalid);
	
	cerr<<"INIT TEST MODEL"<<endl;
	Model* md = new Model(_ObjShaderProgram);
	_models.push_back(md);
	cerr<<"DONE INIT MODEL"<<endl;


	//textures[Textures::Icons1] = loadTexture(Textures::Icons1);

	
	glUseProgram(0);
	
	cerr<<"END INIT"<<endl;
	
	
}

void screenControler::initScreen(){
	mainFrame = new UIMainFrame();
}

void screenControler::clickScreen(uint32_t x, uint32_t y){
	
	
	cerr<<"click X "<<x<<" Y "<<y<<endl;
	//float mouseclip[4] = {float(x) * 2 / float(Basewidth) - 1, 1 - float(y) * 2 / float(Basehight), 0, 1};
	//glm::vec4 mouseclip = glm::vec4(float((float(x) * 2 / float(Basewidth) - 1)), float(1 - float(y) * 2 / float(Basehight)), 0.0f, 1.0f);
	
	glm::vec4 lRayStart_NDC(
    ((float)x/(float)Basewidth  - 0.5f) * 2.0f,
    (((float)y/(float)Basehight - 0.5f) * -2.0f),
    -1.0, // The near plane maps to Z=-1 in Normalized Device Coordinates
    1.0f
	);
	glm::vec4 lRayEnd_NDC(
    ((float)x/(float)Basewidth  - 0.5f) * 2.0f,
    (((float)y/(float)Basehight - 0.5f) * -2.0f),
    0.0,
    1.0f
	);
	
	glm::mat4 C = glm::inverse(_viewMatrix);
	glm::mat4 InverseProjectionMatrix = glm::inverse(_projectionMatrix);
	glm::mat4 InverseViewMatrix = glm::inverse(_viewMatrix);

	glm::vec4 lRayStart_camera = InverseProjectionMatrix * lRayStart_NDC;    lRayStart_camera/=lRayStart_camera.w;
	glm::vec4 lRayStart_world  = InverseViewMatrix       * lRayStart_camera; lRayStart_world /=lRayStart_world.w;

	glm::vec4 lRayEnd_camera   = InverseProjectionMatrix * lRayEnd_NDC;      lRayEnd_camera  /=lRayEnd_camera.w;
	glm::vec4 lRayEnd_world    = InverseViewMatrix       * lRayEnd_camera;   lRayEnd_world   /=lRayEnd_world.w;
 
	
	glm::vec3 mouseWorld3(lRayEnd_world - lRayStart_world);
	//mouseWorld3 = glm::normalize(mouseWorld3);

	cerr<<"mouse "<<mouseWorld3.x<<endl;
	cerr<<"mouse "<<mouseWorld3.y<<endl;
	cerr<<"mouse "<<mouseWorld3.z<<endl;

	cerr<<"cam "<<C[3][0]<<endl;
	cerr<<"cam "<<C[3][1]<<endl;
	cerr<<"cam "<<C[3][2]<<endl;
	cerr<<"cam "<<C[3][3]<<endl;
	
	glm::mat2x3 ray = glm::mat2x3(C[3].xyz(),mouseWorld3);
	
	
	for (map<uint32_t,CObj*>::iterator it = playerObj->getObjs().begin(); it != playerObj->getObjs().end();it++){
		if (it->second->getCreature())
			it->second->getCreature()->rayIntersect(it->second->getCreature(),ray);
	}
	
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

