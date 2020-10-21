.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425C8_911C78
/* 911C78 802425C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 911C7C 802425CC AFB20018 */  sw        $s2, 0x18($sp)
/* 911C80 802425D0 0080902D */  daddu     $s2, $a0, $zero
/* 911C84 802425D4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 911C88 802425D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 911C8C 802425DC AFB00010 */  sw        $s0, 0x10($sp)
/* 911C90 802425E0 8E510148 */  lw        $s1, 0x148($s2)
/* 911C94 802425E4 0C00EABB */  jal       get_npc_unsafe
/* 911C98 802425E8 86240008 */   lh       $a0, 8($s1)
/* 911C9C 802425EC 0040802D */  daddu     $s0, $v0, $zero
/* 911CA0 802425F0 9602008E */  lhu       $v0, 0x8e($s0)
/* 911CA4 802425F4 2442FFFF */  addiu     $v0, $v0, -1
/* 911CA8 802425F8 A602008E */  sh        $v0, 0x8e($s0)
/* 911CAC 802425FC 00021400 */  sll       $v0, $v0, 0x10
/* 911CB0 80242600 1C400012 */  bgtz      $v0, .L8024264C
/* 911CB4 80242604 00000000 */   nop      
/* 911CB8 80242608 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 911CBC 8024260C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 911CC0 80242610 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 911CC4 80242614 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 911CC8 80242618 8C460028 */  lw        $a2, 0x28($v0)
/* 911CCC 8024261C 0C00A720 */  jal       atan2
/* 911CD0 80242620 8C470030 */   lw       $a3, 0x30($v0)
/* 911CD4 80242624 0200202D */  daddu     $a0, $s0, $zero
/* 911CD8 80242628 0C00EAE8 */  jal       enable_npc_shadow
/* 911CDC 8024262C E600000C */   swc1     $f0, 0xc($s0)
/* 911CE0 80242630 8E2200CC */  lw        $v0, 0xcc($s1)
/* 911CE4 80242634 8C430028 */  lw        $v1, 0x28($v0)
/* 911CE8 80242638 24020008 */  addiu     $v0, $zero, 8
/* 911CEC 8024263C A602008E */  sh        $v0, 0x8e($s0)
/* 911CF0 80242640 24020003 */  addiu     $v0, $zero, 3
/* 911CF4 80242644 AE030028 */  sw        $v1, 0x28($s0)
/* 911CF8 80242648 AE420070 */  sw        $v0, 0x70($s2)
.L8024264C:
/* 911CFC 8024264C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 911D00 80242650 8FB20018 */  lw        $s2, 0x18($sp)
/* 911D04 80242654 8FB10014 */  lw        $s1, 0x14($sp)
/* 911D08 80242658 8FB00010 */  lw        $s0, 0x10($sp)
/* 911D0C 8024265C 03E00008 */  jr        $ra
/* 911D10 80242660 27BD0020 */   addiu    $sp, $sp, 0x20
