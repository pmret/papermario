.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B04_8EE924
/* 8EE924 80242B04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8EE928 80242B08 AFB10014 */  sw        $s1, 0x14($sp)
/* 8EE92C 80242B0C 0080882D */  daddu     $s1, $a0, $zero
/* 8EE930 80242B10 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8EE934 80242B14 10A00014 */  beqz      $a1, .L80242B68
/* 8EE938 80242B18 AFB00010 */   sw       $s0, 0x10($sp)
/* 8EE93C 80242B1C 0C00AB39 */  jal       heap_malloc
/* 8EE940 80242B20 2404002C */   addiu    $a0, $zero, 0x2c
/* 8EE944 80242B24 0040802D */  daddu     $s0, $v0, $zero
/* 8EE948 80242B28 0000202D */  daddu     $a0, $zero, $zero
/* 8EE94C 80242B2C 3C058024 */  lui       $a1, %hi(func_80242A04_8EE824)
/* 8EE950 80242B30 24A52A04 */  addiu     $a1, $a1, %lo(func_80242A04_8EE824)
/* 8EE954 80242B34 240200FF */  addiu     $v0, $zero, 0xff
/* 8EE958 80242B38 AE300070 */  sw        $s0, 0x70($s1)
/* 8EE95C 80242B3C A6000000 */  sh        $zero, ($s0)
/* 8EE960 80242B40 0C048C56 */  jal       bind_dynamic_entity_3
/* 8EE964 80242B44 A602001A */   sh       $v0, 0x1a($s0)
/* 8EE968 80242B48 0220202D */  daddu     $a0, $s1, $zero
/* 8EE96C 80242B4C 3C05FD05 */  lui       $a1, 0xfd05
/* 8EE970 80242B50 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 8EE974 80242B54 0200302D */  daddu     $a2, $s0, $zero
/* 8EE978 80242B58 0C0B2026 */  jal       set_variable
/* 8EE97C 80242B5C AE020020 */   sw       $v0, 0x20($s0)
/* 8EE980 80242B60 0C090A8F */  jal       func_80242A3C_8EE85C
/* 8EE984 80242B64 0200202D */   daddu    $a0, $s0, $zero
.L80242B68:
/* 8EE988 80242B68 8E300070 */  lw        $s0, 0x70($s1)
/* 8EE98C 80242B6C 96030000 */  lhu       $v1, ($s0)
/* 8EE990 80242B70 24020005 */  addiu     $v0, $zero, 5
/* 8EE994 80242B74 14620007 */  bne       $v1, $v0, .L80242B94
/* 8EE998 80242B78 0000102D */   daddu    $v0, $zero, $zero
/* 8EE99C 80242B7C 8E040020 */  lw        $a0, 0x20($s0)
/* 8EE9A0 80242B80 0C048D70 */  jal       func_801235C0
/* 8EE9A4 80242B84 00000000 */   nop
/* 8EE9A8 80242B88 0C00AB4B */  jal       heap_free
/* 8EE9AC 80242B8C 0200202D */   daddu    $a0, $s0, $zero
/* 8EE9B0 80242B90 24020001 */  addiu     $v0, $zero, 1
.L80242B94:
/* 8EE9B4 80242B94 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8EE9B8 80242B98 8FB10014 */  lw        $s1, 0x14($sp)
/* 8EE9BC 80242B9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EE9C0 80242BA0 03E00008 */  jr        $ra
/* 8EE9C4 80242BA4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 8EE9C8 80242BA8 00000000 */  nop
/* 8EE9CC 80242BAC 00000000 */  nop
