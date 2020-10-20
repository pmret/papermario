.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240160_93DE30
/* 93DE30 80240160 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 93DE34 80240164 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 93DE38 80240168 4485A000 */  mtc1      $a1, $f20
/* 93DE3C 8024016C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 93DE40 80240170 4486B000 */  mtc1      $a2, $f22
/* 93DE44 80240174 AFB00010 */  sw        $s0, 0x10($sp)
/* 93DE48 80240178 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 93DE4C 8024017C 4487C000 */  mtc1      $a3, $f24
/* 93DE50 80240180 AFBF0014 */  sw        $ra, 0x14($sp)
/* 93DE54 80240184 0C019D28 */  jal       guMtxIdentF
/* 93DE58 80240188 0080802D */   daddu    $s0, $a0, $zero
/* 93DE5C 8024018C 4616A582 */  mul.s     $f22, $f20, $f22
/* 93DE60 80240190 00000000 */  nop       
/* 93DE64 80240194 4618A502 */  mul.s     $f20, $f20, $f24
/* 93DE68 80240198 00000000 */  nop       
/* 93DE6C 8024019C 3C013F80 */  lui       $at, 0x3f80
/* 93DE70 802401A0 44810000 */  mtc1      $at, $f0
/* 93DE74 802401A4 00000000 */  nop       
/* 93DE78 802401A8 E6000014 */  swc1      $f0, 0x14($s0)
/* 93DE7C 802401AC E6160010 */  swc1      $f22, 0x10($s0)
/* 93DE80 802401B0 E6140018 */  swc1      $f20, 0x18($s0)
/* 93DE84 802401B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 93DE88 802401B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 93DE8C 802401BC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 93DE90 802401C0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 93DE94 802401C4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 93DE98 802401C8 03E00008 */  jr        $ra
/* 93DE9C 802401CC 27BD0030 */   addiu    $sp, $sp, 0x30
