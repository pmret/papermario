.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_HeartBlockContent__setupGfx
/* 105FB0 802E4730 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 105FB4 802E4734 AFB00060 */  sw        $s0, 0x60($sp)
/* 105FB8 802E4738 00A0802D */  daddu     $s0, $a1, $zero
/* 105FBC 802E473C AFBF0084 */  sw        $ra, 0x84($sp)
/* 105FC0 802E4740 AFBE0080 */  sw        $fp, 0x80($sp)
/* 105FC4 802E4744 AFB7007C */  sw        $s7, 0x7c($sp)
/* 105FC8 802E4748 AFB60078 */  sw        $s6, 0x78($sp)
/* 105FCC 802E474C AFB50074 */  sw        $s5, 0x74($sp)
/* 105FD0 802E4750 AFB40070 */  sw        $s4, 0x70($sp)
/* 105FD4 802E4754 AFB3006C */  sw        $s3, 0x6c($sp)
/* 105FD8 802E4758 AFB20068 */  sw        $s2, 0x68($sp)
/* 105FDC 802E475C 0C04417A */  jal       get_entity_by_index
/* 105FE0 802E4760 AFB10064 */   sw       $s1, 0x64($sp)
/* 105FE4 802E4764 3C04FCFF */  lui       $a0, 0xfcff
/* 105FE8 802E4768 3484B3FF */  ori       $a0, $a0, 0xb3ff
/* 105FEC 802E476C 3C03FF2C */  lui       $v1, 0xff2c
/* 105FF0 802E4770 3463FE7F */  ori       $v1, $v1, 0xfe7f
/* 105FF4 802E4774 2415005C */  addiu     $s5, $zero, 0x5c
/* 105FF8 802E4778 0040882D */  daddu     $s1, $v0, $zero
/* 105FFC 802E477C 3210FFFF */  andi      $s0, $s0, 0xffff
/* 106000 802E4780 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 106004 802E4784 8E52A66C */  lw        $s2, %lo(gMasterGfxPos)($s2)
/* 106008 802E4788 8E330040 */  lw        $s3, 0x40($s1)
/* 10600C 802E478C 8E250044 */  lw        $a1, 0x44($s1)
/* 106010 802E4790 0240102D */  daddu     $v0, $s2, $zero
/* 106014 802E4794 26520008 */  addiu     $s2, $s2, 8
/* 106018 802E4798 AC430004 */  sw        $v1, 4($v0)
/* 10601C 802E479C 0240182D */  daddu     $v1, $s2, $zero
/* 106020 802E47A0 AC440000 */  sw        $a0, ($v0)
/* 106024 802E47A4 3C02FA00 */  lui       $v0, 0xfa00
/* 106028 802E47A8 AC620000 */  sw        $v0, ($v1)
/* 10602C 802E47AC 9222000B */  lbu       $v0, 0xb($s1)
/* 106030 802E47B0 26520008 */  addiu     $s2, $s2, 8
/* 106034 802E47B4 AC620004 */  sw        $v0, 4($v1)
/* 106038 802E47B8 9223000B */  lbu       $v1, 0xb($s1)
/* 10603C 802E47BC 0075102A */  slt       $v0, $v1, $s5
/* 106040 802E47C0 10400002 */  beqz      $v0, .L802E47CC
/* 106044 802E47C4 00B0F021 */   addu     $fp, $a1, $s0
/* 106048 802E47C8 0060A82D */  daddu     $s5, $v1, $zero
.L802E47CC:
/* 10604C 802E47CC 0260202D */  daddu     $a0, $s3, $zero
/* 106050 802E47D0 0C0B91C4 */  jal       entity_HeartBlockContent_get_previous_yaw
/* 106054 802E47D4 24050002 */   addiu    $a1, $zero, 2
/* 106058 802E47D8 44050000 */  mfc1      $a1, $f0
/* 10605C 802E47DC 44800000 */  mtc1      $zero, $f0
/* 106060 802E47E0 3C073F80 */  lui       $a3, 0x3f80
/* 106064 802E47E4 44060000 */  mfc1      $a2, $f0
/* 106068 802E47E8 27A40018 */  addiu     $a0, $sp, 0x18
/* 10606C 802E47EC 0C019EC8 */  jal       guRotateF
/* 106070 802E47F0 AFA60010 */   sw       $a2, 0x10($sp)
/* 106074 802E47F4 27A40018 */  addiu     $a0, $sp, 0x18
/* 106078 802E47F8 26700058 */  addiu     $s0, $s3, 0x58
/* 10607C 802E47FC 0C019D40 */  jal       guMtxF2L
/* 106080 802E4800 0200282D */   daddu    $a1, $s0, $zero
/* 106084 802E4804 3C040001 */  lui       $a0, 1
/* 106088 802E4808 34841630 */  ori       $a0, $a0, 0x1630
/* 10608C 802E480C 26650098 */  addiu     $a1, $s3, 0x98
/* 106090 802E4810 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 106094 802E4814 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* 106098 802E4818 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 10609C 802E481C 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 1060A0 802E4820 00021180 */  sll       $v0, $v0, 6
/* 1060A4 802E4824 00621821 */  addu      $v1, $v1, $v0
/* 1060A8 802E4828 00641821 */  addu      $v1, $v1, $a0
.L802E482C:
/* 1060AC 802E482C 8E160000 */  lw        $s6, ($s0)
/* 1060B0 802E4830 8E170004 */  lw        $s7, 4($s0)
/* 1060B4 802E4834 8E180008 */  lw        $t8, 8($s0)
/* 1060B8 802E4838 8E19000C */  lw        $t9, 0xc($s0)
/* 1060BC 802E483C AC760000 */  sw        $s6, ($v1)
/* 1060C0 802E4840 AC770004 */  sw        $s7, 4($v1)
/* 1060C4 802E4844 AC780008 */  sw        $t8, 8($v1)
/* 1060C8 802E4848 AC79000C */  sw        $t9, 0xc($v1)
/* 1060CC 802E484C 26100010 */  addiu     $s0, $s0, 0x10
/* 1060D0 802E4850 1605FFF6 */  bne       $s0, $a1, .L802E482C
/* 1060D4 802E4854 24630010 */   addiu    $v1, $v1, 0x10
/* 1060D8 802E4858 0240502D */  daddu     $t2, $s2, $zero
/* 1060DC 802E485C 26520008 */  addiu     $s2, $s2, 8
/* 1060E0 802E4860 3C160001 */  lui       $s6, 1
/* 1060E4 802E4864 36D61630 */  ori       $s6, $s6, 0x1630
/* 1060E8 802E4868 0240482D */  daddu     $t1, $s2, $zero
/* 1060EC 802E486C 26520008 */  addiu     $s2, $s2, 8
/* 1060F0 802E4870 3C0FE200 */  lui       $t7, 0xe200
/* 1060F4 802E4874 35EF001C */  ori       $t7, $t7, 0x1c
/* 1060F8 802E4878 3C0E0050 */  lui       $t6, 0x50
/* 1060FC 802E487C 35CE4358 */  ori       $t6, $t6, 0x4358
/* 106100 802E4880 0240302D */  daddu     $a2, $s2, $zero
/* 106104 802E4884 26520008 */  addiu     $s2, $s2, 8
/* 106108 802E4888 0240382D */  daddu     $a3, $s2, $zero
/* 10610C 802E488C 26520008 */  addiu     $s2, $s2, 8
/* 106110 802E4890 0240402D */  daddu     $t0, $s2, $zero
/* 106114 802E4894 26520008 */  addiu     $s2, $s2, 8
/* 106118 802E4898 3C0DFCFF */  lui       $t5, 0xfcff
/* 10611C 802E489C 35ADB3FF */  ori       $t5, $t5, 0xb3ff
/* 106120 802E48A0 3C0CFF2C */  lui       $t4, 0xff2c
/* 106124 802E48A4 358CFE7F */  ori       $t4, $t4, 0xfe7f
/* 106128 802E48A8 0240202D */  daddu     $a0, $s2, $zero
/* 10612C 802E48AC 26520008 */  addiu     $s2, $s2, 8
/* 106130 802E48B0 0240282D */  daddu     $a1, $s2, $zero
/* 106134 802E48B4 3C0BD838 */  lui       $t3, 0xd838
/* 106138 802E48B8 356B0002 */  ori       $t3, $t3, 2
/* 10613C 802E48BC 3C148007 */  lui       $s4, %hi(gMatrixListPos)
/* 106140 802E48C0 269441F0 */  addiu     $s4, $s4, %lo(gMatrixListPos)
/* 106144 802E48C4 AFB60058 */  sw        $s6, 0x58($sp)
/* 106148 802E48C8 96820000 */  lhu       $v0, ($s4)
/* 10614C 802E48CC 3C03DA38 */  lui       $v1, 0xda38
/* 106150 802E48D0 AD430000 */  sw        $v1, ($t2)
/* 106154 802E48D4 24430001 */  addiu     $v1, $v0, 1
/* 106158 802E48D8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 10615C 802E48DC 00021180 */  sll       $v0, $v0, 6
/* 106160 802E48E0 A6830000 */  sh        $v1, ($s4)
/* 106164 802E48E4 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 106168 802E48E8 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 10616C 802E48EC 00561021 */  addu      $v0, $v0, $s6
/* 106170 802E48F0 00621821 */  addu      $v1, $v1, $v0
/* 106174 802E48F4 3C02DE00 */  lui       $v0, 0xde00
/* 106178 802E48F8 AD430004 */  sw        $v1, 4($t2)
/* 10617C 802E48FC AD2F0000 */  sw        $t7, ($t1)
/* 106180 802E4900 AD2E0004 */  sw        $t6, 4($t1)
/* 106184 802E4904 ACC20000 */  sw        $v0, ($a2)
/* 106188 802E4908 3C02E700 */  lui       $v0, 0xe700
/* 10618C 802E490C ACDE0004 */  sw        $fp, 4($a2)
/* 106190 802E4910 ACE20000 */  sw        $v0, ($a3)
/* 106194 802E4914 3C02FA00 */  lui       $v0, 0xfa00
/* 106198 802E4918 ACE00004 */  sw        $zero, 4($a3)
/* 10619C 802E491C AD0D0000 */  sw        $t5, ($t0)
/* 1061A0 802E4920 AD0C0004 */  sw        $t4, 4($t0)
/* 1061A4 802E4924 AC820000 */  sw        $v0, ($a0)
/* 1061A8 802E4928 24020040 */  addiu     $v0, $zero, 0x40
/* 1061AC 802E492C AC950004 */  sw        $s5, 4($a0)
/* 1061B0 802E4930 ACAB0000 */  sw        $t3, ($a1)
/* 1061B4 802E4934 ACA20004 */  sw        $v0, 4($a1)
/* 1061B8 802E4938 9223000B */  lbu       $v1, 0xb($s1)
/* 1061BC 802E493C 24150048 */  addiu     $s5, $zero, 0x48
/* 1061C0 802E4940 0075102A */  slt       $v0, $v1, $s5
/* 1061C4 802E4944 10400002 */  beqz      $v0, .L802E4950
/* 1061C8 802E4948 26520008 */   addiu    $s2, $s2, 8
/* 1061CC 802E494C 0060A82D */  daddu     $s5, $v1, $zero
.L802E4950:
/* 1061D0 802E4950 0260202D */  daddu     $a0, $s3, $zero
/* 1061D4 802E4954 0C0B91C4 */  jal       entity_HeartBlockContent_get_previous_yaw
/* 1061D8 802E4958 24050003 */   addiu    $a1, $zero, 3
/* 1061DC 802E495C 44050000 */  mfc1      $a1, $f0
/* 1061E0 802E4960 44800000 */  mtc1      $zero, $f0
/* 1061E4 802E4964 3C073F80 */  lui       $a3, 0x3f80
/* 1061E8 802E4968 44060000 */  mfc1      $a2, $f0
/* 1061EC 802E496C 27A40018 */  addiu     $a0, $sp, 0x18
/* 1061F0 802E4970 0C019EC8 */  jal       guRotateF
/* 1061F4 802E4974 AFA60010 */   sw       $a2, 0x10($sp)
/* 1061F8 802E4978 27A40018 */  addiu     $a0, $sp, 0x18
/* 1061FC 802E497C 26700098 */  addiu     $s0, $s3, 0x98
/* 106200 802E4980 0C019D40 */  jal       guMtxF2L
/* 106204 802E4984 0200282D */   daddu    $a1, $s0, $zero
/* 106208 802E4988 266400D8 */  addiu     $a0, $s3, 0xd8
/* 10620C 802E498C 96820000 */  lhu       $v0, ($s4)
/* 106210 802E4990 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 106214 802E4994 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 106218 802E4998 8FB70058 */  lw        $s7, 0x58($sp)
/* 10621C 802E499C 00021180 */  sll       $v0, $v0, 6
/* 106220 802E49A0 00621821 */  addu      $v1, $v1, $v0
/* 106224 802E49A4 00771821 */  addu      $v1, $v1, $s7
.L802E49A8:
/* 106228 802E49A8 8E180000 */  lw        $t8, ($s0)
/* 10622C 802E49AC 8E190004 */  lw        $t9, 4($s0)
/* 106230 802E49B0 8E160008 */  lw        $s6, 8($s0)
/* 106234 802E49B4 8E17000C */  lw        $s7, 0xc($s0)
/* 106238 802E49B8 AC780000 */  sw        $t8, ($v1)
/* 10623C 802E49BC AC790004 */  sw        $t9, 4($v1)
/* 106240 802E49C0 AC760008 */  sw        $s6, 8($v1)
/* 106244 802E49C4 AC77000C */  sw        $s7, 0xc($v1)
/* 106248 802E49C8 26100010 */  addiu     $s0, $s0, 0x10
/* 10624C 802E49CC 1604FFF6 */  bne       $s0, $a0, .L802E49A8
/* 106250 802E49D0 24630010 */   addiu    $v1, $v1, 0x10
/* 106254 802E49D4 0240582D */  daddu     $t3, $s2, $zero
/* 106258 802E49D8 26520008 */  addiu     $s2, $s2, 8
/* 10625C 802E49DC 3C110001 */  lui       $s1, 1
/* 106260 802E49E0 36311630 */  ori       $s1, $s1, 0x1630
/* 106264 802E49E4 0240502D */  daddu     $t2, $s2, $zero
/* 106268 802E49E8 26520008 */  addiu     $s2, $s2, 8
/* 10626C 802E49EC 3C10E200 */  lui       $s0, 0xe200
/* 106270 802E49F0 3610001C */  ori       $s0, $s0, 0x1c
/* 106274 802E49F4 3C0F0050 */  lui       $t7, 0x50
/* 106278 802E49F8 35EF4358 */  ori       $t7, $t7, 0x4358
/* 10627C 802E49FC 0240382D */  daddu     $a3, $s2, $zero
/* 106280 802E4A00 26520008 */  addiu     $s2, $s2, 8
/* 106284 802E4A04 0240402D */  daddu     $t0, $s2, $zero
/* 106288 802E4A08 26520008 */  addiu     $s2, $s2, 8
/* 10628C 802E4A0C 0240482D */  daddu     $t1, $s2, $zero
/* 106290 802E4A10 26520008 */  addiu     $s2, $s2, 8
/* 106294 802E4A14 3C0EFCFF */  lui       $t6, 0xfcff
/* 106298 802E4A18 35CEB3FF */  ori       $t6, $t6, 0xb3ff
/* 10629C 802E4A1C 3C0DFF2C */  lui       $t5, 0xff2c
/* 1062A0 802E4A20 35ADFE7F */  ori       $t5, $t5, 0xfe7f
/* 1062A4 802E4A24 0240282D */  daddu     $a1, $s2, $zero
/* 1062A8 802E4A28 26520008 */  addiu     $s2, $s2, 8
/* 1062AC 802E4A2C 0240302D */  daddu     $a2, $s2, $zero
/* 1062B0 802E4A30 26520008 */  addiu     $s2, $s2, 8
/* 1062B4 802E4A34 3C0CD838 */  lui       $t4, 0xd838
/* 1062B8 802E4A38 358C0002 */  ori       $t4, $t4, 2
/* 1062BC 802E4A3C 3C048007 */  lui       $a0, %hi(gMatrixListPos)
/* 1062C0 802E4A40 248441F0 */  addiu     $a0, $a0, %lo(gMatrixListPos)
/* 1062C4 802E4A44 94820000 */  lhu       $v0, ($a0)
/* 1062C8 802E4A48 3C03DA38 */  lui       $v1, 0xda38
/* 1062CC 802E4A4C AD630000 */  sw        $v1, ($t3)
/* 1062D0 802E4A50 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 1062D4 802E4A54 AC32A66C */  sw        $s2, %lo(gMasterGfxPos)($at)
/* 1062D8 802E4A58 24430001 */  addiu     $v1, $v0, 1
/* 1062DC 802E4A5C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 1062E0 802E4A60 00021180 */  sll       $v0, $v0, 6
/* 1062E4 802E4A64 A4830000 */  sh        $v1, ($a0)
/* 1062E8 802E4A68 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 1062EC 802E4A6C 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 1062F0 802E4A70 00511021 */  addu      $v0, $v0, $s1
/* 1062F4 802E4A74 00621821 */  addu      $v1, $v1, $v0
/* 1062F8 802E4A78 3C02DE00 */  lui       $v0, 0xde00
/* 1062FC 802E4A7C AD630004 */  sw        $v1, 4($t3)
/* 106300 802E4A80 AD500000 */  sw        $s0, ($t2)
/* 106304 802E4A84 AD4F0004 */  sw        $t7, 4($t2)
/* 106308 802E4A88 ACE20000 */  sw        $v0, ($a3)
/* 10630C 802E4A8C 3C02E700 */  lui       $v0, 0xe700
/* 106310 802E4A90 ACFE0004 */  sw        $fp, 4($a3)
/* 106314 802E4A94 AD020000 */  sw        $v0, ($t0)
/* 106318 802E4A98 3C02FA00 */  lui       $v0, 0xfa00
/* 10631C 802E4A9C AD000004 */  sw        $zero, 4($t0)
/* 106320 802E4AA0 AD2E0000 */  sw        $t6, ($t1)
/* 106324 802E4AA4 AD2D0004 */  sw        $t5, 4($t1)
/* 106328 802E4AA8 ACA20000 */  sw        $v0, ($a1)
/* 10632C 802E4AAC 24020040 */  addiu     $v0, $zero, 0x40
/* 106330 802E4AB0 ACB50004 */  sw        $s5, 4($a1)
/* 106334 802E4AB4 ACCC0000 */  sw        $t4, ($a2)
/* 106338 802E4AB8 ACC20004 */  sw        $v0, 4($a2)
/* 10633C 802E4ABC 8FBF0084 */  lw        $ra, 0x84($sp)
/* 106340 802E4AC0 8FBE0080 */  lw        $fp, 0x80($sp)
/* 106344 802E4AC4 8FB7007C */  lw        $s7, 0x7c($sp)
/* 106348 802E4AC8 8FB60078 */  lw        $s6, 0x78($sp)
/* 10634C 802E4ACC 8FB50074 */  lw        $s5, 0x74($sp)
/* 106350 802E4AD0 8FB40070 */  lw        $s4, 0x70($sp)
/* 106354 802E4AD4 8FB3006C */  lw        $s3, 0x6c($sp)
/* 106358 802E4AD8 8FB20068 */  lw        $s2, 0x68($sp)
/* 10635C 802E4ADC 8FB10064 */  lw        $s1, 0x64($sp)
/* 106360 802E4AE0 8FB00060 */  lw        $s0, 0x60($sp)
/* 106364 802E4AE4 03E00008 */  jr        $ra
/* 106368 802E4AE8 27BD0088 */   addiu    $sp, $sp, 0x88
