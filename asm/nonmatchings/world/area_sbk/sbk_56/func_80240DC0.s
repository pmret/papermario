.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DC0
/* 954D80 80240DC0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 954D84 80240DC4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 954D88 80240DC8 4485A000 */  mtc1      $a1, $f20
/* 954D8C 80240DCC F7B60020 */  sdc1      $f22, 0x20($sp)
/* 954D90 80240DD0 4486B000 */  mtc1      $a2, $f22
/* 954D94 80240DD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 954D98 80240DD8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 954D9C 80240DDC 4487C000 */  mtc1      $a3, $f24
/* 954DA0 80240DE0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 954DA4 80240DE4 0C019D28 */  jal       guMtxIdentF
/* 954DA8 80240DE8 0080802D */   daddu    $s0, $a0, $zero
/* 954DAC 80240DEC 4616A582 */  mul.s     $f22, $f20, $f22
/* 954DB0 80240DF0 00000000 */  nop       
/* 954DB4 80240DF4 4618A502 */  mul.s     $f20, $f20, $f24
/* 954DB8 80240DF8 00000000 */  nop       
/* 954DBC 80240DFC 3C013F80 */  lui       $at, 0x3f80
/* 954DC0 80240E00 44810000 */  mtc1      $at, $f0
/* 954DC4 80240E04 00000000 */  nop       
/* 954DC8 80240E08 E6000014 */  swc1      $f0, 0x14($s0)
/* 954DCC 80240E0C E6160010 */  swc1      $f22, 0x10($s0)
/* 954DD0 80240E10 E6140018 */  swc1      $f20, 0x18($s0)
/* 954DD4 80240E14 8FBF0014 */  lw        $ra, 0x14($sp)
/* 954DD8 80240E18 8FB00010 */  lw        $s0, 0x10($sp)
/* 954DDC 80240E1C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 954DE0 80240E20 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 954DE4 80240E24 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 954DE8 80240E28 03E00008 */  jr        $ra
/* 954DEC 80240E2C 27BD0030 */   addiu    $sp, $sp, 0x30
