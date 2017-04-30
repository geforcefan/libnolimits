#ifndef LIB_FILE_BUFFERFILE_H
#define LIB_FILE_BUFFERFILE_H

#include <File/File.h>
#include <string>

namespace Library {
    namespace File {
        class BufferFile : public File
        {
        public:
            BufferFile();

            bool openWB();
            bool openRB();

            std::streamsize write(const void * ptr, std::streamsize size, std::streamsize count);
            std::streamsize read (void * ptr, std::streamsize size, std::streamsize count);

            bool close();

            bool isEof();
            int seek(long offset, int origin);
            long tell();

            bool canWrite();
            bool canSeekInFile();

            long getFilesize();

            static BufferFile *createFromFilePath(std::string filepath);
            void setBuffer(void *_buffer, long _size);
        private:
            void *buffer;
            long pos;
            long bufferSize;
            void reallocBuffer();
        };
    }
}

#endif
