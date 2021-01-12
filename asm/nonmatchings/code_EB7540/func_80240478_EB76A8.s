.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240478_EB76A8
/* EB76A8 80240478 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EB76AC 8024047C AFB10014 */  sw        $s1, 0x14($sp)
/* EB76B0 80240480 0080882D */  daddu     $s1, $a0, $zero
/* EB76B4 80240484 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB76B8 80240488 AFB00010 */  sw        $s0, 0x10($sp)
/* EB76BC 8024048C F7B60028 */  sdc1      $f22, 0x28($sp)
/* EB76C0 80240490 F7B40020 */  sdc1      $f20, 0x20($sp)
/* EB76C4 80240494 8E30000C */  lw        $s0, 0xc($s1)
/* EB76C8 80240498 8E050000 */  lw        $a1, ($s0)
/* EB76CC 8024049C 0C0B55FF */  jal       func_802D57FC
/* EB76D0 802404A0 26100004 */   addiu    $s0, $s0, 4
/* EB76D4 802404A4 8E050000 */  lw        $a1, ($s0)
/* EB76D8 802404A8 26100004 */  addiu     $s0, $s0, 4
/* EB76DC 802404AC 0220202D */  daddu     $a0, $s1, $zero
/* EB76E0 802404B0 0C0B55FF */  jal       func_802D57FC
/* EB76E4 802404B4 46000586 */   mov.s    $f22, $f0
/* EB76E8 802404B8 0220202D */  daddu     $a0, $s1, $zero
/* EB76EC 802404BC 8E050000 */  lw        $a1, ($s0)
/* EB76F0 802404C0 0C0B55FF */  jal       func_802D57FC
/* EB76F4 802404C4 46000506 */   mov.s    $f20, $f0
/* EB76F8 802404C8 8E2300BC */  lw        $v1, 0xbc($s1)
/* EB76FC 802404CC 8C62000C */  lw        $v0, 0xc($v1)
/* EB7700 802404D0 E4560038 */  swc1      $f22, 0x38($v0)
/* EB7704 802404D4 8C62000C */  lw        $v0, 0xc($v1)
/* EB7708 802404D8 E454003C */  swc1      $f20, 0x3c($v0)
/* EB770C 802404DC 8C62000C */  lw        $v0, 0xc($v1)
/* EB7710 802404E0 E4400040 */  swc1      $f0, 0x40($v0)
/* EB7714 802404E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB7718 802404E8 8FB10014 */  lw        $s1, 0x14($sp)
/* EB771C 802404EC 8FB00010 */  lw        $s0, 0x10($sp)
/* EB7720 802404F0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* EB7724 802404F4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* EB7728 802404F8 24020002 */  addiu     $v0, $zero, 2
/* EB772C 802404FC 03E00008 */  jr        $ra
/* EB7730 80240500 27BD0030 */   addiu    $sp, $sp, 0x30
