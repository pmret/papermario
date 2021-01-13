.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B80000
/* B80000 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B80004 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* B80008 80240008 0080882D */  daddu     $s1, $a0, $zero
/* B8000C 8024000C AFBF001C */  sw        $ra, 0x1c($sp)
/* B80010 80240010 AFB20018 */  sw        $s2, 0x18($sp)
/* B80014 80240014 AFB00010 */  sw        $s0, 0x10($sp)
/* B80018 80240018 8E30000C */  lw        $s0, 0xc($s1)
/* B8001C 8024001C 8E050000 */  lw        $a1, ($s0)
/* B80020 80240020 0C0B1EAF */  jal       get_variable
/* B80024 80240024 26100004 */   addiu    $s0, $s0, 4
/* B80028 80240028 8E050000 */  lw        $a1, ($s0)
/* B8002C 8024002C 26100004 */  addiu     $s0, $s0, 4
/* B80030 80240030 0220202D */  daddu     $a0, $s1, $zero
/* B80034 80240034 0C0B1EAF */  jal       get_variable
/* B80038 80240038 0040902D */   daddu    $s2, $v0, $zero
/* B8003C 8024003C 0220202D */  daddu     $a0, $s1, $zero
/* B80040 80240040 8E050000 */  lw        $a1, ($s0)
/* B80044 80240044 0C0B1EAF */  jal       get_variable
/* B80048 80240048 0040802D */   daddu    $s0, $v0, $zero
/* B8004C 8024004C 0040882D */  daddu     $s1, $v0, $zero
/* B80050 80240050 2402FFFF */  addiu     $v0, $zero, -1
/* B80054 80240054 16020005 */  bne       $s0, $v0, .L8024006C
/* B80058 80240058 24020001 */   addiu    $v0, $zero, 1
/* B8005C 8024005C 0C04760B */  jal       func_8011D82C
/* B80060 80240060 0220202D */   daddu    $a0, $s1, $zero
/* B80064 80240064 08090043 */  j         .L8024010C
/* B80068 80240068 24020002 */   addiu    $v0, $zero, 2
.L8024006C:
/* B8006C 8024006C 12420018 */  beq       $s2, $v0, .L802400D0
/* B80070 80240070 2A420002 */   slti     $v0, $s2, 2
/* B80074 80240074 10400005 */  beqz      $v0, .L8024008C
/* B80078 80240078 24020002 */   addiu    $v0, $zero, 2
/* B8007C 8024007C 12400007 */  beqz      $s2, .L8024009C
/* B80080 80240080 3412FFFF */   ori      $s2, $zero, 0xffff
/* B80084 80240084 08090043 */  j         .L8024010C
/* B80088 80240088 00000000 */   nop
.L8024008C:
/* B8008C 8024008C 1242001B */  beq       $s2, $v0, .L802400FC
/* B80090 80240090 24020002 */   addiu    $v0, $zero, 2
/* B80094 80240094 08090043 */  j         .L8024010C
/* B80098 80240098 00000000 */   nop
.L8024009C:
/* B8009C 8024009C 8E040000 */  lw        $a0, ($s0)
/* B800A0 802400A0 1092001A */  beq       $a0, $s2, .L8024010C
/* B800A4 802400A4 24020002 */   addiu    $v0, $zero, 2
/* B800A8 802400A8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B800AC 802400AC 26100004 */   addiu    $s0, $s0, 4
/* B800B0 802400B0 0C046B4C */  jal       get_model_from_list_index
/* B800B4 802400B4 0040202D */   daddu    $a0, $v0, $zero
/* B800B8 802400B8 0040202D */  daddu     $a0, $v0, $zero
/* B800BC 802400BC 2405FFFF */  addiu     $a1, $zero, -1
/* B800C0 802400C0 0C046F1F */  jal       func_8011BC7C
/* B800C4 802400C4 0220302D */   daddu    $a2, $s1, $zero
/* B800C8 802400C8 08090027 */  j         .L8024009C
/* B800CC 802400CC 00000000 */   nop
.L802400D0:
/* B800D0 802400D0 3412FFFF */  ori       $s2, $zero, 0xffff
.L802400D4:
/* B800D4 802400D4 8E020000 */  lw        $v0, ($s0)
/* B800D8 802400D8 1052000B */  beq       $v0, $s2, .L80240108
/* B800DC 802400DC 2405FFFF */   addiu    $a1, $zero, -1
/* B800E0 802400E0 96040002 */  lhu       $a0, 2($s0)
/* B800E4 802400E4 0220302D */  daddu     $a2, $s1, $zero
/* B800E8 802400E8 26100004 */  addiu     $s0, $s0, 4
/* B800EC 802400EC 0C046E54 */  jal       func_8011B950
/* B800F0 802400F0 0000382D */   daddu    $a3, $zero, $zero
/* B800F4 802400F4 08090035 */  j         .L802400D4
/* B800F8 802400F8 00000000 */   nop
.L802400FC:
/* B800FC 802400FC 3C028015 */  lui       $v0, %hi(D_801512F0)
/* B80100 80240100 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* B80104 80240104 A0510000 */  sb        $s1, ($v0)
.L80240108:
/* B80108 80240108 24020002 */  addiu     $v0, $zero, 2
.L8024010C:
/* B8010C 8024010C 8FBF001C */  lw        $ra, 0x1c($sp)
/* B80110 80240110 8FB20018 */  lw        $s2, 0x18($sp)
/* B80114 80240114 8FB10014 */  lw        $s1, 0x14($sp)
/* B80118 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* B8011C 8024011C 03E00008 */  jr        $ra
/* B80120 80240120 27BD0020 */   addiu    $sp, $sp, 0x20
