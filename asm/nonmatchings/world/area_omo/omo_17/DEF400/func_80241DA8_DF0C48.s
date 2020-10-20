.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DA8_DF0C48
/* DF0C48 80241DA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF0C4C 80241DAC AFB00010 */  sw        $s0, 0x10($sp)
/* DF0C50 80241DB0 0080802D */  daddu     $s0, $a0, $zero
/* DF0C54 80241DB4 AFBF0014 */  sw        $ra, 0x14($sp)
/* DF0C58 80241DB8 8E020148 */  lw        $v0, 0x148($s0)
/* DF0C5C 80241DBC 0C00EABB */  jal       get_npc_unsafe
/* DF0C60 80241DC0 84440008 */   lh       $a0, 8($v0)
/* DF0C64 80241DC4 0040202D */  daddu     $a0, $v0, $zero
/* DF0C68 80241DC8 8482008E */  lh        $v0, 0x8e($a0)
/* DF0C6C 80241DCC 9483008E */  lhu       $v1, 0x8e($a0)
/* DF0C70 80241DD0 18400005 */  blez      $v0, .L80241DE8
/* DF0C74 80241DD4 2462FFFF */   addiu    $v0, $v1, -1
/* DF0C78 80241DD8 A482008E */  sh        $v0, 0x8e($a0)
/* DF0C7C 80241DDC 00021400 */  sll       $v0, $v0, 0x10
/* DF0C80 80241DE0 1C400006 */  bgtz      $v0, .L80241DFC
/* DF0C84 80241DE4 00000000 */   nop      
.L80241DE8:
/* DF0C88 80241DE8 8482008C */  lh        $v0, 0x8c($a0)
/* DF0C8C 80241DEC 14400003 */  bnez      $v0, .L80241DFC
/* DF0C90 80241DF0 2402000E */   addiu    $v0, $zero, 0xe
/* DF0C94 80241DF4 A480008E */  sh        $zero, 0x8e($a0)
/* DF0C98 80241DF8 AE020070 */  sw        $v0, 0x70($s0)
.L80241DFC:
/* DF0C9C 80241DFC 8FBF0014 */  lw        $ra, 0x14($sp)
/* DF0CA0 80241E00 8FB00010 */  lw        $s0, 0x10($sp)
/* DF0CA4 80241E04 03E00008 */  jr        $ra
/* DF0CA8 80241E08 27BD0018 */   addiu    $sp, $sp, 0x18
