.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024053C_CF80AC
/* CF80AC 8024053C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF80B0 80240540 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF80B4 80240544 10A00003 */  beqz      $a1, .L80240554
/* CF80B8 80240548 8C86000C */   lw       $a2, 0xc($a0)
/* CF80BC 8024054C 3C018024 */  lui       $at, %hi(D_802432D0_CFAE40)
/* CF80C0 80240550 AC2032D0 */  sw        $zero, %lo(D_802432D0_CFAE40)($at)
.L80240554:
/* CF80C4 80240554 3C038024 */  lui       $v1, %hi(D_802432D0_CFAE40)
/* CF80C8 80240558 246332D0 */  addiu     $v1, $v1, %lo(D_802432D0_CFAE40)
/* CF80CC 8024055C 8C620000 */  lw        $v0, ($v1)
/* CF80D0 80240560 54400003 */  bnel      $v0, $zero, .L80240570
/* CF80D4 80240564 AC600000 */   sw       $zero, ($v1)
/* CF80D8 80240568 08090161 */  j         .L80240584
/* CF80DC 8024056C 0000102D */   daddu    $v0, $zero, $zero
.L80240570:
/* CF80E0 80240570 8CC50000 */  lw        $a1, ($a2)
/* CF80E4 80240574 3C068024 */  lui       $a2, %hi(D_802432D4_CFAE44)
/* CF80E8 80240578 0C0B2026 */  jal       evt_set_variable
/* CF80EC 8024057C 8CC632D4 */   lw       $a2, %lo(D_802432D4_CFAE44)($a2)
/* CF80F0 80240580 24020002 */  addiu     $v0, $zero, 2
.L80240584:
/* CF80F4 80240584 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF80F8 80240588 03E00008 */  jr        $ra
/* CF80FC 8024058C 27BD0018 */   addiu    $sp, $sp, 0x18
