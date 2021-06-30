.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A0C_897FEC
/* 897FEC 80240A0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 897FF0 80240A10 AFBF0010 */  sw        $ra, 0x10($sp)
/* 897FF4 80240A14 8C82000C */  lw        $v0, 0xc($a0)
/* 897FF8 80240A18 0C0B1EAF */  jal       get_variable
/* 897FFC 80240A1C 8C450000 */   lw       $a1, ($v0)
/* 898000 80240A20 0C03AC5A */  jal       switch_to_partner
/* 898004 80240A24 0040202D */   daddu    $a0, $v0, $zero
/* 898008 80240A28 8FBF0010 */  lw        $ra, 0x10($sp)
/* 89800C 80240A2C 24020002 */  addiu     $v0, $zero, 2
/* 898010 80240A30 03E00008 */  jr        $ra
/* 898014 80240A34 27BD0018 */   addiu    $sp, $sp, 0x18
