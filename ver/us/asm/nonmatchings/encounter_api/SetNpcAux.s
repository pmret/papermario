.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetNpcAux
/* 201A4 80044DA4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 201A8 80044DA8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 201AC 80044DAC 0080982D */  daddu     $s3, $a0, $zero
/* 201B0 80044DB0 AFB40020 */  sw        $s4, 0x20($sp)
/* 201B4 80044DB4 24140002 */  addiu     $s4, $zero, 2
/* 201B8 80044DB8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 201BC 80044DBC AFB20018 */  sw        $s2, 0x18($sp)
/* 201C0 80044DC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 201C4 80044DC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 201C8 80044DC8 8E70000C */  lw        $s0, 0xc($s3)
/* 201CC 80044DCC 8E710148 */  lw        $s1, 0x148($s3)
/* 201D0 80044DD0 8E050000 */  lw        $a1, ($s0)
/* 201D4 80044DD4 0C0B1EAF */  jal       evt_get_variable
/* 201D8 80044DD8 26100004 */   addiu    $s0, $s0, 4
/* 201DC 80044DDC 0040902D */  daddu     $s2, $v0, $zero
/* 201E0 80044DE0 8E050000 */  lw        $a1, ($s0)
/* 201E4 80044DE4 0C0B1EAF */  jal       evt_get_variable
/* 201E8 80044DE8 0260202D */   daddu    $a0, $s3, $zero
/* 201EC 80044DEC 0040802D */  daddu     $s0, $v0, $zero
/* 201F0 80044DF0 2402FFFF */  addiu     $v0, $zero, -1
/* 201F4 80044DF4 12220011 */  beq       $s1, $v0, .L80044E3C
/* 201F8 80044DF8 0260182D */   daddu    $v1, $s3, $zero
/* 201FC 80044DFC 12420004 */  beq       $s2, $v0, .L80044E10
/* 20200 80044E00 00000000 */   nop
/* 20204 80044E04 86220008 */  lh        $v0, 8($s1)
/* 20208 80044E08 1452000C */  bne       $v0, $s2, .L80044E3C
/* 2020C 80044E0C 00000000 */   nop
.L80044E10:
/* 20210 80044E10 86320008 */  lh        $s2, 8($s1)
.L80044E14:
/* 20214 80044E14 8C620064 */  lw        $v0, 0x64($v1)
/* 20218 80044E18 10400003 */  beqz      $v0, .L80044E28
/* 2021C 80044E1C 00000000 */   nop
/* 20220 80044E20 08011385 */  j         .L80044E14
/* 20224 80044E24 0040182D */   daddu    $v1, $v0, $zero
.L80044E28:
/* 20228 80044E28 8E220044 */  lw        $v0, 0x44($s1)
/* 2022C 80044E2C 50620007 */  beql      $v1, $v0, .L80044E4C
/* 20230 80044E30 241400FF */   addiu    $s4, $zero, 0xff
/* 20234 80044E34 08011393 */  j         .L80044E4C
/* 20238 80044E38 00000000 */   nop
.L80044E3C:
/* 2023C 80044E3C 0C00FB3A */  jal       get_enemy
/* 20240 80044E40 0240202D */   daddu    $a0, $s2, $zero
/* 20244 80044E44 0040882D */  daddu     $s1, $v0, $zero
/* 20248 80044E48 8E220044 */  lw        $v0, 0x44($s1)
.L80044E4C:
/* 2024C 80044E4C 10400003 */  beqz      $v0, .L80044E5C
/* 20250 80044E50 00000000 */   nop
/* 20254 80044E54 0C0B102B */  jal       kill_script_by_ID
/* 20258 80044E58 8E24005C */   lw       $a0, 0x5c($s1)
.L80044E5C:
/* 2025C 80044E5C 1200000D */  beqz      $s0, .L80044E94
/* 20260 80044E60 0200202D */   daddu    $a0, $s0, $zero
/* 20264 80044E64 2405000A */  addiu     $a1, $zero, 0xa
/* 20268 80044E68 0000302D */  daddu     $a2, $zero, $zero
/* 2026C 80044E6C 0C0B0CF8 */  jal       start_script
/* 20270 80044E70 AE24002C */   sw       $a0, 0x2c($s1)
/* 20274 80044E74 0040182D */  daddu     $v1, $v0, $zero
/* 20278 80044E78 AE230044 */  sw        $v1, 0x44($s1)
/* 2027C 80044E7C 8C620144 */  lw        $v0, 0x144($v1)
/* 20280 80044E80 AE22005C */  sw        $v0, 0x5c($s1)
/* 20284 80044E84 AC710148 */  sw        $s1, 0x148($v1)
/* 20288 80044E88 AC72014C */  sw        $s2, 0x14c($v1)
/* 2028C 80044E8C 92620004 */  lbu       $v0, 4($s3)
/* 20290 80044E90 A0620004 */  sb        $v0, 4($v1)
.L80044E94:
/* 20294 80044E94 0280102D */  daddu     $v0, $s4, $zero
/* 20298 80044E98 8FBF0024 */  lw        $ra, 0x24($sp)
/* 2029C 80044E9C 8FB40020 */  lw        $s4, 0x20($sp)
/* 202A0 80044EA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 202A4 80044EA4 8FB20018 */  lw        $s2, 0x18($sp)
/* 202A8 80044EA8 8FB10014 */  lw        $s1, 0x14($sp)
/* 202AC 80044EAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 202B0 80044EB0 03E00008 */  jr        $ra
/* 202B4 80044EB4 27BD0028 */   addiu    $sp, $sp, 0x28
