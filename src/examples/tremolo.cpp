#include "segno.hh"
#include "segno_file.hh"

#define FORMAT SF_FORMAT_FLAC | SF_FORMAT_PCM_16

using namespace std;

int
main()
{
    // Create three segno vertices:
    //  A sawtooth oscillator...
    Segno::Osc::Saw osc;
    //  A tremolo effect...
    Segno::FX::Tremolo tremolo;
    //  And a file writer.
    Segno::File::WriterMono writer("tremolo.flac", FORMAT);
    // Define oscillator parameters.
    float osc_frequency = 440.0f; // Hz
    // Define tremolo parameters.
    float tre_frequency = 2.5f; // Hz
    float tre_depth = 0.3f; // 0 <= depth <= 1
    // Define the duration in seconds.
    float duration = 2.0f;

    unsigned int nsamples;
    unsigned int i;

    // Make connections.
    // A connection "a => b" is written as "b = &a;".
    osc.frequency = &osc_frequency;
    tremolo.input = &osc.output;
    tremolo.frequency = &tre_frequency;
    tremolo.depth = &tre_depth;
    writer.input = &tremolo.output;

    // High-level vertices need to do internal connections before tick.
    tremolo.plug();

    // Tick all vertices in the graph to process signals.
    nsamples = duration * Segno::sample_rate;
    for (i = 0; i < nsamples; i++) {
        osc.tick();
        tremolo.tick();
        writer.tick();
    }

    // Success. Note that the file is closed automatically.
    return 0;
}
