.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C44_EEED44
/* EEED44 80241C44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EEED48 80241C48 AFB00010 */  sw        $s0, 0x10($sp)
/* EEED4C 80241C4C 0080802D */  daddu     $s0, $a0, $zero
/* EEED50 80241C50 AFBF0014 */  sw        $ra, 0x14($sp)
/* EEED54 80241C54 8E020148 */  lw        $v0, 0x148($s0)
/* EEED58 80241C58 0C00F92F */  jal       dead_get_npc_unsafe
/* EEED5C 80241C5C 84440008 */   lh       $a0, 8($v0)
/* EEED60 80241C60 0040202D */  daddu     $a0, $v0, $zero
/* EEED64 80241C64 8482008E */  lh        $v0, 0x8e($a0)
/* EEED68 80241C68 9483008E */  lhu       $v1, 0x8e($a0)
/* EEED6C 80241C6C 18400005 */  blez      $v0, .L80241C84
/* EEED70 80241C70 2462FFFF */   addiu    $v0, $v1, -1
/* EEED74 80241C74 A482008E */  sh        $v0, 0x8e($a0)
/* EEED78 80241C78 00021400 */  sll       $v0, $v0, 0x10
/* EEED7C 80241C7C 1C400006 */  bgtz      $v0, .L80241C98
/* EEED80 80241C80 00000000 */   nop
.L80241C84:
/* EEED84 80241C84 8482008C */  lh        $v0, 0x8c($a0)
/* EEED88 80241C88 14400003 */  bnez      $v0, .L80241C98
/* EEED8C 80241C8C 2402000E */   addiu    $v0, $zero, 0xe
/* EEED90 80241C90 A480008E */  sh        $zero, 0x8e($a0)
/* EEED94 80241C94 AE020070 */  sw        $v0, 0x70($s0)
.L80241C98:
/* EEED98 80241C98 8FBF0014 */  lw        $ra, 0x14($sp)
/* EEED9C 80241C9C 8FB00010 */  lw        $s0, 0x10($sp)
/* EEEDA0 80241CA0 03E00008 */  jr        $ra
/* EEEDA4 80241CA4 27BD0018 */   addiu    $sp, $sp, 0x18
