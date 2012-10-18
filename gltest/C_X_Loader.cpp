#include "C_X_Loader.h"
#include "CMesh.h"
#include "C_X_ReaderBase.h"
#include "C_X_ReaderMesh.h"

CMesh* Lload(string file){
	CMesh* mesh = NULL;
	list<C_X_ReaderBase*> nowReading;
	ifstream reader(file.c_str());
	string line;
	C_X_ReaderBase* Xreader = NULL;
	while (std::getline((reader), line)) {

		if (line.find("//") != string::npos){
			line = line.substr(0,line.find("//"));
		}
		
		if(line.find("{") != string::npos){
			line = trim(line);
			line = line.substr(0,line.length()-1);
			line = trim(line);
			cerr<<"+"<<line<<endl;
			
			if(line == "Mesh"){
				nowReading.push_back(new C_X_ReaderMesh());
			}else if (line =="MeshNormals"){
				C_X_ReaderNormals* temp = new C_X_ReaderNormals();
				nowReading.back()->SetReaderNormal(temp);
				nowReading.push_back(temp);
			}else
				nowReading.push_back(NULL);
			
			continue;
		}
		if(line.find("}") != string::npos){
			if(nowReading.back() && !nowReading.empty()){
				cerr<<"-"<<nowReading.back()->Name()<<endl;
				if(nowReading.back()->Name() == "Mesh")
					mesh = nowReading.back()->getMesh();
				//delete nowReading.back();
			}
			
			nowReading.pop_back();
			continue;
		}
		
		
		if(nowReading.back() != NULL && !nowReading.empty()){
			nowReading.back()->ReadLine(line);
		}
	}

	return mesh;
}


