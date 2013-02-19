/* File read/write with libsdnfile. */

#include <vector>

#include <sndfile.hh>

#include "segno_core.hh"
#include "segno_file.hh"

namespace Segno {

namespace File {

ReaderMono::ReaderMono(const char *path, int format) {
  infile = SndfileHandle(path, SFM_READ, format, 1, sample_rate);
  error = infile.error();
  index = 0;
  eof = false;
  n = infile.read(buffer, SEGNO_BUFFER_SIZE);
  output = n ? buffer[index++] : end();
}

void
ReaderMono::tick() {
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

float
ReaderMono::end() {
  eof = true;
  return 0.0f;
}


ReaderStereo::ReaderStereo(const char *path, int format) {
  infile = SndfileHandle(path, SFM_READ, format, 2, sample_rate);
  error = infile.error();
  index = 0;
  eof = false;
  n = infile.read(buffer, SEGNO_BUFFER_SIZE);
  left  = n ? buffer[index++] : end();
  right = n ? buffer[index++] : end();
}

void
ReaderStereo::tick() {
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

float
ReaderStereo::end() {
  eof = true;
  return 0.0f;
}


WriterMono::WriterMono(const char *path, int format) {
  outfile = SndfileHandle(path, SFM_WRITE, format, 1, sample_rate);
  error = outfile.error();
  index = 0;
}

void
WriterMono::tick() {
  buffer[index++] = *input;
  if (index == SEGNO_BUFFER_SIZE) {
    outfile.write(buffer, index);
    index = 0;
  }
}

WriterMono::~WriterMono() {
  outfile.write(buffer, index);
}


WriterStereo::WriterStereo(const char *path, int format) {
  outfile = SndfileHandle(path, SFM_WRITE, format, 2, sample_rate);
  error = outfile.error();
  index = 0;
}

void
WriterStereo::tick() {
  buffer[index++] = *left;
  buffer[index++] = *right;
  if (index == SEGNO_BUFFER_SIZE) {
    outfile.write(buffer, index);
    index = 0;
  }
}

WriterStereo::~WriterStereo() {
  outfile.write(buffer, index);
}

} // File

} // Segno
