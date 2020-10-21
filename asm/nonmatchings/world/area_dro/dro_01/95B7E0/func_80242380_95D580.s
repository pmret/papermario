.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242380_95D580
/* 95D580 80242380 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 95D584 80242384 AFB10014 */  sw        $s1, 0x14($sp)
/* 95D588 80242388 0080882D */  daddu     $s1, $a0, $zero
/* 95D58C 8024238C AFB00010 */  sw        $s0, 0x10($sp)
/* 95D590 80242390 00A0802D */  daddu     $s0, $a1, $zero
/* 95D594 80242394 AFBF001C */  sw        $ra, 0x1c($sp)
/* 95D598 80242398 AFB20018 */  sw        $s2, 0x18($sp)
/* 95D59C 8024239C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 95D5A0 802423A0 0C00EABB */  jal       get_npc_unsafe
/* 95D5A4 802423A4 2404FFFC */   addiu    $a0, $zero, -4
/* 95D5A8 802423A8 12000017 */  beqz      $s0, .L80242408
/* 95D5AC 802423AC 0040902D */   daddu    $s2, $v0, $zero
/* 95D5B0 802423B0 0220202D */  daddu     $a0, $s1, $zero
/* 95D5B4 802423B4 3C05FE36 */  lui       $a1, 0xfe36
/* 95D5B8 802423B8 0C0B210B */  jal       get_float_variable
/* 95D5BC 802423BC 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 95D5C0 802423C0 0220202D */  daddu     $a0, $s1, $zero
/* 95D5C4 802423C4 3C05FE36 */  lui       $a1, 0xfe36
/* 95D5C8 802423C8 3C014270 */  lui       $at, 0x4270
/* 95D5CC 802423CC 4481A000 */  mtc1      $at, $f20
/* 95D5D0 802423D0 34A53C85 */  ori       $a1, $a1, 0x3c85
/* 95D5D4 802423D4 46140003 */  div.s     $f0, $f0, $f20
/* 95D5D8 802423D8 0C0B210B */  jal       get_float_variable
/* 95D5DC 802423DC E6200074 */   swc1     $f0, 0x74($s1)
/* 95D5E0 802423E0 0220202D */  daddu     $a0, $s1, $zero
/* 95D5E4 802423E4 3C05FE36 */  lui       $a1, 0xfe36
/* 95D5E8 802423E8 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 95D5EC 802423EC 46140003 */  div.s     $f0, $f0, $f20
/* 95D5F0 802423F0 0C0B210B */  jal       get_float_variable
/* 95D5F4 802423F4 E6200078 */   swc1     $f0, 0x78($s1)
/* 95D5F8 802423F8 46140003 */  div.s     $f0, $f0, $f20
/* 95D5FC 802423FC 2402003C */  addiu     $v0, $zero, 0x3c
/* 95D600 80242400 E620007C */  swc1      $f0, 0x7c($s1)
/* 95D604 80242404 AE220070 */  sw        $v0, 0x70($s1)
.L80242408:
/* 95D608 80242408 C6400038 */  lwc1      $f0, 0x38($s2)
/* 95D60C 8024240C C6220074 */  lwc1      $f2, 0x74($s1)
/* 95D610 80242410 46020000 */  add.s     $f0, $f0, $f2
/* 95D614 80242414 E6400038 */  swc1      $f0, 0x38($s2)
/* 95D618 80242418 C640003C */  lwc1      $f0, 0x3c($s2)
/* 95D61C 8024241C C6220078 */  lwc1      $f2, 0x78($s1)
/* 95D620 80242420 46020000 */  add.s     $f0, $f0, $f2
/* 95D624 80242424 E640003C */  swc1      $f0, 0x3c($s2)
/* 95D628 80242428 C6400040 */  lwc1      $f0, 0x40($s2)
/* 95D62C 8024242C C622007C */  lwc1      $f2, 0x7c($s1)
/* 95D630 80242430 46020000 */  add.s     $f0, $f0, $f2
/* 95D634 80242434 E6400040 */  swc1      $f0, 0x40($s2)
/* 95D638 80242438 8E230070 */  lw        $v1, 0x70($s1)
/* 95D63C 8024243C 2463FFFF */  addiu     $v1, $v1, -1
/* 95D640 80242440 2C620001 */  sltiu     $v0, $v1, 1
/* 95D644 80242444 AE230070 */  sw        $v1, 0x70($s1)
/* 95D648 80242448 8FBF001C */  lw        $ra, 0x1c($sp)
/* 95D64C 8024244C 8FB20018 */  lw        $s2, 0x18($sp)
/* 95D650 80242450 8FB10014 */  lw        $s1, 0x14($sp)
/* 95D654 80242454 8FB00010 */  lw        $s0, 0x10($sp)
/* 95D658 80242458 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 95D65C 8024245C 00021040 */  sll       $v0, $v0, 1
/* 95D660 80242460 03E00008 */  jr        $ra
/* 95D664 80242464 27BD0028 */   addiu    $sp, $sp, 0x28
