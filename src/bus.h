#pragma once
#include <iostream>
#include <iomanip>

// Bus class
class Bus {
    private:
        // Memory bus representation
        uint8_t ROMBank00[2048]; // From cartridge, usually a fixed bank                [0000-3FFF]
        uint8_t ROMBank01[2048]; // From cartridge, switchable bank via mapper (if any) [4000-7FFF]
        uint8_t VRAM[1024]; // In CGB mode, switchable bank 0/1                         [8000-9FFF]
        uint8_t ExtRAM[1024]; // From cartridge, switchable bank if any                 [A000-BFFF]
        uint8_t WRAM0[512]; // Work RAM                                                 [C000-CFFF]
        uint8_t WRAM1[512]; // Work RAM: In CGB mode, switchable bank 1-7               [D000-DFFF]
        uint8_t EchoRAM[960]; // mirror of C000-DDFF                                    [E000-FDFF]
        uint8_t OAM[20]; // Object attribute memory                                     [FE00-FE9F]
        uint8_t NUMem[12]; // Not Usable                                                [FEA0-FEFF]
        uint8_t IORegs[16]; // IO Registers                                             [FF00-FF7F]
        uint8_t HRAM[16]; // HRAM (31 nibbles [4-bit])                                  [FF80-FFFE]
        uint8_t IEReg[1]; // Interrupt Enable Register (1 nibble [4-bit])               [FFFF-FFFF]
};
