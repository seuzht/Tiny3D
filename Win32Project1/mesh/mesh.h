/*
 * mesh.h
 *
 *  Created on: 2017-4-2
 *      Author: a
 */

#ifndef MESH_H_
#define MESH_H_

#include "../maths/Maths.h"
#include <vector>
#include <string>

struct FaceBuf {
	int start, count;
	FaceBuf(int s, int n) :start(s), count(n) {}
	FaceBuf* copy() {
		return new FaceBuf(start, count);
	}
};

class Mesh {
private:
	virtual void initFaces()=0;
private:
	std::string name;
public:
	int vertexCount,indexCount;
	vec4* vertices;
	vec3* vertices3;
	vec3* normals;
	vec4* normals4;
	vec3* tangents;
	vec2* texcoords;
	int* materialids;
	int* indices;
	bool isBillboard, drawShadow;
	float* bounding;
	std::vector<FaceBuf*> singleFaces;
	std::vector<FaceBuf*> normalFaces;
public:
	Mesh();
	Mesh(const Mesh& rhs);
	virtual ~Mesh();
	void caculateExData();
	void setIsBillboard(bool billboard);
	void setAllSingle();
	void setAllNormal();
	std::string getName() { return name; }
	void setName(std::string value) { name = value; }
	void clearFaceBuf();
private:
	void caculateBounding();
private:
	vec3 boundScale;
public:
	void setBoundScale(const vec3& size) { boundScale = size; }
	vec3 getBoundScale() { return boundScale; }
};


#endif /* MESH_H_ */
