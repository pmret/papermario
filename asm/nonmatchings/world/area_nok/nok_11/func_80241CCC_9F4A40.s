.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CCC_9F670C
/* 9F670C 80241CCC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9F6710 80241CD0 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 9F6714 80241CD4 4485A000 */  mtc1      $a1, $f20
/* 9F6718 80241CD8 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 9F671C 80241CDC 4486B000 */  mtc1      $a2, $f22
/* 9F6720 80241CE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9F6724 80241CE4 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 9F6728 80241CE8 4487C000 */  mtc1      $a3, $f24
/* 9F672C 80241CEC AFBF0014 */  sw        $ra, 0x14($sp)
/* 9F6730 80241CF0 0C019D28 */  jal       guMtxIdentF
/* 9F6734 80241CF4 0080802D */   daddu    $s0, $a0, $zero
/* 9F6738 80241CF8 4616A582 */  mul.s     $f22, $f20, $f22
/* 9F673C 80241CFC 00000000 */  nop       
/* 9F6740 80241D00 4618A502 */  mul.s     $f20, $f20, $f24
/* 9F6744 80241D04 00000000 */  nop       
/* 9F6748 80241D08 3C013F80 */  lui       $at, 0x3f80
/* 9F674C 80241D0C 44810000 */  mtc1      $at, $f0
/* 9F6750 80241D10 00000000 */  nop       
/* 9F6754 80241D14 E6000014 */  swc1      $f0, 0x14($s0)
/* 9F6758 80241D18 E6160010 */  swc1      $f22, 0x10($s0)
/* 9F675C 80241D1C E6140018 */  swc1      $f20, 0x18($s0)
/* 9F6760 80241D20 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9F6764 80241D24 8FB00010 */  lw        $s0, 0x10($sp)
/* 9F6768 80241D28 D7B80028 */  ldc1      $f24, 0x28($sp)
/* 9F676C 80241D2C D7B60020 */  ldc1      $f22, 0x20($sp)
/* 9F6770 80241D30 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 9F6774 80241D34 03E00008 */  jr        $ra
/* 9F6778 80241D38 27BD0030 */   addiu    $sp, $sp, 0x30
