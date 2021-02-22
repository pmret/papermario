.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003D3BC
/* 187BC 8003D3BC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 187C0 8003D3C0 AFB10024 */  sw        $s1, 0x24($sp)
/* 187C4 8003D3C4 0080882D */  daddu     $s1, $a0, $zero
/* 187C8 8003D3C8 0000282D */  daddu     $a1, $zero, $zero
/* 187CC 8003D3CC AFBF003C */  sw        $ra, 0x3c($sp)
/* 187D0 8003D3D0 AFB60038 */  sw        $s6, 0x38($sp)
/* 187D4 8003D3D4 AFB50034 */  sw        $s5, 0x34($sp)
/* 187D8 8003D3D8 AFB40030 */  sw        $s4, 0x30($sp)
/* 187DC 8003D3DC AFB3002C */  sw        $s3, 0x2c($sp)
/* 187E0 8003D3E0 AFB20028 */  sw        $s2, 0x28($sp)
/* 187E4 8003D3E4 AFB00020 */  sw        $s0, 0x20($sp)
/* 187E8 8003D3E8 86340098 */  lh        $s4, 0x98($s1)
/* 187EC 8003D3EC 8630009A */  lh        $s0, 0x9a($s1)
/* 187F0 8003D3F0 8635009C */  lh        $s5, 0x9c($s1)
/* 187F4 8003D3F4 8632009E */  lh        $s2, 0x9e($s1)
/* 187F8 8003D3F8 863600A0 */  lh        $s6, 0xa0($s1)
/* 187FC 8003D3FC 963300A2 */  lhu       $s3, 0xa2($s1)
/* 18800 8003D400 00A0302D */  daddu     $a2, $a1, $zero
/* 18804 8003D404 AFA00010 */  sw        $zero, 0x10($sp)
/* 18808 8003D408 AFA00014 */  sw        $zero, 0x14($sp)
/* 1880C 8003D40C AFA00018 */  sw        $zero, 0x18($sp)
/* 18810 8003D410 8E240024 */  lw        $a0, 0x24($s1)
/* 18814 8003D414 0C0B7A25 */  jal       func_802DE894
/* 18818 8003D418 00A0382D */   daddu    $a3, $a1, $zero
/* 1881C 8003D41C 2E820011 */  sltiu     $v0, $s4, 0x11
/* 18820 8003D420 10400076 */  beqz      $v0, .L8003D5FC
/* 18824 8003D424 00141080 */   sll      $v0, $s4, 2
/* 18828 8003D428 3C01800A */  lui       $at, %hi(jtbl_80098548)
/* 1882C 8003D42C 00220821 */  addu      $at, $at, $v0
/* 18830 8003D430 8C228548 */  lw        $v0, %lo(jtbl_80098548)($at)
/* 18834 8003D434 00400008 */  jr        $v0
/* 18838 8003D438 00000000 */   nop
glabel L8003D43C_1883C
/* 1883C 8003D43C 0000282D */  daddu     $a1, $zero, $zero
/* 18840 8003D440 00A0302D */  daddu     $a2, $a1, $zero
/* 18844 8003D444 2402000D */  addiu     $v0, $zero, 0xd
/* 18848 8003D448 A22200AA */  sb        $v0, 0xaa($s1)
/* 1884C 8003D44C AFA00010 */  sw        $zero, 0x10($sp)
/* 18850 8003D450 AFA00014 */  sw        $zero, 0x14($sp)
/* 18854 8003D454 AFB30018 */  sw        $s3, 0x18($sp)
/* 18858 8003D458 8E240024 */  lw        $a0, 0x24($s1)
/* 1885C 8003D45C 0800F57D */  j         .L8003D5F4
/* 18860 8003D460 00A0382D */   daddu    $a3, $a1, $zero
glabel L8003D464_18864
/* 18864 8003D464 2402000D */  addiu     $v0, $zero, 0xd
/* 18868 8003D468 A22200AA */  sb        $v0, 0xaa($s1)
glabel L8003D46C_1886C
/* 1886C 8003D46C 0280282D */  daddu     $a1, $s4, $zero
/* 18870 8003D470 0000302D */  daddu     $a2, $zero, $zero
/* 18874 8003D474 AFA00010 */  sw        $zero, 0x10($sp)
/* 18878 8003D478 AFA00014 */  sw        $zero, 0x14($sp)
/* 1887C 8003D47C AFB30018 */  sw        $s3, 0x18($sp)
/* 18880 8003D480 8E240024 */  lw        $a0, 0x24($s1)
/* 18884 8003D484 0800F57D */  j         .L8003D5F4
/* 18888 8003D488 00C0382D */   daddu    $a3, $a2, $zero
glabel L8003D48C_1888C
/* 1888C 8003D48C 24050004 */  addiu     $a1, $zero, 4
/* 18890 8003D490 0200302D */  daddu     $a2, $s0, $zero
/* 18894 8003D494 2402000D */  addiu     $v0, $zero, 0xd
/* 18898 8003D498 A22200AA */  sb        $v0, 0xaa($s1)
/* 1889C 8003D49C AFB20010 */  sw        $s2, 0x10($sp)
/* 188A0 8003D4A0 0800F57A */  j         .L8003D5E8
/* 188A4 8003D4A4 AFA00014 */   sw       $zero, 0x14($sp)
glabel L8003D4A8_188A8
/* 188A8 8003D4A8 24050006 */  addiu     $a1, $zero, 6
/* 188AC 8003D4AC 0200302D */  daddu     $a2, $s0, $zero
/* 188B0 8003D4B0 2402000D */  addiu     $v0, $zero, 0xd
/* 188B4 8003D4B4 A22200AA */  sb        $v0, 0xaa($s1)
/* 188B8 8003D4B8 240200FF */  addiu     $v0, $zero, 0xff
/* 188BC 8003D4BC AFB20010 */  sw        $s2, 0x10($sp)
/* 188C0 8003D4C0 0800F57A */  j         .L8003D5E8
/* 188C4 8003D4C4 AFA20014 */   sw       $v0, 0x14($sp)
glabel L8003D4C8_188C8
/* 188C8 8003D4C8 24050007 */  addiu     $a1, $zero, 7
/* 188CC 8003D4CC 240600FF */  addiu     $a2, $zero, 0xff
/* 188D0 8003D4D0 24020016 */  addiu     $v0, $zero, 0x16
/* 188D4 8003D4D4 A22200AA */  sb        $v0, 0xaa($s1)
/* 188D8 8003D4D8 00C0102D */  daddu     $v0, $a2, $zero
/* 188DC 8003D4DC AFA20010 */  sw        $v0, 0x10($sp)
/* 188E0 8003D4E0 AFB00014 */  sw        $s0, 0x14($sp)
/* 188E4 8003D4E4 AFB30018 */  sw        $s3, 0x18($sp)
/* 188E8 8003D4E8 8E240024 */  lw        $a0, 0x24($s1)
/* 188EC 8003D4EC 0800F57D */  j         .L8003D5F4
/* 188F0 8003D4F0 00C0382D */   daddu    $a3, $a2, $zero
glabel L8003D4F4_188F4
/* 188F4 8003D4F4 24050008 */  addiu     $a1, $zero, 8
/* 188F8 8003D4F8 0200302D */  daddu     $a2, $s0, $zero
/* 188FC 8003D4FC 24020016 */  addiu     $v0, $zero, 0x16
/* 18900 8003D500 A22200AA */  sb        $v0, 0xaa($s1)
/* 18904 8003D504 AFB20010 */  sw        $s2, 0x10($sp)
/* 18908 8003D508 0800F57A */  j         .L8003D5E8
/* 1890C 8003D50C AFB60014 */   sw       $s6, 0x14($sp)
glabel L8003D510_18910
/* 18910 8003D510 24050009 */  addiu     $a1, $zero, 9
/* 18914 8003D514 0200302D */  daddu     $a2, $s0, $zero
/* 18918 8003D518 2402000D */  addiu     $v0, $zero, 0xd
/* 1891C 8003D51C A22200AA */  sb        $v0, 0xaa($s1)
/* 18920 8003D520 240200FF */  addiu     $v0, $zero, 0xff
/* 18924 8003D524 AFB20010 */  sw        $s2, 0x10($sp)
/* 18928 8003D528 0800F57A */  j         .L8003D5E8
/* 1892C 8003D52C AFA20014 */   sw       $v0, 0x14($sp)
glabel L8003D530_18930
/* 18930 8003D530 2405000A */  addiu     $a1, $zero, 0xa
/* 18934 8003D534 0200302D */  daddu     $a2, $s0, $zero
/* 18938 8003D538 24020016 */  addiu     $v0, $zero, 0x16
/* 1893C 8003D53C A22200AA */  sb        $v0, 0xaa($s1)
/* 18940 8003D540 AFB20010 */  sw        $s2, 0x10($sp)
/* 18944 8003D544 0800F57A */  j         .L8003D5E8
/* 18948 8003D548 AFB60014 */   sw       $s6, 0x14($sp)
glabel L8003D54C_1894C
/* 1894C 8003D54C 24050005 */  addiu     $a1, $zero, 5
/* 18950 8003D550 0200302D */  daddu     $a2, $s0, $zero
/* 18954 8003D554 2402000D */  addiu     $v0, $zero, 0xd
/* 18958 8003D558 A22200AA */  sb        $v0, 0xaa($s1)
/* 1895C 8003D55C AFB20010 */  sw        $s2, 0x10($sp)
/* 18960 8003D560 0800F57A */  j         .L8003D5E8
/* 18964 8003D564 AFA00014 */   sw       $zero, 0x14($sp)
glabel L8003D568_18968
/* 18968 8003D568 2405000D */  addiu     $a1, $zero, 0xd
/* 1896C 8003D56C 0200302D */  daddu     $a2, $s0, $zero
/* 18970 8003D570 24020016 */  addiu     $v0, $zero, 0x16
/* 18974 8003D574 A22200AA */  sb        $v0, 0xaa($s1)
/* 18978 8003D578 AFB20010 */  sw        $s2, 0x10($sp)
/* 1897C 8003D57C 0800F57A */  j         .L8003D5E8
/* 18980 8003D580 AFB60014 */   sw       $s6, 0x14($sp)
glabel L8003D584_18984
/* 18984 8003D584 2405000E */  addiu     $a1, $zero, 0xe
/* 18988 8003D588 0200302D */  daddu     $a2, $s0, $zero
/* 1898C 8003D58C 2402000D */  addiu     $v0, $zero, 0xd
/* 18990 8003D590 A22200AA */  sb        $v0, 0xaa($s1)
/* 18994 8003D594 240200FF */  addiu     $v0, $zero, 0xff
/* 18998 8003D598 AFB20010 */  sw        $s2, 0x10($sp)
/* 1899C 8003D59C 0800F57A */  j         .L8003D5E8
/* 189A0 8003D5A0 AFA20014 */   sw       $v0, 0x14($sp)
glabel L8003D5A4_189A4
/* 189A4 8003D5A4 2405000F */  addiu     $a1, $zero, 0xf
/* 189A8 8003D5A8 0200302D */  daddu     $a2, $s0, $zero
/* 189AC 8003D5AC 2402000D */  addiu     $v0, $zero, 0xd
/* 189B0 8003D5B0 A22200AA */  sb        $v0, 0xaa($s1)
/* 189B4 8003D5B4 240200FF */  addiu     $v0, $zero, 0xff
/* 189B8 8003D5B8 AFA00010 */  sw        $zero, 0x10($sp)
/* 189BC 8003D5BC AFA20014 */  sw        $v0, 0x14($sp)
/* 189C0 8003D5C0 AFB30018 */  sw        $s3, 0x18($sp)
/* 189C4 8003D5C4 8E240024 */  lw        $a0, 0x24($s1)
/* 189C8 8003D5C8 0800F57D */  j         .L8003D5F4
/* 189CC 8003D5CC 0040382D */   daddu    $a3, $v0, $zero
glabel L8003D5D0_189D0
/* 189D0 8003D5D0 2405000F */  addiu     $a1, $zero, 0xf
/* 189D4 8003D5D4 0200302D */  daddu     $a2, $s0, $zero
/* 189D8 8003D5D8 24020016 */  addiu     $v0, $zero, 0x16
/* 189DC 8003D5DC A22200AA */  sb        $v0, 0xaa($s1)
/* 189E0 8003D5E0 AFA00010 */  sw        $zero, 0x10($sp)
/* 189E4 8003D5E4 AFB50014 */  sw        $s5, 0x14($sp)
.L8003D5E8:
/* 189E8 8003D5E8 AFB30018 */  sw        $s3, 0x18($sp)
/* 189EC 8003D5EC 8E240024 */  lw        $a0, 0x24($s1)
/* 189F0 8003D5F0 02A0382D */  daddu     $a3, $s5, $zero
.L8003D5F4:
/* 189F4 8003D5F4 0C0B7A25 */  jal       func_802DE894
/* 189F8 8003D5F8 00000000 */   nop
.L8003D5FC:
glabel L8003D5FC_189FC
/* 189FC 8003D5FC 8FBF003C */  lw        $ra, 0x3c($sp)
/* 18A00 8003D600 8FB60038 */  lw        $s6, 0x38($sp)
/* 18A04 8003D604 8FB50034 */  lw        $s5, 0x34($sp)
/* 18A08 8003D608 8FB40030 */  lw        $s4, 0x30($sp)
/* 18A0C 8003D60C 8FB3002C */  lw        $s3, 0x2c($sp)
/* 18A10 8003D610 8FB20028 */  lw        $s2, 0x28($sp)
/* 18A14 8003D614 8FB10024 */  lw        $s1, 0x24($sp)
/* 18A18 8003D618 8FB00020 */  lw        $s0, 0x20($sp)
/* 18A1C 8003D61C 03E00008 */  jr        $ra
/* 18A20 8003D620 27BD0040 */   addiu    $sp, $sp, 0x40
