#include <cmath>
#include <cstring>
#include <vector>

#include <sndfile.hh>

#include "segno.hh"
#include "segno_file.hh"

#define FORMAT SF_FORMAT_FLAC | SF_FORMAT_PCM_16

int
main()
{
    Segno::Osc::Sine osc;
    Segno::File::WriterMono writer("sine.flac", FORMAT);
    float frequency = 440.0f;
    float duration = 1.0f;
    unsigned int nsamples;
    unsigned int i;

    osc.frequency = &frequency;
    writer.input = &osc.output;

    nsamples = duration * Segno::sample_rate;
    for (i = 0; i < nsamples; i++) {
        osc.tick();
        writer.tick();
    }

    return 0;
}
