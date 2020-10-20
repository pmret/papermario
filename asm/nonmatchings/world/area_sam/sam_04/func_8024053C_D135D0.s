.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024053C_D13B0C
/* D13B0C 8024053C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D13B10 80240540 AFBF0010 */  sw        $ra, 0x10($sp)
/* D13B14 80240544 10A00003 */  beqz      $a1, .L80240554
/* D13B18 80240548 8C86000C */   lw       $a2, 0xc($a0)
/* D13B1C 8024054C 3C018024 */  lui       $at, 0x8024
/* D13B20 80240550 AC20387C */  sw        $zero, 0x387c($at)
.L80240554:
/* D13B24 80240554 3C038024 */  lui       $v1, 0x8024
/* D13B28 80240558 2463387C */  addiu     $v1, $v1, 0x387c
/* D13B2C 8024055C 8C620000 */  lw        $v0, ($v1)
/* D13B30 80240560 54400003 */  bnel      $v0, $zero, .L80240570
/* D13B34 80240564 AC600000 */   sw       $zero, ($v1)
/* D13B38 80240568 08090161 */  j         .L80240584
/* D13B3C 8024056C 0000102D */   daddu    $v0, $zero, $zero
.L80240570:
/* D13B40 80240570 8CC50000 */  lw        $a1, ($a2)
/* D13B44 80240574 3C068024 */  lui       $a2, 0x8024
/* D13B48 80240578 0C0B2026 */  jal       set_variable
/* D13B4C 8024057C 8CC63880 */   lw       $a2, 0x3880($a2)
/* D13B50 80240580 24020002 */  addiu     $v0, $zero, 2
.L80240584:
/* D13B54 80240584 8FBF0010 */  lw        $ra, 0x10($sp)
/* D13B58 80240588 03E00008 */  jr        $ra
/* D13B5C 8024058C 27BD0018 */   addiu    $sp, $sp, 0x18
