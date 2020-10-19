.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241370
/* 843F40 80241370 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 843F44 80241374 AFB10014 */  sw        $s1, 0x14($sp)
/* 843F48 80241378 0080882D */  daddu     $s1, $a0, $zero
/* 843F4C 8024137C AFB00010 */  sw        $s0, 0x10($sp)
/* 843F50 80241380 00A0802D */  daddu     $s0, $a1, $zero
/* 843F54 80241384 AFBF001C */  sw        $ra, 0x1c($sp)
/* 843F58 80241388 AFB20018 */  sw        $s2, 0x18($sp)
/* 843F5C 8024138C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 843F60 80241390 0C00EABB */  jal       get_npc_unsafe
/* 843F64 80241394 2404FFFC */   addiu    $a0, $zero, -4
/* 843F68 80241398 12000017 */  beqz      $s0, .L802413F8
/* 843F6C 8024139C 0040902D */   daddu    $s2, $v0, $zero
/* 843F70 802413A0 0220202D */  daddu     $a0, $s1, $zero
/* 843F74 802413A4 3C05FE36 */  lui       $a1, 0xfe36
/* 843F78 802413A8 0C0B210B */  jal       get_float_variable
/* 843F7C 802413AC 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 843F80 802413B0 0220202D */  daddu     $a0, $s1, $zero
/* 843F84 802413B4 3C05FE36 */  lui       $a1, 0xfe36
/* 843F88 802413B8 3C014270 */  lui       $at, 0x4270
/* 843F8C 802413BC 4481A000 */  mtc1      $at, $f20
/* 843F90 802413C0 34A53C85 */  ori       $a1, $a1, 0x3c85
/* 843F94 802413C4 46140003 */  div.s     $f0, $f0, $f20
/* 843F98 802413C8 0C0B210B */  jal       get_float_variable
/* 843F9C 802413CC E6200074 */   swc1     $f0, 0x74($s1)
/* 843FA0 802413D0 0220202D */  daddu     $a0, $s1, $zero
/* 843FA4 802413D4 3C05FE36 */  lui       $a1, 0xfe36
/* 843FA8 802413D8 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 843FAC 802413DC 46140003 */  div.s     $f0, $f0, $f20
/* 843FB0 802413E0 0C0B210B */  jal       get_float_variable
/* 843FB4 802413E4 E6200078 */   swc1     $f0, 0x78($s1)
/* 843FB8 802413E8 46140003 */  div.s     $f0, $f0, $f20
/* 843FBC 802413EC 2402003C */  addiu     $v0, $zero, 0x3c
/* 843FC0 802413F0 E620007C */  swc1      $f0, 0x7c($s1)
/* 843FC4 802413F4 AE220070 */  sw        $v0, 0x70($s1)
.L802413F8:
/* 843FC8 802413F8 C6400038 */  lwc1      $f0, 0x38($s2)
/* 843FCC 802413FC C6220074 */  lwc1      $f2, 0x74($s1)
/* 843FD0 80241400 46020000 */  add.s     $f0, $f0, $f2
/* 843FD4 80241404 E6400038 */  swc1      $f0, 0x38($s2)
/* 843FD8 80241408 C640003C */  lwc1      $f0, 0x3c($s2)
/* 843FDC 8024140C C6220078 */  lwc1      $f2, 0x78($s1)
/* 843FE0 80241410 46020000 */  add.s     $f0, $f0, $f2
/* 843FE4 80241414 E640003C */  swc1      $f0, 0x3c($s2)
/* 843FE8 80241418 C6400040 */  lwc1      $f0, 0x40($s2)
/* 843FEC 8024141C C622007C */  lwc1      $f2, 0x7c($s1)
/* 843FF0 80241420 46020000 */  add.s     $f0, $f0, $f2
/* 843FF4 80241424 E6400040 */  swc1      $f0, 0x40($s2)
/* 843FF8 80241428 8E230070 */  lw        $v1, 0x70($s1)
/* 843FFC 8024142C 2463FFFF */  addiu     $v1, $v1, -1
/* 844000 80241430 2C620001 */  sltiu     $v0, $v1, 1
/* 844004 80241434 AE230070 */  sw        $v1, 0x70($s1)
/* 844008 80241438 8FBF001C */  lw        $ra, 0x1c($sp)
/* 84400C 8024143C 8FB20018 */  lw        $s2, 0x18($sp)
/* 844010 80241440 8FB10014 */  lw        $s1, 0x14($sp)
/* 844014 80241444 8FB00010 */  lw        $s0, 0x10($sp)
/* 844018 80241448 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 84401C 8024144C 00021040 */  sll       $v0, $v0, 1
/* 844020 80241450 03E00008 */  jr        $ra
/* 844024 80241454 27BD0028 */   addiu    $sp, $sp, 0x28
