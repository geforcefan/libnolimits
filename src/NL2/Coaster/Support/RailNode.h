#ifndef LIB_NL2PARK_RAILNODE_H
#define LIB_NL2PARK_RAILNODE_H

#include <Stream/Chunk.h>
#include <src/NL2/Coaster/Support/SupportNode.h>
#include "SPPM.h"

namespace NoLimits {
    namespace NL2 {
        class RailNode : public Stream::Chunk, public SupportNode {
        public:
            enum ConnectionStyle {
                TrackDefault,
                Simple,
                CorkscrewStraightDown,
                TwistedStraightDown,
                TwistedHorizontal,
                TwistedVertical,
                Horizontal4D,
                Vertical4D ,
                Aligned4D,
                Special4D,
                SuspendedHorizontal,
                SuspendedVertical,
            };

            RailNode() {
                sppm = new SPPM();
            }

            void read(File::File *file);
            void write(File::File *file);

            double getPosition() const;
            void setPosition(double value);

            double getSizeParameter() const;
            void setSizeParameter(double value);

            uint32_t getTrackIndex() const;
            void setTrackIndex(const uint32_t &value);

            ConnectionStyle getConnectionStyle() const;
            void setConnectionStyle(const ConnectionStyle &value);

            bool getIsModel() const;
            void setIsModel(bool value);

            SPPM *getSppm() const;
            void setSppm(SPPM *value);

            std::string getChunkName() { return "SRNP"; }
        private:
            ConnectionStyle connectionStyle;
            double position;
            double sizeParameter;
            uint32_t trackIndex;
            bool isModel;

            SPPM* sppm;
        };
    }
}

#endif // LIB_NL2PARK_RAILNODE_H
