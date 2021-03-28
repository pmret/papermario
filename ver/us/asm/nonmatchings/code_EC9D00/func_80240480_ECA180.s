.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240480_ECA180
/* ECA180 80240480 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ECA184 80240484 AFB1001C */  sw        $s1, 0x1c($sp)
/* ECA188 80240488 0080882D */  daddu     $s1, $a0, $zero
/* ECA18C 8024048C AFBF0020 */  sw        $ra, 0x20($sp)
/* ECA190 80240490 AFB00018 */  sw        $s0, 0x18($sp)
/* ECA194 80240494 8E30000C */  lw        $s0, 0xc($s1)
/* ECA198 80240498 8E050000 */  lw        $a1, ($s0)
/* ECA19C 8024049C 0C0B53A3 */  jal       dead_get_variable
/* ECA1A0 802404A0 26100004 */   addiu    $s0, $s0, 4
/* ECA1A4 802404A4 0C0462EC */  jal       func_80118BB0
/* ECA1A8 802404A8 0040202D */   daddu    $a0, $v0, $zero
/* ECA1AC 802404AC 8E100000 */  lw        $s0, ($s0)
/* ECA1B0 802404B0 C444004C */  lwc1      $f4, 0x4c($v0)
/* ECA1B4 802404B4 3C014148 */  lui       $at, 0x4148
/* ECA1B8 802404B8 44810000 */  mtc1      $at, $f0
/* ECA1BC 802404BC 3C013F33 */  lui       $at, 0x3f33
/* ECA1C0 802404C0 34213333 */  ori       $at, $at, 0x3333
/* ECA1C4 802404C4 44811000 */  mtc1      $at, $f2
/* ECA1C8 802404C8 AFA00014 */  sw        $zero, 0x14($sp)
/* ECA1CC 802404CC 46002100 */  add.s     $f4, $f4, $f0
/* ECA1D0 802404D0 E7A20010 */  swc1      $f2, 0x10($sp)
/* ECA1D4 802404D4 8C450048 */  lw        $a1, 0x48($v0)
/* ECA1D8 802404D8 8C470050 */  lw        $a3, 0x50($v0)
/* ECA1DC 802404DC 44062000 */  mfc1      $a2, $f4
/* ECA1E0 802404E0 0C01DA74 */  jal       func_800769D0
/* ECA1E4 802404E4 0000202D */   daddu    $a0, $zero, $zero
/* ECA1E8 802404E8 0220202D */  daddu     $a0, $s1, $zero
/* ECA1EC 802404EC 0200282D */  daddu     $a1, $s0, $zero
/* ECA1F0 802404F0 0C0B551A */  jal       dead_set_variable
/* ECA1F4 802404F4 0040302D */   daddu    $a2, $v0, $zero
/* ECA1F8 802404F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* ECA1FC 802404FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* ECA200 80240500 8FB00018 */  lw        $s0, 0x18($sp)
/* ECA204 80240504 24020002 */  addiu     $v0, $zero, 2
/* ECA208 80240508 03E00008 */  jr        $ra
/* ECA20C 8024050C 27BD0028 */   addiu    $sp, $sp, 0x28
