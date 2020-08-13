.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel LandJump
/* 1A83B4 80279AD4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1A83B8 80279AD8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1A83BC 80279ADC 0080882D */  daddu $s1, $a0, $zero
/* 1A83C0 80279AE0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 1A83C4 80279AE4 AFB00018 */  sw    $s0, 0x18($sp)
/* 1A83C8 80279AE8 8E23000C */  lw    $v1, 0xc($s1)
/* 1A83CC 80279AEC 54A00001 */  bnezl $a1, .L80279AF4
/* 1A83D0 80279AF0 AE200070 */   sw    $zero, 0x70($s1)
.L80279AF4:
/* 1A83D4 80279AF4 8E220070 */  lw    $v0, 0x70($s1)
/* 1A83D8 80279AF8 14400015 */  bnez  $v0, .L80279B50
/* 1A83DC 80279AFC 00000000 */   nop   
/* 1A83E0 80279B00 8C650000 */  lw    $a1, ($v1)
/* 1A83E4 80279B04 0C0B1EAF */  jal   get_variable
/* 1A83E8 80279B08 0220202D */   daddu $a0, $s1, $zero
/* 1A83EC 80279B0C 0040202D */  daddu $a0, $v0, $zero
/* 1A83F0 80279B10 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A83F4 80279B14 14820002 */  bne   $a0, $v0, .L80279B20
/* 1A83F8 80279B18 00000000 */   nop   
/* 1A83FC 80279B1C 8E240148 */  lw    $a0, 0x148($s1)
.L80279B20:
/* 1A8400 80279B20 0C09A75B */  jal   get_actor
/* 1A8404 80279B24 00000000 */   nop   
/* 1A8408 80279B28 0040802D */  daddu $s0, $v0, $zero
/* 1A840C 80279B2C AE300074 */  sw    $s0, 0x74($s1)
/* 1A8410 80279B30 C6000144 */  lwc1  $f0, 0x144($s0)
/* 1A8414 80279B34 C6020148 */  lwc1  $f2, 0x148($s0)
/* 1A8418 80279B38 C604014C */  lwc1  $f4, 0x14c($s0)
/* 1A841C 80279B3C 24020001 */  addiu $v0, $zero, 1
/* 1A8420 80279B40 E600000C */  swc1  $f0, 0xc($s0)
/* 1A8424 80279B44 E6020010 */  swc1  $f2, 0x10($s0)
/* 1A8428 80279B48 E6040014 */  swc1  $f4, 0x14($s0)
/* 1A842C 80279B4C AE220070 */  sw    $v0, 0x70($s1)
.L80279B50:
/* 1A8430 80279B50 8E300074 */  lw    $s0, 0x74($s1)
/* 1A8434 80279B54 C6040010 */  lwc1  $f4, 0x10($s0)
/* 1A8438 80279B58 C6000050 */  lwc1  $f0, 0x50($s0)
/* 1A843C 80279B5C 8E05004C */  lw    $a1, 0x4c($s0)
/* 1A8440 80279B60 46002100 */  add.s $f4, $f4, $f0
/* 1A8444 80279B64 C6020048 */  lwc1  $f2, 0x48($s0)
/* 1A8448 80279B68 8E060054 */  lw    $a2, 0x54($s0)
/* 1A844C 80279B6C 46020001 */  sub.s $f0, $f0, $f2
/* 1A8450 80279B70 2604000C */  addiu $a0, $s0, 0xc
/* 1A8454 80279B74 E6040010 */  swc1  $f4, 0x10($s0)
/* 1A8458 80279B78 0C09904A */  jal   add_xz_vec3f
/* 1A845C 80279B7C E6000050 */   swc1  $f0, 0x50($s0)
/* 1A8460 80279B80 C6000010 */  lwc1  $f0, 0x10($s0)
/* 1A8464 80279B84 C6020014 */  lwc1  $f2, 0x14($s0)
/* 1A8468 80279B88 44803000 */  mtc1  $zero, $f6
/* 1A846C 80279B8C E6000148 */  swc1  $f0, 0x148($s0)
/* 1A8470 80279B90 C600000C */  lwc1  $f0, 0xc($s0)
/* 1A8474 80279B94 C6040148 */  lwc1  $f4, 0x148($s0)
/* 1A8478 80279B98 E602014C */  swc1  $f2, 0x14c($s0)
/* 1A847C 80279B9C 4606203C */  c.lt.s $f4, $f6
/* 1A8480 80279BA0 00000000 */  nop   
/* 1A8484 80279BA4 45010003 */  bc1t  .L80279BB4
/* 1A8488 80279BA8 E6000144 */   swc1  $f0, 0x144($s0)
/* 1A848C 80279BAC 0809E6F6 */  j     .L80279BD8
/* 1A8490 80279BB0 0000102D */   daddu $v0, $zero, $zero

.L80279BB4:
/* 1A8494 80279BB4 C600018C */  lwc1  $f0, 0x18c($s0)
/* 1A8498 80279BB8 E6060148 */  swc1  $f6, 0x148($s0)
/* 1A849C 80279BBC E7A00010 */  swc1  $f0, 0x10($sp)
/* 1A84A0 80279BC0 8E050144 */  lw    $a1, 0x144($s0)
/* 1A84A4 80279BC4 8E060148 */  lw    $a2, 0x148($s0)
/* 1A84A8 80279BC8 8E07014C */  lw    $a3, 0x14c($s0)
/* 1A84AC 80279BCC 0C0990BC */  jal   play_movement_dust_effects
/* 1A84B0 80279BD0 24040002 */   addiu $a0, $zero, 2
/* 1A84B4 80279BD4 24020001 */  addiu $v0, $zero, 1
.L80279BD8:
/* 1A84B8 80279BD8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 1A84BC 80279BDC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1A84C0 80279BE0 8FB00018 */  lw    $s0, 0x18($sp)
/* 1A84C4 80279BE4 03E00008 */  jr    $ra
/* 1A84C8 80279BE8 27BD0028 */   addiu $sp, $sp, 0x28

