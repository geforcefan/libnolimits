#ifndef LIBNOLIMITS_NOLIMITS_TRACK_H
#define LIBNOLIMITS_NOLIMITS_TRACK_H

#include <ostream>
#include "../Stream/Chunk.h"
#include "Info/Version.h"
#include "Track/Track.h"

namespace NoLimits {
    namespace NoLimits1 {
        class NoLimitsTrack : public Stream::Chunk {
        public:
            NoLimitsTrack() {
                setVersion(new Version());
                setTrack(new Track());
            }

            void debug() {
                getVersion()->debug();
                getTrack()->debug();
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            NoLimitsTrack(std::string filepath);
            void save(std::string filepath);

            Version *getVersion() const;
            void setVersion(Version *value);

            bool getUse16Friction() const;
            void setUse16Friction(bool value);

            Track *getTrack() const;
            void setTrack(Track *value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "NLIM"; }
            /*! \endcond */

        private:
            Version *version;
            bool use16Friction;

            Track *track;
        };
    }
}


#endif //LIBNOLIMITS_NOLIMITS_TRACK_H
