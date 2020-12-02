.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056F78
/* 32378 80056F78 308400FF */  andi      $a0, $a0, 0xff
/* 3237C 80056F7C 00041140 */  sll       $v0, $a0, 5
/* 32380 80056F80 3C038008 */  lui       $v1, %hi(D_80078E54)
/* 32384 80056F84 8C638E54 */  lw        $v1, %lo(D_80078E54)($v1)
/* 32388 80056F88 00441023 */  subu      $v0, $v0, $a0
/* 3238C 80056F8C 8C63001C */  lw        $v1, 0x1c($v1)
/* 32390 80056F90 00021080 */  sll       $v0, $v0, 2
/* 32394 80056F94 00621821 */  addu      $v1, $v1, $v0
/* 32398 80056F98 24020001 */  addiu     $v0, $zero, 1
/* 3239C 80056F9C 03E00008 */  jr        $ra
/* 323A0 80056FA0 AC620070 */   sw       $v0, 0x70($v1)
