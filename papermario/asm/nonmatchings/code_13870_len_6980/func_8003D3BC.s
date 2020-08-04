.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003D3BC
/* 0187BC 8003D3BC 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0187C0 8003D3C0 AFB10024 */  sw    $s1, 0x24($sp)
/* 0187C4 8003D3C4 0080882D */  daddu $s1, $a0, $zero
/* 0187C8 8003D3C8 0000282D */  daddu $a1, $zero, $zero
/* 0187CC 8003D3CC AFBF003C */  sw    $ra, 0x3c($sp)
/* 0187D0 8003D3D0 AFB60038 */  sw    $s6, 0x38($sp)
/* 0187D4 8003D3D4 AFB50034 */  sw    $s5, 0x34($sp)
/* 0187D8 8003D3D8 AFB40030 */  sw    $s4, 0x30($sp)
/* 0187DC 8003D3DC AFB3002C */  sw    $s3, 0x2c($sp)
/* 0187E0 8003D3E0 AFB20028 */  sw    $s2, 0x28($sp)
/* 0187E4 8003D3E4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0187E8 8003D3E8 86340098 */  lh    $s4, 0x98($s1)
/* 0187EC 8003D3EC 8630009A */  lh    $s0, 0x9a($s1)
/* 0187F0 8003D3F0 8635009C */  lh    $s5, 0x9c($s1)
/* 0187F4 8003D3F4 8632009E */  lh    $s2, 0x9e($s1)
/* 0187F8 8003D3F8 863600A0 */  lh    $s6, 0xa0($s1)
/* 0187FC 8003D3FC 963300A2 */  lhu   $s3, 0xa2($s1)
/* 018800 8003D400 00A0302D */  daddu $a2, $a1, $zero
/* 018804 8003D404 AFA00010 */  sw    $zero, 0x10($sp)
/* 018808 8003D408 AFA00014 */  sw    $zero, 0x14($sp)
/* 01880C 8003D40C AFA00018 */  sw    $zero, 0x18($sp)
/* 018810 8003D410 8E240024 */  lw    $a0, 0x24($s1)
/* 018814 8003D414 0C0B7A25 */  jal   func_802DE894
/* 018818 8003D418 00A0382D */   daddu $a3, $a1, $zero
/* 01881C 8003D41C 2E820011 */  sltiu $v0, $s4, 0x11
/* 018820 8003D420 10400076 */  beqz  $v0, .L8003D5FC
/* 018824 8003D424 00141080 */   sll   $v0, $s4, 2
/* 018828 8003D428 3C01800A */  lui   $at, 0x800a
/* 01882C 8003D42C 00220821 */  addu  $at, $at, $v0
/* 018830 8003D430 8C228548 */  lw    $v0, -0x7ab8($at)
/* 018834 8003D434 00400008 */  jr    $v0
/* 018838 8003D438 00000000 */   nop   
/* 01883C 8003D43C 0000282D */  daddu $a1, $zero, $zero
/* 018840 8003D440 00A0302D */  daddu $a2, $a1, $zero
/* 018844 8003D444 2402000D */  addiu $v0, $zero, 0xd
/* 018848 8003D448 A22200AA */  sb    $v0, 0xaa($s1)
/* 01884C 8003D44C AFA00010 */  sw    $zero, 0x10($sp)
/* 018850 8003D450 AFA00014 */  sw    $zero, 0x14($sp)
/* 018854 8003D454 AFB30018 */  sw    $s3, 0x18($sp)
/* 018858 8003D458 8E240024 */  lw    $a0, 0x24($s1)
/* 01885C 8003D45C 0800F57D */  j     .L8003D5F4
/* 018860 8003D460 00A0382D */   daddu $a3, $a1, $zero

/* 018864 8003D464 2402000D */  addiu $v0, $zero, 0xd
/* 018868 8003D468 A22200AA */  sb    $v0, 0xaa($s1)
/* 01886C 8003D46C 0280282D */  daddu $a1, $s4, $zero
/* 018870 8003D470 0000302D */  daddu $a2, $zero, $zero
/* 018874 8003D474 AFA00010 */  sw    $zero, 0x10($sp)
/* 018878 8003D478 AFA00014 */  sw    $zero, 0x14($sp)
/* 01887C 8003D47C AFB30018 */  sw    $s3, 0x18($sp)
/* 018880 8003D480 8E240024 */  lw    $a0, 0x24($s1)
/* 018884 8003D484 0800F57D */  j     .L8003D5F4
/* 018888 8003D488 00C0382D */   daddu $a3, $a2, $zero

