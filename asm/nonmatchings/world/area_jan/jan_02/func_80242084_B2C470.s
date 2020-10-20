.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242084_B2E4F4
/* B2E4F4 80242084 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2E4F8 80242088 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2E4FC 8024208C 8C82000C */  lw        $v0, 0xc($a0)
/* B2E500 80242090 0C0B1EAF */  jal       get_variable
/* B2E504 80242094 8C450000 */   lw       $a1, ($v0)
/* B2E508 80242098 0040202D */  daddu     $a0, $v0, $zero
/* B2E50C 8024209C 3C028025 */  lui       $v0, 0x8025
/* B2E510 802420A0 8C428940 */  lw        $v0, -0x76c0($v0)
/* B2E514 802420A4 24030001 */  addiu     $v1, $zero, 1
/* B2E518 802420A8 8C45000C */  lw        $a1, 0xc($v0)
/* B2E51C 802420AC 1083000D */  beq       $a0, $v1, .L802420E4
/* B2E520 802420B0 28820002 */   slti     $v0, $a0, 2
/* B2E524 802420B4 10400005 */  beqz      $v0, .L802420CC
/* B2E528 802420B8 24020002 */   addiu    $v0, $zero, 2
/* B2E52C 802420BC 10800007 */  beqz      $a0, .L802420DC
/* B2E530 802420C0 240200C0 */   addiu    $v0, $zero, 0xc0
/* B2E534 802420C4 0809083D */  j         .L802420F4
/* B2E538 802420C8 ACA00038 */   sw       $zero, 0x38($a1)
.L802420CC:
/* B2E53C 802420CC 10820008 */  beq       $a0, $v0, .L802420F0
/* B2E540 802420D0 24020040 */   addiu    $v0, $zero, 0x40
/* B2E544 802420D4 0809083D */  j         .L802420F4
/* B2E548 802420D8 ACA00038 */   sw       $zero, 0x38($a1)
.L802420DC:
/* B2E54C 802420DC 0809083D */  j         .L802420F4
/* B2E550 802420E0 ACA20038 */   sw       $v0, 0x38($a1)
.L802420E4:
/* B2E554 802420E4 24020080 */  addiu     $v0, $zero, 0x80
/* B2E558 802420E8 0809083D */  j         .L802420F4
/* B2E55C 802420EC ACA20038 */   sw       $v0, 0x38($a1)
.L802420F0:
/* B2E560 802420F0 ACA20038 */  sw        $v0, 0x38($a1)
.L802420F4:
/* B2E564 802420F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2E568 802420F8 24020002 */  addiu     $v0, $zero, 2
/* B2E56C 802420FC 03E00008 */  jr        $ra
/* B2E570 80242100 27BD0018 */   addiu    $sp, $sp, 0x18
