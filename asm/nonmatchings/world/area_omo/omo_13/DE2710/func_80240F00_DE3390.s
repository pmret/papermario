.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F00_DE3390
/* DE3390 80240F00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DE3394 80240F04 AFBF0010 */  sw        $ra, 0x10($sp)
/* DE3398 80240F08 10A00003 */  beqz      $a1, .L80240F18
/* DE339C 80240F0C 8C86000C */   lw       $a2, 0xc($a0)
/* DE33A0 80240F10 3C018024 */  lui       $at, %hi(D_80241C04)
/* DE33A4 80240F14 AC201C04 */  sw        $zero, %lo(D_80241C04)($at)
.L80240F18:
/* DE33A8 80240F18 3C038024 */  lui       $v1, %hi(D_80241C04)
/* DE33AC 80240F1C 24631C04 */  addiu     $v1, $v1, %lo(D_80241C04)
/* DE33B0 80240F20 8C620000 */  lw        $v0, ($v1)
/* DE33B4 80240F24 54400003 */  bnel      $v0, $zero, .L80240F34
/* DE33B8 80240F28 AC600000 */   sw       $zero, ($v1)
/* DE33BC 80240F2C 080903D2 */  j         .L80240F48
/* DE33C0 80240F30 0000102D */   daddu    $v0, $zero, $zero
.L80240F34:
/* DE33C4 80240F34 8CC50000 */  lw        $a1, ($a2)
/* DE33C8 80240F38 3C068024 */  lui       $a2, %hi(D_80241C08)
/* DE33CC 80240F3C 0C0B2026 */  jal       set_variable
/* DE33D0 80240F40 8CC61C08 */   lw       $a2, %lo(D_80241C08)($a2)
/* DE33D4 80240F44 24020002 */  addiu     $v0, $zero, 2
.L80240F48:
/* DE33D8 80240F48 8FBF0010 */  lw        $ra, 0x10($sp)
/* DE33DC 80240F4C 03E00008 */  jr        $ra
/* DE33E0 80240F50 27BD0018 */   addiu    $sp, $sp, 0x18
