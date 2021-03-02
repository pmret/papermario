.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B94_BE8774
/* BE8774 80240B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* BE8778 80240B98 AFB40058 */  sw        $s4, 0x58($sp)
/* BE877C 80240B9C 0080A02D */  daddu     $s4, $a0, $zero
/* BE8780 80240BA0 AFBF0060 */  sw        $ra, 0x60($sp)
/* BE8784 80240BA4 AFB5005C */  sw        $s5, 0x5c($sp)
/* BE8788 80240BA8 AFB30054 */  sw        $s3, 0x54($sp)
/* BE878C 80240BAC AFB20050 */  sw        $s2, 0x50($sp)
/* BE8790 80240BB0 AFB1004C */  sw        $s1, 0x4c($sp)
/* BE8794 80240BB4 AFB00048 */  sw        $s0, 0x48($sp)
/* BE8798 80240BB8 8E910148 */  lw        $s1, 0x148($s4)
/* BE879C 80240BBC 86240008 */  lh        $a0, 8($s1)
/* BE87A0 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* BE87A4 80240BC4 00A0802D */   daddu    $s0, $a1, $zero
/* BE87A8 80240BC8 8E83000C */  lw        $v1, 0xc($s4)
/* BE87AC 80240BCC 0280202D */  daddu     $a0, $s4, $zero
/* BE87B0 80240BD0 8C650000 */  lw        $a1, ($v1)
/* BE87B4 80240BD4 0C0B1EAF */  jal       get_variable
/* BE87B8 80240BD8 0040902D */   daddu    $s2, $v0, $zero
/* BE87BC 80240BDC AFA00018 */  sw        $zero, 0x18($sp)
/* BE87C0 80240BE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE87C4 80240BE4 8C630094 */  lw        $v1, 0x94($v1)
/* BE87C8 80240BE8 AFA3001C */  sw        $v1, 0x1c($sp)
/* BE87CC 80240BEC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE87D0 80240BF0 8C630080 */  lw        $v1, 0x80($v1)
/* BE87D4 80240BF4 AFA30020 */  sw        $v1, 0x20($sp)
/* BE87D8 80240BF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE87DC 80240BFC 8C630088 */  lw        $v1, 0x88($v1)
/* BE87E0 80240C00 AFA30024 */  sw        $v1, 0x24($sp)
/* BE87E4 80240C04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE87E8 80240C08 8C63008C */  lw        $v1, 0x8c($v1)
/* BE87EC 80240C0C 27B50018 */  addiu     $s5, $sp, 0x18
/* BE87F0 80240C10 AFA30028 */  sw        $v1, 0x28($sp)
/* BE87F4 80240C14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE87F8 80240C18 3C014282 */  lui       $at, 0x4282
/* BE87FC 80240C1C 44810000 */  mtc1      $at, $f0
/* BE8800 80240C20 8C630090 */  lw        $v1, 0x90($v1)
/* BE8804 80240C24 0040982D */  daddu     $s3, $v0, $zero
/* BE8808 80240C28 E7A00030 */  swc1      $f0, 0x30($sp)
/* BE880C 80240C2C A7A00034 */  sh        $zero, 0x34($sp)
/* BE8810 80240C30 16000005 */  bnez      $s0, .L80240C48
/* BE8814 80240C34 AFA3002C */   sw       $v1, 0x2c($sp)
/* BE8818 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BE881C 80240C3C 30420004 */  andi      $v0, $v0, 4
/* BE8820 80240C40 10400044 */  beqz      $v0, .L80240D54
/* BE8824 80240C44 00000000 */   nop
.L80240C48:
/* BE8828 80240C48 2404F7FF */  addiu     $a0, $zero, -0x801
/* BE882C 80240C4C AE800070 */  sw        $zero, 0x70($s4)
/* BE8830 80240C50 A640008E */  sh        $zero, 0x8e($s2)
/* BE8834 80240C54 8E2200CC */  lw        $v0, 0xcc($s1)
/* BE8838 80240C58 8E430000 */  lw        $v1, ($s2)
/* BE883C 80240C5C 8C420000 */  lw        $v0, ($v0)
/* BE8840 80240C60 00641824 */  and       $v1, $v1, $a0
/* BE8844 80240C64 AE430000 */  sw        $v1, ($s2)
/* BE8848 80240C68 AE420028 */  sw        $v0, 0x28($s2)
/* BE884C 80240C6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BE8850 80240C70 8C420098 */  lw        $v0, 0x98($v0)
/* BE8854 80240C74 54400005 */  bnel      $v0, $zero, .L80240C8C
/* BE8858 80240C78 2402FDFF */   addiu    $v0, $zero, -0x201
/* BE885C 80240C7C 34620200 */  ori       $v0, $v1, 0x200
/* BE8860 80240C80 2403FFF7 */  addiu     $v1, $zero, -9
/* BE8864 80240C84 08090325 */  j         .L80240C94
/* BE8868 80240C88 00431024 */   and      $v0, $v0, $v1
.L80240C8C:
/* BE886C 80240C8C 00621024 */  and       $v0, $v1, $v0
/* BE8870 80240C90 34420008 */  ori       $v0, $v0, 8
.L80240C94:
/* BE8874 80240C94 AE420000 */  sw        $v0, ($s2)
/* BE8878 80240C98 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BE887C 80240C9C 30420004 */  andi      $v0, $v0, 4
/* BE8880 80240CA0 10400008 */  beqz      $v0, .L80240CC4
/* BE8884 80240CA4 24020063 */   addiu    $v0, $zero, 0x63
/* BE8888 80240CA8 AE820070 */  sw        $v0, 0x70($s4)
/* BE888C 80240CAC AE800074 */  sw        $zero, 0x74($s4)
/* BE8890 80240CB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BE8894 80240CB4 2403FFFB */  addiu     $v1, $zero, -5
/* BE8898 80240CB8 00431024 */  and       $v0, $v0, $v1
/* BE889C 80240CBC 0809033C */  j         .L80240CF0
/* BE88A0 80240CC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240CC4:
/* BE88A4 80240CC4 8E220000 */  lw        $v0, ($s1)
/* BE88A8 80240CC8 3C034000 */  lui       $v1, 0x4000
/* BE88AC 80240CCC 00431024 */  and       $v0, $v0, $v1
/* BE88B0 80240CD0 10400007 */  beqz      $v0, .L80240CF0
/* BE88B4 80240CD4 3C03BFFF */   lui      $v1, 0xbfff
/* BE88B8 80240CD8 2402000C */  addiu     $v0, $zero, 0xc
/* BE88BC 80240CDC AE820070 */  sw        $v0, 0x70($s4)
/* BE88C0 80240CE0 8E220000 */  lw        $v0, ($s1)
/* BE88C4 80240CE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* BE88C8 80240CE8 00431024 */  and       $v0, $v0, $v1
/* BE88CC 80240CEC AE220000 */  sw        $v0, ($s1)
.L80240CF0:
/* BE88D0 80240CF0 27A50038 */  addiu     $a1, $sp, 0x38
/* BE88D4 80240CF4 27A6003C */  addiu     $a2, $sp, 0x3c
/* BE88D8 80240CF8 C6400038 */  lwc1      $f0, 0x38($s2)
/* BE88DC 80240CFC 864200A8 */  lh        $v0, 0xa8($s2)
/* BE88E0 80240D00 3C0142C8 */  lui       $at, 0x42c8
/* BE88E4 80240D04 44812000 */  mtc1      $at, $f4
/* BE88E8 80240D08 44823000 */  mtc1      $v0, $f6
/* BE88EC 80240D0C 00000000 */  nop
/* BE88F0 80240D10 468031A0 */  cvt.s.w   $f6, $f6
/* BE88F4 80240D14 27A20044 */  addiu     $v0, $sp, 0x44
/* BE88F8 80240D18 E7A00038 */  swc1      $f0, 0x38($sp)
/* BE88FC 80240D1C C640003C */  lwc1      $f0, 0x3c($s2)
/* BE8900 80240D20 C6420040 */  lwc1      $f2, 0x40($s2)
/* BE8904 80240D24 46060000 */  add.s     $f0, $f0, $f6
/* BE8908 80240D28 E7A40044 */  swc1      $f4, 0x44($sp)
/* BE890C 80240D2C E7A20040 */  swc1      $f2, 0x40($sp)
/* BE8910 80240D30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* BE8914 80240D34 AFA20010 */  sw        $v0, 0x10($sp)
/* BE8918 80240D38 8E440080 */  lw        $a0, 0x80($s2)
/* BE891C 80240D3C 0C0372DF */  jal       func_800DCB7C
/* BE8920 80240D40 27A70040 */   addiu    $a3, $sp, 0x40
/* BE8924 80240D44 10400003 */  beqz      $v0, .L80240D54
/* BE8928 80240D48 00000000 */   nop
/* BE892C 80240D4C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* BE8930 80240D50 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D54:
/* BE8934 80240D54 8E830070 */  lw        $v1, 0x70($s4)
/* BE8938 80240D58 2C620064 */  sltiu     $v0, $v1, 0x64
/* BE893C 80240D5C 10400042 */  beqz      $v0, L80240E68_BE8A48
/* BE8940 80240D60 00031080 */   sll      $v0, $v1, 2
/* BE8944 80240D64 3C018024 */  lui       $at, %hi(jtbl_80245060_BECC40)
/* BE8948 80240D68 00220821 */  addu      $at, $at, $v0
/* BE894C 80240D6C 8C225060 */  lw        $v0, %lo(jtbl_80245060_BECC40)($at)
/* BE8950 80240D70 00400008 */  jr        $v0
/* BE8954 80240D74 00000000 */   nop
glabel L80240D78_BE8958
/* BE8958 80240D78 0280202D */  daddu     $a0, $s4, $zero
/* BE895C 80240D7C 0260282D */  daddu     $a1, $s3, $zero
/* BE8960 80240D80 0C090000 */  jal       func_80240000_BE7BE0
/* BE8964 80240D84 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240D88_BE8968
/* BE8968 80240D88 0280202D */  daddu     $a0, $s4, $zero
/* BE896C 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* BE8970 80240D90 0C090056 */  jal       func_80240158_BE7D38
/* BE8974 80240D94 02A0302D */   daddu    $a2, $s5, $zero
/* BE8978 80240D98 0809039A */  j         L80240E68_BE8A48
/* BE897C 80240D9C 00000000 */   nop
glabel L80240DA0_BE8980
/* BE8980 80240DA0 0280202D */  daddu     $a0, $s4, $zero
/* BE8984 80240DA4 0260282D */  daddu     $a1, $s3, $zero
/* BE8988 80240DA8 0C090100 */  jal       arn_05_UnkNpcAIFunc1
/* BE898C 80240DAC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DB0_BE8990
/* BE8990 80240DB0 0280202D */  daddu     $a0, $s4, $zero
/* BE8994 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* BE8998 80240DB8 0C090130 */  jal       func_802404C0_BE80A0
/* BE899C 80240DBC 02A0302D */   daddu    $a2, $s5, $zero
/* BE89A0 80240DC0 0809039A */  j         L80240E68_BE8A48
/* BE89A4 80240DC4 00000000 */   nop
glabel L80240DC8_BE89A8
/* BE89A8 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* BE89AC 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* BE89B0 80240DD0 0C09019F */  jal       func_8024067C_BE825C
/* BE89B4 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* BE89B8 80240DD8 0809039A */  j         L80240E68_BE8A48
/* BE89BC 80240DDC 00000000 */   nop
glabel L80240DE0_BE89C0
/* BE89C0 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* BE89C4 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* BE89C8 80240DE8 0C0901CC */  jal       arn_05_NpcJumpFunc2
/* BE89CC 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DF0_BE89D0
/* BE89D0 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* BE89D4 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* BE89D8 80240DF8 0C0901E9 */  jal       arn_05_NpcJumpFunc
/* BE89DC 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* BE89E0 80240E00 0809039A */  j         L80240E68_BE8A48
/* BE89E4 80240E04 00000000 */   nop
glabel L80240E08_BE89E8
/* BE89E8 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* BE89EC 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* BE89F0 80240E10 0C090207 */  jal       arn_05_UnkNpcAIFunc13
/* BE89F4 80240E14 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240E18_BE89F8
/* BE89F8 80240E18 0280202D */  daddu     $a0, $s4, $zero
/* BE89FC 80240E1C 0260282D */  daddu     $a1, $s3, $zero
/* BE8A00 80240E20 0C090253 */  jal       func_8024094C_BE852C
/* BE8A04 80240E24 02A0302D */   daddu    $a2, $s5, $zero
/* BE8A08 80240E28 0809039A */  j         L80240E68_BE8A48
/* BE8A0C 80240E2C 00000000 */   nop
glabel L80240E30_BE8A10
/* BE8A10 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* BE8A14 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* BE8A18 80240E38 0C09029B */  jal       arn_05_UnkNpcDurationFlagFunc
/* BE8A1C 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* BE8A20 80240E40 0809039A */  j         L80240E68_BE8A48
/* BE8A24 80240E44 00000000 */   nop
glabel L80240E48_BE8A28
/* BE8A28 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* BE8A2C 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* BE8A30 80240E50 0C0902B5 */  jal       func_80240AD4_BE86B4
/* BE8A34 80240E54 02A0302D */   daddu    $a2, $s5, $zero
/* BE8A38 80240E58 0809039A */  j         L80240E68_BE8A48
/* BE8A3C 80240E5C 00000000 */   nop
glabel L80240E60_BE8A40
/* BE8A40 80240E60 0C0129CF */  jal       func_8004A73C
/* BE8A44 80240E64 0280202D */   daddu    $a0, $s4, $zero
glabel L80240E68_BE8A48
/* BE8A48 80240E68 8FBF0060 */  lw        $ra, 0x60($sp)
/* BE8A4C 80240E6C 8FB5005C */  lw        $s5, 0x5c($sp)
/* BE8A50 80240E70 8FB40058 */  lw        $s4, 0x58($sp)
/* BE8A54 80240E74 8FB30054 */  lw        $s3, 0x54($sp)
/* BE8A58 80240E78 8FB20050 */  lw        $s2, 0x50($sp)
/* BE8A5C 80240E7C 8FB1004C */  lw        $s1, 0x4c($sp)
/* BE8A60 80240E80 8FB00048 */  lw        $s0, 0x48($sp)
/* BE8A64 80240E84 0000102D */  daddu     $v0, $zero, $zero
/* BE8A68 80240E88 03E00008 */  jr        $ra
/* BE8A6C 80240E8C 27BD0068 */   addiu    $sp, $sp, 0x68
