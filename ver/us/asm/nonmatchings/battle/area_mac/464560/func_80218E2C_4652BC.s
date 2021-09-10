.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218E2C_4652BC
/* 4652BC 80218E2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4652C0 80218E30 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4652C4 80218E34 8C82000C */  lw        $v0, 0xc($a0)
/* 4652C8 80218E38 0C0B1EAF */  jal       evt_get_variable
/* 4652CC 80218E3C 8C450000 */   lw       $a1, ($v0)
/* 4652D0 80218E40 0040202D */  daddu     $a0, $v0, $zero
/* 4652D4 80218E44 8C82000C */  lw        $v0, 0xc($a0)
/* 4652D8 80218E48 3C014310 */  lui       $at, 0x4310
/* 4652DC 80218E4C 44810000 */  mtc1      $at, $f0
/* 4652E0 80218E50 00000000 */  nop
/* 4652E4 80218E54 E4400008 */  swc1      $f0, 8($v0)
/* 4652E8 80218E58 8C830000 */  lw        $v1, ($a0)
/* 4652EC 80218E5C 34630010 */  ori       $v1, $v1, 0x10
/* 4652F0 80218E60 AC830000 */  sw        $v1, ($a0)
/* 4652F4 80218E64 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4652F8 80218E68 24020002 */  addiu     $v0, $zero, 2
/* 4652FC 80218E6C 03E00008 */  jr        $ra
/* 465300 80218E70 27BD0018 */   addiu    $sp, $sp, 0x18
