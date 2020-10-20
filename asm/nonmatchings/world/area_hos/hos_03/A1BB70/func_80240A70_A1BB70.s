.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A70_A1BB70
/* A1BB70 80240A70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A1BB74 80240A74 F7B40018 */  sdc1      $f20, 0x18($sp)
/* A1BB78 80240A78 4485A000 */  mtc1      $a1, $f20
/* A1BB7C 80240A7C F7B60020 */  sdc1      $f22, 0x20($sp)
/* A1BB80 80240A80 4486B000 */  mtc1      $a2, $f22
/* A1BB84 80240A84 AFB00010 */  sw        $s0, 0x10($sp)
/* A1BB88 80240A88 F7B80028 */  sdc1      $f24, 0x28($sp)
/* A1BB8C 80240A8C 4487C000 */  mtc1      $a3, $f24
/* A1BB90 80240A90 AFBF0014 */  sw        $ra, 0x14($sp)
/* A1BB94 80240A94 0C019D28 */  jal       guMtxIdentF
/* A1BB98 80240A98 0080802D */   daddu    $s0, $a0, $zero
/* A1BB9C 80240A9C 4616A582 */  mul.s     $f22, $f20, $f22
/* A1BBA0 80240AA0 00000000 */  nop       
/* A1BBA4 80240AA4 4618A502 */  mul.s     $f20, $f20, $f24
/* A1BBA8 80240AA8 00000000 */  nop       
/* A1BBAC 80240AAC 3C013F80 */  lui       $at, 0x3f80
/* A1BBB0 80240AB0 44810000 */  mtc1      $at, $f0
/* A1BBB4 80240AB4 00000000 */  nop       
/* A1BBB8 80240AB8 E6000014 */  swc1      $f0, 0x14($s0)
/* A1BBBC 80240ABC E6160010 */  swc1      $f22, 0x10($s0)
/* A1BBC0 80240AC0 E6140018 */  swc1      $f20, 0x18($s0)
/* A1BBC4 80240AC4 8FBF0014 */  lw        $ra, 0x14($sp)
/* A1BBC8 80240AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* A1BBCC 80240ACC D7B80028 */  ldc1      $f24, 0x28($sp)
/* A1BBD0 80240AD0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* A1BBD4 80240AD4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* A1BBD8 80240AD8 03E00008 */  jr        $ra
/* A1BBDC 80240ADC 27BD0030 */   addiu    $sp, $sp, 0x30
