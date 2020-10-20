.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802433C0
/* CC6BD0 802433C0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CC6BD4 802433C4 AFB3002C */  sw        $s3, 0x2c($sp)
/* CC6BD8 802433C8 0080982D */  daddu     $s3, $a0, $zero
/* CC6BDC 802433CC AFB00020 */  sw        $s0, 0x20($sp)
/* CC6BE0 802433D0 00A0802D */  daddu     $s0, $a1, $zero
/* CC6BE4 802433D4 24040001 */  addiu     $a0, $zero, 1
/* CC6BE8 802433D8 AFBF0030 */  sw        $ra, 0x30($sp)
/* CC6BEC 802433DC AFB20028 */  sw        $s2, 0x28($sp)
/* CC6BF0 802433E0 0C00EABB */  jal       get_npc_unsafe
/* CC6BF4 802433E4 AFB10024 */   sw       $s1, 0x24($sp)
/* CC6BF8 802433E8 8E63000C */  lw        $v1, 0xc($s3)
/* CC6BFC 802433EC 0260202D */  daddu     $a0, $s3, $zero
/* CC6C00 802433F0 8C650000 */  lw        $a1, ($v1)
/* CC6C04 802433F4 0C0B1EAF */  jal       get_variable
/* CC6C08 802433F8 0040902D */   daddu    $s2, $v0, $zero
/* CC6C0C 802433FC 12000002 */  beqz      $s0, .L80243408
/* CC6C10 80243400 AE620074 */   sw       $v0, 0x74($s3)
/* CC6C14 80243404 AE600070 */  sw        $zero, 0x70($s3)
.L80243408:
/* CC6C18 80243408 3C026666 */  lui       $v0, 0x6666
/* CC6C1C 8024340C 8E640070 */  lw        $a0, 0x70($s3)
/* CC6C20 80243410 34426667 */  ori       $v0, $v0, 0x6667
/* CC6C24 80243414 00820018 */  mult      $a0, $v0
/* CC6C28 80243418 000417C3 */  sra       $v0, $a0, 0x1f
/* CC6C2C 8024341C 00004010 */  mfhi      $t0
/* CC6C30 80243420 00081843 */  sra       $v1, $t0, 1
/* CC6C34 80243424 00621823 */  subu      $v1, $v1, $v0
/* CC6C38 80243428 00031080 */  sll       $v0, $v1, 2
/* CC6C3C 8024342C 00431021 */  addu      $v0, $v0, $v1
/* CC6C40 80243430 1482001B */  bne       $a0, $v0, .L802434A0
/* CC6C44 80243434 3C020020 */   lui      $v0, 0x20
/* CC6C48 80243438 34420002 */  ori       $v0, $v0, 2
/* CC6C4C 8024343C 27B1001A */  addiu     $s1, $sp, 0x1a
/* CC6C50 80243440 27B00018 */  addiu     $s0, $sp, 0x18
/* CC6C54 80243444 AFB10010 */  sw        $s1, 0x10($sp)
/* CC6C58 80243448 AFA20014 */  sw        $v0, 0x14($sp)
/* CC6C5C 8024344C 8E460040 */  lw        $a2, 0x40($s2)
/* CC6C60 80243450 C64C0038 */  lwc1      $f12, 0x38($s2)
/* CC6C64 80243454 C64E003C */  lwc1      $f14, 0x3c($s2)
/* CC6C68 80243458 0C052781 */  jal       func_80149E04
/* CC6C6C 8024345C 0200382D */   daddu    $a3, $s0, $zero
/* CC6C70 80243460 3C0543FA */  lui       $a1, 0x43fa
/* CC6C74 80243464 8E620074 */  lw        $v0, 0x74($s3)
/* CC6C78 80243468 0000202D */  daddu     $a0, $zero, $zero
/* CC6C7C 8024346C AFA20010 */  sw        $v0, 0x10($sp)
/* CC6C80 80243470 8E670070 */  lw        $a3, 0x70($s3)
/* CC6C84 80243474 0C00A8ED */  jal       update_lerp
/* CC6C88 80243478 0000302D */   daddu    $a2, $zero, $zero
/* CC6C8C 8024347C 24040295 */  addiu     $a0, $zero, 0x295
/* CC6C90 80243480 4600008D */  trunc.w.s $f2, $f0
/* CC6C94 80243484 44071000 */  mfc1      $a3, $f2
/* CC6C98 80243488 00000000 */  nop       
/* CC6C9C 8024348C 00073C00 */  sll       $a3, $a3, 0x10
/* CC6CA0 80243490 92050001 */  lbu       $a1, 1($s0)
/* CC6CA4 80243494 92260001 */  lbu       $a2, 1($s1)
/* CC6CA8 80243498 0C0526AE */  jal       _play_sound
/* CC6CAC 8024349C 00073C03 */   sra      $a3, $a3, 0x10
.L802434A0:
/* CC6CB0 802434A0 8E630070 */  lw        $v1, 0x70($s3)
/* CC6CB4 802434A4 8E620074 */  lw        $v0, 0x74($s3)
/* CC6CB8 802434A8 24630001 */  addiu     $v1, $v1, 1
/* CC6CBC 802434AC 0043102A */  slt       $v0, $v0, $v1
/* CC6CC0 802434B0 AE630070 */  sw        $v1, 0x70($s3)
/* CC6CC4 802434B4 8FBF0030 */  lw        $ra, 0x30($sp)
/* CC6CC8 802434B8 8FB3002C */  lw        $s3, 0x2c($sp)
/* CC6CCC 802434BC 8FB20028 */  lw        $s2, 0x28($sp)
/* CC6CD0 802434C0 8FB10024 */  lw        $s1, 0x24($sp)
/* CC6CD4 802434C4 8FB00020 */  lw        $s0, 0x20($sp)
/* CC6CD8 802434C8 00021040 */  sll       $v0, $v0, 1
/* CC6CDC 802434CC 03E00008 */  jr        $ra
/* CC6CE0 802434D0 27BD0038 */   addiu    $sp, $sp, 0x38
