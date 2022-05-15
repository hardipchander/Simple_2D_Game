#include "Things.h"
#include "WindWheelReal.h"

Things::Things(const std::vector<std::string>& fileNames) : 
	images(fileNames.begin(), fileNames.end()) {

}

int Things::GetX() const
{
	return xPos;
}

int Things::GetY() const
{
	return yPos;
}

int Things::GetZ() const
{
	return zPos;
}

bool Things::GetIsSolid() const
{
	return isSolid;
}

int Things::GetIndexOfCurrentImage() const {
	return indexOfCurrentImage;
}

int Things::GetWidth() const {
	return images[indexOfCurrentImage].GetWidth();
}

int Things::GetHeight() const {
	return images[indexOfCurrentImage].GetHeight();
}

void Things::SetX(int newX) {
	xPos = newX;
}

void Things::SetY(int newY){
	yPos = newY;
}

void Things::SetZ(int newZ) {
	zPos = newZ;
}

void Things::SetIsSolid(bool newSolid) {
	isSolid = newSolid;
}

void Things::SetIndexOfCurrentImage(int newIndex) {
	indexOfCurrentImage = newIndex;
}

void Things::Draw() {
	WWR::SingleRenderer::Draw(images[indexOfCurrentImage], xPos, yPos, zPos);
}
