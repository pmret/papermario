.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A2A240
/* A2A240 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A2A244 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* A2A248 80240008 0080882D */  daddu     $s1, $a0, $zero
/* A2A24C 8024000C AFBF001C */  sw        $ra, 0x1c($sp)
/* A2A250 80240010 AFB20018 */  sw        $s2, 0x18($sp)
/* A2A254 80240014 AFB00010 */  sw        $s0, 0x10($sp)
/* A2A258 80240018 8E30000C */  lw        $s0, 0xc($s1)
/* A2A25C 8024001C 8E050000 */  lw        $a1, ($s0)
/* A2A260 80240020 0C0B1EAF */  jal       get_variable
/* A2A264 80240024 26100004 */   addiu    $s0, $s0, 4
/* A2A268 80240028 8E050000 */  lw        $a1, ($s0)
/* A2A26C 8024002C 26100004 */  addiu     $s0, $s0, 4
/* A2A270 80240030 0220202D */  daddu     $a0, $s1, $zero
/* A2A274 80240034 0C0B1EAF */  jal       get_variable
/* A2A278 80240038 0040902D */   daddu    $s2, $v0, $zero
/* A2A27C 8024003C 0220202D */  daddu     $a0, $s1, $zero
/* A2A280 80240040 8E050000 */  lw        $a1, ($s0)
/* A2A284 80240044 0C0B1EAF */  jal       get_variable
/* A2A288 80240048 0040802D */   daddu    $s0, $v0, $zero
/* A2A28C 8024004C 0040882D */  daddu     $s1, $v0, $zero
/* A2A290 80240050 2402FFFF */  addiu     $v0, $zero, -1
/* A2A294 80240054 16020005 */  bne       $s0, $v0, .L8024006C
/* A2A298 80240058 24020001 */   addiu    $v0, $zero, 1
/* A2A29C 8024005C 0C04760B */  jal       func_8011D82C
/* A2A2A0 80240060 0220202D */   daddu    $a0, $s1, $zero
/* A2A2A4 80240064 08090043 */  j         .L8024010C
/* A2A2A8 80240068 24020002 */   addiu    $v0, $zero, 2
.L8024006C:
/* A2A2AC 8024006C 12420018 */  beq       $s2, $v0, .L802400D0
/* A2A2B0 80240070 2A420002 */   slti     $v0, $s2, 2
/* A2A2B4 80240074 10400005 */  beqz      $v0, .L8024008C
/* A2A2B8 80240078 24020002 */   addiu    $v0, $zero, 2
/* A2A2BC 8024007C 12400007 */  beqz      $s2, .L8024009C
/* A2A2C0 80240080 3412FFFF */   ori      $s2, $zero, 0xffff
/* A2A2C4 80240084 08090043 */  j         .L8024010C
/* A2A2C8 80240088 00000000 */   nop
.L8024008C:
/* A2A2CC 8024008C 1242001B */  beq       $s2, $v0, .L802400FC
/* A2A2D0 80240090 24020002 */   addiu    $v0, $zero, 2
/* A2A2D4 80240094 08090043 */  j         .L8024010C
/* A2A2D8 80240098 00000000 */   nop
.L8024009C:
/* A2A2DC 8024009C 8E040000 */  lw        $a0, ($s0)
/* A2A2E0 802400A0 1092001A */  beq       $a0, $s2, .L8024010C
/* A2A2E4 802400A4 24020002 */   addiu    $v0, $zero, 2
/* A2A2E8 802400A8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A2A2EC 802400AC 26100004 */   addiu    $s0, $s0, 4
/* A2A2F0 802400B0 0C046B4C */  jal       get_model_from_list_index
/* A2A2F4 802400B4 0040202D */   daddu    $a0, $v0, $zero
/* A2A2F8 802400B8 0040202D */  daddu     $a0, $v0, $zero
/* A2A2FC 802400BC 2405FFFF */  addiu     $a1, $zero, -1
/* A2A300 802400C0 0C046F1F */  jal       func_8011BC7C
/* A2A304 802400C4 0220302D */   daddu    $a2, $s1, $zero
/* A2A308 802400C8 08090027 */  j         .L8024009C
/* A2A30C 802400CC 00000000 */   nop
.L802400D0:
/* A2A310 802400D0 3412FFFF */  ori       $s2, $zero, 0xffff
.L802400D4:
/* A2A314 802400D4 8E020000 */  lw        $v0, ($s0)
/* A2A318 802400D8 1052000B */  beq       $v0, $s2, .L80240108
/* A2A31C 802400DC 2405FFFF */   addiu    $a1, $zero, -1
/* A2A320 802400E0 96040002 */  lhu       $a0, 2($s0)
/* A2A324 802400E4 0220302D */  daddu     $a2, $s1, $zero
/* A2A328 802400E8 26100004 */  addiu     $s0, $s0, 4
/* A2A32C 802400EC 0C046E54 */  jal       func_8011B950
/* A2A330 802400F0 0000382D */   daddu    $a3, $zero, $zero
/* A2A334 802400F4 08090035 */  j         .L802400D4
/* A2A338 802400F8 00000000 */   nop
.L802400FC:
/* A2A33C 802400FC 3C028015 */  lui       $v0, %hi(D_801512F0)
/* A2A340 80240100 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* A2A344 80240104 A0510000 */  sb        $s1, ($v0)
.L80240108:
/* A2A348 80240108 24020002 */  addiu     $v0, $zero, 2
.L8024010C:
/* A2A34C 8024010C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A2A350 80240110 8FB20018 */  lw        $s2, 0x18($sp)
/* A2A354 80240114 8FB10014 */  lw        $s1, 0x14($sp)
/* A2A358 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* A2A35C 8024011C 03E00008 */  jr        $ra
/* A2A360 80240120 27BD0020 */   addiu    $sp, $sp, 0x20
