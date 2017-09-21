#include "Particle.h"

Particle::Particle() : Particle(ofVec3f(0, 0, 0), 10, ofColor(ofColor(255))) {

}

Particle::Particle(ofVec3f location, float radius, ofColor body_color) {
	this->location = location;
	this->radius = radius - 1.1;
	this->height = 0;
	this->body_color = body_color;
}

Particle::~Particle() {

}


void Particle::update(float height) {
	this->height = height;
	this->body_color.setHsb(this->height / 300 * 255, 255, 255);
}

void Particle::draw() {
	ofPushMatrix();
	ofTranslate(this->location);
	ofTranslate(0, 0, this->location.z);
	ofNoFill();

	ofSetColor(this->body_color);
	
	//ofMesh mesh;
	ofVboMesh mesh;

	float x, y;
	for (int i = 0; i < 360; i += 60) {
		x = this->radius * cos(DEG_TO_RAD * (i + 90));
		y = this->radius * sin(DEG_TO_RAD * (i + 90));
		mesh.addVertex(ofVec3f(x, y, 0));
	}

	for (int i = 0; i < 360; i += 60) {
		x = this->radius * cos(DEG_TO_RAD * (i + 90));
		y = this->radius * sin(DEG_TO_RAD * (i + 90));
		mesh.addVertex(ofVec3f(x, y, this->height));
	}

	// ã–Ê
	 
	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(5);

	mesh.addIndex(1);
	mesh.addIndex(4);
	mesh.addIndex(5);

	mesh.addIndex(1);
	mesh.addIndex(2);
	mesh.addIndex(4);

	mesh.addIndex(2);
	mesh.addIndex(3);
	mesh.addIndex(4);

	// ‰º–Ê

	mesh.addIndex(6);
	mesh.addIndex(7);
	mesh.addIndex(11);

	mesh.addIndex(7);
	mesh.addIndex(10);
	mesh.addIndex(11);

	mesh.addIndex(7);
	mesh.addIndex(8);
	mesh.addIndex(9);

	mesh.addIndex(8);
	mesh.addIndex(9);
	mesh.addIndex(10);

	// ‘¤–Ê

	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(6);

	mesh.addIndex(6);
	mesh.addIndex(7);
	mesh.addIndex(1);

	mesh.addIndex(1);
	mesh.addIndex(2);
	mesh.addIndex(7);

	mesh.addIndex(7);
	mesh.addIndex(8);
	mesh.addIndex(2);

	mesh.addIndex(2);
	mesh.addIndex(3);
	mesh.addIndex(8);

	mesh.addIndex(8);
	mesh.addIndex(9);
	mesh.addIndex(3);

	mesh.addIndex(3);
	mesh.addIndex(4);
	mesh.addIndex(9);

	mesh.addIndex(9);
	mesh.addIndex(10);
	mesh.addIndex(4);

	mesh.addIndex(4);
	mesh.addIndex(5);
	mesh.addIndex(10);

	mesh.addIndex(10);
	mesh.addIndex(11);
	mesh.addIndex(5);

	mesh.addIndex(5);
	mesh.addIndex(0);
	mesh.addIndex(11);

	mesh.addIndex(11);
	mesh.addIndex(6);
	mesh.addIndex(0);

	mesh.draw();

	ofSetColor(255);

	//

	ofBeginShape();
	ofVertex(mesh.getVertex(0));
	ofVertex(mesh.getVertex(1));
	ofVertex(mesh.getVertex(2));
	ofVertex(mesh.getVertex(3));
	ofVertex(mesh.getVertex(4));
	ofVertex(mesh.getVertex(5));
	ofEndShape(true);

	ofBeginShape();
	ofVertex(mesh.getVertex(6));
	ofVertex(mesh.getVertex(7));
	ofVertex(mesh.getVertex(8));
	ofVertex(mesh.getVertex(9));
	ofVertex(mesh.getVertex(10));
	ofVertex(mesh.getVertex(11));
	ofEndShape(true);

	ofLine(mesh.getVertex(0), mesh.getVertex(6));
	ofLine(mesh.getVertex(1), mesh.getVertex(7));
	ofLine(mesh.getVertex(2), mesh.getVertex(8));
	ofLine(mesh.getVertex(3), mesh.getVertex(9));
	ofLine(mesh.getVertex(4), mesh.getVertex(10));
	ofLine(mesh.getVertex(5), mesh.getVertex(11));

	ofPopMatrix();
}

ofVec3f Particle::getLocation()
{
	return this->location;
}