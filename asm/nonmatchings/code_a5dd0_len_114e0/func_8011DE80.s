.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8011DE80
/* 0B4580 8011DE80 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0B4584 8011DE84 AFB40020 */  sw    $s4, 0x20($sp)
/* 0B4588 8011DE88 0080A02D */  daddu $s4, $a0, $zero
/* 0B458C 8011DE8C AFB3001C */  sw    $s3, 0x1c($sp)
/* 0B4590 8011DE90 00A0982D */  daddu $s3, $a1, $zero
/* 0B4594 8011DE94 AFB00010 */  sw    $s0, 0x10($sp)
/* 0B4598 8011DE98 00C0802D */  daddu $s0, $a2, $zero
/* 0B459C 8011DE9C AFB20018 */  sw    $s2, 0x18($sp)
/* 0B45A0 8011DEA0 00E0902D */  daddu $s2, $a3, $zero
/* 0B45A4 8011DEA4 0000282D */  daddu $a1, $zero, $zero
/* 0B45A8 8011DEA8 3C038015 */  lui   $v1, 0x8015
/* 0B45AC 8011DEAC 246333C0 */  addiu $v1, $v1, 0x33c0
/* 0B45B0 8011DEB0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0B45B4 8011DEB4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0B45B8 8011DEB8 000510C0 */  sll   $v0, $a1, 3
.L8011DEBC:
/* 0B45BC 8011DEBC 00438821 */  addu  $s1, $v0, $v1
/* 0B45C0 8011DEC0 8E220000 */  lw    $v0, ($s1)
/* 0B45C4 8011DEC4 04400006 */  bltz  $v0, .L8011DEE0
/* 0B45C8 8011DEC8 28A20060 */   slti  $v0, $a1, 0x60
/* 0B45CC 8011DECC 24A50001 */  addiu $a1, $a1, 1
/* 0B45D0 8011DED0 28A20060 */  slti  $v0, $a1, 0x60
/* 0B45D4 8011DED4 1440FFF9 */  bnez  $v0, .L8011DEBC
/* 0B45D8 8011DED8 000510C0 */   sll   $v0, $a1, 3
/* 0B45DC 8011DEDC 28A20060 */  slti  $v0, $a1, 0x60
.L8011DEE0:
/* 0B45E0 8011DEE0 14400003 */  bnez  $v0, .L8011DEF0
/* 0B45E4 8011DEE4 00000000 */   nop   
.L8011DEE8:
/* 0B45E8 8011DEE8 080477BA */  j     .L8011DEE8
/* 0B45EC 8011DEEC 00000000 */   nop   

.L8011DEF0:
/* 0B45F0 8011DEF0 8FA40038 */  lw    $a0, 0x38($sp)
/* 0B45F4 8011DEF4 02442021 */  addu  $a0, $s2, $a0
/* 0B45F8 8011DEF8 0C00AB0A */  jal   general_heap_malloc
/* 0B45FC 8011DEFC 00042100 */   sll   $a0, $a0, 4
/* 0B4600 8011DF00 0040382D */  daddu $a3, $v0, $zero
/* 0B4604 8011DF04 14E00003 */  bnez  $a3, .L8011DF14
/* 0B4608 8011DF08 AE270004 */   sw    $a3, 4($s1)
.L8011DF0C:
/* 0B460C 8011DF0C 080477C3 */  j     .L8011DF0C
/* 0B4610 8011DF10 00000000 */   nop   

.L8011DF14:
/* 0B4614 8011DF14 24020003 */  addiu $v0, $zero, 3
/* 0B4618 8011DF18 AE220000 */  sw    $v0, ($s1)
/* 0B461C 8011DF1C 8FA2003C */  lw    $v0, 0x3c($sp)
/* 0B4620 8011DF20 8E6300FC */  lw    $v1, 0xfc($s3)
/* 0B4624 8011DF24 8E8400D8 */  lw    $a0, 0xd8($s4)
/* 0B4628 8011DF28 00021100 */  sll   $v0, $v0, 4
/* 0B462C 8011DF2C 10800005 */  beqz  $a0, .L8011DF44
/* 0B4630 8011DF30 00621821 */   addu  $v1, $v1, $v0
/* 0B4634 8011DF34 3C0200FF */  lui   $v0, 0xff
/* 0B4638 8011DF38 3442FFFF */  ori   $v0, $v0, 0xffff
/* 0B463C 8011DF3C 02022824 */  and   $a1, $s0, $v0
/* 0B4640 8011DF40 00A48021 */  addu  $s0, $a1, $a0
.L8011DF44:
/* 0B4644 8011DF44 1A400019 */  blez  $s2, .L8011DFAC
/* 0B4648 8011DF48 0000282D */   daddu $a1, $zero, $zero
/* 0B464C 8011DF4C 26060004 */  addiu $a2, $s0, 4
/* 0B4650 8011DF50 24E40004 */  addiu $a0, $a3, 4
.L8011DF54:
/* 0B4654 8011DF54 8C680000 */  lw    $t0, ($v1)
/* 0B4658 8011DF58 8C690004 */  lw    $t1, 4($v1)
/* 0B465C 8011DF5C 8C6A0008 */  lw    $t2, 8($v1)
/* 0B4660 8011DF60 8C6B000C */  lw    $t3, 0xc($v1)
/* 0B4664 8011DF64 ACE80000 */  sw    $t0, ($a3)
/* 0B4668 8011DF68 ACE90004 */  sw    $t1, 4($a3)
/* 0B466C 8011DF6C ACEA0008 */  sw    $t2, 8($a3)
/* 0B4670 8011DF70 ACEB000C */  sw    $t3, 0xc($a3)
/* 0B4674 8011DF74 96020000 */  lhu   $v0, ($s0)
/* 0B4678 8011DF78 26100006 */  addiu $s0, $s0, 6
/* 0B467C 8011DF7C 24630010 */  addiu $v1, $v1, 0x10
/* 0B4680 8011DF80 24A50001 */  addiu $a1, $a1, 1
/* 0B4684 8011DF84 A4E20000 */  sh    $v0, ($a3)
/* 0B4688 8011DF88 94C2FFFE */  lhu   $v0, -2($a2)
/* 0B468C 8011DF8C 24E70010 */  addiu $a3, $a3, 0x10
/* 0B4690 8011DF90 A482FFFE */  sh    $v0, -2($a0)
/* 0B4694 8011DF94 94C20000 */  lhu   $v0, ($a2)
/* 0B4698 8011DF98 24C60006 */  addiu $a2, $a2, 6
/* 0B469C 8011DF9C A4820000 */  sh    $v0, ($a0)
/* 0B46A0 8011DFA0 00B2102A */  slt   $v0, $a1, $s2
/* 0B46A4 8011DFA4 1440FFEB */  bnez  $v0, .L8011DF54
/* 0B46A8 8011DFA8 24840010 */   addiu $a0, $a0, 0x10
.L8011DFAC:
/* 0B46AC 8011DFAC 8E220004 */  lw    $v0, 4($s1)
/* 0B46B0 8011DFB0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0B46B4 8011DFB4 8FB40020 */  lw    $s4, 0x20($sp)
/* 0B46B8 8011DFB8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0B46BC 8011DFBC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0B46C0 8011DFC0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B46C4 8011DFC4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B46C8 8011DFC8 03E00008 */  jr    $ra
/* 0B46CC 8011DFCC 27BD0028 */   addiu $sp, $sp, 0x28

