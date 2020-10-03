.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802537C0
/* 1820A0 802537C0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1820A4 802537C4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1820A8 802537C8 0080882D */  daddu     $s1, $a0, $zero
/* 1820AC 802537CC AFBF0028 */  sw        $ra, 0x28($sp)
/* 1820B0 802537D0 AFB30024 */  sw        $s3, 0x24($sp)
/* 1820B4 802537D4 AFB20020 */  sw        $s2, 0x20($sp)
/* 1820B8 802537D8 AFB00018 */  sw        $s0, 0x18($sp)
/* 1820BC 802537DC 8E22000C */  lw        $v0, 0xc($s1)
/* 1820C0 802537E0 8C520000 */  lw        $s2, ($v0)
/* 1820C4 802537E4 8C530004 */  lw        $s3, 4($v0)
/* 1820C8 802537E8 24040001 */  addiu     $a0, $zero, 1
/* 1820CC 802537EC 27A50010 */  addiu     $a1, $sp, 0x10
/* 1820D0 802537F0 0C04DF70 */  jal       func_80137DC0
/* 1820D4 802537F4 27A60014 */   addiu    $a2, $sp, 0x14
/* 1820D8 802537F8 C7A20014 */  lwc1      $f2, 0x14($sp)
/* 1820DC 802537FC 3C014300 */  lui       $at, 0x4300
/* 1820E0 80253800 44810000 */  mtc1      $at, $f0
/* 1820E4 80253804 00000000 */  nop       
/* 1820E8 80253808 4600103C */  c.lt.s    $f2, $f0
/* 1820EC 8025380C 00000000 */  nop       
/* 1820F0 80253810 45000002 */  bc1f      .L8025381C
/* 1820F4 80253814 24100001 */   addiu    $s0, $zero, 1
/* 1820F8 80253818 0000802D */  daddu     $s0, $zero, $zero
.L8025381C:
/* 1820FC 8025381C 0220202D */  daddu     $a0, $s1, $zero
/* 182100 80253820 0240282D */  daddu     $a1, $s2, $zero
/* 182104 80253824 0C0B2026 */  jal       set_variable
/* 182108 80253828 24060001 */   addiu    $a2, $zero, 1
/* 18210C 8025382C 0220202D */  daddu     $a0, $s1, $zero
/* 182110 80253830 0260282D */  daddu     $a1, $s3, $zero
/* 182114 80253834 0C0B2026 */  jal       set_variable
/* 182118 80253838 0200302D */   daddu    $a2, $s0, $zero
/* 18211C 8025383C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 182120 80253840 8FB30024 */  lw        $s3, 0x24($sp)
/* 182124 80253844 8FB20020 */  lw        $s2, 0x20($sp)
/* 182128 80253848 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18212C 8025384C 8FB00018 */  lw        $s0, 0x18($sp)
/* 182130 80253850 24020002 */  addiu     $v0, $zero, 2
/* 182134 80253854 03E00008 */  jr        $ra
/* 182138 80253858 27BD0030 */   addiu    $sp, $sp, 0x30
