.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80268770
/* 197050 80268770 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197054 80268774 24020002 */  addiu     $v0, $zero, 2
/* 197058 80268778 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19705C 8026877C 3C01802A */  lui       $at, 0x802a
/* 197060 80268780 AC22FBC0 */  sw        $v0, -0x440($at)
/* 197064 80268784 0C09A0A1 */  jal       func_80268284
/* 197068 80268788 0000382D */   daddu    $a3, $zero, $zero
/* 19706C 8026878C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197070 80268790 03E00008 */  jr        $ra
/* 197074 80268794 27BD0018 */   addiu    $sp, $sp, 0x18
