.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_800983E0
.word L80037718_12B18, L8003768C_12A8C, L800376BC_12ABC, L80037718_12B18, L800376C8_12AC8, L800376D4_12AD4

.section .text

glabel appendGfx_title_screen
/* 12A38 80037638 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 12A3C 8003763C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 12A40 80037640 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 12A44 80037644 AFBF0030 */  sw        $ra, 0x30($sp)
/* 12A48 80037648 AFB7002C */  sw        $s7, 0x2c($sp)
/* 12A4C 8003764C AFB60028 */  sw        $s6, 0x28($sp)
/* 12A50 80037650 AFB50024 */  sw        $s5, 0x24($sp)
/* 12A54 80037654 AFB40020 */  sw        $s4, 0x20($sp)
/* 12A58 80037658 AFB3001C */  sw        $s3, 0x1c($sp)
/* 12A5C 8003765C AFB20018 */  sw        $s2, 0x18($sp)
/* 12A60 80037660 AFB10014 */  sw        $s1, 0x14($sp)
/* 12A64 80037664 AFB00010 */  sw        $s0, 0x10($sp)
/* 12A68 80037668 804300AC */  lb        $v1, 0xac($v0)
/* 12A6C 8003766C 2C620006 */  sltiu     $v0, $v1, 6
/* 12A70 80037670 10400029 */  beqz      $v0, L80037718_12B18
/* 12A74 80037674 00031080 */   sll      $v0, $v1, 2
/* 12A78 80037678 3C01800A */  lui       $at, %hi(jtbl_800983E0)
/* 12A7C 8003767C 00220821 */  addu      $at, $at, $v0
/* 12A80 80037680 8C2283E0 */  lw        $v0, %lo(jtbl_800983E0)($at)
/* 12A84 80037684 00400008 */  jr        $v0
/* 12A88 80037688 00000000 */   nop
dlabel L8003768C_12A8C
/* 12A8C 8003768C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 12A90 80037690 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 12A94 80037694 804300AF */  lb        $v1, 0xaf($v0)
/* 12A98 80037698 804200B0 */  lb        $v0, 0xb0($v0)
/* 12A9C 8003769C 44836000 */  mtc1      $v1, $f12
/* 12AA0 800376A0 00000000 */  nop
/* 12AA4 800376A4 46806320 */  cvt.s.w   $f12, $f12
/* 12AA8 800376A8 44820000 */  mtc1      $v0, $f0
/* 12AAC 800376AC 00000000 */  nop
/* 12AB0 800376B0 46800020 */  cvt.s.w   $f0, $f0
/* 12AB4 800376B4 0800DDC2 */  j         .L80037708
/* 12AB8 800376B8 46006303 */   div.s    $f12, $f12, $f0
dlabel L800376BC_12ABC
/* 12ABC 800376BC 44806000 */  mtc1      $zero, $f12
/* 12AC0 800376C0 0800DDC4 */  j         .L80037710
/* 12AC4 800376C4 00000000 */   nop
dlabel L800376C8_12AC8
/* 12AC8 800376C8 44806000 */  mtc1      $zero, $f12
/* 12ACC 800376CC 0800DDC4 */  j         .L80037710
/* 12AD0 800376D0 00000000 */   nop
dlabel L800376D4_12AD4
/* 12AD4 800376D4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 12AD8 800376D8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 12ADC 800376DC 806200AF */  lb        $v0, 0xaf($v1)
/* 12AE0 800376E0 806300B0 */  lb        $v1, 0xb0($v1)
/* 12AE4 800376E4 2442FFFF */  addiu     $v0, $v0, -1
/* 12AE8 800376E8 00621023 */  subu      $v0, $v1, $v0
/* 12AEC 800376EC 44826000 */  mtc1      $v0, $f12
/* 12AF0 800376F0 00000000 */  nop
/* 12AF4 800376F4 46806320 */  cvt.s.w   $f12, $f12
/* 12AF8 800376F8 44830000 */  mtc1      $v1, $f0
/* 12AFC 800376FC 00000000 */  nop
/* 12B00 80037700 46800020 */  cvt.s.w   $f0, $f0
/* 12B04 80037704 46006303 */  div.s     $f12, $f12, $f0
.L80037708:
/* 12B08 80037708 460C6302 */  mul.s     $f12, $f12, $f12
/* 12B0C 8003770C 00000000 */  nop
.L80037710:
/* 12B10 80037710 0C00DE5A */  jal       title_screen_draw_images
/* 12B14 80037714 46006386 */   mov.s    $f14, $f12
dlabel L80037718_12B18
/* 12B18 80037718 3C03FF10 */  lui       $v1, 0xff10
/* 12B1C 8003771C 3463013F */  ori       $v1, $v1, 0x13f
/* 12B20 80037720 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 12B24 80037724 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 12B28 80037728 3C12E700 */  lui       $s2, 0xe700
/* 12B2C 8003772C 8E110000 */  lw        $s1, ($s0)
/* 12B30 80037730 3C04800A */  lui       $a0, %hi(nuGfxCfb_ptr)
/* 12B34 80037734 8C84A64C */  lw        $a0, %lo(nuGfxCfb_ptr)($a0)
/* 12B38 80037738 0220102D */  daddu     $v0, $s1, $zero
/* 12B3C 8003773C 26310008 */  addiu     $s1, $s1, 8
/* 12B40 80037740 AE110000 */  sw        $s1, ($s0)
/* 12B44 80037744 AC520000 */  sw        $s2, ($v0)
/* 12B48 80037748 AC400004 */  sw        $zero, 4($v0)
/* 12B4C 8003774C 26220008 */  addiu     $v0, $s1, 8
/* 12B50 80037750 AE020000 */  sw        $v0, ($s0)
/* 12B54 80037754 0C0187A4 */  jal       osVirtualToPhysical
/* 12B58 80037758 AE230000 */   sw       $v1, ($s1)
/* 12B5C 8003775C 3C060050 */  lui       $a2, 0x50
/* 12B60 80037760 34C603C0 */  ori       $a2, $a2, 0x3c0
/* 12B64 80037764 3C07E300 */  lui       $a3, 0xe300
/* 12B68 80037768 34E70A01 */  ori       $a3, $a3, 0xa01
/* 12B6C 8003776C 3C08D9C0 */  lui       $t0, 0xd9c0
/* 12B70 80037770 3508F9FA */  ori       $t0, $t0, 0xf9fa
/* 12B74 80037774 3C0AD9FF */  lui       $t2, 0xd9ff
/* 12B78 80037778 354AFFFF */  ori       $t2, $t2, 0xffff
/* 12B7C 8003777C 3C090022 */  lui       $t1, 0x22
/* 12B80 80037780 35290005 */  ori       $t1, $t1, 5
/* 12B84 80037784 3C0BDC08 */  lui       $t3, 0xdc08
/* 12B88 80037788 356B060A */  ori       $t3, $t3, 0x60a
/* 12B8C 8003778C 3C0CDC08 */  lui       $t4, 0xdc08
/* 12B90 80037790 358C090A */  ori       $t4, $t4, 0x90a
/* 12B94 80037794 3C0DD700 */  lui       $t5, 0xd700
/* 12B98 80037798 35AD0002 */  ori       $t5, $t5, 2
/* 12B9C 8003779C 3C0EE300 */  lui       $t6, 0xe300
/* 12BA0 800377A0 35CE0F00 */  ori       $t6, $t6, 0xf00
/* 12BA4 800377A4 3C0FE300 */  lui       $t7, 0xe300
/* 12BA8 800377A8 35EF0C00 */  ori       $t7, $t7, 0xc00
/* 12BAC 800377AC 3C13E300 */  lui       $s3, 0xe300
/* 12BB0 800377B0 36731201 */  ori       $s3, $s3, 0x1201
/* 12BB4 800377B4 3C14E300 */  lui       $s4, 0xe300
/* 12BB8 800377B8 36941801 */  ori       $s4, $s4, 0x1801
/* 12BBC 800377BC 3C15E300 */  lui       $s5, 0xe300
/* 12BC0 800377C0 36B50D01 */  ori       $s5, $s5, 0xd01
/* 12BC4 800377C4 3C16E300 */  lui       $s6, 0xe300
/* 12BC8 800377C8 36D61402 */  ori       $s6, $s6, 0x1402
/* 12BCC 800377CC 3C17E300 */  lui       $s7, 0xe300
/* 12BD0 800377D0 36F71700 */  ori       $s7, $s7, 0x1700
/* 12BD4 800377D4 3C18E200 */  lui       $t8, 0xe200
/* 12BD8 800377D8 37181E01 */  ori       $t8, $t8, 0x1e01
/* 12BDC 800377DC 8E030000 */  lw        $v1, ($s0)
/* 12BE0 800377E0 0000202D */  daddu     $a0, $zero, $zero
/* 12BE4 800377E4 AE220004 */  sw        $v0, 4($s1)
/* 12BE8 800377E8 3C02ED00 */  lui       $v0, 0xed00
/* 12BEC 800377EC 0060282D */  daddu     $a1, $v1, $zero
/* 12BF0 800377F0 24630008 */  addiu     $v1, $v1, 8
/* 12BF4 800377F4 AE030000 */  sw        $v1, ($s0)
/* 12BF8 800377F8 ACA20000 */  sw        $v0, ($a1)
/* 12BFC 800377FC 24620008 */  addiu     $v0, $v1, 8
/* 12C00 80037800 ACA60004 */  sw        $a2, 4($a1)
/* 12C04 80037804 AE020000 */  sw        $v0, ($s0)
/* 12C08 80037808 24620010 */  addiu     $v0, $v1, 0x10
/* 12C0C 8003780C AC670000 */  sw        $a3, ($v1)
/* 12C10 80037810 AC600004 */  sw        $zero, 4($v1)
/* 12C14 80037814 AE020000 */  sw        $v0, ($s0)
/* 12C18 80037818 24620018 */  addiu     $v0, $v1, 0x18
/* 12C1C 8003781C AC720008 */  sw        $s2, 8($v1)
/* 12C20 80037820 AC60000C */  sw        $zero, 0xc($v1)
/* 12C24 80037824 AE020000 */  sw        $v0, ($s0)
/* 12C28 80037828 24620020 */  addiu     $v0, $v1, 0x20
/* 12C2C 8003782C AC680010 */  sw        $t0, 0x10($v1)
/* 12C30 80037830 AC600014 */  sw        $zero, 0x14($v1)
/* 12C34 80037834 AE020000 */  sw        $v0, ($s0)
/* 12C38 80037838 24620028 */  addiu     $v0, $v1, 0x28
/* 12C3C 8003783C AC6A0018 */  sw        $t2, 0x18($v1)
/* 12C40 80037840 AC69001C */  sw        $t1, 0x1c($v1)
/* 12C44 80037844 AE020000 */  sw        $v0, ($s0)
/* 12C48 80037848 3C02DB02 */  lui       $v0, 0xdb02
/* 12C4C 8003784C AC620020 */  sw        $v0, 0x20($v1)
/* 12C50 80037850 24020018 */  addiu     $v0, $zero, 0x18
/* 12C54 80037854 AC620024 */  sw        $v0, 0x24($v1)
/* 12C58 80037858 24620030 */  addiu     $v0, $v1, 0x30
/* 12C5C 8003785C 3C058007 */  lui       $a1, %hi(D_80077A40)
/* 12C60 80037860 24A57A40 */  addiu     $a1, $a1, %lo(D_80077A40)
/* 12C64 80037864 AE020000 */  sw        $v0, ($s0)
/* 12C68 80037868 24620038 */  addiu     $v0, $v1, 0x38
/* 12C6C 8003786C AC65002C */  sw        $a1, 0x2c($v1)
/* 12C70 80037870 24A5FFF8 */  addiu     $a1, $a1, -8
/* 12C74 80037874 AC6B0028 */  sw        $t3, 0x28($v1)
/* 12C78 80037878 AE020000 */  sw        $v0, ($s0)
/* 12C7C 8003787C 24620040 */  addiu     $v0, $v1, 0x40
/* 12C80 80037880 AC6C0030 */  sw        $t4, 0x30($v1)
/* 12C84 80037884 AC650034 */  sw        $a1, 0x34($v1)
/* 12C88 80037888 AE020000 */  sw        $v0, ($s0)
/* 12C8C 8003788C 2402FFFF */  addiu     $v0, $zero, -1
/* 12C90 80037890 AC62003C */  sw        $v0, 0x3c($v1)
/* 12C94 80037894 24620048 */  addiu     $v0, $v1, 0x48
/* 12C98 80037898 AC6D0038 */  sw        $t5, 0x38($v1)
/* 12C9C 8003789C AE020000 */  sw        $v0, ($s0)
/* 12CA0 800378A0 24620050 */  addiu     $v0, $v1, 0x50
/* 12CA4 800378A4 AC6E0040 */  sw        $t6, 0x40($v1)
/* 12CA8 800378A8 AC600044 */  sw        $zero, 0x44($v1)
/* 12CAC 800378AC AE020000 */  sw        $v0, ($s0)
/* 12CB0 800378B0 3C020008 */  lui       $v0, 8
/* 12CB4 800378B4 AC6F0048 */  sw        $t7, 0x48($v1)
/* 12CB8 800378B8 AC62004C */  sw        $v0, 0x4c($v1)
/* 12CBC 800378BC 24620058 */  addiu     $v0, $v1, 0x58
/* 12CC0 800378C0 AE020000 */  sw        $v0, ($s0)
/* 12CC4 800378C4 24022000 */  addiu     $v0, $zero, 0x2000
/* 12CC8 800378C8 AC620054 */  sw        $v0, 0x54($v1)
/* 12CCC 800378CC 24620060 */  addiu     $v0, $v1, 0x60
/* 12CD0 800378D0 AC730050 */  sw        $s3, 0x50($v1)
/* 12CD4 800378D4 AE020000 */  sw        $v0, ($s0)
/* 12CD8 800378D8 240200C0 */  addiu     $v0, $zero, 0xc0
/* 12CDC 800378DC AC62005C */  sw        $v0, 0x5c($v1)
/* 12CE0 800378E0 24620068 */  addiu     $v0, $v1, 0x68
/* 12CE4 800378E4 AC740058 */  sw        $s4, 0x58($v1)
/* 12CE8 800378E8 AE020000 */  sw        $v0, ($s0)
/* 12CEC 800378EC 24620070 */  addiu     $v0, $v1, 0x70
/* 12CF0 800378F0 AC750060 */  sw        $s5, 0x60($v1)
/* 12CF4 800378F4 AC600064 */  sw        $zero, 0x64($v1)
/* 12CF8 800378F8 AE020000 */  sw        $v0, ($s0)
/* 12CFC 800378FC 24020C00 */  addiu     $v0, $zero, 0xc00
/* 12D00 80037900 AC62006C */  sw        $v0, 0x6c($v1)
/* 12D04 80037904 24620078 */  addiu     $v0, $v1, 0x78
/* 12D08 80037908 AC760068 */  sw        $s6, 0x68($v1)
/* 12D0C 8003790C AE020000 */  sw        $v0, ($s0)
/* 12D10 80037910 24620080 */  addiu     $v0, $v1, 0x80
/* 12D14 80037914 AC770070 */  sw        $s7, 0x70($v1)
/* 12D18 80037918 AC600074 */  sw        $zero, 0x74($v1)
/* 12D1C 8003791C AE020000 */  sw        $v0, ($s0)
/* 12D20 80037920 AC780078 */  sw        $t8, 0x78($v1)
/* 12D24 80037924 0C00B5CF */  jal       render_frame
/* 12D28 80037928 AC60007C */   sw       $zero, 0x7c($v1)
/* 12D2C 8003792C 0C00B5CF */  jal       render_frame
/* 12D30 80037930 24040001 */   addiu    $a0, $zero, 1
/* 12D34 80037934 8FBF0030 */  lw        $ra, 0x30($sp)
/* 12D38 80037938 8FB7002C */  lw        $s7, 0x2c($sp)
/* 12D3C 8003793C 8FB60028 */  lw        $s6, 0x28($sp)
/* 12D40 80037940 8FB50024 */  lw        $s5, 0x24($sp)
/* 12D44 80037944 8FB40020 */  lw        $s4, 0x20($sp)
/* 12D48 80037948 8FB3001C */  lw        $s3, 0x1c($sp)
/* 12D4C 8003794C 8FB20018 */  lw        $s2, 0x18($sp)
/* 12D50 80037950 8FB10014 */  lw        $s1, 0x14($sp)
/* 12D54 80037954 8FB00010 */  lw        $s0, 0x10($sp)
/* 12D58 80037958 03E00008 */  jr        $ra
/* 12D5C 8003795C 27BD0038 */   addiu    $sp, $sp, 0x38
