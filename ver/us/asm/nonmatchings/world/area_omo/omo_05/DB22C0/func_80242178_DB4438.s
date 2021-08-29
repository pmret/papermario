.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242178_DB4438
/* DB4438 80242178 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB443C 8024217C AFBF0010 */  sw        $ra, 0x10($sp)
/* DB4440 80242180 10A00003 */  beqz      $a1, .L80242190
/* DB4444 80242184 8C86000C */   lw       $a2, 0xc($a0)
/* DB4448 80242188 3C018024 */  lui       $at, %hi(D_80243098_DB5358)
/* DB444C 8024218C AC203098 */  sw        $zero, %lo(D_80243098_DB5358)($at)
.L80242190:
/* DB4450 80242190 3C038024 */  lui       $v1, %hi(D_80243098_DB5358)
/* DB4454 80242194 24633098 */  addiu     $v1, $v1, %lo(D_80243098_DB5358)
/* DB4458 80242198 8C620000 */  lw        $v0, ($v1)
/* DB445C 8024219C 54400003 */  bnel      $v0, $zero, .L802421AC
/* DB4460 802421A0 AC600000 */   sw       $zero, ($v1)
/* DB4464 802421A4 08090870 */  j         .L802421C0
/* DB4468 802421A8 0000102D */   daddu    $v0, $zero, $zero
.L802421AC:
/* DB446C 802421AC 8CC50000 */  lw        $a1, ($a2)
/* DB4470 802421B0 3C068024 */  lui       $a2, %hi(D_8024309C_DB535C)
/* DB4474 802421B4 0C0B2026 */  jal       evt_set_variable
/* DB4478 802421B8 8CC6309C */   lw       $a2, %lo(D_8024309C_DB535C)($a2)
/* DB447C 802421BC 24020002 */  addiu     $v0, $zero, 2
.L802421C0:
/* DB4480 802421C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* DB4484 802421C4 03E00008 */  jr        $ra
/* DB4488 802421C8 27BD0018 */   addiu    $sp, $sp, 0x18
