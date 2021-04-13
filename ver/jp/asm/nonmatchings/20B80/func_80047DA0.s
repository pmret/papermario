.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047DA0
/* 231A0 80047DA0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 231A4 80047DA4 00041040 */  sll       $v0, $a0, 1
/* 231A8 80047DA8 00441021 */  addu      $v0, $v0, $a0
/* 231AC 80047DAC 00021080 */  sll       $v0, $v0, 2
/* 231B0 80047DB0 00441023 */  subu      $v0, $v0, $a0
/* 231B4 80047DB4 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 231B8 80047DB8 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 231BC 80047DBC 00021100 */  sll       $v0, $v0, 4
/* 231C0 80047DC0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 231C4 80047DC4 00621821 */  addu      $v1, $v1, $v0
/* 231C8 80047DC8 806200A0 */  lb        $v0, 0xa0($v1)
/* 231CC 80047DCC 10400004 */  beqz      $v0, .L80047DE0
/* 231D0 80047DD0 00000000 */   nop
/* 231D4 80047DD4 8C6400A4 */  lw        $a0, 0xa4($v1)
/* 231D8 80047DD8 0C052669 */  jal       func_801499A4
/* 231DC 80047DDC A06000A0 */   sb       $zero, 0xa0($v1)
.L80047DE0:
/* 231E0 80047DE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 231E4 80047DE4 03E00008 */  jr        $ra
/* 231E8 80047DE8 27BD0018 */   addiu    $sp, $sp, 0x18
