/* 
 * File:   Camera.cpp
 * Author: karsten
 * 
 * Created on 5. oktober 2013, 22:18
 */

#include "Camera.h"

Camera::Camera() {
}
void Camera::setLookat(glm::vec3 eye,glm::vec3 center, glm::vec3 up){
	_viewMatrix = glm::lookAt(eye,center,up);
	_position = center;
			
}

Camera::~Camera() {
}

