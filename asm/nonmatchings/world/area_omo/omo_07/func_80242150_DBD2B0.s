.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242150_DBF400
/* DBF400 80242150 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DBF404 80242154 AFB3001C */  sw        $s3, 0x1c($sp)
/* DBF408 80242158 0080982D */  daddu     $s3, $a0, $zero
/* DBF40C 8024215C AFBF0020 */  sw        $ra, 0x20($sp)
/* DBF410 80242160 AFB20018 */  sw        $s2, 0x18($sp)
/* DBF414 80242164 AFB10014 */  sw        $s1, 0x14($sp)
/* DBF418 80242168 AFB00010 */  sw        $s0, 0x10($sp)
/* DBF41C 8024216C 8E720148 */  lw        $s2, 0x148($s3)
/* DBF420 80242170 86440008 */  lh        $a0, 8($s2)
/* DBF424 80242174 0C00EABB */  jal       get_npc_unsafe
/* DBF428 80242178 00A0882D */   daddu    $s1, $a1, $zero
/* DBF42C 8024217C 8E240008 */  lw        $a0, 8($s1)
/* DBF430 80242180 0040802D */  daddu     $s0, $v0, $zero
/* DBF434 80242184 00041FC2 */  srl       $v1, $a0, 0x1f
/* DBF438 80242188 00832021 */  addu      $a0, $a0, $v1
/* DBF43C 8024218C 00042043 */  sra       $a0, $a0, 1
/* DBF440 80242190 0C00A67F */  jal       rand_int
/* DBF444 80242194 24840001 */   addiu    $a0, $a0, 1
/* DBF448 80242198 8E230008 */  lw        $v1, 8($s1)
/* DBF44C 8024219C 240400B4 */  addiu     $a0, $zero, 0xb4
/* DBF450 802421A0 00032FC2 */  srl       $a1, $v1, 0x1f
/* DBF454 802421A4 00651821 */  addu      $v1, $v1, $a1
/* DBF458 802421A8 00031843 */  sra       $v1, $v1, 1
/* DBF45C 802421AC 00621821 */  addu      $v1, $v1, $v0
/* DBF460 802421B0 0C00A67F */  jal       rand_int
/* DBF464 802421B4 A603008E */   sh       $v1, 0x8e($s0)
/* DBF468 802421B8 C60C000C */  lwc1      $f12, 0xc($s0)
/* DBF46C 802421BC 44820000 */  mtc1      $v0, $f0
/* DBF470 802421C0 00000000 */  nop       
/* DBF474 802421C4 46800020 */  cvt.s.w   $f0, $f0
/* DBF478 802421C8 46006300 */  add.s     $f12, $f12, $f0
/* DBF47C 802421CC 3C0142B4 */  lui       $at, 0x42b4
/* DBF480 802421D0 44810000 */  mtc1      $at, $f0
/* DBF484 802421D4 0C00A6C9 */  jal       clamp_angle
/* DBF488 802421D8 46006301 */   sub.s    $f12, $f12, $f0
/* DBF48C 802421DC E600000C */  swc1      $f0, 0xc($s0)
/* DBF490 802421E0 8E4200CC */  lw        $v0, 0xcc($s2)
/* DBF494 802421E4 8C420000 */  lw        $v0, ($v0)
/* DBF498 802421E8 AE020028 */  sw        $v0, 0x28($s0)
/* DBF49C 802421EC 24020003 */  addiu     $v0, $zero, 3
/* DBF4A0 802421F0 AE620070 */  sw        $v0, 0x70($s3)
/* DBF4A4 802421F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* DBF4A8 802421F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* DBF4AC 802421FC 8FB20018 */  lw        $s2, 0x18($sp)
/* DBF4B0 80242200 8FB10014 */  lw        $s1, 0x14($sp)
/* DBF4B4 80242204 8FB00010 */  lw        $s0, 0x10($sp)
/* DBF4B8 80242208 03E00008 */  jr        $ra
/* DBF4BC 8024220C 27BD0028 */   addiu    $sp, $sp, 0x28
