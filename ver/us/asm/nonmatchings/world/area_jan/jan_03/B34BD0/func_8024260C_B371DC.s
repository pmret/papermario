.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024260C_B371DC
/* B371DC 8024260C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B371E0 80242610 AFBF0010 */  sw        $ra, 0x10($sp)
/* B371E4 80242614 8C82000C */  lw        $v0, 0xc($a0)
/* B371E8 80242618 0C0B1EAF */  jal       evt_get_variable
/* B371EC 8024261C 8C450000 */   lw       $a1, ($v0)
/* B371F0 80242620 0040202D */  daddu     $a0, $v0, $zero
/* B371F4 80242624 3C028025 */  lui       $v0, %hi(D_8024FEF8)
/* B371F8 80242628 8C42FEF8 */  lw        $v0, %lo(D_8024FEF8)($v0)
/* B371FC 8024262C 24030001 */  addiu     $v1, $zero, 1
/* B37200 80242630 8C45000C */  lw        $a1, 0xc($v0)
/* B37204 80242634 1083000D */  beq       $a0, $v1, .L8024266C
/* B37208 80242638 28820002 */   slti     $v0, $a0, 2
/* B3720C 8024263C 10400005 */  beqz      $v0, .L80242654
/* B37210 80242640 24020002 */   addiu    $v0, $zero, 2
/* B37214 80242644 10800007 */  beqz      $a0, .L80242664
/* B37218 80242648 240200C0 */   addiu    $v0, $zero, 0xc0
/* B3721C 8024264C 0809099F */  j         .L8024267C
/* B37220 80242650 ACA00038 */   sw       $zero, 0x38($a1)
.L80242654:
/* B37224 80242654 10820008 */  beq       $a0, $v0, .L80242678
/* B37228 80242658 24020040 */   addiu    $v0, $zero, 0x40
/* B3722C 8024265C 0809099F */  j         .L8024267C
/* B37230 80242660 ACA00038 */   sw       $zero, 0x38($a1)
.L80242664:
/* B37234 80242664 0809099F */  j         .L8024267C
/* B37238 80242668 ACA20038 */   sw       $v0, 0x38($a1)
.L8024266C:
/* B3723C 8024266C 24020080 */  addiu     $v0, $zero, 0x80
/* B37240 80242670 0809099F */  j         .L8024267C
/* B37244 80242674 ACA20038 */   sw       $v0, 0x38($a1)
.L80242678:
/* B37248 80242678 ACA20038 */  sw        $v0, 0x38($a1)
.L8024267C:
/* B3724C 8024267C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B37250 80242680 24020002 */  addiu     $v0, $zero, 2
/* B37254 80242684 03E00008 */  jr        $ra
/* B37258 80242688 27BD0018 */   addiu    $sp, $sp, 0x18
