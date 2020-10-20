.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024046C_AD633C
/* AD633C 8024046C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AD6340 80240470 AFB00010 */  sw        $s0, 0x10($sp)
/* AD6344 80240474 0080802D */  daddu     $s0, $a0, $zero
/* AD6348 80240478 10A00003 */  beqz      $a1, .L80240488
/* AD634C 8024047C AFBF0014 */   sw       $ra, 0x14($sp)
/* AD6350 80240480 240200FF */  addiu     $v0, $zero, 0xff
/* AD6354 80240484 AE020074 */  sw        $v0, 0x74($s0)
.L80240488:
/* AD6358 80240488 8E020074 */  lw        $v0, 0x74($s0)
/* AD635C 8024048C 2442FFC0 */  addiu     $v0, $v0, -0x40
/* AD6360 80240490 1C400002 */  bgtz      $v0, .L8024049C
/* AD6364 80240494 AE020074 */   sw       $v0, 0x74($s0)
/* AD6368 80240498 AE000074 */  sw        $zero, 0x74($s0)
.L8024049C:
/* AD636C 8024049C 0000202D */  daddu     $a0, $zero, $zero
/* AD6370 802404A0 240500A0 */  addiu     $a1, $zero, 0xa0
/* AD6374 802404A4 00A0302D */  daddu     $a2, $a1, $zero
/* AD6378 802404A8 0C04DF84 */  jal       func_80137E10
/* AD637C 802404AC 00A0382D */   daddu    $a3, $a1, $zero
/* AD6380 802404B0 C6000074 */  lwc1      $f0, 0x74($s0)
/* AD6384 802404B4 46800020 */  cvt.s.w   $f0, $f0
/* AD6388 802404B8 44050000 */  mfc1      $a1, $f0
/* AD638C 802404BC 0C04DF62 */  jal       func_80137D88
/* AD6390 802404C0 24040001 */   addiu    $a0, $zero, 1
/* AD6394 802404C4 8E020074 */  lw        $v0, 0x74($s0)
/* AD6398 802404C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* AD639C 802404CC 8FB00010 */  lw        $s0, 0x10($sp)
/* AD63A0 802404D0 2C420001 */  sltiu     $v0, $v0, 1
/* AD63A4 802404D4 00021040 */  sll       $v0, $v0, 1
/* AD63A8 802404D8 03E00008 */  jr        $ra
/* AD63AC 802404DC 27BD0018 */   addiu    $sp, $sp, 0x18
