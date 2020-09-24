.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E7F6C
/* 1097EC 802E7F6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1097F0 802E7F70 3C050A00 */  lui       $a1, 0xa00
/* 1097F4 802E7F74 24A54350 */  addiu     $a1, $a1, 0x4350
/* 1097F8 802E7F78 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1097FC 802E7F7C 8C820040 */  lw        $v0, 0x40($a0)
/* 109800 802E7F80 C480004C */  lwc1      $f0, 0x4c($a0)
/* 109804 802E7F84 3C060A00 */  lui       $a2, 0xa00
/* 109808 802E7F88 24C626F0 */  addiu     $a2, $a2, 0x26f0
/* 10980C 802E7F8C 0C0B9F78 */  jal       func_802E7DE0
/* 109810 802E7F90 E440000C */   swc1     $f0, 0xc($v0)
/* 109814 802E7F94 8FBF0010 */  lw        $ra, 0x10($sp)
/* 109818 802E7F98 03E00008 */  jr        $ra
/* 10981C 802E7F9C 27BD0018 */   addiu    $sp, $sp, 0x18
