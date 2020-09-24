.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetOwnerEncounterTrigger
/* 1FA00 80044600 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1FA04 80044604 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1FA08 80044608 8C82000C */  lw        $v0, 0xc($a0)
/* 1FA0C 8004460C 8C830148 */  lw        $v1, 0x148($a0)
/* 1FA10 80044610 8C450000 */  lw        $a1, ($v0)
/* 1FA14 80044614 0C0B2026 */  jal       set_variable
/* 1FA18 80044618 80660005 */   lb       $a2, 5($v1)
/* 1FA1C 8004461C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1FA20 80044620 24020002 */  addiu     $v0, $zero, 2
/* 1FA24 80044624 03E00008 */  jr        $ra
/* 1FA28 80044628 27BD0018 */   addiu    $sp, $sp, 0x18
