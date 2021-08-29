.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417D8_9C6BB8
/* 9C6BB8 802417D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C6BBC 802417DC AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C6BC0 802417E0 8C82000C */  lw        $v0, 0xc($a0)
/* 9C6BC4 802417E4 0C0B1EAF */  jal       evt_get_variable
/* 9C6BC8 802417E8 8C450000 */   lw       $a1, ($v0)
/* 9C6BCC 802417EC 0040202D */  daddu     $a0, $v0, $zero
/* 9C6BD0 802417F0 3C028025 */  lui       $v0, %hi(D_80251C60)
/* 9C6BD4 802417F4 8C421C60 */  lw        $v0, %lo(D_80251C60)($v0)
/* 9C6BD8 802417F8 24030001 */  addiu     $v1, $zero, 1
/* 9C6BDC 802417FC 8C45000C */  lw        $a1, 0xc($v0)
/* 9C6BE0 80241800 1083000D */  beq       $a0, $v1, .L80241838
/* 9C6BE4 80241804 28820002 */   slti     $v0, $a0, 2
/* 9C6BE8 80241808 10400005 */  beqz      $v0, .L80241820
/* 9C6BEC 8024180C 24020002 */   addiu    $v0, $zero, 2
/* 9C6BF0 80241810 10800007 */  beqz      $a0, .L80241830
/* 9C6BF4 80241814 240200C0 */   addiu    $v0, $zero, 0xc0
/* 9C6BF8 80241818 08090612 */  j         .L80241848
/* 9C6BFC 8024181C ACA00038 */   sw       $zero, 0x38($a1)
.L80241820:
/* 9C6C00 80241820 10820008 */  beq       $a0, $v0, .L80241844
/* 9C6C04 80241824 24020040 */   addiu    $v0, $zero, 0x40
/* 9C6C08 80241828 08090612 */  j         .L80241848
/* 9C6C0C 8024182C ACA00038 */   sw       $zero, 0x38($a1)
.L80241830:
/* 9C6C10 80241830 08090612 */  j         .L80241848
/* 9C6C14 80241834 ACA20038 */   sw       $v0, 0x38($a1)
.L80241838:
/* 9C6C18 80241838 24020080 */  addiu     $v0, $zero, 0x80
/* 9C6C1C 8024183C 08090612 */  j         .L80241848
/* 9C6C20 80241840 ACA20038 */   sw       $v0, 0x38($a1)
.L80241844:
/* 9C6C24 80241844 ACA20038 */  sw        $v0, 0x38($a1)
.L80241848:
/* 9C6C28 80241848 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C6C2C 8024184C 24020002 */  addiu     $v0, $zero, 2
/* 9C6C30 80241850 03E00008 */  jr        $ra
/* 9C6C34 80241854 27BD0018 */   addiu    $sp, $sp, 0x18
