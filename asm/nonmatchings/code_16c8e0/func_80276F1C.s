.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80276F1C
/* 1A57FC 80276F1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A5800 80276F20 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A5804 80276F24 8C82000C */  lw        $v0, 0xc($a0)
/* 1A5808 80276F28 0C0B1EAF */  jal       get_variable
/* 1A580C 80276F2C 8C450000 */   lw       $a1, ($v0)
/* 1A5810 80276F30 0C09C596 */  jal       dispatch_event_player
/* 1A5814 80276F34 0040202D */   daddu    $a0, $v0, $zero
/* 1A5818 80276F38 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A581C 80276F3C 24020002 */  addiu     $v0, $zero, 2
/* 1A5820 80276F40 03E00008 */  jr        $ra
/* 1A5824 80276F44 27BD0018 */   addiu    $sp, $sp, 0x18
/* 1A5828 80276F48 00000000 */  nop       
/* 1A582C 80276F4C 00000000 */  nop       
