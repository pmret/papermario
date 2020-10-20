.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240878_D05FA8
/* D05FA8 80240878 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D05FAC 8024087C AFB10014 */  sw        $s1, 0x14($sp)
/* D05FB0 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D05FB4 80240884 AFBF0018 */  sw        $ra, 0x18($sp)
/* D05FB8 80240888 AFB00010 */  sw        $s0, 0x10($sp)
/* D05FBC 8024088C 8E30000C */  lw        $s0, 0xc($s1)
/* D05FC0 80240890 8E050000 */  lw        $a1, ($s0)
/* D05FC4 80240894 0C0B1EAF */  jal       get_variable
/* D05FC8 80240898 26100004 */   addiu    $s0, $s0, 4
/* D05FCC 8024089C 0220202D */  daddu     $a0, $s1, $zero
/* D05FD0 802408A0 8E050000 */  lw        $a1, ($s0)
/* D05FD4 802408A4 0C0B1EAF */  jal       get_variable
/* D05FD8 802408A8 0040882D */   daddu    $s1, $v0, $zero
/* D05FDC 802408AC 0000202D */  daddu     $a0, $zero, $zero
/* D05FE0 802408B0 0080282D */  daddu     $a1, $a0, $zero
/* D05FE4 802408B4 0040802D */  daddu     $s0, $v0, $zero
/* D05FE8 802408B8 240600BE */  addiu     $a2, $zero, 0xbe
/* D05FEC 802408BC 0C04DF93 */  jal       func_80137E4C
/* D05FF0 802408C0 24070091 */   addiu    $a3, $zero, 0x91
/* D05FF4 802408C4 44900000 */  mtc1      $s0, $f0
/* D05FF8 802408C8 00000000 */  nop       
/* D05FFC 802408CC 46800020 */  cvt.s.w   $f0, $f0
/* D06000 802408D0 44050000 */  mfc1      $a1, $f0
/* D06004 802408D4 0C04DF62 */  jal       func_80137D88
/* D06008 802408D8 322400FF */   andi     $a0, $s1, 0xff
/* D0600C 802408DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D06010 802408E0 8FB10014 */  lw        $s1, 0x14($sp)
/* D06014 802408E4 8FB00010 */  lw        $s0, 0x10($sp)
/* D06018 802408E8 24020002 */  addiu     $v0, $zero, 2
/* D0601C 802408EC 03E00008 */  jr        $ra
/* D06020 802408F0 27BD0020 */   addiu    $sp, $sp, 0x20
