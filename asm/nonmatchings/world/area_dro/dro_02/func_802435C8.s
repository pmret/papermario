.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435C8
/* 96C788 802435C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C78C 802435CC AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C790 802435D0 8C82000C */  lw        $v0, 0xc($a0)
/* 96C794 802435D4 0C0B1EAF */  jal       get_variable
/* 96C798 802435D8 8C450000 */   lw       $a1, ($v0)
/* 96C79C 802435DC 0C0B1059 */  jal       does_script_exist
/* 96C7A0 802435E0 0040202D */   daddu    $a0, $v0, $zero
/* 96C7A4 802435E4 2C420001 */  sltiu     $v0, $v0, 1
/* 96C7A8 802435E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C7AC 802435EC 00021040 */  sll       $v0, $v0, 1
/* 96C7B0 802435F0 03E00008 */  jr        $ra
/* 96C7B4 802435F4 27BD0018 */   addiu    $sp, $sp, 0x18
