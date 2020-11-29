.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242680_DF9080
/* DF9080 80242680 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DF9084 80242684 AFBF0028 */  sw        $ra, 0x28($sp)
/* DF9088 80242688 AFB10024 */  sw        $s1, 0x24($sp)
/* DF908C 8024268C AFB00020 */  sw        $s0, 0x20($sp)
/* DF9090 80242690 8C82000C */  lw        $v0, 0xc($a0)
/* DF9094 80242694 0C0B1EAF */  jal       get_variable
/* DF9098 80242698 8C450000 */   lw       $a1, ($v0)
/* DF909C 8024269C 24030100 */  addiu     $v1, $zero, 0x100
/* DF90A0 802426A0 0040882D */  daddu     $s1, $v0, $zero
/* DF90A4 802426A4 3C028024 */  lui       $v0, %hi(D_80244D74)
/* DF90A8 802426A8 24424D74 */  addiu     $v0, $v0, %lo(D_80244D74)
/* DF90AC 802426AC 00118040 */  sll       $s0, $s1, 1
/* DF90B0 802426B0 02118021 */  addu      $s0, $s0, $s1
/* DF90B4 802426B4 001080C0 */  sll       $s0, $s0, 3
/* DF90B8 802426B8 02028021 */  addu      $s0, $s0, $v0
/* DF90BC 802426BC AFA30010 */  sw        $v1, 0x10($sp)
/* DF90C0 802426C0 8E020000 */  lw        $v0, ($s0)
/* DF90C4 802426C4 AFA00018 */  sw        $zero, 0x18($sp)
/* DF90C8 802426C8 AFA0001C */  sw        $zero, 0x1c($sp)
/* DF90CC 802426CC AFA20014 */  sw        $v0, 0x14($sp)
/* DF90D0 802426D0 8E050004 */  lw        $a1, 4($s0)
/* DF90D4 802426D4 24020001 */  addiu     $v0, $zero, 1
/* DF90D8 802426D8 3C01802E */  lui       $at, %hi(D_802DF524)
/* DF90DC 802426DC AC22F524 */  sw        $v0, %lo(D_802DF524)($at)
/* DF90E0 802426E0 0C00E219 */  jal       create_standard_npc
/* DF90E4 802426E4 27A40010 */   addiu    $a0, $sp, 0x10
/* DF90E8 802426E8 0C00E2B7 */  jal       get_npc_by_index
/* DF90EC 802426EC 0040202D */   daddu    $a0, $v0, $zero
/* DF90F0 802426F0 3C04FBFF */  lui       $a0, 0xfbff
/* DF90F4 802426F4 8C430000 */  lw        $v1, ($v0)
/* DF90F8 802426F8 3484FFFF */  ori       $a0, $a0, 0xffff
/* DF90FC 802426FC A05100A4 */  sb        $s1, 0xa4($v0)
/* DF9100 80242700 00641824 */  and       $v1, $v1, $a0
/* DF9104 80242704 AC430000 */  sw        $v1, ($v0)
/* DF9108 80242708 C6000008 */  lwc1      $f0, 8($s0)
/* DF910C 8024270C E4400038 */  swc1      $f0, 0x38($v0)
/* DF9110 80242710 C600000C */  lwc1      $f0, 0xc($s0)
/* DF9114 80242714 E440003C */  swc1      $f0, 0x3c($v0)
/* DF9118 80242718 C6000010 */  lwc1      $f0, 0x10($s0)
/* DF911C 8024271C E4400040 */  swc1      $f0, 0x40($v0)
/* DF9120 80242720 8E050014 */  lw        $a1, 0x14($s0)
/* DF9124 80242724 0C00ECD0 */  jal       set_npc_yaw
/* DF9128 80242728 0040202D */   daddu    $a0, $v0, $zero
/* DF912C 8024272C 8FBF0028 */  lw        $ra, 0x28($sp)
/* DF9130 80242730 8FB10024 */  lw        $s1, 0x24($sp)
/* DF9134 80242734 8FB00020 */  lw        $s0, 0x20($sp)
/* DF9138 80242738 24020002 */  addiu     $v0, $zero, 2
/* DF913C 8024273C 03E00008 */  jr        $ra
/* DF9140 80242740 27BD0030 */   addiu    $sp, $sp, 0x30
