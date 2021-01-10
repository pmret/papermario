.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241648_BE03D8
/* BE03D8 80241648 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BE03DC 8024164C AFBF0010 */  sw        $ra, 0x10($sp)
/* BE03E0 80241650 8C82000C */  lw        $v0, 0xc($a0)
/* BE03E4 80241654 0C0B1EAF */  jal       get_variable
/* BE03E8 80241658 8C450000 */   lw       $a1, ($v0)
/* BE03EC 8024165C 3C018024 */  lui       $at, %hi(D_80241CD0)
/* BE03F0 80241660 AC221CD0 */  sw        $v0, %lo(D_80241CD0)($at)
/* BE03F4 80241664 24020002 */  addiu     $v0, $zero, 2
/* BE03F8 80241668 8FBF0010 */  lw        $ra, 0x10($sp)
/* BE03FC 8024166C 24030001 */  addiu     $v1, $zero, 1
/* BE0400 80241670 3C018024 */  lui       $at, %hi(func_80241CCC_A3B1AC)
/* BE0404 80241674 AC231CCC */  sw        $v1, %lo(func_80241CCC_A3B1AC)($at)
/* BE0408 80241678 03E00008 */  jr        $ra
/* BE040C 8024167C 27BD0018 */   addiu    $sp, $sp, 0x18
