/* 
 * File:   C_X_ReaderBase.h
 * Author: karsten
 *
 * Created on 16. oktober 2012, 23:04
 */

#ifndef C_X_READERBASE_H
#define	C_X_READERBASE_H
#include "C_X_Loader.h"
class CMesh;
class C_X_ReaderBase {
public:
	C_X_ReaderBase();
	virtual void ReadLine(string line){}
	virtual CMesh* getMesh(){return NULL;}
	virtual string Name(){}
private:

};

#endif	/* C_X_READERBASE_H */

