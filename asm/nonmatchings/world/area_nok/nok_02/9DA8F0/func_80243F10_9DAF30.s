.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243F10_9DAF30
/* 9DAF30 80243F10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9DAF34 80243F14 AFB40020 */  sw        $s4, 0x20($sp)
/* 9DAF38 80243F18 0080A02D */  daddu     $s4, $a0, $zero
/* 9DAF3C 80243F1C AFB20018 */  sw        $s2, 0x18($sp)
/* 9DAF40 80243F20 0000902D */  daddu     $s2, $zero, $zero
/* 9DAF44 80243F24 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9DAF48 80243F28 3C138025 */  lui       $s3, %hi(D_80252784)
/* 9DAF4C 80243F2C 26732784 */  addiu     $s3, $s3, %lo(D_80252784)
/* 9DAF50 80243F30 AFB10014 */  sw        $s1, 0x14($sp)
/* 9DAF54 80243F34 0240882D */  daddu     $s1, $s2, $zero
/* 9DAF58 80243F38 AFBF002C */  sw        $ra, 0x2c($sp)
/* 9DAF5C 80243F3C AFB60028 */  sw        $s6, 0x28($sp)
/* 9DAF60 80243F40 AFB50024 */  sw        $s5, 0x24($sp)
/* 9DAF64 80243F44 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DAF68 80243F48 8E82000C */  lw        $v0, 0xc($s4)
/* 9DAF6C 80243F4C 26700010 */  addiu     $s0, $s3, 0x10
/* 9DAF70 80243F50 8C550000 */  lw        $s5, ($v0)
.L80243F54:
/* 9DAF74 80243F54 8E05FFFC */  lw        $a1, -4($s0)
/* 9DAF78 80243F58 0C0B1EAF */  jal       get_variable
/* 9DAF7C 80243F5C 0280202D */   daddu    $a0, $s4, $zero
/* 9DAF80 80243F60 5040000D */  beql      $v0, $zero, .L80243F98
/* 9DAF84 80243F64 26310001 */   addiu    $s1, $s1, 1
/* 9DAF88 80243F68 8E050004 */  lw        $a1, 4($s0)
/* 9DAF8C 80243F6C 0C0B1EAF */  jal       get_variable
/* 9DAF90 80243F70 0280202D */   daddu    $a0, $s4, $zero
/* 9DAF94 80243F74 54400008 */  bnel      $v0, $zero, .L80243F98
/* 9DAF98 80243F78 26310001 */   addiu    $s1, $s1, 1
/* 9DAF9C 80243F7C 26520001 */  addiu     $s2, $s2, 1
/* 9DAFA0 80243F80 8E050000 */  lw        $a1, ($s0)
/* 9DAFA4 80243F84 0C0B1EAF */  jal       get_variable
/* 9DAFA8 80243F88 0280202D */   daddu    $a0, $s4, $zero
/* 9DAFAC 80243F8C 10400007 */  beqz      $v0, .L80243FAC
/* 9DAFB0 80243F90 24020014 */   addiu    $v0, $zero, 0x14
/* 9DAFB4 80243F94 26310001 */  addiu     $s1, $s1, 1
.L80243F98:
/* 9DAFB8 80243F98 2610001C */  addiu     $s0, $s0, 0x1c
/* 9DAFBC 80243F9C 2E220014 */  sltiu     $v0, $s1, 0x14
/* 9DAFC0 80243FA0 1440FFEC */  bnez      $v0, .L80243F54
/* 9DAFC4 80243FA4 2673001C */   addiu    $s3, $s3, 0x1c
/* 9DAFC8 80243FA8 24020014 */  addiu     $v0, $zero, 0x14
.L80243FAC:
/* 9DAFCC 80243FAC 16220021 */  bne       $s1, $v0, .L80244034
/* 9DAFD0 80243FB0 0280202D */   daddu    $a0, $s4, $zero
/* 9DAFD4 80243FB4 16400004 */  bnez      $s2, .L80243FC8
/* 9DAFD8 80243FB8 02A0282D */   daddu    $a1, $s5, $zero
/* 9DAFDC 80243FBC AE800084 */  sw        $zero, 0x84($s4)
/* 9DAFE0 80243FC0 08091011 */  j         .L80244044
/* 9DAFE4 80243FC4 240600FF */   addiu    $a2, $zero, 0xff
.L80243FC8:
/* 9DAFE8 80243FC8 0C00A67F */  jal       rand_int
/* 9DAFEC 80243FCC 2644FFFF */   addiu    $a0, $s2, -1
/* 9DAFF0 80243FD0 0040B02D */  daddu     $s6, $v0, $zero
/* 9DAFF4 80243FD4 0000902D */  daddu     $s2, $zero, $zero
/* 9DAFF8 80243FD8 3C138025 */  lui       $s3, %hi(D_80252784)
/* 9DAFFC 80243FDC 26732784 */  addiu     $s3, $s3, %lo(D_80252784)
/* 9DB000 80243FE0 0240882D */  daddu     $s1, $s2, $zero
/* 9DB004 80243FE4 26700014 */  addiu     $s0, $s3, 0x14
.L80243FE8:
/* 9DB008 80243FE8 8E05FFF8 */  lw        $a1, -8($s0)
/* 9DB00C 80243FEC 0C0B1EAF */  jal       get_variable
/* 9DB010 80243FF0 0280202D */   daddu    $a0, $s4, $zero
/* 9DB014 80243FF4 5040000A */  beql      $v0, $zero, .L80244020
/* 9DB018 80243FF8 26310001 */   addiu    $s1, $s1, 1
/* 9DB01C 80243FFC 8E050000 */  lw        $a1, ($s0)
/* 9DB020 80244000 0C0B1EAF */  jal       get_variable
/* 9DB024 80244004 0280202D */   daddu    $a0, $s4, $zero
/* 9DB028 80244008 54400005 */  bnel      $v0, $zero, .L80244020
/* 9DB02C 8024400C 26310001 */   addiu    $s1, $s1, 1
/* 9DB030 80244010 0240102D */  daddu     $v0, $s2, $zero
/* 9DB034 80244014 10560006 */  beq       $v0, $s6, .L80244030
/* 9DB038 80244018 26520001 */   addiu    $s2, $s2, 1
/* 9DB03C 8024401C 26310001 */  addiu     $s1, $s1, 1
.L80244020:
/* 9DB040 80244020 2610001C */  addiu     $s0, $s0, 0x1c
/* 9DB044 80244024 2E220014 */  sltiu     $v0, $s1, 0x14
/* 9DB048 80244028 1440FFEF */  bnez      $v0, .L80243FE8
/* 9DB04C 8024402C 2673001C */   addiu    $s3, $s3, 0x1c
.L80244030:
/* 9DB050 80244030 0280202D */  daddu     $a0, $s4, $zero
.L80244034:
/* 9DB054 80244034 02A0282D */  daddu     $a1, $s5, $zero
/* 9DB058 80244038 8E620000 */  lw        $v0, ($s3)
/* 9DB05C 8024403C 26260001 */  addiu     $a2, $s1, 1
/* 9DB060 80244040 AC820084 */  sw        $v0, 0x84($a0)
.L80244044:
/* 9DB064 80244044 0C0B2026 */  jal       set_variable
/* 9DB068 80244048 00000000 */   nop      
/* 9DB06C 8024404C 24020002 */  addiu     $v0, $zero, 2
/* 9DB070 80244050 8FBF002C */  lw        $ra, 0x2c($sp)
/* 9DB074 80244054 8FB60028 */  lw        $s6, 0x28($sp)
/* 9DB078 80244058 8FB50024 */  lw        $s5, 0x24($sp)
/* 9DB07C 8024405C 8FB40020 */  lw        $s4, 0x20($sp)
/* 9DB080 80244060 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9DB084 80244064 8FB20018 */  lw        $s2, 0x18($sp)
/* 9DB088 80244068 8FB10014 */  lw        $s1, 0x14($sp)
/* 9DB08C 8024406C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DB090 80244070 03E00008 */  jr        $ra
/* 9DB094 80244074 27BD0030 */   addiu    $sp, $sp, 0x30
