.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80254250
/* 182B30 80254250 3C03800E */  lui       $v1, %hi(gBattleStatus+0x180)
/* 182B34 80254254 8463C1F0 */  lh        $v1, %lo(gBattleStatus+0x180)($v1)
/* 182B38 80254258 28620003 */  slti      $v0, $v1, 3
/* 182B3C 8025425C 14400008 */  bnez      $v0, .L80254280
/* 182B40 80254260 0000202D */   daddu    $a0, $zero, $zero
/* 182B44 80254264 28620005 */  slti      $v0, $v1, 5
/* 182B48 80254268 14400005 */  bnez      $v0, .L80254280
/* 182B4C 8025426C 24040001 */   addiu    $a0, $zero, 1
/* 182B50 80254270 28620009 */  slti      $v0, $v1, 9
/* 182B54 80254274 10400002 */  beqz      $v0, .L80254280
/* 182B58 80254278 24040003 */   addiu    $a0, $zero, 3
/* 182B5C 8025427C 24040002 */  addiu     $a0, $zero, 2
.L80254280:
/* 182B60 80254280 03E00008 */  jr        $ra
/* 182B64 80254284 0080102D */   daddu    $v0, $a0, $zero
