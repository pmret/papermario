.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_AD62C0
/* AD62C0 802403F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AD62C4 802403F4 AFB00010 */  sw        $s0, 0x10($sp)
/* AD62C8 802403F8 0080802D */  daddu     $s0, $a0, $zero
/* AD62CC 802403FC 10A00002 */  beqz      $a1, .L80240408
/* AD62D0 80240400 AFBF0014 */   sw       $ra, 0x14($sp)
/* AD62D4 80240404 AE000074 */  sw        $zero, 0x74($s0)
.L80240408:
/* AD62D8 80240408 8E020074 */  lw        $v0, 0x74($s0)
/* AD62DC 8024040C 24420040 */  addiu     $v0, $v0, 0x40
/* AD62E0 80240410 AE020074 */  sw        $v0, 0x74($s0)
/* AD62E4 80240414 28420100 */  slti      $v0, $v0, 0x100
/* AD62E8 80240418 14400003 */  bnez      $v0, .L80240428
/* AD62EC 8024041C 0000202D */   daddu    $a0, $zero, $zero
/* AD62F0 80240420 240200FF */  addiu     $v0, $zero, 0xff
/* AD62F4 80240424 AE020074 */  sw        $v0, 0x74($s0)
.L80240428:
/* AD62F8 80240428 240500A0 */  addiu     $a1, $zero, 0xa0
/* AD62FC 8024042C 00A0302D */  daddu     $a2, $a1, $zero
/* AD6300 80240430 0C04DF84 */  jal       set_screen_overlay_color
/* AD6304 80240434 00A0382D */   daddu    $a3, $a1, $zero
/* AD6308 80240438 C6000074 */  lwc1      $f0, 0x74($s0)
/* AD630C 8024043C 46800020 */  cvt.s.w   $f0, $f0
/* AD6310 80240440 44050000 */  mfc1      $a1, $f0
/* AD6314 80240444 0C04DF62 */  jal       set_screen_overlay_params_front
/* AD6318 80240448 24040001 */   addiu    $a0, $zero, 1
/* AD631C 8024044C 8E020074 */  lw        $v0, 0x74($s0)
/* AD6320 80240450 8FBF0014 */  lw        $ra, 0x14($sp)
/* AD6324 80240454 8FB00010 */  lw        $s0, 0x10($sp)
/* AD6328 80240458 384200FF */  xori      $v0, $v0, 0xff
/* AD632C 8024045C 2C420001 */  sltiu     $v0, $v0, 1
/* AD6330 80240460 00021040 */  sll       $v0, $v0, 1
/* AD6334 80240464 03E00008 */  jr        $ra
/* AD6338 80240468 27BD0018 */   addiu    $sp, $sp, 0x18
