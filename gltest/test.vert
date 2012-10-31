
attribute vec2 Index;
attribute vec2 Weight;

uniform mat4 Bone[10];

varying vec3 N;

void main(void)  
{     
   vec4 newVertex;
   vec4 newNormal;
   int index;
   //-----------------------
   index=int(Index.x);    //Cast to int
   newVertex = (Bone[index] * gl_Vertex) * Weight.x;
   newNormal = (Bone[index] * vec4(gl_Normal, 0.0)) * Weight.x;
   index=int(Index.y);    //Cast to int
   newVertex = (Bone[index] * gl_Vertex) * Weight.y + newVertex;
   newNormal = (Bone[index] * vec4(gl_Normal, 0.0)) * Weight.y + newNormal;
   N = vec3(gl_ModelviewMatrix * newNormal);
   gl_Position = gl_ModelViewProjectionMatrix  * newVertex;


 
}
          