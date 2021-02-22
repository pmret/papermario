.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802687E4
/* 1970C4 802687E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1970C8 802687E8 3C01802A */  lui       $at, %hi(D_8029FBC0)
/* 1970CC 802687EC AC27FBC0 */  sw        $a3, %lo(D_8029FBC0)($at)
/* 1970D0 802687F0 8FA70028 */  lw        $a3, 0x28($sp)
/* 1970D4 802687F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1970D8 802687F8 0C09A0A1 */  jal       func_80268284
/* 1970DC 802687FC 00000000 */   nop
/* 1970E0 80268800 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1970E4 80268804 03E00008 */  jr        $ra
/* 1970E8 80268808 27BD0018 */   addiu    $sp, $sp, 0x18
