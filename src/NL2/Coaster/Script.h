#ifndef LIB_NL2PARK_SCRIPT_H
#define LIB_NL2PARK_SCRIPT_H

#include <Stream/Chunk.h>
#include <vector>
#include "ResourceFile.h"

namespace NoLimits {
    namespace NL2 {
        class Script: public Stream::Chunk {
        public:
            Script() {
                setScriptClass("");
                setClassPath("");
                setPrivateVirtualMachine(false);
            }

            void debug() {
                std::cout << "Script[getScriptClass]: " << getScriptClass() << std::endl;
                std::cout << "Script[getClassPath]: " << getClassPath() << std::endl;
                std::cout << "Script[getPrivateVirtualMachine]: " << getPrivateVirtualMachine() << std::endl;

                std::cout << "Script[getResourceFile.size]: " << resourceFile.size() << std::endl;
                if(resourceFile.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < resourceFile.size(); i++) {
                    resourceFile[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            void read(File::File *file);
            void write(File::File *file);

            std::vector<ResourceFile *> getResourceFile() const;
            void insertResourceFile(ResourceFile* value);

            std::string getScriptClass() const;
            void setScriptClass(const std::string &value);

            std::string getClassPath() const;
            void setClassPath(const std::string &value);

            bool getPrivateVirtualMachine() const;
            void setPrivateVirtualMachine(bool value);

            std::string getChunkName() { return "SCRT"; }

        private:
            std::string scriptClass;
            std::string classPath;
            bool privateVirtualMachine;
            std::vector<ResourceFile*> resourceFile;
        };
    }
}

#endif // LIB_NL2PARK_SCRIPT_H
