.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047B88
/* 22F88 80047B88 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 22F8C 80047B8C 00041040 */  sll       $v0, $a0, 1
/* 22F90 80047B90 00441021 */  addu      $v0, $v0, $a0
/* 22F94 80047B94 00021080 */  sll       $v0, $v0, 2
/* 22F98 80047B98 00441023 */  subu      $v0, $v0, $a0
/* 22F9C 80047B9C 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22FA0 80047BA0 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22FA4 80047BA4 00021100 */  sll       $v0, $v0, 4
/* 22FA8 80047BA8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 22FAC 80047BAC 00621821 */  addu      $v1, $v1, $v0
/* 22FB0 80047BB0 80620090 */  lb        $v0, 0x90($v1)
/* 22FB4 80047BB4 10400004 */  beqz      $v0, .L80047BC8
/* 22FB8 80047BB8 00000000 */   nop
/* 22FBC 80047BBC 8C640094 */  lw        $a0, 0x94($v1)
/* 22FC0 80047BC0 0C052669 */  jal       func_801499A4
/* 22FC4 80047BC4 A0600090 */   sb       $zero, 0x90($v1)
.L80047BC8:
/* 22FC8 80047BC8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 22FCC 80047BCC 03E00008 */  jr        $ra
/* 22FD0 80047BD0 27BD0018 */   addiu    $sp, $sp, 0x18
