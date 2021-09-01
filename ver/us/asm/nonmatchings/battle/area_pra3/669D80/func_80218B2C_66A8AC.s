.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B2C_66A8AC
/* 66A8AC 80218B2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 66A8B0 80218B30 AFBF0010 */  sw        $ra, 0x10($sp)
/* 66A8B4 80218B34 8C82000C */  lw        $v0, 0xc($a0)
/* 66A8B8 80218B38 0C0B1EAF */  jal       evt_get_variable
/* 66A8BC 80218B3C 8C450000 */   lw       $a1, ($v0)
/* 66A8C0 80218B40 0040202D */  daddu     $a0, $v0, $zero
/* 66A8C4 80218B44 8C82000C */  lw        $v0, 0xc($a0)
/* 66A8C8 80218B48 3C014310 */  lui       $at, 0x4310
/* 66A8CC 80218B4C 44810000 */  mtc1      $at, $f0
/* 66A8D0 80218B50 00000000 */  nop
/* 66A8D4 80218B54 E4400008 */  swc1      $f0, 8($v0)
/* 66A8D8 80218B58 8C830000 */  lw        $v1, ($a0)
/* 66A8DC 80218B5C 34630010 */  ori       $v1, $v1, 0x10
/* 66A8E0 80218B60 AC830000 */  sw        $v1, ($a0)
/* 66A8E4 80218B64 8FBF0010 */  lw        $ra, 0x10($sp)
/* 66A8E8 80218B68 24020002 */  addiu     $v0, $zero, 2
/* 66A8EC 80218B6C 03E00008 */  jr        $ra
/* 66A8F0 80218B70 27BD0018 */   addiu    $sp, $sp, 0x18
