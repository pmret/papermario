.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241240_D3B810
/* D3B810 80241240 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3B814 80241244 AFBF0010 */  sw        $ra, 0x10($sp)
/* D3B818 80241248 8C82000C */  lw        $v0, 0xc($a0)
/* D3B81C 8024124C 0C0B1EAF */  jal       get_variable
/* D3B820 80241250 8C450000 */   lw       $a1, ($v0)
/* D3B824 80241254 0040202D */  daddu     $a0, $v0, $zero
/* D3B828 80241258 3C028025 */  lui       $v0, 0x8025
/* D3B82C 8024125C 8C421470 */  lw        $v0, 0x1470($v0)
/* D3B830 80241260 24030001 */  addiu     $v1, $zero, 1
/* D3B834 80241264 8C45000C */  lw        $a1, 0xc($v0)
/* D3B838 80241268 1083000D */  beq       $a0, $v1, .L802412A0
/* D3B83C 8024126C 28820002 */   slti     $v0, $a0, 2
/* D3B840 80241270 10400005 */  beqz      $v0, .L80241288
/* D3B844 80241274 24020002 */   addiu    $v0, $zero, 2
/* D3B848 80241278 10800007 */  beqz      $a0, .L80241298
/* D3B84C 8024127C 240200C0 */   addiu    $v0, $zero, 0xc0
/* D3B850 80241280 080904AC */  j         .L802412B0
/* D3B854 80241284 ACA00038 */   sw       $zero, 0x38($a1)
.L80241288:
/* D3B858 80241288 10820008 */  beq       $a0, $v0, .L802412AC
/* D3B85C 8024128C 24020040 */   addiu    $v0, $zero, 0x40
/* D3B860 80241290 080904AC */  j         .L802412B0
/* D3B864 80241294 ACA00038 */   sw       $zero, 0x38($a1)
.L80241298:
/* D3B868 80241298 080904AC */  j         .L802412B0
/* D3B86C 8024129C ACA20038 */   sw       $v0, 0x38($a1)
.L802412A0:
/* D3B870 802412A0 24020080 */  addiu     $v0, $zero, 0x80
/* D3B874 802412A4 080904AC */  j         .L802412B0
/* D3B878 802412A8 ACA20038 */   sw       $v0, 0x38($a1)
.L802412AC:
/* D3B87C 802412AC ACA20038 */  sw        $v0, 0x38($a1)
.L802412B0:
/* D3B880 802412B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3B884 802412B4 24020002 */  addiu     $v0, $zero, 2
/* D3B888 802412B8 03E00008 */  jr        $ra
/* D3B88C 802412BC 27BD0018 */   addiu    $sp, $sp, 0x18
