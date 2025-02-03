#pragma once
#include <iostream>
#include <iomanip>

// Bus class
class Bus {
    private:
        // Memory bus representation
        unsigned char ROMBank00[2048]; // From cartridge, usually a fixed bank                [0000-3FFF]
        unsigned char ROMBank01[2048]; // From cartridge, switchable bank via mapper (if any) [4000-7FFF]
        unsigned char VRAM[1024]; // In CGB mode, switchable bank 0/1                         [8000-9FFF]
        unsigned char ExtRAM[1024]; // From cartridge, switchable bank if any                 [A000-BFFF]
        unsigned char WRAM0[512]; // Work RAM                                                 [C000-CFFF]
        unsigned char WRAM1[512]; // Work RAM: In CGB mode, switchable bank 1-7               [D000-DFFF]
        unsigned char EchoRAM[960]; // mirror of C000-DDFF                                    [E000-FDFF]
        unsigned char OAM[20]; // Object attribute memory                                     [FE00-FE9F]
        unsigned char NUMem[12]; // Not Usable                                                [FEA0-FEFF]
        unsigned char IORegs[16]; // IO Registers                                             [FF00-FF7F]
        unsigned char HRAM[16]; // HRAM (31 nibbles [4-bit])                                  [FF80-FFFE]
        unsigned char IEReg[1]; // Interrupt Enable Register (1 nibble [4-bit])               [FFFF-FFFF]
};
