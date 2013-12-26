/* 
 * File:   Camera.h
 * Author: karsten
 *
 * Created on 5. oktober 2013, 22:18
 */

#ifndef CAMERA_H
#define	CAMERA_H
#include "../GLutil.h"
#include "../CFunctions.h"

class Camera {
public:
	Camera();
	
	void setLookat(glm::vec3 _eye,glm::vec3 center, glm::vec3 up);
	glm::mat4* getViewMatrix(){return &_viewMatrix;}
	glm::mat4* getProjectionMatrix(){return &_projectionMatrix;}
	void setProjectionMatrix(glm::mat4 projection){_projectionMatrix = projection;}
	glm::vec3* getPosition(){return &_position;}
	glm::mat4* getRelVec(){return &_relVec;}
	glm::vec3* getRight(){return &_right;}
		
		void setRelVec(glm::mat4 relVec){_relVec = relVec;}
        void updateCamera();
        float _cx,_cy;
	virtual ~Camera();
private:
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
	glm::vec3 _position;
    glm::mat4 _relVec;    
	glm::vec3 _right;
};

#endif	/* CAMERA_H */

