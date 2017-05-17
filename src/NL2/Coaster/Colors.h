#ifndef LIB_NL2PARK_COLORS_H
#define LIB_NL2PARK_COLORS_H

#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Colors: public Stream::Chunk {
        public:
            Colors() {
                setWireframeTrack(glm::vec3(0.0f));
                setRails(glm::vec3(0.0f));
                setCrossTies(glm::vec3(0.0f));
                setMainSpine(glm::vec3(0.0f));
                setCar(glm::vec3(0.0f));
                setSeat(glm::vec3(0.0f));
                setHarness(glm::vec3(0.0f));
                setBogie(glm::vec3(0.0f));
                setChasiss(glm::vec3(0.0f));
                setSupports(glm::vec3(0.0f));
                setTunnel(glm::vec3(0.0f));
                setHandrails(glm::vec3(0.0f));
                setCatwalks(glm::vec3(0.0f));
                setSpineColorScheme(SpineColorScheme::Plain);
            }

            enum SpineColorScheme {
                Plain = 0,
                TopAccented = 1,
                BottomAccented = 2,
                Stripe = 3
            };

            void debug() {
                std::cout << "Colors[getWireframeTrack]: " << Helper::debug(getWireframeTrack()) << std::endl;
                std::cout << "Colors[getRails]: " << Helper::debug(getRails()) << std::endl;
                std::cout << "Colors[getCrossTies]: " << Helper::debug(getCrossTies()) << std::endl;
                std::cout << "Colors[getMainSpine]: " << Helper::debug(getMainSpine()) << std::endl;
                std::cout << "Colors[getCar]: " << Helper::debug(getCar()) << std::endl;
                std::cout << "Colors[getSeat]: " << Helper::debug(getSeat()) << std::endl;
                std::cout << "Colors[getHarness]: " << Helper::debug(getHarness()) << std::endl;
                std::cout << "Colors[getBogie]: " << Helper::debug(getBogie()) << std::endl;
                std::cout << "Colors[getChasiss]: " << Helper::debug(getChasiss()) << std::endl;
                std::cout << "Colors[getSupports]: " << Helper::debug(getSupports()) << std::endl;
                std::cout << "Colors[getTunnel]: " << Helper::debug(getTunnel()) << std::endl;
                std::cout << "Colors[getHandrails]: " << Helper::debug(getHandrails()) << std::endl;
                std::cout << "Colors[getCatwalks]: " << Helper::debug(getCatwalks()) << std::endl;
                std::cout << "Colors[getSpineColorScheme]: " << getSpineColorScheme() << std::endl;
            }

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
