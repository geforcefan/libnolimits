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

            RailNode() : SupportNode() {
                setPosition(0.0f);
                setSizeParameter(0.0f);
                setTrackIndex(0);
                setConnectionStyle(ConnectionStyle::TrackDefault);
                setIsModel(0);
                setPrefabIndex(0);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                SupportNode::debug();

                std::cout << "RailNode[getPosition]: " << getPosition() << std::endl;
                std::cout << "RailNode[getSizeParameter]: " << getSizeParameter() << std::endl;
                std::cout << "RailNode[getTrackIndex]: " << getTrackIndex() << std::endl;
                std::cout << "RailNode[getConnectionStyle]: " << getConnectionStyle() << std::endl;
                std::cout << "RailNode[getIsModel]: " << getIsModel() << std::endl;
                std::cout << "RailNode[getPrefabIndex]: " << getPrefabIndex() << std::endl;

                std::cout << "RailNode[vertex.size]: " << supportParameter.size() << std::endl;
                if(supportParameter.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < supportParameter.size(); i++) {
                    supportParameter[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

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

            std::vector<SupportParameter *> getSupportParameter() const;
            uint32_t insertSupportParameter(SupportParameter* value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "SRNP"; }
            /*! \endcond */
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
