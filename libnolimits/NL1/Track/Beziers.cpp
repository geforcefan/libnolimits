#include "Beziers.h"
#include "Track.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Beziers::read(File::File *file) {
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

        void Beziers::write(File::File *file) {
            file->writeNull(16);
            file->writeUnsignedInteger(track->getVertex().size());

            for(uint32_t i = 0; i < track->getVertex().size(); i++) {
                track->getVertex()[i]->write(file);
            }

            file->writeNull(16);
            file->writeUnsignedInteger(0); // number of sub chunks
        }
    }
}