/* 01888C 8003D48C 24050004 */  addiu $a1, $zero, 4
/* 018890 8003D490 0200302D */  daddu $a2, $s0, $zero
/* 018894 8003D494 2402000D */  addiu $v0, $zero, 0xd
/* 018898 8003D498 A22200AA */  sb    $v0, 0xaa($s1)
/* 01889C 8003D49C AFB20010 */  sw    $s2, 0x10($sp)
/* 0188A0 8003D4A0 0800F57A */  j     .L8003D5E8
/* 0188A4 8003D4A4 AFA00014 */   sw    $zero, 0x14($sp)

/* 0188A8 8003D4A8 24050006 */  addiu $a1, $zero, 6
/* 0188AC 8003D4AC 0200302D */  daddu $a2, $s0, $zero
/* 0188B0 8003D4B0 2402000D */  addiu $v0, $zero, 0xd
/* 0188B4 8003D4B4 A22200AA */  sb    $v0, 0xaa($s1)
/* 0188B8 8003D4B8 240200FF */  addiu $v0, $zero, 0xff
/* 0188BC 8003D4BC AFB20010 */  sw    $s2, 0x10($sp)
/* 0188C0 8003D4C0 0800F57A */  j     .L8003D5E8
/* 0188C4 8003D4C4 AFA20014 */   sw    $v0, 0x14($sp)

/* 0188C8 8003D4C8 24050007 */  addiu $a1, $zero, 7
/* 0188CC 8003D4CC 240600FF */  addiu $a2, $zero, 0xff
/* 0188D0 8003D4D0 24020016 */  addiu $v0, $zero, 0x16
/* 0188D4 8003D4D4 A22200AA */  sb    $v0, 0xaa($s1)
/* 0188D8 8003D4D8 00C0102D */  daddu $v0, $a2, $zero
/* 0188DC 8003D4DC AFA20010 */  sw    $v0, 0x10($sp)
/* 0188E0 8003D4E0 AFB00014 */  sw    $s0, 0x14($sp)
/* 0188E4 8003D4E4 AFB30018 */  sw    $s3, 0x18($sp)
/* 0188E8 8003D4E8 8E240024 */  lw    $a0, 0x24($s1)
/* 0188EC 8003D4EC 0800F57D */  j     .L8003D5F4
/* 0188F0 8003D4F0 00C0382D */   daddu $a3, $a2, $zero

/* 0188F4 8003D4F4 24050008 */  addiu $a1, $zero, 8
/* 0188F8 8003D4F8 0200302D */  daddu $a2, $s0, $zero
/* 0188FC 8003D4FC 24020016 */  addiu $v0, $zero, 0x16
/* 018900 8003D500 A22200AA */  sb    $v0, 0xaa($s1)
/* 018904 8003D504 AFB20010 */  sw    $s2, 0x10($sp)
/* 018908 8003D508 0800F57A */  j     .L8003D5E8
/* 01890C 8003D50C AFB60014 */   sw    $s6, 0x14($sp)

/* 018910 8003D510 24050009 */  addiu $a1, $zero, 9
/* 018914 8003D514 0200302D */  daddu $a2, $s0, $zero
/* 018918 8003D518 2402000D */  addiu $v0, $zero, 0xd
/* 01891C 8003D51C A22200AA */  sb    $v0, 0xaa($s1)
/* 018920 8003D520 240200FF */  addiu $v0, $zero, 0xff
/* 018924 8003D524 AFB20010 */  sw    $s2, 0x10($sp)
/* 018928 8003D528 0800F57A */  j     .L8003D5E8
/* 01892C 8003D52C AFA20014 */   sw    $v0, 0x14($sp)

/* 018930 8003D530 2405000A */  addiu $a1, $zero, 0xa
/* 018934 8003D534 0200302D */  daddu $a2, $s0, $zero
/* 018938 8003D538 24020016 */  addiu $v0, $zero, 0x16
/* 01893C 8003D53C A22200AA */  sb    $v0, 0xaa($s1)
/* 018940 8003D540 AFB20010 */  sw    $s2, 0x10($sp)
/* 018944 8003D544 0800F57A */  j     .L8003D5E8
/* 018948 8003D548 AFB60014 */   sw    $s6, 0x14($sp)

/* 01894C 8003D54C 24050005 */  addiu $a1, $zero, 5
/* 018950 8003D550 0200302D */  daddu $a2, $s0, $zero
/* 018954 8003D554 2402000D */  addiu $v0, $zero, 0xd
/* 018958 8003D558 A22200AA */  sb    $v0, 0xaa($s1)
/* 01895C 8003D55C AFB20010 */  sw    $s2, 0x10($sp)
/* 018960 8003D560 0800F57A */  j     .L8003D5E8
/* 018964 8003D564 AFA00014 */   sw    $zero, 0x14($sp)

