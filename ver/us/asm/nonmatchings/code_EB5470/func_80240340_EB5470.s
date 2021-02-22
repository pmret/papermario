.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_EB5470
/* EB5470 80240340 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB5474 80240344 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB5478 80240348 8C82000C */  lw        $v0, 0xc($a0)
/* EB547C 8024034C 3C068017 */  lui       $a2, %hi(D_80169B12)
/* EB5480 80240350 84C69B12 */  lh        $a2, %lo(D_80169B12)($a2)
/* EB5484 80240354 0C0B551A */  jal       func_802D5468
/* EB5488 80240358 8C450000 */   lw       $a1, ($v0)
/* EB548C 8024035C 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB5490 80240360 24020002 */  addiu     $v0, $zero, 2
/* EB5494 80240364 03E00008 */  jr        $ra
/* EB5498 80240368 27BD0018 */   addiu    $sp, $sp, 0x18
