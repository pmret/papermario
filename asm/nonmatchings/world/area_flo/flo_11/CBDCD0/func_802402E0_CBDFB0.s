.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E0_CBDFB0
/* CBDFB0 802402E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CBDFB4 802402E4 0000202D */  daddu     $a0, $zero, $zero
/* CBDFB8 802402E8 0080282D */  daddu     $a1, $a0, $zero
/* CBDFBC 802402EC 0080302D */  daddu     $a2, $a0, $zero
/* CBDFC0 802402F0 0080382D */  daddu     $a3, $a0, $zero
/* CBDFC4 802402F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* CBDFC8 802402F8 AFA00010 */  sw        $zero, 0x10($sp)
/* CBDFCC 802402FC 0C01CA54 */  jal       func_80072950
/* CBDFD0 80240300 AFA00014 */   sw       $zero, 0x14($sp)
/* CBDFD4 80240304 8FBF0018 */  lw        $ra, 0x18($sp)
/* CBDFD8 80240308 24020002 */  addiu     $v0, $zero, 2
/* CBDFDC 8024030C 03E00008 */  jr        $ra
/* CBDFE0 80240310 27BD0020 */   addiu    $sp, $sp, 0x20
/* CBDFE4 80240314 00000000 */  nop       
/* CBDFE8 80240318 00000000 */  nop       
/* CBDFEC 8024031C 00000000 */  nop       
