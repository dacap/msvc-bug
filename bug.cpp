#include <stdio.h>
#include <stdint.h>

const uint32_t r_shift = 0;
const uint32_t g_shift = 8;
const uint32_t b_shift = 16;
const uint32_t a_shift = 24;

inline uint8_t getr(uint32_t c) { return (c >> r_shift) & 0xff; }
inline uint8_t getg(uint32_t c) { return (c >> g_shift) & 0xff; }
inline uint8_t getb(uint32_t c) { return (c >> b_shift) & 0xff; }
inline uint8_t geta(uint32_t c) { return (c >> a_shift) & 0xff; }
inline uint32_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  return ((r << r_shift) |
          (g << g_shift) |
          (b << b_shift) |
          (a << a_shift));
}

int map_color(const uint32_t rgba)
{
  const int r = getr(rgba);
  const int g = getg(rgba);
  const int b = getb(rgba);
  const int a = geta(rgba);
  // bits -> bbbbbgggggrrrrraaa
  const int i = (a>>5) | ((b>>3) << 3) | ((g>>3) << 8) | ((r>>3) << 13);
  printf("i=%x rgb=%d %d %d %d\n", i, r, g, b, a);
  return i;
}

int main() {
  if (map_color(rgba(90, 120, 180, 255)) == 0x16fb7)
    return 0;
  else
    return 1;
}
