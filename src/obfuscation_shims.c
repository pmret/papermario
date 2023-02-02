#include "common.h"
#include "ld_addrs.h"

void create_audio_system_obfuscated(void);
void load_engine_data_obfuscated(void);
void general_heap_create_obfuscated(void);
void battle_heap_create_obfuscated(void);

void shim_create_audio_system_obfuscated(void) {
    dma_copy(
        create_audio_system_obfuscated_ROM_START,
        create_audio_system_obfuscated_ROM_END,
        create_audio_system_obfuscated_VRAM
    );
    create_audio_system_obfuscated();
}

void shim_load_engine_data_obfuscated(void) {
    dma_copy(
        load_engine_data_obfuscated_ROM_START,
        load_engine_data_obfuscated_ROM_END,
        load_engine_data_obfuscated_VRAM
    );
    load_engine_data_obfuscated();
}

void shim_general_heap_create_obfuscated(void) {
    dma_copy(
        general_heap_create_obfuscated_ROM_START,
        general_heap_create_obfuscated_ROM_END,
        general_heap_create_obfuscated_VRAM
    );
    general_heap_create_obfuscated();
}

void shim_battle_heap_create_obfuscated(void) {
    dma_copy(
        battle_heap_create_obfuscated_ROM_START,
        battle_heap_create_obfuscated_ROM_END,
        battle_heap_create_obfuscated_VRAM
    );
    battle_heap_create_obfuscated();
}
