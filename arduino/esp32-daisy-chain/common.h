#ifndef CHAIN_CONFIG_H
#define CHAIN_CONFIG_H

#define ENABLE_DEBUG_OUTPUT 1

// Number of chained boards
constexpr size_t CHAIN_SIZE = 2;  // 30
constexpr size_t LED_COUNT = 12;

enum class ChainIdx {
  CHAIN_0 = 0,
  CHAIN_1 = 1,
};

typedef uint8_t BrgNumber;

struct LedObj {
  ChainIdx chain_idx;
  uint8_t pcb_idx;
  uint8_t led_idx;
  BrgNumber brightness;
};

enum class BrgName : BrgNumber {
  BRG_OFF = 0,
  BRG_LOW = 10,
  BRG_MEDIUM = 50,
  BRG_HIGH = 100,
};

static const BrgName DEFAULT_BRIGHTNESS_CHAIN0[CHAIN_SIZE][LED_COUNT] = {
  { BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF,    //
    BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF,    //
    BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF },  // PCB0 (chain 0)
  { BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF,    //
    BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF,    //
    BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF },  // PCB1 (chain 0)
};

static const BrgName DEFAULT_BRIGHTNESS_CHAIN1[CHAIN_SIZE][LED_COUNT] = {
  { BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF,    //
    BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF,    //
    BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF },  // PCB0 (chain 1)
  { BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF,    //
    BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF,    //
    BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF, BrgName::BRG_OFF },  // PCB1 (chain 1)
};

// Gamma brightness lookup table <https://victornpb.github.io/gamma-table-generator>
// gamma = 2.20 steps = 101 range = 0-65535
static const uint16_t BRIGHTNESS_LINEARIZATION_TABLE[101] = {
  0,     3,     12,    29,    55,    90,    134,   189,   253,   328,   413,   510,   618,   736,   867,   1009,  1163,
  1329,  1507,  1697,  1900,  2115,  2343,  2584,  2838,  3104,  3384,  3677,  3983,  4303,  4636,  4983,  5343,  5717,
  6106,  6508,  6924,  7354,  7798,  8257,  8730,  9217,  9719,  10235, 10766, 11312, 11872, 12448, 13038, 13643, 14263,
  14898, 15548, 16214, 16894, 17590, 18302, 19028, 19770, 20528, 21301, 22090, 22895, 23715, 24551, 25403, 26271, 27154,
  28054, 28970, 29901, 30849, 31813, 32793, 33790, 34802, 35831, 36877, 37939, 39017, 40112, 41223, 42351, 43496, 44657,
  45835, 47029, 48241, 49469, 50714, 51976, 53255, 54551, 55864, 57195, 58542, 59906, 61287, 62686, 64102, 65535,
};

static const char DIVIDER[] = "<=====================================>";

#endif  // CHAIN_CONFIG_H
