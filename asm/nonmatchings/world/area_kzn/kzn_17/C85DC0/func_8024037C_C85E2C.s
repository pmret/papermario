.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024037C_C85E2C
/* C85E2C 8024037C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C85E30 80240380 AFB10014 */  sw        $s1, 0x14($sp)
/* C85E34 80240384 0080882D */  daddu     $s1, $a0, $zero
/* C85E38 80240388 AFBF0018 */  sw        $ra, 0x18($sp)
/* C85E3C 8024038C AFB00010 */  sw        $s0, 0x10($sp)
/* C85E40 80240390 8E300148 */  lw        $s0, 0x148($s1)
/* C85E44 80240394 0C00EABB */  jal       get_npc_unsafe
/* C85E48 80240398 86040008 */   lh       $a0, 8($s0)
/* C85E4C 8024039C 0040202D */  daddu     $a0, $v0, $zero
/* C85E50 802403A0 9482008E */  lhu       $v0, 0x8e($a0)
/* C85E54 802403A4 2442FFFF */  addiu     $v0, $v0, -1
/* C85E58 802403A8 A482008E */  sh        $v0, 0x8e($a0)
/* C85E5C 802403AC 00021400 */  sll       $v0, $v0, 0x10
/* C85E60 802403B0 1C400009 */  bgtz      $v0, .L802403D8
/* C85E64 802403B4 24020003 */   addiu    $v0, $zero, 3
/* C85E68 802403B8 96030076 */  lhu       $v1, 0x76($s0)
/* C85E6C 802403BC AE02006C */  sw        $v0, 0x6c($s0)
/* C85E70 802403C0 A483008E */  sh        $v1, 0x8e($a0)
/* C85E74 802403C4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C85E78 802403C8 8C420024 */  lw        $v0, 0x24($v0)
/* C85E7C 802403CC AC820028 */  sw        $v0, 0x28($a0)
/* C85E80 802403D0 24020020 */  addiu     $v0, $zero, 0x20
/* C85E84 802403D4 AE220070 */  sw        $v0, 0x70($s1)
.L802403D8:
/* C85E88 802403D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C85E8C 802403DC 8FB10014 */  lw        $s1, 0x14($sp)
/* C85E90 802403E0 8FB00010 */  lw        $s0, 0x10($sp)
/* C85E94 802403E4 03E00008 */  jr        $ra
/* C85E98 802403E8 27BD0020 */   addiu    $sp, $sp, 0x20
