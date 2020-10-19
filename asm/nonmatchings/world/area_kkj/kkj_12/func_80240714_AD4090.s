.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240714_AD47A4
/* AD47A4 80240714 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AD47A8 80240718 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AD47AC 8024071C 9062007E */  lbu       $v0, 0x7e($v1)
/* AD47B0 80240720 34420008 */  ori       $v0, $v0, 8
/* AD47B4 80240724 A062007E */  sb        $v0, 0x7e($v1)
/* AD47B8 80240728 03E00008 */  jr        $ra
/* AD47BC 8024072C 24020002 */   addiu    $v0, $zero, 2
