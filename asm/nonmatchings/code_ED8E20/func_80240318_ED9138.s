.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240318_ED9138
/* ED9138 80240318 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ED913C 8024031C 0000202D */  daddu     $a0, $zero, $zero
/* ED9140 80240320 0080282D */  daddu     $a1, $a0, $zero
/* ED9144 80240324 0080302D */  daddu     $a2, $a0, $zero
/* ED9148 80240328 0080382D */  daddu     $a3, $a0, $zero
/* ED914C 8024032C AFBF0018 */  sw        $ra, 0x18($sp)
/* ED9150 80240330 AFA00010 */  sw        $zero, 0x10($sp)
/* ED9154 80240334 0C01DEF4 */  jal       func_80077BD0
/* ED9158 80240338 AFA00014 */   sw       $zero, 0x14($sp)
/* ED915C 8024033C 8FBF0018 */  lw        $ra, 0x18($sp)
/* ED9160 80240340 24020002 */  addiu     $v0, $zero, 2
/* ED9164 80240344 03E00008 */  jr        $ra
/* ED9168 80240348 27BD0020 */   addiu    $sp, $sp, 0x20
/* ED916C 8024034C 00000000 */  nop       
