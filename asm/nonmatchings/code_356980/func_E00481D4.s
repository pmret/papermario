.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00481D4
/* 356B54 E00481D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 356B58 E00481D8 3C02E005 */  lui       $v0, 0xe005
/* 356B5C E00481DC 24428218 */  addiu     $v0, $v0, -0x7de8
/* 356B60 E00481E0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 356B64 E00481E4 24020028 */  addiu     $v0, $zero, 0x28
/* 356B68 E00481E8 AFA40018 */  sw        $a0, 0x18($sp)
/* 356B6C E00481EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 356B70 E00481F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 356B74 E00481F4 AFA00014 */  sw        $zero, 0x14($sp)
/* 356B78 E00481F8 0C080120 */  jal       func_E0200480
/* 356B7C E00481FC AFA20010 */   sw       $v0, 0x10($sp)
/* 356B80 E0048200 8C430000 */  lw        $v1, ($v0)
/* 356B84 E0048204 34630002 */  ori       $v1, $v1, 2
/* 356B88 E0048208 AC430000 */  sw        $v1, ($v0)
/* 356B8C E004820C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 356B90 E0048210 03E00008 */  jr        $ra
/* 356B94 E0048214 27BD0028 */   addiu    $sp, $sp, 0x28
