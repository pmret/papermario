.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243880
/* 95EA80 80243880 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 95EA84 80243884 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 95EA88 80243888 4485A000 */  mtc1      $a1, $f20
/* 95EA8C 8024388C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 95EA90 80243890 4486B000 */  mtc1      $a2, $f22
/* 95EA94 80243894 AFB00010 */  sw        $s0, 0x10($sp)
/* 95EA98 80243898 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 95EA9C 8024389C 4487C000 */  mtc1      $a3, $f24
/* 95EAA0 802438A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 95EAA4 802438A4 0C019D28 */  jal       guMtxIdentF
/* 95EAA8 802438A8 0080802D */   daddu    $s0, $a0, $zero
/* 95EAAC 802438AC 4616A582 */  mul.s     $f22, $f20, $f22
/* 95EAB0 802438B0 00000000 */  nop       
/* 95EAB4 802438B4 4618A502 */  mul.s     $f20, $f20, $f24
/* 95EAB8 802438B8 00000000 */  nop       
/* 95EABC 802438BC 3C013F80 */  lui       $at, 0x3f80
/* 95EAC0 802438C0 44810000 */  mtc1      $at, $f0
/* 95EAC4 802438C4 00000000 */  nop       
/* 95EAC8 802438C8 E6000014 */  swc1      $f0, 0x14($s0)
/* 95EACC 802438CC E6160010 */  swc1      $f22, 0x10($s0)
/* 95EAD0 802438D0 E6140018 */  swc1      $f20, 0x18($s0)
/* 95EAD4 802438D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 95EAD8 802438D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 95EADC 802438DC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 95EAE0 802438E0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 95EAE4 802438E4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 95EAE8 802438E8 03E00008 */  jr        $ra
/* 95EAEC 802438EC 27BD0030 */   addiu    $sp, $sp, 0x30
