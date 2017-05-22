#ifndef LIB_NL2PARK_RAILNODE_H
#define LIB_NL2PARK_RAILNODE_H

#include "../../../Stream/Chunk.h"
#include "SupportNode.h"
#include "SupportParameter.h"
#include <vector>

namespace NoLimits {
    namespace NoLimits2 {
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
                Prefab
            };

            RailNode() { }

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

            uint32_t getPrefabIndex() const;
            void setPrefabIndex(const uint32_t &value);

            std::string getChunkName() { return "SRNP"; }

            std::vector<SupportParameter *> getSupportParameter() const;
            void insertSupportParameter(SupportParameter* value);

        private:
            ConnectionStyle connectionStyle;
            double position;
            double sizeParameter;
            uint32_t trackIndex;
            bool isModel;

            uint32_t prefabIndex;

            std::vector<SupportParameter*> supportParameter;
        };
    }
}

#endif // LIB_NL2PARK_RAILNODE_H
