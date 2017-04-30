#ifndef LIB_NL2PARK_STATION_H
#define LIB_NL2PARK_STATION_H

#include "Section.h"
#include "WaitTime.h"
#include "TransportDevice.h"
#include "BrakeDevice.h"
#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Station : public Section {
        public:
            enum Display {
                FullBuilding,
                NoRoof,
                GatesOnly,
                HideAll
            };

            enum GateDirection {
                Left,
                Right
            };

            enum Stairs {
                None,
                BeginFront,
                BeginSide,
                EndFront,
                EndSide
            };

            Station() : Section(Section::SectionType::Station) {
                waitTime = new WaitTime();
                brakeDevice = new BrakeDevice();
                transportDevice = new TransportDevice();
            }

            void read(File::File *file);

            double getExtraBlockLength() const;
            void setExtraBlockLength(double value);

            bool getUnloadingOnly() const;
            void setUnloadingOnly(bool value);

            Display getDisplay() const;
            void setDisplay(const Display &value);

            GateDirection getGateDirection() const;
            void setGateDirection(const GateDirection &value);

            Stairs getEntranceStairs() const;
            void setEntranceStairs(const Stairs &value);

            Stairs getExitStairs() const;
            void setExitStairs(const Stairs &value);

            uint8_t getPasses() const;
            void setPasses(const uint8_t &value);

            bool getShuttleBackwardsStart() const;
            void setShuttleBackwardsStart(bool value);

            glm::vec3 getStructureColor() const;
            void setStructureColor(const glm::vec3 &value);

            glm::vec3 getRailingsColor() const;
            void setRailingsColor(const glm::vec3 &value);

            glm::vec3 getGatesColor() const;
            void setGatesColor(const glm::vec3 &value);

            WaitTime *getWaitTime() const;
            void setWaitTime(WaitTime *value);

            BrakeDevice *getBrakeDevice() const;
            void setBrakeDevice(BrakeDevice *value);

            bool getUseTransportDevice() const;
            void setUseTransportDevice(bool value);

            TransportDevice *getTransportDevice() const;
            void setTransportDevice(TransportDevice *value);

            uint32_t getStationNumber() const;
            void setStationNumber(const uint32_t &value);

        private:
            double extraBlockLength;

            bool unloadingOnly;

            Display display;
            GateDirection gateDirection;

            Stairs entranceStairs;
            Stairs exitStairs;

            uint8_t passes;
            bool shuttleBackwardsStart;

            glm::vec3 structureColor;
            glm::vec3 railingsColor;
            glm::vec3 gatesColor;

            WaitTime* waitTime;
            BrakeDevice* brakeDevice;

            bool useTransportDevice;
            TransportDevice* transportDevice;

            uint32_t stationNumber;
        };
    }
}

#endif // LIB_NL2PARK_STATION_H
