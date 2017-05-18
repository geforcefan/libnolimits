#include "Script.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void Script::read(File::File *file) {
            resourceFile.clear();

            file->readNull(4);

            setClassPath(file->readString());
            setScriptClass(file->readString());

            uint32_t numberOfResourceFiles = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numberOfResourceFiles; i++) {
                ResourceFile *_resourceFile = new ResourceFile();
                _resourceFile->read(file);
                insertResourceFile(_resourceFile);
            }

            setPrivateVirtualMachine(!file->readBoolean());
            file->readNull(7);
        }

        void Script::write(File::File *file) {
            file->writeNull(4);

            file->writeString(getClassPath());
            file->writeString(getScriptClass());

            file->writeUnsignedInteger(resourceFile.size());
            for(uint32_t i = 0; i < resourceFile.size(); i++) {
                resourceFile[i]->write(file);
            }

            file->writeBoolean(!getPrivateVirtualMachine());
            file->writeNull(7);
        }

        std::vector<ResourceFile *> Script::getResourceFile() const {
            return resourceFile;
        }

        void Script::insertResourceFile(ResourceFile* value) {
            resourceFile.push_back(value);
        }

        std::string Script::getScriptClass() const {
            return scriptClass;
        }

        void Script::setScriptClass(const std::string &value) {
            scriptClass = value;
        }

        std::string Script::getClassPath() const {
            return classPath;
        }

        void Script::setClassPath(const std::string &value) {
            classPath = value;
        }

        bool Script::getPrivateVirtualMachine() const {
            return privateVirtualMachine;
        }

        void Script::setPrivateVirtualMachine(bool value) {
            privateVirtualMachine = value;
        }
    }
}
