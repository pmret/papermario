.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242898_A18AB8
/* A18AB8 80242898 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A18ABC 8024289C AFB10014 */  sw        $s1, 0x14($sp)
/* A18AC0 802428A0 0080882D */  daddu     $s1, $a0, $zero
/* A18AC4 802428A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* A18AC8 802428A8 AFB00010 */  sw        $s0, 0x10($sp)
/* A18ACC 802428AC 8E300148 */  lw        $s0, 0x148($s1)
/* A18AD0 802428B0 0C00EABB */  jal       get_npc_unsafe
/* A18AD4 802428B4 86040008 */   lh       $a0, 8($s0)
/* A18AD8 802428B8 0040182D */  daddu     $v1, $v0, $zero
/* A18ADC 802428BC 9462008E */  lhu       $v0, 0x8e($v1)
/* A18AE0 802428C0 2442FFFF */  addiu     $v0, $v0, -1
/* A18AE4 802428C4 A462008E */  sh        $v0, 0x8e($v1)
/* A18AE8 802428C8 00021400 */  sll       $v0, $v0, 0x10
/* A18AEC 802428CC 1C400004 */  bgtz      $v0, .L802428E0
/* A18AF0 802428D0 00000000 */   nop      
/* A18AF4 802428D4 AE000074 */  sw        $zero, 0x74($s0)
/* A18AF8 802428D8 A460008E */  sh        $zero, 0x8e($v1)
/* A18AFC 802428DC AE200070 */  sw        $zero, 0x70($s1)
.L802428E0:
/* A18B00 802428E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A18B04 802428E4 8FB10014 */  lw        $s1, 0x14($sp)
/* A18B08 802428E8 8FB00010 */  lw        $s0, 0x10($sp)
/* A18B0C 802428EC 03E00008 */  jr        $ra
/* A18B10 802428F0 27BD0020 */   addiu    $sp, $sp, 0x20
