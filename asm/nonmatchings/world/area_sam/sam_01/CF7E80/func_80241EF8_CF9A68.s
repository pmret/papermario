.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EF8_CF9A68
/* CF9A68 80241EF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF9A6C 80241EFC AFB00010 */  sw        $s0, 0x10($sp)
/* CF9A70 80241F00 0080802D */  daddu     $s0, $a0, $zero
/* CF9A74 80241F04 AFBF0014 */  sw        $ra, 0x14($sp)
/* CF9A78 80241F08 8E02000C */  lw        $v0, 0xc($s0)
/* CF9A7C 80241F0C 0C0B1EAF */  jal       get_variable
/* CF9A80 80241F10 8C450000 */   lw       $a1, ($v0)
/* CF9A84 80241F14 00021140 */  sll       $v0, $v0, 5
/* CF9A88 80241F18 AE000084 */  sw        $zero, 0x84($s0)
/* CF9A8C 80241F1C 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* CF9A90 80241F20 00220821 */  addu      $at, $at, $v0
/* CF9A94 80241F24 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* CF9A98 80241F28 30420040 */  andi      $v0, $v0, 0x40
/* CF9A9C 80241F2C 10400002 */  beqz      $v0, .L80241F38
/* CF9AA0 80241F30 24020001 */   addiu    $v0, $zero, 1
/* CF9AA4 80241F34 AE020084 */  sw        $v0, 0x84($s0)
.L80241F38:
/* CF9AA8 80241F38 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF9AAC 80241F3C 8FB00010 */  lw        $s0, 0x10($sp)
/* CF9AB0 80241F40 24020002 */  addiu     $v0, $zero, 2
/* CF9AB4 80241F44 03E00008 */  jr        $ra
/* CF9AB8 80241F48 27BD0018 */   addiu    $sp, $sp, 0x18
/* CF9ABC 80241F4C 00000000 */  nop       
