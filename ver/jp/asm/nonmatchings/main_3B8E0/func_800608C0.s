.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800608C0
/* 3BCC0 800608C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BCC4 800608C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BCC8 800608C8 0C018244 */  jal       func_80060910
/* 3BCCC 800608CC 24040001 */   addiu    $a0, $zero, 1
/* 3BCD0 800608D0 3C01800A */  lui       $at, %hi(D_8009A5C0)
/* 3BCD4 800608D4 AC20A5C0 */  sw        $zero, %lo(D_8009A5C0)($at)
/* 3BCD8 800608D8 0C018244 */  jal       func_80060910
/* 3BCDC 800608DC 0040202D */   daddu    $a0, $v0, $zero
/* 3BCE0 800608E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BCE4 800608E4 03E00008 */  jr        $ra
/* 3BCE8 800608E8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3BCEC 800608EC 00000000 */  nop
