.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80268E88
/* 197768 80268E88 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19776C 80268E8C AFB00010 */  sw        $s0, 0x10($sp)
/* 197770 80268E90 3C10802A */  lui       $s0, %hi(gActionCommandStatus)
/* 197774 80268E94 2610FBE0 */  addiu     $s0, $s0, %lo(gActionCommandStatus)
/* 197778 80268E98 3C048027 */  lui       $a0, %hi(func_80268938)
/* 19777C 80268E9C 24848938 */  addiu     $a0, $a0, %lo(func_80268938)
/* 197780 80268EA0 3C058027 */  lui       $a1, %hi(func_80268AF8)
/* 197784 80268EA4 24A58AF8 */  addiu     $a1, $a1, %lo(func_80268AF8)
/* 197788 80268EA8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 19778C 80268EAC 0C048C8F */  jal       create_generic_entity_frontUI
/* 197790 80268EB0 00000000 */   nop
/* 197794 80268EB4 AE020000 */  sw        $v0, ($s0)
/* 197798 80268EB8 A600004A */  sh        $zero, 0x4a($s0)
/* 19779C 80268EBC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1977A0 80268EC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 1977A4 80268EC4 03E00008 */  jr        $ra
/* 1977A8 80268EC8 27BD0018 */   addiu    $sp, $sp, 0x18
