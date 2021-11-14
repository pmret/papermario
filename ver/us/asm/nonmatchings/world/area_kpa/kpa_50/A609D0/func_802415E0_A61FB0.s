.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80243660_A64030
.word L802419EC_A623BC, L802419F8_A623C8, L802419F8_A623C8, L802419F8_A623C8, L802419F8_A623C8, L802419F8_A623C8, L802419F8_A623C8, L802419F8_A623C8, L802419EC_A623BC, L802419F8_A623C8, L802419EC_A623BC, L802419F8_A623C8, L802419EC_A623BC, L802419F8_A623C8, L802419EC_A623BC, L802419F8_A623C8, L802419F8_A623C8, L802419F8_A623C8, L802419EC_A623BC, L802419F8_A623C8, L802419EC_A623BC, 0, 0, 0

.section .text

glabel func_802415E0_A61FB0
/* A61FB0 802415E0 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A61FB4 802415E4 AFB3005C */  sw        $s3, 0x5c($sp)
/* A61FB8 802415E8 0080982D */  daddu     $s3, $a0, $zero
/* A61FBC 802415EC AFBF0068 */  sw        $ra, 0x68($sp)
/* A61FC0 802415F0 AFB50064 */  sw        $s5, 0x64($sp)
/* A61FC4 802415F4 AFB40060 */  sw        $s4, 0x60($sp)
/* A61FC8 802415F8 AFB20058 */  sw        $s2, 0x58($sp)
/* A61FCC 802415FC AFB10054 */  sw        $s1, 0x54($sp)
/* A61FD0 80241600 AFB00050 */  sw        $s0, 0x50($sp)
/* A61FD4 80241604 8E710148 */  lw        $s1, 0x148($s3)
/* A61FD8 80241608 86240008 */  lh        $a0, 8($s1)
/* A61FDC 8024160C 0C00EABB */  jal       get_npc_unsafe
/* A61FE0 80241610 00A0802D */   daddu    $s0, $a1, $zero
/* A61FE4 80241614 8E63000C */  lw        $v1, 0xc($s3)
/* A61FE8 80241618 0260202D */  daddu     $a0, $s3, $zero
/* A61FEC 8024161C 8C650000 */  lw        $a1, ($v1)
/* A61FF0 80241620 0C0B1EAF */  jal       evt_get_variable
/* A61FF4 80241624 0040902D */   daddu    $s2, $v0, $zero
/* A61FF8 80241628 AFA00028 */  sw        $zero, 0x28($sp)
/* A61FFC 8024162C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A62000 80241630 8C630030 */  lw        $v1, 0x30($v1)
/* A62004 80241634 AFA3002C */  sw        $v1, 0x2c($sp)
/* A62008 80241638 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A6200C 8024163C 8C63001C */  lw        $v1, 0x1c($v1)
/* A62010 80241640 AFA30030 */  sw        $v1, 0x30($sp)
/* A62014 80241644 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A62018 80241648 8C630024 */  lw        $v1, 0x24($v1)
/* A6201C 8024164C AFA30034 */  sw        $v1, 0x34($sp)
/* A62020 80241650 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A62024 80241654 8C630028 */  lw        $v1, 0x28($v1)
/* A62028 80241658 27B50028 */  addiu     $s5, $sp, 0x28
/* A6202C 8024165C AFA30038 */  sw        $v1, 0x38($sp)
/* A62030 80241660 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A62034 80241664 3C0142C8 */  lui       $at, 0x42c8
/* A62038 80241668 44810000 */  mtc1      $at, $f0
/* A6203C 8024166C 8C63002C */  lw        $v1, 0x2c($v1)
/* A62040 80241670 0040A02D */  daddu     $s4, $v0, $zero
/* A62044 80241674 E7A00040 */  swc1      $f0, 0x40($sp)
/* A62048 80241678 A7A00044 */  sh        $zero, 0x44($sp)
/* A6204C 8024167C 12000009 */  beqz      $s0, .L802416A4
/* A62050 80241680 AFA3003C */   sw       $v1, 0x3c($sp)
/* A62054 80241684 864300A8 */  lh        $v1, 0xa8($s2)
/* A62058 80241688 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A6205C 8024168C AE20008C */  sw        $zero, 0x8c($s1)
/* A62060 80241690 A22000B5 */  sb        $zero, 0xb5($s1)
/* A62064 80241694 34420008 */  ori       $v0, $v0, 8
/* A62068 80241698 AE230084 */  sw        $v1, 0x84($s1)
/* A6206C 8024169C 080905AD */  j         .L802416B4
/* A62070 802416A0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802416A4:
/* A62074 802416A4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A62078 802416A8 30420004 */  andi      $v0, $v0, 4
/* A6207C 802416AC 10400047 */  beqz      $v0, .L802417CC
/* A62080 802416B0 00000000 */   nop
.L802416B4:
/* A62084 802416B4 AE600070 */  sw        $zero, 0x70($s3)
/* A62088 802416B8 A640008E */  sh        $zero, 0x8e($s2)
/* A6208C 802416BC 8E2300CC */  lw        $v1, 0xcc($s1)
/* A62090 802416C0 2404F7FF */  addiu     $a0, $zero, -0x801
/* A62094 802416C4 A2200007 */  sb        $zero, 7($s1)
/* A62098 802416C8 8E420000 */  lw        $v0, ($s2)
/* A6209C 802416CC 8C630000 */  lw        $v1, ($v1)
/* A620A0 802416D0 00441024 */  and       $v0, $v0, $a0
/* A620A4 802416D4 AE420000 */  sw        $v0, ($s2)
/* A620A8 802416D8 AE430028 */  sw        $v1, 0x28($s2)
/* A620AC 802416DC 96220086 */  lhu       $v0, 0x86($s1)
/* A620B0 802416E0 A64200A8 */  sh        $v0, 0xa8($s2)
/* A620B4 802416E4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A620B8 802416E8 AE200090 */  sw        $zero, 0x90($s1)
/* A620BC 802416EC 8C420034 */  lw        $v0, 0x34($v0)
/* A620C0 802416F0 14400006 */  bnez      $v0, .L8024170C
/* A620C4 802416F4 2403FDFF */   addiu    $v1, $zero, -0x201
/* A620C8 802416F8 8E420000 */  lw        $v0, ($s2)
/* A620CC 802416FC 2403FFF7 */  addiu     $v1, $zero, -9
/* A620D0 80241700 34420200 */  ori       $v0, $v0, 0x200
/* A620D4 80241704 080905C6 */  j         .L80241718
/* A620D8 80241708 00431024 */   and      $v0, $v0, $v1
.L8024170C:
/* A620DC 8024170C 8E420000 */  lw        $v0, ($s2)
/* A620E0 80241710 00431024 */  and       $v0, $v0, $v1
/* A620E4 80241714 34420008 */  ori       $v0, $v0, 8
.L80241718:
/* A620E8 80241718 AE420000 */  sw        $v0, ($s2)
/* A620EC 8024171C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A620F0 80241720 30420004 */  andi      $v0, $v0, 4
/* A620F4 80241724 1040001E */  beqz      $v0, .L802417A0
/* A620F8 80241728 24040002 */   addiu    $a0, $zero, 2
/* A620FC 8024172C 0240282D */  daddu     $a1, $s2, $zero
/* A62100 80241730 0000302D */  daddu     $a2, $zero, $zero
/* A62104 80241734 24020063 */  addiu     $v0, $zero, 0x63
/* A62108 80241738 AE620070 */  sw        $v0, 0x70($s3)
/* A6210C 8024173C AE600074 */  sw        $zero, 0x74($s3)
/* A62110 80241740 864300A8 */  lh        $v1, 0xa8($s2)
/* A62114 80241744 3C013F80 */  lui       $at, 0x3f80
/* A62118 80241748 44810000 */  mtc1      $at, $f0
/* A6211C 8024174C 3C014000 */  lui       $at, 0x4000
/* A62120 80241750 44811000 */  mtc1      $at, $f2
/* A62124 80241754 3C01C1A0 */  lui       $at, 0xc1a0
/* A62128 80241758 44812000 */  mtc1      $at, $f4
/* A6212C 8024175C 24020028 */  addiu     $v0, $zero, 0x28
/* A62130 80241760 AFA2001C */  sw        $v0, 0x1c($sp)
/* A62134 80241764 44833000 */  mtc1      $v1, $f6
/* A62138 80241768 00000000 */  nop
/* A6213C 8024176C 468031A0 */  cvt.s.w   $f6, $f6
/* A62140 80241770 44073000 */  mfc1      $a3, $f6
/* A62144 80241774 27A20048 */  addiu     $v0, $sp, 0x48
/* A62148 80241778 AFA20020 */  sw        $v0, 0x20($sp)
/* A6214C 8024177C E7A00010 */  swc1      $f0, 0x10($sp)
/* A62150 80241780 E7A20014 */  swc1      $f2, 0x14($sp)
/* A62154 80241784 0C01BFA4 */  jal       fx_emote
/* A62158 80241788 E7A40018 */   swc1     $f4, 0x18($sp)
/* A6215C 8024178C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A62160 80241790 2403FFFB */  addiu     $v1, $zero, -5
/* A62164 80241794 00431024 */  and       $v0, $v0, $v1
/* A62168 80241798 080905F3 */  j         .L802417CC
/* A6216C 8024179C AE2200B0 */   sw       $v0, 0xb0($s1)
.L802417A0:
/* A62170 802417A0 8E220000 */  lw        $v0, ($s1)
/* A62174 802417A4 3C034000 */  lui       $v1, 0x4000
/* A62178 802417A8 00431024 */  and       $v0, $v0, $v1
/* A6217C 802417AC 10400007 */  beqz      $v0, .L802417CC
/* A62180 802417B0 3C03BFFF */   lui      $v1, 0xbfff
/* A62184 802417B4 2402000C */  addiu     $v0, $zero, 0xc
/* A62188 802417B8 AE620070 */  sw        $v0, 0x70($s3)
/* A6218C 802417BC 8E220000 */  lw        $v0, ($s1)
/* A62190 802417C0 3463FFFF */  ori       $v1, $v1, 0xffff
/* A62194 802417C4 00431024 */  and       $v0, $v0, $v1
/* A62198 802417C8 AE220000 */  sw        $v0, ($s1)
.L802417CC:
/* A6219C 802417CC 8E220090 */  lw        $v0, 0x90($s1)
/* A621A0 802417D0 1840000C */  blez      $v0, .L80241804
/* A621A4 802417D4 2442FFFF */   addiu    $v0, $v0, -1
/* A621A8 802417D8 14400087 */  bnez      $v0, L802419F8_A623C8
/* A621AC 802417DC AE220090 */   sw       $v0, 0x90($s1)
/* A621B0 802417E0 3C03FFAA */  lui       $v1, 0xffaa
/* A621B4 802417E4 8E420028 */  lw        $v0, 0x28($s2)
/* A621B8 802417E8 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* A621BC 802417EC 00431021 */  addu      $v0, $v0, $v1
/* A621C0 802417F0 2C420002 */  sltiu     $v0, $v0, 2
/* A621C4 802417F4 10400003 */  beqz      $v0, .L80241804
/* A621C8 802417F8 3C020055 */   lui      $v0, 0x55
/* A621CC 802417FC 3442000C */  ori       $v0, $v0, 0xc
/* A621D0 80241800 AE420028 */  sw        $v0, 0x28($s2)
.L80241804:
/* A621D4 80241804 8E630070 */  lw        $v1, 0x70($s3)
/* A621D8 80241808 2402000C */  addiu     $v0, $zero, 0xc
/* A621DC 8024180C 10620048 */  beq       $v1, $v0, .L80241930
/* A621E0 80241810 2862000D */   slti     $v0, $v1, 0xd
/* A621E4 80241814 1040000F */  beqz      $v0, .L80241854
/* A621E8 80241818 24100001 */   addiu    $s0, $zero, 1
/* A621EC 8024181C 1070001E */  beq       $v1, $s0, .L80241898
/* A621F0 80241820 28620002 */   slti     $v0, $v1, 2
/* A621F4 80241824 10400005 */  beqz      $v0, .L8024183C
/* A621F8 80241828 24020002 */   addiu    $v0, $zero, 2
/* A621FC 8024182C 10600015 */  beqz      $v1, .L80241884
/* A62200 80241830 0260202D */   daddu    $a0, $s3, $zero
/* A62204 80241834 08090663 */  j         .L8024198C
/* A62208 80241838 00000000 */   nop
.L8024183C:
/* A6220C 8024183C 1062001C */  beq       $v1, $v0, .L802418B0
/* A62210 80241840 24020003 */   addiu    $v0, $zero, 3
/* A62214 80241844 10620035 */  beq       $v1, $v0, .L8024191C
/* A62218 80241848 0260202D */   daddu    $a0, $s3, $zero
/* A6221C 8024184C 08090663 */  j         .L8024198C
/* A62220 80241850 00000000 */   nop
.L80241854:
/* A62224 80241854 2402000E */  addiu     $v0, $zero, 0xe
/* A62228 80241858 1062003F */  beq       $v1, $v0, .L80241958
/* A6222C 8024185C 0062102A */   slt      $v0, $v1, $v0
/* A62230 80241860 14400038 */  bnez      $v0, .L80241944
/* A62234 80241864 0260202D */   daddu    $a0, $s3, $zero
/* A62238 80241868 2402000F */  addiu     $v0, $zero, 0xf
/* A6223C 8024186C 10620040 */  beq       $v1, $v0, .L80241970
/* A62240 80241870 24020063 */   addiu    $v0, $zero, 0x63
/* A62244 80241874 10620043 */  beq       $v1, $v0, .L80241984
/* A62248 80241878 00000000 */   nop
/* A6224C 8024187C 08090663 */  j         .L8024198C
/* A62250 80241880 00000000 */   nop
.L80241884:
/* A62254 80241884 0280282D */  daddu     $a1, $s4, $zero
/* A62258 80241888 0C012568 */  jal       func_800495A0
/* A6225C 8024188C 02A0302D */   daddu    $a2, $s5, $zero
/* A62260 80241890 96220086 */  lhu       $v0, 0x86($s1)
/* A62264 80241894 A64200A8 */  sh        $v0, 0xa8($s2)
.L80241898:
/* A62268 80241898 0260202D */  daddu     $a0, $s3, $zero
/* A6226C 8024189C 0280282D */  daddu     $a1, $s4, $zero
/* A62270 802418A0 0C0125AE */  jal       func_800496B8
/* A62274 802418A4 02A0302D */   daddu    $a2, $s5, $zero
/* A62278 802418A8 08090663 */  j         .L8024198C
/* A6227C 802418AC 00000000 */   nop
.L802418B0:
/* A62280 802418B0 0260202D */  daddu     $a0, $s3, $zero
/* A62284 802418B4 0280282D */  daddu     $a1, $s4, $zero
/* A62288 802418B8 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* A6228C 802418BC 02A0302D */   daddu    $a2, $s5, $zero
/* A62290 802418C0 8E230088 */  lw        $v1, 0x88($s1)
/* A62294 802418C4 24020006 */  addiu     $v0, $zero, 6
/* A62298 802418C8 14620014 */  bne       $v1, $v0, .L8024191C
/* A6229C 802418CC 0260202D */   daddu    $a0, $s3, $zero
/* A622A0 802418D0 0C00A67F */  jal       rand_int
/* A622A4 802418D4 24040064 */   addiu    $a0, $zero, 0x64
/* A622A8 802418D8 28420021 */  slti      $v0, $v0, 0x21
/* A622AC 802418DC 5040000F */  beql      $v0, $zero, .L8024191C
/* A622B0 802418E0 0260202D */   daddu    $a0, $s3, $zero
/* A622B4 802418E4 8E22008C */  lw        $v0, 0x8c($s1)
/* A622B8 802418E8 10400005 */  beqz      $v0, .L80241900
/* A622BC 802418EC 3C020055 */   lui      $v0, 0x55
/* A622C0 802418F0 3442002F */  ori       $v0, $v0, 0x2f
/* A622C4 802418F4 AE20008C */  sw        $zero, 0x8c($s1)
/* A622C8 802418F8 08090643 */  j         .L8024190C
/* A622CC 802418FC A22000B5 */   sb       $zero, 0xb5($s1)
.L80241900:
/* A622D0 80241900 3442002E */  ori       $v0, $v0, 0x2e
/* A622D4 80241904 AE30008C */  sw        $s0, 0x8c($s1)
/* A622D8 80241908 A23000B5 */  sb        $s0, 0xb5($s1)
.L8024190C:
/* A622DC 8024190C AE420028 */  sw        $v0, 0x28($s2)
/* A622E0 80241910 24020007 */  addiu     $v0, $zero, 7
/* A622E4 80241914 0809067E */  j         L802419F8_A623C8
/* A622E8 80241918 AE220090 */   sw       $v0, 0x90($s1)
.L8024191C:
/* A622EC 8024191C 0280282D */  daddu     $a1, $s4, $zero
/* A622F0 80241920 0C012701 */  jal       func_80049C04
/* A622F4 80241924 02A0302D */   daddu    $a2, $s5, $zero
/* A622F8 80241928 08090663 */  j         .L8024198C
/* A622FC 8024192C 00000000 */   nop
.L80241930:
/* A62300 80241930 0260202D */  daddu     $a0, $s3, $zero
/* A62304 80241934 0280282D */  daddu     $a1, $s4, $zero
/* A62308 80241938 0C090493 */  jal       kpa_50_set_script_owner_npc_anim
/* A6230C 8024193C 02A0302D */   daddu    $a2, $s5, $zero
/* A62310 80241940 0260202D */  daddu     $a0, $s3, $zero
.L80241944:
/* A62314 80241944 0280282D */  daddu     $a1, $s4, $zero
/* A62318 80241948 0C0904B2 */  jal       kpa_50_UnkDistFunc
/* A6231C 8024194C 02A0302D */   daddu    $a2, $s5, $zero
/* A62320 80241950 08090663 */  j         .L8024198C
/* A62324 80241954 00000000 */   nop
.L80241958:
/* A62328 80241958 0260202D */  daddu     $a0, $s3, $zero
/* A6232C 8024195C 0280282D */  daddu     $a1, $s4, $zero
/* A62330 80241960 0C0904FF */  jal       kpa_50_UnkNpcAIFunc12
/* A62334 80241964 02A0302D */   daddu    $a2, $s5, $zero
/* A62338 80241968 08090663 */  j         .L8024198C
/* A6233C 8024196C 00000000 */   nop
.L80241970:
/* A62340 80241970 0280282D */  daddu     $a1, $s4, $zero
/* A62344 80241974 0C090558 */  jal       kpa_50_set_script_owner_npc_col_height
/* A62348 80241978 02A0302D */   daddu    $a2, $s5, $zero
/* A6234C 8024197C 08090663 */  j         .L8024198C
/* A62350 80241980 00000000 */   nop
.L80241984:
/* A62354 80241984 0C0129CF */  jal       func_8004A73C
/* A62358 80241988 0260202D */   daddu    $a0, $s3, $zero
.L8024198C:
/* A6235C 8024198C 8E230088 */  lw        $v1, 0x88($s1)
/* A62360 80241990 24020006 */  addiu     $v0, $zero, 6
/* A62364 80241994 14620019 */  bne       $v1, $v0, .L802419FC
/* A62368 80241998 0000102D */   daddu    $v0, $zero, $zero
/* A6236C 8024199C 8E22008C */  lw        $v0, 0x8c($s1)
/* A62370 802419A0 10400003 */  beqz      $v0, .L802419B0
/* A62374 802419A4 24020001 */   addiu    $v0, $zero, 1
/* A62378 802419A8 0809066D */  j         .L802419B4
/* A6237C 802419AC A22200B5 */   sb       $v0, 0xb5($s1)
.L802419B0:
/* A62380 802419B0 A22000B5 */  sb        $zero, 0xb5($s1)
.L802419B4:
/* A62384 802419B4 8E22008C */  lw        $v0, 0x8c($s1)
/* A62388 802419B8 1040000F */  beqz      $v0, L802419F8_A623C8
/* A6238C 802419BC 3C03FFAA */   lui      $v1, 0xffaa
/* A62390 802419C0 8E420028 */  lw        $v0, 0x28($s2)
/* A62394 802419C4 3463FFFC */  ori       $v1, $v1, 0xfffc
/* A62398 802419C8 00431821 */  addu      $v1, $v0, $v1
/* A6239C 802419CC 2C620015 */  sltiu     $v0, $v1, 0x15
/* A623A0 802419D0 10400009 */  beqz      $v0, L802419F8_A623C8
/* A623A4 802419D4 00031080 */   sll      $v0, $v1, 2
/* A623A8 802419D8 3C018024 */  lui       $at, %hi(jtbl_80243660_A64030)
/* A623AC 802419DC 00220821 */  addu      $at, $at, $v0
/* A623B0 802419E0 8C223660 */  lw        $v0, %lo(jtbl_80243660_A64030)($at)
/* A623B4 802419E4 00400008 */  jr        $v0
/* A623B8 802419E8 00000000 */   nop
dlabel L802419EC_A623BC
/* A623BC 802419EC 8E420028 */  lw        $v0, 0x28($s2)
/* A623C0 802419F0 24420001 */  addiu     $v0, $v0, 1
/* A623C4 802419F4 AE420028 */  sw        $v0, 0x28($s2)
dlabel L802419F8_A623C8
/* A623C8 802419F8 0000102D */  daddu     $v0, $zero, $zero
.L802419FC:
/* A623CC 802419FC 8FBF0068 */  lw        $ra, 0x68($sp)
/* A623D0 80241A00 8FB50064 */  lw        $s5, 0x64($sp)
/* A623D4 80241A04 8FB40060 */  lw        $s4, 0x60($sp)
/* A623D8 80241A08 8FB3005C */  lw        $s3, 0x5c($sp)
/* A623DC 80241A0C 8FB20058 */  lw        $s2, 0x58($sp)
/* A623E0 80241A10 8FB10054 */  lw        $s1, 0x54($sp)
/* A623E4 80241A14 8FB00050 */  lw        $s0, 0x50($sp)
/* A623E8 80241A18 03E00008 */  jr        $ra
/* A623EC 80241A1C 27BD0070 */   addiu    $sp, $sp, 0x70
