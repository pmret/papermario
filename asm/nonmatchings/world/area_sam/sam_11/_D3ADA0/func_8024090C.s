.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024090C
/* D3AEDC 8024090C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D3AEE0 80240910 AFB10024 */  sw        $s1, 0x24($sp)
/* D3AEE4 80240914 0080882D */  daddu     $s1, $a0, $zero
/* D3AEE8 80240918 3C05F840 */  lui       $a1, 0xf840
/* D3AEEC 8024091C AFBF0044 */  sw        $ra, 0x44($sp)
/* D3AEF0 80240920 AFBE0040 */  sw        $fp, 0x40($sp)
/* D3AEF4 80240924 AFB7003C */  sw        $s7, 0x3c($sp)
/* D3AEF8 80240928 AFB60038 */  sw        $s6, 0x38($sp)
/* D3AEFC 8024092C AFB50034 */  sw        $s5, 0x34($sp)
/* D3AF00 80240930 AFB40030 */  sw        $s4, 0x30($sp)
/* D3AF04 80240934 AFB3002C */  sw        $s3, 0x2c($sp)
/* D3AF08 80240938 AFB20028 */  sw        $s2, 0x28($sp)
/* D3AF0C 8024093C AFB00020 */  sw        $s0, 0x20($sp)
/* D3AF10 80240940 8E3E0148 */  lw        $fp, 0x148($s1)
/* D3AF14 80240944 0C0B1EAF */  jal       get_variable
/* D3AF18 80240948 34A56268 */   ori      $a1, $a1, 0x6268
/* D3AF1C 8024094C 0040802D */  daddu     $s0, $v0, $zero
/* D3AF20 80240950 0220202D */  daddu     $a0, $s1, $zero
/* D3AF24 80240954 3C05F840 */  lui       $a1, 0xf840
/* D3AF28 80240958 0C0B1EAF */  jal       get_variable
/* D3AF2C 8024095C 34A56269 */   ori      $a1, $a1, 0x6269
/* D3AF30 80240960 0040B82D */  daddu     $s7, $v0, $zero
/* D3AF34 80240964 0220202D */  daddu     $a0, $s1, $zero
/* D3AF38 80240968 3C05F5DE */  lui       $a1, 0xf5de
/* D3AF3C 8024096C 0C0B1EAF */  jal       get_variable
/* D3AF40 80240970 34A502DE */   ori      $a1, $a1, 0x2de
/* D3AF44 80240974 0040B02D */  daddu     $s6, $v0, $zero
/* D3AF48 80240978 0220202D */  daddu     $a0, $s1, $zero
/* D3AF4C 8024097C 3C05F5DE */  lui       $a1, 0xf5de
/* D3AF50 80240980 0C0B1EAF */  jal       get_variable
/* D3AF54 80240984 34A502DF */   ori      $a1, $a1, 0x2df
/* D3AF58 80240988 0040A82D */  daddu     $s5, $v0, $zero
/* D3AF5C 8024098C 93D3006D */  lbu       $s3, 0x6d($fp)
/* D3AF60 80240990 32C2FFFF */  andi      $v0, $s6, 0xffff
/* D3AF64 80240994 A7B30010 */  sh        $s3, 0x10($sp)
/* D3AF68 80240998 93D2006E */  lbu       $s2, 0x6e($fp)
/* D3AF6C 8024099C 93C7006F */  lbu       $a3, 0x6f($fp)
/* D3AF70 802409A0 3274FFFF */  andi      $s4, $s3, 0xffff
/* D3AF74 802409A4 12820003 */  beq       $s4, $v0, .L802409B4
/* D3AF78 802409A8 A7A7001E */   sh       $a3, 0x1e($sp)
/* D3AF7C 802409AC 0000B82D */  daddu     $s7, $zero, $zero
/* D3AF80 802409B0 02E0802D */  daddu     $s0, $s7, $zero
.L802409B4:
/* D3AF84 802409B4 3202FFFF */  andi      $v0, $s0, 0xffff
/* D3AF88 802409B8 14400016 */  bnez      $v0, .L80240A14
/* D3AF8C 802409BC 0220202D */   daddu    $a0, $s1, $zero
/* D3AF90 802409C0 0C00A67F */  jal       rand_int
/* D3AF94 802409C4 24040064 */   addiu    $a0, $zero, 0x64
/* D3AF98 802409C8 2842001E */  slti      $v0, $v0, 0x1e
/* D3AF9C 802409CC 10400011 */  beqz      $v0, .L80240A14
/* D3AFA0 802409D0 0220202D */   daddu    $a0, $s1, $zero
/* D3AFA4 802409D4 0C00A67F */  jal       rand_int
/* D3AFA8 802409D8 2644FFFF */   addiu    $a0, $s2, -1
/* D3AFAC 802409DC 0040A82D */  daddu     $s5, $v0, $zero
/* D3AFB0 802409E0 0260B02D */  daddu     $s6, $s3, $zero
/* D3AFB4 802409E4 0220202D */  daddu     $a0, $s1, $zero
/* D3AFB8 802409E8 3C05F5DE */  lui       $a1, 0xf5de
/* D3AFBC 802409EC 34A502DE */  ori       $a1, $a1, 0x2de
/* D3AFC0 802409F0 0C0B2026 */  jal       set_variable
/* D3AFC4 802409F4 0280302D */   daddu    $a2, $s4, $zero
/* D3AFC8 802409F8 0220202D */  daddu     $a0, $s1, $zero
/* D3AFCC 802409FC 3C05F5DE */  lui       $a1, 0xf5de
/* D3AFD0 80240A00 34A502DF */  ori       $a1, $a1, 0x2df
/* D3AFD4 80240A04 0C0B2026 */  jal       set_variable
/* D3AFD8 80240A08 32A6FFFF */   andi     $a2, $s5, 0xffff
/* D3AFDC 80240A0C 24100001 */  addiu     $s0, $zero, 1
/* D3AFE0 80240A10 0220202D */  daddu     $a0, $s1, $zero
.L80240A14:
/* D3AFE4 80240A14 3C05F840 */  lui       $a1, 0xf840
/* D3AFE8 80240A18 34A56268 */  ori       $a1, $a1, 0x6268
/* D3AFEC 80240A1C 0C0B2026 */  jal       set_variable
/* D3AFF0 80240A20 3206FFFF */   andi     $a2, $s0, 0xffff
/* D3AFF4 80240A24 0220202D */  daddu     $a0, $s1, $zero
/* D3AFF8 80240A28 3C05F840 */  lui       $a1, 0xf840
/* D3AFFC 80240A2C 34A56269 */  ori       $a1, $a1, 0x6269
/* D3B000 80240A30 0C0B2026 */  jal       set_variable
/* D3B004 80240A34 32E6FFFF */   andi     $a2, $s7, 0xffff
/* D3B008 80240A38 0000202D */  daddu     $a0, $zero, $zero
/* D3B00C 80240A3C 3C05F5DE */  lui       $a1, 0xf5de
/* D3B010 80240A40 0C0B1EAF */  jal       get_variable
/* D3B014 80240A44 34A502E0 */   ori      $a1, $a1, 0x2e0
/* D3B018 80240A48 0000202D */  daddu     $a0, $zero, $zero
/* D3B01C 80240A4C 3C05F5DE */  lui       $a1, 0xf5de
/* D3B020 80240A50 34A50180 */  ori       $a1, $a1, 0x180
/* D3B024 80240A54 0C0B1EAF */  jal       get_variable
/* D3B028 80240A58 0040802D */   daddu    $s0, $v0, $zero
/* D3B02C 80240A5C 0040282D */  daddu     $a1, $v0, $zero
/* D3B030 80240A60 0000182D */  daddu     $v1, $zero, $zero
/* D3B034 80240A64 3C068024 */  lui       $a2, 0x8024
/* D3B038 80240A68 24C6501C */  addiu     $a2, $a2, 0x501c
/* D3B03C 80240A6C 00C0202D */  daddu     $a0, $a2, $zero
.L80240A70:
/* D3B040 80240A70 8C820000 */  lw        $v0, ($a0)
/* D3B044 80240A74 00A2102A */  slt       $v0, $a1, $v0
/* D3B048 80240A78 14400006 */  bnez      $v0, .L80240A94
/* D3B04C 80240A7C 000310C0 */   sll      $v0, $v1, 3
/* D3B050 80240A80 24630001 */  addiu     $v1, $v1, 1
/* D3B054 80240A84 28620008 */  slti      $v0, $v1, 8
/* D3B058 80240A88 1440FFF9 */  bnez      $v0, .L80240A70
/* D3B05C 80240A8C 24840008 */   addiu    $a0, $a0, 8
/* D3B060 80240A90 000310C0 */  sll       $v0, $v1, 3
.L80240A94:
/* D3B064 80240A94 00461021 */  addu      $v0, $v0, $a2
/* D3B068 80240A98 8C420004 */  lw        $v0, 4($v0)
/* D3B06C 80240A9C 97A30010 */  lhu       $v1, 0x10($sp)
/* D3B070 80240AA0 0202202A */  slt       $a0, $s0, $v0
/* D3B074 80240AA4 32C2FFFF */  andi      $v0, $s6, 0xffff
/* D3B078 80240AA8 14620008 */  bne       $v1, $v0, .L80240ACC
/* D3B07C 80240AAC 32A2FFFF */   andi     $v0, $s5, 0xffff
/* D3B080 80240AB0 97A7001E */  lhu       $a3, 0x1e($sp)
/* D3B084 80240AB4 14E20005 */  bne       $a3, $v0, .L80240ACC
/* D3B088 80240AB8 32E2FFFF */   andi     $v0, $s7, 0xffff
/* D3B08C 80240ABC 14400003 */  bnez      $v0, .L80240ACC
/* D3B090 80240AC0 00000000 */   nop      
/* D3B094 80240AC4 14800008 */  bnez      $a0, .L80240AE8
/* D3B098 80240AC8 24020001 */   addiu    $v0, $zero, 1
.L80240ACC:
/* D3B09C 80240ACC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D3B0A0 80240AD0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D3B0A4 80240AD4 80420075 */  lb        $v0, 0x75($v0)
/* D3B0A8 80240AD8 10400005 */  beqz      $v0, .L80240AF0
/* D3B0AC 80240ADC 00000000 */   nop      
/* D3B0B0 80240AE0 10800003 */  beqz      $a0, .L80240AF0
/* D3B0B4 80240AE4 24020001 */   addiu    $v0, $zero, 1
.L80240AE8:
/* D3B0B8 80240AE8 080902BF */  j         .L80240AFC
/* D3B0BC 80240AEC AE220084 */   sw       $v0, 0x84($s1)
.L80240AF0:
/* D3B0C0 80240AF0 0C00F9EB */  jal       kill_enemy
/* D3B0C4 80240AF4 03C0202D */   daddu    $a0, $fp, $zero
/* D3B0C8 80240AF8 AE200084 */  sw        $zero, 0x84($s1)
.L80240AFC:
/* D3B0CC 80240AFC 8FBF0044 */  lw        $ra, 0x44($sp)
/* D3B0D0 80240B00 8FBE0040 */  lw        $fp, 0x40($sp)
/* D3B0D4 80240B04 8FB7003C */  lw        $s7, 0x3c($sp)
/* D3B0D8 80240B08 8FB60038 */  lw        $s6, 0x38($sp)
/* D3B0DC 80240B0C 8FB50034 */  lw        $s5, 0x34($sp)
/* D3B0E0 80240B10 8FB40030 */  lw        $s4, 0x30($sp)
/* D3B0E4 80240B14 8FB3002C */  lw        $s3, 0x2c($sp)
/* D3B0E8 80240B18 8FB20028 */  lw        $s2, 0x28($sp)
/* D3B0EC 80240B1C 8FB10024 */  lw        $s1, 0x24($sp)
/* D3B0F0 80240B20 8FB00020 */  lw        $s0, 0x20($sp)
/* D3B0F4 80240B24 24020002 */  addiu     $v0, $zero, 2
/* D3B0F8 80240B28 03E00008 */  jr        $ra
/* D3B0FC 80240B2C 27BD0048 */   addiu    $sp, $sp, 0x48
