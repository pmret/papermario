.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80127BA4
/* 0BE2A4 80127BA4 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0BE2A8 80127BA8 0080402D */  daddu $t0, $a0, $zero
/* 0BE2AC 80127BAC 2402000D */  addiu $v0, $zero, 0xd
/* 0BE2B0 80127BB0 AFBF0050 */  sw    $ra, 0x50($sp)
/* 0BE2B4 80127BB4 910304F8 */  lbu   $v1, 0x4f8($t0)
/* 0BE2B8 80127BB8 3C013F80 */  lui   $at, 0x3f80
/* 0BE2BC 80127BBC 44810000 */  mtc1  $at, $f0
/* 0BE2C0 80127BC0 10620006 */  beq   $v1, $v0, .L80127BDC
/* 0BE2C4 80127BC4 0000482D */   daddu $t1, $zero, $zero
/* 0BE2C8 80127BC8 2402000E */  addiu $v0, $zero, 0xe
/* 0BE2CC 80127BCC 1062001D */  beq   $v1, $v0, .L80127C44
/* 0BE2D0 80127BD0 2862000F */   slti  $v0, $v1, 0xf
/* 0BE2D4 80127BD4 08049F2B */  j     .L80127CAC
/* 0BE2D8 80127BD8 00000000 */   nop   

.L80127BDC:
/* 0BE2DC 80127BDC 24050004 */  addiu $a1, $zero, 4
/* 0BE2E0 80127BE0 91030509 */  lbu   $v1, 0x509($t0)
/* 0BE2E4 80127BE4 3C014059 */  lui   $at, 0x4059
/* 0BE2E8 80127BE8 44811800 */  mtc1  $at, $f3
/* 0BE2EC 80127BEC 44801000 */  mtc1  $zero, $f2
/* 0BE2F0 80127BF0 00A32023 */  subu  $a0, $a1, $v1
/* 0BE2F4 80127BF4 00041040 */  sll   $v0, $a0, 1
/* 0BE2F8 80127BF8 00444821 */  addu  $t1, $v0, $a0
/* 0BE2FC 80127BFC 3C028015 */  lui   $v0, 0x8015
/* 0BE300 80127C00 00431021 */  addu  $v0, $v0, $v1
/* 0BE304 80127C04 9042C580 */  lbu   $v0, -0x3a80($v0)
/* 0BE308 80127C08 24630001 */  addiu $v1, $v1, 1
/* 0BE30C 80127C0C A1030509 */  sb    $v1, 0x509($t0)
/* 0BE310 80127C10 44820000 */  mtc1  $v0, $f0
/* 0BE314 80127C14 00000000 */  nop   
/* 0BE318 80127C18 46800020 */  cvt.s.w $f0, $f0
/* 0BE31C 80127C1C 46000021 */  cvt.d.s $f0, $f0
/* 0BE320 80127C20 306200FF */  andi  $v0, $v1, 0xff
/* 0BE324 80127C24 46220003 */  div.d $f0, $f0, $f2
/* 0BE328 80127C28 3C018015 */  lui   $at, 0x8015
/* 0BE32C 80127C2C 00220821 */  addu  $at, $at, $v0
/* 0BE330 80127C30 9022C580 */  lbu   $v0, -0x3a80($at)
/* 0BE334 80127C34 1440001B */  bnez  $v0, .L80127CA4
/* 0BE338 80127C38 46200020 */   cvt.s.d $f0, $f0
/* 0BE33C 80127C3C 08049F29 */  j     .L80127CA4
/* 0BE340 80127C40 A10504F8 */   sb    $a1, 0x4f8($t0)

