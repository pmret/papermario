.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013673C
/* CCE3C 8013673C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CCE40 80136740 AFB1001C */  sw        $s1, 0x1c($sp)
/* CCE44 80136744 0080882D */  daddu     $s1, $a0, $zero
/* CCE48 80136748 AFB20020 */  sw        $s2, 0x20($sp)
/* CCE4C 8013674C 00A0902D */  daddu     $s2, $a1, $zero
/* CCE50 80136750 AFB30024 */  sw        $s3, 0x24($sp)
/* CCE54 80136754 3C048008 */  lui       $a0, %hi(gItemTable)
/* CCE58 80136758 248478E0 */  addiu     $a0, $a0, %lo(gItemTable)
/* CCE5C 8013675C AFBF0028 */  sw        $ra, 0x28($sp)
/* CCE60 80136760 AFB00018 */  sw        $s0, 0x18($sp)
/* CCE64 80136764 86230018 */  lh        $v1, 0x18($s1)
/* CCE68 80136768 9222001A */  lbu       $v0, 0x1a($s1)
/* CCE6C 8013676C 00031940 */  sll       $v1, $v1, 5
/* CCE70 80136770 00642021 */  addu      $a0, $v1, $a0
/* CCE74 80136774 2442FFFE */  addiu     $v0, $v0, -2
/* CCE78 80136778 00021600 */  sll       $v0, $v0, 0x18
/* CCE7C 8013677C 00021E03 */  sra       $v1, $v0, 0x18
/* CCE80 80136780 2C62000D */  sltiu     $v0, $v1, 0xd
/* CCE84 80136784 1040008B */  beqz      $v0, .L801369B4
/* CCE88 80136788 00C0982D */   daddu    $s3, $a2, $zero
/* CCE8C 8013678C 00031080 */  sll       $v0, $v1, 2
/* CCE90 80136790 3C018015 */  lui       $at, %hi(jtbl_80150E60_E7560)
/* CCE94 80136794 00220821 */  addu      $at, $at, $v0
/* CCE98 80136798 8C220E60 */  lw        $v0, %lo(jtbl_80150E60_E7560)($at)
/* CCE9C 8013679C 00400008 */  jr        $v0
/* CCEA0 801367A0 00000000 */   nop
glabel L801367A4_CCEA4
/* CCEA4 801367A4 94820018 */  lhu       $v0, 0x18($a0)
/* CCEA8 801367A8 30420040 */  andi      $v0, $v0, 0x40
/* CCEAC 801367AC 1440001C */  bnez      $v0, .L80136820
/* CCEB0 801367B0 3C030400 */   lui      $v1, 0x400
/* CCEB4 801367B4 8E220000 */  lw        $v0, ($s1)
/* CCEB8 801367B8 00431024 */  and       $v0, $v0, $v1
/* CCEBC 801367BC 10400005 */  beqz      $v0, .L801367D4
/* CCEC0 801367C0 3C10001D */   lui      $s0, 0x1d
/* CCEC4 801367C4 96220006 */  lhu       $v0, 6($s1)
/* CCEC8 801367C8 30420004 */  andi      $v0, $v0, 4
/* CCECC 801367CC 50400002 */  beql      $v0, $zero, .L801367D8
/* CCED0 801367D0 3610005A */   ori      $s0, $s0, 0x5a
.L801367D4:
/* CCED4 801367D4 36100058 */  ori       $s0, $s0, 0x58
.L801367D8:
/* CCED8 801367D8 8C840000 */  lw        $a0, ($a0)
/* CCEDC 801367DC 0C0496CF */  jal       set_message_string
/* CCEE0 801367E0 0000282D */   daddu    $a1, $zero, $zero
/* CCEE4 801367E4 96230006 */  lhu       $v1, 6($s1)
/* CCEE8 801367E8 30620010 */  andi      $v0, $v1, 0x10
/* CCEEC 801367EC 10400003 */  beqz      $v0, .L801367FC
/* CCEF0 801367F0 30620020 */   andi     $v0, $v1, 0x20
/* CCEF4 801367F4 3C10001D */  lui       $s0, 0x1d
/* CCEF8 801367F8 3610005D */  ori       $s0, $s0, 0x5d
.L801367FC:
/* CCEFC 801367FC 10400003 */  beqz      $v0, .L8013680C
/* CCF00 80136800 30620040 */   andi     $v0, $v1, 0x40
/* CCF04 80136804 3C10001D */  lui       $s0, 0x1d
/* CCF08 80136808 3610005E */  ori       $s0, $s0, 0x5e
.L8013680C:
/* CCF0C 8013680C 1040001E */  beqz      $v0, .L80136888
/* CCF10 80136810 00000000 */   nop
/* CCF14 80136814 3C10001D */  lui       $s0, 0x1d
/* CCF18 80136818 0804DA22 */  j         .L80136888
/* CCF1C 8013681C 3610005C */   ori      $s0, $s0, 0x5c
.L80136820:
/* CCF20 80136820 8E220000 */  lw        $v0, ($s1)
/* CCF24 80136824 00431024 */  and       $v0, $v0, $v1
/* CCF28 80136828 10400005 */  beqz      $v0, .L80136840
/* CCF2C 8013682C 3C10001D */   lui      $s0, 0x1d
/* CCF30 80136830 96220006 */  lhu       $v0, 6($s1)
/* CCF34 80136834 30420004 */  andi      $v0, $v0, 4
/* CCF38 80136838 50400002 */  beql      $v0, $zero, .L80136844
/* CCF3C 8013683C 3610005B */   ori      $s0, $s0, 0x5b
.L80136840:
/* CCF40 80136840 36100059 */  ori       $s0, $s0, 0x59
.L80136844:
/* CCF44 80136844 96230006 */  lhu       $v1, 6($s1)
/* CCF48 80136848 30620010 */  andi      $v0, $v1, 0x10
/* CCF4C 8013684C 10400003 */  beqz      $v0, .L8013685C
/* CCF50 80136850 30620020 */   andi     $v0, $v1, 0x20
/* CCF54 80136854 3C10001D */  lui       $s0, 0x1d
/* CCF58 80136858 3610005D */  ori       $s0, $s0, 0x5d
.L8013685C:
/* CCF5C 8013685C 10400003 */  beqz      $v0, .L8013686C
/* CCF60 80136860 30620040 */   andi     $v0, $v1, 0x40
/* CCF64 80136864 3C10001D */  lui       $s0, 0x1d
/* CCF68 80136868 3610005E */  ori       $s0, $s0, 0x5e
.L8013686C:
/* CCF6C 8013686C 10400003 */  beqz      $v0, .L8013687C
/* CCF70 80136870 00000000 */   nop
/* CCF74 80136874 3C10001D */  lui       $s0, 0x1d
/* CCF78 80136878 3610005C */  ori       $s0, $s0, 0x5c
.L8013687C:
/* CCF7C 8013687C 8C840000 */  lw        $a0, ($a0)
/* CCF80 80136880 0C0496CF */  jal       set_message_string
/* CCF84 80136884 0000282D */   daddu    $a1, $zero, $zero
.L80136888:
/* CCF88 80136888 0C04992C */  jal       func_801264B0
/* CCF8C 8013688C 0200202D */   daddu    $a0, $s0, $zero
/* CCF90 80136890 2442FFFF */  addiu     $v0, $v0, -1
/* CCF94 80136894 86250018 */  lh        $a1, 0x18($s1)
/* CCF98 80136898 00021040 */  sll       $v0, $v0, 1
/* CCF9C 8013689C 00051940 */  sll       $v1, $a1, 5
/* CCFA0 801368A0 3C048008 */  lui       $a0, %hi(gItemTable+0x18)
/* CCFA4 801368A4 00832021 */  addu      $a0, $a0, $v1
/* CCFA8 801368A8 948478F8 */  lhu       $a0, %lo(gItemTable+0x18)($a0)
/* CCFAC 801368AC 3C068015 */  lui       $a2, %hi(D_8014C6E4)
/* CCFB0 801368B0 00C23021 */  addu      $a2, $a2, $v0
/* CCFB4 801368B4 84C6C6E4 */  lh        $a2, %lo(D_8014C6E4)($a2)
/* CCFB8 801368B8 30830040 */  andi      $v1, $a0, 0x40
/* CCFBC 801368BC 5460000E */  bnel      $v1, $zero, .L801368F8
/* CCFC0 801368C0 0200202D */   daddu    $a0, $s0, $zero
/* CCFC4 801368C4 30820008 */  andi      $v0, $a0, 8
/* CCFC8 801368C8 5440000B */  bnel      $v0, $zero, .L801368F8
/* CCFCC 801368CC 0200202D */   daddu    $a0, $s0, $zero
/* CCFD0 801368D0 2402015C */  addiu     $v0, $zero, 0x15c
/* CCFD4 801368D4 10A20007 */  beq       $a1, $v0, .L801368F4
/* CCFD8 801368D8 30820020 */   andi     $v0, $a0, 0x20
/* CCFDC 801368DC 14400006 */  bnez      $v0, .L801368F8
/* CCFE0 801368E0 0200202D */   daddu    $a0, $s0, $zero
/* CCFE4 801368E4 96220006 */  lhu       $v0, 6($s1)
/* CCFE8 801368E8 30420030 */  andi      $v0, $v0, 0x30
/* CCFEC 801368EC 1040000B */  beqz      $v0, .L8013691C
/* CCFF0 801368F0 26450028 */   addiu    $a1, $s2, 0x28
.L801368F4:
/* CCFF4 801368F4 0200202D */  daddu     $a0, $s0, $zero
.L801368F8:
/* CCFF8 801368F8 2645000F */  addiu     $a1, $s2, 0xf
/* CCFFC 801368FC 02663021 */  addu      $a2, $s3, $a2
/* CD000 80136900 240700FF */  addiu     $a3, $zero, 0xff
/* CD004 80136904 2402002F */  addiu     $v0, $zero, 0x2f
/* CD008 80136908 AFA20010 */  sw        $v0, 0x10($sp)
/* CD00C 8013690C 0C04993B */  jal       draw_string
/* CD010 80136910 AFA00014 */   sw       $zero, 0x14($sp)
/* CD014 80136914 0804DA6D */  j         .L801369B4
/* CD018 80136918 00000000 */   nop
.L8013691C:
/* CD01C 8013691C 02663021 */  addu      $a2, $s3, $a2
/* CD020 80136920 240700FF */  addiu     $a3, $zero, 0xff
/* CD024 80136924 2402002F */  addiu     $v0, $zero, 0x2f
/* CD028 80136928 AFA20010 */  sw        $v0, 0x10($sp)
/* CD02C 8013692C 0C04993B */  jal       draw_string
/* CD030 80136930 AFA00014 */   sw       $zero, 0x14($sp)
/* CD034 80136934 96220006 */  lhu       $v0, 6($s1)
/* CD038 80136938 30420030 */  andi      $v0, $v0, 0x30
/* CD03C 8013693C 1440001D */  bnez      $v0, .L801369B4
/* CD040 80136940 26450014 */   addiu    $a1, $s2, 0x14
/* CD044 80136944 0804DA65 */  j         .L80136994
/* CD048 80136948 00000000 */   nop
glabel L8013694C_CD04C
/* CD04C 8013694C 3C028015 */  lui       $v0, %hi(D_801568EC)
/* CD050 80136950 8C4268EC */  lw        $v0, %lo(D_801568EC)($v0)
/* CD054 80136954 00021140 */  sll       $v0, $v0, 5
/* CD058 80136958 3C048008 */  lui       $a0, %hi(gItemTable)
/* CD05C 8013695C 00822021 */  addu      $a0, $a0, $v0
/* CD060 80136960 8C8478E0 */  lw        $a0, %lo(gItemTable)($a0)
/* CD064 80136964 0C0496CF */  jal       set_message_string
/* CD068 80136968 0000282D */   daddu    $a1, $zero, $zero
/* CD06C 8013696C 3C04001D */  lui       $a0, 0x1d
/* CD070 80136970 3484005F */  ori       $a0, $a0, 0x5f
/* CD074 80136974 26450028 */  addiu     $a1, $s2, 0x28
/* CD078 80136978 26660004 */  addiu     $a2, $s3, 4
/* CD07C 8013697C 240700FF */  addiu     $a3, $zero, 0xff
/* CD080 80136980 2402002F */  addiu     $v0, $zero, 0x2f
/* CD084 80136984 AFA20010 */  sw        $v0, 0x10($sp)
/* CD088 80136988 0C04993B */  jal       draw_string
/* CD08C 8013698C AFA00014 */   sw       $zero, 0x14($sp)
/* CD090 80136990 26450014 */  addiu     $a1, $s2, 0x14
.L80136994:
/* CD094 80136994 3C108015 */  lui       $s0, %hi(D_801568E0)
/* CD098 80136998 261068E0 */  addiu     $s0, $s0, %lo(D_801568E0)
/* CD09C 8013699C 8E040000 */  lw        $a0, ($s0)
/* CD0A0 801369A0 0C051261 */  jal       set_icon_render_pos
/* CD0A4 801369A4 26660014 */   addiu    $a2, $s3, 0x14
/* CD0A8 801369A8 8E040000 */  lw        $a0, ($s0)
/* CD0AC 801369AC 0C0511F1 */  jal       draw_icon_1
/* CD0B0 801369B0 00000000 */   nop
.L801369B4:
glabel L801369B4_CD0B4
/* CD0B4 801369B4 8FBF0028 */  lw        $ra, 0x28($sp)
/* CD0B8 801369B8 8FB30024 */  lw        $s3, 0x24($sp)
/* CD0BC 801369BC 8FB20020 */  lw        $s2, 0x20($sp)
/* CD0C0 801369C0 8FB1001C */  lw        $s1, 0x1c($sp)
/* CD0C4 801369C4 8FB00018 */  lw        $s0, 0x18($sp)
/* CD0C8 801369C8 03E00008 */  jr        $ra
/* CD0CC 801369CC 27BD0030 */   addiu    $sp, $sp, 0x30
