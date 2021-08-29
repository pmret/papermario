.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243CD4_855E44
/* 855E44 80243CD4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 855E48 80243CD8 AFB10014 */  sw        $s1, 0x14($sp)
/* 855E4C 80243CDC 0080882D */  daddu     $s1, $a0, $zero
/* 855E50 80243CE0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 855E54 80243CE4 AFB20018 */  sw        $s2, 0x18($sp)
/* 855E58 80243CE8 AFB00010 */  sw        $s0, 0x10($sp)
/* 855E5C 80243CEC F7B60028 */  sdc1      $f22, 0x28($sp)
/* 855E60 80243CF0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 855E64 80243CF4 8E30000C */  lw        $s0, 0xc($s1)
/* 855E68 80243CF8 8E050000 */  lw        $a1, ($s0)
/* 855E6C 80243CFC 0C0B1EAF */  jal       get_variable
/* 855E70 80243D00 26100004 */   addiu    $s0, $s0, 4
/* 855E74 80243D04 8E050000 */  lw        $a1, ($s0)
/* 855E78 80243D08 26100004 */  addiu     $s0, $s0, 4
/* 855E7C 80243D0C 0220202D */  daddu     $a0, $s1, $zero
/* 855E80 80243D10 0C0B210B */  jal       evt_get_float_variable
/* 855E84 80243D14 0040902D */   daddu    $s2, $v0, $zero
/* 855E88 80243D18 8E050000 */  lw        $a1, ($s0)
/* 855E8C 80243D1C 26100004 */  addiu     $s0, $s0, 4
/* 855E90 80243D20 0220202D */  daddu     $a0, $s1, $zero
/* 855E94 80243D24 0C0B210B */  jal       evt_get_float_variable
/* 855E98 80243D28 46000586 */   mov.s    $f22, $f0
/* 855E9C 80243D2C 0220202D */  daddu     $a0, $s1, $zero
/* 855EA0 80243D30 8E050000 */  lw        $a1, ($s0)
/* 855EA4 80243D34 0C0B210B */  jal       evt_get_float_variable
/* 855EA8 80243D38 46000506 */   mov.s    $f20, $f0
/* 855EAC 80243D3C 8E42000C */  lw        $v0, 0xc($s2)
/* 855EB0 80243D40 E4560008 */  swc1      $f22, 8($v0)
/* 855EB4 80243D44 8E42000C */  lw        $v0, 0xc($s2)
/* 855EB8 80243D48 E454000C */  swc1      $f20, 0xc($v0)
/* 855EBC 80243D4C 8E43000C */  lw        $v1, 0xc($s2)
/* 855EC0 80243D50 E4600010 */  swc1      $f0, 0x10($v1)
/* 855EC4 80243D54 8FBF001C */  lw        $ra, 0x1c($sp)
/* 855EC8 80243D58 8FB20018 */  lw        $s2, 0x18($sp)
/* 855ECC 80243D5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 855ED0 80243D60 8FB00010 */  lw        $s0, 0x10($sp)
/* 855ED4 80243D64 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 855ED8 80243D68 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 855EDC 80243D6C 24020002 */  addiu     $v0, $zero, 2
/* 855EE0 80243D70 03E00008 */  jr        $ra
/* 855EE4 80243D74 27BD0030 */   addiu    $sp, $sp, 0x30
