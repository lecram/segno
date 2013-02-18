/* File read/write with libsdnfile. */

// #include <sndfile.hh>

#define SEGNO_BUFFER_SIZE 2520 // multiple of 1, 2, 3, 4, 5, 6, 7, 8, 9 & 10.

namespace Segno {

  namespace File {

    class ReaderMono: public Vertex {
        float buffer[SEGNO_BUFFER_SIZE];
        int index;
        SndfileHandle infile;
        int n;
      public:
        float output;
        int error;
        bool eof;
        ReaderMono(const char *path, int format) {
          infile = SndfileHandle(path, SFM_READ, format, 1, sample_rate);
          error = infile.error();
          index = 0;
          eof = false;
          n = infile.read(buffer, SEGNO_BUFFER_SIZE);
          output = n ? buffer[index++] : end();
        }
        void tick() {
          if (eof)
            return;
          if (index == n) {
            if (n == SEGNO_BUFFER_SIZE) {
              index = 0;
              n = infile.read(buffer, SEGNO_BUFFER_SIZE);
              output = n ? buffer[index++] : end();
            }
            else
              output = end();
          }
          else
            output = buffer[index++];
        }
        float end() {
          eof = true;
          return 0.0f;
        }
    };

    class ReaderStereo: public Vertex {
        float buffer[SEGNO_BUFFER_SIZE];
        int index;
        SndfileHandle infile;
        int n;
      public:
        float left;
        float right;
        int error;
        bool eof;
        ReaderStereo(const char *path, int format) {
          infile = SndfileHandle(path, SFM_READ, format, 2, sample_rate);
          error = infile.error();
          index = 0;
          eof = false;
          n = infile.read(buffer, SEGNO_BUFFER_SIZE);
          left  = n ? buffer[index++] : end();
          right = n ? buffer[index++] : end();
        }
        void tick() {
          if (eof)
            return;
          if (index == n) {
            if (n == SEGNO_BUFFER_SIZE) {
              index = 0;
              n = infile.read(buffer, SEGNO_BUFFER_SIZE);
              left  = n ? buffer[index++] : end();
              right = n ? buffer[index++] : end();
            }
            else
              left = right = end();
          }
          else {
            left  = buffer[index++];
            right = buffer[index++];
          }
        }
        float end() {
          eof = true;
          return 0.0f;
        }
    };

    class WriterMono: public Vertex {
        float buffer[SEGNO_BUFFER_SIZE];
        int index;
        SndfileHandle outfile;
      public:
        float *input;
        int error;
        WriterMono(const char *path, int format) {
          outfile = SndfileHandle(path, SFM_WRITE, format, 1, sample_rate);
          error = outfile.error();
          index = 0;
        }
        void tick() {
          buffer[index++] = *input;
          if (index == SEGNO_BUFFER_SIZE) {
            outfile.write(buffer, index);
            index = 0;
          }
        }
        ~WriterMono() {
          outfile.write(buffer, index);
        }
    };

    class WriterStereo: public Vertex {
        float buffer[SEGNO_BUFFER_SIZE];
        int index;
        SndfileHandle outfile;
      public:
        float *left;
        float *right;
        int error;
        WriterStereo(const char *path, int format) {
          outfile = SndfileHandle(path, SFM_WRITE, format, 2, sample_rate);
          error = outfile.error();
          index = 0;
        }
        void tick() {
          buffer[index++] = *left;
          buffer[index++] = *right;
          if (index == SEGNO_BUFFER_SIZE) {
            outfile.write(buffer, index);
            index = 0;
          }
        }
        ~WriterStereo() {
          outfile.write(buffer, index);
        }
    };

  }

}
