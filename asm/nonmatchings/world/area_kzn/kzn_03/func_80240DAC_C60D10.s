.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DAC_C61ABC
/* C61ABC 80240DAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C61AC0 80240DB0 AFB10014 */  sw        $s1, 0x14($sp)
/* C61AC4 80240DB4 0080882D */  daddu     $s1, $a0, $zero
/* C61AC8 80240DB8 AFBF0018 */  sw        $ra, 0x18($sp)
/* C61ACC 80240DBC AFB00010 */  sw        $s0, 0x10($sp)
/* C61AD0 80240DC0 8E300148 */  lw        $s0, 0x148($s1)
/* C61AD4 80240DC4 0C00EABB */  jal       get_npc_unsafe
/* C61AD8 80240DC8 86040008 */   lh       $a0, 8($s0)
/* C61ADC 80240DCC 9443008E */  lhu       $v1, 0x8e($v0)
/* C61AE0 80240DD0 2463FFFF */  addiu     $v1, $v1, -1
/* C61AE4 80240DD4 A443008E */  sh        $v1, 0x8e($v0)
/* C61AE8 80240DD8 00031C00 */  sll       $v1, $v1, 0x10
/* C61AEC 80240DDC 1C600003 */  bgtz      $v1, .L80240DEC
/* C61AF0 80240DE0 2402000C */   addiu    $v0, $zero, 0xc
/* C61AF4 80240DE4 AE00006C */  sw        $zero, 0x6c($s0)
/* C61AF8 80240DE8 AE220070 */  sw        $v0, 0x70($s1)
.L80240DEC:
/* C61AFC 80240DEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C61B00 80240DF0 8FB10014 */  lw        $s1, 0x14($sp)
/* C61B04 80240DF4 8FB00010 */  lw        $s0, 0x10($sp)
/* C61B08 80240DF8 03E00008 */  jr        $ra
/* C61B0C 80240DFC 27BD0020 */   addiu    $sp, $sp, 0x20
