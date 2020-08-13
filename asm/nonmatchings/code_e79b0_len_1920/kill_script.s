.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel kill_script
/* 0E88EC 802C3F3C 3C03802E */  lui   $v1, 0x802e
/* 0E88F0 802C3F40 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E88F4 802C3F44 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E88F8 802C3F48 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E88FC 802C3F4C 0080902D */  daddu $s2, $a0, $zero
/* 0E8900 802C3F50 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8904 802C3F54 0000802D */  daddu $s0, $zero, $zero
/* 0E8908 802C3F58 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E890C 802C3F5C AFB10014 */  sw    $s1, 0x14($sp)
.L802C3F60:
/* 0E8910 802C3F60 8C620000 */  lw    $v0, ($v1)
/* 0E8914 802C3F64 10520006 */  beq   $v0, $s2, .L802C3F80
/* 0E8918 802C3F68 2A020080 */   slti  $v0, $s0, 0x80
/* 0E891C 802C3F6C 26100001 */  addiu $s0, $s0, 1
/* 0E8920 802C3F70 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8924 802C3F74 1440FFFA */  bnez  $v0, .L802C3F60
/* 0E8928 802C3F78 24630004 */   addiu $v1, $v1, 4
/* 0E892C 802C3F7C 2A020080 */  slti  $v0, $s0, 0x80
.L802C3F80:
/* 0E8930 802C3F80 10400044 */  beqz  $v0, .L802C4094
/* 0E8934 802C3F84 00000000 */   nop   
/* 0E8938 802C3F88 8E440068 */  lw    $a0, 0x68($s2)
/* 0E893C 802C3F8C 10800003 */  beqz  $a0, .L802C3F9C
/* 0E8940 802C3F90 0000882D */   daddu $s1, $zero, $zero
/* 0E8944 802C3F94 0C0B0FCF */  jal   kill_script
/* 0E8948 802C3F98 00000000 */   nop   
.L802C3F9C:
/* 0E894C 802C3F9C 3C03802E */  lui   $v1, 0x802e
/* 0E8950 802C3FA0 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8954 802C3FA4 00111080 */  sll   $v0, $s1, 2
/* 0E8958 802C3FA8 00431021 */  addu  $v0, $v0, $v1
/* 0E895C 802C3FAC 8C440000 */  lw    $a0, ($v0)
/* 0E8960 802C3FB0 10800006 */  beqz  $a0, .L802C3FCC
/* 0E8964 802C3FB4 26310001 */   addiu $s1, $s1, 1
/* 0E8968 802C3FB8 8C82006C */  lw    $v0, 0x6c($a0)
/* 0E896C 802C3FBC 14520003 */  bne   $v0, $s2, .L802C3FCC
/* 0E8970 802C3FC0 00000000 */   nop   
/* 0E8974 802C3FC4 0C0B0FCF */  jal   kill_script
/* 0E8978 802C3FC8 00000000 */   nop   
.L802C3FCC:
/* 0E897C 802C3FCC 2A220080 */  slti  $v0, $s1, 0x80
/* 0E8980 802C3FD0 1440FFF2 */  bnez  $v0, .L802C3F9C
/* 0E8984 802C3FD4 00000000 */   nop   
/* 0E8988 802C3FD8 8E450064 */  lw    $a1, 0x64($s2)
/* 0E898C 802C3FDC 10A00018 */  beqz  $a1, .L802C4040
/* 0E8990 802C3FE0 0000882D */   daddu $s1, $zero, $zero
/* 0E8994 802C3FE4 0240202D */  daddu $a0, $s2, $zero
/* 0E8998 802C3FE8 90A20000 */  lbu   $v0, ($a1)
/* 0E899C 802C3FEC 00A0182D */  daddu $v1, $a1, $zero
/* 0E89A0 802C3FF0 ACA00068 */  sw    $zero, 0x68($a1)
/* 0E89A4 802C3FF4 304200EF */  andi  $v0, $v0, 0xef
/* 0E89A8 802C3FF8 A0A20000 */  sb    $v0, ($a1)
.L802C3FFC:
/* 0E89AC 802C3FFC 8C820084 */  lw    $v0, 0x84($a0)
/* 0E89B0 802C4000 24840004 */  addiu $a0, $a0, 4
/* 0E89B4 802C4004 26310001 */  addiu $s1, $s1, 1
/* 0E89B8 802C4008 AC620084 */  sw    $v0, 0x84($v1)
/* 0E89BC 802C400C 2A220010 */  slti  $v0, $s1, 0x10
/* 0E89C0 802C4010 1440FFFA */  bnez  $v0, .L802C3FFC
/* 0E89C4 802C4014 24630004 */   addiu $v1, $v1, 4
/* 0E89C8 802C4018 0000882D */  daddu $s1, $zero, $zero
/* 0E89CC 802C401C 0240202D */  daddu $a0, $s2, $zero
/* 0E89D0 802C4020 00A0182D */  daddu $v1, $a1, $zero
.L802C4024:
/* 0E89D4 802C4024 8C8200C4 */  lw    $v0, 0xc4($a0)
/* 0E89D8 802C4028 24840004 */  addiu $a0, $a0, 4
/* 0E89DC 802C402C 26310001 */  addiu $s1, $s1, 1
/* 0E89E0 802C4030 AC6200C4 */  sw    $v0, 0xc4($v1)
/* 0E89E4 802C4034 2A220003 */  slti  $v0, $s1, 3
/* 0E89E8 802C4038 1440FFFA */  bnez  $v0, .L802C4024
/* 0E89EC 802C403C 24630004 */   addiu $v1, $v1, 4
.L802C4040:
/* 0E89F0 802C4040 8E440060 */  lw    $a0, 0x60($s2)
/* 0E89F4 802C4044 10800004 */  beqz  $a0, .L802C4058
/* 0E89F8 802C4048 00000000 */   nop   
/* 0E89FC 802C404C 0C00AB4B */  jal   heap_free
/* 0E8A00 802C4050 00000000 */   nop   
/* 0E8A04 802C4054 AE400060 */  sw    $zero, 0x60($s2)
.L802C4058:
/* 0E8A08 802C4058 3C11802E */  lui   $s1, 0x802e
/* 0E8A0C 802C405C 2631A890 */  addiu $s1, $s1, -0x5770
/* 0E8A10 802C4060 8E220000 */  lw    $v0, ($s1)
/* 0E8A14 802C4064 00108080 */  sll   $s0, $s0, 2
/* 0E8A18 802C4068 02021021 */  addu  $v0, $s0, $v0
/* 0E8A1C 802C406C 0C00AB4B */  jal   heap_free
/* 0E8A20 802C4070 8C440000 */   lw    $a0, ($v0)
/* 0E8A24 802C4074 3C04802E */  lui   $a0, 0x802e
/* 0E8A28 802C4078 2484A488 */  addiu $a0, $a0, -0x5b78
/* 0E8A2C 802C407C 8E230000 */  lw    $v1, ($s1)
/* 0E8A30 802C4080 8C820000 */  lw    $v0, ($a0)
/* 0E8A34 802C4084 02038021 */  addu  $s0, $s0, $v1
/* 0E8A38 802C4088 2442FFFF */  addiu $v0, $v0, -1
/* 0E8A3C 802C408C AE000000 */  sw    $zero, ($s0)
/* 0E8A40 802C4090 AC820000 */  sw    $v0, ($a0)
.L802C4094:
/* 0E8A44 802C4094 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E8A48 802C4098 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E8A4C 802C409C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8A50 802C40A0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8A54 802C40A4 03E00008 */  jr    $ra
/* 0E8A58 802C40A8 27BD0020 */   addiu $sp, $sp, 0x20

