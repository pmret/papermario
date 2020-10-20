.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C2C
/* 9C600C 80240C2C 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 9C6010 80240C30 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 9C6014 80240C34 AC800088 */  sw        $zero, 0x88($a0)
/* 9C6018 80240C38 80A30003 */  lb        $v1, 3($a1)
/* 9C601C 80240C3C 80A20002 */  lb        $v0, 2($a1)
/* 9C6020 80240C40 1462000B */  bne       $v1, $v0, .L80240C70
/* 9C6024 80240C44 00A0302D */   daddu    $a2, $a1, $zero
/* 9C6028 80240C48 80A30006 */  lb        $v1, 6($a1)
/* 9C602C 80240C4C 80A20005 */  lb        $v0, 5($a1)
/* 9C6030 80240C50 14620007 */  bne       $v1, $v0, .L80240C70
/* 9C6034 80240C54 00000000 */   nop      
/* 9C6038 80240C58 80C2028E */  lb        $v0, 0x28e($a2)
/* 9C603C 80240C5C 84C30290 */  lh        $v1, 0x290($a2)
/* 9C6040 80240C60 00021200 */  sll       $v0, $v0, 8
/* 9C6044 80240C64 14620004 */  bne       $v1, $v0, .L80240C78
/* 9C6048 80240C68 24020001 */   addiu    $v0, $zero, 1
/* 9C604C 80240C6C AC820088 */  sw        $v0, 0x88($a0)
.L80240C70:
/* 9C6050 80240C70 03E00008 */  jr        $ra
/* 9C6054 80240C74 24020002 */   addiu    $v0, $zero, 2
.L80240C78:
/* 9C6058 80240C78 03E00008 */  jr        $ra
/* 9C605C 80240C7C 24020002 */   addiu    $v0, $zero, 2
