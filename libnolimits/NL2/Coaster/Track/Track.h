#ifndef LIB_NL2PARK_TRACK_H
#define LIB_NL2PARK_TRACK_H

#include "../../../Stream/Chunk.h"
#include "Section/Section.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Track : public Stream::Chunk {
        public:
            enum TrackType {
                None,
                Custom,
                SpecialTrack
            };

            Track(TrackType _trackType) : trackType(_trackType) {}
            Track() : trackType(TrackType::None) {}
            TrackType getTrackType() const;
            void setTrackType(const TrackType &value);
            virtual Section *getSectionByName(std::string name) { return nullptr; }

            /*! \cond INTERNAL */
            virtual void debug() {
                std::cout << "Track[getTrackType]: " << getTrackType() << std::endl;
            }
            /*! \endcond */
        private:
            TrackType trackType;
        };
    }
}

#endif // TRACK_H
