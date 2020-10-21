.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F7C_A3A45C
/* A3A45C 80240F7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3A460 80240F80 AFBF0010 */  sw        $ra, 0x10($sp)
/* A3A464 80240F84 10A00003 */  beqz      $a1, .L80240F94
/* A3A468 80240F88 8C86000C */   lw       $a2, 0xc($a0)
/* A3A46C 80240F8C 3C018024 */  lui       $at, 0x8024
/* A3A470 80240F90 AC2045D0 */  sw        $zero, 0x45d0($at)
.L80240F94:
/* A3A474 80240F94 3C038024 */  lui       $v1, 0x8024
/* A3A478 80240F98 246345D0 */  addiu     $v1, $v1, 0x45d0
/* A3A47C 80240F9C 8C620000 */  lw        $v0, ($v1)
/* A3A480 80240FA0 54400003 */  bnel      $v0, $zero, .L80240FB0
/* A3A484 80240FA4 AC600000 */   sw       $zero, ($v1)
/* A3A488 80240FA8 080903F1 */  j         .L80240FC4
/* A3A48C 80240FAC 0000102D */   daddu    $v0, $zero, $zero
.L80240FB0:
/* A3A490 80240FB0 8CC50000 */  lw        $a1, ($a2)
/* A3A494 80240FB4 3C068024 */  lui       $a2, 0x8024
/* A3A498 80240FB8 0C0B2026 */  jal       set_variable
/* A3A49C 80240FBC 8CC645D4 */   lw       $a2, 0x45d4($a2)
/* A3A4A0 80240FC0 24020002 */  addiu     $v0, $zero, 2
.L80240FC4:
/* A3A4A4 80240FC4 8FBF0010 */  lw        $ra, 0x10($sp)
/* A3A4A8 80240FC8 03E00008 */  jr        $ra
/* A3A4AC 80240FCC 27BD0018 */   addiu    $sp, $sp, 0x18
