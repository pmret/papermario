.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024F7C8
/* 17E0A8 8024F7C8 0000382D */  daddu     $a3, $zero, $zero
/* 17E0AC 8024F7CC 24090001 */  addiu     $t1, $zero, 1
/* 17E0B0 8024F7D0 24080014 */  addiu     $t0, $zero, 0x14
/* 17E0B4 8024F7D4 3C06802A */  lui       $a2, %hi(popupMessages)
/* 17E0B8 8024F7D8 24C6F2C0 */  addiu     $a2, $a2, %lo(popupMessages)
.L8024F7DC:
/* 17E0BC 8024F7DC 84C20010 */  lh        $v0, 0x10($a2)
/* 17E0C0 8024F7E0 94C30010 */  lhu       $v1, 0x10($a2)
/* 17E0C4 8024F7E4 10400013 */  beqz      $v0, .L8024F834
/* 17E0C8 8024F7E8 30620010 */   andi     $v0, $v1, 0x10
/* 17E0CC 8024F7EC 50400012 */  beql      $v0, $zero, .L8024F838
/* 17E0D0 8024F7F0 24E70001 */   addiu    $a3, $a3, 1
/* 17E0D4 8024F7F4 84C20012 */  lh        $v0, 0x12($a2)
/* 17E0D8 8024F7F8 8CC40018 */  lw        $a0, 0x18($a2)
/* 17E0DC 8024F7FC 1840000D */  blez      $v0, .L8024F834
/* 17E0E0 8024F800 0000282D */   daddu    $a1, $zero, $zero
/* 17E0E4 8024F804 24830044 */  addiu     $v1, $a0, 0x44
.L8024F808:
/* 17E0E8 8024F808 8C820000 */  lw        $v0, ($a0)
/* 17E0EC 8024F80C 10400004 */  beqz      $v0, .L8024F820
/* 17E0F0 8024F810 24A50001 */   addiu    $a1, $a1, 1
/* 17E0F4 8024F814 AC60FFE0 */  sw        $zero, -0x20($v1)
/* 17E0F8 8024F818 AC69FFDC */  sw        $t1, -0x24($v1)
/* 17E0FC 8024F81C AC680000 */  sw        $t0, ($v1)
.L8024F820:
/* 17E100 8024F820 2463004C */  addiu     $v1, $v1, 0x4c
/* 17E104 8024F824 84C20012 */  lh        $v0, 0x12($a2)
/* 17E108 8024F828 00A2102A */  slt       $v0, $a1, $v0
/* 17E10C 8024F82C 1440FFF6 */  bnez      $v0, .L8024F808
/* 17E110 8024F830 2484004C */   addiu    $a0, $a0, 0x4c
.L8024F834:
/* 17E114 8024F834 24E70001 */  addiu     $a3, $a3, 1
.L8024F838:
/* 17E118 8024F838 28E20020 */  slti      $v0, $a3, 0x20
/* 17E11C 8024F83C 1440FFE7 */  bnez      $v0, .L8024F7DC
/* 17E120 8024F840 24C6001C */   addiu    $a2, $a2, 0x1c
/* 17E124 8024F844 03E00008 */  jr        $ra
/* 17E128 8024F848 00000000 */   nop
