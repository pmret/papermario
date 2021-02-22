.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218220_4DA800
/* 4DA800 80218220 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4DA804 80218224 AFB00010 */  sw        $s0, 0x10($sp)
/* 4DA808 80218228 0080802D */  daddu     $s0, $a0, $zero
/* 4DA80C 8021822C AFBF0014 */  sw        $ra, 0x14($sp)
/* 4DA810 80218230 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 4DA814 80218234 8E0400AC */   lw       $a0, 0xac($s0)
/* 4DA818 80218238 0C046B4C */  jal       get_model_from_list_index
/* 4DA81C 8021823C 0040202D */   daddu    $a0, $v0, $zero
/* 4DA820 80218240 C4400098 */  lwc1      $f0, 0x98($v0)
/* 4DA824 80218244 4600008D */  trunc.w.s $f2, $f0
/* 4DA828 80218248 E60200B0 */  swc1      $f2, 0xb0($s0)
/* 4DA82C 8021824C C440009C */  lwc1      $f0, 0x9c($v0)
/* 4DA830 80218250 4600008D */  trunc.w.s $f2, $f0
/* 4DA834 80218254 E60200B4 */  swc1      $f2, 0xb4($s0)
/* 4DA838 80218258 C44000A0 */  lwc1      $f0, 0xa0($v0)
/* 4DA83C 8021825C 4600008D */  trunc.w.s $f2, $f0
/* 4DA840 80218260 E60200B8 */  swc1      $f2, 0xb8($s0)
/* 4DA844 80218264 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4DA848 80218268 8FB00010 */  lw        $s0, 0x10($sp)
/* 4DA84C 8021826C 24020002 */  addiu     $v0, $zero, 2
/* 4DA850 80218270 03E00008 */  jr        $ra
/* 4DA854 80218274 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4DA858 80218278 00000000 */  nop
/* 4DA85C 8021827C 00000000 */  nop
