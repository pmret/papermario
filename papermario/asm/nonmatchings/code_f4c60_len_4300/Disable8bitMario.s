.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel Disable8bitMario
/* 0F7538 802D2B88 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F753C 802D2B8C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F7540 802D2B90 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F7544 802D2B94 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7548 802D2B98 8C82000C */  lw    $v0, 0xc($a0)
/* 0F754C 802D2B9C 3C108011 */  lui   $s0, 0x8011
/* 0F7550 802D2BA0 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 0F7554 802D2BA4 8C450000 */  lw    $a1, ($v0)
/* 0F7558 802D2BA8 0C0B1EAF */  jal   get_variable
/* 0F755C 802D2BAC 0200882D */   daddu $s1, $s0, $zero
/* 0F7560 802D2BB0 10400009 */  beqz  $v0, .L802D2BD8
/* 0F7564 802D2BB4 24020025 */   addiu $v0, $zero, 0x25
/* 0F7568 802D2BB8 A60200B0 */  sh    $v0, 0xb0($s0)
/* 0F756C 802D2BBC 2402001A */  addiu $v0, $zero, 0x1a
/* 0F7570 802D2BC0 A60200B2 */  sh    $v0, 0xb2($s0)
/* 0F7574 802D2BC4 8E020004 */  lw    $v0, 4($s0)
/* 0F7578 802D2BC8 2403BFFF */  addiu $v1, $zero, -0x4001
/* 0F757C 802D2BCC 00431024 */  and   $v0, $v0, $v1
/* 0F7580 802D2BD0 080B4AFF */  j     .L802D2BFC
/* 0F7584 802D2BD4 AE020004 */   sw    $v0, 4($s0)

.L802D2BD8:
/* 0F7588 802D2BD8 3C040004 */  lui   $a0, 4
/* 0F758C 802D2BDC 34844004 */  ori   $a0, $a0, 0x4004
/* 0F7590 802D2BE0 24020013 */  addiu $v0, $zero, 0x13
/* 0F7594 802D2BE4 A62200B0 */  sh    $v0, 0xb0($s1)
/* 0F7598 802D2BE8 8E220004 */  lw    $v0, 4($s1)
/* 0F759C 802D2BEC 2403001A */  addiu $v1, $zero, 0x1a
/* 0F75A0 802D2BF0 A62300B2 */  sh    $v1, 0xb2($s1)
/* 0F75A4 802D2BF4 00441025 */  or    $v0, $v0, $a0
/* 0F75A8 802D2BF8 AE220004 */  sw    $v0, 4($s1)
.L802D2BFC:
/* 0F75AC 802D2BFC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F75B0 802D2C00 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F75B4 802D2C04 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F75B8 802D2C08 24020002 */  addiu $v0, $zero, 2
/* 0F75BC 802D2C0C 03E00008 */  jr    $ra
/* 0F75C0 802D2C10 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F75C4 802D2C14 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F75C8 802D2C18 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F75CC 802D2C1C 8C82000C */  lw    $v0, 0xc($a0)
/* 0F75D0 802D2C20 0C0B1EAF */  jal   get_variable
/* 0F75D4 802D2C24 8C450000 */   lw    $a1, ($v0)
/* 0F75D8 802D2C28 0C03BCF5 */  jal   func_800EF3D4
/* 0F75DC 802D2C2C 0040202D */   daddu $a0, $v0, $zero
/* 0F75E0 802D2C30 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F75E4 802D2C34 24020002 */  addiu $v0, $zero, 2
/* 0F75E8 802D2C38 03E00008 */  jr    $ra
/* 0F75EC 802D2C3C 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F75F0 802D2C40 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F75F4 802D2C44 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F75F8 802D2C48 0080902D */  daddu $s2, $a0, $zero
/* 0F75FC 802D2C4C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F7600 802D2C50 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F7604 802D2C54 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7608 802D2C58 8E50000C */  lw    $s0, 0xc($s2)
/* 0F760C 802D2C5C 8E050000 */  lw    $a1, ($s0)
/* 0F7610 802D2C60 0C0B1EAF */  jal   get_variable
/* 0F7614 802D2C64 26100004 */   addiu $s0, $s0, 4
/* 0F7618 802D2C68 44820000 */  mtc1  $v0, $f0
/* 0F761C 802D2C6C 00000000 */  nop   
/* 0F7620 802D2C70 46800020 */  cvt.s.w $f0, $f0
/* 0F7624 802D2C74 3C118011 */  lui   $s1, 0x8011
/* 0F7628 802D2C78 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 0F762C 802D2C7C E620001C */  swc1  $f0, 0x1c($s1)
/* 0F7630 802D2C80 8E050000 */  lw    $a1, ($s0)
/* 0F7634 802D2C84 26100004 */  addiu $s0, $s0, 4
/* 0F7638 802D2C88 0C0B1EAF */  jal   get_variable
/* 0F763C 802D2C8C 0240202D */   daddu $a0, $s2, $zero
/* 0F7640 802D2C90 44820000 */  mtc1  $v0, $f0
/* 0F7644 802D2C94 00000000 */  nop   
/* 0F7648 802D2C98 46800020 */  cvt.s.w $f0, $f0
/* 0F764C 802D2C9C E6200020 */  swc1  $f0, 0x20($s1)
/* 0F7650 802D2CA0 8E050000 */  lw    $a1, ($s0)
/* 0F7654 802D2CA4 0C0B1EAF */  jal   get_variable
/* 0F7658 802D2CA8 0240202D */   daddu $a0, $s2, $zero
/* 0F765C 802D2CAC 44820000 */  mtc1  $v0, $f0
/* 0F7660 802D2CB0 00000000 */  nop   
/* 0F7664 802D2CB4 46800020 */  cvt.s.w $f0, $f0
/* 0F7668 802D2CB8 E6200024 */  swc1  $f0, 0x24($s1)
/* 0F766C 802D2CBC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F7670 802D2CC0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F7674 802D2CC4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F7678 802D2CC8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F767C 802D2CCC 24020002 */  addiu $v0, $zero, 2
/* 0F7680 802D2CD0 03E00008 */  jr    $ra
/* 0F7684 802D2CD4 27BD0020 */   addiu $sp, $sp, 0x20

