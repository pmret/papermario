.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024268C_BE5E3C
/* BE5E3C 8024268C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE5E40 80242690 AFB20018 */  sw        $s2, 0x18($sp)
/* BE5E44 80242694 0080902D */  daddu     $s2, $a0, $zero
/* BE5E48 80242698 AFBF001C */  sw        $ra, 0x1c($sp)
/* BE5E4C 8024269C AFB10014 */  sw        $s1, 0x14($sp)
/* BE5E50 802426A0 AFB00010 */  sw        $s0, 0x10($sp)
/* BE5E54 802426A4 8E510148 */  lw        $s1, 0x148($s2)
/* BE5E58 802426A8 0C00EABB */  jal       get_npc_unsafe
/* BE5E5C 802426AC 86240008 */   lh       $a0, 8($s1)
/* BE5E60 802426B0 0040802D */  daddu     $s0, $v0, $zero
/* BE5E64 802426B4 9602008E */  lhu       $v0, 0x8e($s0)
/* BE5E68 802426B8 2442FFFF */  addiu     $v0, $v0, -1
/* BE5E6C 802426BC A602008E */  sh        $v0, 0x8e($s0)
/* BE5E70 802426C0 00021400 */  sll       $v0, $v0, 0x10
/* BE5E74 802426C4 1C400012 */  bgtz      $v0, .L80242710
/* BE5E78 802426C8 00000000 */   nop      
/* BE5E7C 802426CC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE5E80 802426D0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE5E84 802426D4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE5E88 802426D8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE5E8C 802426DC 8C460028 */  lw        $a2, 0x28($v0)
/* BE5E90 802426E0 0C00A720 */  jal       atan2
/* BE5E94 802426E4 8C470030 */   lw       $a3, 0x30($v0)
/* BE5E98 802426E8 0200202D */  daddu     $a0, $s0, $zero
/* BE5E9C 802426EC 0C00EAE8 */  jal       enable_npc_shadow
/* BE5EA0 802426F0 E600000C */   swc1     $f0, 0xc($s0)
/* BE5EA4 802426F4 8E2200CC */  lw        $v0, 0xcc($s1)
/* BE5EA8 802426F8 8C430028 */  lw        $v1, 0x28($v0)
/* BE5EAC 802426FC 24020008 */  addiu     $v0, $zero, 8
/* BE5EB0 80242700 A602008E */  sh        $v0, 0x8e($s0)
/* BE5EB4 80242704 24020003 */  addiu     $v0, $zero, 3
/* BE5EB8 80242708 AE030028 */  sw        $v1, 0x28($s0)
/* BE5EBC 8024270C AE420070 */  sw        $v0, 0x70($s2)
.L80242710:
/* BE5EC0 80242710 8FBF001C */  lw        $ra, 0x1c($sp)
/* BE5EC4 80242714 8FB20018 */  lw        $s2, 0x18($sp)
/* BE5EC8 80242718 8FB10014 */  lw        $s1, 0x14($sp)
/* BE5ECC 8024271C 8FB00010 */  lw        $s0, 0x10($sp)
/* BE5ED0 80242720 03E00008 */  jr        $ra
/* BE5ED4 80242724 27BD0020 */   addiu    $sp, $sp, 0x20
