.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412A0
/* 8B1310 802412A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8B1314 802412A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B1318 802412A8 0080882D */  daddu     $s1, $a0, $zero
/* 8B131C 802412AC AFB00010 */  sw        $s0, 0x10($sp)
/* 8B1320 802412B0 00A0802D */  daddu     $s0, $a1, $zero
/* 8B1324 802412B4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8B1328 802412B8 AFB20018 */  sw        $s2, 0x18($sp)
/* 8B132C 802412BC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8B1330 802412C0 0C00EABB */  jal       get_npc_unsafe
/* 8B1334 802412C4 2404FFFC */   addiu    $a0, $zero, -4
/* 8B1338 802412C8 12000017 */  beqz      $s0, .L80241328
/* 8B133C 802412CC 0040902D */   daddu    $s2, $v0, $zero
/* 8B1340 802412D0 0220202D */  daddu     $a0, $s1, $zero
/* 8B1344 802412D4 3C05FE36 */  lui       $a1, 0xfe36
/* 8B1348 802412D8 0C0B210B */  jal       get_float_variable
/* 8B134C 802412DC 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8B1350 802412E0 0220202D */  daddu     $a0, $s1, $zero
/* 8B1354 802412E4 3C05FE36 */  lui       $a1, 0xfe36
/* 8B1358 802412E8 3C014270 */  lui       $at, 0x4270
/* 8B135C 802412EC 4481A000 */  mtc1      $at, $f20
/* 8B1360 802412F0 34A53C85 */  ori       $a1, $a1, 0x3c85
/* 8B1364 802412F4 46140003 */  div.s     $f0, $f0, $f20
/* 8B1368 802412F8 0C0B210B */  jal       get_float_variable
/* 8B136C 802412FC E6200074 */   swc1     $f0, 0x74($s1)
/* 8B1370 80241300 0220202D */  daddu     $a0, $s1, $zero
/* 8B1374 80241304 3C05FE36 */  lui       $a1, 0xfe36
/* 8B1378 80241308 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 8B137C 8024130C 46140003 */  div.s     $f0, $f0, $f20
/* 8B1380 80241310 0C0B210B */  jal       get_float_variable
/* 8B1384 80241314 E6200078 */   swc1     $f0, 0x78($s1)
/* 8B1388 80241318 46140003 */  div.s     $f0, $f0, $f20
/* 8B138C 8024131C 2402003C */  addiu     $v0, $zero, 0x3c
/* 8B1390 80241320 E620007C */  swc1      $f0, 0x7c($s1)
/* 8B1394 80241324 AE220070 */  sw        $v0, 0x70($s1)
.L80241328:
/* 8B1398 80241328 C6400038 */  lwc1      $f0, 0x38($s2)
/* 8B139C 8024132C C6220074 */  lwc1      $f2, 0x74($s1)
/* 8B13A0 80241330 46020000 */  add.s     $f0, $f0, $f2
/* 8B13A4 80241334 E6400038 */  swc1      $f0, 0x38($s2)
/* 8B13A8 80241338 C640003C */  lwc1      $f0, 0x3c($s2)
/* 8B13AC 8024133C C6220078 */  lwc1      $f2, 0x78($s1)
/* 8B13B0 80241340 46020000 */  add.s     $f0, $f0, $f2
/* 8B13B4 80241344 E640003C */  swc1      $f0, 0x3c($s2)
/* 8B13B8 80241348 C6400040 */  lwc1      $f0, 0x40($s2)
/* 8B13BC 8024134C C622007C */  lwc1      $f2, 0x7c($s1)
/* 8B13C0 80241350 46020000 */  add.s     $f0, $f0, $f2
/* 8B13C4 80241354 E6400040 */  swc1      $f0, 0x40($s2)
/* 8B13C8 80241358 8E230070 */  lw        $v1, 0x70($s1)
/* 8B13CC 8024135C 2463FFFF */  addiu     $v1, $v1, -1
/* 8B13D0 80241360 2C620001 */  sltiu     $v0, $v1, 1
/* 8B13D4 80241364 AE230070 */  sw        $v1, 0x70($s1)
/* 8B13D8 80241368 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8B13DC 8024136C 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B13E0 80241370 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B13E4 80241374 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B13E8 80241378 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8B13EC 8024137C 00021040 */  sll       $v0, $v0, 1
/* 8B13F0 80241380 03E00008 */  jr        $ra
/* 8B13F4 80241384 27BD0028 */   addiu    $sp, $sp, 0x28
