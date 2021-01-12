.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC1A8_E2C8D8
/* E2C8D8 802BC1A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2C8DC 802BC1AC 3C013F80 */  lui       $at, 0x3f80
/* E2C8E0 802BC1B0 44811000 */  mtc1      $at, $f2
/* E2C8E4 802BC1B4 0000282D */  daddu     $a1, $zero, $zero
/* E2C8E8 802BC1B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2C8EC 802BC1BC 8C830040 */  lw        $v1, 0x40($a0)
.L802BC1C0:
/* E2C8F0 802BC1C0 C46000B4 */  lwc1      $f0, 0xb4($v1)
/* E2C8F4 802BC1C4 46020000 */  add.s     $f0, $f0, $f2
/* E2C8F8 802BC1C8 24A50001 */  addiu     $a1, $a1, 1
/* E2C8FC 802BC1CC 28A2000C */  slti      $v0, $a1, 0xc
/* E2C900 802BC1D0 E46000B4 */  swc1      $f0, 0xb4($v1)
/* E2C904 802BC1D4 1440FFFA */  bnez      $v0, .L802BC1C0
/* E2C908 802BC1D8 24630004 */   addiu    $v1, $v1, 4
/* E2C90C 802BC1DC 3C05802C */  lui       $a1, %hi(D_802BCE1C)
/* E2C910 802BC1E0 0C0442F3 */  jal       func_80110BCC
/* E2C914 802BC1E4 24A5CE1C */   addiu    $a1, $a1, %lo(D_802BCE1C)
/* E2C918 802BC1E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2C91C 802BC1EC 03E00008 */  jr        $ra
/* E2C920 802BC1F0 27BD0018 */   addiu    $sp, $sp, 0x18
/* E2C924 802BC1F4 00000000 */  nop       
/* E2C928 802BC1F8 00000000 */  nop       
/* E2C92C 802BC1FC 00000000 */  nop       
