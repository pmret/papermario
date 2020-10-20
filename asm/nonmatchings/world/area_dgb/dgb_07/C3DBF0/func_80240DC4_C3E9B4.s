.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DC4_C3E9B4
/* C3E9B4 80240DC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C3E9B8 80240DC8 AFB00010 */  sw        $s0, 0x10($sp)
/* C3E9BC 80240DCC 0080802D */  daddu     $s0, $a0, $zero
/* C3E9C0 80240DD0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C3E9C4 80240DD4 8E020148 */  lw        $v0, 0x148($s0)
/* C3E9C8 80240DD8 0C00EABB */  jal       get_npc_unsafe
/* C3E9CC 80240DDC 84440008 */   lh       $a0, 8($v0)
/* C3E9D0 80240DE0 0040182D */  daddu     $v1, $v0, $zero
/* C3E9D4 80240DE4 8462008C */  lh        $v0, 0x8c($v1)
/* C3E9D8 80240DE8 14400009 */  bnez      $v0, .L80240E10
/* C3E9DC 80240DEC 00000000 */   nop      
/* C3E9E0 80240DF0 9462008E */  lhu       $v0, 0x8e($v1)
/* C3E9E4 80240DF4 2442FFFF */  addiu     $v0, $v0, -1
/* C3E9E8 80240DF8 A462008E */  sh        $v0, 0x8e($v1)
/* C3E9EC 80240DFC 00021400 */  sll       $v0, $v0, 0x10
/* C3E9F0 80240E00 1C400003 */  bgtz      $v0, .L80240E10
/* C3E9F4 80240E04 00000000 */   nop      
/* C3E9F8 80240E08 A460008E */  sh        $zero, 0x8e($v1)
/* C3E9FC 80240E0C AE000070 */  sw        $zero, 0x70($s0)
.L80240E10:
/* C3EA00 80240E10 8FBF0014 */  lw        $ra, 0x14($sp)
/* C3EA04 80240E14 8FB00010 */  lw        $s0, 0x10($sp)
/* C3EA08 80240E18 03E00008 */  jr        $ra
/* C3EA0C 80240E1C 27BD0018 */   addiu    $sp, $sp, 0x18
