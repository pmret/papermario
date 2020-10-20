.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404AC_94637C
/* 94637C 802404AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 946380 802404B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 946384 802404B4 0080882D */  daddu     $s1, $a0, $zero
/* 946388 802404B8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 94638C 802404BC AFB00010 */  sw        $s0, 0x10($sp)
/* 946390 802404C0 8E30000C */  lw        $s0, 0xc($s1)
/* 946394 802404C4 8E050000 */  lw        $a1, ($s0)
/* 946398 802404C8 0C0B1EAF */  jal       get_variable
/* 94639C 802404CC 26100004 */   addiu    $s0, $s0, 4
/* 9463A0 802404D0 AE22008C */  sw        $v0, 0x8c($s1)
/* 9463A4 802404D4 8E050000 */  lw        $a1, ($s0)
/* 9463A8 802404D8 26100004 */  addiu     $s0, $s0, 4
/* 9463AC 802404DC 0C0B1EAF */  jal       get_variable
/* 9463B0 802404E0 0220202D */   daddu    $a0, $s1, $zero
/* 9463B4 802404E4 AE220090 */  sw        $v0, 0x90($s1)
/* 9463B8 802404E8 8E050000 */  lw        $a1, ($s0)
/* 9463BC 802404EC 26100004 */  addiu     $s0, $s0, 4
/* 9463C0 802404F0 0C0B1EAF */  jal       get_variable
/* 9463C4 802404F4 0220202D */   daddu    $a0, $s1, $zero
/* 9463C8 802404F8 AE220094 */  sw        $v0, 0x94($s1)
/* 9463CC 802404FC 8E050000 */  lw        $a1, ($s0)
/* 9463D0 80240500 26100004 */  addiu     $s0, $s0, 4
/* 9463D4 80240504 0C0B1EAF */  jal       get_variable
/* 9463D8 80240508 0220202D */   daddu    $a0, $s1, $zero
/* 9463DC 8024050C AE220098 */  sw        $v0, 0x98($s1)
/* 9463E0 80240510 8E050000 */  lw        $a1, ($s0)
/* 9463E4 80240514 26100004 */  addiu     $s0, $s0, 4
/* 9463E8 80240518 0C0B1EAF */  jal       get_variable
/* 9463EC 8024051C 0220202D */   daddu    $a0, $s1, $zero
/* 9463F0 80240520 AE22009C */  sw        $v0, 0x9c($s1)
/* 9463F4 80240524 8E050000 */  lw        $a1, ($s0)
/* 9463F8 80240528 26100004 */  addiu     $s0, $s0, 4
/* 9463FC 8024052C 0C0B1EAF */  jal       get_variable
/* 946400 80240530 0220202D */   daddu    $a0, $s1, $zero
/* 946404 80240534 AE2200A0 */  sw        $v0, 0xa0($s1)
/* 946408 80240538 8E050000 */  lw        $a1, ($s0)
/* 94640C 8024053C 26100004 */  addiu     $s0, $s0, 4
/* 946410 80240540 0C0B1EAF */  jal       get_variable
/* 946414 80240544 0220202D */   daddu    $a0, $s1, $zero
/* 946418 80240548 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 94641C 8024054C 8E050000 */  lw        $a1, ($s0)
/* 946420 80240550 26100004 */  addiu     $s0, $s0, 4
/* 946424 80240554 0C0B1EAF */  jal       get_variable
/* 946428 80240558 0220202D */   daddu    $a0, $s1, $zero
/* 94642C 8024055C AE2200A8 */  sw        $v0, 0xa8($s1)
/* 946430 80240560 8E050000 */  lw        $a1, ($s0)
/* 946434 80240564 26100004 */  addiu     $s0, $s0, 4
/* 946438 80240568 0C0B1EAF */  jal       get_variable
/* 94643C 8024056C 0220202D */   daddu    $a0, $s1, $zero
/* 946440 80240570 AE2200AC */  sw        $v0, 0xac($s1)
/* 946444 80240574 8E050000 */  lw        $a1, ($s0)
/* 946448 80240578 0C0B1EAF */  jal       get_variable
/* 94644C 8024057C 0220202D */   daddu    $a0, $s1, $zero
/* 946450 80240580 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 946454 80240584 8FBF0018 */  lw        $ra, 0x18($sp)
/* 946458 80240588 8FB10014 */  lw        $s1, 0x14($sp)
/* 94645C 8024058C 8FB00010 */  lw        $s0, 0x10($sp)
/* 946460 80240590 24020002 */  addiu     $v0, $zero, 2
/* 946464 80240594 03E00008 */  jr        $ra
/* 946468 80240598 27BD0020 */   addiu    $sp, $sp, 0x20
