.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CA988
/* EF338 802CA988 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EF33C 802CA98C AFB20018 */  sw        $s2, 0x18($sp)
/* EF340 802CA990 0080902D */  daddu     $s2, $a0, $zero
/* EF344 802CA994 AFBF0028 */  sw        $ra, 0x28($sp)
/* EF348 802CA998 AFB50024 */  sw        $s5, 0x24($sp)
/* EF34C 802CA99C AFB40020 */  sw        $s4, 0x20($sp)
/* EF350 802CA9A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* EF354 802CA9A4 AFB10014 */  sw        $s1, 0x14($sp)
/* EF358 802CA9A8 AFB00010 */  sw        $s0, 0x10($sp)
/* EF35C 802CA9AC 8E50000C */  lw        $s0, 0xc($s2)
/* EF360 802CA9B0 8E050000 */  lw        $a1, ($s0)
/* EF364 802CA9B4 0C0B1EAF */  jal       get_variable
/* EF368 802CA9B8 26100004 */   addiu    $s0, $s0, 4
/* EF36C 802CA9BC 8E140000 */  lw        $s4, ($s0)
/* EF370 802CA9C0 26100004 */  addiu     $s0, $s0, 4
/* EF374 802CA9C4 8E150000 */  lw        $s5, ($s0)
/* EF378 802CA9C8 26100004 */  addiu     $s0, $s0, 4
/* EF37C 802CA9CC 3C04800B */  lui       $a0, %hi(gCameras)
/* EF380 802CA9D0 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* EF384 802CA9D4 00021880 */  sll       $v1, $v0, 2
/* EF388 802CA9D8 00621821 */  addu      $v1, $v1, $v0
/* EF38C 802CA9DC 00031880 */  sll       $v1, $v1, 2
/* EF390 802CA9E0 00621823 */  subu      $v1, $v1, $v0
/* EF394 802CA9E4 000310C0 */  sll       $v0, $v1, 3
/* EF398 802CA9E8 00621821 */  addu      $v1, $v1, $v0
/* EF39C 802CA9EC 000318C0 */  sll       $v1, $v1, 3
/* EF3A0 802CA9F0 00648821 */  addu      $s1, $v1, $a0
/* EF3A4 802CA9F4 C62C0094 */  lwc1      $f12, 0x94($s1)
/* EF3A8 802CA9F8 8E130000 */  lw        $s3, ($s0)
/* EF3AC 802CA9FC 8E100004 */  lw        $s0, 4($s0)
/* EF3B0 802CAA00 24020002 */  addiu     $v0, $zero, 2
/* EF3B4 802CAA04 A6220004 */  sh        $v0, 4($s1)
/* EF3B8 802CAA08 0C00A6B1 */  jal       round
/* EF3BC 802CAA0C A6200006 */   sh       $zero, 6($s1)
/* EF3C0 802CAA10 C6220048 */  lwc1      $f2, 0x48($s1)
/* EF3C4 802CAA14 C620003C */  lwc1      $f0, 0x3c($s1)
/* EF3C8 802CAA18 46001081 */  sub.s     $f2, $f2, $f0
/* EF3CC 802CAA1C 46021082 */  mul.s     $f2, $f2, $f2
/* EF3D0 802CAA20 00000000 */  nop       
/* EF3D4 802CAA24 C624004C */  lwc1      $f4, 0x4c($s1)
/* EF3D8 802CAA28 C6200040 */  lwc1      $f0, 0x40($s1)
/* EF3DC 802CAA2C 46002101 */  sub.s     $f4, $f4, $f0
/* EF3E0 802CAA30 46042102 */  mul.s     $f4, $f4, $f4
/* EF3E4 802CAA34 00000000 */  nop       
/* EF3E8 802CAA38 C6260050 */  lwc1      $f6, 0x50($s1)
/* EF3EC 802CAA3C C6200044 */  lwc1      $f0, 0x44($s1)
/* EF3F0 802CAA40 46003181 */  sub.s     $f6, $f6, $f0
/* EF3F4 802CAA44 46063182 */  mul.s     $f6, $f6, $f6
/* EF3F8 802CAA48 00000000 */  nop       
/* EF3FC 802CAA4C C6200090 */  lwc1      $f0, 0x90($s1)
/* EF400 802CAA50 46041080 */  add.s     $f2, $f2, $f4
/* EF404 802CAA54 00021023 */  negu      $v0, $v0
/* EF408 802CAA58 A622001C */  sh        $v0, 0x1c($s1)
/* EF40C 802CAA5C 46000007 */  neg.s     $f0, $f0
/* EF410 802CAA60 46061300 */  add.s     $f12, $f2, $f6
/* EF414 802CAA64 4600020D */  trunc.w.s $f8, $f0
/* EF418 802CAA68 44024000 */  mfc1      $v0, $f8
/* EF41C 802CAA6C 46006004 */  sqrt.s    $f0, $f12
/* EF420 802CAA70 46000032 */  c.eq.s    $f0, $f0
/* EF424 802CAA74 00000000 */  nop       
/* EF428 802CAA78 45010003 */  bc1t      .L802CAA88
/* EF42C 802CAA7C A622001E */   sh       $v0, 0x1e($s1)
/* EF430 802CAA80 0C0187BC */  jal       sqrtf
/* EF434 802CAA84 00000000 */   nop      
.L802CAA88:
/* EF438 802CAA88 0C00A6B1 */  jal       round
/* EF43C 802CAA8C 46000306 */   mov.s    $f12, $f0
/* EF440 802CAA90 0240202D */  daddu     $a0, $s2, $zero
/* EF444 802CAA94 8626001C */  lh        $a2, 0x1c($s1)
/* EF448 802CAA98 C6200048 */  lwc1      $f0, 0x48($s1)
/* EF44C 802CAA9C C622004C */  lwc1      $f2, 0x4c($s1)
/* EF450 802CAAA0 C6240050 */  lwc1      $f4, 0x50($s1)
/* EF454 802CAAA4 0280282D */  daddu     $a1, $s4, $zero
/* EF458 802CAAA8 A6220020 */  sh        $v0, 0x20($s1)
/* EF45C 802CAAAC A6200022 */  sh        $zero, 0x22($s1)
/* EF460 802CAAB0 E6200054 */  swc1      $f0, 0x54($s1)
/* EF464 802CAAB4 E6220058 */  swc1      $f2, 0x58($s1)
/* EF468 802CAAB8 0C0B2026 */  jal       set_variable
/* EF46C 802CAABC E624005C */   swc1     $f4, 0x5c($s1)
/* EF470 802CAAC0 0240202D */  daddu     $a0, $s2, $zero
/* EF474 802CAAC4 8626001E */  lh        $a2, 0x1e($s1)
/* EF478 802CAAC8 0C0B2026 */  jal       set_variable
/* EF47C 802CAACC 02A0282D */   daddu    $a1, $s5, $zero
/* EF480 802CAAD0 0240202D */  daddu     $a0, $s2, $zero
/* EF484 802CAAD4 86260020 */  lh        $a2, 0x20($s1)
/* EF488 802CAAD8 0C0B2026 */  jal       set_variable
/* EF48C 802CAADC 0260282D */   daddu    $a1, $s3, $zero
/* EF490 802CAAE0 0240202D */  daddu     $a0, $s2, $zero
/* EF494 802CAAE4 86260022 */  lh        $a2, 0x22($s1)
/* EF498 802CAAE8 0C0B2026 */  jal       set_variable
/* EF49C 802CAAEC 0200282D */   daddu    $a1, $s0, $zero
/* EF4A0 802CAAF0 8FBF0028 */  lw        $ra, 0x28($sp)
/* EF4A4 802CAAF4 8FB50024 */  lw        $s5, 0x24($sp)
/* EF4A8 802CAAF8 8FB40020 */  lw        $s4, 0x20($sp)
/* EF4AC 802CAAFC 8FB3001C */  lw        $s3, 0x1c($sp)
/* EF4B0 802CAB00 8FB20018 */  lw        $s2, 0x18($sp)
/* EF4B4 802CAB04 8FB10014 */  lw        $s1, 0x14($sp)
/* EF4B8 802CAB08 8FB00010 */  lw        $s0, 0x10($sp)
/* EF4BC 802CAB0C 24020002 */  addiu     $v0, $zero, 2
/* EF4C0 802CAB10 03E00008 */  jr        $ra
/* EF4C4 802CAB14 27BD0030 */   addiu    $sp, $sp, 0x30