.L80127C44:
/* 0BE344 80127C44 91020512 */  lbu   $v0, 0x512($t0)
/* 0BE348 80127C48 3C014059 */  lui   $at, 0x4059
/* 0BE34C 80127C4C 44811800 */  mtc1  $at, $f3
/* 0BE350 80127C50 44801000 */  mtc1  $zero, $f2
/* 0BE354 80127C54 00024823 */  negu  $t1, $v0
/* 0BE358 80127C58 3C038015 */  lui   $v1, 0x8015
/* 0BE35C 80127C5C 00621821 */  addu  $v1, $v1, $v0
/* 0BE360 80127C60 9063C588 */  lbu   $v1, -0x3a78($v1)
/* 0BE364 80127C64 24420001 */  addiu $v0, $v0, 1
/* 0BE368 80127C68 A1020512 */  sb    $v0, 0x512($t0)
/* 0BE36C 80127C6C 304200FF */  andi  $v0, $v0, 0xff
/* 0BE370 80127C70 3C018015 */  lui   $at, 0x8015
/* 0BE374 80127C74 00220821 */  addu  $at, $at, $v0
/* 0BE378 80127C78 9022C588 */  lbu   $v0, -0x3a78($at)
/* 0BE37C 80127C7C 44830000 */  mtc1  $v1, $f0
/* 0BE380 80127C80 00000000 */  nop   
/* 0BE384 80127C84 46800020 */  cvt.s.w $f0, $f0
/* 0BE388 80127C88 46000021 */  cvt.d.s $f0, $f0
/* 0BE38C 80127C8C 46220003 */  div.d $f0, $f0, $f2
/* 0BE390 80127C90 14400004 */  bnez  $v0, .L80127CA4
/* 0BE394 80127C94 46200020 */   cvt.s.d $f0, $f0
/* 0BE398 80127C98 8D0204FC */  lw    $v0, 0x4fc($t0)
/* 0BE39C 80127C9C 34420001 */  ori   $v0, $v0, 1
/* 0BE3A0 80127CA0 AD0204FC */  sw    $v0, 0x4fc($t0)
.L80127CA4:
/* 0BE3A4 80127CA4 910304F8 */  lbu   $v1, 0x4f8($t0)
/* 0BE3A8 80127CA8 2862000F */  slti  $v0, $v1, 0xf
.L80127CAC:
/* 0BE3AC 80127CAC 1040002B */  beqz  $v0, .L80127D5C
/* 0BE3B0 80127CB0 2862000D */   slti  $v0, $v1, 0xd
/* 0BE3B4 80127CB4 1440002A */  bnez  $v0, .L80127D60
/* 0BE3B8 80127CB8 0100202D */   daddu $a0, $t0, $zero
/* 0BE3BC 80127CBC 24040001 */  addiu $a0, $zero, 1
/* 0BE3C0 80127CC0 24070038 */  addiu $a3, $zero, 0x38
/* 0BE3C4 80127CC4 95030514 */  lhu   $v1, 0x514($t0)
/* 0BE3C8 80127CC8 240200A0 */  addiu $v0, $zero, 0xa0
/* 0BE3CC 80127CCC 00831806 */  srlv  $v1, $v1, $a0
/* 0BE3D0 80127CD0 00431023 */  subu  $v0, $v0, $v1
/* 0BE3D4 80127CD4 A502045A */  sh    $v0, 0x45a($t0)
/* 0BE3D8 80127CD8 8506045A */  lh    $a2, 0x45a($t0)
/* 0BE3DC 80127CDC 00E0102D */  daddu $v0, $a3, $zero
/* 0BE3E0 80127CE0 A502045C */  sh    $v0, 0x45c($t0)
/* 0BE3E4 80127CE4 AFA00010 */  sw    $zero, 0x10($sp)
/* 0BE3E8 80127CE8 95020514 */  lhu   $v0, 0x514($t0)
/* 0BE3EC 80127CEC 0000282D */  daddu $a1, $zero, $zero
/* 0BE3F0 80127CF0 AFA20014 */  sw    $v0, 0x14($sp)
/* 0BE3F4 80127CF4 95030516 */  lhu   $v1, 0x516($t0)
/* 0BE3F8 80127CF8 240200FF */  addiu $v0, $zero, 0xff
/* 0BE3FC 80127CFC E7A00024 */  swc1  $f0, 0x24($sp)
/* 0BE400 80127D00 E7A00028 */  swc1  $f0, 0x28($sp)
/* 0BE404 80127D04 44890000 */  mtc1  $t1, $f0
/* 0BE408 80127D08 00000000 */  nop   
/* 0BE40C 80127D0C 46800020 */  cvt.s.w $f0, $f0
/* 0BE410 80127D10 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0BE414 80127D14 3C028012 */  lui   $v0, 0x8012
/* 0BE418 80127D18 24427B70 */  addiu $v0, $v0, 0x7b70
/* 0BE41C 80127D1C AFA20038 */  sw    $v0, 0x38($sp)
/* 0BE420 80127D20 24020140 */  addiu $v0, $zero, 0x140
/* 0BE424 80127D24 AFA20044 */  sw    $v0, 0x44($sp)
/* 0BE428 80127D28 240200F0 */  addiu $v0, $zero, 0xf0
/* 0BE42C 80127D2C AFA00020 */  sw    $zero, 0x20($sp)
/* 0BE430 80127D30 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0BE434 80127D34 AFA00030 */  sw    $zero, 0x30($sp)
/* 0BE438 80127D38 E7A00034 */  swc1  $f0, 0x34($sp)
/* 0BE43C 80127D3C AFA8003C */  sw    $t0, 0x3c($sp)
/* 0BE440 80127D40 AFA00040 */  sw    $zero, 0x40($sp)
/* 0BE444 80127D44 AFA20048 */  sw    $v0, 0x48($sp)
/* 0BE448 80127D48 AFA0004C */  sw    $zero, 0x4c($sp)
/* 0BE44C 80127D4C 0C03D4B8 */  jal   draw_box
/* 0BE450 80127D50 AFA30018 */   sw    $v1, 0x18($sp)
/* 0BE454 80127D54 08049F61 */  j     .L80127D84
/* 0BE458 80127D58 00000000 */   nop   

.L80127D5C:
/* 0BE45C 80127D5C 0100202D */  daddu $a0, $t0, $zero
.L80127D60:
/* 0BE460 80127D60 84850456 */  lh    $a1, 0x456($a0)
/* 0BE464 80127D64 84860458 */  lh    $a2, 0x458($a0)
/* 0BE468 80127D68 9487046E */  lhu   $a3, 0x46e($a0)
/* 0BE46C 80127D6C 94830462 */  lhu   $v1, 0x462($a0)
/* 0BE470 80127D70 24020004 */  addiu $v0, $zero, 4
/* 0BE474 80127D74 AFA20014 */  sw    $v0, 0x14($sp)
/* 0BE478 80127D78 AFA00018 */  sw    $zero, 0x18($sp)
/* 0BE47C 80127D7C 0C049F64 */  jal   func_80127D90
/* 0BE480 80127D80 AFA30010 */   sw    $v1, 0x10($sp)
.L80127D84:
/* 0BE484 80127D84 8FBF0050 */  lw    $ra, 0x50($sp)
/* 0BE488 80127D88 03E00008 */  jr    $ra
/* 0BE48C 80127D8C 27BD0058 */   addiu $sp, $sp, 0x58

