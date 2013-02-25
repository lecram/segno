#include <unistd.h>

#include "segno.hh"
#include "segno_jack.hh"

using namespace std;

int
main()
{
    Segno::FX::Flanger flanger;
    Segno::Jack::Client * client;
    vector<Segno::Vertex*> vertices;
    float frequency = 0.3f;
    float depth = 0.5f;
    float tone = 0.5f;
    float feedback = 0.4f;
    float dry = 0.4f;
    float wet = 0.4f;

    flanger.frequency = &frequency;
    flanger.depth = &depth;
    flanger.tone = &tone;
    flanger.feedback = &feedback;
    flanger.dry = &dry;
    flanger.wet = &wet;

    vertices.push_back(&flanger);

    client = new Segno::Jack::Client(1, 2, &vertices);
    Segno::sample_rate = client->getSampleRate();
    flanger.input = &client->in[0];
    flanger.plug();
    client->out[0] = &flanger.output;
    client->out[1] = &flanger.output;

    client->start();
    client->connectFromPhysical(0, 0);
    client->connectToPhysical(0, 0);
    client->connectToPhysical(1, 1);

    while (true) sleep(1);

    client->disconnectInPort(0);
    client->disconnectOutPort(0);
    client->disconnectOutPort(1);
    client->close();
    delete client;

    return 0;
}
