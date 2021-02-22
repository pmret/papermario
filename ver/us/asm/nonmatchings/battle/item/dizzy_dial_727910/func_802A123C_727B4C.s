.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_727B4C
/* 727B4C 802A123C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 727B50 802A1240 0000202D */  daddu     $a0, $zero, $zero
/* 727B54 802A1244 0080282D */  daddu     $a1, $a0, $zero
/* 727B58 802A1248 24060140 */  addiu     $a2, $zero, 0x140
/* 727B5C 802A124C 3C014320 */  lui       $at, 0x4320
/* 727B60 802A1250 44810000 */  mtc1      $at, $f0
/* 727B64 802A1254 240700F0 */  addiu     $a3, $zero, 0xf0
/* 727B68 802A1258 AFBF0018 */  sw        $ra, 0x18($sp)
/* 727B6C 802A125C 0C04E362 */  jal       func_80138D88
/* 727B70 802A1260 E7A00010 */   swc1     $f0, 0x10($sp)
/* 727B74 802A1264 8FBF0018 */  lw        $ra, 0x18($sp)
/* 727B78 802A1268 03E00008 */  jr        $ra
/* 727B7C 802A126C 27BD0020 */   addiu    $sp, $sp, 0x20
