.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240410_8C83A0
/* 8C83A0 80240410 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8C83A4 80240414 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8C83A8 80240418 4485A000 */  mtc1      $a1, $f20
/* 8C83AC 8024041C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8C83B0 80240420 4486B000 */  mtc1      $a2, $f22
/* 8C83B4 80240424 AFB00010 */  sw        $s0, 0x10($sp)
/* 8C83B8 80240428 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8C83BC 8024042C 4487C000 */  mtc1      $a3, $f24
/* 8C83C0 80240430 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8C83C4 80240434 0C019D28 */  jal       guMtxIdentF
/* 8C83C8 80240438 0080802D */   daddu    $s0, $a0, $zero
/* 8C83CC 8024043C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8C83D0 80240440 00000000 */  nop       
/* 8C83D4 80240444 4618A502 */  mul.s     $f20, $f20, $f24
/* 8C83D8 80240448 00000000 */  nop       
/* 8C83DC 8024044C 3C013F80 */  lui       $at, 0x3f80
/* 8C83E0 80240450 44810000 */  mtc1      $at, $f0
/* 8C83E4 80240454 00000000 */  nop       
/* 8C83E8 80240458 E6000014 */  swc1      $f0, 0x14($s0)
/* 8C83EC 8024045C E6160010 */  swc1      $f22, 0x10($s0)
/* 8C83F0 80240460 E6140018 */  swc1      $f20, 0x18($s0)
/* 8C83F4 80240464 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8C83F8 80240468 8FB00010 */  lw        $s0, 0x10($sp)
/* 8C83FC 8024046C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8C8400 80240470 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8C8404 80240474 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8C8408 80240478 03E00008 */  jr        $ra
/* 8C840C 8024047C 27BD0030 */   addiu    $sp, $sp, 0x30
