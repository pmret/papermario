.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021875C_4EFBFC
/* 4EFBFC 8021875C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4EFC00 80218760 AFB1002C */  sw        $s1, 0x2c($sp)
/* 4EFC04 80218764 0080882D */  daddu     $s1, $a0, $zero
/* 4EFC08 80218768 AFBF0034 */  sw        $ra, 0x34($sp)
/* 4EFC0C 8021876C AFB20030 */  sw        $s2, 0x30($sp)
/* 4EFC10 80218770 AFB00028 */  sw        $s0, 0x28($sp)
/* 4EFC14 80218774 8E30000C */  lw        $s0, 0xc($s1)
/* 4EFC18 80218778 8E050000 */  lw        $a1, ($s0)
/* 4EFC1C 8021877C 0C0B1EAF */  jal       evt_get_variable
/* 4EFC20 80218780 26100004 */   addiu    $s0, $s0, 4
/* 4EFC24 80218784 8E050000 */  lw        $a1, ($s0)
/* 4EFC28 80218788 26100004 */  addiu     $s0, $s0, 4
/* 4EFC2C 8021878C 0220202D */  daddu     $a0, $s1, $zero
/* 4EFC30 80218790 0C0B1EAF */  jal       evt_get_variable
/* 4EFC34 80218794 0040902D */   daddu    $s2, $v0, $zero
/* 4EFC38 80218798 0220202D */  daddu     $a0, $s1, $zero
/* 4EFC3C 8021879C 8E050000 */  lw        $a1, ($s0)
/* 4EFC40 802187A0 0C0B1EAF */  jal       evt_get_variable
/* 4EFC44 802187A4 0040802D */   daddu    $s0, $v0, $zero
/* 4EFC48 802187A8 24040002 */  addiu     $a0, $zero, 2
/* 4EFC4C 802187AC 44923000 */  mtc1      $s2, $f6
/* 4EFC50 802187B0 00000000 */  nop
/* 4EFC54 802187B4 468031A0 */  cvt.s.w   $f6, $f6
/* 4EFC58 802187B8 44900000 */  mtc1      $s0, $f0
/* 4EFC5C 802187BC 00000000 */  nop
/* 4EFC60 802187C0 46800020 */  cvt.s.w   $f0, $f0
/* 4EFC64 802187C4 44053000 */  mfc1      $a1, $f6
/* 4EFC68 802187C8 44823000 */  mtc1      $v0, $f6
/* 4EFC6C 802187CC 00000000 */  nop
/* 4EFC70 802187D0 468031A0 */  cvt.s.w   $f6, $f6
/* 4EFC74 802187D4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 4EFC78 802187D8 3C01BF00 */  lui       $at, 0xbf00
/* 4EFC7C 802187DC 44810000 */  mtc1      $at, $f0
/* 4EFC80 802187E0 3C01BF66 */  lui       $at, 0xbf66
/* 4EFC84 802187E4 34216666 */  ori       $at, $at, 0x6666
/* 4EFC88 802187E8 44811000 */  mtc1      $at, $f2
/* 4EFC8C 802187EC 3C013F00 */  lui       $at, 0x3f00
/* 4EFC90 802187F0 44812000 */  mtc1      $at, $f4
/* 4EFC94 802187F4 3C064316 */  lui       $a2, 0x4316
/* 4EFC98 802187F8 44073000 */  mfc1      $a3, $f6
/* 4EFC9C 802187FC 2403003C */  addiu     $v1, $zero, 0x3c
/* 4EFCA0 80218800 AFA30020 */  sw        $v1, 0x20($sp)
/* 4EFCA4 80218804 E7A00014 */  swc1      $f0, 0x14($sp)
/* 4EFCA8 80218808 E7A20018 */  swc1      $f2, 0x18($sp)
/* 4EFCAC 8021880C 0C01C544 */  jal       playFX_4C
/* 4EFCB0 80218810 E7A4001C */   swc1     $f4, 0x1c($sp)
/* 4EFCB4 80218814 8C43000C */  lw        $v1, 0xc($v0)
/* 4EFCB8 80218818 AC600030 */  sw        $zero, 0x30($v1)
/* 4EFCBC 8021881C 8C43000C */  lw        $v1, 0xc($v0)
/* 4EFCC0 80218820 AC600038 */  sw        $zero, 0x38($v1)
/* 4EFCC4 80218824 8C43000C */  lw        $v1, 0xc($v0)
/* 4EFCC8 80218828 AC600034 */  sw        $zero, 0x34($v1)
/* 4EFCCC 8021882C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 4EFCD0 80218830 8FB20030 */  lw        $s2, 0x30($sp)
/* 4EFCD4 80218834 8FB1002C */  lw        $s1, 0x2c($sp)
/* 4EFCD8 80218838 8FB00028 */  lw        $s0, 0x28($sp)
/* 4EFCDC 8021883C 24020002 */  addiu     $v0, $zero, 2
/* 4EFCE0 80218840 03E00008 */  jr        $ra
/* 4EFCE4 80218844 27BD0038 */   addiu    $sp, $sp, 0x38
/* 4EFCE8 80218848 00000000 */  nop
/* 4EFCEC 8021884C 00000000 */  nop
