TEMPLATE = app
CONFIG += c++11
CONFIG += app_bundle
CONFIG += qt

LIBS += -lz

QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

SOURCES += main.cpp \
    lib/File/File.cpp \
    lib/NL2Park/Coaster/Track/Section/Brake.cpp \
    lib/NL2Park/Coaster/Track/Section/BrakeDevice.cpp \
    lib/NL2Park/Coaster/Track/Section/Lift.cpp \
    lib/NL2Park/Coaster/Track/Section/Section.cpp \
    lib/NL2Park/Coaster/Track/Section/Station.cpp \
    lib/NL2Park/Coaster/Track/Section/Storage.cpp \
    lib/NL2Park/Coaster/Track/Section/Transport.cpp \
    lib/NL2Park/Coaster/Track/Section/TransportDevice.cpp \
    lib/NL2Park/Coaster/Track/Section/WaitTime.cpp \
    lib/NL2Park/Coaster/Track/Support/RailNode.cpp \
    lib/NL2Park/Coaster/Track/Support/SupportNode.cpp \
    lib/NL2Park/Coaster/Track/CustomTrack.cpp \
    lib/NL2Park/Coaster/Track/Parameter4D.cpp \
    lib/NL2Park/Coaster/Track/RollPoint.cpp \
    lib/NL2Park/Coaster/Track/Segment.cpp \
    lib/NL2Park/Coaster/Track/Separator.cpp \
    lib/NL2Park/Coaster/Track/Track.cpp \
    lib/NL2Park/Coaster/Track/Trigger.cpp \
    lib/NL2Park/Coaster/Track/Vertex.cpp \
    lib/NL2Park/Coaster/Track/WoodenSupportGenerator.cpp \
    lib/NL2Park/Coaster/Car.cpp \
    lib/NL2Park/Coaster/Coaster.cpp \
    lib/NL2Park/Coaster/Colors.cpp \
    lib/NL2Park/Coaster/CustomFriction.cpp \
    lib/NL2Park/Coaster/IndividualColor.cpp \
    lib/NL2Park/Coaster/Mode.cpp \
    lib/NL2Park/Coaster/Style.cpp \
    lib/NL2Park/Coaster/Train.cpp \
    lib/NL2Park/Info/Info.cpp \
    lib/NL2Park/Info/Sky.cpp \
    lib/NL2Park/Info/Version.cpp \
    lib/NL2Park/Info/Weather.cpp \
    lib/NL2Park/Terrain/AutoPaint.cpp \
    lib/NL2Park/Terrain/BaseMap.cpp \
    lib/NL2Park/Terrain/BumpMap.cpp \
    lib/NL2Park/Terrain/DetailMap.cpp \
    lib/NL2Park/Terrain/Extras.cpp \
    lib/NL2Park/Terrain/Layer.cpp \
    lib/NL2Park/Terrain/Terrain.cpp \
    lib/NL2Park/Terrain/Water.cpp \
    lib/NL2Park/Park.cpp \
    lib/NL2Park/Uspk.cpp \
    lib/Stream/Chunk.cpp \
    lib/Helper.cpp \
    lib/NL2Park/Scenery/Scenery.cpp \
    lib/NL2Park/Scenery/SceneObjectInstance.cpp \
    lib/File/MemoryFile.cpp \
    lib/File/NormalFile.cpp

HEADERS += \
    lib/File/File.h \
    lib/NL2Park/Coaster/Track/Section/Brake.h \
    lib/NL2Park/Coaster/Track/Section/BrakeDevice.h \
    lib/NL2Park/Coaster/Track/Section/Lift.h \
    lib/NL2Park/Coaster/Track/Section/Section.h \
    lib/NL2Park/Coaster/Track/Section/Station.h \
    lib/NL2Park/Coaster/Track/Section/Storage.h \
    lib/NL2Park/Coaster/Track/Section/Transport.h \
    lib/NL2Park/Coaster/Track/Section/TransportDevice.h \
    lib/NL2Park/Coaster/Track/Section/WaitTime.h \
    lib/NL2Park/Coaster/Track/Support/RailNode.h \
    lib/NL2Park/Coaster/Track/Support/SupportNode.h \
    lib/NL2Park/Coaster/Track/CustomTrack.h \
    lib/NL2Park/Coaster/Track/Parameter4D.h \
    lib/NL2Park/Coaster/Track/RollPoint.h \
    lib/NL2Park/Coaster/Track/Segment.h \
    lib/NL2Park/Coaster/Track/Separator.h \
    lib/NL2Park/Coaster/Track/Track.h \
    lib/NL2Park/Coaster/Track/Trigger.h \
    lib/NL2Park/Coaster/Track/Vertex.h \
    lib/NL2Park/Coaster/Track/WoodenSupportGenerator.h \
    lib/NL2Park/Coaster/Car.h \
    lib/NL2Park/Coaster/Coaster.h \
    lib/NL2Park/Coaster/Colors.h \
    lib/NL2Park/Coaster/CustomFriction.h \
    lib/NL2Park/Coaster/IndividualColor.h \
    lib/NL2Park/Coaster/Mode.h \
    lib/NL2Park/Coaster/Style.h \
    lib/NL2Park/Coaster/Train.h \
    lib/NL2Park/Info/Info.h \
    lib/NL2Park/Info/Sky.h \
    lib/NL2Park/Info/Version.h \
    lib/NL2Park/Info/Weather.h \
    lib/NL2Park/Terrain/AutoPaint.h \
    lib/NL2Park/Terrain/BaseMap.h \
    lib/NL2Park/Terrain/BumpMap.h \
    lib/NL2Park/Terrain/DetailMap.h \
    lib/NL2Park/Terrain/Extras.h \
    lib/NL2Park/Terrain/Layer.h \
    lib/NL2Park/Terrain/Terrain.h \
    lib/NL2Park/Terrain/TerrainMap.h \
    lib/NL2Park/Terrain/Water.h \
    lib/NL2Park/Park.h \
    lib/NL2Park/Uspk.h \
    lib/Stream/Chunk.h \
    lib/Helper.h \
    lib/nolimits.h \
    lib/NL2Park/Scenery/Scenery.h \
    lib/NL2Park/Scenery/SceneObjectInstance.h \
    lib/File/MemoryFile.h \
    lib/File/NormalFile.h

INCLUDEPATH += lib/ \
    /usr/local/include/
