.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EA28
/* 19E28 8003EA28 3C03800B */  lui       $v1, %hi(D_800B0EF0)
/* 19E2C 8003EA2C 24630EF0 */  addiu     $v1, $v1, %lo(D_800B0EF0)
/* 19E30 8003EA30 8062001C */  lb        $v0, 0x1c($v1)
/* 19E34 8003EA34 1840001A */  blez      $v0, .L8003EAA0
/* 19E38 8003EA38 0000382D */   daddu    $a3, $zero, $zero
/* 19E3C 8003EA3C 0040502D */  daddu     $t2, $v0, $zero
/* 19E40 8003EA40 0060482D */  daddu     $t1, $v1, $zero
.L8003EA44:
/* 19E44 8003EA44 8D220028 */  lw        $v0, 0x28($t1)
/* 19E48 8003EA48 50400012 */  beql      $v0, $zero, .L8003EA94
/* 19E4C 8003EA4C 24E70001 */   addiu    $a3, $a3, 1
/* 19E50 8003EA50 8C430000 */  lw        $v1, ($v0)
/* 19E54 8003EA54 1860000E */  blez      $v1, .L8003EA90
/* 19E58 8003EA58 0000302D */   daddu    $a2, $zero, $zero
/* 19E5C 8003EA5C 0060402D */  daddu     $t0, $v1, $zero
/* 19E60 8003EA60 0040282D */  daddu     $a1, $v0, $zero
.L8003EA64:
/* 19E64 8003EA64 8CA30004 */  lw        $v1, 4($a1)
/* 19E68 8003EA68 10600006 */  beqz      $v1, .L8003EA84
/* 19E6C 8003EA6C 24C60001 */   addiu    $a2, $a2, 1
/* 19E70 8003EA70 84620008 */  lh        $v0, 8($v1)
/* 19E74 8003EA74 14440004 */  bne       $v0, $a0, .L8003EA88
/* 19E78 8003EA78 00C8102A */   slt      $v0, $a2, $t0
/* 19E7C 8003EA7C 03E00008 */  jr        $ra
/* 19E80 8003EA80 0060102D */   daddu    $v0, $v1, $zero
.L8003EA84:
/* 19E84 8003EA84 00C8102A */  slt       $v0, $a2, $t0
.L8003EA88:
/* 19E88 8003EA88 1440FFF6 */  bnez      $v0, .L8003EA64
/* 19E8C 8003EA8C 24A50004 */   addiu    $a1, $a1, 4
.L8003EA90:
/* 19E90 8003EA90 24E70001 */  addiu     $a3, $a3, 1
.L8003EA94:
/* 19E94 8003EA94 00EA102A */  slt       $v0, $a3, $t2
/* 19E98 8003EA98 1440FFEA */  bnez      $v0, .L8003EA44
/* 19E9C 8003EA9C 25290004 */   addiu    $t1, $t1, 4
.L8003EAA0:
/* 19EA0 8003EAA0 03E00008 */  jr        $ra
/* 19EA4 8003EAA4 0000102D */   daddu    $v0, $zero, $zero
/* 19EA8 8003EAA8 00000000 */  nop
/* 19EAC 8003EAAC 00000000 */  nop
