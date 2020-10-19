.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241060_8ECE80
/* 8ECE80 80241060 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8ECE84 80241064 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8ECE88 80241068 4485A000 */  mtc1      $a1, $f20
/* 8ECE8C 8024106C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8ECE90 80241070 4486B000 */  mtc1      $a2, $f22
/* 8ECE94 80241074 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ECE98 80241078 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8ECE9C 8024107C 4487C000 */  mtc1      $a3, $f24
/* 8ECEA0 80241080 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8ECEA4 80241084 0C019D28 */  jal       guMtxIdentF
/* 8ECEA8 80241088 0080802D */   daddu    $s0, $a0, $zero
/* 8ECEAC 8024108C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8ECEB0 80241090 00000000 */  nop       
/* 8ECEB4 80241094 4618A502 */  mul.s     $f20, $f20, $f24
/* 8ECEB8 80241098 00000000 */  nop       
/* 8ECEBC 8024109C 3C013F80 */  lui       $at, 0x3f80
/* 8ECEC0 802410A0 44810000 */  mtc1      $at, $f0
/* 8ECEC4 802410A4 00000000 */  nop       
/* 8ECEC8 802410A8 E6000014 */  swc1      $f0, 0x14($s0)
/* 8ECECC 802410AC E6160010 */  swc1      $f22, 0x10($s0)
/* 8ECED0 802410B0 E6140018 */  swc1      $f20, 0x18($s0)
/* 8ECED4 802410B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8ECED8 802410B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ECEDC 802410BC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8ECEE0 802410C0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8ECEE4 802410C4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8ECEE8 802410C8 03E00008 */  jr        $ra
/* 8ECEEC 802410CC 27BD0030 */   addiu    $sp, $sp, 0x30
