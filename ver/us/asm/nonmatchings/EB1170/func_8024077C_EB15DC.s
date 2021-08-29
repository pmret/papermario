.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024077C_EB15DC
/* EB15DC 8024077C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB15E0 80240780 AFB10014 */  sw        $s1, 0x14($sp)
/* EB15E4 80240784 0080882D */  daddu     $s1, $a0, $zero
/* EB15E8 80240788 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB15EC 8024078C AFB00010 */  sw        $s0, 0x10($sp)
/* EB15F0 80240790 8E30000C */  lw        $s0, 0xc($s1)
/* EB15F4 80240794 8E050000 */  lw        $a1, ($s0)
/* EB15F8 80240798 0C0B53A3 */  jal       dead_evt_get_variable
/* EB15FC 8024079C 26100004 */   addiu    $s0, $s0, 4
/* EB1600 802407A0 AE22008C */  sw        $v0, 0x8c($s1)
/* EB1604 802407A4 8E050000 */  lw        $a1, ($s0)
/* EB1608 802407A8 26100004 */  addiu     $s0, $s0, 4
/* EB160C 802407AC 0C0B53A3 */  jal       dead_evt_get_variable
/* EB1610 802407B0 0220202D */   daddu    $a0, $s1, $zero
/* EB1614 802407B4 AE220090 */  sw        $v0, 0x90($s1)
/* EB1618 802407B8 8E050000 */  lw        $a1, ($s0)
/* EB161C 802407BC 26100004 */  addiu     $s0, $s0, 4
/* EB1620 802407C0 0C0B53A3 */  jal       dead_evt_get_variable
/* EB1624 802407C4 0220202D */   daddu    $a0, $s1, $zero
/* EB1628 802407C8 AE220094 */  sw        $v0, 0x94($s1)
/* EB162C 802407CC 8E050000 */  lw        $a1, ($s0)
/* EB1630 802407D0 26100004 */  addiu     $s0, $s0, 4
/* EB1634 802407D4 0C0B53A3 */  jal       dead_evt_get_variable
/* EB1638 802407D8 0220202D */   daddu    $a0, $s1, $zero
/* EB163C 802407DC AE220098 */  sw        $v0, 0x98($s1)
/* EB1640 802407E0 8E050000 */  lw        $a1, ($s0)
/* EB1644 802407E4 26100004 */  addiu     $s0, $s0, 4
/* EB1648 802407E8 0C0B53A3 */  jal       dead_evt_get_variable
/* EB164C 802407EC 0220202D */   daddu    $a0, $s1, $zero
/* EB1650 802407F0 AE22009C */  sw        $v0, 0x9c($s1)
/* EB1654 802407F4 8E050000 */  lw        $a1, ($s0)
/* EB1658 802407F8 26100004 */  addiu     $s0, $s0, 4
/* EB165C 802407FC 0C0B53A3 */  jal       dead_evt_get_variable
/* EB1660 80240800 0220202D */   daddu    $a0, $s1, $zero
/* EB1664 80240804 AE2200A0 */  sw        $v0, 0xa0($s1)
/* EB1668 80240808 8E050000 */  lw        $a1, ($s0)
/* EB166C 8024080C 26100004 */  addiu     $s0, $s0, 4
/* EB1670 80240810 0C0B53A3 */  jal       dead_evt_get_variable
/* EB1674 80240814 0220202D */   daddu    $a0, $s1, $zero
/* EB1678 80240818 AE2200A4 */  sw        $v0, 0xa4($s1)
/* EB167C 8024081C 8E050000 */  lw        $a1, ($s0)
/* EB1680 80240820 26100004 */  addiu     $s0, $s0, 4
/* EB1684 80240824 0C0B53A3 */  jal       dead_evt_get_variable
/* EB1688 80240828 0220202D */   daddu    $a0, $s1, $zero
/* EB168C 8024082C AE2200A8 */  sw        $v0, 0xa8($s1)
/* EB1690 80240830 8E050000 */  lw        $a1, ($s0)
/* EB1694 80240834 26100004 */  addiu     $s0, $s0, 4
/* EB1698 80240838 0C0B53A3 */  jal       dead_evt_get_variable
/* EB169C 8024083C 0220202D */   daddu    $a0, $s1, $zero
/* EB16A0 80240840 AE2200AC */  sw        $v0, 0xac($s1)
/* EB16A4 80240844 8E050000 */  lw        $a1, ($s0)
/* EB16A8 80240848 0C0B53A3 */  jal       dead_evt_get_variable
/* EB16AC 8024084C 0220202D */   daddu    $a0, $s1, $zero
/* EB16B0 80240850 AE2200B0 */  sw        $v0, 0xb0($s1)
/* EB16B4 80240854 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB16B8 80240858 8FB10014 */  lw        $s1, 0x14($sp)
/* EB16BC 8024085C 8FB00010 */  lw        $s0, 0x10($sp)
/* EB16C0 80240860 24020002 */  addiu     $v0, $zero, 2
/* EB16C4 80240864 03E00008 */  jr        $ra
/* EB16C8 80240868 27BD0020 */   addiu    $sp, $sp, 0x20
