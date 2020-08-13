.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80243BA4
/* 136EE4 80243BA4 0C019D40 */  jal   guMtxF2L
/* 136EE8 80243BA8 00452821 */   addu  $a1, $v0, $a1
/* 136EEC 80243BAC 3C02DA38 */  lui   $v0, 0xda38
/* 136EF0 80243BB0 34420002 */  ori   $v0, $v0, 2
/* 136EF4 80243BB4 24050006 */  addiu $a1, $zero, 6
/* 136EF8 80243BB8 240600FF */  addiu $a2, $zero, 0xff
/* 136EFC 80243BBC 00C0382D */  daddu $a3, $a2, $zero
/* 136F00 80243BC0 00178080 */  sll   $s0, $s7, 2
/* 136F04 80243BC4 26F70001 */  addiu $s7, $s7, 1
/* 136F08 80243BC8 8EC80000 */  lw    $t0, ($s6)
/* 136F0C 80243BCC 97C90000 */  lhu   $t1, ($fp)
/* 136F10 80243BD0 3C03800A */  lui   $v1, 0x800a
/* 136F14 80243BD4 8C63A674 */  lw    $v1, -0x598c($v1)
/* 136F18 80243BD8 0100202D */  daddu $a0, $t0, $zero
/* 136F1C 80243BDC AC820000 */  sw    $v0, ($a0)
/* 136F20 80243BE0 3122FFFF */  andi  $v0, $t1, 0xffff
/* 136F24 80243BE4 00A21004 */  sllv  $v0, $v0, $a1
/* 136F28 80243BE8 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 136F2C 80243BEC 25080008 */  addiu $t0, $t0, 8
/* 136F30 80243BF0 004F1021 */  addu  $v0, $v0, $t7
/* 136F34 80243BF4 00621821 */  addu  $v1, $v1, $v0
/* 136F38 80243BF8 00C0102D */  daddu $v0, $a2, $zero
/* 136F3C 80243BFC AC830004 */  sw    $v1, 4($a0)
/* 136F40 80243C00 240E0040 */  addiu $t6, $zero, 0x40
/* 136F44 80243C04 AFA20010 */  sw    $v0, 0x10($sp)
/* 136F48 80243C08 AFA20014 */  sw    $v0, 0x14($sp)
/* 136F4C 80243C0C 3C028027 */  lui   $v0, 0x8027
/* 136F50 80243C10 2442011C */  addiu $v0, $v0, 0x11c
/* 136F54 80243C14 02028021 */  addu  $s0, $s0, $v0
/* 136F58 80243C18 AFAE0018 */  sw    $t6, 0x18($sp)
/* 136F5C 80243C1C 8E040000 */  lw    $a0, ($s0)
/* 136F60 80243C20 25290001 */  addiu $t1, $t1, 1
/* 136F64 80243C24 AEC80000 */  sw    $t0, ($s6)
/* 136F68 80243C28 0C0B7A25 */  jal   func_802DE894
/* 136F6C 80243C2C A7C90000 */   sh    $t1, ($fp)
/* 136F70 80243C30 0000282D */  daddu $a1, $zero, $zero
/* 136F74 80243C34 00A0302D */  daddu $a2, $a1, $zero
/* 136F78 80243C38 27A20028 */  addiu $v0, $sp, 0x28
/* 136F7C 80243C3C AFA20010 */  sw    $v0, 0x10($sp)
/* 136F80 80243C40 8E040000 */  lw    $a0, ($s0)
/* 136F84 80243C44 0C0B78F6 */  jal   func_802DE3D8
/* 136F88 80243C48 00A0382D */   daddu $a3, $a1, $zero
/* 136F8C 80243C4C 3C04D838 */  lui   $a0, 0xd838
/* 136F90 80243C50 8EC20000 */  lw    $v0, ($s6)
/* 136F94 80243C54 34840002 */  ori   $a0, $a0, 2
/* 136F98 80243C58 0040182D */  daddu $v1, $v0, $zero
/* 136F9C 80243C5C 24420008 */  addiu $v0, $v0, 8
/* 136FA0 80243C60 240F0040 */  addiu $t7, $zero, 0x40
/* 136FA4 80243C64 AEC20000 */  sw    $v0, ($s6)
/* 136FA8 80243C68 2AE20003 */  slti  $v0, $s7, 3
/* 136FAC 80243C6C AC640000 */  sw    $a0, ($v1)
/* 136FB0 80243C70 1440FF8E */  bnez  $v0, .L80243AAC
/* 136FB4 80243C74 AC6F0004 */   sw    $t7, 4($v1)
/* 136FB8 80243C78 0C093BA0 */  jal   func_8024EE80
/* 136FBC 80243C7C 24040001 */   addiu $a0, $zero, 1
/* 136FC0 80243C80 0040202D */  daddu $a0, $v0, $zero
/* 136FC4 80243C84 27A500A8 */  addiu $a1, $sp, 0xa8
/* 136FC8 80243C88 27A600AC */  addiu $a2, $sp, 0xac
/* 136FCC 80243C8C 27A700B0 */  addiu $a3, $sp, 0xb0
/* 136FD0 80243C90 27A200B4 */  addiu $v0, $sp, 0xb4
/* 136FD4 80243C94 AFA20010 */  sw    $v0, 0x10($sp)
/* 136FD8 80243C98 27A200B8 */  addiu $v0, $sp, 0xb8
/* 136FDC 80243C9C 24140001 */  addiu $s4, $zero, 1
/* 136FE0 80243CA0 AFA20014 */  sw    $v0, 0x14($sp)
/* 136FE4 80243CA4 AFA00018 */  sw    $zero, 0x18($sp)
/* 136FE8 80243CA8 0C0497DA */  jal   get_string_properties
/* 136FEC 80243CAC AFB4001C */   sw    $s4, 0x1c($sp)
/* 136FF0 80243CB0 8FB000AC */  lw    $s0, 0xac($sp)
/* 136FF4 80243CB4 8FAE012C */  lw    $t6, 0x12c($sp)
/* 136FF8 80243CB8 0280202D */  daddu $a0, $s4, $zero
/* 136FFC 80243CBC 01D08023 */  subu  $s0, $t6, $s0
/* 137000 80243CC0 0C093BA0 */  jal   func_8024EE80
/* 137004 80243CC4 02908007 */   srav  $s0, $s0, $s4
/* 137008 80243CC8 0040202D */  daddu $a0, $v0, $zero
/* 13700C 80243CCC 8FAF0124 */  lw    $t7, 0x124($sp)
/* 137010 80243CD0 8FA60128 */  lw    $a2, 0x128($sp)
/* 137014 80243CD4 240700FF */  addiu $a3, $zero, 0xff
/* 137018 80243CD8 AFA00010 */  sw    $zero, 0x10($sp)
/* 13701C 80243CDC AFB40014 */  sw    $s4, 0x14($sp)
/* 137020 80243CE0 0C04993B */  jal   draw_string
/* 137024 80243CE4 01F02821 */   addu  $a1, $t7, $s0
/* 137028 80243CE8 3C158025 */  lui   $s5, 0x8025
/* 13702C 80243CEC 26B5F018 */  addiu $s5, $s5, -0xfe8
/* 137030 80243CF0 8EA20000 */  lw    $v0, ($s5)
/* 137034 80243CF4 3C138025 */  lui   $s3, 0x8025
/* 137038 80243CF8 2673F110 */  addiu $s3, $s3, -0xef0
/* 13703C 80243CFC 000220C0 */  sll   $a0, $v0, 3
/* 137040 80243D00 00822021 */  addu  $a0, $a0, $v0
/* 137044 80243D04 00042080 */  sll   $a0, $a0, 2
/* 137048 80243D08 00822023 */  subu  $a0, $a0, $v0
/* 13704C 80243D0C 8E620000 */  lw    $v0, ($s3)
/* 137050 80243D10 00042080 */  sll   $a0, $a0, 2
/* 137054 80243D14 0C090D06 */  jal   func_80243418
/* 137058 80243D18 00822023 */   subu  $a0, $a0, $v0
/* 13705C 80243D1C 3C08800A */  lui   $t0, 0x800a
/* 137060 80243D20 2508A66C */  addiu $t0, $t0, -0x5994
/* 137064 80243D24 8D060000 */  lw    $a2, ($t0)
/* 137068 80243D28 8FAE0124 */  lw    $t6, 0x124($sp)
/* 13706C 80243D2C 3C014080 */  lui   $at, 0x4080
/* 137070 80243D30 44812000 */  mtc1  $at, $f4
/* 137074 80243D34 8FAF0128 */  lw    $t7, 0x128($sp)
/* 137078 80243D38 01D41821 */  addu  $v1, $t6, $s4
/* 13707C 80243D3C 44831000 */  mtc1  $v1, $f2
/* 137080 80243D40 00000000 */  nop   
/* 137084 80243D44 468010A0 */  cvt.s.w $f2, $f2
/* 137088 80243D48 00C0382D */  daddu $a3, $a2, $zero
/* 13708C 80243D4C 46041082 */  mul.s $f2, $f2, $f4
/* 137090 80243D50 00000000 */  nop   
/* 137094 80243D54 01F41821 */  addu  $v1, $t7, $s4
/* 137098 80243D58 44830000 */  mtc1  $v1, $f0
/* 13709C 80243D5C 00000000 */  nop   
/* 1370A0 80243D60 46800020 */  cvt.s.w $f0, $f0
/* 1370A4 80243D64 24C60008 */  addiu $a2, $a2, 8
/* 1370A8 80243D68 3C03ED00 */  lui   $v1, 0xed00
/* 1370AC 80243D6C 46040002 */  mul.s $f0, $f0, $f4
/* 1370B0 80243D70 00000000 */  nop   
/* 1370B4 80243D74 8FAF0124 */  lw    $t7, 0x124($sp)
/* 1370B8 80243D78 4600118D */  trunc.w.s $f6, $f2
/* 1370BC 80243D7C 44043000 */  mfc1  $a0, $f6
/* 1370C0 80243D80 00000000 */  nop   
/* 1370C4 80243D84 30840FFF */  andi  $a0, $a0, 0xfff
/* 1370C8 80243D88 00042300 */  sll   $a0, $a0, 0xc
