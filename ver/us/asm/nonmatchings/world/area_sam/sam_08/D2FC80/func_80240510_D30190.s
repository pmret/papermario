.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_08_UnkFunc39
/* D30190 80240510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D30194 80240514 AFBF0010 */  sw        $ra, 0x10($sp)
/* D30198 80240518 8C82000C */  lw        $v0, 0xc($a0)
/* D3019C 8024051C 0C0B1EAF */  jal       get_variable
/* D301A0 80240520 8C450000 */   lw       $a1, ($v0)
/* D301A4 80240524 0040202D */  daddu     $a0, $v0, $zero
/* D301A8 80240528 8C830000 */  lw        $v1, ($a0)
/* D301AC 8024052C 34630010 */  ori       $v1, $v1, 0x10
/* D301B0 80240530 AC830000 */  sw        $v1, ($a0)
/* D301B4 80240534 8FBF0010 */  lw        $ra, 0x10($sp)
/* D301B8 80240538 24020002 */  addiu     $v0, $zero, 2
/* D301BC 8024053C 03E00008 */  jr        $ra
/* D301C0 80240540 27BD0018 */   addiu    $sp, $sp, 0x18
