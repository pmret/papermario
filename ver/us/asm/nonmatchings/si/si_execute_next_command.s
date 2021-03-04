.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_execute_next_command
/* EBDB4 802C7404 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EBDB8 802C7408 AFB00010 */  sw        $s0, 0x10($sp)
/* EBDBC 802C740C 0080802D */  daddu     $s0, $a0, $zero
/* EBDC0 802C7410 AFBF0014 */  sw        $ra, 0x14($sp)
.L802C7414:
/* EBDC4 802C7414 92030002 */  lbu       $v1, 2($s0)
/* EBDC8 802C7418 2C62005F */  sltiu     $v0, $v1, 0x5f
/* EBDCC 802C741C 1040018B */  beqz      $v0, .L802C7A4C
/* EBDD0 802C7420 24050002 */   addiu    $a1, $zero, 2
/* EBDD4 802C7424 00A31004 */  sllv      $v0, $v1, $a1
/* EBDD8 802C7428 3C01802E */  lui       $at, %hi(jtbl_802D9F20)
/* EBDDC 802C742C 00220821 */  addu      $at, $at, $v0
/* EBDE0 802C7430 8C229F20 */  lw        $v0, %lo(jtbl_802D9F20)($at)
/* EBDE4 802C7434 00400008 */  jr        $v0
/* EBDE8 802C7438 00000000 */   nop
glabel L802C743C_EBDEC
/* EBDEC 802C743C 8E030008 */  lw        $v1, 8($s0)
/* EBDF0 802C7440 24050003 */  addiu     $a1, $zero, 3
/* EBDF4 802C7444 0060102D */  daddu     $v0, $v1, $zero
/* EBDF8 802C7448 AE020164 */  sw        $v0, 0x164($s0)
/* EBDFC 802C744C 90620003 */  lbu       $v0, 3($v1)
/* EBE00 802C7450 24630004 */  addiu     $v1, $v1, 4
/* EBE04 802C7454 A2020002 */  sb        $v0, 2($s0)
/* EBE08 802C7458 8C640000 */  lw        $a0, ($v1)
/* EBE0C 802C745C 24630004 */  addiu     $v1, $v1, 4
/* EBE10 802C7460 AE03000C */  sw        $v1, 0xc($s0)
/* EBE14 802C7464 A2000005 */  sb        $zero, 5($s0)
/* EBE18 802C7468 00041080 */  sll       $v0, $a0, 2
/* EBE1C 802C746C 00621821 */  addu      $v1, $v1, $v0
/* EBE20 802C7470 A2040001 */  sb        $a0, 1($s0)
/* EBE24 802C7474 080B1E95 */  j         L802C7A54_EC404
/* EBE28 802C7478 AE030008 */   sw       $v1, 8($s0)
glabel L802C747C_EBE2C
/* EBE2C 802C747C 0C0B1266 */  jal       si_handle_return
/* EBE30 802C7480 0200202D */   daddu    $a0, $s0, $zero
/* EBE34 802C7484 080B1E95 */  j         L802C7A54_EC404
/* EBE38 802C7488 0040282D */   daddu    $a1, $v0, $zero
glabel L802C748C_EBE3C
/* EBE3C 802C748C 0C0B126E */  jal       si_handle_label
/* EBE40 802C7490 0200202D */   daddu    $a0, $s0, $zero
/* EBE44 802C7494 080B1E95 */  j         L802C7A54_EC404
/* EBE48 802C7498 0040282D */   daddu    $a1, $v0, $zero
glabel L802C749C_EBE4C
/* EBE4C 802C749C 0C0B1270 */  jal       si_handle_goto
/* EBE50 802C74A0 0200202D */   daddu    $a0, $s0, $zero
/* EBE54 802C74A4 080B1E95 */  j         L802C7A54_EC404
/* EBE58 802C74A8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C74AC_EBE5C
/* EBE5C 802C74AC 0C0B1280 */  jal       si_handle_loop
/* EBE60 802C74B0 0200202D */   daddu    $a0, $s0, $zero
/* EBE64 802C74B4 080B1E95 */  j         L802C7A54_EC404
/* EBE68 802C74B8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C74BC_EBE6C
/* EBE6C 802C74BC 0C0B1292 */  jal       si_handle_end_loop
/* EBE70 802C74C0 0200202D */   daddu    $a0, $s0, $zero
/* EBE74 802C74C4 080B1E95 */  j         L802C7A54_EC404
/* EBE78 802C74C8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C74CC_EBE7C
/* EBE7C 802C74CC 0C0B12C3 */  jal       si_handle_break_loop
/* EBE80 802C74D0 0200202D */   daddu    $a0, $s0, $zero
/* EBE84 802C74D4 080B1E95 */  j         L802C7A54_EC404
/* EBE88 802C74D8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C74DC_EBE8C
/* EBE8C 802C74DC 0C0B12D7 */  jal       si_handle_sleep_frames
/* EBE90 802C74E0 0200202D */   daddu    $a0, $s0, $zero
/* EBE94 802C74E4 080B1E95 */  j         L802C7A54_EC404
/* EBE98 802C74E8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C74EC_EBE9C
/* EBE9C 802C74EC 0C0B12EE */  jal       si_handle_sleep_seconds
/* EBEA0 802C74F0 0200202D */   daddu    $a0, $s0, $zero
/* EBEA4 802C74F4 080B1E95 */  j         L802C7A54_EC404
/* EBEA8 802C74F8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C74FC_EBEAC
/* EBEAC 802C74FC 0C0B1310 */  jal       si_handle_if_equal
/* EBEB0 802C7500 0200202D */   daddu    $a0, $s0, $zero
/* EBEB4 802C7504 080B1E95 */  j         L802C7A54_EC404
/* EBEB8 802C7508 0040282D */   daddu    $a1, $v0, $zero
glabel L802C750C_EBEBC
/* EBEBC 802C750C 0C0B1328 */  jal       si_handle_if_not_equal
/* EBEC0 802C7510 0200202D */   daddu    $a0, $s0, $zero
/* EBEC4 802C7514 080B1E95 */  j         L802C7A54_EC404
/* EBEC8 802C7518 0040282D */   daddu    $a1, $v0, $zero
glabel L802C751C_EBECC
/* EBECC 802C751C 0C0B1340 */  jal       si_handle_if_less
/* EBED0 802C7520 0200202D */   daddu    $a0, $s0, $zero
/* EBED4 802C7524 080B1E95 */  j         L802C7A54_EC404
/* EBED8 802C7528 0040282D */   daddu    $a1, $v0, $zero
glabel L802C752C_EBEDC
/* EBEDC 802C752C 0C0B1359 */  jal       si_handle_if_greater
/* EBEE0 802C7530 0200202D */   daddu    $a0, $s0, $zero
/* EBEE4 802C7534 080B1E95 */  j         L802C7A54_EC404
/* EBEE8 802C7538 0040282D */   daddu    $a1, $v0, $zero
glabel L802C753C_EBEEC
/* EBEEC 802C753C 0C0B1372 */  jal       si_handle_if_less_equal
/* EBEF0 802C7540 0200202D */   daddu    $a0, $s0, $zero
/* EBEF4 802C7544 080B1E95 */  j         L802C7A54_EC404
/* EBEF8 802C7548 0040282D */   daddu    $a1, $v0, $zero
glabel L802C754C_EBEFC
/* EBEFC 802C754C 0C0B138B */  jal       si_handle_if_greater_equal
/* EBF00 802C7550 0200202D */   daddu    $a0, $s0, $zero
/* EBF04 802C7554 080B1E95 */  j         L802C7A54_EC404
/* EBF08 802C7558 0040282D */   daddu    $a1, $v0, $zero
glabel L802C755C_EBF0C
/* EBF0C 802C755C 0C0B13A4 */  jal       si_handle_if_flag
/* EBF10 802C7560 0200202D */   daddu    $a0, $s0, $zero
/* EBF14 802C7564 080B1E95 */  j         L802C7A54_EC404
/* EBF18 802C7568 0040282D */   daddu    $a1, $v0, $zero
glabel L802C756C_EBF1C
/* EBF1C 802C756C 0C0B13BA */  jal       si_handle_if_not_flag
/* EBF20 802C7570 0200202D */   daddu    $a0, $s0, $zero
/* EBF24 802C7574 080B1E95 */  j         L802C7A54_EC404
/* EBF28 802C7578 0040282D */   daddu    $a1, $v0, $zero
glabel L802C757C_EBF2C
/* EBF2C 802C757C 0C0B13D0 */  jal       si_handle_else
/* EBF30 802C7580 0200202D */   daddu    $a0, $s0, $zero
/* EBF34 802C7584 080B1E95 */  j         L802C7A54_EC404
/* EBF38 802C7588 0040282D */   daddu    $a1, $v0, $zero
glabel L802C758C_EBF3C
/* EBF3C 802C758C 0C0B13DB */  jal       si_handle_end_if
/* EBF40 802C7590 0200202D */   daddu    $a0, $s0, $zero
/* EBF44 802C7594 080B1E95 */  j         L802C7A54_EC404
/* EBF48 802C7598 0040282D */   daddu    $a1, $v0, $zero
glabel L802C759C_EBF4C
/* EBF4C 802C759C 0C0B13DD */  jal       si_handle_match
/* EBF50 802C75A0 0200202D */   daddu    $a0, $s0, $zero
/* EBF54 802C75A4 080B1E95 */  j         L802C7A54_EC404
/* EBF58 802C75A8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C75AC_EBF5C
/* EBF5C 802C75AC 0C0B13F9 */  jal       si_handle_match_const
/* EBF60 802C75B0 0200202D */   daddu    $a0, $s0, $zero
/* EBF64 802C75B4 080B1E95 */  j         L802C7A54_EC404
/* EBF68 802C75B8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C75BC_EBF6C
/* EBF6C 802C75BC 0C0B140C */  jal       si_handle_case_equal
/* EBF70 802C75C0 0200202D */   daddu    $a0, $s0, $zero
/* EBF74 802C75C4 080B1E95 */  j         L802C7A54_EC404
/* EBF78 802C75C8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C75CC_EBF7C
/* EBF7C 802C75CC 0C0B142F */  jal       si_handle_case_not_equal
/* EBF80 802C75D0 0200202D */   daddu    $a0, $s0, $zero
/* EBF84 802C75D4 080B1E95 */  j         L802C7A54_EC404
/* EBF88 802C75D8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C75DC_EBF8C
/* EBF8C 802C75DC 0C0B1452 */  jal       si_handle_case_less
/* EBF90 802C75E0 0200202D */   daddu    $a0, $s0, $zero
/* EBF94 802C75E4 080B1E95 */  j         L802C7A54_EC404
/* EBF98 802C75E8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C75EC_EBF9C
/* EBF9C 802C75EC 0C0B1476 */  jal       si_handle_case_less_equal
/* EBFA0 802C75F0 0200202D */   daddu    $a0, $s0, $zero
/* EBFA4 802C75F4 080B1E95 */  j         L802C7A54_EC404
/* EBFA8 802C75F8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C75FC_EBFAC
/* EBFAC 802C75FC 0C0B149A */  jal       si_handle_case_greater
/* EBFB0 802C7600 0200202D */   daddu    $a0, $s0, $zero
/* EBFB4 802C7604 080B1E95 */  j         L802C7A54_EC404
/* EBFB8 802C7608 0040282D */   daddu    $a1, $v0, $zero
glabel L802C760C_EBFBC
/* EBFBC 802C760C 0C0B14BE */  jal       si_handle_case_greater_equal
/* EBFC0 802C7610 0200202D */   daddu    $a0, $s0, $zero
/* EBFC4 802C7614 080B1E95 */  j         L802C7A54_EC404
/* EBFC8 802C7618 0040282D */   daddu    $a1, $v0, $zero
glabel L802C761C_EBFCC
/* EBFCC 802C761C 0C0B1511 */  jal       si_handle_case_else
/* EBFD0 802C7620 0200202D */   daddu    $a0, $s0, $zero
/* EBFD4 802C7624 080B1E95 */  j         L802C7A54_EC404
/* EBFD8 802C7628 0040282D */   daddu    $a1, $v0, $zero
glabel L802C762C_EBFDC
/* EBFDC 802C762C 0C0B15B5 */  jal       si_handle_break_match
/* EBFE0 802C7630 0200202D */   daddu    $a0, $s0, $zero
/* EBFE4 802C7634 080B1E95 */  j         L802C7A54_EC404
/* EBFE8 802C7638 0040282D */   daddu    $a1, $v0, $zero
glabel L802C763C_EBFEC
/* EBFEC 802C763C 0C0B1546 */  jal       si_handle_case_multi_or_equal
/* EBFF0 802C7640 0200202D */   daddu    $a0, $s0, $zero
/* EBFF4 802C7644 080B1E95 */  j         L802C7A54_EC404
/* EBFF8 802C7648 0040282D */   daddu    $a1, $v0, $zero
glabel L802C764C_EBFFC
/* EBFFC 802C764C 0C0B1597 */  jal       si_handle_end_case_multi
/* EC000 802C7650 0200202D */   daddu    $a0, $s0, $zero
/* EC004 802C7654 080B1E95 */  j         L802C7A54_EC404
/* EC008 802C7658 0040282D */   daddu    $a1, $v0, $zero
glabel L802C765C_EC00C
/* EC00C 802C765C 0C0B156E */  jal       si_handle_case_multi_and_equal
/* EC010 802C7660 0200202D */   daddu    $a0, $s0, $zero
/* EC014 802C7664 080B1E95 */  j         L802C7A54_EC404
/* EC018 802C7668 0040282D */   daddu    $a1, $v0, $zero
glabel L802C766C_EC01C
/* EC01C 802C766C 0C0B1527 */  jal       si_handle_case_flag
/* EC020 802C7670 0200202D */   daddu    $a0, $s0, $zero
/* EC024 802C7674 080B1E95 */  j         L802C7A54_EC404
/* EC028 802C7678 0040282D */   daddu    $a1, $v0, $zero
glabel L802C767C_EC02C
/* EC02C 802C767C 0C0B14E2 */  jal       si_handle_case_range
/* EC030 802C7680 0200202D */   daddu    $a0, $s0, $zero
/* EC034 802C7684 080B1E95 */  j         L802C7A54_EC404
/* EC038 802C7688 0040282D */   daddu    $a1, $v0, $zero
glabel L802C768C_EC03C
/* EC03C 802C768C 0C0B15C6 */  jal       si_handle_end_match
/* EC040 802C7690 0200202D */   daddu    $a0, $s0, $zero
/* EC044 802C7694 080B1E95 */  j         L802C7A54_EC404
/* EC048 802C7698 0040282D */   daddu    $a1, $v0, $zero
glabel L802C769C_EC04C
/* EC04C 802C769C 0C0B15D1 */  jal       si_handle_set_var
/* EC050 802C76A0 0200202D */   daddu    $a0, $s0, $zero
/* EC054 802C76A4 080B1E95 */  j         L802C7A54_EC404
/* EC058 802C76A8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C76AC_EC05C
/* EC05C 802C76AC 0C0B15E4 */  jal       si_handle_set_const
/* EC060 802C76B0 0200202D */   daddu    $a0, $s0, $zero
/* EC064 802C76B4 080B1E95 */  j         L802C7A54_EC404
/* EC068 802C76B8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C76BC_EC06C
/* EC06C 802C76BC 0C0B15EE */  jal       si_handle_set_float
/* EC070 802C76C0 0200202D */   daddu    $a0, $s0, $zero
/* EC074 802C76C4 080B1E95 */  j         L802C7A54_EC404
/* EC078 802C76C8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C76CC_EC07C
/* EC07C 802C76CC 0C0B1601 */  jal       si_handle_add
/* EC080 802C76D0 0200202D */   daddu    $a0, $s0, $zero
/* EC084 802C76D4 080B1E95 */  j         L802C7A54_EC404
/* EC088 802C76D8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C76DC_EC08C
/* EC08C 802C76DC 0C0B161A */  jal       si_handle_subtract
/* EC090 802C76E0 0200202D */   daddu    $a0, $s0, $zero
/* EC094 802C76E4 080B1E95 */  j         L802C7A54_EC404
/* EC098 802C76E8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C76EC_EC09C
/* EC09C 802C76EC 0C0B1633 */  jal       si_handle_multiply
/* EC0A0 802C76F0 0200202D */   daddu    $a0, $s0, $zero
/* EC0A4 802C76F4 080B1E95 */  j         L802C7A54_EC404
/* EC0A8 802C76F8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C76FC_EC0AC
/* EC0AC 802C76FC 0C0B164D */  jal       si_handle_divide
/* EC0B0 802C7700 0200202D */   daddu    $a0, $s0, $zero
/* EC0B4 802C7704 080B1E95 */  j         L802C7A54_EC404
/* EC0B8 802C7708 0040282D */   daddu    $a1, $v0, $zero
glabel L802C770C_EC0BC
/* EC0BC 802C770C 0C0B166F */  jal       si_handle_mod
/* EC0C0 802C7710 0200202D */   daddu    $a0, $s0, $zero
/* EC0C4 802C7714 080B1E95 */  j         L802C7A54_EC404
/* EC0C8 802C7718 0040282D */   daddu    $a1, $v0, $zero
glabel L802C771C_EC0CC
/* EC0CC 802C771C 0C0B16A1 */  jal       si_handle_addF
/* EC0D0 802C7720 0200202D */   daddu    $a0, $s0, $zero
/* EC0D4 802C7724 080B1E95 */  j         L802C7A54_EC404
/* EC0D8 802C7728 0040282D */   daddu    $a1, $v0, $zero
glabel L802C772C_EC0DC
/* EC0DC 802C772C 0C0B16BB */  jal       si_handle_subtractF
/* EC0E0 802C7730 0200202D */   daddu    $a0, $s0, $zero
/* EC0E4 802C7734 080B1E95 */  j         L802C7A54_EC404
/* EC0E8 802C7738 0040282D */   daddu    $a1, $v0, $zero
glabel L802C773C_EC0EC
/* EC0EC 802C773C 0C0B16D5 */  jal       si_handle_multiplyF
/* EC0F0 802C7740 0200202D */   daddu    $a0, $s0, $zero
/* EC0F4 802C7744 080B1E95 */  j         L802C7A54_EC404
/* EC0F8 802C7748 0040282D */   daddu    $a1, $v0, $zero
glabel L802C774C_EC0FC
/* EC0FC 802C774C 0C0B16F0 */  jal       si_handle_divideF
/* EC100 802C7750 0200202D */   daddu    $a0, $s0, $zero
/* EC104 802C7754 080B1E95 */  j         L802C7A54_EC404
/* EC108 802C7758 0040282D */   daddu    $a1, $v0, $zero
glabel L802C775C_EC10C
/* EC10C 802C775C 0C0B170A */  jal       si_handle_set_int_buffer_ptr
/* EC110 802C7760 0200202D */   daddu    $a0, $s0, $zero
/* EC114 802C7764 080B1E95 */  j         L802C7A54_EC404
/* EC118 802C7768 0040282D */   daddu    $a1, $v0, $zero
glabel L802C776C_EC11C
/* EC11C 802C776C 0C0B1724 */  jal       si_handle_get_1_word
/* EC120 802C7770 0200202D */   daddu    $a0, $s0, $zero
/* EC124 802C7774 080B1E95 */  j         L802C7A54_EC404
/* EC128 802C7778 0040282D */   daddu    $a1, $v0, $zero
glabel L802C777C_EC12C
/* EC12C 802C777C 0C0B1731 */  jal       si_handle_get_2_word
/* EC130 802C7780 0200202D */   daddu    $a0, $s0, $zero
/* EC134 802C7784 080B1E95 */  j         L802C7A54_EC404
/* EC138 802C7788 0040282D */   daddu    $a1, $v0, $zero
glabel L802C778C_EC13C
/* EC13C 802C778C 0C0B174B */  jal       si_handle_get_3_word
/* EC140 802C7790 0200202D */   daddu    $a0, $s0, $zero
/* EC144 802C7794 080B1E95 */  j         L802C7A54_EC404
/* EC148 802C7798 0040282D */   daddu    $a1, $v0, $zero
glabel L802C779C_EC14C
/* EC14C 802C779C 0C0B176D */  jal       si_handle_get_4_word
/* EC150 802C77A0 0200202D */   daddu    $a0, $s0, $zero
/* EC154 802C77A4 080B1E95 */  j         L802C7A54_EC404
/* EC158 802C77A8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C77AC_EC15C
/* EC15C 802C77AC 0C0B1797 */  jal       si_handle_get_Nth_word
/* EC160 802C77B0 0200202D */   daddu    $a0, $s0, $zero
/* EC164 802C77B4 080B1E95 */  j         L802C7A54_EC404
/* EC168 802C77B8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C77BC_EC16C
/* EC16C 802C77BC 0C0B1717 */  jal       si_handle_set_float_buffer_ptr
/* EC170 802C77C0 0200202D */   daddu    $a0, $s0, $zero
/* EC174 802C77C4 080B1E95 */  j         L802C7A54_EC404
/* EC178 802C77C8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C77CC_EC17C
/* EC17C 802C77CC 0C0B17AD */  jal       si_handle_get_1_float
/* EC180 802C77D0 0200202D */   daddu    $a0, $s0, $zero
/* EC184 802C77D4 080B1E95 */  j         L802C7A54_EC404
/* EC188 802C77D8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C77DC_EC18C
/* EC18C 802C77DC 0C0B17C3 */  jal       si_handle_get_2_float
/* EC190 802C77E0 0200202D */   daddu    $a0, $s0, $zero
/* EC194 802C77E4 080B1E95 */  j         L802C7A54_EC404
/* EC198 802C77E8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C77EC_EC19C
/* EC19C 802C77EC 0C0B17E7 */  jal       si_handle_get_3_float
/* EC1A0 802C77F0 0200202D */   daddu    $a0, $s0, $zero
/* EC1A4 802C77F4 080B1E95 */  j         L802C7A54_EC404
/* EC1A8 802C77F8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C77FC_EC1AC
/* EC1AC 802C77FC 0C0B1817 */  jal       si_handle_get_4_float
/* EC1B0 802C7800 0200202D */   daddu    $a0, $s0, $zero
/* EC1B4 802C7804 080B1E95 */  j         L802C7A54_EC404
/* EC1B8 802C7808 0040282D */   daddu    $a1, $v0, $zero
glabel L802C780C_EC1BC
/* EC1BC 802C780C 0C0B1853 */  jal       si_handle_get_Nth_float
/* EC1C0 802C7810 0200202D */   daddu    $a0, $s0, $zero
/* EC1C4 802C7814 080B1E95 */  j         L802C7A54_EC404
/* EC1C8 802C7818 0040282D */   daddu    $a1, $v0, $zero
glabel L802C781C_EC1CC
/* EC1CC 802C781C 0C0B186B */  jal       si_handle_set_array
/* EC1D0 802C7820 0200202D */   daddu    $a0, $s0, $zero
/* EC1D4 802C7824 080B1E95 */  j         L802C7A54_EC404
/* EC1D8 802C7828 0040282D */   daddu    $a1, $v0, $zero
glabel L802C782C_EC1DC
/* EC1DC 802C782C 0C0B1878 */  jal       si_handle_set_flag_array
/* EC1E0 802C7830 0200202D */   daddu    $a0, $s0, $zero
/* EC1E4 802C7834 080B1E95 */  j         L802C7A54_EC404
/* EC1E8 802C7838 0040282D */   daddu    $a1, $v0, $zero
glabel L802C783C_EC1EC
/* EC1EC 802C783C 0C0B1885 */  jal       si_handle_allocate_array
/* EC1F0 802C7840 0200202D */   daddu    $a0, $s0, $zero
/* EC1F4 802C7844 080B1E95 */  j         L802C7A54_EC404
/* EC1F8 802C7848 0040282D */   daddu    $a1, $v0, $zero
glabel L802C784C_EC1FC
/* EC1FC 802C784C 0C0B1A1C */  jal       si_handle_kill_script
/* EC200 802C7850 0200202D */   daddu    $a0, $s0, $zero
/* EC204 802C7854 080B1E95 */  j         L802C7A54_EC404
/* EC208 802C7858 0040282D */   daddu    $a1, $v0, $zero
glabel L802C785C_EC20C
/* EC20C 802C785C 0C0B189C */  jal       si_handle_AND
/* EC210 802C7860 0200202D */   daddu    $a0, $s0, $zero
/* EC214 802C7864 080B1E95 */  j         L802C7A54_EC404
/* EC218 802C7868 0040282D */   daddu    $a1, $v0, $zero
glabel L802C786C_EC21C
/* EC21C 802C786C 0C0B18B5 */  jal       si_handle_AND_const
/* EC220 802C7870 0200202D */   daddu    $a0, $s0, $zero
/* EC224 802C7874 080B1E95 */  j         L802C7A54_EC404
/* EC228 802C7878 0040282D */   daddu    $a1, $v0, $zero
glabel L802C787C_EC22C
/* EC22C 802C787C 0C0B18CB */  jal       si_handle_OR
/* EC230 802C7880 0200202D */   daddu    $a0, $s0, $zero
/* EC234 802C7884 080B1E95 */  j         L802C7A54_EC404
/* EC238 802C7888 0040282D */   daddu    $a1, $v0, $zero
glabel L802C788C_EC23C
/* EC23C 802C788C 0C0B18E4 */  jal       si_handle_OR_const
/* EC240 802C7890 0200202D */   daddu    $a0, $s0, $zero
/* EC244 802C7894 080B1E95 */  j         L802C7A54_EC404
/* EC248 802C7898 0040282D */   daddu    $a1, $v0, $zero
glabel L802C789C_EC24C
/* EC24C 802C789C 0C0B18FA */  jal       si_handle_call
/* EC250 802C78A0 0200202D */   daddu    $a0, $s0, $zero
/* EC254 802C78A4 080B1E95 */  j         L802C7A54_EC404
/* EC258 802C78A8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C78AC_EC25C
/* EC25C 802C78AC 0C0B191B */  jal       si_handle_spawn_script
/* EC260 802C78B0 0200202D */   daddu    $a0, $s0, $zero
/* EC264 802C78B4 080B1E95 */  j         L802C7A54_EC404
/* EC268 802C78B8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C78BC_EC26C
/* EC26C 802C78BC 0C0B1949 */  jal       si_handle_spawn_script_get_id
/* EC270 802C78C0 0200202D */   daddu    $a0, $s0, $zero
/* EC274 802C78C4 080B1E95 */  j         L802C7A54_EC404
/* EC278 802C78C8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C78CC_EC27C
/* EC27C 802C78CC 0C0B197F */  jal       si_handle_await_script
/* EC280 802C78D0 0200202D */   daddu    $a0, $s0, $zero
/* EC284 802C78D4 080B1E95 */  j         L802C7A54_EC404
/* EC288 802C78D8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C78DC_EC28C
/* EC28C 802C78DC 0C0B19C5 */  jal       si_handle_bind_trigger
/* EC290 802C78E0 0200202D */   daddu    $a0, $s0, $zero
/* EC294 802C78E4 080B1E95 */  j         L802C7A54_EC404
/* EC298 802C78E8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C78EC_EC29C
/* EC29C 802C78EC 0C0B1A14 */  jal       si_handle_unbind
/* EC2A0 802C78F0 0200202D */   daddu    $a0, $s0, $zero
/* EC2A4 802C78F4 080B1E95 */  j         L802C7A54_EC404
/* EC2A8 802C78F8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C78FC_EC2AC
/* EC2AC 802C78FC 0C0B1A27 */  jal       si_handle_set_priority
/* EC2B0 802C7900 0200202D */   daddu    $a0, $s0, $zero
/* EC2B4 802C7904 080B1E95 */  j         L802C7A54_EC404
/* EC2B8 802C7908 0040282D */   daddu    $a1, $v0, $zero
glabel L802C790C_EC2BC
/* EC2BC 802C790C 0C0B1A36 */  jal       si_handle_set_timescale
/* EC2C0 802C7910 0200202D */   daddu    $a0, $s0, $zero
/* EC2C4 802C7914 080B1E95 */  j         L802C7A54_EC404
/* EC2C8 802C7918 0040282D */   daddu    $a1, $v0, $zero
glabel L802C791C_EC2CC
/* EC2CC 802C791C 0C0B1A45 */  jal       si_handle_set_group
/* EC2D0 802C7920 0200202D */   daddu    $a0, $s0, $zero
/* EC2D4 802C7924 080B1E95 */  j         L802C7A54_EC404
/* EC2D8 802C7928 0040282D */   daddu    $a1, $v0, $zero
glabel L802C792C_EC2DC
/* EC2DC 802C792C 0C0B1990 */  jal       si_handle_jump
/* EC2E0 802C7930 0200202D */   daddu    $a0, $s0, $zero
/* EC2E4 802C7934 080B1E95 */  j         L802C7A54_EC404
/* EC2E8 802C7938 0040282D */   daddu    $a1, $v0, $zero
glabel L802C793C_EC2EC
/* EC2EC 802C793C 0C0B1AD5 */  jal       si_handle_bind_lock
/* EC2F0 802C7940 0200202D */   daddu    $a0, $s0, $zero
/* EC2F4 802C7944 080B1E95 */  j         L802C7A54_EC404
/* EC2F8 802C7948 0040282D */   daddu    $a1, $v0, $zero
glabel L802C794C_EC2FC
/* EC2FC 802C794C 0C0B1A54 */  jal       si_handle_suspend_all
/* EC300 802C7950 0200202D */   daddu    $a0, $s0, $zero
/* EC304 802C7954 080B1E95 */  j         L802C7A54_EC404
/* EC308 802C7958 0040282D */   daddu    $a1, $v0, $zero
glabel L802C795C_EC30C
/* EC30C 802C795C 0C0B1A5F */  jal       si_handle_resume_all
/* EC310 802C7960 0200202D */   daddu    $a0, $s0, $zero
/* EC314 802C7964 080B1E95 */  j         L802C7A54_EC404
/* EC318 802C7968 0040282D */   daddu    $a1, $v0, $zero
glabel L802C796C_EC31C
/* EC31C 802C796C 0C0B1A6A */  jal       si_handle_suspend_others
/* EC320 802C7970 0200202D */   daddu    $a0, $s0, $zero
/* EC324 802C7974 080B1E95 */  j         L802C7A54_EC404
/* EC328 802C7978 0040282D */   daddu    $a1, $v0, $zero
glabel L802C797C_EC32C
/* EC32C 802C797C 0C0B1A79 */  jal       si_handle_resume_others
/* EC330 802C7980 0200202D */   daddu    $a0, $s0, $zero
/* EC334 802C7984 080B1E95 */  j         L802C7A54_EC404
/* EC338 802C7988 0040282D */   daddu    $a1, $v0, $zero
glabel L802C798C_EC33C
/* EC33C 802C798C 0C0B1A88 */  jal       si_handle_suspend_script
/* EC340 802C7990 0200202D */   daddu    $a0, $s0, $zero
/* EC344 802C7994 080B1E95 */  j         L802C7A54_EC404
/* EC348 802C7998 0040282D */   daddu    $a1, $v0, $zero
glabel L802C799C_EC34C
/* EC34C 802C799C 0C0B1A93 */  jal       si_handle_resume_script
/* EC350 802C79A0 0200202D */   daddu    $a0, $s0, $zero
/* EC354 802C79A4 080B1E95 */  j         L802C7A54_EC404
/* EC358 802C79A8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C79AC_EC35C
/* EC35C 802C79AC 0C0B1A9E */  jal       si_handle_does_script_exist
/* EC360 802C79B0 0200202D */   daddu    $a0, $s0, $zero
/* EC364 802C79B4 080B1E95 */  j         L802C7A54_EC404
/* EC368 802C79B8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C79BC_EC36C
/* EC36C 802C79BC 0C0B1B1E */  jal       si_handle_spawn_thread
/* EC370 802C79C0 0200202D */   daddu    $a0, $s0, $zero
/* EC374 802C79C4 080B1E95 */  j         L802C7A54_EC404
/* EC378 802C79C8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C79CC_EC37C
/* EC37C 802C79CC 0C0B1B53 */  jal       si_handle_end_spawn_thread
/* EC380 802C79D0 0200202D */   daddu    $a0, $s0, $zero
/* EC384 802C79D4 080B1E95 */  j         L802C7A54_EC404
/* EC388 802C79D8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C79DC_EC38C
/* EC38C 802C79DC 0C0B1B5B */  jal       si_handle_parallel_thread
/* EC390 802C79E0 0200202D */   daddu    $a0, $s0, $zero
/* EC394 802C79E4 080B1E95 */  j         L802C7A54_EC404
/* EC398 802C79E8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C79EC_EC39C
/* EC39C 802C79EC 0C0B1B7D */  jal       si_handle_end_parallel_thread
/* EC3A0 802C79F0 0200202D */   daddu    $a0, $s0, $zero
/* EC3A4 802C79F4 080B1E95 */  j         L802C7A54_EC404
/* EC3A8 802C79F8 0040282D */   daddu    $a1, $v0, $zero
glabel L802C79FC_EC3AC
/* EC3AC 802C79FC 0C0B1B85 */  jal       func_802C6E14
/* EC3B0 802C7A00 0200202D */   daddu    $a0, $s0, $zero
/* EC3B4 802C7A04 080B1E95 */  j         L802C7A54_EC404
/* EC3B8 802C7A08 0040282D */   daddu    $a1, $v0, $zero
glabel L802C7A0C_EC3BC
/* EC3BC 802C7A0C 0C0B1B87 */  jal       si_handle_print_debug_var
/* EC3C0 802C7A10 0200202D */   daddu    $a0, $s0, $zero
/* EC3C4 802C7A14 080B1E95 */  j         L802C7A54_EC404
/* EC3C8 802C7A18 0040282D */   daddu    $a1, $v0, $zero
glabel L802C7A1C_EC3CC
/* EC3CC 802C7A1C 0C0B1CE7 */  jal       func_802C739C
/* EC3D0 802C7A20 0200202D */   daddu    $a0, $s0, $zero
/* EC3D4 802C7A24 080B1E95 */  j         L802C7A54_EC404
/* EC3D8 802C7A28 0040282D */   daddu    $a1, $v0, $zero
glabel L802C7A2C_EC3DC
/* EC3DC 802C7A2C 0C0B1CEC */  jal       func_802C73B0
/* EC3E0 802C7A30 0200202D */   daddu    $a0, $s0, $zero
/* EC3E4 802C7A34 080B1E95 */  j         L802C7A54_EC404
/* EC3E8 802C7A38 0040282D */   daddu    $a1, $v0, $zero
glabel L802C7A3C_EC3EC
/* EC3EC 802C7A3C 0C0B1CEE */  jal       func_802C73B8
/* EC3F0 802C7A40 0200202D */   daddu    $a0, $s0, $zero
/* EC3F4 802C7A44 080B1E95 */  j         L802C7A54_EC404
/* EC3F8 802C7A48 0040282D */   daddu    $a1, $v0, $zero
.L802C7A4C:
/* EC3FC 802C7A4C 080B1E93 */  j         .L802C7A4C
/* EC400 802C7A50 00000000 */   nop
glabel L802C7A54_EC404
/* EC404 802C7A54 24020003 */  addiu     $v0, $zero, 3
/* EC408 802C7A58 10A2FE6E */  beq       $a1, $v0, .L802C7414
/* EC40C 802C7A5C 240200FF */   addiu    $v0, $zero, 0xff
/* EC410 802C7A60 10A20012 */  beq       $a1, $v0, .L802C7AAC
/* EC414 802C7A64 2402FFFF */   addiu    $v0, $zero, -1
/* EC418 802C7A68 04A00010 */  bltz      $a1, .L802C7AAC
/* EC41C 802C7A6C 24020001 */   addiu    $v0, $zero, 1
/* EC420 802C7A70 50A0000E */  beql      $a1, $zero, .L802C7AAC
/* EC424 802C7A74 0000102D */   daddu    $v0, $zero, $zero
/* EC428 802C7A78 14A20003 */  bne       $a1, $v0, .L802C7A88
/* EC42C 802C7A7C 24020002 */   addiu    $v0, $zero, 2
/* EC430 802C7A80 080B1EAA */  j         .L802C7AA8
/* EC434 802C7A84 A2000002 */   sb       $zero, 2($s0)
.L802C7A88:
/* EC438 802C7A88 14A2FE62 */  bne       $a1, $v0, .L802C7414
/* EC43C 802C7A8C 00000000 */   nop
/* EC440 802C7A90 A2000002 */  sb        $zero, 2($s0)
/* EC444 802C7A94 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* EC448 802C7A98 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* EC44C 802C7A9C 80420078 */  lb        $v0, 0x78($v0)
/* EC450 802C7AA0 1445FE5C */  bne       $v0, $a1, .L802C7414
/* EC454 802C7AA4 00000000 */   nop
.L802C7AA8:
/* EC458 802C7AA8 0000102D */  daddu     $v0, $zero, $zero
.L802C7AAC:
/* EC45C 802C7AAC 8FBF0014 */  lw        $ra, 0x14($sp)
/* EC460 802C7AB0 8FB00010 */  lw        $s0, 0x10($sp)
/* EC464 802C7AB4 03E00008 */  jr        $ra
/* EC468 802C7AB8 27BD0018 */   addiu    $sp, $sp, 0x18
