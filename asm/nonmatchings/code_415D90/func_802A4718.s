.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A4718
/* 4194A8 802A4718 2402000A */  addiu     $v0, $zero, 0xa
/* 4194AC 802A471C 3C01802B */  lui       $at, %hi(D_802AD604)
/* 4194B0 802A4720 A022D604 */  sb        $v0, %lo(D_802AD604)($at)
/* 4194B4 802A4724 03E00008 */  jr        $ra
/* 4194B8 802A4728 00000000 */   nop
