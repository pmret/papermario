.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240140_93AD70
/* 93AD70 80240140 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 93AD74 80240144 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 93AD78 80240148 4485A000 */  mtc1      $a1, $f20
/* 93AD7C 8024014C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 93AD80 80240150 4486B000 */  mtc1      $a2, $f22
/* 93AD84 80240154 AFB00010 */  sw        $s0, 0x10($sp)
/* 93AD88 80240158 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 93AD8C 8024015C 4487C000 */  mtc1      $a3, $f24
/* 93AD90 80240160 AFBF0014 */  sw        $ra, 0x14($sp)
/* 93AD94 80240164 0C019D28 */  jal       guMtxIdentF
/* 93AD98 80240168 0080802D */   daddu    $s0, $a0, $zero
/* 93AD9C 8024016C 4616A582 */  mul.s     $f22, $f20, $f22
/* 93ADA0 80240170 00000000 */  nop       
/* 93ADA4 80240174 4618A502 */  mul.s     $f20, $f20, $f24
/* 93ADA8 80240178 00000000 */  nop       
/* 93ADAC 8024017C 3C013F80 */  lui       $at, 0x3f80
/* 93ADB0 80240180 44810000 */  mtc1      $at, $f0
/* 93ADB4 80240184 00000000 */  nop       
/* 93ADB8 80240188 E6000014 */  swc1      $f0, 0x14($s0)
/* 93ADBC 8024018C E6160010 */  swc1      $f22, 0x10($s0)
/* 93ADC0 80240190 E6140018 */  swc1      $f20, 0x18($s0)
/* 93ADC4 80240194 8FBF0014 */  lw        $ra, 0x14($sp)
/* 93ADC8 80240198 8FB00010 */  lw        $s0, 0x10($sp)
/* 93ADCC 8024019C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 93ADD0 802401A0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 93ADD4 802401A4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 93ADD8 802401A8 03E00008 */  jr        $ra
/* 93ADDC 802401AC 27BD0030 */   addiu    $sp, $sp, 0x30
