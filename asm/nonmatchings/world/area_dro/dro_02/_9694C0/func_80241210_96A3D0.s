.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241210_96A3D0
/* 96A3D0 80241210 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 96A3D4 80241214 AFB10014 */  sw        $s1, 0x14($sp)
/* 96A3D8 80241218 0080882D */  daddu     $s1, $a0, $zero
/* 96A3DC 8024121C AFB00010 */  sw        $s0, 0x10($sp)
/* 96A3E0 80241220 00A0802D */  daddu     $s0, $a1, $zero
/* 96A3E4 80241224 AFBF001C */  sw        $ra, 0x1c($sp)
/* 96A3E8 80241228 AFB20018 */  sw        $s2, 0x18($sp)
/* 96A3EC 8024122C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 96A3F0 80241230 0C00EABB */  jal       get_npc_unsafe
/* 96A3F4 80241234 2404FFFC */   addiu    $a0, $zero, -4
/* 96A3F8 80241238 12000017 */  beqz      $s0, .L80241298
/* 96A3FC 8024123C 0040902D */   daddu    $s2, $v0, $zero
/* 96A400 80241240 0220202D */  daddu     $a0, $s1, $zero
/* 96A404 80241244 3C05FE36 */  lui       $a1, 0xfe36
/* 96A408 80241248 0C0B210B */  jal       get_float_variable
/* 96A40C 8024124C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 96A410 80241250 0220202D */  daddu     $a0, $s1, $zero
/* 96A414 80241254 3C05FE36 */  lui       $a1, 0xfe36
/* 96A418 80241258 3C014270 */  lui       $at, 0x4270
/* 96A41C 8024125C 4481A000 */  mtc1      $at, $f20
/* 96A420 80241260 34A53C85 */  ori       $a1, $a1, 0x3c85
/* 96A424 80241264 46140003 */  div.s     $f0, $f0, $f20
/* 96A428 80241268 0C0B210B */  jal       get_float_variable
/* 96A42C 8024126C E6200074 */   swc1     $f0, 0x74($s1)
/* 96A430 80241270 0220202D */  daddu     $a0, $s1, $zero
/* 96A434 80241274 3C05FE36 */  lui       $a1, 0xfe36
/* 96A438 80241278 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 96A43C 8024127C 46140003 */  div.s     $f0, $f0, $f20
/* 96A440 80241280 0C0B210B */  jal       get_float_variable
/* 96A444 80241284 E6200078 */   swc1     $f0, 0x78($s1)
/* 96A448 80241288 46140003 */  div.s     $f0, $f0, $f20
/* 96A44C 8024128C 2402003C */  addiu     $v0, $zero, 0x3c
/* 96A450 80241290 E620007C */  swc1      $f0, 0x7c($s1)
/* 96A454 80241294 AE220070 */  sw        $v0, 0x70($s1)
.L80241298:
/* 96A458 80241298 C6400038 */  lwc1      $f0, 0x38($s2)
/* 96A45C 8024129C C6220074 */  lwc1      $f2, 0x74($s1)
/* 96A460 802412A0 46020000 */  add.s     $f0, $f0, $f2
/* 96A464 802412A4 E6400038 */  swc1      $f0, 0x38($s2)
/* 96A468 802412A8 C640003C */  lwc1      $f0, 0x3c($s2)
/* 96A46C 802412AC C6220078 */  lwc1      $f2, 0x78($s1)
/* 96A470 802412B0 46020000 */  add.s     $f0, $f0, $f2
/* 96A474 802412B4 E640003C */  swc1      $f0, 0x3c($s2)
/* 96A478 802412B8 C6400040 */  lwc1      $f0, 0x40($s2)
/* 96A47C 802412BC C622007C */  lwc1      $f2, 0x7c($s1)
/* 96A480 802412C0 46020000 */  add.s     $f0, $f0, $f2
/* 96A484 802412C4 E6400040 */  swc1      $f0, 0x40($s2)
/* 96A488 802412C8 8E230070 */  lw        $v1, 0x70($s1)
/* 96A48C 802412CC 2463FFFF */  addiu     $v1, $v1, -1
/* 96A490 802412D0 2C620001 */  sltiu     $v0, $v1, 1
/* 96A494 802412D4 AE230070 */  sw        $v1, 0x70($s1)
/* 96A498 802412D8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 96A49C 802412DC 8FB20018 */  lw        $s2, 0x18($sp)
/* 96A4A0 802412E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 96A4A4 802412E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 96A4A8 802412E8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 96A4AC 802412EC 00021040 */  sll       $v0, $v0, 1
/* 96A4B0 802412F0 03E00008 */  jr        $ra
/* 96A4B4 802412F4 27BD0028 */   addiu    $sp, $sp, 0x28
