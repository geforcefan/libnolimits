#ifndef NORMALFILE_H
#define NORMALFILE_H

#include "File.h"
#include <stdio.h>

namespace NoLimits {
    namespace File {
        class NormalFile : public File {
        public:
            NormalFile(std::string _filepath) : File(_filepath) {}
            ~NormalFile();

            bool openWB();
            bool openRB();

            std::streamsize write(const void* ptr, std::streamsize size, std::streamsize count);
            std::streamsize read(void* ptr, std::streamsize size, std::streamsize count);

            bool close();
            bool isEof();
            int seek(long offset, int origin);
            long tell();
            int flush();

            long getFilesize();
        private:
            FILE *filePtr;
        };
    }
}

#endif // NORMALFILE_H
