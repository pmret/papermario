.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802446AC_804F2C
/* 804F2C 802446AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 804F30 802446B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 804F34 802446B4 8C82000C */  lw        $v0, 0xc($a0)
/* 804F38 802446B8 0C0B1EAF */  jal       get_variable
/* 804F3C 802446BC 8C450000 */   lw       $a1, ($v0)
/* 804F40 802446C0 8C44000C */  lw        $a0, 0xc($v0)
/* 804F44 802446C4 8C83001C */  lw        $v1, 0x1c($a0)
/* 804F48 802446C8 24630001 */  addiu     $v1, $v1, 1
/* 804F4C 802446CC AC83001C */  sw        $v1, 0x1c($a0)
/* 804F50 802446D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 804F54 802446D4 24020002 */  addiu     $v0, $zero, 2
/* 804F58 802446D8 03E00008 */  jr        $ra
/* 804F5C 802446DC 27BD0018 */   addiu    $sp, $sp, 0x18
