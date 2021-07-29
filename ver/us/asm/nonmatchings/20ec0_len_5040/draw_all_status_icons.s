.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_all_status_icons
/* 219E0 800465E0 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 219E4 800465E4 3C08ED03 */  lui       $t0, 0xed03
/* 219E8 800465E8 35080050 */  ori       $t0, $t0, 0x50
/* 219EC 800465EC 3C07004D */  lui       $a3, 0x4d
/* 219F0 800465F0 34E70370 */  ori       $a3, $a3, 0x370
/* 219F4 800465F4 3C09E300 */  lui       $t1, 0xe300
/* 219F8 800465F8 35290A01 */  ori       $t1, $t1, 0xa01
/* 219FC 800465FC 3C0AE300 */  lui       $t2, 0xe300
/* 21A00 80046600 354A0C00 */  ori       $t2, $t2, 0xc00
/* 21A04 80046604 3C0BE300 */  lui       $t3, 0xe300
/* 21A08 80046608 356B0F00 */  ori       $t3, $t3, 0xf00
/* 21A0C 8004660C 3C0CE300 */  lui       $t4, 0xe300
/* 21A10 80046610 358C0D01 */  ori       $t4, $t4, 0xd01
/* 21A14 80046614 3C0DE300 */  lui       $t5, 0xe300
/* 21A18 80046618 35AD1402 */  ori       $t5, $t5, 0x1402
/* 21A1C 8004661C 3C0EE300 */  lui       $t6, 0xe300
/* 21A20 80046620 35CE1700 */  ori       $t6, $t6, 0x1700
/* 21A24 80046624 3C0FE200 */  lui       $t7, 0xe200
/* 21A28 80046628 35EF1E01 */  ori       $t7, $t7, 0x1e01
/* 21A2C 8004662C AFB00040 */  sw        $s0, 0x40($sp)
/* 21A30 80046630 3C10E300 */  lui       $s0, 0xe300
/* 21A34 80046634 36101801 */  ori       $s0, $s0, 0x1801
/* 21A38 80046638 AFB10044 */  sw        $s1, 0x44($sp)
/* 21A3C 8004663C 3C11E300 */  lui       $s1, 0xe300
/* 21A40 80046640 36311A01 */  ori       $s1, $s1, 0x1a01
/* 21A44 80046644 AFB20048 */  sw        $s2, 0x48($sp)
/* 21A48 80046648 3C12D700 */  lui       $s2, 0xd700
/* 21A4C 8004664C 36520002 */  ori       $s2, $s2, 2
/* 21A50 80046650 AFBE0060 */  sw        $fp, 0x60($sp)
/* 21A54 80046654 241E0001 */  addiu     $fp, $zero, 1
/* 21A58 80046658 AFB7005C */  sw        $s7, 0x5c($sp)
/* 21A5C 8004665C 27B70028 */  addiu     $s7, $sp, 0x28
/* 21A60 80046660 AFB60058 */  sw        $s6, 0x58($sp)
/* 21A64 80046664 27B6002C */  addiu     $s6, $sp, 0x2c
/* 21A68 80046668 AFB50054 */  sw        $s5, 0x54($sp)
/* 21A6C 8004666C 27B50030 */  addiu     $s5, $sp, 0x30
/* 21A70 80046670 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 21A74 80046674 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 21A78 80046678 3C06800B */  lui       $a2, %hi(gCameras)
/* 21A7C 8004667C 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
/* 21A80 80046680 AFBF0064 */  sw        $ra, 0x64($sp)
/* 21A84 80046684 AFB40050 */  sw        $s4, 0x50($sp)
/* 21A88 80046688 AFB3004C */  sw        $s3, 0x4c($sp)
/* 21A8C 8004668C F7B60070 */  sdc1      $f22, 0x70($sp)
/* 21A90 80046690 F7B40068 */  sdc1      $f20, 0x68($sp)
/* 21A94 80046694 AFA00038 */  sw        $zero, 0x38($sp)
/* 21A98 80046698 8CA30000 */  lw        $v1, ($a1)
/* 21A9C 8004669C 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 21AA0 800466A0 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 21AA4 800466A4 3C0142B4 */  lui       $at, 0x42b4
/* 21AA8 800466A8 4481B000 */  mtc1      $at, $f22
/* 21AAC 800466AC 00041080 */  sll       $v0, $a0, 2
/* 21AB0 800466B0 00441021 */  addu      $v0, $v0, $a0
/* 21AB4 800466B4 00021080 */  sll       $v0, $v0, 2
/* 21AB8 800466B8 00441023 */  subu      $v0, $v0, $a0
/* 21ABC 800466BC 000220C0 */  sll       $a0, $v0, 3
/* 21AC0 800466C0 00441021 */  addu      $v0, $v0, $a0
/* 21AC4 800466C4 000210C0 */  sll       $v0, $v0, 3
/* 21AC8 800466C8 00461021 */  addu      $v0, $v0, $a2
/* 21ACC 800466CC AFA20034 */  sw        $v0, 0x34($sp)
/* 21AD0 800466D0 0060102D */  daddu     $v0, $v1, $zero
/* 21AD4 800466D4 24630008 */  addiu     $v1, $v1, 8
/* 21AD8 800466D8 ACA30000 */  sw        $v1, ($a1)
/* 21ADC 800466DC AC480000 */  sw        $t0, ($v0)
/* 21AE0 800466E0 AC470004 */  sw        $a3, 4($v0)
/* 21AE4 800466E4 24620008 */  addiu     $v0, $v1, 8
/* 21AE8 800466E8 ACA20000 */  sw        $v0, ($a1)
/* 21AEC 800466EC 3C02E700 */  lui       $v0, 0xe700
/* 21AF0 800466F0 AC620000 */  sw        $v0, ($v1)
/* 21AF4 800466F4 24620010 */  addiu     $v0, $v1, 0x10
/* 21AF8 800466F8 AC600004 */  sw        $zero, 4($v1)
/* 21AFC 800466FC ACA20000 */  sw        $v0, ($a1)
/* 21B00 80046700 24620018 */  addiu     $v0, $v1, 0x18
/* 21B04 80046704 AC690008 */  sw        $t1, 8($v1)
/* 21B08 80046708 AC60000C */  sw        $zero, 0xc($v1)
/* 21B0C 8004670C ACA20000 */  sw        $v0, ($a1)
/* 21B10 80046710 24620020 */  addiu     $v0, $v1, 0x20
/* 21B14 80046714 AC6A0010 */  sw        $t2, 0x10($v1)
/* 21B18 80046718 AC600014 */  sw        $zero, 0x14($v1)
/* 21B1C 8004671C ACA20000 */  sw        $v0, ($a1)
/* 21B20 80046720 24620028 */  addiu     $v0, $v1, 0x28
/* 21B24 80046724 AC6B0018 */  sw        $t3, 0x18($v1)
/* 21B28 80046728 AC60001C */  sw        $zero, 0x1c($v1)
/* 21B2C 8004672C ACA20000 */  sw        $v0, ($a1)
/* 21B30 80046730 24620030 */  addiu     $v0, $v1, 0x30
/* 21B34 80046734 AC6C0020 */  sw        $t4, 0x20($v1)
/* 21B38 80046738 AC600024 */  sw        $zero, 0x24($v1)
/* 21B3C 8004673C ACA20000 */  sw        $v0, ($a1)
/* 21B40 80046740 24020C00 */  addiu     $v0, $zero, 0xc00
/* 21B44 80046744 AC62002C */  sw        $v0, 0x2c($v1)
/* 21B48 80046748 24620038 */  addiu     $v0, $v1, 0x38
/* 21B4C 8004674C AC6D0028 */  sw        $t5, 0x28($v1)
/* 21B50 80046750 ACA20000 */  sw        $v0, ($a1)
/* 21B54 80046754 24620040 */  addiu     $v0, $v1, 0x40
/* 21B58 80046758 AC6E0030 */  sw        $t6, 0x30($v1)
/* 21B5C 8004675C AC600034 */  sw        $zero, 0x34($v1)
/* 21B60 80046760 ACA20000 */  sw        $v0, ($a1)
/* 21B64 80046764 24620048 */  addiu     $v0, $v1, 0x48
/* 21B68 80046768 AC6F0038 */  sw        $t7, 0x38($v1)
/* 21B6C 8004676C AC60003C */  sw        $zero, 0x3c($v1)
/* 21B70 80046770 ACA20000 */  sw        $v0, ($a1)
/* 21B74 80046774 24620050 */  addiu     $v0, $v1, 0x50
/* 21B78 80046778 AC600040 */  sw        $zero, 0x40($v1)
/* 21B7C 8004677C AC600044 */  sw        $zero, 0x44($v1)
/* 21B80 80046780 ACA20000 */  sw        $v0, ($a1)
/* 21B84 80046784 AC700048 */  sw        $s0, 0x48($v1)
/* 21B88 80046788 3C14800A */  lui       $s4, %hi(D_800A0F44)
/* 21B8C 8004678C 8E940F44 */  lw        $s4, %lo(D_800A0F44)($s4)
/* 21B90 80046790 240200C0 */  addiu     $v0, $zero, 0xc0
/* 21B94 80046794 AC62004C */  sw        $v0, 0x4c($v1)
/* 21B98 80046798 24620058 */  addiu     $v0, $v1, 0x58
/* 21B9C 8004679C ACA20000 */  sw        $v0, ($a1)
/* 21BA0 800467A0 24020030 */  addiu     $v0, $zero, 0x30
/* 21BA4 800467A4 AC620054 */  sw        $v0, 0x54($v1)
/* 21BA8 800467A8 24620060 */  addiu     $v0, $v1, 0x60
/* 21BAC 800467AC AC710050 */  sw        $s1, 0x50($v1)
/* 21BB0 800467B0 ACA20000 */  sw        $v0, ($a1)
/* 21BB4 800467B4 2402FFFF */  addiu     $v0, $zero, -1
/* 21BB8 800467B8 AC720058 */  sw        $s2, 0x58($v1)
/* 21BBC 800467BC AC62005C */  sw        $v0, 0x5c($v1)
/* 21BC0 800467C0 269100AC */  addiu     $s1, $s4, 0xac
.L800467C4:
/* 21BC4 800467C4 8E830000 */  lw        $v1, ($s4)
/* 21BC8 800467C8 5060037B */  beql      $v1, $zero, .L800475B8
/* 21BCC 800467CC 263100B0 */   addiu    $s1, $s1, 0xb0
/* 21BD0 800467D0 0000902D */  daddu     $s2, $zero, $zero
/* 21BD4 800467D4 8222FF8E */  lb        $v0, -0x72($s1)
/* 21BD8 800467D8 24180002 */  addiu     $t8, $zero, 2
/* 21BDC 800467DC 1458003C */  bne       $v0, $t8, .L800468D0
/* 21BE0 800467E0 0240982D */   daddu    $s3, $s2, $zero
/* 21BE4 800467E4 30620004 */  andi      $v0, $v1, 4
/* 21BE8 800467E8 10400006 */  beqz      $v0, .L80046804
/* 21BEC 800467EC 30620002 */   andi     $v0, $v1, 2
/* 21BF0 800467F0 8E24FF94 */  lw        $a0, -0x6c($s1)
/* 21BF4 800467F4 0C051280 */  jal       set_hud_element_flags
/* 21BF8 800467F8 0300282D */   daddu    $a1, $t8, $zero
/* 21BFC 800467FC 08011A34 */  j         .L800468D0
/* 21C00 80046800 00000000 */   nop
.L80046804:
/* 21C04 80046804 14400006 */  bnez      $v0, .L80046820
/* 21C08 80046808 00000000 */   nop
/* 21C0C 8004680C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 21C10 80046810 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 21C14 80046814 80420070 */  lb        $v0, 0x70($v0)
/* 21C18 80046818 105E002D */  beq       $v0, $fp, .L800468D0
/* 21C1C 8004681C 00000000 */   nop
.L80046820:
/* 21C20 80046820 8E24FF94 */  lw        $a0, -0x6c($s1)
/* 21C24 80046824 0C05128B */  jal       clear_hud_element_flags
/* 21C28 80046828 24050002 */   addiu    $a1, $zero, 2
/* 21C2C 8004682C C620FF68 */  lwc1      $f0, -0x98($s1)
/* 21C30 80046830 46800020 */  cvt.s.w   $f0, $f0
/* 21C34 80046834 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 21C38 80046838 8FB80034 */  lw        $t8, 0x34($sp)
/* 21C3C 8004683C 46001500 */  add.s     $f20, $f2, $f0
/* 21C40 80046840 C622FF58 */  lwc1      $f2, -0xa8($s1)
/* 21C44 80046844 C70C006C */  lwc1      $f12, 0x6c($t8)
/* 21C48 80046848 C620FF60 */  lwc1      $f0, -0xa0($s1)
/* 21C4C 8004684C 46166300 */  add.s     $f12, $f12, $f22
/* 21C50 80046850 E7A20020 */  swc1      $f2, 0x20($sp)
/* 21C54 80046854 0C00A6C9 */  jal       clamp_angle
/* 21C58 80046858 E7A00024 */   swc1     $f0, 0x24($sp)
/* 21C5C 8004685C 27A40020 */  addiu     $a0, $sp, 0x20
/* 21C60 80046860 C626FF64 */  lwc1      $f6, -0x9c($s1)
/* 21C64 80046864 468031A0 */  cvt.s.w   $f6, $f6
/* 21C68 80046868 44070000 */  mfc1      $a3, $f0
/* 21C6C 8004686C 44063000 */  mfc1      $a2, $f6
/* 21C70 80046870 0C00A7E7 */  jal       add_vec2D_polar
/* 21C74 80046874 27A50024 */   addiu    $a1, $sp, 0x24
/* 21C78 80046878 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 21C7C 8004687C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 21C80 80046880 4406A000 */  mfc1      $a2, $f20
/* 21C84 80046884 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 21C88 80046888 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 21C8C 8004688C 44050000 */  mfc1      $a1, $f0
/* 21C90 80046890 44071000 */  mfc1      $a3, $f2
/* 21C94 80046894 24120001 */  addiu     $s2, $zero, 1
/* 21C98 80046898 AFB70010 */  sw        $s7, 0x10($sp)
/* 21C9C 8004689C AFB60014 */  sw        $s6, 0x14($sp)
/* 21CA0 800468A0 0C00B94E */  jal       get_screen_coords
/* 21CA4 800468A4 AFB50018 */   sw       $s5, 0x18($sp)
/* 21CA8 800468A8 0240982D */  daddu     $s3, $s2, $zero
/* 21CAC 800468AC 8E30FF94 */  lw        $s0, -0x6c($s1)
/* 21CB0 800468B0 8FA50028 */  lw        $a1, 0x28($sp)
/* 21CB4 800468B4 8FA6002C */  lw        $a2, 0x2c($sp)
/* 21CB8 800468B8 0200202D */  daddu     $a0, $s0, $zero
/* 21CBC 800468BC 24A5FFF8 */  addiu     $a1, $a1, -8
/* 21CC0 800468C0 0C051261 */  jal       set_hud_element_render_pos
/* 21CC4 800468C4 24C6FFF8 */   addiu    $a2, $a2, -8
/* 21CC8 800468C8 0C0511F1 */  jal       draw_hud_element_2
/* 21CCC 800468CC 0200202D */   daddu    $a0, $s0, $zero
.L800468D0:
/* 21CD0 800468D0 8222FF8F */  lb        $v0, -0x71($s1)
/* 21CD4 800468D4 24180002 */  addiu     $t8, $zero, 2
/* 21CD8 800468D8 14580036 */  bne       $v0, $t8, .L800469B4
/* 21CDC 800468DC 00000000 */   nop
/* 21CE0 800468E0 8E820000 */  lw        $v0, ($s4)
/* 21CE4 800468E4 00581024 */  and       $v0, $v0, $t8
/* 21CE8 800468E8 14400006 */  bnez      $v0, .L80046904
/* 21CEC 800468EC 00000000 */   nop
/* 21CF0 800468F0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 21CF4 800468F4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 21CF8 800468F8 80420070 */  lb        $v0, 0x70($v0)
/* 21CFC 800468FC 105E002D */  beq       $v0, $fp, .L800469B4
/* 21D00 80046900 00000000 */   nop
.L80046904:
/* 21D04 80046904 8E24FF98 */  lw        $a0, -0x68($s1)
/* 21D08 80046908 0C05128B */  jal       clear_hud_element_flags
/* 21D0C 8004690C 24050002 */   addiu    $a1, $zero, 2
/* 21D10 80046910 52600001 */  beql      $s3, $zero, .L80046918
/* 21D14 80046914 26520001 */   addiu    $s2, $s2, 1
.L80046918:
/* 21D18 80046918 C620FF68 */  lwc1      $f0, -0x98($s1)
/* 21D1C 8004691C 46800020 */  cvt.s.w   $f0, $f0
/* 21D20 80046920 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 21D24 80046924 8FB80034 */  lw        $t8, 0x34($sp)
/* 21D28 80046928 46001500 */  add.s     $f20, $f2, $f0
/* 21D2C 8004692C C622FF58 */  lwc1      $f2, -0xa8($s1)
/* 21D30 80046930 C70C006C */  lwc1      $f12, 0x6c($t8)
/* 21D34 80046934 C620FF60 */  lwc1      $f0, -0xa0($s1)
/* 21D38 80046938 46166300 */  add.s     $f12, $f12, $f22
/* 21D3C 8004693C E7A20020 */  swc1      $f2, 0x20($sp)
/* 21D40 80046940 0C00A6C9 */  jal       clamp_angle
/* 21D44 80046944 E7A00024 */   swc1     $f0, 0x24($sp)
/* 21D48 80046948 27A40020 */  addiu     $a0, $sp, 0x20
/* 21D4C 8004694C C626FF64 */  lwc1      $f6, -0x9c($s1)
/* 21D50 80046950 468031A0 */  cvt.s.w   $f6, $f6
/* 21D54 80046954 44070000 */  mfc1      $a3, $f0
/* 21D58 80046958 44063000 */  mfc1      $a2, $f6
/* 21D5C 8004695C 0C00A7E7 */  jal       add_vec2D_polar
/* 21D60 80046960 27A50024 */   addiu    $a1, $sp, 0x24
/* 21D64 80046964 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 21D68 80046968 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 21D6C 8004696C 4406A000 */  mfc1      $a2, $f20
/* 21D70 80046970 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 21D74 80046974 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 21D78 80046978 44050000 */  mfc1      $a1, $f0
/* 21D7C 8004697C 44071000 */  mfc1      $a3, $f2
/* 21D80 80046980 AFB70010 */  sw        $s7, 0x10($sp)
/* 21D84 80046984 AFB60014 */  sw        $s6, 0x14($sp)
/* 21D88 80046988 0C00B94E */  jal       get_screen_coords
/* 21D8C 8004698C AFB50018 */   sw       $s5, 0x18($sp)
/* 21D90 80046990 8E30FF98 */  lw        $s0, -0x68($s1)
/* 21D94 80046994 8FA50028 */  lw        $a1, 0x28($sp)
/* 21D98 80046998 8FA6002C */  lw        $a2, 0x2c($sp)
/* 21D9C 8004699C 0200202D */  daddu     $a0, $s0, $zero
/* 21DA0 800469A0 24A5FFF8 */  addiu     $a1, $a1, -8
/* 21DA4 800469A4 0C051261 */  jal       set_hud_element_render_pos
/* 21DA8 800469A8 24C6FFF8 */   addiu    $a2, $a2, -8
/* 21DAC 800469AC 0C0511F1 */  jal       draw_hud_element_2
/* 21DB0 800469B0 0200202D */   daddu    $a0, $s0, $zero
.L800469B4:
/* 21DB4 800469B4 8222FF9E */  lb        $v0, -0x62($s1)
/* 21DB8 800469B8 24180002 */  addiu     $t8, $zero, 2
/* 21DBC 800469BC 14580044 */  bne       $v0, $t8, .L80046AD0
/* 21DC0 800469C0 0000982D */   daddu    $s3, $zero, $zero
/* 21DC4 800469C4 8E830000 */  lw        $v1, ($s4)
/* 21DC8 800469C8 30620008 */  andi      $v0, $v1, 8
/* 21DCC 800469CC 10400006 */  beqz      $v0, .L800469E8
/* 21DD0 800469D0 30620002 */   andi     $v0, $v1, 2
/* 21DD4 800469D4 8E24FFA4 */  lw        $a0, -0x5c($s1)
/* 21DD8 800469D8 0C051280 */  jal       set_hud_element_flags
/* 21DDC 800469DC 0300282D */   daddu    $a1, $t8, $zero
/* 21DE0 800469E0 08011AB4 */  j         .L80046AD0
/* 21DE4 800469E4 00000000 */   nop
.L800469E8:
/* 21DE8 800469E8 14400006 */  bnez      $v0, .L80046A04
/* 21DEC 800469EC 00000000 */   nop
/* 21DF0 800469F0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 21DF4 800469F4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 21DF8 800469F8 80420070 */  lb        $v0, 0x70($v0)
/* 21DFC 800469FC 105E0034 */  beq       $v0, $fp, .L80046AD0
/* 21E00 80046A00 00000000 */   nop
.L80046A04:
/* 21E04 80046A04 8E24FFA4 */  lw        $a0, -0x5c($s1)
/* 21E08 80046A08 0C05128B */  jal       clear_hud_element_flags
/* 21E0C 80046A0C 24050002 */   addiu    $a1, $zero, 2
/* 21E10 80046A10 16400002 */  bnez      $s2, .L80046A1C
/* 21E14 80046A14 0000102D */   daddu    $v0, $zero, $zero
/* 21E18 80046A18 2402FFEF */  addiu     $v0, $zero, -0x11
.L80046A1C:
/* 21E1C 80046A1C 8FB80034 */  lw        $t8, 0x34($sp)
/* 21E20 80046A20 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 21E24 80046A24 C70C006C */  lwc1      $f12, 0x6c($t8)
/* 21E28 80046A28 E7A00020 */  swc1      $f0, 0x20($sp)
/* 21E2C 80046A2C C624FF70 */  lwc1      $f4, -0x90($s1)
/* 21E30 80046A30 46802120 */  cvt.s.w   $f4, $f4
/* 21E34 80046A34 46166300 */  add.s     $f12, $f12, $f22
/* 21E38 80046A38 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 21E3C 80046A3C C620FF60 */  lwc1      $f0, -0xa0($s1)
/* 21E40 80046A40 46041080 */  add.s     $f2, $f2, $f4
/* 21E44 80046A44 E7A00024 */  swc1      $f0, 0x24($sp)
/* 21E48 80046A48 44820000 */  mtc1      $v0, $f0
/* 21E4C 80046A4C 00000000 */  nop
/* 21E50 80046A50 46800020 */  cvt.s.w   $f0, $f0
/* 21E54 80046A54 0C00A6C9 */  jal       clamp_angle
/* 21E58 80046A58 46001500 */   add.s    $f20, $f2, $f0
/* 21E5C 80046A5C 27A40020 */  addiu     $a0, $sp, 0x20
/* 21E60 80046A60 C626FF6C */  lwc1      $f6, -0x94($s1)
/* 21E64 80046A64 468031A0 */  cvt.s.w   $f6, $f6
/* 21E68 80046A68 44070000 */  mfc1      $a3, $f0
/* 21E6C 80046A6C 44063000 */  mfc1      $a2, $f6
/* 21E70 80046A70 0C00A7E7 */  jal       add_vec2D_polar
/* 21E74 80046A74 27A50024 */   addiu    $a1, $sp, 0x24
/* 21E78 80046A78 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 21E7C 80046A7C 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 21E80 80046A80 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 21E84 80046A84 44050000 */  mfc1      $a1, $f0
/* 21E88 80046A88 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 21E8C 80046A8C 4406A000 */  mfc1      $a2, $f20
/* 21E90 80046A90 44070000 */  mfc1      $a3, $f0
/* 21E94 80046A94 26520001 */  addiu     $s2, $s2, 1
/* 21E98 80046A98 AFB70010 */  sw        $s7, 0x10($sp)
/* 21E9C 80046A9C AFB60014 */  sw        $s6, 0x14($sp)
/* 21EA0 80046AA0 0C00B94E */  jal       get_screen_coords
/* 21EA4 80046AA4 AFB50018 */   sw       $s5, 0x18($sp)
/* 21EA8 80046AA8 24130001 */  addiu     $s3, $zero, 1
/* 21EAC 80046AAC 8E30FFA4 */  lw        $s0, -0x5c($s1)
/* 21EB0 80046AB0 8FA50028 */  lw        $a1, 0x28($sp)
/* 21EB4 80046AB4 8FA6002C */  lw        $a2, 0x2c($sp)
/* 21EB8 80046AB8 0200202D */  daddu     $a0, $s0, $zero
/* 21EBC 80046ABC 24A5FFF8 */  addiu     $a1, $a1, -8
/* 21EC0 80046AC0 0C051261 */  jal       set_hud_element_render_pos
/* 21EC4 80046AC4 24C6FFF8 */   addiu    $a2, $a2, -8
/* 21EC8 80046AC8 0C0511F1 */  jal       draw_hud_element_2
/* 21ECC 80046ACC 0200202D */   daddu    $a0, $s0, $zero
.L80046AD0:
/* 21ED0 80046AD0 8222FF9F */  lb        $v0, -0x61($s1)
/* 21ED4 80046AD4 24180002 */  addiu     $t8, $zero, 2
/* 21ED8 80046AD8 1458003D */  bne       $v0, $t8, .L80046BD0
/* 21EDC 80046ADC 00000000 */   nop
/* 21EE0 80046AE0 8E820000 */  lw        $v0, ($s4)
/* 21EE4 80046AE4 00581024 */  and       $v0, $v0, $t8
/* 21EE8 80046AE8 14400006 */  bnez      $v0, .L80046B04
/* 21EEC 80046AEC 00000000 */   nop
/* 21EF0 80046AF0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 21EF4 80046AF4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 21EF8 80046AF8 80420070 */  lb        $v0, 0x70($v0)
/* 21EFC 80046AFC 105E0034 */  beq       $v0, $fp, .L80046BD0
/* 21F00 80046B00 00000000 */   nop
.L80046B04:
/* 21F04 80046B04 8E24FFA8 */  lw        $a0, -0x58($s1)
/* 21F08 80046B08 0C05128B */  jal       clear_hud_element_flags
/* 21F0C 80046B0C 24050002 */   addiu    $a1, $zero, 2
/* 21F10 80046B10 16400002 */  bnez      $s2, .L80046B1C
/* 21F14 80046B14 0000102D */   daddu    $v0, $zero, $zero
/* 21F18 80046B18 2402FFEF */  addiu     $v0, $zero, -0x11
.L80046B1C:
/* 21F1C 80046B1C 52600001 */  beql      $s3, $zero, .L80046B24
/* 21F20 80046B20 26520001 */   addiu    $s2, $s2, 1
.L80046B24:
/* 21F24 80046B24 8FB80034 */  lw        $t8, 0x34($sp)
/* 21F28 80046B28 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 21F2C 80046B2C C70C006C */  lwc1      $f12, 0x6c($t8)
/* 21F30 80046B30 E7A00020 */  swc1      $f0, 0x20($sp)
/* 21F34 80046B34 C624FF70 */  lwc1      $f4, -0x90($s1)
/* 21F38 80046B38 46802120 */  cvt.s.w   $f4, $f4
/* 21F3C 80046B3C 46166300 */  add.s     $f12, $f12, $f22
/* 21F40 80046B40 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 21F44 80046B44 C620FF60 */  lwc1      $f0, -0xa0($s1)
/* 21F48 80046B48 46041080 */  add.s     $f2, $f2, $f4
/* 21F4C 80046B4C E7A00024 */  swc1      $f0, 0x24($sp)
/* 21F50 80046B50 44820000 */  mtc1      $v0, $f0
/* 21F54 80046B54 00000000 */  nop
/* 21F58 80046B58 46800020 */  cvt.s.w   $f0, $f0
/* 21F5C 80046B5C 0C00A6C9 */  jal       clamp_angle
/* 21F60 80046B60 46001500 */   add.s    $f20, $f2, $f0
/* 21F64 80046B64 27A40020 */  addiu     $a0, $sp, 0x20
/* 21F68 80046B68 C626FF6C */  lwc1      $f6, -0x94($s1)
/* 21F6C 80046B6C 468031A0 */  cvt.s.w   $f6, $f6
/* 21F70 80046B70 44070000 */  mfc1      $a3, $f0
/* 21F74 80046B74 44063000 */  mfc1      $a2, $f6
/* 21F78 80046B78 0C00A7E7 */  jal       add_vec2D_polar
/* 21F7C 80046B7C 27A50024 */   addiu    $a1, $sp, 0x24
/* 21F80 80046B80 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 21F84 80046B84 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 21F88 80046B88 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 21F8C 80046B8C 44050000 */  mfc1      $a1, $f0
/* 21F90 80046B90 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 21F94 80046B94 4406A000 */  mfc1      $a2, $f20
/* 21F98 80046B98 44070000 */  mfc1      $a3, $f0
/* 21F9C 80046B9C AFB70010 */  sw        $s7, 0x10($sp)
/* 21FA0 80046BA0 AFB60014 */  sw        $s6, 0x14($sp)
/* 21FA4 80046BA4 0C00B94E */  jal       get_screen_coords
/* 21FA8 80046BA8 AFB50018 */   sw       $s5, 0x18($sp)
/* 21FAC 80046BAC 8E30FFA8 */  lw        $s0, -0x58($s1)
/* 21FB0 80046BB0 8FA50028 */  lw        $a1, 0x28($sp)
/* 21FB4 80046BB4 8FA6002C */  lw        $a2, 0x2c($sp)
/* 21FB8 80046BB8 0200202D */  daddu     $a0, $s0, $zero
/* 21FBC 80046BBC 24A5FFF8 */  addiu     $a1, $a1, -8
/* 21FC0 80046BC0 0C051261 */  jal       set_hud_element_render_pos
/* 21FC4 80046BC4 24C6FFF8 */   addiu    $a2, $a2, -8
/* 21FC8 80046BC8 0C0511F1 */  jal       draw_hud_element_2
/* 21FCC 80046BCC 0200202D */   daddu    $a0, $s0, $zero
.L80046BD0:
/* 21FD0 80046BD0 8222FFAE */  lb        $v0, -0x52($s1)
/* 21FD4 80046BD4 24180002 */  addiu     $t8, $zero, 2
/* 21FD8 80046BD8 14580046 */  bne       $v0, $t8, .L80046CF4
/* 21FDC 80046BDC 0000982D */   daddu    $s3, $zero, $zero
/* 21FE0 80046BE0 8E830000 */  lw        $v1, ($s4)
/* 21FE4 80046BE4 30620010 */  andi      $v0, $v1, 0x10
/* 21FE8 80046BE8 10400006 */  beqz      $v0, .L80046C04
/* 21FEC 80046BEC 30620002 */   andi     $v0, $v1, 2
/* 21FF0 80046BF0 8E24FFB4 */  lw        $a0, -0x4c($s1)
/* 21FF4 80046BF4 0C051280 */  jal       set_hud_element_flags
/* 21FF8 80046BF8 0300282D */   daddu    $a1, $t8, $zero
/* 21FFC 80046BFC 08011B3D */  j         .L80046CF4
/* 22000 80046C00 00000000 */   nop
.L80046C04:
/* 22004 80046C04 14400006 */  bnez      $v0, .L80046C20
/* 22008 80046C08 00000000 */   nop
/* 2200C 80046C0C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 22010 80046C10 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 22014 80046C14 80420070 */  lb        $v0, 0x70($v0)
/* 22018 80046C18 105E0036 */  beq       $v0, $fp, .L80046CF4
/* 2201C 80046C1C 00000000 */   nop
.L80046C20:
/* 22020 80046C20 8E24FFB4 */  lw        $a0, -0x4c($s1)
/* 22024 80046C24 0C05128B */  jal       clear_hud_element_flags
/* 22028 80046C28 24050002 */   addiu    $a1, $zero, 2
/* 2202C 80046C2C 165E0002 */  bne       $s2, $fp, .L80046C38
/* 22030 80046C30 0000102D */   daddu    $v0, $zero, $zero
/* 22034 80046C34 2402FFEF */  addiu     $v0, $zero, -0x11
.L80046C38:
/* 22038 80046C38 52400001 */  beql      $s2, $zero, .L80046C40
/* 2203C 80046C3C 2402FFDE */   addiu    $v0, $zero, -0x22
.L80046C40:
/* 22040 80046C40 8FB80034 */  lw        $t8, 0x34($sp)
/* 22044 80046C44 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 22048 80046C48 C70C006C */  lwc1      $f12, 0x6c($t8)
/* 2204C 80046C4C E7A00020 */  swc1      $f0, 0x20($sp)
/* 22050 80046C50 C624FF78 */  lwc1      $f4, -0x88($s1)
/* 22054 80046C54 46802120 */  cvt.s.w   $f4, $f4
/* 22058 80046C58 46166300 */  add.s     $f12, $f12, $f22
/* 2205C 80046C5C C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22060 80046C60 C620FF60 */  lwc1      $f0, -0xa0($s1)
/* 22064 80046C64 46041080 */  add.s     $f2, $f2, $f4
/* 22068 80046C68 E7A00024 */  swc1      $f0, 0x24($sp)
/* 2206C 80046C6C 44820000 */  mtc1      $v0, $f0
/* 22070 80046C70 00000000 */  nop
/* 22074 80046C74 46800020 */  cvt.s.w   $f0, $f0
/* 22078 80046C78 0C00A6C9 */  jal       clamp_angle
/* 2207C 80046C7C 46001500 */   add.s    $f20, $f2, $f0
/* 22080 80046C80 27A40020 */  addiu     $a0, $sp, 0x20
/* 22084 80046C84 C626FF74 */  lwc1      $f6, -0x8c($s1)
/* 22088 80046C88 468031A0 */  cvt.s.w   $f6, $f6
/* 2208C 80046C8C 44070000 */  mfc1      $a3, $f0
/* 22090 80046C90 44063000 */  mfc1      $a2, $f6
/* 22094 80046C94 0C00A7E7 */  jal       add_vec2D_polar
/* 22098 80046C98 27A50024 */   addiu    $a1, $sp, 0x24
/* 2209C 80046C9C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 220A0 80046CA0 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 220A4 80046CA4 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 220A8 80046CA8 44050000 */  mfc1      $a1, $f0
/* 220AC 80046CAC C7A00024 */  lwc1      $f0, 0x24($sp)
/* 220B0 80046CB0 4406A000 */  mfc1      $a2, $f20
/* 220B4 80046CB4 44070000 */  mfc1      $a3, $f0
/* 220B8 80046CB8 26520001 */  addiu     $s2, $s2, 1
/* 220BC 80046CBC AFB70010 */  sw        $s7, 0x10($sp)
/* 220C0 80046CC0 AFB60014 */  sw        $s6, 0x14($sp)
/* 220C4 80046CC4 0C00B94E */  jal       get_screen_coords
/* 220C8 80046CC8 AFB50018 */   sw       $s5, 0x18($sp)
/* 220CC 80046CCC 24130001 */  addiu     $s3, $zero, 1
/* 220D0 80046CD0 8E30FFB4 */  lw        $s0, -0x4c($s1)
/* 220D4 80046CD4 8FA50028 */  lw        $a1, 0x28($sp)
/* 220D8 80046CD8 8FA6002C */  lw        $a2, 0x2c($sp)
/* 220DC 80046CDC 0200202D */  daddu     $a0, $s0, $zero
/* 220E0 80046CE0 24A5FFF8 */  addiu     $a1, $a1, -8
/* 220E4 80046CE4 0C051261 */  jal       set_hud_element_render_pos
/* 220E8 80046CE8 24C6FFF8 */   addiu    $a2, $a2, -8
/* 220EC 80046CEC 0C0511F1 */  jal       draw_hud_element_2
/* 220F0 80046CF0 0200202D */   daddu    $a0, $s0, $zero
.L80046CF4:
/* 220F4 80046CF4 8222FFAF */  lb        $v0, -0x51($s1)
/* 220F8 80046CF8 24180002 */  addiu     $t8, $zero, 2
/* 220FC 80046CFC 1458003F */  bne       $v0, $t8, .L80046DFC
/* 22100 80046D00 00000000 */   nop
/* 22104 80046D04 8E820000 */  lw        $v0, ($s4)
/* 22108 80046D08 00581024 */  and       $v0, $v0, $t8
/* 2210C 80046D0C 14400006 */  bnez      $v0, .L80046D28
/* 22110 80046D10 00000000 */   nop
/* 22114 80046D14 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 22118 80046D18 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 2211C 80046D1C 80420070 */  lb        $v0, 0x70($v0)
/* 22120 80046D20 105E0036 */  beq       $v0, $fp, .L80046DFC
/* 22124 80046D24 00000000 */   nop
.L80046D28:
/* 22128 80046D28 8E24FFB8 */  lw        $a0, -0x48($s1)
/* 2212C 80046D2C 0C05128B */  jal       clear_hud_element_flags
/* 22130 80046D30 24050002 */   addiu    $a1, $zero, 2
/* 22134 80046D34 165E0002 */  bne       $s2, $fp, .L80046D40
/* 22138 80046D38 0000102D */   daddu    $v0, $zero, $zero
/* 2213C 80046D3C 2402FFEF */  addiu     $v0, $zero, -0x11
.L80046D40:
/* 22140 80046D40 52400001 */  beql      $s2, $zero, .L80046D48
/* 22144 80046D44 2402FFDE */   addiu    $v0, $zero, -0x22
.L80046D48:
/* 22148 80046D48 52600001 */  beql      $s3, $zero, .L80046D50
/* 2214C 80046D4C 26520001 */   addiu    $s2, $s2, 1
.L80046D50:
/* 22150 80046D50 8FB80034 */  lw        $t8, 0x34($sp)
/* 22154 80046D54 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 22158 80046D58 C70C006C */  lwc1      $f12, 0x6c($t8)
/* 2215C 80046D5C E7A00020 */  swc1      $f0, 0x20($sp)
/* 22160 80046D60 C624FF78 */  lwc1      $f4, -0x88($s1)
/* 22164 80046D64 46802120 */  cvt.s.w   $f4, $f4
/* 22168 80046D68 46166300 */  add.s     $f12, $f12, $f22
/* 2216C 80046D6C C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22170 80046D70 C620FF60 */  lwc1      $f0, -0xa0($s1)
/* 22174 80046D74 46041080 */  add.s     $f2, $f2, $f4
/* 22178 80046D78 E7A00024 */  swc1      $f0, 0x24($sp)
/* 2217C 80046D7C 44820000 */  mtc1      $v0, $f0
/* 22180 80046D80 00000000 */  nop
/* 22184 80046D84 46800020 */  cvt.s.w   $f0, $f0
/* 22188 80046D88 0C00A6C9 */  jal       clamp_angle
/* 2218C 80046D8C 46001500 */   add.s    $f20, $f2, $f0
/* 22190 80046D90 27A40020 */  addiu     $a0, $sp, 0x20
/* 22194 80046D94 C626FF74 */  lwc1      $f6, -0x8c($s1)
/* 22198 80046D98 468031A0 */  cvt.s.w   $f6, $f6
/* 2219C 80046D9C 44070000 */  mfc1      $a3, $f0
/* 221A0 80046DA0 44063000 */  mfc1      $a2, $f6
/* 221A4 80046DA4 0C00A7E7 */  jal       add_vec2D_polar
/* 221A8 80046DA8 27A50024 */   addiu    $a1, $sp, 0x24
/* 221AC 80046DAC C7A00020 */  lwc1      $f0, 0x20($sp)
/* 221B0 80046DB0 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 221B4 80046DB4 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 221B8 80046DB8 44050000 */  mfc1      $a1, $f0
/* 221BC 80046DBC C7A00024 */  lwc1      $f0, 0x24($sp)
/* 221C0 80046DC0 4406A000 */  mfc1      $a2, $f20
/* 221C4 80046DC4 44070000 */  mfc1      $a3, $f0
/* 221C8 80046DC8 AFB70010 */  sw        $s7, 0x10($sp)
/* 221CC 80046DCC AFB60014 */  sw        $s6, 0x14($sp)
/* 221D0 80046DD0 0C00B94E */  jal       get_screen_coords
/* 221D4 80046DD4 AFB50018 */   sw       $s5, 0x18($sp)
/* 221D8 80046DD8 8E30FFB8 */  lw        $s0, -0x48($s1)
/* 221DC 80046DDC 8FA50028 */  lw        $a1, 0x28($sp)
/* 221E0 80046DE0 8FA6002C */  lw        $a2, 0x2c($sp)
/* 221E4 80046DE4 0200202D */  daddu     $a0, $s0, $zero
/* 221E8 80046DE8 24A5FFF8 */  addiu     $a1, $a1, -8
/* 221EC 80046DEC 0C051261 */  jal       set_hud_element_render_pos
/* 221F0 80046DF0 24C6FFF8 */   addiu    $a2, $a2, -8
/* 221F4 80046DF4 0C0511F1 */  jal       draw_hud_element_2
/* 221F8 80046DF8 0200202D */   daddu    $a0, $s0, $zero
.L80046DFC:
/* 221FC 80046DFC 8222FFBE */  lb        $v0, -0x42($s1)
/* 22200 80046E00 24180002 */  addiu     $t8, $zero, 2
/* 22204 80046E04 14580067 */  bne       $v0, $t8, .L80046FA4
/* 22208 80046E08 0000982D */   daddu    $s3, $zero, $zero
/* 2220C 80046E0C 8E830000 */  lw        $v1, ($s4)
/* 22210 80046E10 30620020 */  andi      $v0, $v1, 0x20
/* 22214 80046E14 10400024 */  beqz      $v0, .L80046EA8
/* 22218 80046E18 30620002 */   andi     $v0, $v1, 2
/* 2221C 80046E1C 8E24FFC4 */  lw        $a0, -0x3c($s1)
/* 22220 80046E20 0C051280 */  jal       set_hud_element_flags
/* 22224 80046E24 0300282D */   daddu    $a1, $t8, $zero
/* 22228 80046E28 08011BE9 */  j         .L80046FA4
/* 2222C 80046E2C 00000000 */   nop
.L80046E30:
/* 22230 80046E30 8E24FFD0 */  lw        $a0, -0x30($s1)
/* 22234 80046E34 0C051280 */  jal       set_hud_element_flags
/* 22238 80046E38 24050002 */   addiu    $a1, $zero, 2
/* 2223C 80046E3C 08011C56 */  j         .L80047158
/* 22240 80046E40 00000000 */   nop
.L80046E44:
/* 22244 80046E44 8E24FFDC */  lw        $a0, -0x24($s1)
/* 22248 80046E48 0C051280 */  jal       set_hud_element_flags
/* 2224C 80046E4C 24050002 */   addiu    $a1, $zero, 2
/* 22250 80046E50 08011CA1 */  j         .L80047284
/* 22254 80046E54 00000000 */   nop
.L80046E58:
/* 22258 80046E58 8E24FFE8 */  lw        $a0, -0x18($s1)
/* 2225C 80046E5C 0C051280 */  jal       set_hud_element_flags
/* 22260 80046E60 24050002 */   addiu    $a1, $zero, 2
/* 22264 80046E64 08011CEC */  j         .L800473B0
/* 22268 80046E68 00000000 */   nop
.L80046E6C:
/* 2226C 80046E6C 8E24FFF0 */  lw        $a0, -0x10($s1)
/* 22270 80046E70 0C051280 */  jal       set_hud_element_flags
/* 22274 80046E74 24050002 */   addiu    $a1, $zero, 2
/* 22278 80046E78 08011D17 */  j         .L8004745C
/* 2227C 80046E7C 00000000 */   nop
.L80046E80:
/* 22280 80046E80 8E24FFF8 */  lw        $a0, -8($s1)
/* 22284 80046E84 0C051280 */  jal       set_hud_element_flags
/* 22288 80046E88 24050002 */   addiu    $a1, $zero, 2
/* 2228C 80046E8C 08011D42 */  j         .L80047508
/* 22290 80046E90 00000000 */   nop
.L80046E94:
/* 22294 80046E94 8E240000 */  lw        $a0, ($s1)
/* 22298 80046E98 0C051280 */  jal       set_hud_element_flags
/* 2229C 80046E9C 24050002 */   addiu    $a1, $zero, 2
/* 222A0 80046EA0 08011D6E */  j         .L800475B8
/* 222A4 80046EA4 263100B0 */   addiu    $s1, $s1, 0xb0
.L80046EA8:
/* 222A8 80046EA8 14400006 */  bnez      $v0, .L80046EC4
/* 222AC 80046EAC 00000000 */   nop
/* 222B0 80046EB0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 222B4 80046EB4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 222B8 80046EB8 80420070 */  lb        $v0, 0x70($v0)
/* 222BC 80046EBC 105E0039 */  beq       $v0, $fp, .L80046FA4
/* 222C0 80046EC0 00000000 */   nop
.L80046EC4:
/* 222C4 80046EC4 8E24FFC4 */  lw        $a0, -0x3c($s1)
/* 222C8 80046EC8 0C05128B */  jal       clear_hud_element_flags
/* 222CC 80046ECC 24050002 */   addiu    $a1, $zero, 2
/* 222D0 80046ED0 24180002 */  addiu     $t8, $zero, 2
/* 222D4 80046ED4 16580002 */  bne       $s2, $t8, .L80046EE0
/* 222D8 80046ED8 0000102D */   daddu    $v0, $zero, $zero
/* 222DC 80046EDC 2402FFEF */  addiu     $v0, $zero, -0x11
.L80046EE0:
/* 222E0 80046EE0 525E0001 */  beql      $s2, $fp, .L80046EE8
/* 222E4 80046EE4 2402FFDE */   addiu    $v0, $zero, -0x22
.L80046EE8:
/* 222E8 80046EE8 52400001 */  beql      $s2, $zero, .L80046EF0
/* 222EC 80046EEC 2402FFCD */   addiu    $v0, $zero, -0x33
.L80046EF0:
/* 222F0 80046EF0 8FB80034 */  lw        $t8, 0x34($sp)
/* 222F4 80046EF4 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 222F8 80046EF8 C70C006C */  lwc1      $f12, 0x6c($t8)
/* 222FC 80046EFC E7A00020 */  swc1      $f0, 0x20($sp)
/* 22300 80046F00 C624FF80 */  lwc1      $f4, -0x80($s1)
/* 22304 80046F04 46802120 */  cvt.s.w   $f4, $f4
/* 22308 80046F08 46166300 */  add.s     $f12, $f12, $f22
/* 2230C 80046F0C C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22310 80046F10 C620FF60 */  lwc1      $f0, -0xa0($s1)
/* 22314 80046F14 46041080 */  add.s     $f2, $f2, $f4
/* 22318 80046F18 E7A00024 */  swc1      $f0, 0x24($sp)
/* 2231C 80046F1C 44820000 */  mtc1      $v0, $f0
/* 22320 80046F20 00000000 */  nop
/* 22324 80046F24 46800020 */  cvt.s.w   $f0, $f0
/* 22328 80046F28 0C00A6C9 */  jal       clamp_angle
/* 2232C 80046F2C 46001500 */   add.s    $f20, $f2, $f0
/* 22330 80046F30 27A40020 */  addiu     $a0, $sp, 0x20
/* 22334 80046F34 C626FF7C */  lwc1      $f6, -0x84($s1)
/* 22338 80046F38 468031A0 */  cvt.s.w   $f6, $f6
/* 2233C 80046F3C 44070000 */  mfc1      $a3, $f0
/* 22340 80046F40 44063000 */  mfc1      $a2, $f6
/* 22344 80046F44 0C00A7E7 */  jal       add_vec2D_polar
/* 22348 80046F48 27A50024 */   addiu    $a1, $sp, 0x24
/* 2234C 80046F4C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 22350 80046F50 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 22354 80046F54 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 22358 80046F58 44050000 */  mfc1      $a1, $f0
/* 2235C 80046F5C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 22360 80046F60 4406A000 */  mfc1      $a2, $f20
/* 22364 80046F64 44070000 */  mfc1      $a3, $f0
/* 22368 80046F68 26520001 */  addiu     $s2, $s2, 1
/* 2236C 80046F6C AFB70010 */  sw        $s7, 0x10($sp)
/* 22370 80046F70 AFB60014 */  sw        $s6, 0x14($sp)
/* 22374 80046F74 0C00B94E */  jal       get_screen_coords
/* 22378 80046F78 AFB50018 */   sw       $s5, 0x18($sp)
/* 2237C 80046F7C 24130001 */  addiu     $s3, $zero, 1
/* 22380 80046F80 8E30FFC4 */  lw        $s0, -0x3c($s1)
/* 22384 80046F84 8FA50028 */  lw        $a1, 0x28($sp)
/* 22388 80046F88 8FA6002C */  lw        $a2, 0x2c($sp)
/* 2238C 80046F8C 0200202D */  daddu     $a0, $s0, $zero
/* 22390 80046F90 24A5FFF8 */  addiu     $a1, $a1, -8
/* 22394 80046F94 0C051261 */  jal       set_hud_element_render_pos
/* 22398 80046F98 24C6FFF8 */   addiu    $a2, $a2, -8
/* 2239C 80046F9C 0C0511F1 */  jal       draw_hud_element_2
/* 223A0 80046FA0 0200202D */   daddu    $a0, $s0, $zero
.L80046FA4:
/* 223A4 80046FA4 8230FFBF */  lb        $s0, -0x41($s1)
/* 223A8 80046FA8 24180002 */  addiu     $t8, $zero, 2
/* 223AC 80046FAC 1618003F */  bne       $s0, $t8, .L800470AC
/* 223B0 80046FB0 00000000 */   nop
/* 223B4 80046FB4 8E820000 */  lw        $v0, ($s4)
/* 223B8 80046FB8 00581024 */  and       $v0, $v0, $t8
/* 223BC 80046FBC 14400006 */  bnez      $v0, .L80046FD8
/* 223C0 80046FC0 00000000 */   nop
/* 223C4 80046FC4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 223C8 80046FC8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 223CC 80046FCC 80420070 */  lb        $v0, 0x70($v0)
/* 223D0 80046FD0 105E0036 */  beq       $v0, $fp, .L800470AC
/* 223D4 80046FD4 00000000 */   nop
.L80046FD8:
/* 223D8 80046FD8 8E24FFC8 */  lw        $a0, -0x38($s1)
/* 223DC 80046FDC 0C05128B */  jal       clear_hud_element_flags
/* 223E0 80046FE0 24050002 */   addiu    $a1, $zero, 2
/* 223E4 80046FE4 16500002 */  bne       $s2, $s0, .L80046FF0
/* 223E8 80046FE8 0000102D */   daddu    $v0, $zero, $zero
/* 223EC 80046FEC 2402FFEF */  addiu     $v0, $zero, -0x11
.L80046FF0:
/* 223F0 80046FF0 525E0001 */  beql      $s2, $fp, .L80046FF8
/* 223F4 80046FF4 2402FFDE */   addiu    $v0, $zero, -0x22
.L80046FF8:
/* 223F8 80046FF8 52400001 */  beql      $s2, $zero, .L80047000
/* 223FC 80046FFC 2402FFCD */   addiu    $v0, $zero, -0x33
.L80047000:
/* 22400 80047000 8FB80034 */  lw        $t8, 0x34($sp)
/* 22404 80047004 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 22408 80047008 C70C006C */  lwc1      $f12, 0x6c($t8)
/* 2240C 8004700C E7A00020 */  swc1      $f0, 0x20($sp)
/* 22410 80047010 C624FF80 */  lwc1      $f4, -0x80($s1)
/* 22414 80047014 46802120 */  cvt.s.w   $f4, $f4
/* 22418 80047018 46166300 */  add.s     $f12, $f12, $f22
/* 2241C 8004701C C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22420 80047020 C620FF60 */  lwc1      $f0, -0xa0($s1)
/* 22424 80047024 46041080 */  add.s     $f2, $f2, $f4
/* 22428 80047028 E7A00024 */  swc1      $f0, 0x24($sp)
/* 2242C 8004702C 44820000 */  mtc1      $v0, $f0
/* 22430 80047030 00000000 */  nop
/* 22434 80047034 46800020 */  cvt.s.w   $f0, $f0
/* 22438 80047038 0C00A6C9 */  jal       clamp_angle
/* 2243C 8004703C 46001500 */   add.s    $f20, $f2, $f0
/* 22440 80047040 27A40020 */  addiu     $a0, $sp, 0x20
/* 22444 80047044 C626FF7C */  lwc1      $f6, -0x84($s1)
/* 22448 80047048 468031A0 */  cvt.s.w   $f6, $f6
/* 2244C 8004704C 44070000 */  mfc1      $a3, $f0
/* 22450 80047050 44063000 */  mfc1      $a2, $f6
/* 22454 80047054 0C00A7E7 */  jal       add_vec2D_polar
/* 22458 80047058 27A50024 */   addiu    $a1, $sp, 0x24
/* 2245C 8004705C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 22460 80047060 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 22464 80047064 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 22468 80047068 44050000 */  mfc1      $a1, $f0
/* 2246C 8004706C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 22470 80047070 4406A000 */  mfc1      $a2, $f20
/* 22474 80047074 44070000 */  mfc1      $a3, $f0
/* 22478 80047078 AFB70010 */  sw        $s7, 0x10($sp)
/* 2247C 8004707C AFB60014 */  sw        $s6, 0x14($sp)
/* 22480 80047080 0C00B94E */  jal       get_screen_coords
/* 22484 80047084 AFB50018 */   sw       $s5, 0x18($sp)
/* 22488 80047088 8E30FFC8 */  lw        $s0, -0x38($s1)
/* 2248C 8004708C 8FA50028 */  lw        $a1, 0x28($sp)
/* 22490 80047090 8FA6002C */  lw        $a2, 0x2c($sp)
/* 22494 80047094 0200202D */  daddu     $a0, $s0, $zero
/* 22498 80047098 24A5FFF8 */  addiu     $a1, $a1, -8
/* 2249C 8004709C 0C051261 */  jal       set_hud_element_render_pos
/* 224A0 800470A0 24C6FFF8 */   addiu    $a2, $a2, -8
/* 224A4 800470A4 0C0511F1 */  jal       draw_hud_element_2
/* 224A8 800470A8 0200202D */   daddu    $a0, $s0, $zero
.L800470AC:
/* 224AC 800470AC 8222FFCC */  lb        $v0, -0x34($s1)
/* 224B0 800470B0 10400029 */  beqz      $v0, .L80047158
/* 224B4 800470B4 00000000 */   nop
/* 224B8 800470B8 8E830000 */  lw        $v1, ($s4)
/* 224BC 800470BC 30620040 */  andi      $v0, $v1, 0x40
/* 224C0 800470C0 1440FF5B */  bnez      $v0, .L80046E30
/* 224C4 800470C4 30620002 */   andi     $v0, $v1, 2
/* 224C8 800470C8 14400006 */  bnez      $v0, .L800470E4
/* 224CC 800470CC 00000000 */   nop
/* 224D0 800470D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 224D4 800470D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 224D8 800470D8 80420070 */  lb        $v0, 0x70($v0)
/* 224DC 800470DC 105E001E */  beq       $v0, $fp, .L80047158
/* 224E0 800470E0 00000000 */   nop
.L800470E4:
/* 224E4 800470E4 8E24FFD0 */  lw        $a0, -0x30($s1)
/* 224E8 800470E8 0C05128B */  jal       clear_hud_element_flags
/* 224EC 800470EC 24050002 */   addiu    $a1, $zero, 2
/* 224F0 800470F0 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 224F4 800470F4 C622FF60 */  lwc1      $f2, -0xa0($s1)
/* 224F8 800470F8 44050000 */  mfc1      $a1, $f0
/* 224FC 800470FC 44071000 */  mfc1      $a3, $f2
/* 22500 80047100 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22504 80047104 C620FF84 */  lwc1      $f0, -0x7c($s1)
/* 22508 80047108 46800020 */  cvt.s.w   $f0, $f0
/* 2250C 8004710C 46001080 */  add.s     $f2, $f2, $f0
/* 22510 80047110 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 22514 80047114 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 22518 80047118 44061000 */  mfc1      $a2, $f2
/* 2251C 8004711C AFA50020 */  sw        $a1, 0x20($sp)
/* 22520 80047120 AFA70024 */  sw        $a3, 0x24($sp)
/* 22524 80047124 AFB70010 */  sw        $s7, 0x10($sp)
/* 22528 80047128 AFB60014 */  sw        $s6, 0x14($sp)
/* 2252C 8004712C 0C00B94E */  jal       get_screen_coords
/* 22530 80047130 AFB50018 */   sw       $s5, 0x18($sp)
/* 22534 80047134 8E30FFD0 */  lw        $s0, -0x30($s1)
/* 22538 80047138 8FA50028 */  lw        $a1, 0x28($sp)
/* 2253C 8004713C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 22540 80047140 0200202D */  daddu     $a0, $s0, $zero
/* 22544 80047144 24A50002 */  addiu     $a1, $a1, 2
/* 22548 80047148 0C051261 */  jal       set_hud_element_render_pos
/* 2254C 8004714C 24C6FFF4 */   addiu    $a2, $a2, -0xc
/* 22550 80047150 0C0511F1 */  jal       draw_hud_element_2
/* 22554 80047154 0200202D */   daddu    $a0, $s0, $zero
.L80047158:
/* 22558 80047158 8222FFCD */  lb        $v0, -0x33($s1)
/* 2255C 8004715C 1040001E */  beqz      $v0, .L800471D8
/* 22560 80047160 00000000 */   nop
/* 22564 80047164 8E24FFD4 */  lw        $a0, -0x2c($s1)
/* 22568 80047168 0C05128B */  jal       clear_hud_element_flags
/* 2256C 8004716C 24050002 */   addiu    $a1, $zero, 2
/* 22570 80047170 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 22574 80047174 C622FF60 */  lwc1      $f2, -0xa0($s1)
/* 22578 80047178 44050000 */  mfc1      $a1, $f0
/* 2257C 8004717C 44071000 */  mfc1      $a3, $f2
/* 22580 80047180 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22584 80047184 C620FF84 */  lwc1      $f0, -0x7c($s1)
/* 22588 80047188 46800020 */  cvt.s.w   $f0, $f0
/* 2258C 8004718C 46001080 */  add.s     $f2, $f2, $f0
/* 22590 80047190 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 22594 80047194 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 22598 80047198 44061000 */  mfc1      $a2, $f2
/* 2259C 8004719C AFA50020 */  sw        $a1, 0x20($sp)
/* 225A0 800471A0 AFA70024 */  sw        $a3, 0x24($sp)
/* 225A4 800471A4 AFB70010 */  sw        $s7, 0x10($sp)
/* 225A8 800471A8 AFB60014 */  sw        $s6, 0x14($sp)
/* 225AC 800471AC 0C00B94E */  jal       get_screen_coords
/* 225B0 800471B0 AFB50018 */   sw       $s5, 0x18($sp)
/* 225B4 800471B4 8E30FFD4 */  lw        $s0, -0x2c($s1)
/* 225B8 800471B8 8FA50028 */  lw        $a1, 0x28($sp)
/* 225BC 800471BC 8FA6002C */  lw        $a2, 0x2c($sp)
/* 225C0 800471C0 0200202D */  daddu     $a0, $s0, $zero
/* 225C4 800471C4 24A50002 */  addiu     $a1, $a1, 2
/* 225C8 800471C8 0C051261 */  jal       set_hud_element_render_pos
/* 225CC 800471CC 24C6FFF4 */   addiu    $a2, $a2, -0xc
/* 225D0 800471D0 0C0511F1 */  jal       draw_hud_element_2
/* 225D4 800471D4 0200202D */   daddu    $a0, $s0, $zero
.L800471D8:
/* 225D8 800471D8 8222FFD8 */  lb        $v0, -0x28($s1)
/* 225DC 800471DC 10400029 */  beqz      $v0, .L80047284
/* 225E0 800471E0 00000000 */   nop
/* 225E4 800471E4 8E830000 */  lw        $v1, ($s4)
/* 225E8 800471E8 30620080 */  andi      $v0, $v1, 0x80
/* 225EC 800471EC 1440FF15 */  bnez      $v0, .L80046E44
/* 225F0 800471F0 30620002 */   andi     $v0, $v1, 2
/* 225F4 800471F4 14400006 */  bnez      $v0, .L80047210
/* 225F8 800471F8 00000000 */   nop
/* 225FC 800471FC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 22600 80047200 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 22604 80047204 80420070 */  lb        $v0, 0x70($v0)
/* 22608 80047208 105E001E */  beq       $v0, $fp, .L80047284
/* 2260C 8004720C 00000000 */   nop
.L80047210:
/* 22610 80047210 8E24FFDC */  lw        $a0, -0x24($s1)
/* 22614 80047214 0C05128B */  jal       clear_hud_element_flags
/* 22618 80047218 24050002 */   addiu    $a1, $zero, 2
/* 2261C 8004721C C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 22620 80047220 C622FF60 */  lwc1      $f2, -0xa0($s1)
/* 22624 80047224 44050000 */  mfc1      $a1, $f0
/* 22628 80047228 44071000 */  mfc1      $a3, $f2
/* 2262C 8004722C C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22630 80047230 C620FF84 */  lwc1      $f0, -0x7c($s1)
/* 22634 80047234 46800020 */  cvt.s.w   $f0, $f0
/* 22638 80047238 46001080 */  add.s     $f2, $f2, $f0
/* 2263C 8004723C 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 22640 80047240 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 22644 80047244 44061000 */  mfc1      $a2, $f2
/* 22648 80047248 AFA50020 */  sw        $a1, 0x20($sp)
/* 2264C 8004724C AFA70024 */  sw        $a3, 0x24($sp)
/* 22650 80047250 AFB70010 */  sw        $s7, 0x10($sp)
/* 22654 80047254 AFB60014 */  sw        $s6, 0x14($sp)
/* 22658 80047258 0C00B94E */  jal       get_screen_coords
/* 2265C 8004725C AFB50018 */   sw       $s5, 0x18($sp)
/* 22660 80047260 8E30FFDC */  lw        $s0, -0x24($s1)
/* 22664 80047264 8FA50028 */  lw        $a1, 0x28($sp)
/* 22668 80047268 8FA6002C */  lw        $a2, 0x2c($sp)
/* 2266C 8004726C 0200202D */  daddu     $a0, $s0, $zero
/* 22670 80047270 24A50002 */  addiu     $a1, $a1, 2
/* 22674 80047274 0C051261 */  jal       set_hud_element_render_pos
/* 22678 80047278 24C6FFF4 */   addiu    $a2, $a2, -0xc
/* 2267C 8004727C 0C0511F1 */  jal       draw_hud_element_2
/* 22680 80047280 0200202D */   daddu    $a0, $s0, $zero
.L80047284:
/* 22684 80047284 8222FFD9 */  lb        $v0, -0x27($s1)
/* 22688 80047288 1040001E */  beqz      $v0, .L80047304
/* 2268C 8004728C 00000000 */   nop
/* 22690 80047290 8E24FFE0 */  lw        $a0, -0x20($s1)
/* 22694 80047294 0C05128B */  jal       clear_hud_element_flags
/* 22698 80047298 24050002 */   addiu    $a1, $zero, 2
/* 2269C 8004729C C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 226A0 800472A0 C622FF60 */  lwc1      $f2, -0xa0($s1)
/* 226A4 800472A4 44050000 */  mfc1      $a1, $f0
/* 226A8 800472A8 44071000 */  mfc1      $a3, $f2
/* 226AC 800472AC C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 226B0 800472B0 C620FF84 */  lwc1      $f0, -0x7c($s1)
/* 226B4 800472B4 46800020 */  cvt.s.w   $f0, $f0
/* 226B8 800472B8 46001080 */  add.s     $f2, $f2, $f0
/* 226BC 800472BC 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 226C0 800472C0 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 226C4 800472C4 44061000 */  mfc1      $a2, $f2
/* 226C8 800472C8 AFA50020 */  sw        $a1, 0x20($sp)
/* 226CC 800472CC AFA70024 */  sw        $a3, 0x24($sp)
/* 226D0 800472D0 AFB70010 */  sw        $s7, 0x10($sp)
/* 226D4 800472D4 AFB60014 */  sw        $s6, 0x14($sp)
/* 226D8 800472D8 0C00B94E */  jal       get_screen_coords
/* 226DC 800472DC AFB50018 */   sw       $s5, 0x18($sp)
/* 226E0 800472E0 8E30FFE0 */  lw        $s0, -0x20($s1)
/* 226E4 800472E4 8FA50028 */  lw        $a1, 0x28($sp)
/* 226E8 800472E8 8FA6002C */  lw        $a2, 0x2c($sp)
/* 226EC 800472EC 0200202D */  daddu     $a0, $s0, $zero
/* 226F0 800472F0 24A50002 */  addiu     $a1, $a1, 2
/* 226F4 800472F4 0C051261 */  jal       set_hud_element_render_pos
/* 226F8 800472F8 24C6FFF4 */   addiu    $a2, $a2, -0xc
/* 226FC 800472FC 0C0511F1 */  jal       draw_hud_element_2
/* 22700 80047300 0200202D */   daddu    $a0, $s0, $zero
.L80047304:
/* 22704 80047304 8222FFE4 */  lb        $v0, -0x1c($s1)
/* 22708 80047308 10400029 */  beqz      $v0, .L800473B0
/* 2270C 8004730C 00000000 */   nop
/* 22710 80047310 8E830000 */  lw        $v1, ($s4)
/* 22714 80047314 30620100 */  andi      $v0, $v1, 0x100
/* 22718 80047318 1440FECF */  bnez      $v0, .L80046E58
/* 2271C 8004731C 30620002 */   andi     $v0, $v1, 2
/* 22720 80047320 14400006 */  bnez      $v0, .L8004733C
/* 22724 80047324 00000000 */   nop
/* 22728 80047328 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 2272C 8004732C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 22730 80047330 80420070 */  lb        $v0, 0x70($v0)
/* 22734 80047334 105E001E */  beq       $v0, $fp, .L800473B0
/* 22738 80047338 00000000 */   nop
.L8004733C:
/* 2273C 8004733C 8E24FFE8 */  lw        $a0, -0x18($s1)
/* 22740 80047340 0C05128B */  jal       clear_hud_element_flags
/* 22744 80047344 24050002 */   addiu    $a1, $zero, 2
/* 22748 80047348 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 2274C 8004734C C622FF60 */  lwc1      $f2, -0xa0($s1)
/* 22750 80047350 44050000 */  mfc1      $a1, $f0
/* 22754 80047354 44071000 */  mfc1      $a3, $f2
/* 22758 80047358 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 2275C 8004735C C620FF84 */  lwc1      $f0, -0x7c($s1)
/* 22760 80047360 46800020 */  cvt.s.w   $f0, $f0
/* 22764 80047364 46001080 */  add.s     $f2, $f2, $f0
/* 22768 80047368 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 2276C 8004736C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 22770 80047370 44061000 */  mfc1      $a2, $f2
/* 22774 80047374 AFA50020 */  sw        $a1, 0x20($sp)
/* 22778 80047378 AFA70024 */  sw        $a3, 0x24($sp)
/* 2277C 8004737C AFB70010 */  sw        $s7, 0x10($sp)
/* 22780 80047380 AFB60014 */  sw        $s6, 0x14($sp)
/* 22784 80047384 0C00B94E */  jal       get_screen_coords
/* 22788 80047388 AFB50018 */   sw       $s5, 0x18($sp)
/* 2278C 8004738C 8E30FFE8 */  lw        $s0, -0x18($s1)
/* 22790 80047390 8FA50028 */  lw        $a1, 0x28($sp)
/* 22794 80047394 8FA6002C */  lw        $a2, 0x2c($sp)
/* 22798 80047398 0200202D */  daddu     $a0, $s0, $zero
/* 2279C 8004739C 24A50002 */  addiu     $a1, $a1, 2
/* 227A0 800473A0 0C051261 */  jal       set_hud_element_render_pos
/* 227A4 800473A4 24C6FFF4 */   addiu    $a2, $a2, -0xc
/* 227A8 800473A8 0C0511F1 */  jal       draw_hud_element_2
/* 227AC 800473AC 0200202D */   daddu    $a0, $s0, $zero
.L800473B0:
/* 227B0 800473B0 8222FFEC */  lb        $v0, -0x14($s1)
/* 227B4 800473B4 10400029 */  beqz      $v0, .L8004745C
/* 227B8 800473B8 00000000 */   nop
/* 227BC 800473BC 8E830000 */  lw        $v1, ($s4)
/* 227C0 800473C0 30620200 */  andi      $v0, $v1, 0x200
/* 227C4 800473C4 1440FEA9 */  bnez      $v0, .L80046E6C
/* 227C8 800473C8 30620002 */   andi     $v0, $v1, 2
/* 227CC 800473CC 14400006 */  bnez      $v0, .L800473E8
/* 227D0 800473D0 00000000 */   nop
/* 227D4 800473D4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 227D8 800473D8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 227DC 800473DC 80420070 */  lb        $v0, 0x70($v0)
/* 227E0 800473E0 105E001E */  beq       $v0, $fp, .L8004745C
/* 227E4 800473E4 00000000 */   nop
.L800473E8:
/* 227E8 800473E8 8E24FFF0 */  lw        $a0, -0x10($s1)
/* 227EC 800473EC 0C05128B */  jal       clear_hud_element_flags
/* 227F0 800473F0 24050002 */   addiu    $a1, $zero, 2
/* 227F4 800473F4 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 227F8 800473F8 C622FF60 */  lwc1      $f2, -0xa0($s1)
/* 227FC 800473FC 44050000 */  mfc1      $a1, $f0
/* 22800 80047400 44071000 */  mfc1      $a3, $f2
/* 22804 80047404 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22808 80047408 C620FF84 */  lwc1      $f0, -0x7c($s1)
/* 2280C 8004740C 46800020 */  cvt.s.w   $f0, $f0
/* 22810 80047410 46001080 */  add.s     $f2, $f2, $f0
/* 22814 80047414 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 22818 80047418 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 2281C 8004741C 44061000 */  mfc1      $a2, $f2
/* 22820 80047420 AFA50020 */  sw        $a1, 0x20($sp)
/* 22824 80047424 AFA70024 */  sw        $a3, 0x24($sp)
/* 22828 80047428 AFB70010 */  sw        $s7, 0x10($sp)
/* 2282C 8004742C AFB60014 */  sw        $s6, 0x14($sp)
/* 22830 80047430 0C00B94E */  jal       get_screen_coords
/* 22834 80047434 AFB50018 */   sw       $s5, 0x18($sp)
/* 22838 80047438 8E30FFF0 */  lw        $s0, -0x10($s1)
/* 2283C 8004743C 8FA50028 */  lw        $a1, 0x28($sp)
/* 22840 80047440 8FA6002C */  lw        $a2, 0x2c($sp)
/* 22844 80047444 0200202D */  daddu     $a0, $s0, $zero
/* 22848 80047448 24A50002 */  addiu     $a1, $a1, 2
/* 2284C 8004744C 0C051261 */  jal       set_hud_element_render_pos
/* 22850 80047450 24C6FFF1 */   addiu    $a2, $a2, -0xf
/* 22854 80047454 0C0511F1 */  jal       draw_hud_element_2
/* 22858 80047458 0200202D */   daddu    $a0, $s0, $zero
.L8004745C:
/* 2285C 8004745C 8222FFF4 */  lb        $v0, -0xc($s1)
/* 22860 80047460 10400029 */  beqz      $v0, .L80047508
/* 22864 80047464 00000000 */   nop
/* 22868 80047468 8E830000 */  lw        $v1, ($s4)
/* 2286C 8004746C 30620400 */  andi      $v0, $v1, 0x400
/* 22870 80047470 1440FE83 */  bnez      $v0, .L80046E80
/* 22874 80047474 30620002 */   andi     $v0, $v1, 2
/* 22878 80047478 14400006 */  bnez      $v0, .L80047494
/* 2287C 8004747C 00000000 */   nop
/* 22880 80047480 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 22884 80047484 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 22888 80047488 80420070 */  lb        $v0, 0x70($v0)
/* 2288C 8004748C 105E001E */  beq       $v0, $fp, .L80047508
/* 22890 80047490 00000000 */   nop
.L80047494:
/* 22894 80047494 8E24FFF8 */  lw        $a0, -8($s1)
/* 22898 80047498 0C05128B */  jal       clear_hud_element_flags
/* 2289C 8004749C 24050002 */   addiu    $a1, $zero, 2
/* 228A0 800474A0 C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 228A4 800474A4 C622FF60 */  lwc1      $f2, -0xa0($s1)
/* 228A8 800474A8 44050000 */  mfc1      $a1, $f0
/* 228AC 800474AC 44071000 */  mfc1      $a3, $f2
/* 228B0 800474B0 C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 228B4 800474B4 C620FF84 */  lwc1      $f0, -0x7c($s1)
/* 228B8 800474B8 46800020 */  cvt.s.w   $f0, $f0
/* 228BC 800474BC 46001080 */  add.s     $f2, $f2, $f0
/* 228C0 800474C0 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 228C4 800474C4 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 228C8 800474C8 44061000 */  mfc1      $a2, $f2
/* 228CC 800474CC AFA50020 */  sw        $a1, 0x20($sp)
/* 228D0 800474D0 AFA70024 */  sw        $a3, 0x24($sp)
/* 228D4 800474D4 AFB70010 */  sw        $s7, 0x10($sp)
/* 228D8 800474D8 AFB60014 */  sw        $s6, 0x14($sp)
/* 228DC 800474DC 0C00B94E */  jal       get_screen_coords
/* 228E0 800474E0 AFB50018 */   sw       $s5, 0x18($sp)
/* 228E4 800474E4 8E30FFF8 */  lw        $s0, -8($s1)
/* 228E8 800474E8 8FA50028 */  lw        $a1, 0x28($sp)
/* 228EC 800474EC 8FA6002C */  lw        $a2, 0x2c($sp)
/* 228F0 800474F0 0200202D */  daddu     $a0, $s0, $zero
/* 228F4 800474F4 24A50002 */  addiu     $a1, $a1, 2
/* 228F8 800474F8 0C051261 */  jal       set_hud_element_render_pos
/* 228FC 800474FC 24C6FFF0 */   addiu    $a2, $a2, -0x10
/* 22900 80047500 0C0511F1 */  jal       draw_hud_element_2
/* 22904 80047504 0200202D */   daddu    $a0, $s0, $zero
.L80047508:
/* 22908 80047508 8222FFFC */  lb        $v0, -4($s1)
/* 2290C 8004750C 5040002A */  beql      $v0, $zero, .L800475B8
/* 22910 80047510 263100B0 */   addiu    $s1, $s1, 0xb0
/* 22914 80047514 8E830000 */  lw        $v1, ($s4)
/* 22918 80047518 30620800 */  andi      $v0, $v1, 0x800
/* 2291C 8004751C 1440FE5D */  bnez      $v0, .L80046E94
/* 22920 80047520 30620002 */   andi     $v0, $v1, 2
/* 22924 80047524 14400006 */  bnez      $v0, .L80047540
/* 22928 80047528 00000000 */   nop
/* 2292C 8004752C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 22930 80047530 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 22934 80047534 80420070 */  lb        $v0, 0x70($v0)
/* 22938 80047538 505E001F */  beql      $v0, $fp, .L800475B8
/* 2293C 8004753C 263100B0 */   addiu    $s1, $s1, 0xb0
.L80047540:
/* 22940 80047540 8E240000 */  lw        $a0, ($s1)
/* 22944 80047544 0C05128B */  jal       clear_hud_element_flags
/* 22948 80047548 24050002 */   addiu    $a1, $zero, 2
/* 2294C 8004754C C620FF58 */  lwc1      $f0, -0xa8($s1)
/* 22950 80047550 C622FF60 */  lwc1      $f2, -0xa0($s1)
/* 22954 80047554 44050000 */  mfc1      $a1, $f0
/* 22958 80047558 44071000 */  mfc1      $a3, $f2
/* 2295C 8004755C C622FF5C */  lwc1      $f2, -0xa4($s1)
/* 22960 80047560 C620FF84 */  lwc1      $f0, -0x7c($s1)
/* 22964 80047564 46800020 */  cvt.s.w   $f0, $f0
/* 22968 80047568 46001080 */  add.s     $f2, $f2, $f0
/* 2296C 8004756C 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 22970 80047570 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 22974 80047574 44061000 */  mfc1      $a2, $f2
/* 22978 80047578 AFA50020 */  sw        $a1, 0x20($sp)
/* 2297C 8004757C AFA70024 */  sw        $a3, 0x24($sp)
/* 22980 80047580 AFB70010 */  sw        $s7, 0x10($sp)
/* 22984 80047584 AFB60014 */  sw        $s6, 0x14($sp)
/* 22988 80047588 0C00B94E */  jal       get_screen_coords
/* 2298C 8004758C AFB50018 */   sw       $s5, 0x18($sp)
/* 22990 80047590 8E300000 */  lw        $s0, ($s1)
/* 22994 80047594 8FA50028 */  lw        $a1, 0x28($sp)
/* 22998 80047598 8FA6002C */  lw        $a2, 0x2c($sp)
/* 2299C 8004759C 0200202D */  daddu     $a0, $s0, $zero
/* 229A0 800475A0 24A50002 */  addiu     $a1, $a1, 2
/* 229A4 800475A4 0C051261 */  jal       set_hud_element_render_pos
/* 229A8 800475A8 24C6FFF0 */   addiu    $a2, $a2, -0x10
/* 229AC 800475AC 0C0511F1 */  jal       draw_hud_element_2
/* 229B0 800475B0 0200202D */   daddu    $a0, $s0, $zero
/* 229B4 800475B4 263100B0 */  addiu     $s1, $s1, 0xb0
.L800475B8:
/* 229B8 800475B8 8FB80038 */  lw        $t8, 0x38($sp)
/* 229BC 800475BC 269400B0 */  addiu     $s4, $s4, 0xb0
/* 229C0 800475C0 27180001 */  addiu     $t8, $t8, 1
/* 229C4 800475C4 2B020040 */  slti      $v0, $t8, 0x40
/* 229C8 800475C8 1440FC7E */  bnez      $v0, .L800467C4
/* 229CC 800475CC AFB80038 */   sw       $t8, 0x38($sp)
/* 229D0 800475D0 8FBF0064 */  lw        $ra, 0x64($sp)
/* 229D4 800475D4 8FBE0060 */  lw        $fp, 0x60($sp)
/* 229D8 800475D8 8FB7005C */  lw        $s7, 0x5c($sp)
/* 229DC 800475DC 8FB60058 */  lw        $s6, 0x58($sp)
/* 229E0 800475E0 8FB50054 */  lw        $s5, 0x54($sp)
/* 229E4 800475E4 8FB40050 */  lw        $s4, 0x50($sp)
/* 229E8 800475E8 8FB3004C */  lw        $s3, 0x4c($sp)
/* 229EC 800475EC 8FB20048 */  lw        $s2, 0x48($sp)
/* 229F0 800475F0 8FB10044 */  lw        $s1, 0x44($sp)
/* 229F4 800475F4 8FB00040 */  lw        $s0, 0x40($sp)
/* 229F8 800475F8 D7B60070 */  ldc1      $f22, 0x70($sp)
/* 229FC 800475FC D7B40068 */  ldc1      $f20, 0x68($sp)
/* 22A00 80047600 03E00008 */  jr        $ra
/* 22A04 80047604 27BD0078 */   addiu    $sp, $sp, 0x78
