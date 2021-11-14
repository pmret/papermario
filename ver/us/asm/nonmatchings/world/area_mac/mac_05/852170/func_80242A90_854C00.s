.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80252950_864AC0
.word L80242B14_854C84, L80242B24_854C94, L80242B34_854CA4, L80242B44_854CB4, L80242B68_854CD8

.section .text

glabel func_80242A90_854C00
/* 854C00 80242A90 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 854C04 80242A94 AFB20018 */  sw        $s2, 0x18($sp)
/* 854C08 80242A98 0080902D */  daddu     $s2, $a0, $zero
/* 854C0C 80242A9C AFBF0028 */  sw        $ra, 0x28($sp)
/* 854C10 80242AA0 AFB50024 */  sw        $s5, 0x24($sp)
/* 854C14 80242AA4 AFB40020 */  sw        $s4, 0x20($sp)
/* 854C18 80242AA8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 854C1C 80242AAC AFB10014 */  sw        $s1, 0x14($sp)
/* 854C20 80242AB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 854C24 80242AB4 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 854C28 80242AB8 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 854C2C 80242ABC F7B60038 */  sdc1      $f22, 0x38($sp)
/* 854C30 80242AC0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 854C34 80242AC4 8E50000C */  lw        $s0, 0xc($s2)
/* 854C38 80242AC8 8E050000 */  lw        $a1, ($s0)
/* 854C3C 80242ACC 0C0B1EAF */  jal       evt_get_variable
/* 854C40 80242AD0 26100004 */   addiu    $s0, $s0, 4
/* 854C44 80242AD4 8E130000 */  lw        $s3, ($s0)
/* 854C48 80242AD8 26100004 */  addiu     $s0, $s0, 4
/* 854C4C 80242ADC 0000202D */  daddu     $a0, $zero, $zero
/* 854C50 80242AE0 8E140000 */  lw        $s4, ($s0)
/* 854C54 80242AE4 8E150004 */  lw        $s5, 4($s0)
/* 854C58 80242AE8 0C00EAD2 */  jal       get_npc_safe
/* 854C5C 80242AEC 0040882D */   daddu    $s1, $v0, $zero
/* 854C60 80242AF0 0040802D */  daddu     $s0, $v0, $zero
/* 854C64 80242AF4 2E220005 */  sltiu     $v0, $s1, 5
/* 854C68 80242AF8 10400024 */  beqz      $v0, .L80242B8C
/* 854C6C 80242AFC 00111080 */   sll      $v0, $s1, 2
/* 854C70 80242B00 3C018025 */  lui       $at, %hi(jtbl_80252950_864AC0)
/* 854C74 80242B04 00220821 */  addu      $at, $at, $v0
/* 854C78 80242B08 8C222950 */  lw        $v0, %lo(jtbl_80252950_864AC0)($at)
/* 854C7C 80242B0C 00400008 */  jr        $v0
/* 854C80 80242B10 00000000 */   nop
dlabel L80242B14_854C84
/* 854C84 80242B14 3C01425C */  lui       $at, 0x425c
/* 854C88 80242B18 4481D000 */  mtc1      $at, $f26
/* 854C8C 80242B1C 08090AEB */  j         .L80242BAC
/* 854C90 80242B20 2A220003 */   slti     $v0, $s1, 3
dlabel L80242B24_854C94
/* 854C94 80242B24 3C0142AA */  lui       $at, 0x42aa
/* 854C98 80242B28 4481D000 */  mtc1      $at, $f26
/* 854C9C 80242B2C 08090AEB */  j         .L80242BAC
/* 854CA0 80242B30 2A220003 */   slti     $v0, $s1, 3
dlabel L80242B34_854CA4
/* 854CA4 80242B34 3C0141C8 */  lui       $at, 0x41c8
/* 854CA8 80242B38 4481D000 */  mtc1      $at, $f26
/* 854CAC 80242B3C 08090AEB */  j         .L80242BAC
/* 854CB0 80242B40 2A220003 */   slti     $v0, $s1, 3
dlabel L80242B44_854CB4
/* 854CB4 80242B44 3C01C393 */  lui       $at, 0xc393
/* 854CB8 80242B48 34218000 */  ori       $at, $at, 0x8000
/* 854CBC 80242B4C 4481C000 */  mtc1      $at, $f24
/* 854CC0 80242B50 3C01C120 */  lui       $at, 0xc120
/* 854CC4 80242B54 4481B000 */  mtc1      $at, $f22
/* 854CC8 80242B58 3C0143C8 */  lui       $at, 0x43c8
/* 854CCC 80242B5C 4481A000 */  mtc1      $at, $f20
/* 854CD0 80242B60 08090AEB */  j         .L80242BAC
/* 854CD4 80242B64 2A220003 */   slti     $v0, $s1, 3
dlabel L80242B68_854CD8
/* 854CD8 80242B68 3C01C38E */  lui       $at, 0xc38e
/* 854CDC 80242B6C 34218000 */  ori       $at, $at, 0x8000
/* 854CE0 80242B70 4481C000 */  mtc1      $at, $f24
/* 854CE4 80242B74 3C01C120 */  lui       $at, 0xc120
/* 854CE8 80242B78 4481B000 */  mtc1      $at, $f22
/* 854CEC 80242B7C 3C0143BE */  lui       $at, 0x43be
/* 854CF0 80242B80 4481A000 */  mtc1      $at, $f20
/* 854CF4 80242B84 08090AEB */  j         .L80242BAC
/* 854CF8 80242B88 2A220003 */   slti     $v0, $s1, 3
.L80242B8C:
/* 854CFC 80242B8C 3C01C393 */  lui       $at, 0xc393
/* 854D00 80242B90 34218000 */  ori       $at, $at, 0x8000
/* 854D04 80242B94 4481C000 */  mtc1      $at, $f24
/* 854D08 80242B98 3C01C120 */  lui       $at, 0xc120
/* 854D0C 80242B9C 4481B000 */  mtc1      $at, $f22
/* 854D10 80242BA0 3C0143D2 */  lui       $at, 0x43d2
/* 854D14 80242BA4 4481A000 */  mtc1      $at, $f20
/* 854D18 80242BA8 2A220003 */  slti      $v0, $s1, 3
.L80242BAC:
/* 854D1C 80242BAC 10400019 */  beqz      $v0, .L80242C14
/* 854D20 80242BB0 0240202D */   daddu    $a0, $s2, $zero
/* 854D24 80242BB4 C614000C */  lwc1      $f20, 0xc($s0)
/* 854D28 80242BB8 4600A507 */  neg.s     $f20, $f20
/* 854D2C 80242BBC 0C00A8BB */  jal       sin_deg
/* 854D30 80242BC0 4600A306 */   mov.s    $f12, $f20
/* 854D34 80242BC4 461A0002 */  mul.s     $f0, $f0, $f26
/* 854D38 80242BC8 00000000 */  nop
/* 854D3C 80242BCC C6020038 */  lwc1      $f2, 0x38($s0)
/* 854D40 80242BD0 3C0141F0 */  lui       $at, 0x41f0
/* 854D44 80242BD4 44812000 */  mtc1      $at, $f4
/* 854D48 80242BD8 00000000 */  nop
/* 854D4C 80242BDC 46041080 */  add.s     $f2, $f2, $f4
/* 854D50 80242BE0 46001600 */  add.s     $f24, $f2, $f0
/* 854D54 80242BE4 0C00A8D4 */  jal       cos_deg
/* 854D58 80242BE8 4600A306 */   mov.s    $f12, $f20
/* 854D5C 80242BEC 461A0002 */  mul.s     $f0, $f0, $f26
/* 854D60 80242BF0 00000000 */  nop
/* 854D64 80242BF4 C604003C */  lwc1      $f4, 0x3c($s0)
/* 854D68 80242BF8 3C014248 */  lui       $at, 0x4248
/* 854D6C 80242BFC 44811000 */  mtc1      $at, $f2
/* 854D70 80242C00 00000000 */  nop
/* 854D74 80242C04 46022580 */  add.s     $f22, $f4, $f2
/* 854D78 80242C08 C6020040 */  lwc1      $f2, 0x40($s0)
/* 854D7C 80242C0C 46001500 */  add.s     $f20, $f2, $f0
/* 854D80 80242C10 0240202D */  daddu     $a0, $s2, $zero
.L80242C14:
/* 854D84 80242C14 4406C000 */  mfc1      $a2, $f24
/* 854D88 80242C18 0C0B2190 */  jal       evt_set_float_variable
/* 854D8C 80242C1C 0260282D */   daddu    $a1, $s3, $zero
/* 854D90 80242C20 0240202D */  daddu     $a0, $s2, $zero
/* 854D94 80242C24 4406B000 */  mfc1      $a2, $f22
/* 854D98 80242C28 0C0B2190 */  jal       evt_set_float_variable
/* 854D9C 80242C2C 0280282D */   daddu    $a1, $s4, $zero
/* 854DA0 80242C30 0240202D */  daddu     $a0, $s2, $zero
/* 854DA4 80242C34 4406A000 */  mfc1      $a2, $f20
/* 854DA8 80242C38 0C0B2190 */  jal       evt_set_float_variable
/* 854DAC 80242C3C 02A0282D */   daddu    $a1, $s5, $zero
/* 854DB0 80242C40 8FBF0028 */  lw        $ra, 0x28($sp)
/* 854DB4 80242C44 8FB50024 */  lw        $s5, 0x24($sp)
/* 854DB8 80242C48 8FB40020 */  lw        $s4, 0x20($sp)
/* 854DBC 80242C4C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 854DC0 80242C50 8FB20018 */  lw        $s2, 0x18($sp)
/* 854DC4 80242C54 8FB10014 */  lw        $s1, 0x14($sp)
/* 854DC8 80242C58 8FB00010 */  lw        $s0, 0x10($sp)
/* 854DCC 80242C5C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 854DD0 80242C60 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 854DD4 80242C64 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 854DD8 80242C68 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 854DDC 80242C6C 24020002 */  addiu     $v0, $zero, 2
/* 854DE0 80242C70 03E00008 */  jr        $ra
/* 854DE4 80242C74 27BD0050 */   addiu    $sp, $sp, 0x50
