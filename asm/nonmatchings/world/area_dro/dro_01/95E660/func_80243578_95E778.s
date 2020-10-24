.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243578_95E778
/* 95E778 80243578 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95E77C 8024357C AFBF0010 */  sw        $ra, 0x10($sp)
/* 95E780 80243580 0C03A5B2 */  jal       func_800E96C8
/* 95E784 80243584 00000000 */   nop      
/* 95E788 80243588 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95E78C 8024358C 24020002 */  addiu     $v0, $zero, 2
/* 95E790 80243590 03E00008 */  jr        $ra
/* 95E794 80243594 27BD0018 */   addiu    $sp, $sp, 0x18
/* 95E798 80243598 00000000 */  nop       
/* 95E79C 8024359C 00000000 */  nop       
