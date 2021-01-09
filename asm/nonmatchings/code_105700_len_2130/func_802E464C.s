.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E464C
/* 105ECC 802E464C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105ED0 802E4650 AFB00010 */  sw        $s0, 0x10($sp)
/* 105ED4 802E4654 AFBF0014 */  sw        $ra, 0x14($sp)
/* 105ED8 802E4658 0C0B8DB9 */  jal       entity_init_Hammer23Block_normal
/* 105EDC 802E465C 0080802D */   daddu    $s0, $a0, $zero
/* 105EE0 802E4660 8E030040 */  lw        $v1, 0x40($s0)
/* 105EE4 802E4664 3C028016 */  lui       $v0, %hi(D_8015C7D2)
/* 105EE8 802E4668 9442C7D2 */  lhu       $v0, %lo(D_8015C7D2)($v0)
/* 105EEC 802E466C A4620010 */  sh        $v0, 0x10($v1)
/* 105EF0 802E4670 3402FFFF */  ori       $v0, $zero, 0xffff
/* 105EF4 802E4674 A462000A */  sh        $v0, 0xa($v1)
/* 105EF8 802E4678 3C02802E */  lui       $v0, %hi(func_802E455C)
/* 105EFC 802E467C 2442455C */  addiu     $v0, $v0, %lo(func_802E455C)
/* 105F00 802E4680 AE02003C */  sw        $v0, 0x3c($s0)
/* 105F04 802E4684 8FBF0014 */  lw        $ra, 0x14($sp)
/* 105F08 802E4688 8FB00010 */  lw        $s0, 0x10($sp)
/* 105F0C 802E468C 03E00008 */  jr        $ra
/* 105F10 802E4690 27BD0018 */   addiu    $sp, $sp, 0x18
