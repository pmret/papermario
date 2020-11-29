.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243A40_96CC00
/* 96CC00 80243A40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96CC04 80243A44 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96CC08 80243A48 0C00EABB */  jal       get_npc_unsafe
/* 96CC0C 80243A4C 8C84008C */   lw       $a0, 0x8c($a0)
/* 96CC10 80243A50 3C038025 */  lui       $v1, %hi(D_8024F3B8)
/* 96CC14 80243A54 8C63F3B8 */  lw        $v1, %lo(D_8024F3B8)($v1)
/* 96CC18 80243A58 AC430028 */  sw        $v1, 0x28($v0)
/* 96CC1C 80243A5C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96CC20 80243A60 24020002 */  addiu     $v0, $zero, 2
/* 96CC24 80243A64 03E00008 */  jr        $ra
/* 96CC28 80243A68 27BD0018 */   addiu    $sp, $sp, 0x18
/* 96CC2C 80243A6C 00000000 */  nop       
