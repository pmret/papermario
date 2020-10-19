.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DC4_C53304
/* C53304 80240DC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C53308 80240DC8 AFB00010 */  sw        $s0, 0x10($sp)
/* C5330C 80240DCC 0080802D */  daddu     $s0, $a0, $zero
/* C53310 80240DD0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C53314 80240DD4 8E020148 */  lw        $v0, 0x148($s0)
/* C53318 80240DD8 0C00EABB */  jal       get_npc_unsafe
/* C5331C 80240DDC 84440008 */   lh       $a0, 8($v0)
/* C53320 80240DE0 0040182D */  daddu     $v1, $v0, $zero
/* C53324 80240DE4 8462008C */  lh        $v0, 0x8c($v1)
/* C53328 80240DE8 14400009 */  bnez      $v0, .L80240E10
/* C5332C 80240DEC 00000000 */   nop      
/* C53330 80240DF0 9462008E */  lhu       $v0, 0x8e($v1)
/* C53334 80240DF4 2442FFFF */  addiu     $v0, $v0, -1
/* C53338 80240DF8 A462008E */  sh        $v0, 0x8e($v1)
/* C5333C 80240DFC 00021400 */  sll       $v0, $v0, 0x10
/* C53340 80240E00 1C400003 */  bgtz      $v0, .L80240E10
/* C53344 80240E04 00000000 */   nop      
/* C53348 80240E08 A460008E */  sh        $zero, 0x8e($v1)
/* C5334C 80240E0C AE000070 */  sw        $zero, 0x70($s0)
.L80240E10:
/* C53350 80240E10 8FBF0014 */  lw        $ra, 0x14($sp)
/* C53354 80240E14 8FB00010 */  lw        $s0, 0x10($sp)
/* C53358 80240E18 03E00008 */  jr        $ra
/* C5335C 80240E1C 27BD0018 */   addiu    $sp, $sp, 0x18
