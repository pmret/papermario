.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240960_86F460
/* 86F460 80240960 3C088011 */  lui       $t0, %hi(gPlayerStatus)
/* 86F464 80240964 2508EFC8 */  addiu     $t0, $t0, %lo(gPlayerStatus)
/* 86F468 80240968 0000202D */  daddu     $a0, $zero, $zero
/* 86F46C 8024096C 3C058016 */  lui       $a1, 0x8016
/* 86F470 80240970 84A5A552 */  lh        $a1, -0x5aae($a1)
/* 86F474 80240974 2407000E */  addiu     $a3, $zero, 0xe
/* 86F478 80240978 24060010 */  addiu     $a2, $zero, 0x10
/* 86F47C 8024097C 3C038024 */  lui       $v1, 0x8024
/* 86F480 80240980 24632930 */  addiu     $v1, $v1, 0x2930
.L80240984:
/* 86F484 80240984 8C620000 */  lw        $v0, ($v1)
/* 86F488 80240988 54A20008 */  bnel      $a1, $v0, .L802409AC
/* 86F48C 8024098C 24840001 */   addiu    $a0, $a0, 1
/* 86F490 80240990 810200B4 */  lb        $v0, 0xb4($t0)
/* 86F494 80240994 10470003 */  beq       $v0, $a3, .L802409A4
/* 86F498 80240998 00000000 */   nop      
/* 86F49C 8024099C 14460003 */  bne       $v0, $a2, .L802409AC
/* 86F4A0 802409A0 24840001 */   addiu    $a0, $a0, 1
.L802409A4:
/* 86F4A4 802409A4 03E00008 */  jr        $ra
/* 86F4A8 802409A8 0000102D */   daddu    $v0, $zero, $zero
.L802409AC:
/* 86F4AC 802409AC 2C820004 */  sltiu     $v0, $a0, 4
/* 86F4B0 802409B0 1440FFF4 */  bnez      $v0, .L80240984
/* 86F4B4 802409B4 24630004 */   addiu    $v1, $v1, 4
/* 86F4B8 802409B8 03E00008 */  jr        $ra
/* 86F4BC 802409BC 24020002 */   addiu    $v0, $zero, 2
