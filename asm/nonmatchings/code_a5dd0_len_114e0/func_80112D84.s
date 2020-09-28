.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80112D84
/* A9484 80112D84 3C038015 */  lui       $v1, %hi(gMainGameState)
/* A9488 80112D88 24631700 */  addiu     $v1, $v1, %lo(gMainGameState)
/* A948C 80112D8C 00041040 */  sll       $v0, $a0, 1
/* A9490 80112D90 00441021 */  addu      $v0, $v0, $a0
/* A9494 80112D94 000210C0 */  sll       $v0, $v0, 3
/* A9498 80112D98 28840002 */  slti      $a0, $a0, 2
/* A949C 80112D9C 14800003 */  bnez      $a0, .L80112DAC
/* A94A0 80112DA0 00431821 */   addu     $v1, $v0, $v1
.L80112DA4:
/* A94A4 80112DA4 08044B69 */  j         .L80112DA4
/* A94A8 80112DA8 00000000 */   nop      
.L80112DAC:
/* A94AC 80112DAC 94620000 */  lhu       $v0, ($v1)
/* A94B0 80112DB0 AC650014 */  sw        $a1, 0x14($v1)
/* A94B4 80112DB4 34420020 */  ori       $v0, $v0, 0x20
/* A94B8 80112DB8 14A00004 */  bnez      $a1, .L80112DCC
/* A94BC 80112DBC A4620000 */   sh       $v0, ($v1)
/* A94C0 80112DC0 3C028011 */  lui       $v0, 0x8011
/* A94C4 80112DC4 24422B90 */  addiu     $v0, $v0, 0x2b90
/* A94C8 80112DC8 AC620014 */  sw        $v0, 0x14($v1)
.L80112DCC:
/* A94CC 80112DCC 03E00008 */  jr        $ra
/* A94D0 80112DD0 00000000 */   nop      
