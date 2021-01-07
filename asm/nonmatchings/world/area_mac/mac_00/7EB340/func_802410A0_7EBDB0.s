.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410A0_7EBDB0
/* 7EBDB0 802410A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EBDB4 802410A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EBDB8 802410A8 8C82000C */  lw        $v0, 0xc($a0)
/* 7EBDBC 802410AC 0C0B1EAF */  jal       get_variable
/* 7EBDC0 802410B0 8C450000 */   lw       $a1, ($v0)
/* 7EBDC4 802410B4 0040202D */  daddu     $a0, $v0, $zero
/* 7EBDC8 802410B8 3C028025 */  lui       $v0, %hi(D_80255B90)
/* 7EBDCC 802410BC 8C425B90 */  lw        $v0, %lo(D_80255B90)($v0)
/* 7EBDD0 802410C0 24030001 */  addiu     $v1, $zero, 1
/* 7EBDD4 802410C4 8C45000C */  lw        $a1, 0xc($v0)
/* 7EBDD8 802410C8 1083000D */  beq       $a0, $v1, .L80241100
/* 7EBDDC 802410CC 28820002 */   slti     $v0, $a0, 2
/* 7EBDE0 802410D0 10400005 */  beqz      $v0, .L802410E8
/* 7EBDE4 802410D4 24020002 */   addiu    $v0, $zero, 2
/* 7EBDE8 802410D8 10800007 */  beqz      $a0, .L802410F8
/* 7EBDEC 802410DC 240200C0 */   addiu    $v0, $zero, 0xc0
/* 7EBDF0 802410E0 08090444 */  j         .L80241110
/* 7EBDF4 802410E4 ACA00038 */   sw       $zero, 0x38($a1)
.L802410E8:
/* 7EBDF8 802410E8 10820008 */  beq       $a0, $v0, .L8024110C
/* 7EBDFC 802410EC 24020040 */   addiu    $v0, $zero, 0x40
/* 7EBE00 802410F0 08090444 */  j         .L80241110
/* 7EBE04 802410F4 ACA00038 */   sw       $zero, 0x38($a1)
.L802410F8:
/* 7EBE08 802410F8 08090444 */  j         .L80241110
/* 7EBE0C 802410FC ACA20038 */   sw       $v0, 0x38($a1)
.L80241100:
/* 7EBE10 80241100 24020080 */  addiu     $v0, $zero, 0x80
/* 7EBE14 80241104 08090444 */  j         .L80241110
/* 7EBE18 80241108 ACA20038 */   sw       $v0, 0x38($a1)
.L8024110C:
/* 7EBE1C 8024110C ACA20038 */  sw        $v0, 0x38($a1)
.L80241110:
/* 7EBE20 80241110 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EBE24 80241114 24020002 */  addiu     $v0, $zero, 2
/* 7EBE28 80241118 03E00008 */  jr        $ra
/* 7EBE2C 8024111C 27BD0018 */   addiu    $sp, $sp, 0x18
