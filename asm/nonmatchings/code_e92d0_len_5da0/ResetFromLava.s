.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ResetFromLava
/* 0EE888 802C9ED8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EE88C 802C9EDC AFBF0020 */  sw    $ra, 0x20($sp)
/* 0EE890 802C9EE0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EE894 802C9EE4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EE898 802C9EE8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EE89C 802C9EEC AFB00010 */  sw    $s0, 0x10($sp)
/* 0EE8A0 802C9EF0 10A0001D */  beqz  $a1, .L802C9F68
/* 0EE8A4 802C9EF4 8C82000C */   lw    $v0, 0xc($a0)
/* 0EE8A8 802C9EF8 8C450000 */  lw    $a1, ($v0)
/* 0EE8AC 802C9EFC 3C12800B */  lui   $s2, 0x800b
/* 0EE8B0 802C9F00 265242E0 */  addiu $s2, $s2, 0x42e0
/* 0EE8B4 802C9F04 0C0B1EAF */  jal   get_variable
/* 0EE8B8 802C9F08 2413FFFF */   addiu $s3, $zero, -1
/* 0EE8BC 802C9F0C 0040882D */  daddu $s1, $v0, $zero
/* 0EE8C0 802C9F10 3C01802E */  lui   $at, 0x802e
/* 0EE8C4 802C9F14 AC31ADA0 */  sw    $s1, -0x5260($at)
.L802C9F18:
/* 0EE8C8 802C9F18 8E230000 */  lw    $v1, ($s1)
/* 0EE8CC 802C9F1C 1073000F */  beq   $v1, $s3, .L802C9F5C
/* 0EE8D0 802C9F20 000310C0 */   sll   $v0, $v1, 3
/* 0EE8D4 802C9F24 00431023 */  subu  $v0, $v0, $v1
/* 0EE8D8 802C9F28 8E430004 */  lw    $v1, 4($s2)
/* 0EE8DC 802C9F2C 00021080 */  sll   $v0, $v0, 2
/* 0EE8E0 802C9F30 00628021 */  addu  $s0, $v1, $v0
/* 0EE8E4 802C9F34 86040006 */  lh    $a0, 6($s0)
/* 0EE8E8 802C9F38 04800003 */  bltz  $a0, .L802C9F48
/* 0EE8EC 802C9F3C 24050100 */   addiu $a1, $zero, 0x100
/* 0EE8F0 802C9F40 0C0B273A */  jal   modify_collider_family_flags
/* 0EE8F4 802C9F44 0000302D */   daddu $a2, $zero, $zero
.L802C9F48:
/* 0EE8F8 802C9F48 8E020000 */  lw    $v0, ($s0)
/* 0EE8FC 802C9F4C 26310010 */  addiu $s1, $s1, 0x10
/* 0EE900 802C9F50 34420100 */  ori   $v0, $v0, 0x100
/* 0EE904 802C9F54 080B27C6 */  j     .L802C9F18
/* 0EE908 802C9F58 AE020000 */   sw    $v0, ($s0)

.L802C9F5C:
/* 0EE90C 802C9F5C 2402FFFF */  addiu $v0, $zero, -1
/* 0EE910 802C9F60 3C01802E */  lui   $at, 0x802e
/* 0EE914 802C9F64 AC22ADA4 */  sw    $v0, -0x525c($at)
.L802C9F68:
/* 0EE918 802C9F68 3C028016 */  lui   $v0, 0x8016
/* 0EE91C 802C9F6C 2442A550 */  addiu $v0, $v0, -0x5ab0
/* 0EE920 802C9F70 94430002 */  lhu   $v1, 2($v0)
/* 0EE924 802C9F74 30624000 */  andi  $v0, $v1, 0x4000
/* 0EE928 802C9F78 1440000F */  bnez  $v0, .L802C9FB8
/* 0EE92C 802C9F7C 0000102D */   daddu $v0, $zero, $zero
/* 0EE930 802C9F80 00031400 */  sll   $v0, $v1, 0x10
/* 0EE934 802C9F84 00022403 */  sra   $a0, $v0, 0x10
/* 0EE938 802C9F88 000410C0 */  sll   $v0, $a0, 3
/* 0EE93C 802C9F8C 00441023 */  subu  $v0, $v0, $a0
/* 0EE940 802C9F90 3C03800B */  lui   $v1, 0x800b
/* 0EE944 802C9F94 8C6342E4 */  lw    $v1, 0x42e4($v1)
/* 0EE948 802C9F98 00021080 */  sll   $v0, $v0, 2
/* 0EE94C 802C9F9C 00628021 */  addu  $s0, $v1, $v0
/* 0EE950 802C9FA0 8E020000 */  lw    $v0, ($s0)
/* 0EE954 802C9FA4 30420100 */  andi  $v0, $v0, 0x100
/* 0EE958 802C9FA8 10400003 */  beqz  $v0, .L802C9FB8
/* 0EE95C 802C9FAC 0000102D */   daddu $v0, $zero, $zero
/* 0EE960 802C9FB0 3C01802E */  lui   $at, 0x802e
/* 0EE964 802C9FB4 AC24ADA4 */  sw    $a0, -0x525c($at)
.L802C9FB8:
/* 0EE968 802C9FB8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0EE96C 802C9FBC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EE970 802C9FC0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EE974 802C9FC4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EE978 802C9FC8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EE97C 802C9FCC 03E00008 */  jr    $ra
/* 0EE980 802C9FD0 27BD0028 */   addiu $sp, $sp, 0x28

