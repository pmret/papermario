.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024046C_EE6A1C
/* EE6A1C 8024046C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EE6A20 80240470 AFB1001C */  sw        $s1, 0x1c($sp)
/* EE6A24 80240474 0080882D */  daddu     $s1, $a0, $zero
/* EE6A28 80240478 AFBF0020 */  sw        $ra, 0x20($sp)
/* EE6A2C 8024047C AFB00018 */  sw        $s0, 0x18($sp)
/* EE6A30 80240480 8E30000C */  lw        $s0, 0xc($s1)
/* EE6A34 80240484 8E050000 */  lw        $a1, ($s0)
/* EE6A38 80240488 0C0B53A3 */  jal       dead_get_variable
/* EE6A3C 8024048C 26100004 */   addiu    $s0, $s0, 4
/* EE6A40 80240490 AE220070 */  sw        $v0, 0x70($s1)
/* EE6A44 80240494 8E050000 */  lw        $a1, ($s0)
/* EE6A48 80240498 26100004 */  addiu     $s0, $s0, 4
/* EE6A4C 8024049C 0C0B53A3 */  jal       dead_get_variable
/* EE6A50 802404A0 0220202D */   daddu    $a0, $s1, $zero
/* EE6A54 802404A4 AE220074 */  sw        $v0, 0x74($s1)
/* EE6A58 802404A8 8E050000 */  lw        $a1, ($s0)
/* EE6A5C 802404AC 0C0B53A3 */  jal       dead_get_variable
/* EE6A60 802404B0 0220202D */   daddu    $a0, $s1, $zero
/* EE6A64 802404B4 24040194 */  addiu     $a0, $zero, 0x194
/* EE6A68 802404B8 0000282D */  daddu     $a1, $zero, $zero
/* EE6A6C 802404BC C6200070 */  lwc1      $f0, 0x70($s1)
/* EE6A70 802404C0 46800020 */  cvt.s.w   $f0, $f0
/* EE6A74 802404C4 C6220074 */  lwc1      $f2, 0x74($s1)
/* EE6A78 802404C8 468010A0 */  cvt.s.w   $f2, $f2
/* EE6A7C 802404CC 44060000 */  mfc1      $a2, $f0
/* EE6A80 802404D0 44071000 */  mfc1      $a3, $f2
/* EE6A84 802404D4 44820000 */  mtc1      $v0, $f0
/* EE6A88 802404D8 00000000 */  nop
/* EE6A8C 802404DC 46800020 */  cvt.s.w   $f0, $f0
/* EE6A90 802404E0 AE220078 */  sw        $v0, 0x78($s1)
/* EE6A94 802404E4 0C055C13 */  jal       func_8015704C
/* EE6A98 802404E8 E7A00010 */   swc1     $f0, 0x10($sp)
/* EE6A9C 802404EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* EE6AA0 802404F0 8FB1001C */  lw        $s1, 0x1c($sp)
/* EE6AA4 802404F4 8FB00018 */  lw        $s0, 0x18($sp)
/* EE6AA8 802404F8 24020002 */  addiu     $v0, $zero, 2
/* EE6AAC 802404FC 03E00008 */  jr        $ra
/* EE6AB0 80240500 27BD0028 */   addiu    $sp, $sp, 0x28
