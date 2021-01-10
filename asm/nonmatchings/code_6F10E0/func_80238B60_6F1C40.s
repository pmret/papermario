.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238B60_6F1C40
/* 6F1C40 80238B60 3C02800E */  lui       $v0, %hi(gBattleStatus+0xDC)
/* 6F1C44 80238B64 8C42C14C */  lw        $v0, %lo(gBattleStatus+0xDC)($v0)
/* 6F1C48 80238B68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6F1C4C 80238B6C AFB00010 */  sw        $s0, 0x10($sp)
/* 6F1C50 80238B70 0080802D */  daddu     $s0, $a0, $zero
/* 6F1C54 80238B74 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6F1C58 80238B78 0C09A75B */  jal       get_actor
/* 6F1C5C 80238B7C 84440428 */   lh       $a0, 0x428($v0)
/* 6F1C60 80238B80 0040202D */  daddu     $a0, $v0, $zero
/* 6F1C64 80238B84 90820136 */  lbu       $v0, 0x136($a0)
/* 6F1C68 80238B88 00021080 */  sll       $v0, $v0, 2
/* 6F1C6C 80238B8C 3C018028 */  lui       $at, %hi(D_80282B98)
/* 6F1C70 80238B90 00220821 */  addu      $at, $at, $v0
/* 6F1C74 80238B94 8C222B98 */  lw        $v0, %lo(D_80282B98)($at)
/* 6F1C78 80238B98 3C038028 */  lui       $v1, %hi(D_80282B98)
/* 6F1C7C 80238B9C 24632B98 */  addiu     $v1, $v1, %lo(D_80282B98)
/* 6F1C80 80238BA0 14400003 */  bnez      $v0, .L80238BB0
/* 6F1C84 80238BA4 AE020084 */   sw       $v0, 0x84($s0)
/* 6F1C88 80238BA8 8C620000 */  lw        $v0, ($v1)
/* 6F1C8C 80238BAC AE020084 */  sw        $v0, 0x84($s0)
.L80238BB0:
/* 6F1C90 80238BB0 0C094F44 */  jal       save_tattle_flags
/* 6F1C94 80238BB4 90840136 */   lbu      $a0, 0x136($a0)
/* 6F1C98 80238BB8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6F1C9C 80238BBC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6F1CA0 80238BC0 24020002 */  addiu     $v0, $zero, 2
/* 6F1CA4 80238BC4 03E00008 */  jr        $ra
/* 6F1CA8 80238BC8 27BD0018 */   addiu    $sp, $sp, 0x18
