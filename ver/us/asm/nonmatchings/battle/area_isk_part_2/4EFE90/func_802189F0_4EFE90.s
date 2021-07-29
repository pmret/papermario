.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802189F0_4EFE90
/* 4EFE90 802189F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4EFE94 802189F4 3C028022 */  lui       $v0, %hi(D_80220760)
/* 4EFE98 802189F8 24420760 */  addiu     $v0, $v0, %lo(D_80220760)
/* 4EFE9C 802189FC 3C013E99 */  lui       $at, 0x3e99
/* 4EFEA0 80218A00 3421999A */  ori       $at, $at, 0x999a
/* 4EFEA4 80218A04 44810000 */  mtc1      $at, $f0
/* 4EFEA8 80218A08 3C05C2DC */  lui       $a1, 0xc2dc
/* 4EFEAC 80218A0C 3C0642A0 */  lui       $a2, 0x42a0
/* 4EFEB0 80218A10 3C07C312 */  lui       $a3, 0xc312
/* 4EFEB4 80218A14 24040001 */  addiu     $a0, $zero, 1
/* 4EFEB8 80218A18 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFEBC 80218A1C AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFEC0 80218A20 0C01C124 */  jal       playFX_20
/* 4EFEC4 80218A24 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4EFEC8 80218A28 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFECC 80218A2C 24020002 */  addiu     $v0, $zero, 2
/* 4EFED0 80218A30 03E00008 */  jr        $ra
/* 4EFED4 80218A34 27BD0020 */   addiu    $sp, $sp, 0x20
