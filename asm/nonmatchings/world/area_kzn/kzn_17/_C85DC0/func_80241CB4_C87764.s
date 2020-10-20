.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CB4_C87764
/* C87764 80241CB4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C87768 80241CB8 AFB20018 */  sw        $s2, 0x18($sp)
/* C8776C 80241CBC 0080902D */  daddu     $s2, $a0, $zero
/* C87770 80241CC0 AFBF001C */  sw        $ra, 0x1c($sp)
/* C87774 80241CC4 AFB10014 */  sw        $s1, 0x14($sp)
/* C87778 80241CC8 AFB00010 */  sw        $s0, 0x10($sp)
/* C8777C 80241CCC 8E510148 */  lw        $s1, 0x148($s2)
/* C87780 80241CD0 0C00EABB */  jal       get_npc_unsafe
/* C87784 80241CD4 86240008 */   lh       $a0, 8($s1)
/* C87788 80241CD8 0040802D */  daddu     $s0, $v0, $zero
/* C8778C 80241CDC 8E2300CC */  lw        $v1, 0xcc($s1)
/* C87790 80241CE0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C87794 80241CE4 8C630020 */  lw        $v1, 0x20($v1)
/* C87798 80241CE8 AE030028 */  sw        $v1, 0x28($s0)
/* C8779C 80241CEC 96220076 */  lhu       $v0, 0x76($s1)
/* C877A0 80241CF0 A602008E */  sh        $v0, 0x8e($s0)
/* C877A4 80241CF4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C877A8 80241CF8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C877AC 80241CFC C60E0040 */  lwc1      $f14, 0x40($s0)
/* C877B0 80241D00 8C460028 */  lw        $a2, 0x28($v0)
/* C877B4 80241D04 0C00A720 */  jal       atan2
/* C877B8 80241D08 8C470030 */   lw       $a3, 0x30($v0)
/* C877BC 80241D0C 2402000D */  addiu     $v0, $zero, 0xd
/* C877C0 80241D10 E600000C */  swc1      $f0, 0xc($s0)
/* C877C4 80241D14 AE420070 */  sw        $v0, 0x70($s2)
/* C877C8 80241D18 8FBF001C */  lw        $ra, 0x1c($sp)
/* C877CC 80241D1C 8FB20018 */  lw        $s2, 0x18($sp)
/* C877D0 80241D20 8FB10014 */  lw        $s1, 0x14($sp)
/* C877D4 80241D24 8FB00010 */  lw        $s0, 0x10($sp)
/* C877D8 80241D28 03E00008 */  jr        $ra
/* C877DC 80241D2C 27BD0020 */   addiu    $sp, $sp, 0x20
