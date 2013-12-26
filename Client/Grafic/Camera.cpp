/* 
 * File:   Camera.cpp
 * Author: karsten
 * 
 * Created on 5. oktober 2013, 22:18
 */

#include "Camera.h"
#include "../objects/CObj.h"
Camera::Camera() {
	_cx = 0;
	_cy = 0;
	_relVec = glm::mat4();
	//_relVec = glm::translate(_relVec,glm::vec3(0,0,80.0f));
}
void Camera::setLookat(glm::vec3 eye,glm::vec3 center, glm::vec3 up){
	_viewMatrix = glm::lookAt(eye,center,up);
	_position = eye;
	_right = glm::cross((eye-center),up);	
}


void Camera::updateCamera(){
	if (!playerObj->getObjs()[1])// TODO fix get follow object 
		return;
	
	glm::vec3 objPos = glm::vec3((float)playerObj->getObjs()[1]->getPos().x/1000, (float)playerObj->getObjs()[1]->getPos().y/1000, (float)playerObj->getObjs()[1]->getPos().z/1000);
 
	glm::vec3 camRelVec = glm::vec3(this->_relVec * glm::vec4(0,0,80,1));
	
	
	//cerr<<camRelVec.x<<" "<<camRelVec.z<<" "<<camRelVec.z<<endl;
	this->setLookat(objPos + camRelVec,objPos,glm::vec3(0,-1,0));
	
}

Camera::~Camera() {
}

