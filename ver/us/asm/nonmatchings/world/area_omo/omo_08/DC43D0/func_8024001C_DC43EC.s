.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_DC43EC
/* DC43EC 8024001C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DC43F0 80240020 AFB10014 */  sw        $s1, 0x14($sp)
/* DC43F4 80240024 0080882D */  daddu     $s1, $a0, $zero
/* DC43F8 80240028 AFBF001C */  sw        $ra, 0x1c($sp)
/* DC43FC 8024002C AFB20018 */  sw        $s2, 0x18($sp)
/* DC4400 80240030 AFB00010 */  sw        $s0, 0x10($sp)
/* DC4404 80240034 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DC4408 80240038 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DC440C 8024003C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DC4410 80240040 8E30000C */  lw        $s0, 0xc($s1)
/* DC4414 80240044 8E120000 */  lw        $s2, ($s0)
/* DC4418 80240048 26100004 */  addiu     $s0, $s0, 4
/* DC441C 8024004C 8E050000 */  lw        $a1, ($s0)
/* DC4420 80240050 0C0B210B */  jal       get_float_variable
/* DC4424 80240054 26100004 */   addiu    $s0, $s0, 4
/* DC4428 80240058 8E050000 */  lw        $a1, ($s0)
/* DC442C 8024005C 26100004 */  addiu     $s0, $s0, 4
/* DC4430 80240060 0220202D */  daddu     $a0, $s1, $zero
/* DC4434 80240064 0C0B210B */  jal       get_float_variable
/* DC4438 80240068 46000606 */   mov.s    $f24, $f0
/* DC443C 8024006C 8E050000 */  lw        $a1, ($s0)
/* DC4440 80240070 26100004 */  addiu     $s0, $s0, 4
/* DC4444 80240074 0220202D */  daddu     $a0, $s1, $zero
/* DC4448 80240078 0C0B210B */  jal       get_float_variable
/* DC444C 8024007C 46000586 */   mov.s    $f22, $f0
/* DC4450 80240080 0220202D */  daddu     $a0, $s1, $zero
/* DC4454 80240084 8E050000 */  lw        $a1, ($s0)
/* DC4458 80240088 0C0B210B */  jal       get_float_variable
/* DC445C 8024008C 46000506 */   mov.s    $f20, $f0
/* DC4460 80240090 4600C306 */  mov.s     $f12, $f24
/* DC4464 80240094 4406A000 */  mfc1      $a2, $f20
/* DC4468 80240098 44070000 */  mfc1      $a3, $f0
/* DC446C 8024009C 0C00A720 */  jal       atan2
/* DC4470 802400A0 4600B386 */   mov.s    $f14, $f22
/* DC4474 802400A4 0C00A6C9 */  jal       clamp_angle
/* DC4478 802400A8 46000306 */   mov.s    $f12, $f0
/* DC447C 802400AC 0220202D */  daddu     $a0, $s1, $zero
/* DC4480 802400B0 44060000 */  mfc1      $a2, $f0
/* DC4484 802400B4 0C0B2190 */  jal       set_float_variable
/* DC4488 802400B8 0240282D */   daddu    $a1, $s2, $zero
/* DC448C 802400BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* DC4490 802400C0 8FB20018 */  lw        $s2, 0x18($sp)
/* DC4494 802400C4 8FB10014 */  lw        $s1, 0x14($sp)
/* DC4498 802400C8 8FB00010 */  lw        $s0, 0x10($sp)
/* DC449C 802400CC D7B80030 */  ldc1      $f24, 0x30($sp)
/* DC44A0 802400D0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DC44A4 802400D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DC44A8 802400D8 24020002 */  addiu     $v0, $zero, 2
/* DC44AC 802400DC 03E00008 */  jr        $ra
/* DC44B0 802400E0 27BD0038 */   addiu    $sp, $sp, 0x38
