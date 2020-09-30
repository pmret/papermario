.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802695D4
/* 197EB4 802695D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197EB8 802695D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197EBC 802695DC 8C82000C */  lw        $v0, 0xc($a0)
/* 197EC0 802695E0 0C0B1EAF */  jal       get_variable
/* 197EC4 802695E4 8C450000 */   lw       $a1, ($v0)
/* 197EC8 802695E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197ECC 802695EC 3C01800E */  lui       $at, 0x800e
/* 197ED0 802695F0 A022C0F4 */  sb        $v0, -0x3f0c($at)
/* 197ED4 802695F4 24020002 */  addiu     $v0, $zero, 2
/* 197ED8 802695F8 03E00008 */  jr        $ra
/* 197EDC 802695FC 27BD0018 */   addiu    $sp, $sp, 0x18
