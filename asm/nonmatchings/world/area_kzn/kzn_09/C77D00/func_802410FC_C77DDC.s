.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410FC_C77DDC
/* C77DDC 802410FC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C77DE0 80241100 AFB10034 */  sw        $s1, 0x34($sp)
/* C77DE4 80241104 0080882D */  daddu     $s1, $a0, $zero
/* C77DE8 80241108 AFBF0038 */  sw        $ra, 0x38($sp)
/* C77DEC 8024110C AFB00030 */  sw        $s0, 0x30($sp)
/* C77DF0 80241110 8E300148 */  lw        $s0, 0x148($s1)
/* C77DF4 80241114 0C00EABB */  jal       get_npc_unsafe
/* C77DF8 80241118 86040008 */   lh       $a0, 8($s0)
/* C77DFC 8024111C 0040282D */  daddu     $a1, $v0, $zero
/* C77E00 80241120 94A2008E */  lhu       $v0, 0x8e($a1)
/* C77E04 80241124 2442FFFF */  addiu     $v0, $v0, -1
/* C77E08 80241128 A4A2008E */  sh        $v0, 0x8e($a1)
/* C77E0C 8024112C 00021400 */  sll       $v0, $v0, 0x10
/* C77E10 80241130 1C400023 */  bgtz      $v0, .L802411C0
/* C77E14 80241134 24020004 */   addiu    $v0, $zero, 4
/* C77E18 80241138 8E0300CC */  lw        $v1, 0xcc($s0)
/* C77E1C 8024113C AE02006C */  sw        $v0, 0x6c($s0)
/* C77E20 80241140 8C620000 */  lw        $v0, ($v1)
/* C77E24 80241144 ACA20028 */  sw        $v0, 0x28($a1)
/* C77E28 80241148 9602007A */  lhu       $v0, 0x7a($s0)
/* C77E2C 8024114C A4A2008E */  sh        $v0, 0x8e($a1)
/* C77E30 80241150 8E020078 */  lw        $v0, 0x78($s0)
/* C77E34 80241154 28420008 */  slti      $v0, $v0, 8
/* C77E38 80241158 14400018 */  bnez      $v0, .L802411BC
/* C77E3C 8024115C 24020021 */   addiu    $v0, $zero, 0x21
/* C77E40 80241160 24040003 */  addiu     $a0, $zero, 3
/* C77E44 80241164 27A30028 */  addiu     $v1, $sp, 0x28
/* C77E48 80241168 84A700A8 */  lh        $a3, 0xa8($a1)
/* C77E4C 8024116C 3C013F80 */  lui       $at, 0x3f80
/* C77E50 80241170 44810000 */  mtc1      $at, $f0
/* C77E54 80241174 3C014000 */  lui       $at, 0x4000
/* C77E58 80241178 44811000 */  mtc1      $at, $f2
/* C77E5C 8024117C 3C01C1A0 */  lui       $at, 0xc1a0
/* C77E60 80241180 44812000 */  mtc1      $at, $f4
/* C77E64 80241184 44873000 */  mtc1      $a3, $f6
/* C77E68 80241188 00000000 */  nop       
/* C77E6C 8024118C 468031A0 */  cvt.s.w   $f6, $f6
/* C77E70 80241190 E7A00010 */  swc1      $f0, 0x10($sp)
/* C77E74 80241194 E7A20014 */  swc1      $f2, 0x14($sp)
/* C77E78 80241198 E7A40018 */  swc1      $f4, 0x18($sp)
/* C77E7C 8024119C 8E020078 */  lw        $v0, 0x78($s0)
/* C77E80 802411A0 44073000 */  mfc1      $a3, $f6
/* C77E84 802411A4 0000302D */  daddu     $a2, $zero, $zero
/* C77E88 802411A8 AFA30020 */  sw        $v1, 0x20($sp)
/* C77E8C 802411AC 2442FFFF */  addiu     $v0, $v0, -1
/* C77E90 802411B0 0C01BFA4 */  jal       fx_emote
/* C77E94 802411B4 AFA2001C */   sw       $v0, 0x1c($sp)
/* C77E98 802411B8 24020021 */  addiu     $v0, $zero, 0x21
.L802411BC:
/* C77E9C 802411BC AE220070 */  sw        $v0, 0x70($s1)
.L802411C0:
/* C77EA0 802411C0 8FBF0038 */  lw        $ra, 0x38($sp)
/* C77EA4 802411C4 8FB10034 */  lw        $s1, 0x34($sp)
/* C77EA8 802411C8 8FB00030 */  lw        $s0, 0x30($sp)
/* C77EAC 802411CC 03E00008 */  jr        $ra
/* C77EB0 802411D0 27BD0040 */   addiu    $sp, $sp, 0x40
