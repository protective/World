/* 
 * File:   Camera.h
 * Author: karsten
 *
 * Created on 5. oktober 2013, 22:18
 */

#ifndef CAMERA_H
#define	CAMERA_H
#include "../GLutil.h"

class Camera {
public:
	Camera();
	
	void setLookat(glm::vec3 _eye,glm::vec3 center, glm::vec3 up);
	glm::mat4* getViewMatrix(){return &_viewMatrix;}
	glm::mat4* getProjectionMatrix(){return &_projectionMatrix;}
	void setProjectionMatrix(glm::mat4 projection){_projectionMatrix = projection;}
	glm::vec3* getPosition(){return &_position;}
	virtual ~Camera();
private:
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
	glm::vec3 _position;
};

#endif	/* CAMERA_H */

