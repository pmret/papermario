.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C78
/* 8D3188 80241C78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8D318C 80241C7C AFB00010 */  sw        $s0, 0x10($sp)
/* 8D3190 80241C80 0080802D */  daddu     $s0, $a0, $zero
/* 8D3194 80241C84 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8D3198 80241C88 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8D319C 80241C8C 8E02000C */  lw        $v0, 0xc($s0)
/* 8D31A0 80241C90 0C0B210B */  jal       get_float_variable
/* 8D31A4 80241C94 8C450000 */   lw       $a1, ($v0)
/* 8D31A8 80241C98 0200202D */  daddu     $a0, $s0, $zero
/* 8D31AC 80241C9C 3C05FD05 */  lui       $a1, 0xfd05
/* 8D31B0 80241CA0 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 8D31B4 80241CA4 0C0B1EAF */  jal       get_variable
/* 8D31B8 80241CA8 46000506 */   mov.s    $f20, $f0
/* 8D31BC 80241CAC E4540040 */  swc1      $f20, 0x40($v0)
/* 8D31C0 80241CB0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8D31C4 80241CB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D31C8 80241CB8 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8D31CC 80241CBC 24020002 */  addiu     $v0, $zero, 2
/* 8D31D0 80241CC0 03E00008 */  jr        $ra
/* 8D31D4 80241CC4 27BD0020 */   addiu    $sp, $sp, 0x20