/* 018968 8003D568 2405000D */  addiu $a1, $zero, 0xd
/* 01896C 8003D56C 0200302D */  daddu $a2, $s0, $zero
/* 018970 8003D570 24020016 */  addiu $v0, $zero, 0x16
/* 018974 8003D574 A22200AA */  sb    $v0, 0xaa($s1)
/* 018978 8003D578 AFB20010 */  sw    $s2, 0x10($sp)
/* 01897C 8003D57C 0800F57A */  j     .L8003D5E8
/* 018980 8003D580 AFB60014 */   sw    $s6, 0x14($sp)

/* 018984 8003D584 2405000E */  addiu $a1, $zero, 0xe
/* 018988 8003D588 0200302D */  daddu $a2, $s0, $zero
/* 01898C 8003D58C 2402000D */  addiu $v0, $zero, 0xd
/* 018990 8003D590 A22200AA */  sb    $v0, 0xaa($s1)
/* 018994 8003D594 240200FF */  addiu $v0, $zero, 0xff
/* 018998 8003D598 AFB20010 */  sw    $s2, 0x10($sp)
/* 01899C 8003D59C 0800F57A */  j     .L8003D5E8
/* 0189A0 8003D5A0 AFA20014 */   sw    $v0, 0x14($sp)

/* 0189A4 8003D5A4 2405000F */  addiu $a1, $zero, 0xf
/* 0189A8 8003D5A8 0200302D */  daddu $a2, $s0, $zero
/* 0189AC 8003D5AC 2402000D */  addiu $v0, $zero, 0xd
/* 0189B0 8003D5B0 A22200AA */  sb    $v0, 0xaa($s1)
/* 0189B4 8003D5B4 240200FF */  addiu $v0, $zero, 0xff
/* 0189B8 8003D5B8 AFA00010 */  sw    $zero, 0x10($sp)
/* 0189BC 8003D5BC AFA20014 */  sw    $v0, 0x14($sp)
/* 0189C0 8003D5C0 AFB30018 */  sw    $s3, 0x18($sp)
/* 0189C4 8003D5C4 8E240024 */  lw    $a0, 0x24($s1)
/* 0189C8 8003D5C8 0800F57D */  j     .L8003D5F4
/* 0189CC 8003D5CC 0040382D */   daddu $a3, $v0, $zero

/* 0189D0 8003D5D0 2405000F */  addiu $a1, $zero, 0xf
/* 0189D4 8003D5D4 0200302D */  daddu $a2, $s0, $zero
/* 0189D8 8003D5D8 24020016 */  addiu $v0, $zero, 0x16
/* 0189DC 8003D5DC A22200AA */  sb    $v0, 0xaa($s1)
/* 0189E0 8003D5E0 AFA00010 */  sw    $zero, 0x10($sp)
/* 0189E4 8003D5E4 AFB50014 */  sw    $s5, 0x14($sp)
.L8003D5E8:
/* 0189E8 8003D5E8 AFB30018 */  sw    $s3, 0x18($sp)
/* 0189EC 8003D5EC 8E240024 */  lw    $a0, 0x24($s1)
/* 0189F0 8003D5F0 02A0382D */  daddu $a3, $s5, $zero
.L8003D5F4:
/* 0189F4 8003D5F4 0C0B7A25 */  jal   func_802DE894
/* 0189F8 8003D5F8 00000000 */   nop   
.L8003D5FC:
/* 0189FC 8003D5FC 8FBF003C */  lw    $ra, 0x3c($sp)
/* 018A00 8003D600 8FB60038 */  lw    $s6, 0x38($sp)
/* 018A04 8003D604 8FB50034 */  lw    $s5, 0x34($sp)
/* 018A08 8003D608 8FB40030 */  lw    $s4, 0x30($sp)
/* 018A0C 8003D60C 8FB3002C */  lw    $s3, 0x2c($sp)
/* 018A10 8003D610 8FB20028 */  lw    $s2, 0x28($sp)
/* 018A14 8003D614 8FB10024 */  lw    $s1, 0x24($sp)
/* 018A18 8003D618 8FB00020 */  lw    $s0, 0x20($sp)
/* 018A1C 8003D61C 03E00008 */  jr    $ra
/* 018A20 8003D620 27BD0040 */   addiu $sp, $sp, 0x40

