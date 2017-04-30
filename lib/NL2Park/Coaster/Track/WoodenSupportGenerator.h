#ifndef LIB_NL2PARK_WOODENSUPPORTGENERATOR_H
#define LIB_NL2PARK_WOODENSUPPORTGENERATOR_H

#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class WoodenSupportGenerator : public Stream::Chunk {
        public:
            enum Flag {
                IndividualSettings,
                WideSupportsLeft,
                WideSupportsRight,
                CatwalksLeft,
                CatwalksRight,
                HandrailsLeft,
                HandrailsRight,
                CollisionDetection
            };

            enum BentSpacing {
                Spacing9Ft,
                Spacing625Ft,
                Spacing45Ft
            };

            WoodenSupportGenerator() {}
            void read(File::File *file);

            bool getUseIndividualSettings();
            bool getUseLeftWideSupports();
            bool getUseRightWideSupports();
            bool getUseLeftCatwalks();
            bool getUseRightCatwalks();
            bool getUseLeftHandrails();
            bool getUseRightHandrails();
            bool getCollisionDetection();
            bool getEnableSupports();

            void setUseIndividualSettings(bool state);
            void setUseLeftWideSupports(bool state);
            void setUseRightWideSupports(bool state);
            void setUseLeftCatwalks(bool state);
            void setUseRightCatwalks(bool state);
            void setUseLeftHandrails(bool state);
            void setUseRightHandrails(bool state);
            void setCollisionDetection(bool state);
            void setEnableSupports(bool state);

            void setBentSpacing(BentSpacing spacing);
            BentSpacing getBentSpacing();

        private:
            uint8_t flag1;
            uint8_t flag2;

            void setFlag1(const uint8_t &value);
            void setFlag2(const uint8_t &value);

        protected:
            bool hasFlag1(uint8_t flag);
            bool hasFlag2(uint8_t flag);

            void setWithCheckFlag1(uint8_t flag, bool state);
            void setWithCheckFlag2(uint8_t flag, bool state);
        };
    }
}

#endif // LIB_NL2PARK_WOODENSUPPORTGENERATOR_H
