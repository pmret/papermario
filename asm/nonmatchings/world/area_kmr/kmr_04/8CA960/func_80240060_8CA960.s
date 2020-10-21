.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240060_8CA960
/* 8CA960 80240060 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8CA964 80240064 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8CA968 80240068 4485A000 */  mtc1      $a1, $f20
/* 8CA96C 8024006C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8CA970 80240070 4486B000 */  mtc1      $a2, $f22
/* 8CA974 80240074 AFB00010 */  sw        $s0, 0x10($sp)
/* 8CA978 80240078 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8CA97C 8024007C 4487C000 */  mtc1      $a3, $f24
/* 8CA980 80240080 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8CA984 80240084 0C019D28 */  jal       guMtxIdentF
/* 8CA988 80240088 0080802D */   daddu    $s0, $a0, $zero
/* 8CA98C 8024008C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8CA990 80240090 00000000 */  nop       
/* 8CA994 80240094 4618A502 */  mul.s     $f20, $f20, $f24
/* 8CA998 80240098 00000000 */  nop       
/* 8CA99C 8024009C 3C013F80 */  lui       $at, 0x3f80
/* 8CA9A0 802400A0 44810000 */  mtc1      $at, $f0
/* 8CA9A4 802400A4 00000000 */  nop       
/* 8CA9A8 802400A8 E6000014 */  swc1      $f0, 0x14($s0)
/* 8CA9AC 802400AC E6160010 */  swc1      $f22, 0x10($s0)
/* 8CA9B0 802400B0 E6140018 */  swc1      $f20, 0x18($s0)
/* 8CA9B4 802400B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8CA9B8 802400B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CA9BC 802400BC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8CA9C0 802400C0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8CA9C4 802400C4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8CA9C8 802400C8 03E00008 */  jr        $ra
/* 8CA9CC 802400CC 27BD0030 */   addiu    $sp, $sp, 0x30
