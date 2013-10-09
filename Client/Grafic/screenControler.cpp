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
#include "Camera.h"


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
	
	_camera = new Camera();
	
	//INIT UI shader
	glm::mat4 _UiprojectionMatrix = glm::make_mat4(CreateOthoMatrix(0,Basewidth,0,Basehight).m);
	_UIShaderProgram = new UIShader();
	cerr<<(_UIShaderProgram->init()?"UI Shader Fail":"UI Shader OK")<<endl;
	_UIShaderProgram->enable();
	_UIShaderProgram->setProjectionMatrix(&_UiprojectionMatrix);

	_UIPrimShader = new UIPrimShader();
	cerr<<(_UIPrimShader->init()?"UI Prim Shader Fail":"UI Prim Shader OK")<<endl;
	_UIPrimShader->enable();
	_UIPrimShader->setProjectionMatrix(&_UiprojectionMatrix);
	
	//INIT object shader
	
	_camera->setLookat(glm::vec3(0,0,-60),glm::vec3(0,0,0),glm::vec3(0,-1,0));
	_projectionMatrix = glm::make_mat4(CreateProjectionMatrix(30,(float)Basewidth / Basehight,1.0f,1000.0f).m);
	
	_camera->setProjectionMatrix(_projectionMatrix);
	
	_ObjShaderProgram = new ObjectShader();
	cerr<<(_ObjShaderProgram->init()?"Object Shader Fail":"Object Shader OK")<<endl;
	_ObjShaderProgram->enable();
	_ObjShaderProgram->setProjectionMatrix(&_projectionMatrix);
	_ObjShaderProgram->setViewMatrix(_camera->getViewMatrix());
	textures[0] = loadTexture(Textures::Invalid);
	textures[1] = loadTexture(Textures::Invalid);
	
	
	cerr<<"INIT Partical Engine"<<endl;
	_particalEngine = new ParticalEngine();
	_particalEngine->InitParticleEngine();
	
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
	
	if (mainFrame->click(x,y)){
		cerr<<"UI click"<<endl;
		return;
	}
	
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
	
	glm::mat4 C = glm::inverse(*_camera->getViewMatrix());
	glm::mat4 InverseProjectionMatrix = glm::inverse(_projectionMatrix);
	glm::mat4 InverseViewMatrix = glm::inverse(*_camera->getViewMatrix());

	glm::vec4 lRayStart_camera = InverseProjectionMatrix * lRayStart_NDC;    lRayStart_camera/=lRayStart_camera.w;
	glm::vec4 lRayStart_world  = InverseViewMatrix       * lRayStart_camera; lRayStart_world /=lRayStart_world.w;

	glm::vec4 lRayEnd_camera   = InverseProjectionMatrix * lRayEnd_NDC;      lRayEnd_camera  /=lRayEnd_camera.w;
	glm::vec4 lRayEnd_world    = InverseViewMatrix       * lRayEnd_camera;   lRayEnd_world   /=lRayEnd_world.w;
	
	glm::vec3 mouseWorld3(lRayEnd_world - lRayStart_world);

	glm::mat2x3 ray = glm::mat2x3(C[3].xyz(),mouseWorld3);

	for (map<uint32_t,CObj*>::iterator it = playerObj->getObjs().begin(); it != playerObj->getObjs().end();it++){
		if (it->second->getCreature())
			it->second->getCreature()->rayIntersect(it->second->getCreature(),ray);
	}
	
}

void screenControler::drawScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glUseProgram(0);

	mainFrame->updateUI(); //update all ui objects
	mainFrame->draw(); //draw all ui objects

	//draw 3d objecs on screen
	for (map<uint32_t,CObj*>::iterator it = playerObj->getObjs().begin(); it != playerObj->getObjs().end();it++){
		if (it->second->getCreature())
			it->second->getCreature()->draw(it->second->getCreature());
	}

	SDL_GL_SwapBuffers();

}

screenControler::~screenControler() {
}

