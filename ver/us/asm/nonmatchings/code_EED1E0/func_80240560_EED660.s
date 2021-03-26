.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240560_EED660
/* EED660 80240560 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EED664 80240564 AFB1001C */  sw        $s1, 0x1c($sp)
/* EED668 80240568 0080882D */  daddu     $s1, $a0, $zero
/* EED66C 8024056C AFBF0020 */  sw        $ra, 0x20($sp)
/* EED670 80240570 AFB00018 */  sw        $s0, 0x18($sp)
/* EED674 80240574 8E30000C */  lw        $s0, 0xc($s1)
/* EED678 80240578 8E050000 */  lw        $a1, ($s0)
/* EED67C 8024057C 0C0B53A3 */  jal       dead_get_variable
/* EED680 80240580 26100004 */   addiu    $s0, $s0, 4
/* EED684 80240584 0C0462EC */  jal       func_80118BB0
/* EED688 80240588 0040202D */   daddu    $a0, $v0, $zero
/* EED68C 8024058C 8E100000 */  lw        $s0, ($s0)
/* EED690 80240590 C444004C */  lwc1      $f4, 0x4c($v0)
/* EED694 80240594 3C014148 */  lui       $at, 0x4148
/* EED698 80240598 44810000 */  mtc1      $at, $f0
/* EED69C 8024059C 3C013F33 */  lui       $at, 0x3f33
/* EED6A0 802405A0 34213333 */  ori       $at, $at, 0x3333
/* EED6A4 802405A4 44811000 */  mtc1      $at, $f2
/* EED6A8 802405A8 AFA00014 */  sw        $zero, 0x14($sp)
/* EED6AC 802405AC 46002100 */  add.s     $f4, $f4, $f0
/* EED6B0 802405B0 E7A20010 */  swc1      $f2, 0x10($sp)
/* EED6B4 802405B4 8C450048 */  lw        $a1, 0x48($v0)
/* EED6B8 802405B8 8C470050 */  lw        $a3, 0x50($v0)
/* EED6BC 802405BC 44062000 */  mfc1      $a2, $f4
/* EED6C0 802405C0 0C01DA74 */  jal       func_800769D0
/* EED6C4 802405C4 0000202D */   daddu    $a0, $zero, $zero
/* EED6C8 802405C8 0220202D */  daddu     $a0, $s1, $zero
/* EED6CC 802405CC 0200282D */  daddu     $a1, $s0, $zero
/* EED6D0 802405D0 0C0B551A */  jal       dead_set_variable
/* EED6D4 802405D4 0040302D */   daddu    $a2, $v0, $zero
/* EED6D8 802405D8 8FBF0020 */  lw        $ra, 0x20($sp)
/* EED6DC 802405DC 8FB1001C */  lw        $s1, 0x1c($sp)
/* EED6E0 802405E0 8FB00018 */  lw        $s0, 0x18($sp)
/* EED6E4 802405E4 24020002 */  addiu     $v0, $zero, 2
/* EED6E8 802405E8 03E00008 */  jr        $ra
/* EED6EC 802405EC 27BD0028 */   addiu    $sp, $sp, 0x28
