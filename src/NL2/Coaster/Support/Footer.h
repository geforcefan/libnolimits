#ifndef LIB_NL2PARK_FOOTER_H
#define LIB_NL2PARK_FOOTER_H

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
        class Footer : public Stream::Chunk {
        public:
            enum BaseStyle {
                SteelSquare = 0,
                SteelRound = 1,
                WoodSquare = 2,
                WoodRound = 3
            };

            enum ConnectionStyle {
                Simple = 0,
                ExtendedA = 1,
                ExtendedB = 2
            };

            enum ColorMode {
                Custom = 0,
                Support = 16,
                Handrail = 32,
                Catwalk = 48,
                Spine = 64
            };

            Footer() {}

            void read(File::File *file);
            void write(File::File *file);

            glm::vec3 getPosition() const;
            void setPosition(const glm::vec3 &value);

            float getRotationAngle() const;
            void setRotationAngle(float value);

            float getAboveGround() const;
            void setAboveGround(float value);

            BaseStyle getBaseStyle() const;
            void setBaseStyle(const BaseStyle &value);

            ConnectionStyle getConnectionStyle() const;
            void setConnectionStyle(const ConnectionStyle &value);

            ColorMode getColorMode() const;
            void setColorMode(const ColorMode &value);

            glm::vec3 getCustomColor() const;
            void setCustomColor(const glm::vec3 &value);

        private:
            glm::vec3 position;

            float rotationAngle;
            float aboveGround;

            BaseStyle baseStyle;
            ConnectionStyle connectionStyle;

            ColorMode colorMode;
            glm::vec3 customColor;
        };
    }
}

#endif // LIB_NL2PARK_FOOTER_H
