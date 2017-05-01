TEMPLATE = app
CONFIG += c++11
CONFIG += app_bundle
CONFIG += qt

LIBS += -lz

QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

SOURCES += main.cpp \
    src/File/File.cpp \
    src/NL2/Coaster/Track/Section/Brake.cpp \
    src/NL2/Coaster/Track/Section/BrakeDevice.cpp \
    src/NL2/Coaster/Track/Section/Lift.cpp \
    src/NL2/Coaster/Track/Section/Section.cpp \
    src/NL2/Coaster/Track/Section/Station.cpp \
    src/NL2/Coaster/Track/Section/Storage.cpp \
    src/NL2/Coaster/Track/Section/Transport.cpp \
    src/NL2/Coaster/Track/Section/TransportDevice.cpp \
    src/NL2/Coaster/Track/Section/WaitTime.cpp \
    src/NL2/Coaster/Track/Support/RailNode.cpp \
    src/NL2/Coaster/Track/Support/SupportNode.cpp \
    src/NL2/Coaster/Track/CustomTrack.cpp \
    src/NL2/Coaster/Track/Parameter4D.cpp \
    src/NL2/Coaster/Track/RollPoint.cpp \
    src/NL2/Coaster/Track/Segment.cpp \
    src/NL2/Coaster/Track/Separator.cpp \
    src/NL2/Coaster/Track/Track.cpp \
    src/NL2/Coaster/Track/Trigger.cpp \
    src/NL2/Coaster/Track/Vertex.cpp \
    src/NL2/Coaster/Track/WoodenSupportGenerator.cpp \
    src/NL2/Coaster/Car.cpp \
    src/NL2/Coaster/Coaster.cpp \
    src/NL2/Coaster/Colors.cpp \
    src/NL2/Coaster/CustomFriction.cpp \
    src/NL2/Coaster/IndividualColor.cpp \
    src/NL2/Coaster/Mode.cpp \
    src/NL2/Coaster/Style.cpp \
    src/NL2/Coaster/Train.cpp \
    src/NL2/Info/Info.cpp \
    src/NL2/Info/Sky.cpp \
    src/NL2/Info/Version.cpp \
    src/NL2/Info/Weather.cpp \
    src/NL2/Terrain/AutoPaint.cpp \
    src/NL2/Terrain/BaseMap.cpp \
    src/NL2/Terrain/BumpMap.cpp \
    src/NL2/Terrain/DetailMap.cpp \
    src/NL2/Terrain/Extras.cpp \
    src/NL2/Terrain/Layer.cpp \
    src/NL2/Terrain/Terrain.cpp \
    src/NL2/Terrain/Water.cpp \
    src/NL2/Park.cpp \
    src/NL2/Uspk.cpp \
    src/Helper.cpp \
    src/NL2/Scenery/Scenery.cpp \
    src/NL2/Scenery/SceneObjectInstance.cpp \
    src/File/MemoryFile.cpp \
    src/File/NormalFile.cpp

HEADERS += \
    src/File/File.h \
    src/NL2/Coaster/Track/Section/Brake.h \
    src/NL2/Coaster/Track/Section/BrakeDevice.h \
    src/NL2/Coaster/Track/Section/Lift.h \
    src/NL2/Coaster/Track/Section/Section.h \
    src/NL2/Coaster/Track/Section/Station.h \
    src/NL2/Coaster/Track/Section/Storage.h \
    src/NL2/Coaster/Track/Section/Transport.h \
    src/NL2/Coaster/Track/Section/TransportDevice.h \
    src/NL2/Coaster/Track/Section/WaitTime.h \
    src/NL2/Coaster/Track/Support/RailNode.h \
    src/NL2/Coaster/Track/Support/SupportNode.h \
    src/NL2/Coaster/Track/CustomTrack.h \
    src/NL2/Coaster/Track/Parameter4D.h \
    src/NL2/Coaster/Track/RollPoint.h \
    src/NL2/Coaster/Track/Segment.h \
    src/NL2/Coaster/Track/Separator.h \
    src/NL2/Coaster/Track/Track.h \
    src/NL2/Coaster/Track/Trigger.h \
    src/NL2/Coaster/Track/Vertex.h \
    src/NL2/Coaster/Track/WoodenSupportGenerator.h \
    src/NL2/Coaster/Car.h \
    src/NL2/Coaster/Coaster.h \
    src/NL2/Coaster/Colors.h \
    src/NL2/Coaster/CustomFriction.h \
    src/NL2/Coaster/IndividualColor.h \
    src/NL2/Coaster/Mode.h \
    src/NL2/Coaster/Style.h \
    src/NL2/Coaster/Train.h \
    src/NL2/Info/Info.h \
    src/NL2/Info/Sky.h \
    src/NL2/Info/Version.h \
    src/NL2/Info/Weather.h \
    src/NL2/Terrain/AutoPaint.h \
    src/NL2/Terrain/BaseMap.h \
    src/NL2/Terrain/BumpMap.h \
    src/NL2/Terrain/DetailMap.h \
    src/NL2/Terrain/Extras.h \
    src/NL2/Terrain/Layer.h \
    src/NL2/Terrain/Terrain.h \
    src/NL2/Terrain/TerrainMap.h \
    src/NL2/Terrain/Water.h \
    src/NL2/Park.h \
    src/NL2/Uspk.h \
    src/Stream/Chunk.h \
    src/Helper.h \
    src/Nolimits.h \
    src/NL2/Scenery/Scenery.h \
    src/NL2/Scenery/SceneObjectInstance.h \
    src/File/MemoryFile.h \
    src/File/NormalFile.h

INCLUDEPATH += src/ \
    /usr/local/include/
