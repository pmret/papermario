.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024106C
/* 7EBD7C 8024106C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EBD80 80241070 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EBD84 80241074 8C82000C */  lw        $v0, 0xc($a0)
/* 7EBD88 80241078 0C0B1EAF */  jal       get_variable
/* 7EBD8C 8024107C 8C450000 */   lw       $a1, ($v0)
/* 7EBD90 80241080 3C038025 */  lui       $v1, 0x8025
/* 7EBD94 80241084 8C635B90 */  lw        $v1, 0x5b90($v1)
/* 7EBD98 80241088 8C63000C */  lw        $v1, 0xc($v1)
/* 7EBD9C 8024108C AC620034 */  sw        $v0, 0x34($v1)
/* 7EBDA0 80241090 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EBDA4 80241094 24020002 */  addiu     $v0, $zero, 2
/* 7EBDA8 80241098 03E00008 */  jr        $ra
/* 7EBDAC 8024109C 27BD0018 */   addiu    $sp, $sp, 0x18
