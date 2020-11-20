.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkSetDurationFunc
/* DF1780 802428E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DF1784 802428E4 AFB10014 */  sw        $s1, 0x14($sp)
/* DF1788 802428E8 0080882D */  daddu     $s1, $a0, $zero
/* DF178C 802428EC AFBF0018 */  sw        $ra, 0x18($sp)
/* DF1790 802428F0 AFB00010 */  sw        $s0, 0x10($sp)
/* DF1794 802428F4 8E300148 */  lw        $s0, 0x148($s1)
/* DF1798 802428F8 0C00EABB */  jal       get_npc_unsafe
/* DF179C 802428FC 86040008 */   lh       $a0, 8($s0)
/* DF17A0 80242900 96030076 */  lhu       $v1, 0x76($s0)
/* DF17A4 80242904 A443008E */  sh        $v1, 0x8e($v0)
/* DF17A8 80242908 24020021 */  addiu     $v0, $zero, 0x21
/* DF17AC 8024290C AE220070 */  sw        $v0, 0x70($s1)
/* DF17B0 80242910 8FBF0018 */  lw        $ra, 0x18($sp)
/* DF17B4 80242914 8FB10014 */  lw        $s1, 0x14($sp)
/* DF17B8 80242918 8FB00010 */  lw        $s0, 0x10($sp)
/* DF17BC 8024291C 03E00008 */  jr        $ra
/* DF17C0 80242920 27BD0020 */   addiu    $sp, $sp, 0x20