/* 0EE984 802C9FD4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EE988 802C9FD8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EE98C 802C9FDC 0080802D */  daddu $s0, $a0, $zero
/* 0EE990 802C9FE0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EE994 802C9FE4 00A0882D */  daddu $s1, $a1, $zero
/* 0EE998 802C9FE8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EE99C 802C9FEC 3C04802E */  lui   $a0, 0x802e
/* 0EE9A0 802C9FF0 2484ADA4 */  addiu $a0, $a0, -0x525c
/* 0EE9A4 802C9FF4 2402FFFF */  addiu $v0, $zero, -1
/* 0EE9A8 802C9FF8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EE9AC 802C9FFC 8C830000 */  lw    $v1, ($a0)
/* 0EE9B0 802CA000 3C05802E */  lui   $a1, 0x802e
/* 0EE9B4 802CA004 8CA5ADA0 */  lw    $a1, -0x5260($a1)
/* 0EE9B8 802CA008 14620018 */  bne   $v1, $v0, .L802CA06C
/* 0EE9BC 802CA00C 00C0902D */   daddu $s2, $a2, $zero
/* 0EE9C0 802CA010 0C016AFA */  jal   get_current_map_header
/* 0EE9C4 802CA014 00000000 */   nop   
/* 0EE9C8 802CA018 3C038007 */  lui   $v1, 0x8007
/* 0EE9CC 802CA01C 8C63419C */  lw    $v1, 0x419c($v1)
/* 0EE9D0 802CA020 8463008E */  lh    $v1, 0x8e($v1)
/* 0EE9D4 802CA024 8C420014 */  lw    $v0, 0x14($v0)
/* 0EE9D8 802CA028 00031900 */  sll   $v1, $v1, 4
/* 0EE9DC 802CA02C 00431021 */  addu  $v0, $v0, $v1
/* 0EE9E0 802CA030 C4400000 */  lwc1  $f0, ($v0)
/* 0EE9E4 802CA034 E6000000 */  swc1  $f0, ($s0)
/* 0EE9E8 802CA038 C4400004 */  lwc1  $f0, 4($v0)
/* 0EE9EC 802CA03C E6200000 */  swc1  $f0, ($s1)
/* 0EE9F0 802CA040 C4400008 */  lwc1  $f0, 8($v0)
/* 0EE9F4 802CA044 2402FFFF */  addiu $v0, $zero, -1
/* 0EE9F8 802CA048 080B2825 */  j     .L802CA094
/* 0EE9FC 802CA04C E6400000 */   swc1  $f0, ($s2)

.L802CA050:
/* 0EEA00 802CA050 C4A00004 */  lwc1  $f0, 4($a1)
/* 0EEA04 802CA054 E6000000 */  swc1  $f0, ($s0)
/* 0EEA08 802CA058 C4A00008 */  lwc1  $f0, 8($a1)
/* 0EEA0C 802CA05C E6200000 */  swc1  $f0, ($s1)
/* 0EEA10 802CA060 C4A0000C */  lwc1  $f0, 0xc($a1)
/* 0EEA14 802CA064 080B2825 */  j     .L802CA094
/* 0EEA18 802CA068 E6400000 */   swc1  $f0, ($s2)

.L802CA06C:
/* 0EEA1C 802CA06C 2406FFFF */  addiu $a2, $zero, -1
/* 0EEA20 802CA070 0080182D */  daddu $v1, $a0, $zero
.L802CA074:
/* 0EEA24 802CA074 8CA40000 */  lw    $a0, ($a1)
/* 0EEA28 802CA078 10860006 */  beq   $a0, $a2, .L802CA094
/* 0EEA2C 802CA07C 0000102D */   daddu $v0, $zero, $zero
/* 0EEA30 802CA080 8C620000 */  lw    $v0, ($v1)
/* 0EEA34 802CA084 1082FFF2 */  beq   $a0, $v0, .L802CA050
/* 0EEA38 802CA088 24020001 */   addiu $v0, $zero, 1
/* 0EEA3C 802CA08C 080B281D */  j     .L802CA074
/* 0EEA40 802CA090 24A50010 */   addiu $a1, $a1, 0x10

.L802CA094:
/* 0EEA44 802CA094 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EEA48 802CA098 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EEA4C 802CA09C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EEA50 802CA0A0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EEA54 802CA0A4 03E00008 */  jr    $ra
/* 0EEA58 802CA0A8 27BD0020 */   addiu $sp, $sp, 0x20

