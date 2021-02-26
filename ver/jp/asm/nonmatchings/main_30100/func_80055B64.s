.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055B64
/* 30F64 80055B64 2C820008 */  sltiu     $v0, $a0, 8
/* 30F68 80055B68 10400025 */  beqz      $v0, .L80055C00
/* 30F6C 80055B6C 0000182D */   daddu    $v1, $zero, $zero
/* 30F70 80055B70 00041080 */  sll       $v0, $a0, 2
/* 30F74 80055B74 3C01800A */  lui       $at, %hi(D_800988E8)
/* 30F78 80055B78 00220821 */  addu      $at, $at, $v0
/* 30F7C 80055B7C 8C2288E8 */  lw        $v0, %lo(D_800988E8)($at)
/* 30F80 80055B80 00400008 */  jr        $v0
/* 30F84 80055B84 00000000 */   nop
/* 30F88 80055B88 3C038008 */  lui       $v1, %hi(D_80078D88)
/* 30F8C 80055B8C 24638D88 */  addiu     $v1, $v1, %lo(D_80078D88)
/* 30F90 80055B90 03E00008 */  jr        $ra
/* 30F94 80055B94 0060102D */   daddu    $v0, $v1, $zero
/* 30F98 80055B98 3C038008 */  lui       $v1, %hi(D_80078D94)
/* 30F9C 80055B9C 24638D94 */  addiu     $v1, $v1, %lo(D_80078D94)
/* 30FA0 80055BA0 03E00008 */  jr        $ra
/* 30FA4 80055BA4 0060102D */   daddu    $v0, $v1, $zero
/* 30FA8 80055BA8 3C038008 */  lui       $v1, %hi(D_80078D9C)
/* 30FAC 80055BAC 24638D9C */  addiu     $v1, $v1, %lo(D_80078D9C)
/* 30FB0 80055BB0 03E00008 */  jr        $ra
/* 30FB4 80055BB4 0060102D */   daddu    $v0, $v1, $zero
/* 30FB8 80055BB8 3C038008 */  lui       $v1, %hi(D_80078DA0)
/* 30FBC 80055BBC 24638DA0 */  addiu     $v1, $v1, %lo(D_80078DA0)
/* 30FC0 80055BC0 03E00008 */  jr        $ra
/* 30FC4 80055BC4 0060102D */   daddu    $v0, $v1, $zero
/* 30FC8 80055BC8 3C038008 */  lui       $v1, %hi(D_80078DAC)
/* 30FCC 80055BCC 24638DAC */  addiu     $v1, $v1, %lo(D_80078DAC)
/* 30FD0 80055BD0 03E00008 */  jr        $ra
/* 30FD4 80055BD4 0060102D */   daddu    $v0, $v1, $zero
/* 30FD8 80055BD8 3C038008 */  lui       $v1, %hi(D_80078DC8)
/* 30FDC 80055BDC 24638DC8 */  addiu     $v1, $v1, %lo(D_80078DC8)
/* 30FE0 80055BE0 03E00008 */  jr        $ra
/* 30FE4 80055BE4 0060102D */   daddu    $v0, $v1, $zero
/* 30FE8 80055BE8 3C038008 */  lui       $v1, %hi(D_80078DE4)
/* 30FEC 80055BEC 24638DE4 */  addiu     $v1, $v1, %lo(D_80078DE4)
/* 30FF0 80055BF0 03E00008 */  jr        $ra
/* 30FF4 80055BF4 0060102D */   daddu    $v0, $v1, $zero
/* 30FF8 80055BF8 3C038008 */  lui       $v1, %hi(D_80078E00)
/* 30FFC 80055BFC 24638E00 */  addiu     $v1, $v1, %lo(D_80078E00)
.L80055C00:
/* 31000 80055C00 03E00008 */  jr        $ra
/* 31004 80055C04 0060102D */   daddu    $v0, $v1, $zero
