.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244360_9DB380
/* 9DB380 80244360 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9DB384 80244364 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 9DB388 80244368 4485A000 */  mtc1      $a1, $f20
/* 9DB38C 8024436C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 9DB390 80244370 4486B000 */  mtc1      $a2, $f22
/* 9DB394 80244374 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DB398 80244378 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 9DB39C 8024437C 4487C000 */  mtc1      $a3, $f24
/* 9DB3A0 80244380 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9DB3A4 80244384 0C019D28 */  jal       guMtxIdentF
/* 9DB3A8 80244388 0080802D */   daddu    $s0, $a0, $zero
/* 9DB3AC 8024438C 4616A582 */  mul.s     $f22, $f20, $f22
/* 9DB3B0 80244390 00000000 */  nop       
/* 9DB3B4 80244394 4618A502 */  mul.s     $f20, $f20, $f24
/* 9DB3B8 80244398 00000000 */  nop       
/* 9DB3BC 8024439C 3C013F80 */  lui       $at, 0x3f80
/* 9DB3C0 802443A0 44810000 */  mtc1      $at, $f0
/* 9DB3C4 802443A4 00000000 */  nop       
/* 9DB3C8 802443A8 E6000014 */  swc1      $f0, 0x14($s0)
/* 9DB3CC 802443AC E6160010 */  swc1      $f22, 0x10($s0)
/* 9DB3D0 802443B0 E6140018 */  swc1      $f20, 0x18($s0)
/* 9DB3D4 802443B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9DB3D8 802443B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DB3DC 802443BC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 9DB3E0 802443C0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 9DB3E4 802443C4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 9DB3E8 802443C8 03E00008 */  jr        $ra
/* 9DB3EC 802443CC 27BD0030 */   addiu    $sp, $sp, 0x30
