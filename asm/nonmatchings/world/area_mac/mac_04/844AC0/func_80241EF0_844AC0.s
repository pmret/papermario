.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EF0_844AC0
/* 844AC0 80241EF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 844AC4 80241EF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 844AC8 80241EF8 0080802D */  daddu     $s0, $a0, $zero
/* 844ACC 80241EFC AFB20018 */  sw        $s2, 0x18($sp)
/* 844AD0 80241F00 AFBF001C */  sw        $ra, 0x1c($sp)
/* 844AD4 80241F04 AFB10014 */  sw        $s1, 0x14($sp)
/* 844AD8 80241F08 8E02000C */  lw        $v0, 0xc($s0)
/* 844ADC 80241F0C 10A00008 */  beqz      $a1, .L80241F30
/* 844AE0 80241F10 0000902D */   daddu    $s2, $zero, $zero
/* 844AE4 80241F14 8C450000 */  lw        $a1, ($v0)
/* 844AE8 80241F18 0C0B1EAF */  jal       get_variable
/* 844AEC 80241F1C 00000000 */   nop      
/* 844AF0 80241F20 AE020070 */  sw        $v0, 0x70($s0)
/* 844AF4 80241F24 AE000074 */  sw        $zero, 0x74($s0)
/* 844AF8 80241F28 8C420014 */  lw        $v0, 0x14($v0)
/* 844AFC 80241F2C AE020078 */  sw        $v0, 0x78($s0)
.L80241F30:
/* 844B00 80241F30 8E050078 */  lw        $a1, 0x78($s0)
/* 844B04 80241F34 8E110070 */  lw        $s1, 0x70($s0)
/* 844B08 80241F38 0C0B1EAF */  jal       get_variable
/* 844B0C 80241F3C 0200202D */   daddu    $a0, $s0, $zero
/* 844B10 80241F40 10400006 */  beqz      $v0, .L80241F5C
/* 844B14 80241F44 24030002 */   addiu    $v1, $zero, 2
/* 844B18 80241F48 8E020074 */  lw        $v0, 0x74($s0)
/* 844B1C 80241F4C 10430027 */  beq       $v0, $v1, .L80241FEC
/* 844B20 80241F50 00000000 */   nop      
/* 844B24 80241F54 080907FA */  j         .L80241FE8
/* 844B28 80241F58 AE030074 */   sw       $v1, 0x74($s0)
.L80241F5C:
/* 844B2C 80241F5C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 844B30 80241F60 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 844B34 80241F64 8E260000 */  lw        $a2, ($s1)
/* 844B38 80241F68 8E270004 */  lw        $a3, 4($s1)
/* 844B3C 80241F6C C44C0028 */  lwc1      $f12, 0x28($v0)
/* 844B40 80241F70 0C00A7B5 */  jal       dist2D
/* 844B44 80241F74 C44E0030 */   lwc1     $f14, 0x30($v0)
/* 844B48 80241F78 8E030074 */  lw        $v1, 0x74($s0)
/* 844B4C 80241F7C 24040001 */  addiu     $a0, $zero, 1
/* 844B50 80241F80 10640013 */  beq       $v1, $a0, .L80241FD0
/* 844B54 80241F84 46000086 */   mov.s    $f2, $f0
/* 844B58 80241F88 28620002 */  slti      $v0, $v1, 2
/* 844B5C 80241F8C 50400005 */  beql      $v0, $zero, .L80241FA4
/* 844B60 80241F90 24020002 */   addiu    $v0, $zero, 2
/* 844B64 80241F94 10600007 */  beqz      $v1, .L80241FB4
/* 844B68 80241F98 00000000 */   nop      
/* 844B6C 80241F9C 080907FB */  j         .L80241FEC
/* 844B70 80241FA0 00000000 */   nop      
.L80241FA4:
/* 844B74 80241FA4 50620010 */  beql      $v1, $v0, .L80241FE8
/* 844B78 80241FA8 AE040074 */   sw       $a0, 0x74($s0)
/* 844B7C 80241FAC 080907FB */  j         .L80241FEC
/* 844B80 80241FB0 00000000 */   nop      
.L80241FB4:
/* 844B84 80241FB4 C6200008 */  lwc1      $f0, 8($s1)
/* 844B88 80241FB8 4600103C */  c.lt.s    $f2, $f0
/* 844B8C 80241FBC 00000000 */  nop       
/* 844B90 80241FC0 4500000A */  bc1f      .L80241FEC
/* 844B94 80241FC4 00000000 */   nop      
/* 844B98 80241FC8 080907FA */  j         .L80241FE8
/* 844B9C 80241FCC AE040074 */   sw       $a0, 0x74($s0)
.L80241FD0:
/* 844BA0 80241FD0 C620000C */  lwc1      $f0, 0xc($s1)
/* 844BA4 80241FD4 4602003C */  c.lt.s    $f0, $f2
/* 844BA8 80241FD8 00000000 */  nop       
/* 844BAC 80241FDC 45000003 */  bc1f      .L80241FEC
/* 844BB0 80241FE0 00000000 */   nop      
/* 844BB4 80241FE4 AE000074 */  sw        $zero, 0x74($s0)
.L80241FE8:
/* 844BB8 80241FE8 24120001 */  addiu     $s2, $zero, 1
.L80241FEC:
/* 844BBC 80241FEC 12400005 */  beqz      $s2, .L80242004
/* 844BC0 80241FF0 00000000 */   nop      
/* 844BC4 80241FF4 8E250010 */  lw        $a1, 0x10($s1)
/* 844BC8 80241FF8 86060076 */  lh        $a2, 0x76($s0)
/* 844BCC 80241FFC 0C052A95 */  jal       func_8014AA54
/* 844BD0 80242000 0000202D */   daddu    $a0, $zero, $zero
.L80242004:
/* 844BD4 80242004 8FBF001C */  lw        $ra, 0x1c($sp)
/* 844BD8 80242008 8FB20018 */  lw        $s2, 0x18($sp)
/* 844BDC 8024200C 8FB10014 */  lw        $s1, 0x14($sp)
/* 844BE0 80242010 8FB00010 */  lw        $s0, 0x10($sp)
/* 844BE4 80242014 0000102D */  daddu     $v0, $zero, $zero
/* 844BE8 80242018 03E00008 */  jr        $ra
/* 844BEC 8024201C 27BD0020 */   addiu    $sp, $sp, 0x20
