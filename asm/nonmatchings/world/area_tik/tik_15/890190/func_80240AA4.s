.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AA4
/* 890644 80240AA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 890648 80240AA8 AFB00010 */  sw        $s0, 0x10($sp)
/* 89064C 80240AAC AFBF0014 */  sw        $ra, 0x14($sp)
/* 890650 80240AB0 0C039D88 */  jal       get_item_empty_count
/* 890654 80240AB4 0080802D */   daddu    $s0, $a0, $zero
/* 890658 80240AB8 AE020084 */  sw        $v0, 0x84($s0)
/* 89065C 80240ABC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 890660 80240AC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 890664 80240AC4 24020002 */  addiu     $v0, $zero, 2
/* 890668 80240AC8 03E00008 */  jr        $ra
/* 89066C 80240ACC 27BD0018 */   addiu    $sp, $sp, 0x18
