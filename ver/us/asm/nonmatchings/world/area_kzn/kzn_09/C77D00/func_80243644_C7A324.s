.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243644_C7A324
/* C7A324 80243644 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7A328 80243648 AFBF0010 */  sw        $ra, 0x10($sp)
/* C7A32C 8024364C 8C82000C */  lw        $v0, 0xc($a0)
/* C7A330 80243650 0C0B1EAF */  jal       get_variable
/* C7A334 80243654 8C450000 */   lw       $a1, ($v0)
/* C7A338 80243658 3C018024 */  lui       $at, %hi(D_802452B8_C7BF98)
/* C7A33C 8024365C AC2252B8 */  sw        $v0, %lo(D_802452B8_C7BF98)($at)
/* C7A340 80243660 24020002 */  addiu     $v0, $zero, 2
/* C7A344 80243664 8FBF0010 */  lw        $ra, 0x10($sp)
/* C7A348 80243668 24030001 */  addiu     $v1, $zero, 1
/* C7A34C 8024366C 3C018024 */  lui       $at, %hi(D_802452B4_C7BF94)
/* C7A350 80243670 AC2352B4 */  sw        $v1, %lo(D_802452B4_C7BF94)($at)
/* C7A354 80243674 03E00008 */  jr        $ra
/* C7A358 80243678 27BD0018 */   addiu    $sp, $sp, 0x18
