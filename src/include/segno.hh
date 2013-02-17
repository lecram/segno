/* Segno. */

namespace Segno {

    int sample_rate = 48000;

    class Vertex {
      public:
        virtual void tick() {}
        virtual ~Vertex() {}
    };

    void
    pulse(std::vector<Vertex*> vertices, float duration)
    {
        std::vector<Vertex*>::iterator vertex;
        int samples, i;

        samples = duration * sample_rate;
        for (i = 0; i < samples; i++)
            for (vertex = vertices.begin(); vertex != vertices.end(); vertex++)
                (**vertex).tick();
    }

    void
    pulse_while(std::vector<Vertex*> vertices, bool *condition)
    {
        std::vector<Vertex*>::iterator vertex;

        while (*condition)
            for (vertex = vertices.begin(); vertex != vertices.end(); vertex++)
                (**vertex).tick();
    }

    void
    pulse_until(std::vector<Vertex*> vertices, bool *condition)
    {
        std::vector<Vertex*>::iterator vertex;

        while (!*condition)
            for (vertex = vertices.begin(); vertex != vertices.end(); vertex++)
                (**vertex).tick();
    }

#include "segno_op.hh"
#include "segno_dl.hh"
#include "segno_pa.hh"
#include "segno_pac.hh"
#include "segno_osc.hh"
#include "segno_fx.hh"

}
