.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243B2C_7EE83C
/* 7EE83C 80243B2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EE840 80243B30 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EE844 80243B34 0C00EABB */  jal       get_npc_unsafe
/* 7EE848 80243B38 8C84008C */   lw       $a0, 0x8c($a0)
/* 7EE84C 80243B3C 3C038025 */  lui       $v1, 0x8025
/* 7EE850 80243B40 8C6360A4 */  lw        $v1, 0x60a4($v1)
/* 7EE854 80243B44 AC430028 */  sw        $v1, 0x28($v0)
/* 7EE858 80243B48 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EE85C 80243B4C 24020002 */  addiu     $v0, $zero, 2
/* 7EE860 80243B50 03E00008 */  jr        $ra
/* 7EE864 80243B54 27BD0018 */   addiu    $sp, $sp, 0x18
/* 7EE868 80243B58 00000000 */  nop       
/* 7EE86C 80243B5C 00000000 */  nop       
