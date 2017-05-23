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

            SpecialTrack() : Track(TrackType::SpecialTrack), _specialTrackType(SpecialTrackType::None) { }
            SpecialTrack(SpecialTrackType specialTrackType) : Track(TrackType::SpecialTrack), _specialTrackType(specialTrackType) { }

            void read(File::File *file) final;
            void write(File::File *file) final;

            virtual void readSpecialTrack(File::File *file) {}
            virtual void writeSpecialTrack(File::File *file) {}

            SpecialTrackType getSpecialTrackType() const;
            void setSpecialTrackType(const SpecialTrackType &specialTrackType);

            std::string getName() const;
            void setName(const std::string &value);

            glm::vec3 getPosition() const;
            void setPosition(const glm::vec3 &value);

            glm::vec3 getRotation() const;
            void setRotation(const glm::vec3 &value);

            std::vector<uint32_t> getInput() const;
            void insertInput(uint32_t value);

            std::vector<uint32_t> getOutput() const;
            void insertOutput(uint32_t value);

            float getSwitchTime() const;
            void setSwitchTime(float value);

            static SpecialTrack *createSpecialTrackFromType(SpecialTrackType specialTrackType);

            std::string getChunkName() final { return "SPTK"; }
            virtual std::string getSpecialTrackChunkName() { return "CHNK"; }

            std::vector<Segment *> getSegment() const;
            void insertSegment(Segment* value);

        private:
            SpecialTrackType _specialTrackType;

            std::string name;

            glm::vec3 position;
            glm::vec3 rotation;

            std::vector<uint32_t> input;
            std::vector<uint32_t> output;

            float switchTime;

            std::vector<Segment*> segment;
        };
    }
}

#endif // LIB_NL2PARK_SPECIAL_TRACK_H
