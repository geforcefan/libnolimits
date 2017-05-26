#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string.h>
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>
#include <glm/glm.hpp>

/*! \cond INTERNAL */
namespace NoLimits {
    class Helper
    {
    public:
        static std::string leftTrim(std::string str);
        static std::string rightTrim(std::string str);
        static std::string trim(std::string str);
        static std::string debug(glm::vec2 v);
        static std::string debug(glm::vec3 v);
        static std::string debug(glm::vec4 v);

        static double kphToMs(double value);
        static double GToNewton(double value);
    };
}
/*! \endcond */

#endif // HELPER_H
