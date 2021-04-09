.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sbk_30_UnkFunc27
/* 93F5F0 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 93F5F4 80240044 AFB10014 */  sw        $s1, 0x14($sp)
/* 93F5F8 80240048 0080882D */  daddu     $s1, $a0, $zero
/* 93F5FC 8024004C AFBF001C */  sw        $ra, 0x1c($sp)
/* 93F600 80240050 AFB20018 */  sw        $s2, 0x18($sp)
/* 93F604 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* 93F608 80240058 8E30000C */  lw        $s0, 0xc($s1)
/* 93F60C 8024005C 8E050000 */  lw        $a1, ($s0)
/* 93F610 80240060 0C0B1EAF */  jal       get_variable
/* 93F614 80240064 26100004 */   addiu    $s0, $s0, 4
/* 93F618 80240068 8E050000 */  lw        $a1, ($s0)
/* 93F61C 8024006C 26100004 */  addiu     $s0, $s0, 4
/* 93F620 80240070 0220202D */  daddu     $a0, $s1, $zero
/* 93F624 80240074 0C0B1EAF */  jal       get_variable
/* 93F628 80240078 0040902D */   daddu    $s2, $v0, $zero
/* 93F62C 8024007C 0220202D */  daddu     $a0, $s1, $zero
/* 93F630 80240080 8E050000 */  lw        $a1, ($s0)
/* 93F634 80240084 0C0B1EAF */  jal       get_variable
/* 93F638 80240088 0040802D */   daddu    $s0, $v0, $zero
/* 93F63C 8024008C 0040882D */  daddu     $s1, $v0, $zero
/* 93F640 80240090 2402FFFF */  addiu     $v0, $zero, -1
/* 93F644 80240094 16020005 */  bne       $s0, $v0, .L802400AC
/* 93F648 80240098 24020001 */   addiu    $v0, $zero, 1
/* 93F64C 8024009C 0C04760B */  jal       func_8011D82C
/* 93F650 802400A0 0220202D */   daddu    $a0, $s1, $zero
/* 93F654 802400A4 08090053 */  j         .L8024014C
/* 93F658 802400A8 24020002 */   addiu    $v0, $zero, 2
.L802400AC:
/* 93F65C 802400AC 12420018 */  beq       $s2, $v0, .L80240110
/* 93F660 802400B0 2A420002 */   slti     $v0, $s2, 2
/* 93F664 802400B4 10400005 */  beqz      $v0, .L802400CC
/* 93F668 802400B8 24020002 */   addiu    $v0, $zero, 2
/* 93F66C 802400BC 12400007 */  beqz      $s2, .L802400DC
/* 93F670 802400C0 3412FFFF */   ori      $s2, $zero, 0xffff
/* 93F674 802400C4 08090053 */  j         .L8024014C
/* 93F678 802400C8 00000000 */   nop
.L802400CC:
/* 93F67C 802400CC 1242001B */  beq       $s2, $v0, .L8024013C
/* 93F680 802400D0 24020002 */   addiu    $v0, $zero, 2
/* 93F684 802400D4 08090053 */  j         .L8024014C
/* 93F688 802400D8 00000000 */   nop
.L802400DC:
/* 93F68C 802400DC 8E040000 */  lw        $a0, ($s0)
/* 93F690 802400E0 1092001A */  beq       $a0, $s2, .L8024014C
/* 93F694 802400E4 24020002 */   addiu    $v0, $zero, 2
/* 93F698 802400E8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 93F69C 802400EC 26100004 */   addiu    $s0, $s0, 4
/* 93F6A0 802400F0 0C046B4C */  jal       get_model_from_list_index
/* 93F6A4 802400F4 0040202D */   daddu    $a0, $v0, $zero
/* 93F6A8 802400F8 0040202D */  daddu     $a0, $v0, $zero
/* 93F6AC 802400FC 2405FFFF */  addiu     $a1, $zero, -1
/* 93F6B0 80240100 0C046F1F */  jal       func_8011BC7C
/* 93F6B4 80240104 0220302D */   daddu    $a2, $s1, $zero
/* 93F6B8 80240108 08090037 */  j         .L802400DC
/* 93F6BC 8024010C 00000000 */   nop
.L80240110:
/* 93F6C0 80240110 3412FFFF */  ori       $s2, $zero, 0xffff
.L80240114:
/* 93F6C4 80240114 8E020000 */  lw        $v0, ($s0)
/* 93F6C8 80240118 1052000B */  beq       $v0, $s2, .L80240148
/* 93F6CC 8024011C 2405FFFF */   addiu    $a1, $zero, -1
/* 93F6D0 80240120 96040002 */  lhu       $a0, 2($s0)
/* 93F6D4 80240124 0220302D */  daddu     $a2, $s1, $zero
/* 93F6D8 80240128 26100004 */  addiu     $s0, $s0, 4
/* 93F6DC 8024012C 0C046E54 */  jal       func_8011B950
/* 93F6E0 80240130 0000382D */   daddu    $a3, $zero, $zero
/* 93F6E4 80240134 08090045 */  j         .L80240114
/* 93F6E8 80240138 00000000 */   nop
.L8024013C:
/* 93F6EC 8024013C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 93F6F0 80240140 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 93F6F4 80240144 A0510000 */  sb        $s1, ($v0)
.L80240148:
/* 93F6F8 80240148 24020002 */  addiu     $v0, $zero, 2
.L8024014C:
/* 93F6FC 8024014C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 93F700 80240150 8FB20018 */  lw        $s2, 0x18($sp)
/* 93F704 80240154 8FB10014 */  lw        $s1, 0x14($sp)
/* 93F708 80240158 8FB00010 */  lw        $s0, 0x10($sp)
/* 93F70C 8024015C 03E00008 */  jr        $ra
/* 93F710 80240160 27BD0020 */   addiu    $sp, $sp, 0x20
