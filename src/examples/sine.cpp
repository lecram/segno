#include "segno.hh"
#include "segno_file.hh"

#define FORMAT SF_FORMAT_FLAC | SF_FORMAT_PCM_16

int
main()
{
    // Create two segno vertices:
    //  A sine oscillator...
    Segno::Osc::Sine osc;
    //  And a file writer.
    Segno::File::WriterMono writer("sine.flac", FORMAT);
    // Define the frequency in Hertz.
    float frequency = 440.0f;
    // Define the duration in seconds.
    float duration = 1.0f;

    unsigned int nsamples;
    unsigned int i;

    // Make connections.
    // A connection "a => b" is written as "b = &a;".
    osc.frequency = &frequency;
    writer.input = &osc.output;

    // Tick all vertices in the graph to process signals.
    nsamples = duration * Segno::sample_rate;
    for (i = 0; i < nsamples; i++) {
        osc.tick();
        writer.tick();
    }

    // Success. Note that the file is closed automatically.
    return 0;
}
