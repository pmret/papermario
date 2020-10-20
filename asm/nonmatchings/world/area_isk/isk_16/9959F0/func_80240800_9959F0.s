.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240800_9959F0
/* 9959F0 80240800 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9959F4 80240804 AFB10014 */  sw        $s1, 0x14($sp)
/* 9959F8 80240808 0080882D */  daddu     $s1, $a0, $zero
/* 9959FC 8024080C AFBF001C */  sw        $ra, 0x1c($sp)
/* 995A00 80240810 AFB20018 */  sw        $s2, 0x18($sp)
/* 995A04 80240814 AFB00010 */  sw        $s0, 0x10($sp)
/* 995A08 80240818 8E30000C */  lw        $s0, 0xc($s1)
/* 995A0C 8024081C 8E050000 */  lw        $a1, ($s0)
/* 995A10 80240820 0C0B1EAF */  jal       get_variable
/* 995A14 80240824 26100004 */   addiu    $s0, $s0, 4
/* 995A18 80240828 8E050000 */  lw        $a1, ($s0)
/* 995A1C 8024082C 26100004 */  addiu     $s0, $s0, 4
/* 995A20 80240830 0220202D */  daddu     $a0, $s1, $zero
/* 995A24 80240834 0C0B1EAF */  jal       get_variable
/* 995A28 80240838 0040902D */   daddu    $s2, $v0, $zero
/* 995A2C 8024083C 0220202D */  daddu     $a0, $s1, $zero
/* 995A30 80240840 8E050000 */  lw        $a1, ($s0)
/* 995A34 80240844 0C0B1EAF */  jal       get_variable
/* 995A38 80240848 0040802D */   daddu    $s0, $v0, $zero
/* 995A3C 8024084C 0040882D */  daddu     $s1, $v0, $zero
/* 995A40 80240850 2402FFFF */  addiu     $v0, $zero, -1
/* 995A44 80240854 16020005 */  bne       $s0, $v0, .L8024086C
/* 995A48 80240858 24020001 */   addiu    $v0, $zero, 1
/* 995A4C 8024085C 0C04760B */  jal       func_8011D82C
/* 995A50 80240860 0220202D */   daddu    $a0, $s1, $zero
/* 995A54 80240864 08090243 */  j         .L8024090C
/* 995A58 80240868 24020002 */   addiu    $v0, $zero, 2
.L8024086C:
/* 995A5C 8024086C 12420018 */  beq       $s2, $v0, .L802408D0
/* 995A60 80240870 2A420002 */   slti     $v0, $s2, 2
/* 995A64 80240874 10400005 */  beqz      $v0, .L8024088C
/* 995A68 80240878 24020002 */   addiu    $v0, $zero, 2
/* 995A6C 8024087C 12400007 */  beqz      $s2, .L8024089C
/* 995A70 80240880 3412FFFF */   ori      $s2, $zero, 0xffff
/* 995A74 80240884 08090243 */  j         .L8024090C
/* 995A78 80240888 00000000 */   nop      
.L8024088C:
/* 995A7C 8024088C 1242001B */  beq       $s2, $v0, .L802408FC
/* 995A80 80240890 24020002 */   addiu    $v0, $zero, 2
/* 995A84 80240894 08090243 */  j         .L8024090C
/* 995A88 80240898 00000000 */   nop      
.L8024089C:
/* 995A8C 8024089C 8E040000 */  lw        $a0, ($s0)
/* 995A90 802408A0 1092001A */  beq       $a0, $s2, .L8024090C
/* 995A94 802408A4 24020002 */   addiu    $v0, $zero, 2
/* 995A98 802408A8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 995A9C 802408AC 26100004 */   addiu    $s0, $s0, 4
/* 995AA0 802408B0 0C046B4C */  jal       get_model_from_list_index
/* 995AA4 802408B4 0040202D */   daddu    $a0, $v0, $zero
/* 995AA8 802408B8 0040202D */  daddu     $a0, $v0, $zero
/* 995AAC 802408BC 2405FFFF */  addiu     $a1, $zero, -1
/* 995AB0 802408C0 0C046F1F */  jal       func_8011BC7C
/* 995AB4 802408C4 0220302D */   daddu    $a2, $s1, $zero
/* 995AB8 802408C8 08090227 */  j         .L8024089C
/* 995ABC 802408CC 00000000 */   nop      
.L802408D0:
/* 995AC0 802408D0 3412FFFF */  ori       $s2, $zero, 0xffff
.L802408D4:
/* 995AC4 802408D4 8E020000 */  lw        $v0, ($s0)
/* 995AC8 802408D8 1052000B */  beq       $v0, $s2, .L80240908
/* 995ACC 802408DC 2405FFFF */   addiu    $a1, $zero, -1
/* 995AD0 802408E0 96040002 */  lhu       $a0, 2($s0)
/* 995AD4 802408E4 0220302D */  daddu     $a2, $s1, $zero
/* 995AD8 802408E8 26100004 */  addiu     $s0, $s0, 4
/* 995ADC 802408EC 0C046E54 */  jal       func_8011B950
/* 995AE0 802408F0 0000382D */   daddu    $a3, $zero, $zero
/* 995AE4 802408F4 08090235 */  j         .L802408D4
/* 995AE8 802408F8 00000000 */   nop      
.L802408FC:
/* 995AEC 802408FC 3C028015 */  lui       $v0, 0x8015
/* 995AF0 80240900 8C4212F0 */  lw        $v0, 0x12f0($v0)
/* 995AF4 80240904 A0510000 */  sb        $s1, ($v0)
.L80240908:
/* 995AF8 80240908 24020002 */  addiu     $v0, $zero, 2
.L8024090C:
/* 995AFC 8024090C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 995B00 80240910 8FB20018 */  lw        $s2, 0x18($sp)
/* 995B04 80240914 8FB10014 */  lw        $s1, 0x14($sp)
/* 995B08 80240918 8FB00010 */  lw        $s0, 0x10($sp)
/* 995B0C 8024091C 03E00008 */  jr        $ra
/* 995B10 80240920 27BD0020 */   addiu    $sp, $sp, 0x20
