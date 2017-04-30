#include "Helper.h"
#include <string>
#include <sstream>

std::string Helper::leftTrim(std::string str) {
    int numStartSpaces = 0;
    for (unsigned long i = 0; i < str.length(); i++) {
        if (!isspace(str[i])) break;
        numStartSpaces++;
    }
    return str.substr(numStartSpaces);
}

std::string Helper::rightTrim(std::string str) {
    int numEndSpaces = 0;
    for (long i = str.length() - 1; i >= 0; i--) {
        if (!isspace(str[i])) break;
        numEndSpaces++;
    }
    return str.substr(0, str.length() - numEndSpaces);
}

std::string Helper::trim(std::string str) {
    return Helper::rightTrim(Helper::leftTrim(str));
}

std::string Helper::debug(glm::vec2 v) {
    std::stringstream s;
    s << "vec2[" << v.x << ", " << v.y << "]";
    return s.str();
}

std::string Helper::debug(glm::vec3 v) {
    std::stringstream s;
    s << "vec3[" << v.x << ", " << v.y << ", " << v.z << "]";
    return s.str();
}

std::string Helper::debug(glm::vec4 v) {
    std::stringstream s;
    s << "vec4[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
    return s.str();
}
