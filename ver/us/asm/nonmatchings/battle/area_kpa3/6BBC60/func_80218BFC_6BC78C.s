.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BFC_6BC78C
/* 6BC78C 80218BFC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6BC790 80218C00 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6BC794 80218C04 8C82000C */  lw        $v0, 0xc($a0)
/* 6BC798 80218C08 0C0B1EAF */  jal       get_variable
/* 6BC79C 80218C0C 8C450000 */   lw       $a1, ($v0)
/* 6BC7A0 80218C10 0040202D */  daddu     $a0, $v0, $zero
/* 6BC7A4 80218C14 8C82000C */  lw        $v0, 0xc($a0)
/* 6BC7A8 80218C18 3C014310 */  lui       $at, 0x4310
/* 6BC7AC 80218C1C 44810000 */  mtc1      $at, $f0
/* 6BC7B0 80218C20 00000000 */  nop
/* 6BC7B4 80218C24 E4400008 */  swc1      $f0, 8($v0)
/* 6BC7B8 80218C28 8C830000 */  lw        $v1, ($a0)
/* 6BC7BC 80218C2C 34630010 */  ori       $v1, $v1, 0x10
/* 6BC7C0 80218C30 AC830000 */  sw        $v1, ($a0)
/* 6BC7C4 80218C34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6BC7C8 80218C38 24020002 */  addiu     $v0, $zero, 2
/* 6BC7CC 80218C3C 03E00008 */  jr        $ra
/* 6BC7D0 80218C40 27BD0018 */   addiu    $sp, $sp, 0x18
