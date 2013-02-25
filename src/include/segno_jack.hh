/* Client to the Jack server. */

#ifndef SEGNO_JACK_HH_
#define SEGNO_JACK_HH_

namespace Segno {

namespace Jack {

class Client: public JackCpp::AudioIO {
    std::vector<Vertex*>* vertices;
  public:
    std::vector<float*> out;
    std::vector<float> in;
    virtual int audioCallback(jack_nframes_t nframes,
                              audioBufVector inBufs,
                              audioBufVector outBufs);
    Client(int inn, int outn, std::vector<Vertex*>* vertices);
};

} // Jack

} // Segno

#endif // SEGNO_JACK_HH_
