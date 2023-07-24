#include "common.h"
#include "ld_addrs.h"

void create_audio_system_obfuscated(void);
void load_engine_data_obfuscated(void);
void general_heap_create_obfuscated(void);
void battle_heap_create_obfuscated(void);

void shim_create_audio_system_obfuscated(void) {
    DMA_COPY_SEGMENT(create_audio_system_obfuscated);
    create_audio_system_obfuscated();
}

void shim_load_engine_data_obfuscated(void) {
    DMA_COPY_SEGMENT(load_engine_data_obfuscated);
    load_engine_data_obfuscated();
}

void shim_general_heap_create_obfuscated(void) {
    DMA_COPY_SEGMENT(general_heap_create_obfuscated);
    general_heap_create_obfuscated();
}

void shim_battle_heap_create_obfuscated(void) {
    DMA_COPY_SEGMENT(battle_heap_create_obfuscated);
    battle_heap_create_obfuscated();
}
