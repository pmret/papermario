.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8DA100
/* 8DA100 80240000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8DA104 80240004 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8DA108 80240008 4485A000 */  mtc1      $a1, $f20
/* 8DA10C 8024000C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8DA110 80240010 4486B000 */  mtc1      $a2, $f22
/* 8DA114 80240014 AFB00010 */  sw        $s0, 0x10($sp)
/* 8DA118 80240018 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8DA11C 8024001C 4487C000 */  mtc1      $a3, $f24
/* 8DA120 80240020 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8DA124 80240024 0C019D28 */  jal       guMtxIdentF
/* 8DA128 80240028 0080802D */   daddu    $s0, $a0, $zero
/* 8DA12C 8024002C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8DA130 80240030 00000000 */  nop       
/* 8DA134 80240034 4618A502 */  mul.s     $f20, $f20, $f24
/* 8DA138 80240038 00000000 */  nop       
/* 8DA13C 8024003C 3C013F80 */  lui       $at, 0x3f80
/* 8DA140 80240040 44810000 */  mtc1      $at, $f0
/* 8DA144 80240044 00000000 */  nop       
/* 8DA148 80240048 E6000014 */  swc1      $f0, 0x14($s0)
/* 8DA14C 8024004C E6160010 */  swc1      $f22, 0x10($s0)
/* 8DA150 80240050 E6140018 */  swc1      $f20, 0x18($s0)
/* 8DA154 80240054 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8DA158 80240058 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DA15C 8024005C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8DA160 80240060 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8DA164 80240064 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8DA168 80240068 03E00008 */  jr        $ra
/* 8DA16C 8024006C 27BD0030 */   addiu    $sp, $sp, 0x30
