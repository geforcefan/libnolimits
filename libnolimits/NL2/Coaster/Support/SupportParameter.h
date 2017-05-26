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

            SupportParameter() {
                setValue(0.0);
                setType(Type::FooterStyle);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "SupportParameter[getValue]: " << getValue() << std::endl;
                std::cout << "SupportParameter[getType]: " << getType() << std::endl;
            }

            double getValue() const;
            void setValue(double value);

            Type getType() const;
            void setType(const Type &value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "SPPM"; }
            /*! \endcond */

        private:
            double value;
            Type type;
        };
    }
}

#endif // LIB_NL2PARK_SUPPORTPARAMETER_H
