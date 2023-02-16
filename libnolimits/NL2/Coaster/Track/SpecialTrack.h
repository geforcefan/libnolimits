#ifndef LIB_NL2PARK_SPECIAL_TRACK_H
#define LIB_NL2PARK_SPECIAL_TRACK_H

#include <vector>

#include "../../../Stream/Chunk.h"
#include "Track.h"
#include "Segment.h"

namespace NoLimits {
    namespace NoLimits2 {
        class SpecialTrack: public Track  {
        public:
            enum SpecialTrackType {
                None,
                SwitchTrackFork,
                SwitchTrackMerge,
                Transfer
            };

            enum DisplayStructure {
                Simple,
                Off
            };

            SpecialTrack() : Track(TrackType::SpecialTrack), _specialTrackType(SpecialTrackType::None) {}

            SpecialTrack(SpecialTrackType specialTrackType) : Track(TrackType::SpecialTrack), _specialTrackType(specialTrackType) {
                setSwitchTime(0.0f);
            }

            /*! \cond INTERNAL */
            void read(File::File *file) final;
            void write(File::File *file) final;

            virtual void readSpecialTrack(File::File *file) {}
            virtual void writeSpecialTrack(File::File *file) {}
            /*! \endcond */

            void debug() {
                Track::debug();

                std::cout << "SpecialTrack[getSpecialTrackType]: " << getSpecialTrackType() << std::endl;
                std::cout << "SpecialTrack[getName]: " << getName() << std::endl;
                std::cout << "SpecialTrack[getPosition]: " << Helper::debug(getPosition()) << std::endl;
                std::cout << "SpecialTrack[getRotation]: " << Helper::debug(getRotation()) << std::endl;
                std::cout << "SpecialTrack[getSwitchTime]: " << getSwitchTime() << std::endl;

                std::cout << "SpecialTrack[input.size]: " << input.size() << std::endl;
                if(!input.empty())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < input.size(); i++) {
                    std::cout << "SpecialTrack[input][" << i << "]: " << input[i] << std::endl;
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "SpecialTrack[output.size]: " << output.size() << std::endl;
                if(!output.empty())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < output.size(); i++) {
                    std::cout << "SpecialTrack[output][" << i << "]: " << output[i] << std::endl;
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "SpecialTrack[segment.size]: " << segment.size() << std::endl;
                if(!segment.empty())
                    std::cout << "---------------------------------------" << std::endl;
                for(auto & i : segment) {
                    i->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            SpecialTrackType getSpecialTrackType() const;
            void setSpecialTrackType(const SpecialTrackType &specialTrackType);

            std::string getName() const;
            void setName(const std::string &value);

            glm::dvec3 getPosition() const;
            void setPosition(const glm::dvec3 &value);

            glm::dvec3 getRotation() const;
            void setRotation(const glm::dvec3 &value);

            std::vector<uint32_t> getInput() const;
            uint32_t insertInput(uint32_t value);

            std::vector<uint32_t> getOutput() const;
            uint32_t insertOutput(uint32_t value);

            float getSwitchTime() const;
            void setSwitchTime(float value);

            std::vector<Segment *> getSegment() const;
            uint32_t insertSegment(Segment* value);

            static SpecialTrack *createSpecialTrackFromType(SpecialTrackType specialTrackType);

            /*! \cond INTERNAL */
            std::string getChunkName() final { return "SPTK"; }
            virtual std::string getSpecialTrackChunkName() { return "CHNK"; }
            /*! \endcond */
        private:
            SpecialTrackType _specialTrackType;

            std::string name;

            glm::dvec3 position = glm::dvec3(0.0f);
            glm::dvec3 rotation = glm::dvec3(0.0f);

            std::vector<uint32_t> input;
            std::vector<uint32_t> output;

            float switchTime = 15.0f;

            std::vector<Segment*> segment;
        };
    }
}

#endif // LIB_NL2PARK_SPECIAL_TRACK_H
