.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802434D4
/* CC6CE4 802434D4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CC6CE8 802434D8 AFB20028 */  sw        $s2, 0x28($sp)
/* CC6CEC 802434DC 0080902D */  daddu     $s2, $a0, $zero
/* CC6CF0 802434E0 AFB00020 */  sw        $s0, 0x20($sp)
/* CC6CF4 802434E4 00A0802D */  daddu     $s0, $a1, $zero
/* CC6CF8 802434E8 0000202D */  daddu     $a0, $zero, $zero
/* CC6CFC 802434EC AFBF002C */  sw        $ra, 0x2c($sp)
/* CC6D00 802434F0 0C00EABB */  jal       get_npc_unsafe
/* CC6D04 802434F4 AFB10024 */   sw       $s1, 0x24($sp)
/* CC6D08 802434F8 12000002 */  beqz      $s0, .L80243504
/* CC6D0C 802434FC 0040282D */   daddu    $a1, $v0, $zero
/* CC6D10 80243500 AE400070 */  sw        $zero, 0x70($s2)
.L80243504:
/* CC6D14 80243504 3C026666 */  lui       $v0, 0x6666
/* CC6D18 80243508 8E440070 */  lw        $a0, 0x70($s2)
/* CC6D1C 8024350C 34426667 */  ori       $v0, $v0, 0x6667
/* CC6D20 80243510 00820018 */  mult      $a0, $v0
/* CC6D24 80243514 000417C3 */  sra       $v0, $a0, 0x1f
/* CC6D28 80243518 00004010 */  mfhi      $t0
/* CC6D2C 8024351C 00081843 */  sra       $v1, $t0, 1
/* CC6D30 80243520 00621823 */  subu      $v1, $v1, $v0
/* CC6D34 80243524 00031080 */  sll       $v0, $v1, 2
/* CC6D38 80243528 00431021 */  addu      $v0, $v0, $v1
/* CC6D3C 8024352C 1482001B */  bne       $a0, $v0, .L8024359C
/* CC6D40 80243530 3C020020 */   lui      $v0, 0x20
/* CC6D44 80243534 34420002 */  ori       $v0, $v0, 2
/* CC6D48 80243538 27B1001A */  addiu     $s1, $sp, 0x1a
/* CC6D4C 8024353C 27B00018 */  addiu     $s0, $sp, 0x18
/* CC6D50 80243540 AFB10010 */  sw        $s1, 0x10($sp)
/* CC6D54 80243544 AFA20014 */  sw        $v0, 0x14($sp)
/* CC6D58 80243548 8CA60040 */  lw        $a2, 0x40($a1)
/* CC6D5C 8024354C C4AC0038 */  lwc1      $f12, 0x38($a1)
/* CC6D60 80243550 C4AE003C */  lwc1      $f14, 0x3c($a1)
/* CC6D64 80243554 0C052781 */  jal       func_80149E04
/* CC6D68 80243558 0200382D */   daddu    $a3, $s0, $zero
/* CC6D6C 8024355C 0000202D */  daddu     $a0, $zero, $zero
/* CC6D70 80243560 3C0543FA */  lui       $a1, 0x43fa
/* CC6D74 80243564 24020050 */  addiu     $v0, $zero, 0x50
/* CC6D78 80243568 AFA20010 */  sw        $v0, 0x10($sp)
/* CC6D7C 8024356C 8E470070 */  lw        $a3, 0x70($s2)
/* CC6D80 80243570 0C00A8ED */  jal       update_lerp
/* CC6D84 80243574 0000302D */   daddu    $a2, $zero, $zero
/* CC6D88 80243578 24040295 */  addiu     $a0, $zero, 0x295
/* CC6D8C 8024357C 4600008D */  trunc.w.s $f2, $f0
/* CC6D90 80243580 44071000 */  mfc1      $a3, $f2
/* CC6D94 80243584 00000000 */  nop       
/* CC6D98 80243588 00073C00 */  sll       $a3, $a3, 0x10
/* CC6D9C 8024358C 92050001 */  lbu       $a1, 1($s0)
/* CC6DA0 80243590 92260001 */  lbu       $a2, 1($s1)
/* CC6DA4 80243594 0C0526AE */  jal       _play_sound
/* CC6DA8 80243598 00073C03 */   sra      $a3, $a3, 0x10
.L8024359C:
/* CC6DAC 8024359C 8E430070 */  lw        $v1, 0x70($s2)
/* CC6DB0 802435A0 24630001 */  addiu     $v1, $v1, 1
/* CC6DB4 802435A4 28620051 */  slti      $v0, $v1, 0x51
/* CC6DB8 802435A8 38420001 */  xori      $v0, $v0, 1
/* CC6DBC 802435AC AE430070 */  sw        $v1, 0x70($s2)
/* CC6DC0 802435B0 8FBF002C */  lw        $ra, 0x2c($sp)
/* CC6DC4 802435B4 8FB20028 */  lw        $s2, 0x28($sp)
/* CC6DC8 802435B8 8FB10024 */  lw        $s1, 0x24($sp)
/* CC6DCC 802435BC 8FB00020 */  lw        $s0, 0x20($sp)
/* CC6DD0 802435C0 00021040 */  sll       $v0, $v0, 1
/* CC6DD4 802435C4 03E00008 */  jr        $ra
/* CC6DD8 802435C8 27BD0030 */   addiu    $sp, $sp, 0x30
/* CC6DDC 802435CC 00000000 */  nop       
