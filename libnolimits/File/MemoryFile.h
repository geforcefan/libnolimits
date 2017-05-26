#ifndef LIB_FILE_MemoryFile_H
#define LIB_FILE_MemoryFile_H

#include "File.h"
#include <string>

/*! \cond INTERNAL */
namespace NoLimits {
    namespace File {
        class MemoryFile : public File
        {
        public:
            MemoryFile();

            bool openWB();
            bool openRB();

            std::streamsize write(const void * ptr, std::streamsize size, std::streamsize count);
            std::streamsize read (void * ptr, std::streamsize size, std::streamsize count);

            bool close();

            bool isEof();
            int seek(long offset, int origin);
            long tell();

            long getFilesize();

            void setBuffer(void *_buffer, long _size);
        private:
            void *buffer;
            long pos;
            long bufferSize;
            void reallocBuffer();
        };
    }
}
/*! \endcond */

#endif
