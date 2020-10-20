.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_CE39FC
/* CE39FC 8024030C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CE3A00 80240310 24040001 */  addiu     $a0, $zero, 1
/* CE3A04 80240314 0000282D */  daddu     $a1, $zero, $zero
/* CE3A08 80240318 00A0302D */  daddu     $a2, $a1, $zero
/* CE3A0C 8024031C 00A0382D */  daddu     $a3, $a1, $zero
/* CE3A10 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* CE3A14 80240324 AFA00010 */  sw        $zero, 0x10($sp)
/* CE3A18 80240328 0C01CA54 */  jal       func_80072950
/* CE3A1C 8024032C AFA00014 */   sw       $zero, 0x14($sp)
/* CE3A20 80240330 8FBF0018 */  lw        $ra, 0x18($sp)
/* CE3A24 80240334 24020002 */  addiu     $v0, $zero, 2
/* CE3A28 80240338 03E00008 */  jr        $ra
/* CE3A2C 8024033C 27BD0020 */   addiu    $sp, $sp, 0x20
