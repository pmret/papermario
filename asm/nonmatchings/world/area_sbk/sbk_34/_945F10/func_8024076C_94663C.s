.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024076C_94663C
/* 94663C 8024076C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 946640 80240770 AFBF0010 */  sw        $ra, 0x10($sp)
/* 946644 80240774 0C00EABB */  jal       get_npc_unsafe
/* 946648 80240778 8C84008C */   lw       $a0, 0x8c($a0)
/* 94664C 8024077C 3C038024 */  lui       $v1, 0x8024
/* 946650 80240780 8C6329A4 */  lw        $v1, 0x29a4($v1)
/* 946654 80240784 AC430028 */  sw        $v1, 0x28($v0)
/* 946658 80240788 8FBF0010 */  lw        $ra, 0x10($sp)
/* 94665C 8024078C 24020002 */  addiu     $v0, $zero, 2
/* 946660 80240790 03E00008 */  jr        $ra
/* 946664 80240794 27BD0018 */   addiu    $sp, $sp, 0x18
/* 946668 80240798 00000000 */  nop       
/* 94666C 8024079C 00000000 */  nop       
