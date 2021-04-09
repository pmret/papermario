.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_22_UnkFunc30
/* C9A540 80240340 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9A544 80240344 AFBF0010 */  sw        $ra, 0x10($sp)
/* C9A548 80240348 8C82000C */  lw        $v0, 0xc($a0)
/* C9A54C 8024034C 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* C9A550 80240350 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* C9A554 80240354 0C0B2026 */  jal       set_variable
/* C9A558 80240358 8C450000 */   lw       $a1, ($v0)
/* C9A55C 8024035C 8FBF0010 */  lw        $ra, 0x10($sp)
/* C9A560 80240360 24020002 */  addiu     $v0, $zero, 2
/* C9A564 80240364 03E00008 */  jr        $ra
/* C9A568 80240368 27BD0018 */   addiu    $sp, $sp, 0x18
