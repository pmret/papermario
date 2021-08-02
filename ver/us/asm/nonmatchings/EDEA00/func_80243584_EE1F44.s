.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243584_EE1F44
/* EE1F44 80243584 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EE1F48 80243588 AFB20028 */  sw        $s2, 0x28($sp)
/* EE1F4C 8024358C 0080902D */  daddu     $s2, $a0, $zero
/* EE1F50 80243590 AFB00020 */  sw        $s0, 0x20($sp)
/* EE1F54 80243594 00A0802D */  daddu     $s0, $a1, $zero
/* EE1F58 80243598 0000202D */  daddu     $a0, $zero, $zero
/* EE1F5C 8024359C AFBF002C */  sw        $ra, 0x2c($sp)
/* EE1F60 802435A0 0C00F92F */  jal       dead_get_npc_unsafe
/* EE1F64 802435A4 AFB10024 */   sw       $s1, 0x24($sp)
/* EE1F68 802435A8 12000002 */  beqz      $s0, .L802435B4
/* EE1F6C 802435AC 0040282D */   daddu    $a1, $v0, $zero
/* EE1F70 802435B0 AE400070 */  sw        $zero, 0x70($s2)
.L802435B4:
/* EE1F74 802435B4 3C026666 */  lui       $v0, 0x6666
/* EE1F78 802435B8 8E440070 */  lw        $a0, 0x70($s2)
/* EE1F7C 802435BC 34426667 */  ori       $v0, $v0, 0x6667
/* EE1F80 802435C0 00820018 */  mult      $a0, $v0
/* EE1F84 802435C4 000417C3 */  sra       $v0, $a0, 0x1f
/* EE1F88 802435C8 00004010 */  mfhi      $t0
/* EE1F8C 802435CC 00081843 */  sra       $v1, $t0, 1
/* EE1F90 802435D0 00621823 */  subu      $v1, $v1, $v0
/* EE1F94 802435D4 00031080 */  sll       $v0, $v1, 2
/* EE1F98 802435D8 00431021 */  addu      $v0, $v0, $v1
/* EE1F9C 802435DC 1482001B */  bne       $a0, $v0, .L8024364C
/* EE1FA0 802435E0 3C020020 */   lui      $v0, 0x20
/* EE1FA4 802435E4 34420002 */  ori       $v0, $v0, 2
/* EE1FA8 802435E8 27B1001A */  addiu     $s1, $sp, 0x1a
/* EE1FAC 802435EC 27B00018 */  addiu     $s0, $sp, 0x18
/* EE1FB0 802435F0 AFB10010 */  sw        $s1, 0x10($sp)
/* EE1FB4 802435F4 AFA20014 */  sw        $v0, 0x14($sp)
/* EE1FB8 802435F8 8CA60040 */  lw        $a2, 0x40($a1)
/* EE1FBC 802435FC C4AC0038 */  lwc1      $f12, 0x38($a1)
/* EE1FC0 80243600 C4AE003C */  lwc1      $f14, 0x3c($a1)
/* EE1FC4 80243604 0C055D37 */  jal       func_801574DC
/* EE1FC8 80243608 0200382D */   daddu    $a3, $s0, $zero
/* EE1FCC 8024360C 0000202D */  daddu     $a0, $zero, $zero
/* EE1FD0 80243610 3C0543FA */  lui       $a1, 0x43fa
/* EE1FD4 80243614 24020050 */  addiu     $v0, $zero, 0x50
/* EE1FD8 80243618 AFA20010 */  sw        $v0, 0x10($sp)
/* EE1FDC 8024361C 8E470070 */  lw        $a3, 0x70($s2)
/* EE1FE0 80243620 0C00ADA9 */  jal       func_8002B6A4
/* EE1FE4 80243624 0000302D */   daddu    $a2, $zero, $zero
/* EE1FE8 80243628 24040295 */  addiu     $a0, $zero, 0x295
/* EE1FEC 8024362C 4600008D */  trunc.w.s $f2, $f0
/* EE1FF0 80243630 44071000 */  mfc1      $a3, $f2
/* EE1FF4 80243634 00000000 */  nop
/* EE1FF8 80243638 00073C00 */  sll       $a3, $a3, 0x10
/* EE1FFC 8024363C 92050001 */  lbu       $a1, 1($s0)
/* EE2000 80243640 92260001 */  lbu       $a2, 1($s1)
/* EE2004 80243644 0C055C46 */  jal       func_80157118
/* EE2008 80243648 00073C03 */   sra      $a3, $a3, 0x10
.L8024364C:
/* EE200C 8024364C 8E430070 */  lw        $v1, 0x70($s2)
/* EE2010 80243650 24630001 */  addiu     $v1, $v1, 1
/* EE2014 80243654 28620051 */  slti      $v0, $v1, 0x51
/* EE2018 80243658 38420001 */  xori      $v0, $v0, 1
/* EE201C 8024365C AE430070 */  sw        $v1, 0x70($s2)
/* EE2020 80243660 8FBF002C */  lw        $ra, 0x2c($sp)
/* EE2024 80243664 8FB20028 */  lw        $s2, 0x28($sp)
/* EE2028 80243668 8FB10024 */  lw        $s1, 0x24($sp)
/* EE202C 8024366C 8FB00020 */  lw        $s0, 0x20($sp)
/* EE2030 80243670 00021040 */  sll       $v0, $v0, 1
/* EE2034 80243674 03E00008 */  jr        $ra
/* EE2038 80243678 27BD0030 */   addiu    $sp, $sp, 0x30
/* EE203C 8024367C 00000000 */  nop
