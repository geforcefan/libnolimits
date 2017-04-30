#ifndef LIB_NL2PARK_COLORS_H
#define LIB_NL2PARK_COLORS_H

#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Colors: public Stream::Chunk {
        public:
            enum SpineColorScheme {
                Plain = 0,
                TopAccented = 1,
                BottomAccented = 2,
                Stripe = 3
            };

            Colors();
            void read(File::File *file);

            glm::vec3 getWireframeTrack() const;
            void setWireframeTrack(const glm::vec3 &value);

            glm::vec3 getRails() const;
            void setRails(const glm::vec3 &value);

            glm::vec3 getCrossTies() const;
            void setCrossTies(const glm::vec3 &value);

            glm::vec3 getMainSpine() const;
            void setMainSpine(const glm::vec3 &value);

            glm::vec3 getCar() const;
            void setCar(const glm::vec3 &value);

            glm::vec3 getSeat() const;
            void setSeat(const glm::vec3 &value);

            glm::vec3 getHarness() const;
            void setHarness(const glm::vec3 &value);

            glm::vec3 getBogie() const;
            void setBogie(const glm::vec3 &value);

            glm::vec3 getChasiss() const;
            void setChasiss(const glm::vec3 &value);

            glm::vec3 getSupports() const;
            void setSupports(const glm::vec3 &value);

            glm::vec3 getTunnel() const;
            void setTunnel(const glm::vec3 &value);

            glm::vec3 getHandrails() const;
            void setHandrails(const glm::vec3 &value);

            glm::vec3 getCatwalks() const;
            void setCatwalks(const glm::vec3 &value);

            SpineColorScheme getSpineColorScheme() const;
            void setSpineColorScheme(const SpineColorScheme &value);

        private:
            glm::vec3 wireframeTrack;
            glm::vec3 rails;
            glm::vec3 crossTies;
            glm::vec3 mainSpine;
            glm::vec3 car;
            glm::vec3 seat;
            glm::vec3 harness;
            glm::vec3 bogie;
            glm::vec3 chasiss;
            glm::vec3 supports;
            glm::vec3 tunnel;
            glm::vec3 handrails;
            glm::vec3 catwalks;
            SpineColorScheme spineColorScheme;
        };
    }
}

#endif // LIB_NL2PARK_COLORS_H
