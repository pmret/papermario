.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_08_UnkFunc39
/* CAF250 80240510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CAF254 80240514 AFBF0010 */  sw        $ra, 0x10($sp)
/* CAF258 80240518 8C82000C */  lw        $v0, 0xc($a0)
/* CAF25C 8024051C 0C0B1EAF */  jal       get_variable
/* CAF260 80240520 8C450000 */   lw       $a1, ($v0)
/* CAF264 80240524 0040202D */  daddu     $a0, $v0, $zero
/* CAF268 80240528 8C830000 */  lw        $v1, ($a0)
/* CAF26C 8024052C 34630010 */  ori       $v1, $v1, 0x10
/* CAF270 80240530 AC830000 */  sw        $v1, ($a0)
/* CAF274 80240534 8FBF0010 */  lw        $ra, 0x10($sp)
/* CAF278 80240538 24020002 */  addiu     $v0, $zero, 2
/* CAF27C 8024053C 03E00008 */  jr        $ra
/* CAF280 80240540 27BD0018 */   addiu    $sp, $sp, 0x18
