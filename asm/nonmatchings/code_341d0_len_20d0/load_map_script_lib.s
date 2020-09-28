.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_map_script_lib
/* 35AC0 8005A6C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 35AC4 8005A6C4 3C04007E */  lui       $a0, 0x7e
/* 35AC8 8005A6C8 24840E80 */  addiu     $a0, $a0, 0xe80
/* 35ACC 8005A6CC 3C05007E */  lui       $a1, 0x7e
/* 35AD0 8005A6D0 24A573A0 */  addiu     $a1, $a1, 0x73a0
/* 35AD4 8005A6D4 3C068028 */  lui       $a2, 0x8028
/* 35AD8 8005A6D8 24C60000 */  addiu     $a2, $a2, 0
/* 35ADC 8005A6DC AFBF0010 */  sw        $ra, 0x10($sp)
/* 35AE0 8005A6E0 0C00A5CF */  jal       dma_copy
/* 35AE4 8005A6E4 00000000 */   nop      
/* 35AE8 8005A6E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 35AEC 8005A6EC 03E00008 */  jr        $ra
/* 35AF0 8005A6F0 27BD0018 */   addiu    $sp, $sp, 0x18
