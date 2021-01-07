.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0076808
/* 377878 E0076808 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 37787C E007680C 3C02E007 */  lui       $v0, %hi(D_E007685C)
/* 377880 E0076810 2442685C */  addiu     $v0, $v0, %lo(D_E007685C)
/* 377884 E0076814 AFA2001C */  sw        $v0, 0x1c($sp)
/* 377888 E0076818 2402002D */  addiu     $v0, $zero, 0x2d
/* 37788C E007681C AFA40018 */  sw        $a0, 0x18($sp)
/* 377890 E0076820 27A40010 */  addiu     $a0, $sp, 0x10
/* 377894 E0076824 AFBF0020 */  sw        $ra, 0x20($sp)
/* 377898 E0076828 AFA00014 */  sw        $zero, 0x14($sp)
/* 37789C E007682C 0C080120 */  jal       func_E0200480
/* 3778A0 E0076830 AFA20010 */   sw       $v0, 0x10($sp)
/* 3778A4 E0076834 8C430000 */  lw        $v1, ($v0)
/* 3778A8 E0076838 34630002 */  ori       $v1, $v1, 2
/* 3778AC E007683C AC430000 */  sw        $v1, ($v0)
/* 3778B0 E0076840 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3778B4 E0076844 03E00008 */  jr        $ra
/* 3778B8 E0076848 27BD0028 */   addiu    $sp, $sp, 0x28
