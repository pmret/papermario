.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242690
/* E079F0 80242690 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E079F4 80242694 AFBF0028 */  sw        $ra, 0x28($sp)
/* E079F8 80242698 AFB10024 */  sw        $s1, 0x24($sp)
/* E079FC 8024269C AFB00020 */  sw        $s0, 0x20($sp)
/* E07A00 802426A0 8C82000C */  lw        $v0, 0xc($a0)
/* E07A04 802426A4 0C0B1EAF */  jal       get_variable
/* E07A08 802426A8 8C450000 */   lw       $a1, ($v0)
/* E07A0C 802426AC 24030100 */  addiu     $v1, $zero, 0x100
/* E07A10 802426B0 0040882D */  daddu     $s1, $v0, $zero
/* E07A14 802426B4 3C028024 */  lui       $v0, 0x8024
/* E07A18 802426B8 244241F0 */  addiu     $v0, $v0, 0x41f0
/* E07A1C 802426BC 00118040 */  sll       $s0, $s1, 1
/* E07A20 802426C0 02118021 */  addu      $s0, $s0, $s1
/* E07A24 802426C4 001080C0 */  sll       $s0, $s0, 3
/* E07A28 802426C8 02028021 */  addu      $s0, $s0, $v0
/* E07A2C 802426CC AFA30010 */  sw        $v1, 0x10($sp)
/* E07A30 802426D0 8E020000 */  lw        $v0, ($s0)
/* E07A34 802426D4 AFA00018 */  sw        $zero, 0x18($sp)
/* E07A38 802426D8 AFA0001C */  sw        $zero, 0x1c($sp)
/* E07A3C 802426DC AFA20014 */  sw        $v0, 0x14($sp)
/* E07A40 802426E0 8E050004 */  lw        $a1, 4($s0)
/* E07A44 802426E4 24020001 */  addiu     $v0, $zero, 1
/* E07A48 802426E8 3C01802E */  lui       $at, 0x802e
/* E07A4C 802426EC AC22F524 */  sw        $v0, -0xadc($at)
/* E07A50 802426F0 0C00E219 */  jal       create_standard_npc
/* E07A54 802426F4 27A40010 */   addiu    $a0, $sp, 0x10
/* E07A58 802426F8 0C00E2B7 */  jal       get_npc_by_index
/* E07A5C 802426FC 0040202D */   daddu    $a0, $v0, $zero
/* E07A60 80242700 3C04FBFF */  lui       $a0, 0xfbff
/* E07A64 80242704 8C430000 */  lw        $v1, ($v0)
/* E07A68 80242708 3484FFFF */  ori       $a0, $a0, 0xffff
/* E07A6C 8024270C A05100A4 */  sb        $s1, 0xa4($v0)
/* E07A70 80242710 00641824 */  and       $v1, $v1, $a0
/* E07A74 80242714 AC430000 */  sw        $v1, ($v0)
/* E07A78 80242718 C6000008 */  lwc1      $f0, 8($s0)
/* E07A7C 8024271C E4400038 */  swc1      $f0, 0x38($v0)
/* E07A80 80242720 C600000C */  lwc1      $f0, 0xc($s0)
/* E07A84 80242724 E440003C */  swc1      $f0, 0x3c($v0)
/* E07A88 80242728 C6000010 */  lwc1      $f0, 0x10($s0)
/* E07A8C 8024272C E4400040 */  swc1      $f0, 0x40($v0)
/* E07A90 80242730 8E050014 */  lw        $a1, 0x14($s0)
/* E07A94 80242734 0C00ECD0 */  jal       set_npc_yaw
/* E07A98 80242738 0040202D */   daddu    $a0, $v0, $zero
/* E07A9C 8024273C 8FBF0028 */  lw        $ra, 0x28($sp)
/* E07AA0 80242740 8FB10024 */  lw        $s1, 0x24($sp)
/* E07AA4 80242744 8FB00020 */  lw        $s0, 0x20($sp)
/* E07AA8 80242748 24020002 */  addiu     $v0, $zero, 2
/* E07AAC 8024274C 03E00008 */  jr        $ra
/* E07AB0 80242750 27BD0030 */   addiu    $sp, $sp, 0x30
