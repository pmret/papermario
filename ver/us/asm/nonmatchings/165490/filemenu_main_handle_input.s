.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8024BF88
.word L80245C10_166470, L80245C38_166498, L80245C38_166498, L80245C38_166498, L80245C38_166498, 0

glabel jtbl_8024BFA0
.word L80245DD0_166630, L802461E8_166A48, L8024672C_166F8C, L80246370_166BD0, L80246420_166C80, 0

glabel jtbl_8024BFB8
.word L80246920_167180, L8024692C_16718C, L8024692C_16718C, L8024692C_16718C, L8024692C_16718C, 0

glabel jtbl_8024BFD0
.word L80246960_1671C0, L80246A04_167264, L80246AFC_16735C, L80246A60_1672C0, L80246ABC_16731C, 0

.section .text

glabel filemenu_main_handle_input
/* 1662A0 80245A40 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1662A4 80245A44 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1662A8 80245A48 0080982D */  daddu     $s3, $a0, $zero
/* 1662AC 80245A4C 3C028025 */  lui       $v0, %hi(D_8024C08C)
/* 1662B0 80245A50 8C42C08C */  lw        $v0, %lo(D_8024C08C)($v0)
/* 1662B4 80245A54 3C030004 */  lui       $v1, 4
/* 1662B8 80245A58 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1662BC 80245A5C AFB20018 */  sw        $s2, 0x18($sp)
/* 1662C0 80245A60 AFB10014 */  sw        $s1, 0x14($sp)
/* 1662C4 80245A64 AFB00010 */  sw        $s0, 0x10($sp)
/* 1662C8 80245A68 92670003 */  lbu       $a3, 3($s3)
/* 1662CC 80245A6C 00431024 */  and       $v0, $v0, $v1
/* 1662D0 80245A70 1040001C */  beqz      $v0, .L80245AE4
/* 1662D4 80245A74 00000000 */   nop
.L80245A78:
/* 1662D8 80245A78 92620001 */  lbu       $v0, 1($s3)
/* 1662DC 80245A7C 2442FFFF */  addiu     $v0, $v0, -1
/* 1662E0 80245A80 A2620001 */  sb        $v0, 1($s3)
/* 1662E4 80245A84 00021600 */  sll       $v0, $v0, 0x18
/* 1662E8 80245A88 00022E03 */  sra       $a1, $v0, 0x18
/* 1662EC 80245A8C 04A20015 */  bltzl     $a1, .L80245AE4
/* 1662F0 80245A90 A2600001 */   sb       $zero, 1($s3)
/* 1662F4 80245A94 82620004 */  lb        $v0, 4($s3)
/* 1662F8 80245A98 82630005 */  lb        $v1, 5($s3)
/* 1662FC 80245A9C 00430018 */  mult      $v0, $v1
/* 166300 80245AA0 00006012 */  mflo      $t4
/* 166304 80245AA4 82620006 */  lb        $v0, 6($s3)
/* 166308 80245AA8 00000000 */  nop
/* 16630C 80245AAC 01820018 */  mult      $t4, $v0
/* 166310 80245AB0 00002012 */  mflo      $a0
/* 166314 80245AB4 82620002 */  lb        $v0, 2($s3)
/* 166318 80245AB8 00000000 */  nop
/* 16631C 80245ABC 00620018 */  mult      $v1, $v0
/* 166320 80245AC0 00001812 */  mflo      $v1
/* 166324 80245AC4 00831021 */  addu      $v0, $a0, $v1
/* 166328 80245AC8 00451021 */  addu      $v0, $v0, $a1
/* 16632C 80245ACC 8E630008 */  lw        $v1, 8($s3)
/* 166330 80245AD0 92640003 */  lbu       $a0, 3($s3)
/* 166334 80245AD4 00621821 */  addu      $v1, $v1, $v0
/* 166338 80245AD8 90620000 */  lbu       $v0, ($v1)
/* 16633C 80245ADC 1082FFE6 */  beq       $a0, $v0, .L80245A78
/* 166340 80245AE0 00000000 */   nop
.L80245AE4:
/* 166344 80245AE4 3C028025 */  lui       $v0, %hi(D_8024C08C)
/* 166348 80245AE8 8C42C08C */  lw        $v0, %lo(D_8024C08C)($v0)
/* 16634C 80245AEC 3C030008 */  lui       $v1, 8
/* 166350 80245AF0 00431024 */  and       $v0, $v0, $v1
/* 166354 80245AF4 1040001E */  beqz      $v0, .L80245B70
/* 166358 80245AF8 00000000 */   nop
/* 16635C 80245AFC 92660005 */  lbu       $a2, 5($s3)
/* 166360 80245B00 82650005 */  lb        $a1, 5($s3)
.L80245B04:
/* 166364 80245B04 92620001 */  lbu       $v0, 1($s3)
/* 166368 80245B08 24420001 */  addiu     $v0, $v0, 1
/* 16636C 80245B0C A2620001 */  sb        $v0, 1($s3)
/* 166370 80245B10 00021600 */  sll       $v0, $v0, 0x18
/* 166374 80245B14 00022603 */  sra       $a0, $v0, 0x18
/* 166378 80245B18 0085102A */  slt       $v0, $a0, $a1
/* 16637C 80245B1C 1040003A */  beqz      $v0, .L80245C08
/* 166380 80245B20 24C2FFFF */   addiu    $v0, $a2, -1
/* 166384 80245B24 82620004 */  lb        $v0, 4($s3)
/* 166388 80245B28 00450018 */  mult      $v0, $a1
/* 16638C 80245B2C 00001812 */  mflo      $v1
/* 166390 80245B30 82620006 */  lb        $v0, 6($s3)
/* 166394 80245B34 00000000 */  nop
/* 166398 80245B38 00620018 */  mult      $v1, $v0
/* 16639C 80245B3C 00001812 */  mflo      $v1
/* 1663A0 80245B40 82620002 */  lb        $v0, 2($s3)
/* 1663A4 80245B44 00000000 */  nop
/* 1663A8 80245B48 00A20018 */  mult      $a1, $v0
/* 1663AC 80245B4C 00006012 */  mflo      $t4
/* 1663B0 80245B50 006C1021 */  addu      $v0, $v1, $t4
/* 1663B4 80245B54 00441021 */  addu      $v0, $v0, $a0
/* 1663B8 80245B58 8E630008 */  lw        $v1, 8($s3)
/* 1663BC 80245B5C 92640003 */  lbu       $a0, 3($s3)
/* 1663C0 80245B60 00621821 */  addu      $v1, $v1, $v0
/* 1663C4 80245B64 90620000 */  lbu       $v0, ($v1)
/* 1663C8 80245B68 1082FFE6 */  beq       $a0, $v0, .L80245B04
/* 1663CC 80245B6C 00000000 */   nop
.L80245B70:
/* 1663D0 80245B70 3C028025 */  lui       $v0, %hi(D_8024C08C)
/* 1663D4 80245B74 8C42C08C */  lw        $v0, %lo(D_8024C08C)($v0)
/* 1663D8 80245B78 3C030001 */  lui       $v1, 1
/* 1663DC 80245B7C 00431024 */  and       $v0, $v0, $v1
/* 1663E0 80245B80 10400007 */  beqz      $v0, .L80245BA0
/* 1663E4 80245B84 00000000 */   nop
/* 1663E8 80245B88 92620002 */  lbu       $v0, 2($s3)
/* 1663EC 80245B8C 2442FFFF */  addiu     $v0, $v0, -1
/* 1663F0 80245B90 A2620002 */  sb        $v0, 2($s3)
/* 1663F4 80245B94 00021600 */  sll       $v0, $v0, 0x18
/* 1663F8 80245B98 04420001 */  bltzl     $v0, .L80245BA0
/* 1663FC 80245B9C A2600002 */   sb       $zero, 2($s3)
.L80245BA0:
/* 166400 80245BA0 3C028025 */  lui       $v0, %hi(D_8024C08C)
/* 166404 80245BA4 8C42C08C */  lw        $v0, %lo(D_8024C08C)($v0)
/* 166408 80245BA8 3C030002 */  lui       $v1, 2
/* 16640C 80245BAC 00431024 */  and       $v0, $v0, $v1
/* 166410 80245BB0 1040000C */  beqz      $v0, .L80245BE4
/* 166414 80245BB4 00000000 */   nop
/* 166418 80245BB8 92620002 */  lbu       $v0, 2($s3)
/* 16641C 80245BBC 82630006 */  lb        $v1, 6($s3)
/* 166420 80245BC0 24420001 */  addiu     $v0, $v0, 1
/* 166424 80245BC4 A2620002 */  sb        $v0, 2($s3)
/* 166428 80245BC8 00021600 */  sll       $v0, $v0, 0x18
/* 16642C 80245BCC 00021603 */  sra       $v0, $v0, 0x18
/* 166430 80245BD0 0043102A */  slt       $v0, $v0, $v1
/* 166434 80245BD4 92630006 */  lbu       $v1, 6($s3)
/* 166438 80245BD8 14400002 */  bnez      $v0, .L80245BE4
/* 16643C 80245BDC 2462FFFF */   addiu    $v0, $v1, -1
/* 166440 80245BE0 A2620002 */  sb        $v0, 2($s3)
.L80245BE4:
/* 166444 80245BE4 82630004 */  lb        $v1, 4($s3)
/* 166448 80245BE8 2C620005 */  sltiu     $v0, $v1, 5
/* 16644C 80245BEC 1040001F */  beqz      $v0, .L80245C6C
/* 166450 80245BF0 00031080 */   sll      $v0, $v1, 2
/* 166454 80245BF4 3C018025 */  lui       $at, %hi(jtbl_8024BF88)
/* 166458 80245BF8 00220821 */  addu      $at, $at, $v0
/* 16645C 80245BFC 8C22BF88 */  lw        $v0, %lo(jtbl_8024BF88)($at)
/* 166460 80245C00 00400008 */  jr        $v0
/* 166464 80245C04 00000000 */   nop
.L80245C08:
/* 166468 80245C08 080916DC */  j         .L80245B70
/* 16646C 80245C0C A2620001 */   sb       $v0, 1($s3)
glabel L80245C10_166470
/* 166470 80245C10 82630001 */  lb        $v1, 1($s3)
/* 166474 80245C14 24020001 */  addiu     $v0, $zero, 1
/* 166478 80245C18 14620014 */  bne       $v1, $v0, .L80245C6C
/* 16647C 80245C1C 00000000 */   nop
/* 166480 80245C20 92620002 */  lbu       $v0, 2($s3)
/* 166484 80245C24 2C420002 */  sltiu     $v0, $v0, 2
/* 166488 80245C28 54400010 */  bnel      $v0, $zero, .L80245C6C
/* 16648C 80245C2C A2600001 */   sb       $zero, 1($s3)
/* 166490 80245C30 0809171B */  j         .L80245C6C
/* 166494 80245C34 00000000 */   nop
glabel L80245C38_166498
/* 166498 80245C38 82630001 */  lb        $v1, 1($s3)
/* 16649C 80245C3C 24020001 */  addiu     $v0, $zero, 1
/* 1664A0 80245C40 14620005 */  bne       $v1, $v0, .L80245C58
/* 1664A4 80245C44 00000000 */   nop
/* 1664A8 80245C48 92620002 */  lbu       $v0, 2($s3)
/* 1664AC 80245C4C 2C420002 */  sltiu     $v0, $v0, 2
/* 1664B0 80245C50 54400001 */  bnel      $v0, $zero, .L80245C58
/* 1664B4 80245C54 A2600001 */   sb       $zero, 1($s3)
.L80245C58:
/* 1664B8 80245C58 82630002 */  lb        $v1, 2($s3)
/* 1664BC 80245C5C 24020002 */  addiu     $v0, $zero, 2
/* 1664C0 80245C60 14620002 */  bne       $v1, $v0, .L80245C6C
/* 1664C4 80245C64 24020001 */   addiu    $v0, $zero, 1
/* 1664C8 80245C68 A2620001 */  sb        $v0, 1($s3)
.L80245C6C:
/* 1664CC 80245C6C 82620004 */  lb        $v0, 4($s3)
/* 1664D0 80245C70 82630005 */  lb        $v1, 5($s3)
/* 1664D4 80245C74 00430018 */  mult      $v0, $v1
/* 1664D8 80245C78 00006012 */  mflo      $t4
/* 1664DC 80245C7C 82620006 */  lb        $v0, 6($s3)
/* 1664E0 80245C80 00000000 */  nop
/* 1664E4 80245C84 01820018 */  mult      $t4, $v0
/* 1664E8 80245C88 00002012 */  mflo      $a0
/* 1664EC 80245C8C 82620002 */  lb        $v0, 2($s3)
/* 1664F0 80245C90 00000000 */  nop
/* 1664F4 80245C94 00620018 */  mult      $v1, $v0
/* 1664F8 80245C98 00001812 */  mflo      $v1
/* 1664FC 80245C9C 00831821 */  addu      $v1, $a0, $v1
/* 166500 80245CA0 82640001 */  lb        $a0, 1($s3)
/* 166504 80245CA4 8E620008 */  lw        $v0, 8($s3)
/* 166508 80245CA8 00641821 */  addu      $v1, $v1, $a0
/* 16650C 80245CAC 00431021 */  addu      $v0, $v0, $v1
/* 166510 80245CB0 90420000 */  lbu       $v0, ($v0)
/* 166514 80245CB4 A2620003 */  sb        $v0, 3($s3)
/* 166518 80245CB8 304200FF */  andi      $v0, $v0, 0xff
/* 16651C 80245CBC 10E20003 */  beq       $a3, $v0, .L80245CCC
/* 166520 80245CC0 00000000 */   nop
/* 166524 80245CC4 0C05272D */  jal       sfx_play_sound
/* 166528 80245CC8 24042101 */   addiu    $a0, $zero, 0x2101
.L80245CCC:
/* 16652C 80245CCC 82620004 */  lb        $v0, 4($s3)
/* 166530 80245CD0 14400022 */  bnez      $v0, .L80245D5C
/* 166534 80245CD4 00000000 */   nop
/* 166538 80245CD8 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 16653C 80245CDC 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 166540 80245CE0 3C058025 */  lui       $a1, %hi(D_8024C084)
/* 166544 80245CE4 24A5C084 */  addiu     $a1, $a1, %lo(D_8024C084)
/* 166548 80245CE8 8CA20000 */  lw        $v0, ($a1)
/* 16654C 80245CEC 8E030000 */  lw        $v1, ($s0)
/* 166550 80245CF0 30422000 */  andi      $v0, $v0, 0x2000
/* 166554 80245CF4 906400AB */  lbu       $a0, 0xab($v1)
/* 166558 80245CF8 10400002 */  beqz      $v0, .L80245D04
/* 16655C 80245CFC 24020001 */   addiu    $v0, $zero, 1
/* 166560 80245D00 A06200AB */  sb        $v0, 0xab($v1)
.L80245D04:
/* 166564 80245D04 8CA20000 */  lw        $v0, ($a1)
/* 166568 80245D08 30420010 */  andi      $v0, $v0, 0x10
/* 16656C 80245D0C 10400003 */  beqz      $v0, .L80245D1C
/* 166570 80245D10 00000000 */   nop
/* 166574 80245D14 8E020000 */  lw        $v0, ($s0)
/* 166578 80245D18 A04000AB */  sb        $zero, 0xab($v0)
.L80245D1C:
/* 16657C 80245D1C 8E020000 */  lw        $v0, ($s0)
/* 166580 80245D20 904200AB */  lbu       $v0, 0xab($v0)
/* 166584 80245D24 1082000D */  beq       $a0, $v0, .L80245D5C
/* 166588 80245D28 00000000 */   nop
/* 16658C 80245D2C 0C05272D */  jal       sfx_play_sound
/* 166590 80245D30 240400C8 */   addiu    $a0, $zero, 0xc8
/* 166594 80245D34 8E020000 */  lw        $v0, ($s0)
/* 166598 80245D38 904200AB */  lbu       $v0, 0xab($v0)
/* 16659C 80245D3C 10400005 */  beqz      $v0, .L80245D54
/* 1665A0 80245D40 00000000 */   nop
/* 1665A4 80245D44 0C015857 */  jal       func_8005615C
/* 1665A8 80245D48 00000000 */   nop
/* 1665AC 80245D4C 08091757 */  j         .L80245D5C
/* 1665B0 80245D50 00000000 */   nop
.L80245D54:
/* 1665B4 80245D54 0C015860 */  jal       func_80056180
/* 1665B8 80245D58 00000000 */   nop
.L80245D5C:
/* 1665BC 80245D5C 3C038025 */  lui       $v1, %hi(D_8024C084)
/* 1665C0 80245D60 2463C084 */  addiu     $v1, $v1, %lo(D_8024C084)
/* 1665C4 80245D64 8C620000 */  lw        $v0, ($v1)
/* 1665C8 80245D68 30421000 */  andi      $v0, $v0, 0x1000
/* 1665CC 80245D6C 10400009 */  beqz      $v0, .L80245D94
/* 1665D0 80245D70 00000000 */   nop
/* 1665D4 80245D74 82620004 */  lb        $v0, 4($s3)
/* 1665D8 80245D78 14400006 */  bnez      $v0, .L80245D94
/* 1665DC 80245D7C 00000000 */   nop
/* 1665E0 80245D80 92620003 */  lbu       $v0, 3($s3)
/* 1665E4 80245D84 2C420004 */  sltiu     $v0, $v0, 4
/* 1665E8 80245D88 10400002 */  beqz      $v0, .L80245D94
/* 1665EC 80245D8C 34028000 */   ori      $v0, $zero, 0x8000
/* 1665F0 80245D90 AC620000 */  sw        $v0, ($v1)
.L80245D94:
/* 1665F4 80245D94 3C028025 */  lui       $v0, %hi(D_8024C084)
/* 1665F8 80245D98 8C42C084 */  lw        $v0, %lo(D_8024C084)($v0)
/* 1665FC 80245D9C 30428000 */  andi      $v0, $v0, 0x8000
/* 166600 80245DA0 104002D1 */  beqz      $v0, .L802468E8
/* 166604 80245DA4 00000000 */   nop
/* 166608 80245DA8 82630004 */  lb        $v1, 4($s3)
/* 16660C 80245DAC 2C620005 */  sltiu     $v0, $v1, 5
/* 166610 80245DB0 104002CD */  beqz      $v0, .L802468E8
/* 166614 80245DB4 0000202D */   daddu    $a0, $zero, $zero
/* 166618 80245DB8 00031080 */  sll       $v0, $v1, 2
/* 16661C 80245DBC 3C018025 */  lui       $at, %hi(jtbl_8024BFA0)
/* 166620 80245DC0 00220821 */  addu      $at, $at, $v0
/* 166624 80245DC4 8C22BFA0 */  lw        $v0, %lo(jtbl_8024BFA0)($at)
/* 166628 80245DC8 00400008 */  jr        $v0
/* 16662C 80245DCC 00000000 */   nop
glabel L80245DD0_166630
/* 166630 80245DD0 92620003 */  lbu       $v0, 3($s3)
/* 166634 80245DD4 2C420004 */  sltiu     $v0, $v0, 4
/* 166638 80245DD8 10400007 */  beqz      $v0, .L80245DF8
/* 16663C 80245DDC 00000000 */   nop
/* 166640 80245DE0 92620003 */  lbu       $v0, 3($s3)
/* 166644 80245DE4 3C018007 */  lui       $at, %hi(D_80077A24)
/* 166648 80245DE8 00220821 */  addu      $at, $at, $v0
/* 16664C 80245DEC 90227A24 */  lbu       $v0, %lo(D_80077A24)($at)
/* 166650 80245DF0 50400001 */  beql      $v0, $zero, .L80245DF8
/* 166654 80245DF4 24040001 */   addiu    $a0, $zero, 1
.L80245DF8:
/* 166658 80245DF8 10800040 */  beqz      $a0, .L80245EFC
/* 16665C 80245DFC 240400F7 */   addiu    $a0, $zero, 0xf7
/* 166660 80245E00 24030007 */  addiu     $v1, $zero, 7
/* 166664 80245E04 3C028025 */  lui       $v0, %hi(D_8024C117)
/* 166668 80245E08 2442C117 */  addiu     $v0, $v0, %lo(D_8024C117)
.L80245E0C:
/* 16666C 80245E0C A0440000 */  sb        $a0, ($v0)
/* 166670 80245E10 2463FFFF */  addiu     $v1, $v1, -1
/* 166674 80245E14 0461FFFD */  bgez      $v1, .L80245E0C
/* 166678 80245E18 2442FFFF */   addiu    $v0, $v0, -1
/* 16667C 80245E1C 24040030 */  addiu     $a0, $zero, 0x30
/* 166680 80245E20 3C108024 */  lui       $s0, %hi(filemenu_update_show_name_input)
/* 166684 80245E24 26103380 */  addiu     $s0, $s0, %lo(filemenu_update_show_name_input)
/* 166688 80245E28 3C018025 */  lui       $at, %hi(D_8024C090)
/* 16668C 80245E2C A020C090 */  sb        $zero, %lo(D_8024C090)($at)
/* 166690 80245E30 0C051F9F */  jal       set_window_update
/* 166694 80245E34 0200282D */   daddu    $a1, $s0, $zero
/* 166698 80245E38 24040031 */  addiu     $a0, $zero, 0x31
/* 16669C 80245E3C 0C051F9F */  jal       set_window_update
/* 1666A0 80245E40 0200282D */   daddu    $a1, $s0, $zero
/* 1666A4 80245E44 2404002D */  addiu     $a0, $zero, 0x2d
/* 1666A8 80245E48 3C108024 */  lui       $s0, %hi(filemenu_update_hidden_with_rotation)
/* 1666AC 80245E4C 26103898 */  addiu     $s0, $s0, %lo(filemenu_update_hidden_with_rotation)
/* 1666B0 80245E50 0C051F9F */  jal       set_window_update
/* 1666B4 80245E54 0200282D */   daddu    $a1, $s0, $zero
/* 1666B8 80245E58 24040033 */  addiu     $a0, $zero, 0x33
/* 1666BC 80245E5C 0C051F9F */  jal       set_window_update
/* 1666C0 80245E60 0200282D */   daddu    $a1, $s0, $zero
/* 1666C4 80245E64 24040034 */  addiu     $a0, $zero, 0x34
/* 1666C8 80245E68 0C051F9F */  jal       set_window_update
/* 1666CC 80245E6C 0200282D */   daddu    $a1, $s0, $zero
/* 1666D0 80245E70 24040035 */  addiu     $a0, $zero, 0x35
/* 1666D4 80245E74 0C051F9F */  jal       set_window_update
/* 1666D8 80245E78 0200282D */   daddu    $a1, $s0, $zero
/* 1666DC 80245E7C 24040036 */  addiu     $a0, $zero, 0x36
/* 1666E0 80245E80 0C051F9F */  jal       set_window_update
/* 1666E4 80245E84 0200282D */   daddu    $a1, $s0, $zero
/* 1666E8 80245E88 24040037 */  addiu     $a0, $zero, 0x37
/* 1666EC 80245E8C 0C051F9F */  jal       set_window_update
/* 1666F0 80245E90 0200282D */   daddu    $a1, $s0, $zero
/* 1666F4 80245E94 24040035 */  addiu     $a0, $zero, 0x35
/* 1666F8 80245E98 0C051F9F */  jal       set_window_update
/* 1666FC 80245E9C 0200282D */   daddu    $a1, $s0, $zero
/* 166700 80245EA0 24040038 */  addiu     $a0, $zero, 0x38
/* 166704 80245EA4 0C051F9F */  jal       set_window_update
/* 166708 80245EA8 0200282D */   daddu    $a1, $s0, $zero
/* 16670C 80245EAC 24040039 */  addiu     $a0, $zero, 0x39
/* 166710 80245EB0 0C051F9F */  jal       set_window_update
/* 166714 80245EB4 0200282D */   daddu    $a1, $s0, $zero
/* 166718 80245EB8 2404003A */  addiu     $a0, $zero, 0x3a
/* 16671C 80245EBC 0C051F9F */  jal       set_window_update
/* 166720 80245EC0 0200282D */   daddu    $a1, $s0, $zero
/* 166724 80245EC4 2404003B */  addiu     $a0, $zero, 0x3b
/* 166728 80245EC8 0C051F9F */  jal       set_window_update
/* 16672C 80245ECC 0200282D */   daddu    $a1, $s0, $zero
/* 166730 80245ED0 0C05272D */  jal       sfx_play_sound
/* 166734 80245ED4 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166738 80245ED8 0000282D */  daddu     $a1, $zero, $zero
/* 16673C 80245EDC 00A0302D */  daddu     $a2, $a1, $zero
/* 166740 80245EE0 3C048025 */  lui       $a0, %hi(D_80249B90)
/* 166744 80245EE4 8C849B90 */  lw        $a0, %lo(D_80249B90)($a0)
/* 166748 80245EE8 24020003 */  addiu     $v0, $zero, 3
/* 16674C 80245EEC 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 166750 80245EF0 A022C098 */  sb        $v0, %lo(D_8024C098_C09918)($at)
/* 166754 80245EF4 08091A38 */  j         .L802468E0
/* 166758 80245EF8 A0800004 */   sb       $zero, 4($a0)
.L80245EFC:
/* 16675C 80245EFC 92630003 */  lbu       $v1, 3($s3)
/* 166760 80245F00 24020006 */  addiu     $v0, $zero, 6
/* 166764 80245F04 1462002C */  bne       $v1, $v0, .L80245FB8
/* 166768 80245F08 24020004 */   addiu    $v0, $zero, 4
/* 16676C 80245F0C 24040033 */  addiu     $a0, $zero, 0x33
/* 166770 80245F10 3C128024 */  lui       $s2, %hi(filemenu_update_hidden_options_left)
/* 166774 80245F14 2652368C */  addiu     $s2, $s2, %lo(filemenu_update_hidden_options_left)
/* 166778 80245F18 0C051F9F */  jal       set_window_update
/* 16677C 80245F1C 0240282D */   daddu    $a1, $s2, $zero
/* 166780 80245F20 24040034 */  addiu     $a0, $zero, 0x34
/* 166784 80245F24 3C118024 */  lui       $s1, %hi(filemenu_update_hidden_options_right)
/* 166788 80245F28 263136F0 */  addiu     $s1, $s1, %lo(filemenu_update_hidden_options_right)
/* 16678C 80245F2C 0C051F9F */  jal       set_window_update
/* 166790 80245F30 0220282D */   daddu    $a1, $s1, $zero
/* 166794 80245F34 24040035 */  addiu     $a0, $zero, 0x35
/* 166798 80245F38 3C108024 */  lui       $s0, %hi(filemenu_update_hidden_options_bottom)
/* 16679C 80245F3C 261037B8 */  addiu     $s0, $s0, %lo(filemenu_update_hidden_options_bottom)
/* 1667A0 80245F40 0C051F9F */  jal       set_window_update
/* 1667A4 80245F44 0200282D */   daddu    $a1, $s0, $zero
/* 1667A8 80245F48 24040036 */  addiu     $a0, $zero, 0x36
/* 1667AC 80245F4C 0C051F9F */  jal       set_window_update
/* 1667B0 80245F50 0200282D */   daddu    $a1, $s0, $zero
/* 1667B4 80245F54 24040037 */  addiu     $a0, $zero, 0x37
/* 1667B8 80245F58 0C051F9F */  jal       set_window_update
/* 1667BC 80245F5C 0200282D */   daddu    $a1, $s0, $zero
/* 1667C0 80245F60 24040038 */  addiu     $a0, $zero, 0x38
/* 1667C4 80245F64 0C051F9F */  jal       set_window_update
/* 1667C8 80245F68 0240282D */   daddu    $a1, $s2, $zero
/* 1667CC 80245F6C 24040039 */  addiu     $a0, $zero, 0x39
/* 1667D0 80245F70 0C051F9F */  jal       set_window_update
/* 1667D4 80245F74 0220282D */   daddu    $a1, $s1, $zero
/* 1667D8 80245F78 2404003A */  addiu     $a0, $zero, 0x3a
/* 1667DC 80245F7C 0C051F9F */  jal       set_window_update
/* 1667E0 80245F80 0240282D */   daddu    $a1, $s2, $zero
/* 1667E4 80245F84 2404003B */  addiu     $a0, $zero, 0x3b
/* 1667E8 80245F88 0C051F9F */  jal       set_window_update
/* 1667EC 80245F8C 0220282D */   daddu    $a1, $s1, $zero
/* 1667F0 80245F90 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_title)
/* 1667F4 80245F94 24A53754 */  addiu     $a1, $a1, %lo(filemenu_update_hidden_title)
/* 1667F8 80245F98 0C051F9F */  jal       set_window_update
/* 1667FC 80245F9C 2404002D */   addiu    $a0, $zero, 0x2d
/* 166800 80245FA0 0C05272D */  jal       sfx_play_sound
/* 166804 80245FA4 240400D6 */   addiu    $a0, $zero, 0xd6
/* 166808 80245FA8 0C00CD3C */  jal       set_game_mode
/* 16680C 80245FAC 2404000F */   addiu    $a0, $zero, 0xf
/* 166810 80245FB0 08091A3A */  j         .L802468E8
/* 166814 80245FB4 00000000 */   nop
.L80245FB8:
/* 166818 80245FB8 14620005 */  bne       $v1, $v0, .L80245FD0
/* 16681C 80245FBC 24020005 */   addiu    $v0, $zero, 5
/* 166820 80245FC0 0C05272D */  jal       sfx_play_sound
/* 166824 80245FC4 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166828 80245FC8 080917F9 */  j         .L80245FE4
/* 16682C 80245FCC 24020001 */   addiu    $v0, $zero, 1
.L80245FD0:
/* 166830 80245FD0 1462001B */  bne       $v1, $v0, .L80246040
/* 166834 80245FD4 2C620004 */   sltiu    $v0, $v1, 4
/* 166838 80245FD8 0C05272D */  jal       sfx_play_sound
/* 16683C 80245FDC 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166840 80245FE0 24020003 */  addiu     $v0, $zero, 3
.L80245FE4:
/* 166844 80245FE4 A2620004 */  sb        $v0, 4($s3)
/* 166848 80245FE8 0260202D */  daddu     $a0, $s3, $zero
/* 16684C 80245FEC 24050001 */  addiu     $a1, $zero, 1
/* 166850 80245FF0 0C090B65 */  jal       filemenu_set_selected
/* 166854 80245FF4 24060002 */   addiu    $a2, $zero, 2
/* 166858 80245FF8 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_options_left)
/* 16685C 80245FFC 24A5368C */  addiu     $a1, $a1, %lo(filemenu_update_hidden_options_left)
/* 166860 80246000 0C051F9F */  jal       set_window_update
/* 166864 80246004 24040033 */   addiu    $a0, $zero, 0x33
/* 166868 80246008 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_options_right)
/* 16686C 8024600C 24A536F0 */  addiu     $a1, $a1, %lo(filemenu_update_hidden_options_right)
/* 166870 80246010 0C051F9F */  jal       set_window_update
/* 166874 80246014 24040034 */   addiu    $a0, $zero, 0x34
/* 166878 80246018 24040035 */  addiu     $a0, $zero, 0x35
/* 16687C 8024601C 3C108024 */  lui       $s0, %hi(filemenu_update_hidden_options_bottom)
/* 166880 80246020 261037B8 */  addiu     $s0, $s0, %lo(filemenu_update_hidden_options_bottom)
/* 166884 80246024 0C051F9F */  jal       set_window_update
/* 166888 80246028 0200282D */   daddu    $a1, $s0, $zero
/* 16688C 8024602C 24040037 */  addiu     $a0, $zero, 0x37
/* 166890 80246030 0C051F9F */  jal       set_window_update
/* 166894 80246034 0200282D */   daddu    $a1, $s0, $zero
/* 166898 80246038 08091A3A */  j         .L802468E8
/* 16689C 8024603C 00000000 */   nop
.L80246040:
/* 1668A0 80246040 10400229 */  beqz      $v0, .L802468E8
/* 1668A4 80246044 00000000 */   nop
/* 1668A8 80246048 0C05272D */  jal       sfx_play_sound
/* 1668AC 8024604C 240400C9 */   addiu    $a0, $zero, 0xc9
/* 1668B0 80246050 2404002D */  addiu     $a0, $zero, 0x2d
/* 1668B4 80246054 3C108024 */  lui       $s0, %hi(filemenu_update_hidden_with_rotation)
/* 1668B8 80246058 26103898 */  addiu     $s0, $s0, %lo(filemenu_update_hidden_with_rotation)
/* 1668BC 8024605C 0C051F9F */  jal       set_window_update
/* 1668C0 80246060 0200282D */   daddu    $a1, $s0, $zero
/* 1668C4 80246064 24040033 */  addiu     $a0, $zero, 0x33
/* 1668C8 80246068 0C051F9F */  jal       set_window_update
/* 1668CC 8024606C 0200282D */   daddu    $a1, $s0, $zero
/* 1668D0 80246070 24040034 */  addiu     $a0, $zero, 0x34
/* 1668D4 80246074 0C051F9F */  jal       set_window_update
/* 1668D8 80246078 0200282D */   daddu    $a1, $s0, $zero
/* 1668DC 8024607C 24040035 */  addiu     $a0, $zero, 0x35
/* 1668E0 80246080 0C051F9F */  jal       set_window_update
/* 1668E4 80246084 0200282D */   daddu    $a1, $s0, $zero
/* 1668E8 80246088 24040036 */  addiu     $a0, $zero, 0x36
/* 1668EC 8024608C 0C051F9F */  jal       set_window_update
/* 1668F0 80246090 0200282D */   daddu    $a1, $s0, $zero
/* 1668F4 80246094 24040037 */  addiu     $a0, $zero, 0x37
/* 1668F8 80246098 0C051F9F */  jal       set_window_update
/* 1668FC 8024609C 0200282D */   daddu    $a1, $s0, $zero
/* 166900 802460A0 24040035 */  addiu     $a0, $zero, 0x35
/* 166904 802460A4 0C051F9F */  jal       set_window_update
/* 166908 802460A8 0200282D */   daddu    $a1, $s0, $zero
/* 16690C 802460AC 24040038 */  addiu     $a0, $zero, 0x38
/* 166910 802460B0 0C051F9F */  jal       set_window_update
/* 166914 802460B4 0200282D */   daddu    $a1, $s0, $zero
/* 166918 802460B8 24040039 */  addiu     $a0, $zero, 0x39
/* 16691C 802460BC 0C051F9F */  jal       set_window_update
/* 166920 802460C0 0200282D */   daddu    $a1, $s0, $zero
/* 166924 802460C4 2404003A */  addiu     $a0, $zero, 0x3a
/* 166928 802460C8 0C051F9F */  jal       set_window_update
/* 16692C 802460CC 0200282D */   daddu    $a1, $s0, $zero
/* 166930 802460D0 2404003B */  addiu     $a0, $zero, 0x3b
/* 166934 802460D4 0C051F9F */  jal       set_window_update
/* 166938 802460D8 0200282D */   daddu    $a1, $s0, $zero
/* 16693C 802460DC 92640003 */  lbu       $a0, 3($s3)
/* 166940 802460E0 3C058024 */  lui       $a1, %hi(filemenu_update_select_file)
/* 166944 802460E4 24A53908 */  addiu     $a1, $a1, %lo(filemenu_update_select_file)
/* 166948 802460E8 0C051F9F */  jal       set_window_update
/* 16694C 802460EC 24840038 */   addiu    $a0, $a0, 0x38
/* 166950 802460F0 0C05272D */  jal       sfx_play_sound
/* 166954 802460F4 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166958 802460F8 24040032 */  addiu     $a0, $zero, 0x32
/* 16695C 802460FC 0C051F9F */  jal       set_window_update
/* 166960 80246100 24050001 */   addiu    $a1, $zero, 1
/* 166964 80246104 3C048016 */  lui       $a0, %hi(gWindows)
/* 166968 80246108 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 16696C 8024610C 2402008F */  addiu     $v0, $zero, 0x8f
/* 166970 80246110 A482064E */  sh        $v0, 0x64e($a0)
/* 166974 80246114 24020045 */  addiu     $v0, $zero, 0x45
/* 166978 80246118 A4820650 */  sh        $v0, 0x650($a0)
/* 16697C 8024611C 2402002C */  addiu     $v0, $zero, 0x2c
/* 166980 80246120 80830643 */  lb        $v1, 0x643($a0)
/* 166984 80246124 A4820652 */  sh        $v0, 0x652($a0)
/* 166988 80246128 2402FFFF */  addiu     $v0, $zero, -1
/* 16698C 8024612C 1062000B */  beq       $v1, $v0, .L8024615C
/* 166990 80246130 2485064C */   addiu    $a1, $a0, 0x64c
/* 166994 80246134 00031140 */  sll       $v0, $v1, 5
/* 166998 80246138 00441021 */  addu      $v0, $v0, $a0
/* 16699C 8024613C 94420010 */  lhu       $v0, 0x10($v0)
/* 1669A0 80246140 00021400 */  sll       $v0, $v0, 0x10
/* 1669A4 80246144 00021C03 */  sra       $v1, $v0, 0x10
/* 1669A8 80246148 000217C2 */  srl       $v0, $v0, 0x1f
/* 1669AC 8024614C 00621821 */  addu      $v1, $v1, $v0
/* 1669B0 80246150 00031843 */  sra       $v1, $v1, 1
/* 1669B4 80246154 0809185A */  j         .L80246168
/* 1669B8 80246158 2463FFDE */   addiu    $v1, $v1, -0x22
.L8024615C:
/* 1669BC 8024615C 2403007E */  addiu     $v1, $zero, 0x7e
/* 1669C0 80246160 3C048016 */  lui       $a0, %hi(gWindows)
/* 1669C4 80246164 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L80246168:
/* 1669C8 80246168 2402FFE3 */  addiu     $v0, $zero, -0x1d
/* 1669CC 8024616C A4A30000 */  sh        $v1, ($a1)
/* 1669D0 80246170 A48205CE */  sh        $v0, 0x5ce($a0)
/* 1669D4 80246174 240200C0 */  addiu     $v0, $zero, 0xc0
/* 1669D8 80246178 A48205D0 */  sh        $v0, 0x5d0($a0)
/* 1669DC 8024617C 24020019 */  addiu     $v0, $zero, 0x19
/* 1669E0 80246180 808305C3 */  lb        $v1, 0x5c3($a0)
/* 1669E4 80246184 A48205D2 */  sh        $v0, 0x5d2($a0)
/* 1669E8 80246188 2402FFFF */  addiu     $v0, $zero, -1
/* 1669EC 8024618C 1062000B */  beq       $v1, $v0, .L802461BC
/* 1669F0 80246190 248705CC */   addiu    $a3, $a0, 0x5cc
/* 1669F4 80246194 00031140 */  sll       $v0, $v1, 5
/* 1669F8 80246198 00441021 */  addu      $v0, $v0, $a0
/* 1669FC 8024619C 94420010 */  lhu       $v0, 0x10($v0)
/* 166A00 802461A0 00021400 */  sll       $v0, $v0, 0x10
/* 166A04 802461A4 00021C03 */  sra       $v1, $v0, 0x10
/* 166A08 802461A8 000217C2 */  srl       $v0, $v0, 0x1f
/* 166A0C 802461AC 00621821 */  addu      $v1, $v1, $v0
/* 166A10 802461B0 00031843 */  sra       $v1, $v1, 1
/* 166A14 802461B4 08091870 */  j         .L802461C0
/* 166A18 802461B8 2463FFA0 */   addiu    $v1, $v1, -0x60
.L802461BC:
/* 166A1C 802461BC 24030040 */  addiu     $v1, $zero, 0x40
.L802461C0:
/* 166A20 802461C0 0000282D */  daddu     $a1, $zero, $zero
/* 166A24 802461C4 00A0302D */  daddu     $a2, $a1, $zero
/* 166A28 802461C8 A4E30000 */  sh        $v1, ($a3)
/* 166A2C 802461CC 3C048025 */  lui       $a0, %hi(D_80249B88)
/* 166A30 802461D0 8C849B88 */  lw        $a0, %lo(D_80249B88)($a0)
/* 166A34 802461D4 24020001 */  addiu     $v0, $zero, 1
/* 166A38 802461D8 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 166A3C 802461DC A022C098 */  sb        $v0, %lo(D_8024C098_C09918)($at)
/* 166A40 802461E0 08091A37 */  j         .L802468DC
/* 166A44 802461E4 24020004 */   addiu    $v0, $zero, 4
glabel L802461E8_166A48
/* 166A48 802461E8 92630003 */  lbu       $v1, 3($s3)
/* 166A4C 802461EC 24020006 */  addiu     $v0, $zero, 6
/* 166A50 802461F0 14620018 */  bne       $v1, $v0, .L80246254
/* 166A54 802461F4 2C620004 */   sltiu    $v0, $v1, 4
/* 166A58 802461F8 0C05272D */  jal       sfx_play_sound
/* 166A5C 802461FC 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166A60 80246200 A2600004 */  sb        $zero, 4($s3)
/* 166A64 80246204 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_left)
/* 166A68 80246208 24A533F4 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_left)
/* 166A6C 8024620C 0C051F9F */  jal       set_window_update
/* 166A70 80246210 24040033 */   addiu    $a0, $zero, 0x33
/* 166A74 80246214 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_right)
/* 166A78 80246218 24A53468 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_right)
/* 166A7C 8024621C 0C051F9F */  jal       set_window_update
/* 166A80 80246220 24040034 */   addiu    $a0, $zero, 0x34
/* 166A84 80246224 24040035 */  addiu     $a0, $zero, 0x35
/* 166A88 80246228 3C108024 */  lui       $s0, %hi(filemenu_update_show_options_bottom)
/* 166A8C 8024622C 261034DC */  addiu     $s0, $s0, %lo(filemenu_update_show_options_bottom)
/* 166A90 80246230 0C051F9F */  jal       set_window_update
/* 166A94 80246234 0200282D */   daddu    $a1, $s0, $zero
/* 166A98 80246238 24040037 */  addiu     $a0, $zero, 0x37
/* 166A9C 8024623C 0C051F9F */  jal       set_window_update
/* 166AA0 80246240 0200282D */   daddu    $a1, $s0, $zero
/* 166AA4 80246244 0260202D */  daddu     $a0, $s3, $zero
/* 166AA8 80246248 0000282D */  daddu     $a1, $zero, $zero
/* 166AAC 8024624C 08091A38 */  j         .L802468E0
/* 166AB0 80246250 24060002 */   addiu    $a2, $zero, 2
.L80246254:
/* 166AB4 80246254 104001A4 */  beqz      $v0, .L802468E8
/* 166AB8 80246258 00000000 */   nop
/* 166ABC 8024625C 92620003 */  lbu       $v0, 3($s3)
/* 166AC0 80246260 3C018007 */  lui       $at, %hi(D_80077A24)
/* 166AC4 80246264 00220821 */  addu      $at, $at, $v0
/* 166AC8 80246268 90227A24 */  lbu       $v0, %lo(D_80077A24)($at)
/* 166ACC 8024626C 1040007F */  beqz      $v0, .L8024646C
/* 166AD0 80246270 00000000 */   nop
/* 166AD4 80246274 0C05272D */  jal       sfx_play_sound
/* 166AD8 80246278 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166ADC 8024627C 3C058024 */  lui       $a1, %hi(filemenu_update_show_name_confirm)
/* 166AE0 80246280 24A53CCC */  addiu     $a1, $a1, %lo(filemenu_update_show_name_confirm)
/* 166AE4 80246284 0C051F9F */  jal       set_window_update
/* 166AE8 80246288 24040032 */   addiu    $a0, $zero, 0x32
/* 166AEC 8024628C 3C048016 */  lui       $a0, %hi(gWindows)
/* 166AF0 80246290 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 166AF4 80246294 24020079 */  addiu     $v0, $zero, 0x79
/* 166AF8 80246298 A482064E */  sh        $v0, 0x64e($a0)
/* 166AFC 8024629C 24020045 */  addiu     $v0, $zero, 0x45
/* 166B00 802462A0 A4820650 */  sh        $v0, 0x650($a0)
/* 166B04 802462A4 2402002C */  addiu     $v0, $zero, 0x2c
/* 166B08 802462A8 80830643 */  lb        $v1, 0x643($a0)
/* 166B0C 802462AC A4820652 */  sh        $v0, 0x652($a0)
/* 166B10 802462B0 2402FFFF */  addiu     $v0, $zero, -1
/* 166B14 802462B4 1062000B */  beq       $v1, $v0, .L802462E4
/* 166B18 802462B8 2485064C */   addiu    $a1, $a0, 0x64c
/* 166B1C 802462BC 00031140 */  sll       $v0, $v1, 5
/* 166B20 802462C0 00441021 */  addu      $v0, $v0, $a0
/* 166B24 802462C4 94420010 */  lhu       $v0, 0x10($v0)
/* 166B28 802462C8 00021400 */  sll       $v0, $v0, 0x10
/* 166B2C 802462CC 00021C03 */  sra       $v1, $v0, 0x10
/* 166B30 802462D0 000217C2 */  srl       $v0, $v0, 0x1f
/* 166B34 802462D4 00621821 */  addu      $v1, $v1, $v0
/* 166B38 802462D8 00031843 */  sra       $v1, $v1, 1
/* 166B3C 802462DC 080918BC */  j         .L802462F0
/* 166B40 802462E0 2463FFDE */   addiu    $v1, $v1, -0x22
.L802462E4:
/* 166B44 802462E4 2403007E */  addiu     $v1, $zero, 0x7e
/* 166B48 802462E8 3C048016 */  lui       $a0, %hi(gWindows)
/* 166B4C 802462EC 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L802462F0:
/* 166B50 802462F0 2402FFE3 */  addiu     $v0, $zero, -0x1d
/* 166B54 802462F4 A4A30000 */  sh        $v1, ($a1)
/* 166B58 802462F8 A48205CE */  sh        $v0, 0x5ce($a0)
/* 166B5C 802462FC 24020076 */  addiu     $v0, $zero, 0x76
/* 166B60 80246300 A48205D0 */  sh        $v0, 0x5d0($a0)
/* 166B64 80246304 24020019 */  addiu     $v0, $zero, 0x19
/* 166B68 80246308 808305C3 */  lb        $v1, 0x5c3($a0)
/* 166B6C 8024630C A48205D2 */  sh        $v0, 0x5d2($a0)
/* 166B70 80246310 2402FFFF */  addiu     $v0, $zero, -1
/* 166B74 80246314 1062000B */  beq       $v1, $v0, .L80246344
/* 166B78 80246318 248705CC */   addiu    $a3, $a0, 0x5cc
/* 166B7C 8024631C 00031140 */  sll       $v0, $v1, 5
/* 166B80 80246320 00441021 */  addu      $v0, $v0, $a0
/* 166B84 80246324 94420010 */  lhu       $v0, 0x10($v0)
/* 166B88 80246328 00021400 */  sll       $v0, $v0, 0x10
/* 166B8C 8024632C 00021C03 */  sra       $v1, $v0, 0x10
/* 166B90 80246330 000217C2 */  srl       $v0, $v0, 0x1f
/* 166B94 80246334 00621821 */  addu      $v1, $v1, $v0
/* 166B98 80246338 00031843 */  sra       $v1, $v1, 1
/* 166B9C 8024633C 080918D2 */  j         .L80246348
/* 166BA0 80246340 2463FFC5 */   addiu    $v1, $v1, -0x3b
.L80246344:
/* 166BA4 80246344 24030065 */  addiu     $v1, $zero, 0x65
.L80246348:
/* 166BA8 80246348 0000282D */  daddu     $a1, $zero, $zero
/* 166BAC 8024634C 24060001 */  addiu     $a2, $zero, 1
/* 166BB0 80246350 A4E30000 */  sh        $v1, ($a3)
/* 166BB4 80246354 3C048025 */  lui       $a0, %hi(D_80249B88)
/* 166BB8 80246358 8C849B88 */  lw        $a0, %lo(D_80249B88)($a0)
/* 166BBC 8024635C 00C0102D */  daddu     $v0, $a2, $zero
/* 166BC0 80246360 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 166BC4 80246364 A022C098 */  sb        $v0, %lo(D_8024C098_C09918)($at)
/* 166BC8 80246368 08091A38 */  j         .L802468E0
/* 166BCC 8024636C A0800004 */   sb       $zero, 4($a0)
glabel L80246370_166BD0
/* 166BD0 80246370 92630003 */  lbu       $v1, 3($s3)
/* 166BD4 80246374 24020006 */  addiu     $v0, $zero, 6
/* 166BD8 80246378 14620018 */  bne       $v1, $v0, .L802463DC
/* 166BDC 8024637C 2C620004 */   sltiu    $v0, $v1, 4
/* 166BE0 80246380 0C05272D */  jal       sfx_play_sound
/* 166BE4 80246384 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166BE8 80246388 A2600004 */  sb        $zero, 4($s3)
/* 166BEC 8024638C 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_left)
/* 166BF0 80246390 24A533F4 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_left)
/* 166BF4 80246394 0C051F9F */  jal       set_window_update
/* 166BF8 80246398 24040033 */   addiu    $a0, $zero, 0x33
/* 166BFC 8024639C 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_right)
/* 166C00 802463A0 24A53468 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_right)
/* 166C04 802463A4 0C051F9F */  jal       set_window_update
/* 166C08 802463A8 24040034 */   addiu    $a0, $zero, 0x34
/* 166C0C 802463AC 24040035 */  addiu     $a0, $zero, 0x35
/* 166C10 802463B0 3C108024 */  lui       $s0, %hi(filemenu_update_show_options_bottom)
/* 166C14 802463B4 261034DC */  addiu     $s0, $s0, %lo(filemenu_update_show_options_bottom)
/* 166C18 802463B8 0C051F9F */  jal       set_window_update
/* 166C1C 802463BC 0200282D */   daddu    $a1, $s0, $zero
/* 166C20 802463C0 24040037 */  addiu     $a0, $zero, 0x37
/* 166C24 802463C4 0C051F9F */  jal       set_window_update
/* 166C28 802463C8 0200282D */   daddu    $a1, $s0, $zero
/* 166C2C 802463CC 0260202D */  daddu     $a0, $s3, $zero
/* 166C30 802463D0 0000282D */  daddu     $a1, $zero, $zero
/* 166C34 802463D4 08091A38 */  j         .L802468E0
/* 166C38 802463D8 24060001 */   addiu    $a2, $zero, 1
.L802463DC:
/* 166C3C 802463DC 10400142 */  beqz      $v0, .L802468E8
/* 166C40 802463E0 00000000 */   nop
/* 166C44 802463E4 92620003 */  lbu       $v0, 3($s3)
/* 166C48 802463E8 3C018007 */  lui       $at, %hi(D_80077A24)
/* 166C4C 802463EC 00220821 */  addu      $at, $at, $v0
/* 166C50 802463F0 90227A24 */  lbu       $v0, %lo(D_80077A24)($at)
/* 166C54 802463F4 1040001D */  beqz      $v0, .L8024646C
/* 166C58 802463F8 00000000 */   nop
/* 166C5C 802463FC 0C05272D */  jal       sfx_play_sound
/* 166C60 80246400 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166C64 80246404 92630003 */  lbu       $v1, 3($s3)
/* 166C68 80246408 24020004 */  addiu     $v0, $zero, 4
/* 166C6C 8024640C A2620004 */  sb        $v0, 4($s3)
/* 166C70 80246410 3C018025 */  lui       $at, %hi(D_8024C094)
/* 166C74 80246414 AC23C094 */  sw        $v1, %lo(D_8024C094)($at)
/* 166C78 80246418 08091A3A */  j         .L802468E8
/* 166C7C 8024641C 00000000 */   nop
glabel L80246420_166C80
/* 166C80 80246420 92630003 */  lbu       $v1, 3($s3)
/* 166C84 80246424 24020006 */  addiu     $v0, $zero, 6
/* 166C88 80246428 14620009 */  bne       $v1, $v0, .L80246450
/* 166C8C 8024642C 2C620004 */   sltiu    $v0, $v1, 4
/* 166C90 80246430 0C05272D */  jal       sfx_play_sound
/* 166C94 80246434 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166C98 80246438 24020003 */  addiu     $v0, $zero, 3
/* 166C9C 8024643C A2620004 */  sb        $v0, 4($s3)
/* 166CA0 80246440 0260202D */  daddu     $a0, $s3, $zero
/* 166CA4 80246444 0000282D */  daddu     $a1, $zero, $zero
/* 166CA8 80246448 08091A38 */  j         .L802468E0
/* 166CAC 8024644C 24060002 */   addiu    $a2, $zero, 2
.L80246450:
/* 166CB0 80246450 10400125 */  beqz      $v0, .L802468E8
/* 166CB4 80246454 00000000 */   nop
/* 166CB8 80246458 92630003 */  lbu       $v1, 3($s3)
/* 166CBC 8024645C 3C028025 */  lui       $v0, %hi(D_8024C094)
/* 166CC0 80246460 8C42C094 */  lw        $v0, %lo(D_8024C094)($v0)
/* 166CC4 80246464 14430005 */  bne       $v0, $v1, .L8024647C
/* 166CC8 80246468 00000000 */   nop
.L8024646C:
/* 166CCC 8024646C 0C05272D */  jal       sfx_play_sound
/* 166CD0 80246470 2404021D */   addiu    $a0, $zero, 0x21d
/* 166CD4 80246474 08091A3A */  j         .L802468E8
/* 166CD8 80246478 00000000 */   nop
.L8024647C:
/* 166CDC 8024647C 3C018025 */  lui       $at, %hi(D_8024C080)
/* 166CE0 80246480 AC23C080 */  sw        $v1, %lo(D_8024C080)($at)
/* 166CE4 80246484 92620003 */  lbu       $v0, 3($s3)
/* 166CE8 80246488 3C018007 */  lui       $at, %hi(D_80077A24)
/* 166CEC 8024648C 00220821 */  addu      $at, $at, $v0
/* 166CF0 80246490 90227A24 */  lbu       $v0, %lo(D_80077A24)($at)
/* 166CF4 80246494 14400066 */  bnez      $v0, .L80246630
/* 166CF8 80246498 00000000 */   nop
/* 166CFC 8024649C 0C05272D */  jal       sfx_play_sound
/* 166D00 802464A0 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166D04 802464A4 24020002 */  addiu     $v0, $zero, 2
/* 166D08 802464A8 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 166D0C 802464AC A022C098 */  sb        $v0, %lo(D_8024C098_C09918)($at)
/* 166D10 802464B0 24020002 */  addiu     $v0, $zero, 2
/* 166D14 802464B4 3C048016 */  lui       $a0, %hi(gWindows)
/* 166D18 802464B8 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 166D1C 802464BC 3C038025 */  lui       $v1, %hi(D_80249B8C)
/* 166D20 802464C0 8C639B8C */  lw        $v1, %lo(D_80249B8C)($v1)
/* 166D24 802464C4 A0620004 */  sb        $v0, 4($v1)
/* 166D28 802464C8 808305E3 */  lb        $v1, 0x5e3($a0)
/* 166D2C 802464CC 2402009A */  addiu     $v0, $zero, 0x9a
/* 166D30 802464D0 A48205F0 */  sh        $v0, 0x5f0($a0)
/* 166D34 802464D4 24020027 */  addiu     $v0, $zero, 0x27
/* 166D38 802464D8 A48205F2 */  sh        $v0, 0x5f2($a0)
/* 166D3C 802464DC 2402FFFF */  addiu     $v0, $zero, -1
/* 166D40 802464E0 1062000B */  beq       $v1, $v0, .L80246510
/* 166D44 802464E4 248505EC */   addiu    $a1, $a0, 0x5ec
/* 166D48 802464E8 00031140 */  sll       $v0, $v1, 5
/* 166D4C 802464EC 00441021 */  addu      $v0, $v0, $a0
/* 166D50 802464F0 94420010 */  lhu       $v0, 0x10($v0)
/* 166D54 802464F4 00021400 */  sll       $v0, $v0, 0x10
/* 166D58 802464F8 00021C03 */  sra       $v1, $v0, 0x10
/* 166D5C 802464FC 000217C2 */  srl       $v0, $v0, 0x1f
/* 166D60 80246500 00621821 */  addu      $v1, $v1, $v0
/* 166D64 80246504 00031843 */  sra       $v1, $v1, 1
/* 166D68 80246508 08091947 */  j         .L8024651C
/* 166D6C 8024650C 2463FFB3 */   addiu    $v1, $v1, -0x4d
.L80246510:
/* 166D70 80246510 24030053 */  addiu     $v1, $zero, 0x53
/* 166D74 80246514 3C048016 */  lui       $a0, %hi(gWindows)
/* 166D78 80246518 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L8024651C:
/* 166D7C 8024651C A4A30000 */  sh        $v1, ($a1)
/* 166D80 80246520 948205F2 */  lhu       $v0, 0x5f2($a0)
/* 166D84 80246524 00021400 */  sll       $v0, $v0, 0x10
/* 166D88 80246528 00021C03 */  sra       $v1, $v0, 0x10
/* 166D8C 8024652C 000217C2 */  srl       $v0, $v0, 0x1f
/* 166D90 80246530 00621821 */  addu      $v1, $v1, $v0
/* 166D94 80246534 00032843 */  sra       $a1, $v1, 1
/* 166D98 80246538 808305E3 */  lb        $v1, 0x5e3($a0)
/* 166D9C 8024653C 2402FFFF */  addiu     $v0, $zero, -1
/* 166DA0 80246540 1062000B */  beq       $v1, $v0, .L80246570
/* 166DA4 80246544 248605EE */   addiu    $a2, $a0, 0x5ee
/* 166DA8 80246548 00031140 */  sll       $v0, $v1, 5
/* 166DAC 8024654C 00441021 */  addu      $v0, $v0, $a0
/* 166DB0 80246550 94420012 */  lhu       $v0, 0x12($v0)
/* 166DB4 80246554 00021400 */  sll       $v0, $v0, 0x10
/* 166DB8 80246558 00021C03 */  sra       $v1, $v0, 0x10
/* 166DBC 8024655C 000217C2 */  srl       $v0, $v0, 0x1f
/* 166DC0 80246560 00621821 */  addu      $v1, $v1, $v0
/* 166DC4 80246564 00031843 */  sra       $v1, $v1, 1
/* 166DC8 80246568 0809195E */  j         .L80246578
/* 166DCC 8024656C 00651023 */   subu     $v0, $v1, $a1
.L80246570:
/* 166DD0 80246570 24020078 */  addiu     $v0, $zero, 0x78
/* 166DD4 80246574 00451023 */  subu      $v0, $v0, $a1
.L80246578:
/* 166DD8 80246578 2404002F */  addiu     $a0, $zero, 0x2f
/* 166DDC 8024657C 24050001 */  addiu     $a1, $zero, 1
/* 166DE0 80246580 0C051F9F */  jal       set_window_update
/* 166DE4 80246584 A4C20000 */   sh       $v0, ($a2)
/* 166DE8 80246588 24040032 */  addiu     $a0, $zero, 0x32
/* 166DEC 8024658C 0C051F9F */  jal       set_window_update
/* 166DF0 80246590 24050002 */   addiu    $a1, $zero, 2
/* 166DF4 80246594 3C118025 */  lui       $s1, %hi(D_8024C094)
/* 166DF8 80246598 2631C094 */  addiu     $s1, $s1, %lo(D_8024C094)
/* 166DFC 8024659C 0C00ACB4 */  jal       fio_load_game
/* 166E00 802465A0 8E240000 */   lw       $a0, ($s1)
/* 166E04 802465A4 3C108025 */  lui       $s0, %hi(D_8024C080)
/* 166E08 802465A8 2610C080 */  addiu     $s0, $s0, %lo(D_8024C080)
/* 166E0C 802465AC 3C068007 */  lui       $a2, %hi(D_800779C4)
/* 166E10 802465B0 24C679C4 */  addiu     $a2, $a2, %lo(D_800779C4)
/* 166E14 802465B4 8E040000 */  lw        $a0, ($s0)
/* 166E18 802465B8 8E250000 */  lw        $a1, ($s1)
/* 166E1C 802465BC 0080102D */  daddu     $v0, $a0, $zero
/* 166E20 802465C0 00021840 */  sll       $v1, $v0, 1
/* 166E24 802465C4 00621821 */  addu      $v1, $v1, $v0
/* 166E28 802465C8 000318C0 */  sll       $v1, $v1, 3
/* 166E2C 802465CC 00661821 */  addu      $v1, $v1, $a2
/* 166E30 802465D0 00051040 */  sll       $v0, $a1, 1
/* 166E34 802465D4 00451021 */  addu      $v0, $v0, $a1
/* 166E38 802465D8 000210C0 */  sll       $v0, $v0, 3
/* 166E3C 802465DC 00461021 */  addu      $v0, $v0, $a2
/* 166E40 802465E0 8C480000 */  lw        $t0, ($v0)
/* 166E44 802465E4 8C490004 */  lw        $t1, 4($v0)
/* 166E48 802465E8 8C4A0008 */  lw        $t2, 8($v0)
/* 166E4C 802465EC 8C4B000C */  lw        $t3, 0xc($v0)
/* 166E50 802465F0 AC680000 */  sw        $t0, ($v1)
/* 166E54 802465F4 AC690004 */  sw        $t1, 4($v1)
/* 166E58 802465F8 AC6A0008 */  sw        $t2, 8($v1)
/* 166E5C 802465FC AC6B000C */  sw        $t3, 0xc($v1)
/* 166E60 80246600 8C480010 */  lw        $t0, 0x10($v0)
/* 166E64 80246604 8C490014 */  lw        $t1, 0x14($v0)
/* 166E68 80246608 AC680010 */  sw        $t0, 0x10($v1)
/* 166E6C 8024660C 0C00ACDD */  jal       fio_save_game
/* 166E70 80246610 AC690014 */   sw       $t1, 0x14($v1)
/* 166E74 80246614 8E030000 */  lw        $v1, ($s0)
/* 166E78 80246618 24020001 */  addiu     $v0, $zero, 1
/* 166E7C 8024661C 3C018007 */  lui       $at, %hi(D_80077A24)
/* 166E80 80246620 00230821 */  addu      $at, $at, $v1
/* 166E84 80246624 A0227A24 */  sb        $v0, %lo(D_80077A24)($at)
/* 166E88 80246628 08091A3A */  j         .L802468E8
/* 166E8C 8024662C 00000000 */   nop
.L80246630:
/* 166E90 80246630 0C05272D */  jal       sfx_play_sound
/* 166E94 80246634 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166E98 80246638 3C058024 */  lui       $a1, %hi(filemenu_update_show_name_confirm)
/* 166E9C 8024663C 24A53CCC */  addiu     $a1, $a1, %lo(filemenu_update_show_name_confirm)
/* 166EA0 80246640 0C051F9F */  jal       set_window_update
/* 166EA4 80246644 24040032 */   addiu    $a0, $zero, 0x32
/* 166EA8 80246648 3C048016 */  lui       $a0, %hi(gWindows)
/* 166EAC 8024664C 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 166EB0 80246650 24020079 */  addiu     $v0, $zero, 0x79
/* 166EB4 80246654 A482064E */  sh        $v0, 0x64e($a0)
/* 166EB8 80246658 24020045 */  addiu     $v0, $zero, 0x45
/* 166EBC 8024665C A4820650 */  sh        $v0, 0x650($a0)
/* 166EC0 80246660 2402002C */  addiu     $v0, $zero, 0x2c
/* 166EC4 80246664 80830643 */  lb        $v1, 0x643($a0)
/* 166EC8 80246668 A4820652 */  sh        $v0, 0x652($a0)
/* 166ECC 8024666C 2402FFFF */  addiu     $v0, $zero, -1
/* 166ED0 80246670 1062000B */  beq       $v1, $v0, .L802466A0
/* 166ED4 80246674 2485064C */   addiu    $a1, $a0, 0x64c
/* 166ED8 80246678 00031140 */  sll       $v0, $v1, 5
/* 166EDC 8024667C 00441021 */  addu      $v0, $v0, $a0
/* 166EE0 80246680 94420010 */  lhu       $v0, 0x10($v0)
/* 166EE4 80246684 00021400 */  sll       $v0, $v0, 0x10
/* 166EE8 80246688 00021C03 */  sra       $v1, $v0, 0x10
/* 166EEC 8024668C 000217C2 */  srl       $v0, $v0, 0x1f
/* 166EF0 80246690 00621821 */  addu      $v1, $v1, $v0
/* 166EF4 80246694 00031843 */  sra       $v1, $v1, 1
/* 166EF8 80246698 080919AB */  j         .L802466AC
/* 166EFC 8024669C 2463FFDE */   addiu    $v1, $v1, -0x22
.L802466A0:
/* 166F00 802466A0 2403007E */  addiu     $v1, $zero, 0x7e
/* 166F04 802466A4 3C048016 */  lui       $a0, %hi(gWindows)
/* 166F08 802466A8 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L802466AC:
/* 166F0C 802466AC 2402FFD5 */  addiu     $v0, $zero, -0x2b
/* 166F10 802466B0 A4A30000 */  sh        $v1, ($a1)
/* 166F14 802466B4 A48205CE */  sh        $v0, 0x5ce($a0)
/* 166F18 802466B8 240200B6 */  addiu     $v0, $zero, 0xb6
/* 166F1C 802466BC A48205D0 */  sh        $v0, 0x5d0($a0)
/* 166F20 802466C0 24020027 */  addiu     $v0, $zero, 0x27
/* 166F24 802466C4 808305C3 */  lb        $v1, 0x5c3($a0)
/* 166F28 802466C8 A48205D2 */  sh        $v0, 0x5d2($a0)
/* 166F2C 802466CC 2402FFFF */  addiu     $v0, $zero, -1
/* 166F30 802466D0 1062000B */  beq       $v1, $v0, .L80246700
/* 166F34 802466D4 248705CC */   addiu    $a3, $a0, 0x5cc
/* 166F38 802466D8 00031140 */  sll       $v0, $v1, 5
/* 166F3C 802466DC 00441021 */  addu      $v0, $v0, $a0
/* 166F40 802466E0 94420010 */  lhu       $v0, 0x10($v0)
/* 166F44 802466E4 00021400 */  sll       $v0, $v0, 0x10
/* 166F48 802466E8 00021C03 */  sra       $v1, $v0, 0x10
/* 166F4C 802466EC 000217C2 */  srl       $v0, $v0, 0x1f
/* 166F50 802466F0 00621821 */  addu      $v1, $v1, $v0
/* 166F54 802466F4 00031843 */  sra       $v1, $v1, 1
/* 166F58 802466F8 080919C1 */  j         .L80246704
/* 166F5C 802466FC 2463FFA5 */   addiu    $v1, $v1, -0x5b
.L80246700:
/* 166F60 80246700 24030045 */  addiu     $v1, $zero, 0x45
.L80246704:
/* 166F64 80246704 0000282D */  daddu     $a1, $zero, $zero
/* 166F68 80246708 24060001 */  addiu     $a2, $zero, 1
/* 166F6C 8024670C A4E30000 */  sh        $v1, ($a3)
/* 166F70 80246710 3C048025 */  lui       $a0, %hi(D_80249B88)
/* 166F74 80246714 8C849B88 */  lw        $a0, %lo(D_80249B88)($a0)
/* 166F78 80246718 00C0102D */  daddu     $v0, $a2, $zero
/* 166F7C 8024671C 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 166F80 80246720 A022C098 */  sb        $v0, %lo(D_8024C098_C09918)($at)
/* 166F84 80246724 08091A37 */  j         .L802468DC
/* 166F88 80246728 24020003 */   addiu    $v0, $zero, 3
glabel L8024672C_166F8C
/* 166F8C 8024672C 92630003 */  lbu       $v1, 3($s3)
/* 166F90 80246730 24020006 */  addiu     $v0, $zero, 6
/* 166F94 80246734 14620007 */  bne       $v1, $v0, .L80246754
/* 166F98 80246738 2C620004 */   sltiu    $v0, $v1, 4
/* 166F9C 8024673C 0C05272D */  jal       sfx_play_sound
/* 166FA0 80246740 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166FA4 80246744 0C00CD3C */  jal       set_game_mode
/* 166FA8 80246748 2404000D */   addiu    $a0, $zero, 0xd
/* 166FAC 8024674C 08091A3A */  j         .L802468E8
/* 166FB0 80246750 00000000 */   nop
.L80246754:
/* 166FB4 80246754 10400064 */  beqz      $v0, .L802468E8
/* 166FB8 80246758 00000000 */   nop
/* 166FBC 8024675C 92620003 */  lbu       $v0, 3($s3)
/* 166FC0 80246760 3C018007 */  lui       $at, %hi(D_80077A24)
/* 166FC4 80246764 00220821 */  addu      $at, $at, $v0
/* 166FC8 80246768 90227A24 */  lbu       $v0, %lo(D_80077A24)($at)
/* 166FCC 8024676C 3C118007 */  lui       $s1, %hi(D_80077A24)
/* 166FD0 80246770 26317A24 */  addiu     $s1, $s1, %lo(D_80077A24)
/* 166FD4 80246774 1440001B */  bnez      $v0, .L802467E4
/* 166FD8 80246778 00000000 */   nop
/* 166FDC 8024677C 0C05272D */  jal       sfx_play_sound
/* 166FE0 80246780 240400C9 */   addiu    $a0, $zero, 0xc9
/* 166FE4 80246784 2404002C */  addiu     $a0, $zero, 0x2c
/* 166FE8 80246788 3C058014 */  lui       $a1, %hi(main_menu_window_update)
/* 166FEC 8024678C 24A57650 */  addiu     $a1, $a1, %lo(main_menu_window_update)
/* 166FF0 80246790 24020002 */  addiu     $v0, $zero, 2
/* 166FF4 80246794 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 166FF8 80246798 A022C098 */  sb        $v0, %lo(D_8024C098_C09918)($at)
/* 166FFC 8024679C 3C028025 */  lui       $v0, %hi(D_80249B8C)
/* 167000 802467A0 8C429B8C */  lw        $v0, %lo(D_80249B8C)($v0)
/* 167004 802467A4 24100001 */  addiu     $s0, $zero, 1
/* 167008 802467A8 0C051F9F */  jal       set_window_update
/* 16700C 802467AC A0500004 */   sb       $s0, 4($v0)
/* 167010 802467B0 2404002F */  addiu     $a0, $zero, 0x2f
/* 167014 802467B4 0C051F9F */  jal       set_window_update
/* 167018 802467B8 24050001 */   addiu    $a1, $zero, 1
/* 16701C 802467BC 24040032 */  addiu     $a0, $zero, 0x32
/* 167020 802467C0 0C051F9F */  jal       set_window_update
/* 167024 802467C4 24050002 */   addiu    $a1, $zero, 2
/* 167028 802467C8 92640003 */  lbu       $a0, 3($s3)
/* 16702C 802467CC 0C00ACDD */  jal       fio_save_game
/* 167030 802467D0 00000000 */   nop
/* 167034 802467D4 92620003 */  lbu       $v0, 3($s3)
/* 167038 802467D8 00511021 */  addu      $v0, $v0, $s1
/* 16703C 802467DC 08091A3A */  j         .L802468E8
/* 167040 802467E0 A0500000 */   sb       $s0, ($v0)
.L802467E4:
/* 167044 802467E4 0C05272D */  jal       sfx_play_sound
/* 167048 802467E8 240400C9 */   addiu    $a0, $zero, 0xc9
/* 16704C 802467EC 3C058024 */  lui       $a1, %hi(filemenu_update_show_name_confirm)
/* 167050 802467F0 24A53CCC */  addiu     $a1, $a1, %lo(filemenu_update_show_name_confirm)
/* 167054 802467F4 0C051F9F */  jal       set_window_update
/* 167058 802467F8 24040032 */   addiu    $a0, $zero, 0x32
/* 16705C 802467FC 3C048016 */  lui       $a0, %hi(gWindows)
/* 167060 80246800 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
/* 167064 80246804 2402007F */  addiu     $v0, $zero, 0x7f
/* 167068 80246808 A482064E */  sh        $v0, 0x64e($a0)
/* 16706C 8024680C 24020045 */  addiu     $v0, $zero, 0x45
/* 167070 80246810 A4820650 */  sh        $v0, 0x650($a0)
/* 167074 80246814 2402002C */  addiu     $v0, $zero, 0x2c
/* 167078 80246818 80830643 */  lb        $v1, 0x643($a0)
/* 16707C 8024681C A4820652 */  sh        $v0, 0x652($a0)
/* 167080 80246820 2402FFFF */  addiu     $v0, $zero, -1
/* 167084 80246824 1062000B */  beq       $v1, $v0, .L80246854
/* 167088 80246828 2485064C */   addiu    $a1, $a0, 0x64c
/* 16708C 8024682C 00031140 */  sll       $v0, $v1, 5
/* 167090 80246830 00441021 */  addu      $v0, $v0, $a0
/* 167094 80246834 94420010 */  lhu       $v0, 0x10($v0)
/* 167098 80246838 00021400 */  sll       $v0, $v0, 0x10
/* 16709C 8024683C 00021C03 */  sra       $v1, $v0, 0x10
/* 1670A0 80246840 000217C2 */  srl       $v0, $v0, 0x1f
/* 1670A4 80246844 00621821 */  addu      $v1, $v1, $v0
/* 1670A8 80246848 00031843 */  sra       $v1, $v1, 1
/* 1670AC 8024684C 08091A18 */  j         .L80246860
/* 1670B0 80246850 2463FFDE */   addiu    $v1, $v1, -0x22
.L80246854:
/* 1670B4 80246854 2403007E */  addiu     $v1, $zero, 0x7e
/* 1670B8 80246858 3C048016 */  lui       $a0, %hi(gWindows)
/* 1670BC 8024685C 24849D50 */  addiu     $a0, $a0, %lo(gWindows)
.L80246860:
/* 1670C0 80246860 2402FFCE */  addiu     $v0, $zero, -0x32
/* 1670C4 80246864 A4A30000 */  sh        $v1, ($a1)
/* 1670C8 80246868 A48205CE */  sh        $v0, 0x5ce($a0)
/* 1670CC 8024686C 24020094 */  addiu     $v0, $zero, 0x94
/* 1670D0 80246870 A48205D0 */  sh        $v0, 0x5d0($a0)
/* 1670D4 80246874 24020026 */  addiu     $v0, $zero, 0x26
/* 1670D8 80246878 808305C3 */  lb        $v1, 0x5c3($a0)
/* 1670DC 8024687C A48205D2 */  sh        $v0, 0x5d2($a0)
/* 1670E0 80246880 2402FFFF */  addiu     $v0, $zero, -1
/* 1670E4 80246884 1062000B */  beq       $v1, $v0, .L802468B4
/* 1670E8 80246888 248705CC */   addiu    $a3, $a0, 0x5cc
/* 1670EC 8024688C 00031140 */  sll       $v0, $v1, 5
/* 1670F0 80246890 00441021 */  addu      $v0, $v0, $a0
/* 1670F4 80246894 94420010 */  lhu       $v0, 0x10($v0)
/* 1670F8 80246898 00021400 */  sll       $v0, $v0, 0x10
/* 1670FC 8024689C 00021C03 */  sra       $v1, $v0, 0x10
/* 167100 802468A0 000217C2 */  srl       $v0, $v0, 0x1f
/* 167104 802468A4 00621821 */  addu      $v1, $v1, $v0
/* 167108 802468A8 00031843 */  sra       $v1, $v1, 1
/* 16710C 802468AC 08091A2E */  j         .L802468B8
/* 167110 802468B0 2463FFB6 */   addiu    $v1, $v1, -0x4a
.L802468B4:
/* 167114 802468B4 24030056 */  addiu     $v1, $zero, 0x56
.L802468B8:
/* 167118 802468B8 0000282D */  daddu     $a1, $zero, $zero
/* 16711C 802468BC 24060001 */  addiu     $a2, $zero, 1
/* 167120 802468C0 A4E30000 */  sh        $v1, ($a3)
/* 167124 802468C4 3C048025 */  lui       $a0, %hi(D_80249B88)
/* 167128 802468C8 8C849B88 */  lw        $a0, %lo(D_80249B88)($a0)
/* 16712C 802468CC 00C0102D */  daddu     $v0, $a2, $zero
/* 167130 802468D0 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 167134 802468D4 A022C098 */  sb        $v0, %lo(D_8024C098_C09918)($at)
/* 167138 802468D8 00C0102D */  daddu     $v0, $a2, $zero
.L802468DC:
/* 16713C 802468DC A0820004 */  sb        $v0, 4($a0)
.L802468E0:
/* 167140 802468E0 0C090B65 */  jal       filemenu_set_selected
/* 167144 802468E4 00000000 */   nop
.L802468E8:
/* 167148 802468E8 3C028025 */  lui       $v0, %hi(D_8024C084)
/* 16714C 802468EC 8C42C084 */  lw        $v0, %lo(D_8024C084)($v0)
/* 167150 802468F0 30424000 */  andi      $v0, $v0, 0x4000
/* 167154 802468F4 10400086 */  beqz      $v0, .L80246B10
/* 167158 802468F8 00000000 */   nop
/* 16715C 802468FC 82630004 */  lb        $v1, 4($s3)
/* 167160 80246900 2C620005 */  sltiu     $v0, $v1, 5
/* 167164 80246904 1040000E */  beqz      $v0, .L80246940
/* 167168 80246908 00031080 */   sll      $v0, $v1, 2
/* 16716C 8024690C 3C018025 */  lui       $at, %hi(jtbl_8024BFB8)
/* 167170 80246910 00220821 */  addu      $at, $at, $v0
/* 167174 80246914 8C22BFB8 */  lw        $v0, %lo(jtbl_8024BFB8)($at)
/* 167178 80246918 00400008 */  jr        $v0
/* 16717C 8024691C 00000000 */   nop
glabel L80246920_167180
/* 167180 80246920 0260202D */  daddu     $a0, $s3, $zero
/* 167184 80246924 08091A4D */  j         .L80246934
/* 167188 80246928 24050002 */   addiu    $a1, $zero, 2
glabel L8024692C_16718C
/* 16718C 8024692C 0260202D */  daddu     $a0, $s3, $zero
/* 167190 80246930 24050001 */  addiu     $a1, $zero, 1
.L80246934:
/* 167194 80246934 0C090B65 */  jal       filemenu_set_selected
/* 167198 80246938 24060002 */   addiu    $a2, $zero, 2
/* 16719C 8024693C 82630004 */  lb        $v1, 4($s3)
.L80246940:
/* 1671A0 80246940 2C620005 */  sltiu     $v0, $v1, 5
/* 1671A4 80246944 10400072 */  beqz      $v0, .L80246B10
/* 1671A8 80246948 00031080 */   sll      $v0, $v1, 2
/* 1671AC 8024694C 3C018025 */  lui       $at, %hi(jtbl_8024BFD0)
/* 1671B0 80246950 00220821 */  addu      $at, $at, $v0
/* 1671B4 80246954 8C22BFD0 */  lw        $v0, %lo(jtbl_8024BFD0)($at)
/* 1671B8 80246958 00400008 */  jr        $v0
/* 1671BC 8024695C 00000000 */   nop
glabel L80246960_1671C0
/* 1671C0 80246960 24040033 */  addiu     $a0, $zero, 0x33
/* 1671C4 80246964 3C128024 */  lui       $s2, %hi(filemenu_update_hidden_options_left)
/* 1671C8 80246968 2652368C */  addiu     $s2, $s2, %lo(filemenu_update_hidden_options_left)
/* 1671CC 8024696C 0C051F9F */  jal       set_window_update
/* 1671D0 80246970 0240282D */   daddu    $a1, $s2, $zero
/* 1671D4 80246974 24040034 */  addiu     $a0, $zero, 0x34
/* 1671D8 80246978 3C118024 */  lui       $s1, %hi(filemenu_update_hidden_options_right)
/* 1671DC 8024697C 263136F0 */  addiu     $s1, $s1, %lo(filemenu_update_hidden_options_right)
/* 1671E0 80246980 0C051F9F */  jal       set_window_update
/* 1671E4 80246984 0220282D */   daddu    $a1, $s1, $zero
/* 1671E8 80246988 24040035 */  addiu     $a0, $zero, 0x35
/* 1671EC 8024698C 3C108024 */  lui       $s0, %hi(filemenu_update_hidden_options_bottom)
/* 1671F0 80246990 261037B8 */  addiu     $s0, $s0, %lo(filemenu_update_hidden_options_bottom)
/* 1671F4 80246994 0C051F9F */  jal       set_window_update
/* 1671F8 80246998 0200282D */   daddu    $a1, $s0, $zero
/* 1671FC 8024699C 24040036 */  addiu     $a0, $zero, 0x36
/* 167200 802469A0 0C051F9F */  jal       set_window_update
/* 167204 802469A4 0200282D */   daddu    $a1, $s0, $zero
/* 167208 802469A8 24040037 */  addiu     $a0, $zero, 0x37
/* 16720C 802469AC 0C051F9F */  jal       set_window_update
/* 167210 802469B0 0200282D */   daddu    $a1, $s0, $zero
/* 167214 802469B4 24040038 */  addiu     $a0, $zero, 0x38
/* 167218 802469B8 0C051F9F */  jal       set_window_update
/* 16721C 802469BC 0240282D */   daddu    $a1, $s2, $zero
/* 167220 802469C0 24040039 */  addiu     $a0, $zero, 0x39
/* 167224 802469C4 0C051F9F */  jal       set_window_update
/* 167228 802469C8 0220282D */   daddu    $a1, $s1, $zero
/* 16722C 802469CC 2404003A */  addiu     $a0, $zero, 0x3a
/* 167230 802469D0 0C051F9F */  jal       set_window_update
/* 167234 802469D4 0240282D */   daddu    $a1, $s2, $zero
/* 167238 802469D8 2404003B */  addiu     $a0, $zero, 0x3b
/* 16723C 802469DC 0C051F9F */  jal       set_window_update
/* 167240 802469E0 0220282D */   daddu    $a1, $s1, $zero
/* 167244 802469E4 3C058024 */  lui       $a1, %hi(filemenu_update_hidden_title)
/* 167248 802469E8 24A53754 */  addiu     $a1, $a1, %lo(filemenu_update_hidden_title)
/* 16724C 802469EC 0C051F9F */  jal       set_window_update
/* 167250 802469F0 2404002D */   addiu    $a0, $zero, 0x2d
/* 167254 802469F4 0C05272D */  jal       sfx_play_sound
/* 167258 802469F8 240400D6 */   addiu    $a0, $zero, 0xd6
/* 16725C 802469FC 08091AC2 */  j         .L80246B08
/* 167260 80246A00 2404000F */   addiu    $a0, $zero, 0xf
glabel L80246A04_167264
/* 167264 80246A04 A2600004 */  sb        $zero, 4($s3)
/* 167268 80246A08 0260202D */  daddu     $a0, $s3, $zero
/* 16726C 80246A0C 0000282D */  daddu     $a1, $zero, $zero
/* 167270 80246A10 0C090B65 */  jal       filemenu_set_selected
/* 167274 80246A14 24060002 */   addiu    $a2, $zero, 2
/* 167278 80246A18 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_left)
/* 16727C 80246A1C 24A533F4 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_left)
/* 167280 80246A20 0C051F9F */  jal       set_window_update
/* 167284 80246A24 24040033 */   addiu    $a0, $zero, 0x33
/* 167288 80246A28 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_right)
/* 16728C 80246A2C 24A53468 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_right)
/* 167290 80246A30 0C051F9F */  jal       set_window_update
/* 167294 80246A34 24040034 */   addiu    $a0, $zero, 0x34
/* 167298 80246A38 24040035 */  addiu     $a0, $zero, 0x35
/* 16729C 80246A3C 3C108024 */  lui       $s0, %hi(filemenu_update_show_options_bottom)
/* 1672A0 80246A40 261034DC */  addiu     $s0, $s0, %lo(filemenu_update_show_options_bottom)
/* 1672A4 80246A44 0C051F9F */  jal       set_window_update
/* 1672A8 80246A48 0200282D */   daddu    $a1, $s0, $zero
/* 1672AC 80246A4C 24040037 */  addiu     $a0, $zero, 0x37
/* 1672B0 80246A50 0C051F9F */  jal       set_window_update
/* 1672B4 80246A54 0200282D */   daddu    $a1, $s0, $zero
/* 1672B8 80246A58 08091ABB */  j         .L80246AEC
/* 1672BC 80246A5C 00000000 */   nop
glabel L80246A60_1672C0
/* 1672C0 80246A60 A2600004 */  sb        $zero, 4($s3)
/* 1672C4 80246A64 0260202D */  daddu     $a0, $s3, $zero
/* 1672C8 80246A68 24050001 */  addiu     $a1, $zero, 1
/* 1672CC 80246A6C 0C090B65 */  jal       filemenu_set_selected
/* 1672D0 80246A70 24060002 */   addiu    $a2, $zero, 2
/* 1672D4 80246A74 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_left)
/* 1672D8 80246A78 24A533F4 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_left)
/* 1672DC 80246A7C 0C051F9F */  jal       set_window_update
/* 1672E0 80246A80 24040033 */   addiu    $a0, $zero, 0x33
/* 1672E4 80246A84 3C058024 */  lui       $a1, %hi(filemenu_update_show_options_right)
/* 1672E8 80246A88 24A53468 */  addiu     $a1, $a1, %lo(filemenu_update_show_options_right)
/* 1672EC 80246A8C 0C051F9F */  jal       set_window_update
/* 1672F0 80246A90 24040034 */   addiu    $a0, $zero, 0x34
/* 1672F4 80246A94 24040035 */  addiu     $a0, $zero, 0x35
/* 1672F8 80246A98 3C108024 */  lui       $s0, %hi(filemenu_update_show_options_bottom)
/* 1672FC 80246A9C 261034DC */  addiu     $s0, $s0, %lo(filemenu_update_show_options_bottom)
/* 167300 80246AA0 0C051F9F */  jal       set_window_update
/* 167304 80246AA4 0200282D */   daddu    $a1, $s0, $zero
/* 167308 80246AA8 24040037 */  addiu     $a0, $zero, 0x37
/* 16730C 80246AAC 0C051F9F */  jal       set_window_update
/* 167310 80246AB0 0200282D */   daddu    $a1, $s0, $zero
/* 167314 80246AB4 08091ABB */  j         .L80246AEC
/* 167318 80246AB8 00000000 */   nop
glabel L80246ABC_16731C
/* 16731C 80246ABC 24020003 */  addiu     $v0, $zero, 3
/* 167320 80246AC0 A2620004 */  sb        $v0, 4($s3)
/* 167324 80246AC4 3C058025 */  lui       $a1, %hi(D_8024C094)
/* 167328 80246AC8 8CA5C094 */  lw        $a1, %lo(D_8024C094)($a1)
/* 16732C 80246ACC 0260202D */  daddu     $a0, $s3, $zero
/* 167330 80246AD0 000537C2 */  srl       $a2, $a1, 0x1f
/* 167334 80246AD4 00A63021 */  addu      $a2, $a1, $a2
/* 167338 80246AD8 00063043 */  sra       $a2, $a2, 1
/* 16733C 80246ADC 00061040 */  sll       $v0, $a2, 1
/* 167340 80246AE0 00A22823 */  subu      $a1, $a1, $v0
/* 167344 80246AE4 0C090B65 */  jal       filemenu_set_selected
/* 167348 80246AE8 00052840 */   sll      $a1, $a1, 1
.L80246AEC:
/* 16734C 80246AEC 0C05272D */  jal       sfx_play_sound
/* 167350 80246AF0 240400CA */   addiu    $a0, $zero, 0xca
/* 167354 80246AF4 08091AC4 */  j         .L80246B10
/* 167358 80246AF8 00000000 */   nop
glabel L80246AFC_16735C
/* 16735C 80246AFC 0C05272D */  jal       sfx_play_sound
/* 167360 80246B00 240400CA */   addiu    $a0, $zero, 0xca
/* 167364 80246B04 2404000D */  addiu     $a0, $zero, 0xd
.L80246B08:
/* 167368 80246B08 0C00CD3C */  jal       set_game_mode
/* 16736C 80246B0C 00000000 */   nop
.L80246B10:
/* 167370 80246B10 8FBF0020 */  lw        $ra, 0x20($sp)
/* 167374 80246B14 8FB3001C */  lw        $s3, 0x1c($sp)
/* 167378 80246B18 8FB20018 */  lw        $s2, 0x18($sp)
/* 16737C 80246B1C 8FB10014 */  lw        $s1, 0x14($sp)
/* 167380 80246B20 8FB00010 */  lw        $s0, 0x10($sp)
/* 167384 80246B24 03E00008 */  jr        $ra
/* 167388 80246B28 27BD0028 */   addiu    $sp, $sp, 0x28
