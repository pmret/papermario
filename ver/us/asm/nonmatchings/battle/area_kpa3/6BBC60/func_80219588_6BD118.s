.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219588_6BD118
/* 6BD118 80219588 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6BD11C 8021958C AFB20018 */  sw        $s2, 0x18($sp)
/* 6BD120 80219590 0080902D */  daddu     $s2, $a0, $zero
/* 6BD124 80219594 AFB10014 */  sw        $s1, 0x14($sp)
/* 6BD128 80219598 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 6BD12C 8021959C 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 6BD130 802195A0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6BD134 802195A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 6BD138 802195A8 8E50000C */  lw        $s0, 0xc($s2)
/* 6BD13C 802195AC 82260012 */  lb        $a2, 0x12($s1)
/* 6BD140 802195B0 8E050000 */  lw        $a1, ($s0)
/* 6BD144 802195B4 0C0B2026 */  jal       set_variable
/* 6BD148 802195B8 26100004 */   addiu    $s0, $s0, 4
/* 6BD14C 802195BC 82220012 */  lb        $v0, 0x12($s1)
/* 6BD150 802195C0 8E050000 */  lw        $a1, ($s0)
/* 6BD154 802195C4 000210C0 */  sll       $v0, $v0, 3
/* 6BD158 802195C8 00511021 */  addu      $v0, $v0, $s1
/* 6BD15C 802195CC 80460015 */  lb        $a2, 0x15($v0)
/* 6BD160 802195D0 0C0B2026 */  jal       set_variable
/* 6BD164 802195D4 0240202D */   daddu    $a0, $s2, $zero
/* 6BD168 802195D8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6BD16C 802195DC 8FB20018 */  lw        $s2, 0x18($sp)
/* 6BD170 802195E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 6BD174 802195E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 6BD178 802195E8 24020002 */  addiu     $v0, $zero, 2
/* 6BD17C 802195EC 03E00008 */  jr        $ra
/* 6BD180 802195F0 27BD0020 */   addiu    $sp, $sp, 0x20
