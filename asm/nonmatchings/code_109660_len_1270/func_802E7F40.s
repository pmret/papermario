.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E7F40
/* 1097C0 802E7F40 3C013F5B */  lui       $at, 0x3f5b
/* 1097C4 802E7F44 34216DB7 */  ori       $at, $at, 0x6db7
/* 1097C8 802E7F48 44810000 */  mtc1      $at, $f0
/* 1097CC 802E7F4C 8C830040 */  lw        $v1, 0x40($a0)
/* 1097D0 802E7F50 E4800058 */  swc1      $f0, 0x58($a0)
/* 1097D4 802E7F54 3C048016 */  lui       $a0, %hi(D_8015C7D0)
/* 1097D8 802E7F58 8C84C7D0 */  lw        $a0, %lo(D_8015C7D0)($a0)
/* 1097DC 802E7F5C 3402FFFF */  ori       $v0, $zero, 0xffff
/* 1097E0 802E7F60 A4620004 */  sh        $v0, 4($v1)
/* 1097E4 802E7F64 03E00008 */  jr        $ra
/* 1097E8 802E7F68 AC640000 */   sw       $a0, ($v1)
