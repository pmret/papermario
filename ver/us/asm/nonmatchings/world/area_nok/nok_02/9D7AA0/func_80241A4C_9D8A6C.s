.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A4C_9D8A6C
/* 9D8A6C 80241A4C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9D8A70 80241A50 AFB10024 */  sw        $s1, 0x24($sp)
/* 9D8A74 80241A54 0080882D */  daddu     $s1, $a0, $zero
/* 9D8A78 80241A58 3C05F840 */  lui       $a1, 0xf840
/* 9D8A7C 80241A5C AFBF0044 */  sw        $ra, 0x44($sp)
/* 9D8A80 80241A60 AFBE0040 */  sw        $fp, 0x40($sp)
/* 9D8A84 80241A64 AFB7003C */  sw        $s7, 0x3c($sp)
/* 9D8A88 80241A68 AFB60038 */  sw        $s6, 0x38($sp)
/* 9D8A8C 80241A6C AFB50034 */  sw        $s5, 0x34($sp)
/* 9D8A90 80241A70 AFB40030 */  sw        $s4, 0x30($sp)
/* 9D8A94 80241A74 AFB3002C */  sw        $s3, 0x2c($sp)
/* 9D8A98 80241A78 AFB20028 */  sw        $s2, 0x28($sp)
/* 9D8A9C 80241A7C AFB00020 */  sw        $s0, 0x20($sp)
/* 9D8AA0 80241A80 8E3E0148 */  lw        $fp, 0x148($s1)
/* 9D8AA4 80241A84 0C0B1EAF */  jal       evt_get_variable
/* 9D8AA8 80241A88 34A56268 */   ori      $a1, $a1, 0x6268
/* 9D8AAC 80241A8C 0040802D */  daddu     $s0, $v0, $zero
/* 9D8AB0 80241A90 0220202D */  daddu     $a0, $s1, $zero
/* 9D8AB4 80241A94 3C05F840 */  lui       $a1, 0xf840
/* 9D8AB8 80241A98 0C0B1EAF */  jal       evt_get_variable
/* 9D8ABC 80241A9C 34A56269 */   ori      $a1, $a1, 0x6269
/* 9D8AC0 80241AA0 0040B82D */  daddu     $s7, $v0, $zero
/* 9D8AC4 80241AA4 0220202D */  daddu     $a0, $s1, $zero
/* 9D8AC8 80241AA8 3C05F5DE */  lui       $a1, 0xf5de
/* 9D8ACC 80241AAC 0C0B1EAF */  jal       evt_get_variable
/* 9D8AD0 80241AB0 34A502DE */   ori      $a1, $a1, 0x2de
/* 9D8AD4 80241AB4 0040B02D */  daddu     $s6, $v0, $zero
/* 9D8AD8 80241AB8 0220202D */  daddu     $a0, $s1, $zero
/* 9D8ADC 80241ABC 3C05F5DE */  lui       $a1, 0xf5de
/* 9D8AE0 80241AC0 0C0B1EAF */  jal       evt_get_variable
/* 9D8AE4 80241AC4 34A502DF */   ori      $a1, $a1, 0x2df
/* 9D8AE8 80241AC8 0040A82D */  daddu     $s5, $v0, $zero
/* 9D8AEC 80241ACC 93D3006D */  lbu       $s3, 0x6d($fp)
/* 9D8AF0 80241AD0 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 9D8AF4 80241AD4 A7B30010 */  sh        $s3, 0x10($sp)
/* 9D8AF8 80241AD8 93D2006E */  lbu       $s2, 0x6e($fp)
/* 9D8AFC 80241ADC 93C7006F */  lbu       $a3, 0x6f($fp)
/* 9D8B00 80241AE0 3274FFFF */  andi      $s4, $s3, 0xffff
/* 9D8B04 80241AE4 12820003 */  beq       $s4, $v0, .L80241AF4
/* 9D8B08 80241AE8 A7A7001E */   sh       $a3, 0x1e($sp)
/* 9D8B0C 80241AEC 0000B82D */  daddu     $s7, $zero, $zero
/* 9D8B10 80241AF0 02E0802D */  daddu     $s0, $s7, $zero
.L80241AF4:
/* 9D8B14 80241AF4 3202FFFF */  andi      $v0, $s0, 0xffff
/* 9D8B18 80241AF8 14400016 */  bnez      $v0, .L80241B54
/* 9D8B1C 80241AFC 0220202D */   daddu    $a0, $s1, $zero
/* 9D8B20 80241B00 0C00A67F */  jal       rand_int
/* 9D8B24 80241B04 24040064 */   addiu    $a0, $zero, 0x64
/* 9D8B28 80241B08 2842001E */  slti      $v0, $v0, 0x1e
/* 9D8B2C 80241B0C 10400011 */  beqz      $v0, .L80241B54
/* 9D8B30 80241B10 0220202D */   daddu    $a0, $s1, $zero
/* 9D8B34 80241B14 0C00A67F */  jal       rand_int
/* 9D8B38 80241B18 2644FFFF */   addiu    $a0, $s2, -1
/* 9D8B3C 80241B1C 0040A82D */  daddu     $s5, $v0, $zero
/* 9D8B40 80241B20 0260B02D */  daddu     $s6, $s3, $zero
/* 9D8B44 80241B24 0220202D */  daddu     $a0, $s1, $zero
/* 9D8B48 80241B28 3C05F5DE */  lui       $a1, 0xf5de
/* 9D8B4C 80241B2C 34A502DE */  ori       $a1, $a1, 0x2de
/* 9D8B50 80241B30 0C0B2026 */  jal       evt_set_variable
/* 9D8B54 80241B34 0280302D */   daddu    $a2, $s4, $zero
/* 9D8B58 80241B38 0220202D */  daddu     $a0, $s1, $zero
/* 9D8B5C 80241B3C 3C05F5DE */  lui       $a1, 0xf5de
/* 9D8B60 80241B40 34A502DF */  ori       $a1, $a1, 0x2df
/* 9D8B64 80241B44 0C0B2026 */  jal       evt_set_variable
/* 9D8B68 80241B48 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 9D8B6C 80241B4C 24100001 */  addiu     $s0, $zero, 1
/* 9D8B70 80241B50 0220202D */  daddu     $a0, $s1, $zero
.L80241B54:
/* 9D8B74 80241B54 3C05F840 */  lui       $a1, 0xf840
/* 9D8B78 80241B58 34A56268 */  ori       $a1, $a1, 0x6268
/* 9D8B7C 80241B5C 0C0B2026 */  jal       evt_set_variable
/* 9D8B80 80241B60 3206FFFF */   andi     $a2, $s0, 0xffff
/* 9D8B84 80241B64 0220202D */  daddu     $a0, $s1, $zero
/* 9D8B88 80241B68 3C05F840 */  lui       $a1, 0xf840
/* 9D8B8C 80241B6C 34A56269 */  ori       $a1, $a1, 0x6269
/* 9D8B90 80241B70 0C0B2026 */  jal       evt_set_variable
/* 9D8B94 80241B74 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 9D8B98 80241B78 0000202D */  daddu     $a0, $zero, $zero
/* 9D8B9C 80241B7C 3C05F5DE */  lui       $a1, 0xf5de
/* 9D8BA0 80241B80 0C0B1EAF */  jal       evt_get_variable
/* 9D8BA4 80241B84 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 9D8BA8 80241B88 0000202D */  daddu     $a0, $zero, $zero
/* 9D8BAC 80241B8C 3C05F5DE */  lui       $a1, 0xf5de
/* 9D8BB0 80241B90 34A50180 */  ori       $a1, $a1, 0x180
/* 9D8BB4 80241B94 0C0B1EAF */  jal       evt_get_variable
/* 9D8BB8 80241B98 0040802D */   daddu    $s0, $v0, $zero
/* 9D8BBC 80241B9C 0040282D */  daddu     $a1, $v0, $zero
/* 9D8BC0 80241BA0 0000182D */  daddu     $v1, $zero, $zero
/* 9D8BC4 80241BA4 3C068024 */  lui       $a2, %hi(D_8024716C_9DE18C)
/* 9D8BC8 80241BA8 24C6716C */  addiu     $a2, $a2, %lo(D_8024716C_9DE18C)
/* 9D8BCC 80241BAC 00C0202D */  daddu     $a0, $a2, $zero
.L80241BB0:
/* 9D8BD0 80241BB0 8C820000 */  lw        $v0, ($a0)
/* 9D8BD4 80241BB4 00A2102A */  slt       $v0, $a1, $v0
/* 9D8BD8 80241BB8 14400006 */  bnez      $v0, .L80241BD4
/* 9D8BDC 80241BBC 000310C0 */   sll      $v0, $v1, 3
/* 9D8BE0 80241BC0 24630001 */  addiu     $v1, $v1, 1
/* 9D8BE4 80241BC4 28620008 */  slti      $v0, $v1, 8
/* 9D8BE8 80241BC8 1440FFF9 */  bnez      $v0, .L80241BB0
/* 9D8BEC 80241BCC 24840008 */   addiu    $a0, $a0, 8
/* 9D8BF0 80241BD0 000310C0 */  sll       $v0, $v1, 3
.L80241BD4:
/* 9D8BF4 80241BD4 00461021 */  addu      $v0, $v0, $a2
/* 9D8BF8 80241BD8 8C420004 */  lw        $v0, 4($v0)
/* 9D8BFC 80241BDC 97A30010 */  lhu       $v1, 0x10($sp)
/* 9D8C00 80241BE0 0202202A */  slt       $a0, $s0, $v0
/* 9D8C04 80241BE4 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 9D8C08 80241BE8 14620008 */  bne       $v1, $v0, .L80241C0C
/* 9D8C0C 80241BEC 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 9D8C10 80241BF0 97A7001E */  lhu       $a3, 0x1e($sp)
/* 9D8C14 80241BF4 14E20005 */  bne       $a3, $v0, .L80241C0C
/* 9D8C18 80241BF8 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 9D8C1C 80241BFC 14400003 */  bnez      $v0, .L80241C0C
/* 9D8C20 80241C00 00000000 */   nop
/* 9D8C24 80241C04 14800008 */  bnez      $a0, .L80241C28
/* 9D8C28 80241C08 24020001 */   addiu    $v0, $zero, 1
.L80241C0C:
/* 9D8C2C 80241C0C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9D8C30 80241C10 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9D8C34 80241C14 80420075 */  lb        $v0, 0x75($v0)
/* 9D8C38 80241C18 10400005 */  beqz      $v0, .L80241C30
/* 9D8C3C 80241C1C 00000000 */   nop
/* 9D8C40 80241C20 10800003 */  beqz      $a0, .L80241C30
/* 9D8C44 80241C24 24020001 */   addiu    $v0, $zero, 1
.L80241C28:
/* 9D8C48 80241C28 0809070F */  j         .L80241C3C
/* 9D8C4C 80241C2C AE220084 */   sw       $v0, 0x84($s1)
.L80241C30:
/* 9D8C50 80241C30 0C00F9EB */  jal       kill_enemy
/* 9D8C54 80241C34 03C0202D */   daddu    $a0, $fp, $zero
/* 9D8C58 80241C38 AE200084 */  sw        $zero, 0x84($s1)
.L80241C3C:
/* 9D8C5C 80241C3C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9D8C60 80241C40 8FBE0040 */  lw        $fp, 0x40($sp)
/* 9D8C64 80241C44 8FB7003C */  lw        $s7, 0x3c($sp)
/* 9D8C68 80241C48 8FB60038 */  lw        $s6, 0x38($sp)
/* 9D8C6C 80241C4C 8FB50034 */  lw        $s5, 0x34($sp)
/* 9D8C70 80241C50 8FB40030 */  lw        $s4, 0x30($sp)
/* 9D8C74 80241C54 8FB3002C */  lw        $s3, 0x2c($sp)
/* 9D8C78 80241C58 8FB20028 */  lw        $s2, 0x28($sp)
/* 9D8C7C 80241C5C 8FB10024 */  lw        $s1, 0x24($sp)
/* 9D8C80 80241C60 8FB00020 */  lw        $s0, 0x20($sp)
/* 9D8C84 80241C64 24020002 */  addiu     $v0, $zero, 2
/* 9D8C88 80241C68 03E00008 */  jr        $ra
/* 9D8C8C 80241C6C 27BD0048 */   addiu    $sp, $sp, 0x48
