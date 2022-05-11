#include "Things.h"

Things::Things(const std::vector<std::string>& fileNames) : 
	images(fileNames.begin(), fileNames.end()) {

}
