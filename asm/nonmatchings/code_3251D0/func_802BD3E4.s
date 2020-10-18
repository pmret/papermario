.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD3E4
/* 3254B4 802BD3E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3254B8 802BD3E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3254BC 802BD3EC 0C009C22 */  jal       func_80027088
/* 3254C0 802BD3F0 24040002 */   addiu    $a0, $zero, 2
/* 3254C4 802BD3F4 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 3254C8 802BD3F8 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 3254CC 802BD3FC 8C430000 */  lw        $v1, ($v0)
/* 3254D0 802BD400 3C040020 */  lui       $a0, 0x20
/* 3254D4 802BD404 00641825 */  or        $v1, $v1, $a0
/* 3254D8 802BD408 AC430000 */  sw        $v1, ($v0)
/* 3254DC 802BD40C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3254E0 802BD410 24020002 */  addiu     $v0, $zero, 2
/* 3254E4 802BD414 03E00008 */  jr        $ra
/* 3254E8 802BD418 27BD0018 */   addiu    $sp, $sp, 0x18
