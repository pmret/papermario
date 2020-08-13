.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel OnFleeBattleDrops
/* 01AAE8 8003F6E8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 01AAEC 8003F6EC AFB00020 */  sw    $s0, 0x20($sp)
/* 01AAF0 8003F6F0 0080802D */  daddu $s0, $a0, $zero
/* 01AAF4 8003F6F4 AFB10024 */  sw    $s1, 0x24($sp)
/* 01AAF8 8003F6F8 3C118011 */  lui   $s1, 0x8011
/* 01AAFC 8003F6FC 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 01AB00 8003F700 AFB20028 */  sw    $s2, 0x28($sp)
/* 01AB04 8003F704 3C128011 */  lui   $s2, 0x8011
/* 01AB08 8003F708 2652F290 */  addiu $s2, $s2, -0xd70
/* 01AB0C 8003F70C 10A00005 */  beqz  $a1, .L8003F724
/* 01AB10 8003F710 AFBF002C */   sw    $ra, 0x2c($sp)
/* 01AB14 8003F714 24020028 */  addiu $v0, $zero, 0x28
/* 01AB18 8003F718 AE000070 */  sw    $zero, 0x70($s0)
/* 01AB1C 8003F71C AE020074 */  sw    $v0, 0x74($s0)
/* 01AB20 8003F720 AE000078 */  sw    $zero, 0x78($s0)
.L8003F724:
/* 01AB24 8003F724 8E020078 */  lw    $v0, 0x78($s0)
/* 01AB28 8003F728 24420001 */  addiu $v0, $v0, 1
/* 01AB2C 8003F72C AE020078 */  sw    $v0, 0x78($s0)
/* 01AB30 8003F730 28420005 */  slti  $v0, $v0, 5
/* 01AB34 8003F734 1440001B */  bnez  $v0, .L8003F7A4
/* 01AB38 8003F738 00000000 */   nop   
/* 01AB3C 8003F73C 0C00A67F */  jal   rand_int
/* 01AB40 8003F740 24040064 */   addiu $a0, $zero, 0x64
/* 01AB44 8003F744 28420032 */  slti  $v0, $v0, 0x32
/* 01AB48 8003F748 50400016 */  beql  $v0, $zero, .L8003F7A4
/* 01AB4C 8003F74C AE000078 */   sw    $zero, 0x78($s0)
/* 01AB50 8003F750 8642000C */  lh    $v0, 0xc($s2)
/* 01AB54 8003F754 9643000C */  lhu   $v1, 0xc($s2)
/* 01AB58 8003F758 10400011 */  beqz  $v0, .L8003F7A0
/* 01AB5C 8003F75C 2462FFFF */   addiu $v0, $v1, -1
/* 01AB60 8003F760 A642000C */  sh    $v0, 0xc($s2)
/* 01AB64 8003F764 862300B0 */  lh    $v1, 0xb0($s1)
/* 01AB68 8003F768 24020003 */  addiu $v0, $zero, 3
/* 01AB6C 8003F76C AFA20010 */  sw    $v0, 0x10($sp)
/* 01AB70 8003F770 C620002C */  lwc1  $f0, 0x2c($s1)
/* 01AB74 8003F774 44831000 */  mtc1  $v1, $f2
/* 01AB78 8003F778 00000000 */  nop   
/* 01AB7C 8003F77C 468010A0 */  cvt.s.w $f2, $f2
/* 01AB80 8003F780 46020000 */  add.s $f0, $f0, $f2
/* 01AB84 8003F784 8E250028 */  lw    $a1, 0x28($s1)
/* 01AB88 8003F788 8E270030 */  lw    $a3, 0x30($s1)
/* 01AB8C 8003F78C 44060000 */  mfc1  $a2, $f0
/* 01AB90 8003F790 24040157 */  addiu $a0, $zero, 0x157
/* 01AB94 8003F794 AFA00014 */  sw    $zero, 0x14($sp)
/* 01AB98 8003F798 0C04C6B2 */  jal   make_item_entity_delayed
/* 01AB9C 8003F79C AFA00018 */   sw    $zero, 0x18($sp)
.L8003F7A0:
/* 01ABA0 8003F7A0 AE000078 */  sw    $zero, 0x78($s0)
.L8003F7A4:
/* 01ABA4 8003F7A4 8E030074 */  lw    $v1, 0x74($s0)
/* 01ABA8 8003F7A8 2463FFFF */  addiu $v1, $v1, -1
/* 01ABAC 8003F7AC AE030074 */  sw    $v1, 0x74($s0)
/* 01ABB0 8003F7B0 8FBF002C */  lw    $ra, 0x2c($sp)
/* 01ABB4 8003F7B4 8FB20028 */  lw    $s2, 0x28($sp)
/* 01ABB8 8003F7B8 8FB10024 */  lw    $s1, 0x24($sp)
/* 01ABBC 8003F7BC 8FB00020 */  lw    $s0, 0x20($sp)
/* 01ABC0 8003F7C0 2C620001 */  sltiu $v0, $v1, 1
/* 01ABC4 8003F7C4 03E00008 */  jr    $ra
/* 01ABC8 8003F7C8 27BD0030 */   addiu $sp, $sp, 0x30

