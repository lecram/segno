/* File read/write with libsdnfile. */

#ifndef SEGNO_FILE_HH_
#define SEGNO_FILE_HH_

#include <sndfile.hh>

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
  ReaderMono(const char *path, int format);
  void tick();
  float end();
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
  ReaderStereo(const char *path, int format);
  void tick();
  float end();
};

class WriterMono: public Vertex {
  float buffer[SEGNO_BUFFER_SIZE];
  int index;
  SndfileHandle outfile;
 public:
  float *input;
  int error;
  WriterMono(const char *path, int format);
  void tick();
  ~WriterMono();
};

class WriterStereo: public Vertex {
  float buffer[SEGNO_BUFFER_SIZE];
  int index;
  SndfileHandle outfile;
 public:
  float *left;
  float *right;
  int error;
  WriterStereo(const char *path, int format);
  void tick();
  ~WriterStereo();
};

} // File

} // Segno

#endif // SEGNO_FILE_HH_
