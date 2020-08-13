.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80147F30
/* 0DE630 80147F30 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0DE634 80147F34 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0DE638 80147F38 0080882D */  daddu $s1, $a0, $zero
/* 0DE63C 80147F3C AFB30034 */  sw    $s3, 0x34($sp)
/* 0DE640 80147F40 00A0982D */  daddu $s3, $a1, $zero
/* 0DE644 80147F44 AFB20030 */  sw    $s2, 0x30($sp)
/* 0DE648 80147F48 0000902D */  daddu $s2, $zero, $zero
/* 0DE64C 80147F4C AFBF0044 */  sw    $ra, 0x44($sp)
/* 0DE650 80147F50 AFB60040 */  sw    $s6, 0x40($sp)
/* 0DE654 80147F54 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0DE658 80147F58 AFB40038 */  sw    $s4, 0x38($sp)
/* 0DE65C 80147F5C 1A60002C */  blez  $s3, .L80148010
/* 0DE660 80147F60 AFB00028 */   sw    $s0, 0x28($sp)
/* 0DE664 80147F64 2416FFFF */  addiu $s6, $zero, -1
/* 0DE668 80147F68 3C158015 */  lui   $s5, 0x8015
/* 0DE66C 80147F6C 26B5F150 */  addiu $s5, $s5, -0xeb0
/* 0DE670 80147F70 3C148016 */  lui   $s4, 0x8016
/* 0DE674 80147F74 26949D50 */  addiu $s4, $s4, -0x62b0
/* 0DE678 80147F78 2490001C */  addiu $s0, $a0, 0x1c
.L80147F7C:
/* 0DE67C 80147F7C 8602FFEC */  lh    $v0, -0x14($s0)
/* 0DE680 80147F80 82240000 */  lb    $a0, ($s1)
/* 0DE684 80147F84 8605FFE6 */  lh    $a1, -0x1a($s0)
/* 0DE688 80147F88 8606FFE8 */  lh    $a2, -0x18($s0)
/* 0DE68C 80147F8C 8607FFEA */  lh    $a3, -0x16($s0)
/* 0DE690 80147F90 AFA20010 */  sw    $v0, 0x10($sp)
/* 0DE694 80147F94 9202FFEE */  lbu   $v0, -0x12($s0)
/* 0DE698 80147F98 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DE69C 80147F9C 8E02FFF0 */  lw    $v0, -0x10($s0)
/* 0DE6A0 80147FA0 AFA20018 */  sw    $v0, 0x18($sp)
/* 0DE6A4 80147FA4 8E02FFF4 */  lw    $v0, -0xc($s0)
/* 0DE6A8 80147FA8 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0DE6AC 80147FAC 8202FFF8 */  lb    $v0, -8($s0)
/* 0DE6B0 80147FB0 0C051F32 */  jal   func_80147CC8
/* 0DE6B4 80147FB4 AFA20020 */   sw    $v0, 0x20($sp)
/* 0DE6B8 80147FB8 8E030004 */  lw    $v1, 4($s0)
/* 0DE6BC 80147FBC 10760005 */  beq   $v1, $s6, .L80147FD4
/* 0DE6C0 80147FC0 00000000 */   nop   
/* 0DE6C4 80147FC4 82220000 */  lb    $v0, ($s1)
/* 0DE6C8 80147FC8 00021080 */  sll   $v0, $v0, 2
/* 0DE6CC 80147FCC 00551021 */  addu  $v0, $v0, $s5
/* 0DE6D0 80147FD0 AC430000 */  sw    $v1, ($v0)
.L80147FD4:
/* 0DE6D4 80147FD4 82240000 */  lb    $a0, ($s1)
/* 0DE6D8 80147FD8 8E05FFFC */  lw    $a1, -4($s0)
/* 0DE6DC 80147FDC 0C051F9F */  jal   func_80147E7C
/* 0DE6E0 80147FE0 26520001 */   addiu $s2, $s2, 1
/* 0DE6E4 80147FE4 82230000 */  lb    $v1, ($s1)
/* 0DE6E8 80147FE8 92040000 */  lbu   $a0, ($s0)
/* 0DE6EC 80147FEC 26100024 */  addiu $s0, $s0, 0x24
/* 0DE6F0 80147FF0 00031940 */  sll   $v1, $v1, 5
/* 0DE6F4 80147FF4 00741821 */  addu  $v1, $v1, $s4
/* 0DE6F8 80147FF8 90620000 */  lbu   $v0, ($v1)
/* 0DE6FC 80147FFC 00441025 */  or    $v0, $v0, $a0
/* 0DE700 80148000 A0620000 */  sb    $v0, ($v1)
/* 0DE704 80148004 0253102A */  slt   $v0, $s2, $s3
/* 0DE708 80148008 1440FFDC */  bnez  $v0, .L80147F7C
/* 0DE70C 8014800C 26310024 */   addiu $s1, $s1, 0x24
.L80148010:
/* 0DE710 80148010 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0DE714 80148014 8FB60040 */  lw    $s6, 0x40($sp)
/* 0DE718 80148018 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0DE71C 8014801C 8FB40038 */  lw    $s4, 0x38($sp)
/* 0DE720 80148020 8FB30034 */  lw    $s3, 0x34($sp)
/* 0DE724 80148024 8FB20030 */  lw    $s2, 0x30($sp)
/* 0DE728 80148028 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0DE72C 8014802C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0DE730 80148030 03E00008 */  jr    $ra
/* 0DE734 80148034 27BD0048 */   addiu $sp, $sp, 0x48

/* 0DE738 80148038 00000000 */  nop   
/* 0DE73C 8014803C 00000000 */  nop   


