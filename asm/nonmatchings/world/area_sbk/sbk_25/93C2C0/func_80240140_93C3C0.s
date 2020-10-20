.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240140_93C3C0
/* 93C3C0 80240140 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 93C3C4 80240144 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 93C3C8 80240148 4485A000 */  mtc1      $a1, $f20
/* 93C3CC 8024014C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 93C3D0 80240150 4486B000 */  mtc1      $a2, $f22
/* 93C3D4 80240154 AFB00010 */  sw        $s0, 0x10($sp)
/* 93C3D8 80240158 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 93C3DC 8024015C 4487C000 */  mtc1      $a3, $f24
/* 93C3E0 80240160 AFBF0014 */  sw        $ra, 0x14($sp)
/* 93C3E4 80240164 0C019D28 */  jal       guMtxIdentF
/* 93C3E8 80240168 0080802D */   daddu    $s0, $a0, $zero
/* 93C3EC 8024016C 4616A582 */  mul.s     $f22, $f20, $f22
/* 93C3F0 80240170 00000000 */  nop       
/* 93C3F4 80240174 4618A502 */  mul.s     $f20, $f20, $f24
/* 93C3F8 80240178 00000000 */  nop       
/* 93C3FC 8024017C 3C013F80 */  lui       $at, 0x3f80
/* 93C400 80240180 44810000 */  mtc1      $at, $f0
/* 93C404 80240184 00000000 */  nop       
/* 93C408 80240188 E6000014 */  swc1      $f0, 0x14($s0)
/* 93C40C 8024018C E6160010 */  swc1      $f22, 0x10($s0)
/* 93C410 80240190 E6140018 */  swc1      $f20, 0x18($s0)
/* 93C414 80240194 8FBF0014 */  lw        $ra, 0x14($sp)
/* 93C418 80240198 8FB00010 */  lw        $s0, 0x10($sp)
/* 93C41C 8024019C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 93C420 802401A0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 93C424 802401A4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 93C428 802401A8 03E00008 */  jr        $ra
/* 93C42C 802401AC 27BD0030 */   addiu    $sp, $sp, 0x30
