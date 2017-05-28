#include "BeziersChunk.h"
#include "Track.h"

namespace NoLimits {
    namespace NoLimits1 {
        void BeziersChunk::read(File::File *file) {
            file->readNull(16);
            uint32_t numberOfVertices = file->readUnsignedInteger();

            for(uint32_t i = 0; i < numberOfVertices; i++) {
                Vertex *vertex = new Vertex();
                track->insertVertex(vertex);
                vertex->read(file);
            }

            file->readNull(16);
            file->readNull(4); // number of sub chunks
        }

        void BeziersChunk::write(File::File *file) {
            file->writeNull(16);
            file->writeUnsignedInteger((uint32_t) track->getVertex().size());

            for(uint32_t i = 0; i < track->getVertex().size(); i++) {
                track->getVertex()[i]->write(file);
            }

            file->writeNull(16);
            file->writeUnsignedInteger(0); // number of sub chunks
        }
    }
}
