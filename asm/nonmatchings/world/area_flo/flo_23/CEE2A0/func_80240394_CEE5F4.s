.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240394_CEE5F4
/* CEE5F4 80240394 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CEE5F8 80240398 AFB20018 */  sw        $s2, 0x18($sp)
/* CEE5FC 8024039C 0080902D */  daddu     $s2, $a0, $zero
/* CEE600 802403A0 AFBF001C */  sw        $ra, 0x1c($sp)
/* CEE604 802403A4 AFB10014 */  sw        $s1, 0x14($sp)
/* CEE608 802403A8 AFB00010 */  sw        $s0, 0x10($sp)
/* CEE60C 802403AC 8E510148 */  lw        $s1, 0x148($s2)
/* CEE610 802403B0 0C00EABB */  jal       get_npc_unsafe
/* CEE614 802403B4 86240008 */   lh       $a0, 8($s1)
/* CEE618 802403B8 0040802D */  daddu     $s0, $v0, $zero
/* CEE61C 802403BC 8E2300CC */  lw        $v1, 0xcc($s1)
/* CEE620 802403C0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CEE624 802403C4 8C630020 */  lw        $v1, 0x20($v1)
/* CEE628 802403C8 AE030028 */  sw        $v1, 0x28($s0)
/* CEE62C 802403CC 96220076 */  lhu       $v0, 0x76($s1)
/* CEE630 802403D0 A602008E */  sh        $v0, 0x8e($s0)
/* CEE634 802403D4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CEE638 802403D8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CEE63C 802403DC C60E0040 */  lwc1      $f14, 0x40($s0)
/* CEE640 802403E0 8C460028 */  lw        $a2, 0x28($v0)
/* CEE644 802403E4 0C00A720 */  jal       atan2
/* CEE648 802403E8 8C470030 */   lw       $a3, 0x30($v0)
/* CEE64C 802403EC 2402000D */  addiu     $v0, $zero, 0xd
/* CEE650 802403F0 E600000C */  swc1      $f0, 0xc($s0)
/* CEE654 802403F4 AE420070 */  sw        $v0, 0x70($s2)
/* CEE658 802403F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* CEE65C 802403FC 8FB20018 */  lw        $s2, 0x18($sp)
/* CEE660 80240400 8FB10014 */  lw        $s1, 0x14($sp)
/* CEE664 80240404 8FB00010 */  lw        $s0, 0x10($sp)
/* CEE668 80240408 03E00008 */  jr        $ra
/* CEE66C 8024040C 27BD0020 */   addiu    $sp, $sp, 0x20
