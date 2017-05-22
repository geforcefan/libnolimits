#ifndef LIB_NL2PARK_SUPPORTPARAMETER_H
#define LIB_NL2PARK_SUPPORTPARAMETER_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class SupportParameter : public Stream::Chunk {
        public:
            enum Type {
                FooterStyle,
                PipeSize
            };

            SupportParameter() {}

            void read(File::File *file);
            void write(File::File *file);

            std::string getChunkName() { return "SPPM"; }

            double getValue() const;
            void setValue(double value);

            Type getType() const;
            void setType(const Type &value);

        private:
            double value;
            Type type;
        };
    }
}

#endif // LIB_NL2PARK_SUPPORTPARAMETER_H
