.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_partner_ai
/* 887D8 800EF328 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 887DC 800EF32C AFB00010 */  sw        $s0, 0x10($sp)
/* 887E0 800EF330 3C108011 */  lui       $s0, %hi(D_8010C930)
/* 887E4 800EF334 2610C930 */  addiu     $s0, $s0, %lo(D_8010C930)
/* 887E8 800EF338 AFBF0014 */  sw        $ra, 0x14($sp)
/* 887EC 800EF33C 8E040000 */  lw        $a0, ($s0)
/* 887F0 800EF340 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 887F4 800EF344 A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 887F8 800EF348 0C03BD17 */  jal       clear_partner_move_history
/* 887FC 800EF34C 00000000 */   nop
/* 88800 800EF350 3C028011 */  lui       $v0, %hi(D_8010CFEC)
/* 88804 800EF354 8C42CFEC */  lw        $v0, %lo(D_8010CFEC)($v0)
/* 88808 800EF358 8C42000C */  lw        $v0, 0xc($v0)
/* 8880C 800EF35C 14400006 */  bnez      $v0, .L800EF378
/* 88810 800EF360 00000000 */   nop
/* 88814 800EF364 8E040000 */  lw        $a0, ($s0)
/* 88818 800EF368 0C03AE2A */  jal       enable_partner_walking
/* 8881C 800EF36C 0000282D */   daddu    $a1, $zero, $zero
/* 88820 800EF370 0803BCE1 */  j         .L800EF384
/* 88824 800EF374 00000000 */   nop
.L800EF378:
/* 88828 800EF378 8E040000 */  lw        $a0, ($s0)
/* 8882C 800EF37C 0C03B4C4 */  jal       enable_partner_flying
/* 88830 800EF380 0000282D */   daddu    $a1, $zero, $zero
.L800EF384:
/* 88834 800EF384 8FBF0014 */  lw        $ra, 0x14($sp)
/* 88838 800EF388 8FB00010 */  lw        $s0, 0x10($sp)
/* 8883C 800EF38C 03E00008 */  jr        $ra
/* 88840 800EF390 27BD0018 */   addiu    $sp, $sp, 0x18
