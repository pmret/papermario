.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243470_EE1E30
/* EE1E30 80243470 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EE1E34 80243474 AFB3002C */  sw        $s3, 0x2c($sp)
/* EE1E38 80243478 0080982D */  daddu     $s3, $a0, $zero
/* EE1E3C 8024347C AFB00020 */  sw        $s0, 0x20($sp)
/* EE1E40 80243480 00A0802D */  daddu     $s0, $a1, $zero
/* EE1E44 80243484 24040001 */  addiu     $a0, $zero, 1
/* EE1E48 80243488 AFBF0030 */  sw        $ra, 0x30($sp)
/* EE1E4C 8024348C AFB20028 */  sw        $s2, 0x28($sp)
/* EE1E50 80243490 0C00F92F */  jal       func_8003E4BC
/* EE1E54 80243494 AFB10024 */   sw       $s1, 0x24($sp)
/* EE1E58 80243498 8E63000C */  lw        $v1, 0xc($s3)
/* EE1E5C 8024349C 0260202D */  daddu     $a0, $s3, $zero
/* EE1E60 802434A0 8C650000 */  lw        $a1, ($v1)
/* EE1E64 802434A4 0C0B53A3 */  jal       func_802D4E8C
/* EE1E68 802434A8 0040902D */   daddu    $s2, $v0, $zero
/* EE1E6C 802434AC 12000002 */  beqz      $s0, .L802434B8
/* EE1E70 802434B0 AE620074 */   sw       $v0, 0x74($s3)
/* EE1E74 802434B4 AE600070 */  sw        $zero, 0x70($s3)
.L802434B8:
/* EE1E78 802434B8 3C026666 */  lui       $v0, 0x6666
/* EE1E7C 802434BC 8E640070 */  lw        $a0, 0x70($s3)
/* EE1E80 802434C0 34426667 */  ori       $v0, $v0, 0x6667
/* EE1E84 802434C4 00820018 */  mult      $a0, $v0
/* EE1E88 802434C8 000417C3 */  sra       $v0, $a0, 0x1f
/* EE1E8C 802434CC 00004010 */  mfhi      $t0
/* EE1E90 802434D0 00081843 */  sra       $v1, $t0, 1
/* EE1E94 802434D4 00621823 */  subu      $v1, $v1, $v0
/* EE1E98 802434D8 00031080 */  sll       $v0, $v1, 2
/* EE1E9C 802434DC 00431021 */  addu      $v0, $v0, $v1
/* EE1EA0 802434E0 1482001B */  bne       $a0, $v0, .L80243550
/* EE1EA4 802434E4 3C020020 */   lui      $v0, 0x20
/* EE1EA8 802434E8 34420002 */  ori       $v0, $v0, 2
/* EE1EAC 802434EC 27B1001A */  addiu     $s1, $sp, 0x1a
/* EE1EB0 802434F0 27B00018 */  addiu     $s0, $sp, 0x18
/* EE1EB4 802434F4 AFB10010 */  sw        $s1, 0x10($sp)
/* EE1EB8 802434F8 AFA20014 */  sw        $v0, 0x14($sp)
/* EE1EBC 802434FC 8E460040 */  lw        $a2, 0x40($s2)
/* EE1EC0 80243500 C64C0038 */  lwc1      $f12, 0x38($s2)
/* EE1EC4 80243504 C64E003C */  lwc1      $f14, 0x3c($s2)
/* EE1EC8 80243508 0C055D37 */  jal       func_801574DC
/* EE1ECC 8024350C 0200382D */   daddu    $a3, $s0, $zero
/* EE1ED0 80243510 3C0543FA */  lui       $a1, 0x43fa
/* EE1ED4 80243514 8E620074 */  lw        $v0, 0x74($s3)
/* EE1ED8 80243518 0000202D */  daddu     $a0, $zero, $zero
/* EE1EDC 8024351C AFA20010 */  sw        $v0, 0x10($sp)
/* EE1EE0 80243520 8E670070 */  lw        $a3, 0x70($s3)
/* EE1EE4 80243524 0C00ADA9 */  jal       func_8002B6A4
/* EE1EE8 80243528 0000302D */   daddu    $a2, $zero, $zero
/* EE1EEC 8024352C 24040295 */  addiu     $a0, $zero, 0x295
/* EE1EF0 80243530 4600008D */  trunc.w.s $f2, $f0
/* EE1EF4 80243534 44071000 */  mfc1      $a3, $f2
/* EE1EF8 80243538 00000000 */  nop       
/* EE1EFC 8024353C 00073C00 */  sll       $a3, $a3, 0x10
/* EE1F00 80243540 92050001 */  lbu       $a1, 1($s0)
/* EE1F04 80243544 92260001 */  lbu       $a2, 1($s1)
/* EE1F08 80243548 0C055C46 */  jal       func_80157118
/* EE1F0C 8024354C 00073C03 */   sra      $a3, $a3, 0x10
.L80243550:
/* EE1F10 80243550 8E630070 */  lw        $v1, 0x70($s3)
/* EE1F14 80243554 8E620074 */  lw        $v0, 0x74($s3)
/* EE1F18 80243558 24630001 */  addiu     $v1, $v1, 1
/* EE1F1C 8024355C 0043102A */  slt       $v0, $v0, $v1
/* EE1F20 80243560 AE630070 */  sw        $v1, 0x70($s3)
/* EE1F24 80243564 8FBF0030 */  lw        $ra, 0x30($sp)
/* EE1F28 80243568 8FB3002C */  lw        $s3, 0x2c($sp)
/* EE1F2C 8024356C 8FB20028 */  lw        $s2, 0x28($sp)
/* EE1F30 80243570 8FB10024 */  lw        $s1, 0x24($sp)
/* EE1F34 80243574 8FB00020 */  lw        $s0, 0x20($sp)
/* EE1F38 80243578 00021040 */  sll       $v0, $v0, 1
/* EE1F3C 8024357C 03E00008 */  jr        $ra
/* EE1F40 80243580 27BD0038 */   addiu    $sp, $sp, 0x38
