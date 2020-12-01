.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404B4_C7E634
/* C7E634 802404B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7E638 802404B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* C7E63C 802404BC 8C82000C */  lw        $v0, 0xc($a0)
/* C7E640 802404C0 0C0B1EAF */  jal       get_variable
/* C7E644 802404C4 8C450000 */   lw       $a1, ($v0)
/* C7E648 802404C8 44820000 */  mtc1      $v0, $f0
/* C7E64C 802404CC 00000000 */  nop       
/* C7E650 802404D0 46800020 */  cvt.s.w   $f0, $f0
/* C7E654 802404D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C7E658 802404D8 24020002 */  addiu     $v0, $zero, 2
/* C7E65C 802404DC 3C018011 */  lui       $at, %hi(gPlayerStatus+0x8C)
/* C7E660 802404E0 E420F054 */  swc1      $f0, %lo(gPlayerStatus+0x8C)($at)
/* C7E664 802404E4 03E00008 */  jr        $ra
/* C7E668 802404E8 27BD0018 */   addiu    $sp, $sp, 0x18
