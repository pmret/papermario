.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A60
/* 8ED880 80241A60 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8ED884 80241A64 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8ED888 80241A68 4485A000 */  mtc1      $a1, $f20
/* 8ED88C 80241A6C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8ED890 80241A70 4486B000 */  mtc1      $a2, $f22
/* 8ED894 80241A74 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ED898 80241A78 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8ED89C 80241A7C 4487C000 */  mtc1      $a3, $f24
/* 8ED8A0 80241A80 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8ED8A4 80241A84 0C019D28 */  jal       guMtxIdentF
/* 8ED8A8 80241A88 0080802D */   daddu    $s0, $a0, $zero
/* 8ED8AC 80241A8C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8ED8B0 80241A90 00000000 */  nop       
/* 8ED8B4 80241A94 4618A502 */  mul.s     $f20, $f20, $f24
/* 8ED8B8 80241A98 00000000 */  nop       
/* 8ED8BC 80241A9C 3C013F80 */  lui       $at, 0x3f80
/* 8ED8C0 80241AA0 44810000 */  mtc1      $at, $f0
/* 8ED8C4 80241AA4 00000000 */  nop       
/* 8ED8C8 80241AA8 E6000014 */  swc1      $f0, 0x14($s0)
/* 8ED8CC 80241AAC E6160010 */  swc1      $f22, 0x10($s0)
/* 8ED8D0 80241AB0 E6140018 */  swc1      $f20, 0x18($s0)
/* 8ED8D4 80241AB4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8ED8D8 80241AB8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ED8DC 80241ABC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8ED8E0 80241AC0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8ED8E4 80241AC4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8ED8E8 80241AC8 03E00008 */  jr        $ra
/* 8ED8EC 80241ACC 27BD0030 */   addiu    $sp, $sp, 0x30
