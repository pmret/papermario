.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_92A2F0
/* 92A2F0 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 92A2F4 80240044 AFB10014 */  sw        $s1, 0x14($sp)
/* 92A2F8 80240048 0080882D */  daddu     $s1, $a0, $zero
/* 92A2FC 8024004C AFBF001C */  sw        $ra, 0x1c($sp)
/* 92A300 80240050 AFB20018 */  sw        $s2, 0x18($sp)
/* 92A304 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* 92A308 80240058 8E30000C */  lw        $s0, 0xc($s1)
/* 92A30C 8024005C 8E050000 */  lw        $a1, ($s0)
/* 92A310 80240060 0C0B1EAF */  jal       get_variable
/* 92A314 80240064 26100004 */   addiu    $s0, $s0, 4
/* 92A318 80240068 8E050000 */  lw        $a1, ($s0)
/* 92A31C 8024006C 26100004 */  addiu     $s0, $s0, 4
/* 92A320 80240070 0220202D */  daddu     $a0, $s1, $zero
/* 92A324 80240074 0C0B1EAF */  jal       get_variable
/* 92A328 80240078 0040902D */   daddu    $s2, $v0, $zero
/* 92A32C 8024007C 0220202D */  daddu     $a0, $s1, $zero
/* 92A330 80240080 8E050000 */  lw        $a1, ($s0)
/* 92A334 80240084 0C0B1EAF */  jal       get_variable
/* 92A338 80240088 0040802D */   daddu    $s0, $v0, $zero
/* 92A33C 8024008C 0040882D */  daddu     $s1, $v0, $zero
/* 92A340 80240090 2402FFFF */  addiu     $v0, $zero, -1
/* 92A344 80240094 16020005 */  bne       $s0, $v0, .L802400AC
/* 92A348 80240098 24020001 */   addiu    $v0, $zero, 1
/* 92A34C 8024009C 0C04760B */  jal       func_8011D82C
/* 92A350 802400A0 0220202D */   daddu    $a0, $s1, $zero
/* 92A354 802400A4 08090053 */  j         .L8024014C
/* 92A358 802400A8 24020002 */   addiu    $v0, $zero, 2
.L802400AC:
/* 92A35C 802400AC 12420018 */  beq       $s2, $v0, .L80240110
/* 92A360 802400B0 2A420002 */   slti     $v0, $s2, 2
/* 92A364 802400B4 10400005 */  beqz      $v0, .L802400CC
/* 92A368 802400B8 24020002 */   addiu    $v0, $zero, 2
/* 92A36C 802400BC 12400007 */  beqz      $s2, .L802400DC
/* 92A370 802400C0 3412FFFF */   ori      $s2, $zero, 0xffff
/* 92A374 802400C4 08090053 */  j         .L8024014C
/* 92A378 802400C8 00000000 */   nop
.L802400CC:
/* 92A37C 802400CC 1242001B */  beq       $s2, $v0, .L8024013C
/* 92A380 802400D0 24020002 */   addiu    $v0, $zero, 2
/* 92A384 802400D4 08090053 */  j         .L8024014C
/* 92A388 802400D8 00000000 */   nop
.L802400DC:
/* 92A38C 802400DC 8E040000 */  lw        $a0, ($s0)
/* 92A390 802400E0 1092001A */  beq       $a0, $s2, .L8024014C
/* 92A394 802400E4 24020002 */   addiu    $v0, $zero, 2
/* 92A398 802400E8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 92A39C 802400EC 26100004 */   addiu    $s0, $s0, 4
/* 92A3A0 802400F0 0C046B4C */  jal       get_model_from_list_index
/* 92A3A4 802400F4 0040202D */   daddu    $a0, $v0, $zero
/* 92A3A8 802400F8 0040202D */  daddu     $a0, $v0, $zero
/* 92A3AC 802400FC 2405FFFF */  addiu     $a1, $zero, -1
/* 92A3B0 80240100 0C046F1F */  jal       func_8011BC7C
/* 92A3B4 80240104 0220302D */   daddu    $a2, $s1, $zero
/* 92A3B8 80240108 08090037 */  j         .L802400DC
/* 92A3BC 8024010C 00000000 */   nop
.L80240110:
/* 92A3C0 80240110 3412FFFF */  ori       $s2, $zero, 0xffff
.L80240114:
/* 92A3C4 80240114 8E020000 */  lw        $v0, ($s0)
/* 92A3C8 80240118 1052000B */  beq       $v0, $s2, .L80240148
/* 92A3CC 8024011C 2405FFFF */   addiu    $a1, $zero, -1
/* 92A3D0 80240120 96040002 */  lhu       $a0, 2($s0)
/* 92A3D4 80240124 0220302D */  daddu     $a2, $s1, $zero
/* 92A3D8 80240128 26100004 */  addiu     $s0, $s0, 4
/* 92A3DC 8024012C 0C046E54 */  jal       func_8011B950
/* 92A3E0 80240130 0000382D */   daddu    $a3, $zero, $zero
/* 92A3E4 80240134 08090045 */  j         .L80240114
/* 92A3E8 80240138 00000000 */   nop
.L8024013C:
/* 92A3EC 8024013C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 92A3F0 80240140 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 92A3F4 80240144 A0510000 */  sb        $s1, ($v0)
.L80240148:
/* 92A3F8 80240148 24020002 */  addiu     $v0, $zero, 2
.L8024014C:
/* 92A3FC 8024014C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 92A400 80240150 8FB20018 */  lw        $s2, 0x18($sp)
/* 92A404 80240154 8FB10014 */  lw        $s1, 0x14($sp)
/* 92A408 80240158 8FB00010 */  lw        $s0, 0x10($sp)
/* 92A40C 8024015C 03E00008 */  jr        $ra
/* 92A410 80240160 27BD0020 */   addiu    $sp, $sp, 0x20
