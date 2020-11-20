.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416B4_C32B94
/* C32B94 802416B4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* C32B98 802416B8 AFB40058 */  sw        $s4, 0x58($sp)
/* C32B9C 802416BC 0080A02D */  daddu     $s4, $a0, $zero
/* C32BA0 802416C0 AFBF0060 */  sw        $ra, 0x60($sp)
/* C32BA4 802416C4 AFB5005C */  sw        $s5, 0x5c($sp)
/* C32BA8 802416C8 AFB30054 */  sw        $s3, 0x54($sp)
/* C32BAC 802416CC AFB20050 */  sw        $s2, 0x50($sp)
/* C32BB0 802416D0 AFB1004C */  sw        $s1, 0x4c($sp)
/* C32BB4 802416D4 AFB00048 */  sw        $s0, 0x48($sp)
/* C32BB8 802416D8 8E910148 */  lw        $s1, 0x148($s4)
/* C32BBC 802416DC 86240008 */  lh        $a0, 8($s1)
/* C32BC0 802416E0 0C00EABB */  jal       get_npc_unsafe
/* C32BC4 802416E4 00A0802D */   daddu    $s0, $a1, $zero
/* C32BC8 802416E8 8E83000C */  lw        $v1, 0xc($s4)
/* C32BCC 802416EC 0280202D */  daddu     $a0, $s4, $zero
/* C32BD0 802416F0 8C650000 */  lw        $a1, ($v1)
/* C32BD4 802416F4 0C0B1EAF */  jal       get_variable
/* C32BD8 802416F8 0040902D */   daddu    $s2, $v0, $zero
/* C32BDC 802416FC AFA00018 */  sw        $zero, 0x18($sp)
/* C32BE0 80241700 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32BE4 80241704 8C630094 */  lw        $v1, 0x94($v1)
/* C32BE8 80241708 AFA3001C */  sw        $v1, 0x1c($sp)
/* C32BEC 8024170C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32BF0 80241710 8C630080 */  lw        $v1, 0x80($v1)
/* C32BF4 80241714 AFA30020 */  sw        $v1, 0x20($sp)
/* C32BF8 80241718 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32BFC 8024171C 8C630088 */  lw        $v1, 0x88($v1)
/* C32C00 80241720 AFA30024 */  sw        $v1, 0x24($sp)
/* C32C04 80241724 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32C08 80241728 8C63008C */  lw        $v1, 0x8c($v1)
/* C32C0C 8024172C 27B50018 */  addiu     $s5, $sp, 0x18
/* C32C10 80241730 AFA30028 */  sw        $v1, 0x28($sp)
/* C32C14 80241734 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32C18 80241738 3C014282 */  lui       $at, 0x4282
/* C32C1C 8024173C 44810000 */  mtc1      $at, $f0
/* C32C20 80241740 8C630090 */  lw        $v1, 0x90($v1)
/* C32C24 80241744 0040982D */  daddu     $s3, $v0, $zero
/* C32C28 80241748 E7A00030 */  swc1      $f0, 0x30($sp)
/* C32C2C 8024174C A7A00034 */  sh        $zero, 0x34($sp)
/* C32C30 80241750 16000005 */  bnez      $s0, .L80241768
/* C32C34 80241754 AFA3002C */   sw       $v1, 0x2c($sp)
/* C32C38 80241758 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C32C3C 8024175C 30420004 */  andi      $v0, $v0, 4
/* C32C40 80241760 10400044 */  beqz      $v0, .L80241874
/* C32C44 80241764 00000000 */   nop      
.L80241768:
/* C32C48 80241768 2404F7FF */  addiu     $a0, $zero, -0x801
/* C32C4C 8024176C AE800070 */  sw        $zero, 0x70($s4)
/* C32C50 80241770 A640008E */  sh        $zero, 0x8e($s2)
/* C32C54 80241774 8E2200CC */  lw        $v0, 0xcc($s1)
/* C32C58 80241778 8E430000 */  lw        $v1, ($s2)
/* C32C5C 8024177C 8C420000 */  lw        $v0, ($v0)
/* C32C60 80241780 00641824 */  and       $v1, $v1, $a0
/* C32C64 80241784 AE430000 */  sw        $v1, ($s2)
/* C32C68 80241788 AE420028 */  sw        $v0, 0x28($s2)
/* C32C6C 8024178C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C32C70 80241790 8C420098 */  lw        $v0, 0x98($v0)
/* C32C74 80241794 54400005 */  bnel      $v0, $zero, .L802417AC
/* C32C78 80241798 2402FDFF */   addiu    $v0, $zero, -0x201
/* C32C7C 8024179C 34620200 */  ori       $v0, $v1, 0x200
/* C32C80 802417A0 2403FFF7 */  addiu     $v1, $zero, -9
/* C32C84 802417A4 080905ED */  j         .L802417B4
/* C32C88 802417A8 00431024 */   and      $v0, $v0, $v1
.L802417AC:
/* C32C8C 802417AC 00621024 */  and       $v0, $v1, $v0
/* C32C90 802417B0 34420008 */  ori       $v0, $v0, 8
.L802417B4:
/* C32C94 802417B4 AE420000 */  sw        $v0, ($s2)
/* C32C98 802417B8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C32C9C 802417BC 30420004 */  andi      $v0, $v0, 4
/* C32CA0 802417C0 10400008 */  beqz      $v0, .L802417E4
/* C32CA4 802417C4 24020063 */   addiu    $v0, $zero, 0x63
/* C32CA8 802417C8 AE820070 */  sw        $v0, 0x70($s4)
/* C32CAC 802417CC AE800074 */  sw        $zero, 0x74($s4)
/* C32CB0 802417D0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C32CB4 802417D4 2403FFFB */  addiu     $v1, $zero, -5
/* C32CB8 802417D8 00431024 */  and       $v0, $v0, $v1
/* C32CBC 802417DC 08090604 */  j         .L80241810
/* C32CC0 802417E0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802417E4:
/* C32CC4 802417E4 8E220000 */  lw        $v0, ($s1)
/* C32CC8 802417E8 3C034000 */  lui       $v1, 0x4000
/* C32CCC 802417EC 00431024 */  and       $v0, $v0, $v1
/* C32CD0 802417F0 10400007 */  beqz      $v0, .L80241810
/* C32CD4 802417F4 3C03BFFF */   lui      $v1, 0xbfff
/* C32CD8 802417F8 2402000C */  addiu     $v0, $zero, 0xc
/* C32CDC 802417FC AE820070 */  sw        $v0, 0x70($s4)
/* C32CE0 80241800 8E220000 */  lw        $v0, ($s1)
/* C32CE4 80241804 3463FFFF */  ori       $v1, $v1, 0xffff
/* C32CE8 80241808 00431024 */  and       $v0, $v0, $v1
/* C32CEC 8024180C AE220000 */  sw        $v0, ($s1)
.L80241810:
/* C32CF0 80241810 27A50038 */  addiu     $a1, $sp, 0x38
/* C32CF4 80241814 27A6003C */  addiu     $a2, $sp, 0x3c
/* C32CF8 80241818 C6400038 */  lwc1      $f0, 0x38($s2)
/* C32CFC 8024181C 864200A8 */  lh        $v0, 0xa8($s2)
/* C32D00 80241820 3C0142C8 */  lui       $at, 0x42c8
/* C32D04 80241824 44812000 */  mtc1      $at, $f4
/* C32D08 80241828 44823000 */  mtc1      $v0, $f6
/* C32D0C 8024182C 00000000 */  nop       
/* C32D10 80241830 468031A0 */  cvt.s.w   $f6, $f6
/* C32D14 80241834 27A20044 */  addiu     $v0, $sp, 0x44
/* C32D18 80241838 E7A00038 */  swc1      $f0, 0x38($sp)
/* C32D1C 8024183C C640003C */  lwc1      $f0, 0x3c($s2)
/* C32D20 80241840 C6420040 */  lwc1      $f2, 0x40($s2)
/* C32D24 80241844 46060000 */  add.s     $f0, $f0, $f6
/* C32D28 80241848 E7A40044 */  swc1      $f4, 0x44($sp)
/* C32D2C 8024184C E7A20040 */  swc1      $f2, 0x40($sp)
/* C32D30 80241850 E7A0003C */  swc1      $f0, 0x3c($sp)
/* C32D34 80241854 AFA20010 */  sw        $v0, 0x10($sp)
/* C32D38 80241858 8E440080 */  lw        $a0, 0x80($s2)
/* C32D3C 8024185C 0C0372DF */  jal       func_800DCB7C
/* C32D40 80241860 27A70040 */   addiu    $a3, $sp, 0x40
/* C32D44 80241864 10400003 */  beqz      $v0, .L80241874
/* C32D48 80241868 00000000 */   nop      
/* C32D4C 8024186C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* C32D50 80241870 E640003C */  swc1      $f0, 0x3c($s2)
.L80241874:
/* C32D54 80241874 8E830070 */  lw        $v1, 0x70($s4)
/* C32D58 80241878 2C620064 */  sltiu     $v0, $v1, 0x64
/* C32D5C 8024187C 10400042 */  beqz      $v0, .L80241988
/* C32D60 80241880 00031080 */   sll      $v0, $v1, 2
/* C32D64 80241884 3C018024 */  lui       $at, %hi(pause_tabs_draw_stats)
/* C32D68 80241888 00220821 */  addu      $at, $at, $v0
/* C32D6C 8024188C 8C224B98 */  lw        $v0, %lo(pause_tabs_draw_stats)($at)
/* C32D70 80241890 00400008 */  jr        $v0
/* C32D74 80241894 00000000 */   nop      
/* C32D78 80241898 0280202D */  daddu     $a0, $s4, $zero
/* C32D7C 8024189C 0260282D */  daddu     $a1, $s3, $zero
/* C32D80 802418A0 0C0902C8 */  jal       func_80240B20_C32000
/* C32D84 802418A4 02A0302D */   daddu    $a2, $s5, $zero
/* C32D88 802418A8 0280202D */  daddu     $a0, $s4, $zero
/* C32D8C 802418AC 0260282D */  daddu     $a1, $s3, $zero
/* C32D90 802418B0 0C09031E */  jal       func_80240C78_C32158
/* C32D94 802418B4 02A0302D */   daddu    $a2, $s5, $zero
/* C32D98 802418B8 08090662 */  j         .L80241988
/* C32D9C 802418BC 00000000 */   nop      
/* C32DA0 802418C0 0280202D */  daddu     $a0, $s4, $zero
/* C32DA4 802418C4 0260282D */  daddu     $a1, $s3, $zero
/* C32DA8 802418C8 0C0903C8 */  jal       UnkNpcAIFunc1
/* C32DAC 802418CC 02A0302D */   daddu    $a2, $s5, $zero
/* C32DB0 802418D0 0280202D */  daddu     $a0, $s4, $zero
/* C32DB4 802418D4 0260282D */  daddu     $a1, $s3, $zero
/* C32DB8 802418D8 0C0903F8 */  jal       func_80240FE0_C324C0
/* C32DBC 802418DC 02A0302D */   daddu    $a2, $s5, $zero
/* C32DC0 802418E0 08090662 */  j         .L80241988
/* C32DC4 802418E4 00000000 */   nop      
/* C32DC8 802418E8 0280202D */  daddu     $a0, $s4, $zero
/* C32DCC 802418EC 0260282D */  daddu     $a1, $s3, $zero
/* C32DD0 802418F0 0C090467 */  jal       func_8024119C_C3267C
/* C32DD4 802418F4 02A0302D */   daddu    $a2, $s5, $zero
/* C32DD8 802418F8 08090662 */  j         .L80241988
/* C32DDC 802418FC 00000000 */   nop      
/* C32DE0 80241900 0280202D */  daddu     $a0, $s4, $zero
/* C32DE4 80241904 0260282D */  daddu     $a1, $s3, $zero
/* C32DE8 80241908 0C090494 */  jal       func_80241250_C32730
/* C32DEC 8024190C 02A0302D */   daddu    $a2, $s5, $zero
/* C32DF0 80241910 0280202D */  daddu     $a0, $s4, $zero
/* C32DF4 80241914 0260282D */  daddu     $a1, $s3, $zero
/* C32DF8 80241918 0C0904B1 */  jal       NpcJumpFunc
/* C32DFC 8024191C 02A0302D */   daddu    $a2, $s5, $zero
/* C32E00 80241920 08090662 */  j         .L80241988
/* C32E04 80241924 00000000 */   nop      
/* C32E08 80241928 0280202D */  daddu     $a0, $s4, $zero
/* C32E0C 8024192C 0260282D */  daddu     $a1, $s3, $zero
/* C32E10 80241930 0C0904CF */  jal       func_8024133C_C3281C
/* C32E14 80241934 02A0302D */   daddu    $a2, $s5, $zero
/* C32E18 80241938 0280202D */  daddu     $a0, $s4, $zero
/* C32E1C 8024193C 0260282D */  daddu     $a1, $s3, $zero
/* C32E20 80241940 0C09051B */  jal       func_8024146C_C3294C
/* C32E24 80241944 02A0302D */   daddu    $a2, $s5, $zero
/* C32E28 80241948 08090662 */  j         .L80241988
/* C32E2C 8024194C 00000000 */   nop      
/* C32E30 80241950 0280202D */  daddu     $a0, $s4, $zero
/* C32E34 80241954 0260282D */  daddu     $a1, $s3, $zero
/* C32E38 80241958 0C090563 */  jal       UnkNpcDurationFlagFunc
/* C32E3C 8024195C 02A0302D */   daddu    $a2, $s5, $zero
/* C32E40 80241960 08090662 */  j         .L80241988
/* C32E44 80241964 00000000 */   nop      
/* C32E48 80241968 0280202D */  daddu     $a0, $s4, $zero
/* C32E4C 8024196C 0260282D */  daddu     $a1, $s3, $zero
/* C32E50 80241970 0C09057D */  jal       func_802415F4_C32AD4
/* C32E54 80241974 02A0302D */   daddu    $a2, $s5, $zero
/* C32E58 80241978 08090662 */  j         .L80241988
/* C32E5C 8024197C 00000000 */   nop      
/* C32E60 80241980 0C0129CF */  jal       func_8004A73C
/* C32E64 80241984 0280202D */   daddu    $a0, $s4, $zero
.L80241988:
/* C32E68 80241988 8FBF0060 */  lw        $ra, 0x60($sp)
/* C32E6C 8024198C 8FB5005C */  lw        $s5, 0x5c($sp)
/* C32E70 80241990 8FB40058 */  lw        $s4, 0x58($sp)
/* C32E74 80241994 8FB30054 */  lw        $s3, 0x54($sp)
/* C32E78 80241998 8FB20050 */  lw        $s2, 0x50($sp)
/* C32E7C 8024199C 8FB1004C */  lw        $s1, 0x4c($sp)
/* C32E80 802419A0 8FB00048 */  lw        $s0, 0x48($sp)
/* C32E84 802419A4 0000102D */  daddu     $v0, $zero, $zero
/* C32E88 802419A8 03E00008 */  jr        $ra
/* C32E8C 802419AC 27BD0068 */   addiu    $sp, $sp, 0x68
