.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD26C
/* 32533C 802BD26C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 325340 802BD270 AFB1001C */  sw        $s1, 0x1c($sp)
/* 325344 802BD274 0080882D */  daddu     $s1, $a0, $zero
/* 325348 802BD278 AFBF0028 */  sw        $ra, 0x28($sp)
/* 32534C 802BD27C AFB30024 */  sw        $s3, 0x24($sp)
/* 325350 802BD280 AFB20020 */  sw        $s2, 0x20($sp)
/* 325354 802BD284 AFB00018 */  sw        $s0, 0x18($sp)
/* 325358 802BD288 8E30000C */  lw        $s0, 0xc($s1)
/* 32535C 802BD28C 8E050000 */  lw        $a1, ($s0)
/* 325360 802BD290 0C0B1EAF */  jal       get_variable
/* 325364 802BD294 26100004 */   addiu    $s0, $s0, 4
/* 325368 802BD298 8E050000 */  lw        $a1, ($s0)
/* 32536C 802BD29C 26100004 */  addiu     $s0, $s0, 4
/* 325370 802BD2A0 0220202D */  daddu     $a0, $s1, $zero
/* 325374 802BD2A4 0C0B1EAF */  jal       get_variable
/* 325378 802BD2A8 0040982D */   daddu    $s3, $v0, $zero
/* 32537C 802BD2AC 8E050000 */  lw        $a1, ($s0)
/* 325380 802BD2B0 26100004 */  addiu     $s0, $s0, 4
/* 325384 802BD2B4 0220202D */  daddu     $a0, $s1, $zero
/* 325388 802BD2B8 0C0B1EAF */  jal       get_variable
/* 32538C 802BD2BC 0040902D */   daddu    $s2, $v0, $zero
/* 325390 802BD2C0 0220202D */  daddu     $a0, $s1, $zero
/* 325394 802BD2C4 8E050000 */  lw        $a1, ($s0)
/* 325398 802BD2C8 0C0B1EAF */  jal       get_variable
/* 32539C 802BD2CC 0040802D */   daddu    $s0, $v0, $zero
/* 3253A0 802BD2D0 44930000 */  mtc1      $s3, $f0
/* 3253A4 802BD2D4 00000000 */  nop       
/* 3253A8 802BD2D8 46800020 */  cvt.s.w   $f0, $f0
/* 3253AC 802BD2DC 44050000 */  mfc1      $a1, $f0
/* 3253B0 802BD2E0 44920000 */  mtc1      $s2, $f0
/* 3253B4 802BD2E4 00000000 */  nop       
/* 3253B8 802BD2E8 46800020 */  cvt.s.w   $f0, $f0
/* 3253BC 802BD2EC 44060000 */  mfc1      $a2, $f0
/* 3253C0 802BD2F0 44900000 */  mtc1      $s0, $f0
/* 3253C4 802BD2F4 00000000 */  nop       
/* 3253C8 802BD2F8 46800020 */  cvt.s.w   $f0, $f0
/* 3253CC 802BD2FC 44070000 */  mfc1      $a3, $f0
/* 3253D0 802BD300 24040001 */  addiu     $a0, $zero, 1
/* 3253D4 802BD304 0C01C424 */  jal       func_80071090
/* 3253D8 802BD308 AFA20010 */   sw       $v0, 0x10($sp)
/* 3253DC 802BD30C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 3253E0 802BD310 8FB30024 */  lw        $s3, 0x24($sp)
/* 3253E4 802BD314 8FB20020 */  lw        $s2, 0x20($sp)
/* 3253E8 802BD318 8FB1001C */  lw        $s1, 0x1c($sp)
/* 3253EC 802BD31C 8FB00018 */  lw        $s0, 0x18($sp)
/* 3253F0 802BD320 24020002 */  addiu     $v0, $zero, 2
/* 3253F4 802BD324 03E00008 */  jr        $ra
/* 3253F8 802BD328 27BD0030 */   addiu    $sp, $sp, 0x30
