/* Delay Line. */

namespace DL {

  class DelayLine: public Vertex {
      float *buffer;
      int index;
      int size;
    public:
      float *input;
      float *delay;
      float output;
      DelayLine(float max_delay) {
        size = ((int) max_delay + 1) * sample_rate;
        buffer = new float[size];
        memset(buffer, 0, size * sizeof(float));
        output = 0.0f;
        index = 0;
      }
      void tick() {
        float delay_in_samples;

        delay_in_samples = *delay * sample_rate;
        buffer[index] = *input;
        output = buffer[(size + index - (int) delay_in_samples) % size];
        index = (index + 1) % size;
      }
      ~DelayLine() {
        delete[] buffer;
      }
  };

  class DelayLineInterpolated: public Vertex {
      float *buffer;
      int index;
      int size;
    public:
      float *input;
      float *delay;
      float output;
      DelayLineInterpolated(float max_delay) {
        size = ((int) max_delay + 1) * sample_rate;
        buffer = new float[size];
        memset(buffer, 0, size * sizeof(float));
        output = 0.0f;
        index = 0;
      }
      void tick() {
        int index_a, index_b;
        float balance;
        float delay_in_samples;

        delay_in_samples = *delay * sample_rate;
        buffer[index] = *input;
        /* Linear Interpolation. */
        index_a = (size + index - (int) delay_in_samples) % size;
        index_b = (size + index_a - 1) % size;
        balance = delay_in_samples - floor(delay_in_samples);
        output = buffer[index_a] * (1 - balance) + buffer[index_b] * balance;
        index = (index + 1) % size;
      }
      ~DelayLineInterpolated() {
        delete[] buffer;
      }
  };

}
