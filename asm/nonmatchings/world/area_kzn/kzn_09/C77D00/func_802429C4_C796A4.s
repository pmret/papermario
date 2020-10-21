.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429C4_C796A4
/* C796A4 802429C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C796A8 802429C8 AFB20018 */  sw        $s2, 0x18($sp)
/* C796AC 802429CC 0080902D */  daddu     $s2, $a0, $zero
/* C796B0 802429D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* C796B4 802429D4 AFB10014 */  sw        $s1, 0x14($sp)
/* C796B8 802429D8 AFB00010 */  sw        $s0, 0x10($sp)
/* C796BC 802429DC 8E510148 */  lw        $s1, 0x148($s2)
/* C796C0 802429E0 0C00EABB */  jal       get_npc_unsafe
/* C796C4 802429E4 86240008 */   lh       $a0, 8($s1)
/* C796C8 802429E8 0040802D */  daddu     $s0, $v0, $zero
/* C796CC 802429EC 8E2300CC */  lw        $v1, 0xcc($s1)
/* C796D0 802429F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C796D4 802429F4 8C630020 */  lw        $v1, 0x20($v1)
/* C796D8 802429F8 AE030028 */  sw        $v1, 0x28($s0)
/* C796DC 802429FC 96220076 */  lhu       $v0, 0x76($s1)
/* C796E0 80242A00 A602008E */  sh        $v0, 0x8e($s0)
/* C796E4 80242A04 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C796E8 80242A08 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C796EC 80242A0C C60E0040 */  lwc1      $f14, 0x40($s0)
/* C796F0 80242A10 8C460028 */  lw        $a2, 0x28($v0)
/* C796F4 80242A14 0C00A720 */  jal       atan2
/* C796F8 80242A18 8C470030 */   lw       $a3, 0x30($v0)
/* C796FC 80242A1C 2402000D */  addiu     $v0, $zero, 0xd
/* C79700 80242A20 E600000C */  swc1      $f0, 0xc($s0)
/* C79704 80242A24 AE420070 */  sw        $v0, 0x70($s2)
/* C79708 80242A28 8FBF001C */  lw        $ra, 0x1c($sp)
/* C7970C 80242A2C 8FB20018 */  lw        $s2, 0x18($sp)
/* C79710 80242A30 8FB10014 */  lw        $s1, 0x14($sp)
/* C79714 80242A34 8FB00010 */  lw        $s0, 0x10($sp)
/* C79718 80242A38 03E00008 */  jr        $ra
/* C7971C 80242A3C 27BD0020 */   addiu    $sp, $sp, 0x20
