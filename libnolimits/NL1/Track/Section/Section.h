#ifndef LIB_NOLIMITS_NL1_SECTION_H
#define LIB_NOLIMITS_NL1_SECTION_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits1 {
        class Section: public Stream::Chunk {
        public:
            enum SectionType {
                Track,
                Station,
                Lift,
                Transport,
                Brake
            };

            enum SectionFlags {
                Tunnel,
                OwnColors,
                SpineStyle1,
                SpineStyle2,
                LeftRailing,
                RightRailing,
                LockSpin,
                UnlockSpin
            };

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);

            virtual void readSection(File::File *file) {}
            virtual void writeSection(File::File *file) {}
            /*! \endcond */

            SectionType getSectionType() const;
            void setSectionType(SectionType value);

            bool getUseIndividualTrackColor() const;
            void setUseIndividualTrackColor(bool useIndividualTrackColor);

            const glm::vec3 &getTrackSpineColor() const;
            void setTrackSpineColor(const glm::vec3 &trackSpineColor);

            const glm::vec3 &getTrackRailColor() const;
            void setTrackRailColor(const glm::vec3 &trackRailColor);

            const glm::vec3 &getTrackCrosstieColor() const;
            void setTrackCrosstieColor(const glm::vec3 &trackCrosstieColor);

            bool getUseTunnel() const;
            void setUseTunnel(bool useTunnel);

            static Section *createSectionFromType(SectionType sectionType);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "SEGM"; }
            /*! \endcond */

        protected:
            uint32_t getFlags2() const;
            void setFlags2(uint32_t segmentFlags);

        private:
            SectionType sectionType;

            bool useIndividualTrackColor;
            glm::vec3 trackSpineColor;
            glm::vec3 trackRailColor;
            glm::vec3 trackCrosstieColor;
            bool useTunnel;

            uint32_t flags1;
            uint32_t flags2;

            uint32_t getFlags1() const;
            void setFlags1(uint32_t segmentFlags);
        };
    }
}

#endif // LIB_NOLIMITS_NL1_SECTION_H
