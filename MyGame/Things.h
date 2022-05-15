#pragma once

#include "WindWheelReal.h"
#include <vector>

class Things {
public:
	Things(const std::vector< std::string> & fileNames);

	int GetX() const;
	int GetY() const;
	int GetZ() const;

	bool GetIsSolid() const;
	int GetIndexOfCurrentImage() const;
	int GetWidth() const;
	int GetHeight() const;

	void SetX(int newX);
	void SetY(int newY);
	void SetZ(int newZ);
	void SetIsSolid(bool newSolid);
	void SetIndexOfCurrentImage(int newIndex);

	void Draw();

private:
	int xPos{0};
	int yPos{0};
	int zPos{0};

	bool isSolid{true};
	int indexOfCurrentImage{0};

	std::vector<WWR::TwoDSprite> images;
};

