.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80145EC0
/* DC5C0 80145EC0 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* DC5C4 80145EC4 AFB00080 */  sw        $s0, 0x80($sp)
/* DC5C8 80145EC8 0000802D */  daddu     $s0, $zero, $zero
/* DC5CC 80145ECC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* DC5D0 80145ED0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* DC5D4 80145ED4 3C04800B */  lui       $a0, %hi(gCameras)
/* DC5D8 80145ED8 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* DC5DC 80145EDC AFBF00A4 */  sw        $ra, 0xa4($sp)
/* DC5E0 80145EE0 AFBE00A0 */  sw        $fp, 0xa0($sp)
/* DC5E4 80145EE4 AFB7009C */  sw        $s7, 0x9c($sp)
/* DC5E8 80145EE8 AFB60098 */  sw        $s6, 0x98($sp)
/* DC5EC 80145EEC AFB50094 */  sw        $s5, 0x94($sp)
/* DC5F0 80145EF0 AFB40090 */  sw        $s4, 0x90($sp)
/* DC5F4 80145EF4 AFB3008C */  sw        $s3, 0x8c($sp)
/* DC5F8 80145EF8 AFB20088 */  sw        $s2, 0x88($sp)
/* DC5FC 80145EFC AFB10084 */  sw        $s1, 0x84($sp)
/* DC600 80145F00 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* DC604 80145F04 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* DC608 80145F08 00031080 */  sll       $v0, $v1, 2
/* DC60C 80145F0C 00431021 */  addu      $v0, $v0, $v1
/* DC610 80145F10 00021080 */  sll       $v0, $v0, 2
/* DC614 80145F14 00431023 */  subu      $v0, $v0, $v1
/* DC618 80145F18 000218C0 */  sll       $v1, $v0, 3
/* DC61C 80145F1C 00431021 */  addu      $v0, $v0, $v1
/* DC620 80145F20 000210C0 */  sll       $v0, $v0, 3
/* DC624 80145F24 0C046EE9 */  jal       is_world_fog_enabled
/* DC628 80145F28 0044A821 */   addu     $s5, $v0, $a0
/* DC62C 80145F2C 1040000A */  beqz      $v0, .L80145F58
/* DC630 80145F30 27A40018 */   addiu    $a0, $sp, 0x18
/* DC634 80145F34 27A5001C */  addiu     $a1, $sp, 0x1c
/* DC638 80145F38 27A60020 */  addiu     $a2, $sp, 0x20
/* DC63C 80145F3C 0C046EF6 */  jal       get_world_fog_color
/* DC640 80145F40 27A70024 */   addiu    $a3, $sp, 0x24
/* DC644 80145F44 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DC648 80145F48 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DC64C 80145F4C 9442015C */  lhu       $v0, 0x15c($v0)
/* DC650 80145F50 24100001 */  addiu     $s0, $zero, 1
/* DC654 80145F54 AFA20024 */  sw        $v0, 0x24($sp)
.L80145F58:
/* DC658 80145F58 3C028015 */  lui       $v0, %hi(D_801512F0)
/* DC65C 80145F5C 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* DC660 80145F60 90420000 */  lbu       $v0, ($v0)
/* DC664 80145F64 0440000C */  bltz      $v0, .L80145F98
/* DC668 80145F68 28420002 */   slti     $v0, $v0, 2
/* DC66C 80145F6C 1040000A */  beqz      $v0, .L80145F98
/* DC670 80145F70 27A40028 */   addiu    $a0, $sp, 0x28
/* DC674 80145F74 27A50029 */  addiu     $a1, $sp, 0x29
/* DC678 80145F78 27A6002A */  addiu     $a2, $sp, 0x2a
/* DC67C 80145F7C 0C046FA0 */  jal       get_background_color_blend
/* DC680 80145F80 27A7002B */   addiu    $a3, $sp, 0x2b
/* DC684 80145F84 93A2002B */  lbu       $v0, 0x2b($sp)
/* DC688 80145F88 54400020 */  bnel      $v0, $zero, .L8014600C
/* DC68C 80145F8C 36100002 */   ori      $s0, $s0, 2
/* DC690 80145F90 08051804 */  j         .L80146010
/* DC694 80145F94 3203FFFF */   andi     $v1, $s0, 0xffff
.L80145F98:
/* DC698 80145F98 27A40028 */  addiu     $a0, $sp, 0x28
/* DC69C 80145F9C 27A50029 */  addiu     $a1, $sp, 0x29
/* DC6A0 80145FA0 27A6002A */  addiu     $a2, $sp, 0x2a
/* DC6A4 80145FA4 27A7002C */  addiu     $a3, $sp, 0x2c
/* DC6A8 80145FA8 27A2002D */  addiu     $v0, $sp, 0x2d
/* DC6AC 80145FAC AFA20010 */  sw        $v0, 0x10($sp)
/* DC6B0 80145FB0 27A2002E */  addiu     $v0, $sp, 0x2e
/* DC6B4 80145FB4 0C046FF5 */  jal       func_8011BFD4
/* DC6B8 80145FB8 AFA20014 */   sw       $v0, 0x14($sp)
/* DC6BC 80145FBC 93A40028 */  lbu       $a0, 0x28($sp)
/* DC6C0 80145FC0 240200FF */  addiu     $v0, $zero, 0xff
/* DC6C4 80145FC4 54820011 */  bnel      $a0, $v0, .L8014600C
/* DC6C8 80145FC8 36100004 */   ori      $s0, $s0, 4
/* DC6CC 80145FCC 93A30029 */  lbu       $v1, 0x29($sp)
/* DC6D0 80145FD0 5464000E */  bnel      $v1, $a0, .L8014600C
/* DC6D4 80145FD4 36100004 */   ori      $s0, $s0, 4
/* DC6D8 80145FD8 93A2002A */  lbu       $v0, 0x2a($sp)
/* DC6DC 80145FDC 5443000B */  bnel      $v0, $v1, .L8014600C
/* DC6E0 80145FE0 36100004 */   ori      $s0, $s0, 4
/* DC6E4 80145FE4 93A2002C */  lbu       $v0, 0x2c($sp)
/* DC6E8 80145FE8 54400008 */  bnel      $v0, $zero, .L8014600C
/* DC6EC 80145FEC 36100004 */   ori      $s0, $s0, 4
/* DC6F0 80145FF0 93A2002D */  lbu       $v0, 0x2d($sp)
/* DC6F4 80145FF4 54400005 */  bnel      $v0, $zero, .L8014600C
/* DC6F8 80145FF8 36100004 */   ori      $s0, $s0, 4
/* DC6FC 80145FFC 93A2002E */  lbu       $v0, 0x2e($sp)
/* DC700 80146000 10400003 */  beqz      $v0, .L80146010
/* DC704 80146004 3203FFFF */   andi     $v1, $s0, 0xffff
/* DC708 80146008 36100004 */  ori       $s0, $s0, 4
.L8014600C:
/* DC70C 8014600C 3203FFFF */  andi      $v1, $s0, 0xffff
.L80146010:
/* DC710 80146010 2C620005 */  sltiu     $v0, $v1, 5
/* DC714 80146014 10400067 */  beqz      $v0, .L801461B4
/* DC718 80146018 00031080 */   sll      $v0, $v1, 2
/* DC71C 8014601C 3C018015 */  lui       $at, %hi(jtbl_80151220)
/* DC720 80146020 00220821 */  addu      $at, $at, $v0
/* DC724 80146024 8C221220 */  lw        $v0, %lo(jtbl_80151220)($at)
/* DC728 80146028 00400008 */  jr        $v0
/* DC72C 8014602C 00000000 */   nop
glabel L80146030_DC730
/* DC730 80146030 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* DC734 80146034 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* DC738 80146038 94620148 */  lhu       $v0, 0x148($v1)
/* DC73C 8014603C 0805186C */  j         .L801461B0
/* DC740 80146040 3042FFFD */   andi     $v0, $v0, 0xfffd
glabel L80146044_DC744
/* DC744 80146044 3C078007 */  lui       $a3, %hi(gGameStatusPtr)
/* DC748 80146048 8CE7419C */  lw        $a3, %lo(gGameStatusPtr)($a3)
/* DC74C 8014604C 93A60028 */  lbu       $a2, 0x28($sp)
/* DC750 80146050 93A30029 */  lbu       $v1, 0x29($sp)
/* DC754 80146054 93A4002A */  lbu       $a0, 0x2a($sp)
/* DC758 80146058 93A5002B */  lbu       $a1, 0x2b($sp)
/* DC75C 8014605C 94E20148 */  lhu       $v0, 0x148($a3)
/* DC760 80146060 AFA60018 */  sw        $a2, 0x18($sp)
/* DC764 80146064 AFA3001C */  sw        $v1, 0x1c($sp)
/* DC768 80146068 AFA40020 */  sw        $a0, 0x20($sp)
/* DC76C 8014606C AFA50024 */  sw        $a1, 0x24($sp)
/* DC770 80146070 34420002 */  ori       $v0, $v0, 2
/* DC774 80146074 0805186D */  j         .L801461B4
/* DC778 80146078 A4E20148 */   sh       $v0, 0x148($a3)
glabel L8014607C_DC77C
/* DC77C 8014607C 240700FF */  addiu     $a3, $zero, 0xff
/* DC780 80146080 93A8002B */  lbu       $t0, 0x2b($sp)
/* DC784 80146084 8FA20018 */  lw        $v0, 0x18($sp)
/* DC788 80146088 00E83823 */  subu      $a3, $a3, $t0
/* DC78C 8014608C 00470018 */  mult      $v0, $a3
/* DC790 80146090 00001812 */  mflo      $v1
/* DC794 80146094 93A20028 */  lbu       $v0, 0x28($sp)
/* DC798 80146098 00000000 */  nop
/* DC79C 8014609C 00480018 */  mult      $v0, $t0
/* DC7A0 801460A0 3C098080 */  lui       $t1, 0x8080
/* DC7A4 801460A4 00005012 */  mflo      $t2
/* DC7A8 801460A8 35298081 */  ori       $t1, $t1, 0x8081
/* DC7AC 801460AC 006A3021 */  addu      $a2, $v1, $t2
/* DC7B0 801460B0 00C90018 */  mult      $a2, $t1
/* DC7B4 801460B4 00005810 */  mfhi      $t3
/* DC7B8 801460B8 8FA2001C */  lw        $v0, 0x1c($sp)
/* DC7BC 801460BC 00000000 */  nop
/* DC7C0 801460C0 00470018 */  mult      $v0, $a3
/* DC7C4 801460C4 00002012 */  mflo      $a0
/* DC7C8 801460C8 93A20029 */  lbu       $v0, 0x29($sp)
/* DC7CC 801460CC 00000000 */  nop
/* DC7D0 801460D0 00480018 */  mult      $v0, $t0
/* DC7D4 801460D4 00006012 */  mflo      $t4
/* DC7D8 801460D8 8FA20020 */  lw        $v0, 0x20($sp)
/* DC7DC 801460DC 00000000 */  nop
/* DC7E0 801460E0 00470018 */  mult      $v0, $a3
/* DC7E4 801460E4 00005012 */  mflo      $t2
/* DC7E8 801460E8 93A2002A */  lbu       $v0, 0x2a($sp)
/* DC7EC 801460EC 00000000 */  nop
/* DC7F0 801460F0 00480018 */  mult      $v0, $t0
/* DC7F4 801460F4 00002812 */  mflo      $a1
/* DC7F8 801460F8 008C2021 */  addu      $a0, $a0, $t4
/* DC7FC 801460FC 00000000 */  nop
/* DC800 80146100 00890018 */  mult      $a0, $t1
/* DC804 80146104 00006010 */  mfhi      $t4
/* DC808 80146108 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* DC80C 8014610C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* DC810 80146110 01452821 */  addu      $a1, $t2, $a1
/* DC814 80146114 00A90018 */  mult      $a1, $t1
/* DC818 80146118 94620148 */  lhu       $v0, 0x148($v1)
/* DC81C 8014611C 34420002 */  ori       $v0, $v0, 2
/* DC820 80146120 A4620148 */  sh        $v0, 0x148($v1)
/* DC824 80146124 00005010 */  mfhi      $t2
/* DC828 80146128 8FA30024 */  lw        $v1, 0x24($sp)
/* DC82C 8014612C 00000000 */  nop
/* DC830 80146130 00670018 */  mult      $v1, $a3
/* DC834 80146134 01661021 */  addu      $v0, $t3, $a2
/* DC838 80146138 000211C3 */  sra       $v0, $v0, 7
/* DC83C 8014613C 000637C3 */  sra       $a2, $a2, 0x1f
/* DC840 80146140 00461023 */  subu      $v0, $v0, $a2
/* DC844 80146144 00001812 */  mflo      $v1
/* DC848 80146148 AFA20018 */  sw        $v0, 0x18($sp)
/* DC84C 8014614C 01841021 */  addu      $v0, $t4, $a0
/* DC850 80146150 01080018 */  mult      $t0, $t0
/* DC854 80146154 000211C3 */  sra       $v0, $v0, 7
/* DC858 80146158 000427C3 */  sra       $a0, $a0, 0x1f
/* DC85C 8014615C 00441023 */  subu      $v0, $v0, $a0
/* DC860 80146160 AFA2001C */  sw        $v0, 0x1c($sp)
/* DC864 80146164 00004012 */  mflo      $t0
/* DC868 80146168 01451021 */  addu      $v0, $t2, $a1
/* DC86C 8014616C 00681821 */  addu      $v1, $v1, $t0
/* DC870 80146170 00690018 */  mult      $v1, $t1
/* DC874 80146174 000211C3 */  sra       $v0, $v0, 7
/* DC878 80146178 00052FC3 */  sra       $a1, $a1, 0x1f
/* DC87C 8014617C 00451023 */  subu      $v0, $v0, $a1
/* DC880 80146180 AFA20020 */  sw        $v0, 0x20($sp)
/* DC884 80146184 00004010 */  mfhi      $t0
/* DC888 80146188 01031021 */  addu      $v0, $t0, $v1
/* DC88C 8014618C 000211C3 */  sra       $v0, $v0, 7
/* DC890 80146190 00031FC3 */  sra       $v1, $v1, 0x1f
/* DC894 80146194 00431023 */  subu      $v0, $v0, $v1
/* DC898 80146198 0805186D */  j         .L801461B4
/* DC89C 8014619C AFA20024 */   sw       $v0, 0x24($sp)
glabel L801461A0_DC8A0
/* DC8A0 801461A0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* DC8A4 801461A4 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* DC8A8 801461A8 94620148 */  lhu       $v0, 0x148($v1)
/* DC8AC 801461AC 34420002 */  ori       $v0, $v0, 2
.L801461B0:
/* DC8B0 801461B0 A4620148 */  sh        $v0, 0x148($v1)
.L801461B4:
/* DC8B4 801461B4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DC8B8 801461B8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DC8BC 801461BC 94420148 */  lhu       $v0, 0x148($v0)
/* DC8C0 801461C0 30420002 */  andi      $v0, $v0, 2
/* DC8C4 801461C4 10400077 */  beqz      $v0, .L801463A4
/* DC8C8 801461C8 00000000 */   nop
/* DC8CC 801461CC 3C028015 */  lui       $v0, %hi(D_801512F0)
/* DC8D0 801461D0 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* DC8D4 801461D4 90420000 */  lbu       $v0, ($v0)
/* DC8D8 801461D8 04400038 */  bltz      $v0, .L801462BC
/* DC8DC 801461DC 28420002 */   slti     $v0, $v0, 2
/* DC8E0 801461E0 10400036 */  beqz      $v0, .L801462BC
/* DC8E4 801461E4 240200FF */   addiu    $v0, $zero, 0xff
/* DC8E8 801461E8 8FA30024 */  lw        $v1, 0x24($sp)
/* DC8EC 801461EC 1462000B */  bne       $v1, $v0, .L8014621C
/* DC8F0 801461F0 0000982D */   daddu    $s3, $zero, $zero
/* DC8F4 801461F4 24030001 */  addiu     $v1, $zero, 1
/* DC8F8 801461F8 0040982D */  daddu     $s3, $v0, $zero
/* DC8FC 801461FC 3C028016 */  lui       $v0, %hi(D_8015959E)
/* DC900 80146200 2442959E */  addiu     $v0, $v0, %lo(D_8015959E)
.L80146204:
/* DC904 80146204 A4430000 */  sh        $v1, ($v0)
/* DC908 80146208 2673FFFF */  addiu     $s3, $s3, -1
/* DC90C 8014620C 0661FFFD */  bgez      $s3, .L80146204
/* DC910 80146210 2442FFFE */   addiu    $v0, $v0, -2
/* DC914 80146214 080518E9 */  j         .L801463A4
/* DC918 80146218 00000000 */   nop
.L8014621C:
/* DC91C 8014621C 3C148016 */  lui       $s4, %hi(D_801593A0)
/* DC920 80146220 269493A0 */  addiu     $s4, $s4, %lo(D_801593A0)
.L80146224:
/* DC924 80146224 00131840 */  sll       $v1, $s3, 1
/* DC928 80146228 26730001 */  addiu     $s3, $s3, 1
/* DC92C 8014622C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DC930 80146230 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DC934 80146234 8FA60024 */  lw        $a2, 0x24($sp)
/* DC938 80146238 8C420158 */  lw        $v0, 0x158($v0)
/* DC93C 8014623C 8FA50020 */  lw        $a1, 0x20($sp)
/* DC940 80146240 00621821 */  addu      $v1, $v1, $v0
/* DC944 80146244 94700000 */  lhu       $s0, ($v1)
/* DC948 80146248 000528C3 */  sra       $a1, $a1, 3
/* DC94C 8014624C 00102042 */  srl       $a0, $s0, 1
/* DC950 80146250 0C0517A6 */  jal       func_80145E98
/* DC954 80146254 3084001F */   andi     $a0, $a0, 0x1f
/* DC958 80146258 0040902D */  daddu     $s2, $v0, $zero
/* DC95C 8014625C 00102182 */  srl       $a0, $s0, 6
/* DC960 80146260 3084001F */  andi      $a0, $a0, 0x1f
/* DC964 80146264 8FA5001C */  lw        $a1, 0x1c($sp)
/* DC968 80146268 8FA60024 */  lw        $a2, 0x24($sp)
/* DC96C 8014626C 0C0517A6 */  jal       func_80145E98
/* DC970 80146270 000528C3 */   sra      $a1, $a1, 3
/* DC974 80146274 0040882D */  daddu     $s1, $v0, $zero
/* DC978 80146278 001022C2 */  srl       $a0, $s0, 0xb
/* DC97C 8014627C 8FA50018 */  lw        $a1, 0x18($sp)
/* DC980 80146280 8FA60024 */  lw        $a2, 0x24($sp)
/* DC984 80146284 0C0517A6 */  jal       func_80145E98
/* DC988 80146288 000528C3 */   sra      $a1, $a1, 3
/* DC98C 8014628C 00121840 */  sll       $v1, $s2, 1
/* DC990 80146290 00112180 */  sll       $a0, $s1, 6
/* DC994 80146294 00641825 */  or        $v1, $v1, $a0
/* DC998 80146298 000212C0 */  sll       $v0, $v0, 0xb
/* DC99C 8014629C 00621825 */  or        $v1, $v1, $v0
/* DC9A0 801462A0 34630001 */  ori       $v1, $v1, 1
/* DC9A4 801462A4 A6830000 */  sh        $v1, ($s4)
/* DC9A8 801462A8 2A620100 */  slti      $v0, $s3, 0x100
/* DC9AC 801462AC 1440FFDD */  bnez      $v0, .L80146224
/* DC9B0 801462B0 26940002 */   addiu    $s4, $s4, 2
/* DC9B4 801462B4 080518E9 */  j         .L801463A4
/* DC9B8 801462B8 00000000 */   nop
.L801462BC:
/* DC9BC 801462BC 0000982D */  daddu     $s3, $zero, $zero
/* DC9C0 801462C0 3C058016 */  lui       $a1, %hi(D_801593A0)
/* DC9C4 801462C4 24A593A0 */  addiu     $a1, $a1, %lo(D_801593A0)
/* DC9C8 801462C8 3C0C8007 */  lui       $t4, %hi(gGameStatusPtr)
/* DC9CC 801462CC 8D8C419C */  lw        $t4, %lo(gGameStatusPtr)($t4)
/* DC9D0 801462D0 93AB002A */  lbu       $t3, 0x2a($sp)
/* DC9D4 801462D4 93AA0029 */  lbu       $t2, 0x29($sp)
/* DC9D8 801462D8 93A2002E */  lbu       $v0, 0x2e($sp)
/* DC9DC 801462DC 93A90028 */  lbu       $t1, 0x28($sp)
/* DC9E0 801462E0 93A3002C */  lbu       $v1, 0x2c($sp)
/* DC9E4 801462E4 000240C2 */  srl       $t0, $v0, 3
/* DC9E8 801462E8 93A2002D */  lbu       $v0, 0x2d($sp)
/* DC9EC 801462EC 000330C2 */  srl       $a2, $v1, 3
/* DC9F0 801462F0 000238C2 */  srl       $a3, $v0, 3
.L801462F4:
/* DC9F4 801462F4 8D830158 */  lw        $v1, 0x158($t4)
/* DC9F8 801462F8 00131040 */  sll       $v0, $s3, 1
/* DC9FC 801462FC 00431021 */  addu      $v0, $v0, $v1
/* DCA00 80146300 94430000 */  lhu       $v1, ($v0)
/* DCA04 80146304 00031042 */  srl       $v0, $v1, 1
/* DCA08 80146308 3042001F */  andi      $v0, $v0, 0x1f
/* DCA0C 8014630C 004B0018 */  mult      $v0, $t3
/* DCA10 80146310 00002012 */  mflo      $a0
/* DCA14 80146314 00031182 */  srl       $v0, $v1, 6
/* DCA18 80146318 3042001F */  andi      $v0, $v0, 0x1f
/* DCA1C 8014631C 004A0018 */  mult      $v0, $t2
/* DCA20 80146320 00006812 */  mflo      $t5
/* DCA24 80146324 00031AC2 */  srl       $v1, $v1, 0xb
/* DCA28 80146328 00000000 */  nop
/* DCA2C 8014632C 00690018 */  mult      $v1, $t1
/* DCA30 80146330 00041203 */  sra       $v0, $a0, 8
/* DCA34 80146334 01029021 */  addu      $s2, $t0, $v0
/* DCA38 80146338 000D1203 */  sra       $v0, $t5, 8
/* DCA3C 8014633C 00E28821 */  addu      $s1, $a3, $v0
/* DCA40 80146340 00001812 */  mflo      $v1
/* DCA44 80146344 00031203 */  sra       $v0, $v1, 8
/* DCA48 80146348 00C22021 */  addu      $a0, $a2, $v0
/* DCA4C 8014634C 2E420020 */  sltiu     $v0, $s2, 0x20
/* DCA50 80146350 50400001 */  beql      $v0, $zero, .L80146358
/* DCA54 80146354 2412001F */   addiu    $s2, $zero, 0x1f
.L80146358:
/* DCA58 80146358 3222FFFF */  andi      $v0, $s1, 0xffff
/* DCA5C 8014635C 2C420020 */  sltiu     $v0, $v0, 0x20
/* DCA60 80146360 50400001 */  beql      $v0, $zero, .L80146368
/* DCA64 80146364 2411001F */   addiu    $s1, $zero, 0x1f
.L80146368:
/* DCA68 80146368 3082FFFF */  andi      $v0, $a0, 0xffff
/* DCA6C 8014636C 2C420020 */  sltiu     $v0, $v0, 0x20
/* DCA70 80146370 50400001 */  beql      $v0, $zero, .L80146378
/* DCA74 80146374 2404001F */   addiu    $a0, $zero, 0x1f
.L80146378:
/* DCA78 80146378 00121040 */  sll       $v0, $s2, 1
/* DCA7C 8014637C 00111980 */  sll       $v1, $s1, 6
/* DCA80 80146380 00431025 */  or        $v0, $v0, $v1
/* DCA84 80146384 00041AC0 */  sll       $v1, $a0, 0xb
/* DCA88 80146388 00431025 */  or        $v0, $v0, $v1
/* DCA8C 8014638C 34420001 */  ori       $v0, $v0, 1
/* DCA90 80146390 A4A20000 */  sh        $v0, ($a1)
/* DCA94 80146394 26730001 */  addiu     $s3, $s3, 1
/* DCA98 80146398 2A620100 */  slti      $v0, $s3, 0x100
/* DCA9C 8014639C 1440FFD5 */  bnez      $v0, .L801462F4
/* DCAA0 801463A0 24A50002 */   addiu    $a1, $a1, 2
.L801463A4:
/* DCAA4 801463A4 C6AC0084 */  lwc1      $f12, 0x84($s5)
/* DCAA8 801463A8 0C00A6C9 */  jal       clamp_angle
/* DCAAC 801463AC 46006307 */   neg.s    $f12, $f12
/* DCAB0 801463B0 46000586 */  mov.s     $f22, $f0
/* DCAB4 801463B4 0C00A8BB */  jal       sin_deg
/* DCAB8 801463B8 4600B306 */   mov.s    $f12, $f22
/* DCABC 801463BC 4600B306 */  mov.s     $f12, $f22
/* DCAC0 801463C0 0C00A8D4 */  jal       cos_deg
/* DCAC4 801463C4 46000506 */   mov.s    $f20, $f0
/* DCAC8 801463C8 C6A20048 */  lwc1      $f2, 0x48($s5)
/* DCACC 801463CC 46020002 */  mul.s     $f0, $f0, $f2
/* DCAD0 801463D0 00000000 */  nop
/* DCAD4 801463D4 C6A20050 */  lwc1      $f2, 0x50($s5)
/* DCAD8 801463D8 4602A502 */  mul.s     $f20, $f20, $f2
/* DCADC 801463DC 00000000 */  nop
/* DCAE0 801463E0 46140001 */  sub.s     $f0, $f0, $f20
/* DCAE4 801463E4 C6A2050C */  lwc1      $f2, 0x50c($s5)
/* DCAE8 801463E8 46020000 */  add.s     $f0, $f0, $f2
/* DCAEC 801463EC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DCAF0 801463F0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DCAF4 801463F4 3C013E80 */  lui       $at, 0x3e80
/* DCAF8 801463F8 44811000 */  mtc1      $at, $f2
/* DCAFC 801463FC 46000007 */  neg.s     $f0, $f0
/* DCB00 80146400 46020102 */  mul.s     $f4, $f0, $f2
/* DCB04 80146404 00000000 */  nop
/* DCB08 80146408 8442014E */  lh        $v0, 0x14e($v0)
/* DCB0C 8014640C 44820000 */  mtc1      $v0, $f0
/* DCB10 80146410 00000000 */  nop
/* DCB14 80146414 46800020 */  cvt.s.w   $f0, $f0
/* DCB18 80146418 46160002 */  mul.s     $f0, $f0, $f22
/* DCB1C 8014641C 00000000 */  nop
/* DCB20 80146420 3C013C36 */  lui       $at, 0x3c36
/* DCB24 80146424 34210B61 */  ori       $at, $at, 0xb61
/* DCB28 80146428 44811000 */  mtc1      $at, $f2
/* DCB2C 8014642C 00000000 */  nop
/* DCB30 80146430 46020002 */  mul.s     $f0, $f0, $f2
/* DCB34 80146434 00000000 */  nop
/* DCB38 80146438 3C028016 */  lui       $v0, %hi(D_801595A0)
/* DCB3C 8014643C 244295A0 */  addiu     $v0, $v0, %lo(D_801595A0)
/* DCB40 80146440 46002100 */  add.s     $f4, $f4, $f0
/* DCB44 80146444 C4460000 */  lwc1      $f6, ($v0)
/* DCB48 80146448 46062001 */  sub.s     $f0, $f4, $f6
/* DCB4C 8014644C 3C013E99 */  lui       $at, 0x3e99
/* DCB50 80146450 3421999A */  ori       $at, $at, 0x999a
/* DCB54 80146454 44811000 */  mtc1      $at, $f2
/* DCB58 80146458 46000005 */  abs.s     $f0, $f0
/* DCB5C 8014645C 4602003C */  c.lt.s    $f0, $f2
/* DCB60 80146460 00000000 */  nop
/* DCB64 80146464 45020002 */  bc1fl     .L80146470
/* DCB68 80146468 E4440000 */   swc1     $f4, ($v0)
/* DCB6C 8014646C 46003106 */  mov.s     $f4, $f6
.L80146470:
/* DCB70 80146470 44801000 */  mtc1      $zero, $f2
/* DCB74 80146474 00000000 */  nop
/* DCB78 80146478 4602203C */  c.lt.s    $f4, $f2
/* DCB7C 8014647C 00000000 */  nop
/* DCB80 80146480 4500000D */  bc1f      .L801464B8
/* DCB84 80146484 00000000 */   nop
/* DCB88 80146488 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DCB8C 8014648C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DCB90 80146490 8442014E */  lh        $v0, 0x14e($v0)
/* DCB94 80146494 00021140 */  sll       $v0, $v0, 5
/* DCB98 80146498 44820000 */  mtc1      $v0, $f0
/* DCB9C 8014649C 00000000 */  nop
/* DCBA0 801464A0 46800020 */  cvt.s.w   $f0, $f0
/* DCBA4 801464A4 46002100 */  add.s     $f4, $f4, $f0
.L801464A8:
/* DCBA8 801464A8 4602203C */  c.lt.s    $f4, $f2
/* DCBAC 801464AC 00000000 */  nop
/* DCBB0 801464B0 4503FFFD */  bc1tl     .L801464A8
/* DCBB4 801464B4 46002100 */   add.s    $f4, $f4, $f0
.L801464B8:
/* DCBB8 801464B8 3C0E8007 */  lui       $t6, %hi(gGameStatusPtr)
/* DCBBC 801464BC 8DCE419C */  lw        $t6, %lo(gGameStatusPtr)($t6)
/* DCBC0 801464C0 4600220D */  trunc.w.s $f8, $f4
/* DCBC4 801464C4 44024000 */  mfc1      $v0, $f8
/* DCBC8 801464C8 85C3014E */  lh        $v1, 0x14e($t6)
/* DCBCC 801464CC 3C05E300 */  lui       $a1, 0xe300
/* DCBD0 801464D0 14600002 */  bnez      $v1, .L801464DC
/* DCBD4 801464D4 0043001A */   div      $zero, $v0, $v1
/* DCBD8 801464D8 0007000D */  break     7
.L801464DC:
/* DCBDC 801464DC 2401FFFF */   addiu    $at, $zero, -1
/* DCBE0 801464E0 14610004 */  bne       $v1, $at, .L801464F4
/* DCBE4 801464E4 3C018000 */   lui      $at, 0x8000
/* DCBE8 801464E8 14410002 */  bne       $v0, $at, .L801464F4
/* DCBEC 801464EC 00000000 */   nop
/* DCBF0 801464F0 0006000D */  break     6
.L801464F4:
/* DCBF4 801464F4 00001810 */   mfhi     $v1
/* DCBF8 801464F8 34A50A01 */  ori       $a1, $a1, 0xa01
/* DCBFC 801464FC 3C08E300 */  lui       $t0, 0xe300
/* DCC00 80146500 35080C00 */  ori       $t0, $t0, 0xc00
/* DCC04 80146504 3C09E300 */  lui       $t1, 0xe300
/* DCC08 80146508 35291001 */  ori       $t1, $t1, 0x1001
/* DCC0C 8014650C 3C0BFCFF */  lui       $t3, 0xfcff
/* DCC10 80146510 356BFFFF */  ori       $t3, $t3, 0xffff
/* DCC14 80146514 3C0AFFFC */  lui       $t2, 0xfffc
/* DCC18 80146518 354AF87C */  ori       $t2, $t2, 0xf87c
/* DCC1C 8014651C 3C06E200 */  lui       $a2, 0xe200
/* DCC20 80146520 34C6001C */  ori       $a2, $a2, 0x1c
/* DCC24 80146524 3C07E300 */  lui       $a3, 0xe300
/* DCC28 80146528 3C0D800A */  lui       $t5, %hi(gMasterGfxPos)
/* DCC2C 8014652C 25ADA66C */  addiu     $t5, $t5, %lo(gMasterGfxPos)
/* DCC30 80146530 34E71201 */  ori       $a3, $a3, 0x1201
/* DCC34 80146534 8DAC0000 */  lw        $t4, ($t5)
/* DCC38 80146538 3C10E700 */  lui       $s0, 0xe700
/* DCC3C 8014653C 0180202D */  daddu     $a0, $t4, $zero
/* DCC40 80146540 258C0008 */  addiu     $t4, $t4, 8
/* DCC44 80146544 ADAC0000 */  sw        $t4, ($t5)
/* DCC48 80146548 25820008 */  addiu     $v0, $t4, 8
/* DCC4C 8014654C ADA20000 */  sw        $v0, ($t5)
/* DCC50 80146550 25820010 */  addiu     $v0, $t4, 0x10
/* DCC54 80146554 ADA20000 */  sw        $v0, ($t5)
/* DCC58 80146558 25820018 */  addiu     $v0, $t4, 0x18
/* DCC5C 8014655C ADA20000 */  sw        $v0, ($t5)
/* DCC60 80146560 25820020 */  addiu     $v0, $t4, 0x20
/* DCC64 80146564 ADA20000 */  sw        $v0, ($t5)
/* DCC68 80146568 25820028 */  addiu     $v0, $t4, 0x28
/* DCC6C 8014656C ADA20000 */  sw        $v0, ($t5)
/* DCC70 80146570 25820030 */  addiu     $v0, $t4, 0x30
/* DCC74 80146574 ADA20000 */  sw        $v0, ($t5)
/* DCC78 80146578 25820038 */  addiu     $v0, $t4, 0x38
/* DCC7C 8014657C ADA20000 */  sw        $v0, ($t5)
/* DCC80 80146580 85D2014E */  lh        $s2, 0x14e($t6)
/* DCC84 80146584 85CF0150 */  lh        $t7, 0x150($t6)
/* DCC88 80146588 3C020020 */  lui       $v0, 0x20
/* DCC8C 8014658C A5C30152 */  sh        $v1, 0x152($t6)
/* DCC90 80146590 AFAF0034 */  sw        $t7, 0x34($sp)
/* DCC94 80146594 85D9014A */  lh        $t9, 0x14a($t6)
/* DCC98 80146598 85D7014C */  lh        $s7, 0x14c($t6)
/* DCC9C 8014659C 00031C00 */  sll       $v1, $v1, 0x10
/* DCCA0 801465A0 AFB70030 */  sw        $s7, 0x30($sp)
/* DCCA4 801465A4 AC900000 */  sw        $s0, ($a0)
/* DCCA8 801465A8 AC800004 */  sw        $zero, 4($a0)
/* DCCAC 801465AC AD820004 */  sw        $v0, 4($t4)
/* DCCB0 801465B0 34028000 */  ori       $v0, $zero, 0x8000
/* DCCB4 801465B4 AD850000 */  sw        $a1, ($t4)
/* DCCB8 801465B8 AD880008 */  sw        $t0, 8($t4)
/* DCCBC 801465BC AD80000C */  sw        $zero, 0xc($t4)
/* DCCC0 801465C0 AD890010 */  sw        $t1, 0x10($t4)
/* DCCC4 801465C4 AD820014 */  sw        $v0, 0x14($t4)
/* DCCC8 801465C8 AD8B0018 */  sw        $t3, 0x18($t4)
/* DCCCC 801465CC AD8A001C */  sw        $t2, 0x1c($t4)
/* DCCD0 801465D0 AD860020 */  sw        $a2, 0x20($t4)
/* DCCD4 801465D4 AD800024 */  sw        $zero, 0x24($t4)
/* DCCD8 801465D8 AD870028 */  sw        $a3, 0x28($t4)
/* DCCDC 801465DC AD80002C */  sw        $zero, 0x2c($t4)
/* DCCE0 801465E0 AD900030 */  sw        $s0, 0x30($t4)
/* DCCE4 801465E4 AD800034 */  sw        $zero, 0x34($t4)
/* DCCE8 801465E8 95C20148 */  lhu       $v0, 0x148($t6)
/* DCCEC 801465EC 30420002 */  andi      $v0, $v0, 2
/* DCCF0 801465F0 14400024 */  bnez      $v0, .L80146684
/* DCCF4 801465F4 0003C403 */   sra      $t8, $v1, 0x10
/* DCCF8 801465F8 3C03F500 */  lui       $v1, 0xf500
/* DCCFC 801465FC 34630100 */  ori       $v1, $v1, 0x100
/* DCD00 80146600 3C05073F */  lui       $a1, 0x73f
/* DCD04 80146604 34A5C000 */  ori       $a1, $a1, 0xc000
/* DCD08 80146608 25820040 */  addiu     $v0, $t4, 0x40
/* DCD0C 8014660C ADA20000 */  sw        $v0, ($t5)
/* DCD10 80146610 3C02FD10 */  lui       $v0, 0xfd10
/* DCD14 80146614 AD820038 */  sw        $v0, 0x38($t4)
/* DCD18 80146618 25820048 */  addiu     $v0, $t4, 0x48
/* DCD1C 8014661C ADA20000 */  sw        $v0, ($t5)
/* DCD20 80146620 8DC40158 */  lw        $a0, 0x158($t6)
/* DCD24 80146624 3C02E800 */  lui       $v0, 0xe800
/* DCD28 80146628 AD820040 */  sw        $v0, 0x40($t4)
/* DCD2C 8014662C 25820050 */  addiu     $v0, $t4, 0x50
/* DCD30 80146630 AD800044 */  sw        $zero, 0x44($t4)
/* DCD34 80146634 ADA20000 */  sw        $v0, ($t5)
/* DCD38 80146638 3C020700 */  lui       $v0, 0x700
/* DCD3C 8014663C AD82004C */  sw        $v0, 0x4c($t4)
/* DCD40 80146640 25820058 */  addiu     $v0, $t4, 0x58
/* DCD44 80146644 AD830048 */  sw        $v1, 0x48($t4)
/* DCD48 80146648 ADA20000 */  sw        $v0, ($t5)
/* DCD4C 8014664C 3C02E600 */  lui       $v0, 0xe600
/* DCD50 80146650 AD820050 */  sw        $v0, 0x50($t4)
/* DCD54 80146654 25820060 */  addiu     $v0, $t4, 0x60
/* DCD58 80146658 AD800054 */  sw        $zero, 0x54($t4)
/* DCD5C 8014665C ADA20000 */  sw        $v0, ($t5)
/* DCD60 80146660 3C02F000 */  lui       $v0, 0xf000
/* DCD64 80146664 AD820058 */  sw        $v0, 0x58($t4)
/* DCD68 80146668 25820068 */  addiu     $v0, $t4, 0x68
/* DCD6C 8014666C AD85005C */  sw        $a1, 0x5c($t4)
/* DCD70 80146670 ADA20000 */  sw        $v0, ($t5)
/* DCD74 80146674 AD900060 */  sw        $s0, 0x60($t4)
/* DCD78 80146678 AD800064 */  sw        $zero, 0x64($t4)
/* DCD7C 8014667C 080519C4 */  j         .L80146710
/* DCD80 80146680 AD84003C */   sw       $a0, 0x3c($t4)
.L80146684:
/* DCD84 80146684 3C03F500 */  lui       $v1, 0xf500
/* DCD88 80146688 34630100 */  ori       $v1, $v1, 0x100
/* DCD8C 8014668C 3C04073F */  lui       $a0, 0x73f
/* DCD90 80146690 3484C000 */  ori       $a0, $a0, 0xc000
/* DCD94 80146694 25820040 */  addiu     $v0, $t4, 0x40
/* DCD98 80146698 ADA20000 */  sw        $v0, ($t5)
/* DCD9C 8014669C 3C02FD10 */  lui       $v0, 0xfd10
/* DCDA0 801466A0 AD820038 */  sw        $v0, 0x38($t4)
/* DCDA4 801466A4 3C028016 */  lui       $v0, %hi(D_801593A0)
/* DCDA8 801466A8 244293A0 */  addiu     $v0, $v0, %lo(D_801593A0)
/* DCDAC 801466AC AD82003C */  sw        $v0, 0x3c($t4)
/* DCDB0 801466B0 25820048 */  addiu     $v0, $t4, 0x48
/* DCDB4 801466B4 ADA20000 */  sw        $v0, ($t5)
/* DCDB8 801466B8 3C02E800 */  lui       $v0, 0xe800
/* DCDBC 801466BC AD820040 */  sw        $v0, 0x40($t4)
/* DCDC0 801466C0 25820050 */  addiu     $v0, $t4, 0x50
/* DCDC4 801466C4 AD800044 */  sw        $zero, 0x44($t4)
/* DCDC8 801466C8 ADA20000 */  sw        $v0, ($t5)
/* DCDCC 801466CC 3C020700 */  lui       $v0, 0x700
/* DCDD0 801466D0 AD82004C */  sw        $v0, 0x4c($t4)
/* DCDD4 801466D4 25820058 */  addiu     $v0, $t4, 0x58
/* DCDD8 801466D8 AD830048 */  sw        $v1, 0x48($t4)
/* DCDDC 801466DC ADA20000 */  sw        $v0, ($t5)
/* DCDE0 801466E0 3C02E600 */  lui       $v0, 0xe600
/* DCDE4 801466E4 AD820050 */  sw        $v0, 0x50($t4)
/* DCDE8 801466E8 25820060 */  addiu     $v0, $t4, 0x60
/* DCDEC 801466EC AD800054 */  sw        $zero, 0x54($t4)
/* DCDF0 801466F0 ADA20000 */  sw        $v0, ($t5)
/* DCDF4 801466F4 3C02F000 */  lui       $v0, 0xf000
/* DCDF8 801466F8 AD820058 */  sw        $v0, 0x58($t4)
/* DCDFC 801466FC 25820068 */  addiu     $v0, $t4, 0x68
/* DCE00 80146700 AD84005C */  sw        $a0, 0x5c($t4)
/* DCE04 80146704 ADA20000 */  sw        $v0, ($t5)
/* DCE08 80146708 AD900060 */  sw        $s0, 0x60($t4)
/* DCE0C 8014670C AD800064 */  sw        $zero, 0x64($t4)
.L80146710:
/* DCE10 80146710 3C028015 */  lui       $v0, %hi(D_8014F12F)
/* DCE14 80146714 8042F12F */  lb        $v0, %lo(D_8014F12F)($v0)
/* DCE18 80146718 1440013D */  bnez      $v0, .L80146C10
/* DCE1C 8014671C 24110006 */   addiu    $s1, $zero, 6
/* DCE20 80146720 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* DCE24 80146724 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* DCE28 80146728 8483014E */  lh        $v1, 0x14e($a0)
/* DCE2C 8014672C 24020800 */  addiu     $v0, $zero, 0x800
/* DCE30 80146730 14600002 */  bnez      $v1, .L8014673C
/* DCE34 80146734 0043001A */   div      $zero, $v0, $v1
/* DCE38 80146738 0007000D */  break     7
.L8014673C:
/* DCE3C 8014673C 2401FFFF */   addiu    $at, $zero, -1
/* DCE40 80146740 14610004 */  bne       $v1, $at, .L80146754
/* DCE44 80146744 3C018000 */   lui      $at, 0x8000
/* DCE48 80146748 14410002 */  bne       $v0, $at, .L80146754
/* DCE4C 8014674C 00000000 */   nop
/* DCE50 80146750 0006000D */  break     6
.L80146754:
/* DCE54 80146754 00008812 */   mflo     $s1
/* DCE58 80146758 84820150 */  lh        $v0, 0x150($a0)
/* DCE5C 8014675C 16200002 */  bnez      $s1, .L80146768
/* DCE60 80146760 0051001A */   div      $zero, $v0, $s1
/* DCE64 80146764 0007000D */  break     7
.L80146768:
/* DCE68 80146768 2401FFFF */   addiu    $at, $zero, -1
/* DCE6C 8014676C 16210004 */  bne       $s1, $at, .L80146780
/* DCE70 80146770 3C018000 */   lui      $at, 0x8000
/* DCE74 80146774 14410002 */  bne       $v0, $at, .L80146780
/* DCE78 80146778 00000000 */   nop
/* DCE7C 8014677C 0006000D */  break     6
.L80146780:
/* DCE80 80146780 00007812 */   mflo     $t7
/* DCE84 80146784 0000B810 */  mfhi      $s7
/* DCE88 80146788 0000982D */  daddu     $s3, $zero, $zero
/* DCE8C 8014678C AFAF0070 */  sw        $t7, 0x70($sp)
/* DCE90 80146790 19E00095 */  blez      $t7, .L801469E8
/* DCE94 80146794 AFB70038 */   sw       $s7, 0x38($sp)
/* DCE98 80146798 3C0A800A */  lui       $t2, %hi(gMasterGfxPos)
/* DCE9C 8014679C 254AA66C */  addiu     $t2, $t2, %lo(gMasterGfxPos)
/* DCEA0 801467A0 2642FFFF */  addiu     $v0, $s2, -1
/* DCEA4 801467A4 30420FFF */  andi      $v0, $v0, 0xfff
/* DCEA8 801467A8 3C03FD48 */  lui       $v1, 0xfd48
/* DCEAC 801467AC 00431025 */  or        $v0, $v0, $v1
/* DCEB0 801467B0 3C14F548 */  lui       $s4, 0xf548
/* DCEB4 801467B4 36944A00 */  ori       $s4, $s4, 0x4a00
/* DCEB8 801467B8 03191821 */  addu      $v1, $t8, $t9
/* DCEBC 801467BC AFA2003C */  sw        $v0, 0x3c($sp)
/* DCEC0 801467C0 2462FFFF */  addiu     $v0, $v1, -1
/* DCEC4 801467C4 00021080 */  sll       $v0, $v0, 2
/* DCEC8 801467C8 30420FFF */  andi      $v0, $v0, 0xfff
/* DCECC 801467CC 00021300 */  sll       $v0, $v0, 0xc
/* DCED0 801467D0 AFA20040 */  sw        $v0, 0x40($sp)
/* DCED4 801467D4 00191080 */  sll       $v0, $t9, 2
/* DCED8 801467D8 30420FFF */  andi      $v0, $v0, 0xfff
/* DCEDC 801467DC 00021300 */  sll       $v0, $v0, 0xc
/* DCEE0 801467E0 3C16E100 */  lui       $s6, 0xe100
/* DCEE4 801467E4 AFA20044 */  sw        $v0, 0x44($sp)
/* DCEE8 801467E8 02581023 */  subu      $v0, $s2, $t8
/* DCEEC 801467EC 00021540 */  sll       $v0, $v0, 0x15
/* DCEF0 801467F0 3C15F100 */  lui       $s5, 0xf100
/* DCEF4 801467F4 3C101000 */  lui       $s0, 0x1000
/* DCEF8 801467F8 36100400 */  ori       $s0, $s0, 0x400
/* DCEFC 801467FC AFA20048 */  sw        $v0, 0x48($sp)
/* DCF00 80146800 02591021 */  addu      $v0, $s2, $t9
/* DCF04 80146804 2442FFFF */  addiu     $v0, $v0, -1
/* DCF08 80146808 00021080 */  sll       $v0, $v0, 2
/* DCF0C 8014680C 30420FFF */  andi      $v0, $v0, 0xfff
/* DCF10 80146810 00021300 */  sll       $v0, $v0, 0xc
/* DCF14 80146814 00031880 */  sll       $v1, $v1, 2
/* DCF18 80146818 30630FFF */  andi      $v1, $v1, 0xfff
/* DCF1C 8014681C 0003F300 */  sll       $fp, $v1, 0xc
/* DCF20 80146820 0220702D */  daddu     $t6, $s1, $zero
/* DCF24 80146824 8FAF0030 */  lw        $t7, 0x30($sp)
/* DCF28 80146828 0260682D */  daddu     $t5, $s3, $zero
/* DCF2C 8014682C AFA2004C */  sw        $v0, 0x4c($sp)
/* DCF30 80146830 AFAF0078 */  sw        $t7, 0x78($sp)
.L80146834:
/* DCF34 80146834 3C028015 */  lui       $v0, %hi(D_8014F130)
/* DCF38 80146838 9442F130 */  lhu       $v0, %lo(D_8014F130)($v0)
/* DCF3C 8014683C 3C0B8007 */  lui       $t3, %hi(gGameStatusPtr)
/* DCF40 80146840 8D6B419C */  lw        $t3, %lo(gGameStatusPtr)($t3)
/* DCF44 80146844 004D2021 */  addu      $a0, $v0, $t5
/* DCF48 80146848 00041400 */  sll       $v0, $a0, 0x10
/* DCF4C 8014684C 85630150 */  lh        $v1, 0x150($t3)
/* DCF50 80146850 00021403 */  sra       $v0, $v0, 0x10
/* DCF54 80146854 0062182A */  slt       $v1, $v1, $v0
/* DCF58 80146858 95620150 */  lhu       $v0, 0x150($t3)
/* DCF5C 8014685C 10600002 */  beqz      $v1, .L80146868
/* DCF60 80146860 0080602D */   daddu    $t4, $a0, $zero
/* DCF64 80146864 00826023 */  subu      $t4, $a0, $v0
.L80146868:
/* DCF68 80146868 3C080749 */  lui       $t0, 0x749
/* DCF6C 8014686C 3508C014 */  ori       $t0, $t0, 0xc014
/* DCF70 80146870 3C090049 */  lui       $t1, 0x49
/* DCF74 80146874 3529C014 */  ori       $t1, $t1, 0xc014
/* DCF78 80146878 01B16821 */  addu      $t5, $t5, $s1
/* DCF7C 8014687C 26730001 */  addiu     $s3, $s3, 1
/* DCF80 80146880 8FB70078 */  lw        $s7, 0x78($sp)
/* DCF84 80146884 8FAF0030 */  lw        $t7, 0x30($sp)
/* DCF88 80146888 00173080 */  sll       $a2, $s7, 2
/* DCF8C 8014688C 02F1B821 */  addu      $s7, $s7, $s1
/* DCF90 80146890 25E5FFFF */  addiu     $a1, $t7, -1
/* DCF94 80146894 01C52821 */  addu      $a1, $t6, $a1
/* DCF98 80146898 00052880 */  sll       $a1, $a1, 2
/* DCF9C 8014689C AFB70078 */  sw        $s7, 0x78($sp)
/* DCFA0 801468A0 8D430000 */  lw        $v1, ($t2)
/* DCFA4 801468A4 30A50FFF */  andi      $a1, $a1, 0xfff
/* DCFA8 801468A8 0060382D */  daddu     $a3, $v1, $zero
/* DCFAC 801468AC 24630008 */  addiu     $v1, $v1, 8
/* DCFB0 801468B0 24620008 */  addiu     $v0, $v1, 8
/* DCFB4 801468B4 AD430000 */  sw        $v1, ($t2)
/* DCFB8 801468B8 8FB7003C */  lw        $s7, 0x3c($sp)
/* DCFBC 801468BC 24640048 */  addiu     $a0, $v1, 0x48
/* DCFC0 801468C0 ACF70000 */  sw        $s7, ($a3)
/* DCFC4 801468C4 AD420000 */  sw        $v0, ($t2)
/* DCFC8 801468C8 24620010 */  addiu     $v0, $v1, 0x10
/* DCFCC 801468CC AD420000 */  sw        $v0, ($t2)
/* DCFD0 801468D0 24620018 */  addiu     $v0, $v1, 0x18
/* DCFD4 801468D4 AD420000 */  sw        $v0, ($t2)
/* DCFD8 801468D8 24620020 */  addiu     $v0, $v1, 0x20
/* DCFDC 801468DC AD420000 */  sw        $v0, ($t2)
/* DCFE0 801468E0 24620028 */  addiu     $v0, $v1, 0x28
/* DCFE4 801468E4 AD420000 */  sw        $v0, ($t2)
/* DCFE8 801468E8 24620030 */  addiu     $v0, $v1, 0x30
/* DCFEC 801468EC AD420000 */  sw        $v0, ($t2)
/* DCFF0 801468F0 24620038 */  addiu     $v0, $v1, 0x38
/* DCFF4 801468F4 AD420000 */  sw        $v0, ($t2)
/* DCFF8 801468F8 24620040 */  addiu     $v0, $v1, 0x40
/* DCFFC 801468FC AD420000 */  sw        $v0, ($t2)
/* DD000 80146900 000C1400 */  sll       $v0, $t4, 0x10
/* DD004 80146904 00021403 */  sra       $v0, $v0, 0x10
/* DD008 80146908 02420018 */  mult      $s2, $v0
/* DD00C 8014690C AD440000 */  sw        $a0, ($t2)
/* DD010 80146910 8D640154 */  lw        $a0, 0x154($t3)
/* DD014 80146914 24620050 */  addiu     $v0, $v1, 0x50
/* DD018 80146918 AD420000 */  sw        $v0, ($t2)
/* DD01C 8014691C 3C020700 */  lui       $v0, 0x700
/* DD020 80146920 00007812 */  mflo      $t7
/* DD024 80146924 008F2021 */  addu      $a0, $a0, $t7
/* DD028 80146928 ACE40004 */  sw        $a0, 4($a3)
/* DD02C 8014692C AC620004 */  sw        $v0, 4($v1)
/* DD030 80146930 3C02E600 */  lui       $v0, 0xe600
/* DD034 80146934 AC620008 */  sw        $v0, 8($v1)
/* DD038 80146938 3C02F400 */  lui       $v0, 0xf400
/* DD03C 8014693C AC620010 */  sw        $v0, 0x10($v1)
/* DD040 80146940 3C02E700 */  lui       $v0, 0xe700
/* DD044 80146944 AC620018 */  sw        $v0, 0x18($v1)
/* DD048 80146948 3C02F200 */  lui       $v0, 0xf200
/* DD04C 8014694C AC620028 */  sw        $v0, 0x28($v1)
/* DD050 80146950 3C02E400 */  lui       $v0, 0xe400
/* DD054 80146954 AC740000 */  sw        $s4, ($v1)
/* DD058 80146958 AC60000C */  sw        $zero, 0xc($v1)
/* DD05C 8014695C AC680014 */  sw        $t0, 0x14($v1)
/* DD060 80146960 AC60001C */  sw        $zero, 0x1c($v1)
/* DD064 80146964 AC740020 */  sw        $s4, 0x20($v1)
/* DD068 80146968 AC600024 */  sw        $zero, 0x24($v1)
/* DD06C 8014696C AC69002C */  sw        $t1, 0x2c($v1)
/* DD070 80146970 8FB70040 */  lw        $s7, 0x40($sp)
/* DD074 80146974 00A22825 */  or        $a1, $a1, $v0
/* DD078 80146978 02E51025 */  or        $v0, $s7, $a1
/* DD07C 8014697C AC620030 */  sw        $v0, 0x30($v1)
/* DD080 80146980 8FAF0044 */  lw        $t7, 0x44($sp)
/* DD084 80146984 30C60FFF */  andi      $a2, $a2, 0xfff
/* DD088 80146988 01E61025 */  or        $v0, $t7, $a2
/* DD08C 8014698C AC620034 */  sw        $v0, 0x34($v1)
/* DD090 80146990 AC760038 */  sw        $s6, 0x38($v1)
/* DD094 80146994 8FB70048 */  lw        $s7, 0x48($sp)
/* DD098 80146998 03C63025 */  or        $a2, $fp, $a2
/* DD09C 8014699C AC750040 */  sw        $s5, 0x40($v1)
/* DD0A0 801469A0 AC700044 */  sw        $s0, 0x44($v1)
/* DD0A4 801469A4 AC77003C */  sw        $s7, 0x3c($v1)
/* DD0A8 801469A8 8FAF004C */  lw        $t7, 0x4c($sp)
/* DD0AC 801469AC 24620058 */  addiu     $v0, $v1, 0x58
/* DD0B0 801469B0 01E52825 */  or        $a1, $t7, $a1
/* DD0B4 801469B4 AC650048 */  sw        $a1, 0x48($v1)
/* DD0B8 801469B8 AC66004C */  sw        $a2, 0x4c($v1)
/* DD0BC 801469BC AD420000 */  sw        $v0, ($t2)
/* DD0C0 801469C0 24620060 */  addiu     $v0, $v1, 0x60
/* DD0C4 801469C4 AC760050 */  sw        $s6, 0x50($v1)
/* DD0C8 801469C8 AC600054 */  sw        $zero, 0x54($v1)
/* DD0CC 801469CC AD420000 */  sw        $v0, ($t2)
/* DD0D0 801469D0 AC750058 */  sw        $s5, 0x58($v1)
/* DD0D4 801469D4 AC70005C */  sw        $s0, 0x5c($v1)
/* DD0D8 801469D8 8FB70070 */  lw        $s7, 0x70($sp)
/* DD0DC 801469DC 0277102A */  slt       $v0, $s3, $s7
/* DD0E0 801469E0 1440FF94 */  bnez      $v0, .L80146834
/* DD0E4 801469E4 01D17021 */   addu     $t6, $t6, $s1
.L801469E8:
/* DD0E8 801469E8 8FAF0038 */  lw        $t7, 0x38($sp)
/* DD0EC 801469EC 11E001F9 */  beqz      $t7, .L801471D4
/* DD0F0 801469F0 02330018 */   mult     $s1, $s3
/* DD0F4 801469F4 3C0B8007 */  lui       $t3, %hi(gGameStatusPtr)
/* DD0F8 801469F8 8D6B419C */  lw        $t3, %lo(gGameStatusPtr)($t3)
/* DD0FC 801469FC 3C028015 */  lui       $v0, %hi(D_8014F130)
/* DD100 80146A00 9442F130 */  lhu       $v0, %lo(D_8014F130)($v0)
/* DD104 80146A04 85630150 */  lh        $v1, 0x150($t3)
/* DD108 80146A08 00006812 */  mflo      $t5
/* DD10C 80146A0C 004D2021 */  addu      $a0, $v0, $t5
/* DD110 80146A10 00041400 */  sll       $v0, $a0, 0x10
/* DD114 80146A14 00021403 */  sra       $v0, $v0, 0x10
/* DD118 80146A18 0062182A */  slt       $v1, $v1, $v0
/* DD11C 80146A1C 95620150 */  lhu       $v0, 0x150($t3)
/* DD120 80146A20 10600002 */  beqz      $v1, .L80146A2C
/* DD124 80146A24 0080602D */   daddu    $t4, $a0, $zero
/* DD128 80146A28 00826023 */  subu      $t4, $a0, $v0
.L80146A2C:
/* DD12C 80146A2C 3C08F548 */  lui       $t0, 0xf548
/* DD130 80146A30 35084A00 */  ori       $t0, $t0, 0x4a00
/* DD134 80146A34 3C050749 */  lui       $a1, 0x749
/* DD138 80146A38 34A5C000 */  ori       $a1, $a1, 0xc000
/* DD13C 80146A3C 3C090049 */  lui       $t1, 0x49
/* DD140 80146A40 3529C000 */  ori       $t1, $t1, 0xc000
/* DD144 80146A44 3C0A1000 */  lui       $t2, 0x1000
/* DD148 80146A48 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* DD14C 80146A4C 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* DD150 80146A50 354A0400 */  ori       $t2, $t2, 0x400
/* DD154 80146A54 2642FFFF */  addiu     $v0, $s2, -1
/* DD158 80146A58 30420FFF */  andi      $v0, $v0, 0xfff
/* DD15C 80146A5C 3C03FD48 */  lui       $v1, 0xfd48
/* DD160 80146A60 8CE40000 */  lw        $a0, ($a3)
/* DD164 80146A64 00431025 */  or        $v0, $v0, $v1
/* DD168 80146A68 0080302D */  daddu     $a2, $a0, $zero
/* DD16C 80146A6C 24840008 */  addiu     $a0, $a0, 8
/* DD170 80146A70 ACE40000 */  sw        $a0, ($a3)
/* DD174 80146A74 ACC20000 */  sw        $v0, ($a2)
/* DD178 80146A78 24820008 */  addiu     $v0, $a0, 8
/* DD17C 80146A7C ACE20000 */  sw        $v0, ($a3)
/* DD180 80146A80 24820010 */  addiu     $v0, $a0, 0x10
/* DD184 80146A84 ACE20000 */  sw        $v0, ($a3)
/* DD188 80146A88 24820018 */  addiu     $v0, $a0, 0x18
/* DD18C 80146A8C ACE20000 */  sw        $v0, ($a3)
/* DD190 80146A90 24820020 */  addiu     $v0, $a0, 0x20
/* DD194 80146A94 ACE20000 */  sw        $v0, ($a3)
/* DD198 80146A98 24820028 */  addiu     $v0, $a0, 0x28
/* DD19C 80146A9C ACE20000 */  sw        $v0, ($a3)
/* DD1A0 80146AA0 24820030 */  addiu     $v0, $a0, 0x30
/* DD1A4 80146AA4 ACE20000 */  sw        $v0, ($a3)
/* DD1A8 80146AA8 24820038 */  addiu     $v0, $a0, 0x38
/* DD1AC 80146AAC ACE20000 */  sw        $v0, ($a3)
/* DD1B0 80146AB0 24820040 */  addiu     $v0, $a0, 0x40
/* DD1B4 80146AB4 ACE20000 */  sw        $v0, ($a3)
/* DD1B8 80146AB8 000C1400 */  sll       $v0, $t4, 0x10
/* DD1BC 80146ABC 00021403 */  sra       $v0, $v0, 0x10
/* DD1C0 80146AC0 24830048 */  addiu     $v1, $a0, 0x48
/* DD1C4 80146AC4 02420018 */  mult      $s2, $v0
/* DD1C8 80146AC8 ACE30000 */  sw        $v1, ($a3)
/* DD1CC 80146ACC 8D620154 */  lw        $v0, 0x154($t3)
/* DD1D0 80146AD0 24830050 */  addiu     $v1, $a0, 0x50
/* DD1D4 80146AD4 ACE30000 */  sw        $v1, ($a3)
/* DD1D8 80146AD8 3C03E700 */  lui       $v1, 0xe700
/* DD1DC 80146ADC 00007812 */  mflo      $t7
/* DD1E0 80146AE0 004F1021 */  addu      $v0, $v0, $t7
/* DD1E4 80146AE4 ACC20004 */  sw        $v0, 4($a2)
/* DD1E8 80146AE8 3C020700 */  lui       $v0, 0x700
/* DD1EC 80146AEC AC820004 */  sw        $v0, 4($a0)
/* DD1F0 80146AF0 3C02E600 */  lui       $v0, 0xe600
/* DD1F4 80146AF4 AC820008 */  sw        $v0, 8($a0)
/* DD1F8 80146AF8 3C02F400 */  lui       $v0, 0xf400
/* DD1FC 80146AFC AC880000 */  sw        $t0, ($a0)
/* DD200 80146B00 AC80000C */  sw        $zero, 0xc($a0)
/* DD204 80146B04 AC820010 */  sw        $v0, 0x10($a0)
/* DD208 80146B08 8FB70038 */  lw        $s7, 0x38($sp)
/* DD20C 80146B0C 03193021 */  addu      $a2, $t8, $t9
/* DD210 80146B10 26E2FFFF */  addiu     $v0, $s7, -1
/* DD214 80146B14 00021080 */  sll       $v0, $v0, 2
/* DD218 80146B18 30420FFF */  andi      $v0, $v0, 0xfff
/* DD21C 80146B1C 00452825 */  or        $a1, $v0, $a1
/* DD220 80146B20 AC830018 */  sw        $v1, 0x18($a0)
/* DD224 80146B24 3C03F200 */  lui       $v1, 0xf200
/* DD228 80146B28 00491025 */  or        $v0, $v0, $t1
/* DD22C 80146B2C AC82002C */  sw        $v0, 0x2c($a0)
/* DD230 80146B30 24C2FFFF */  addiu     $v0, $a2, -1
/* DD234 80146B34 00021080 */  sll       $v0, $v0, 2
/* DD238 80146B38 30420FFF */  andi      $v0, $v0, 0xfff
/* DD23C 80146B3C 00021300 */  sll       $v0, $v0, 0xc
/* DD240 80146B40 AC830028 */  sw        $v1, 0x28($a0)
/* DD244 80146B44 3C03E400 */  lui       $v1, 0xe400
/* DD248 80146B48 3C09E100 */  lui       $t1, 0xe100
/* DD24C 80146B4C AC880020 */  sw        $t0, 0x20($a0)
/* DD250 80146B50 3C08F100 */  lui       $t0, 0xf100
/* DD254 80146B54 00063080 */  sll       $a2, $a2, 2
/* DD258 80146B58 30C60FFF */  andi      $a2, $a2, 0xfff
/* DD25C 80146B5C 00063300 */  sll       $a2, $a2, 0xc
/* DD260 80146B60 AC850014 */  sw        $a1, 0x14($a0)
/* DD264 80146B64 AC80001C */  sw        $zero, 0x1c($a0)
/* DD268 80146B68 AC800024 */  sw        $zero, 0x24($a0)
/* DD26C 80146B6C 8FAF0030 */  lw        $t7, 0x30($sp)
/* DD270 80146B70 8FB70034 */  lw        $s7, 0x34($sp)
/* DD274 80146B74 25E5FFFF */  addiu     $a1, $t7, -1
/* DD278 80146B78 02E52821 */  addu      $a1, $s7, $a1
/* DD27C 80146B7C 00052880 */  sll       $a1, $a1, 2
/* DD280 80146B80 30A50FFF */  andi      $a1, $a1, 0xfff
/* DD284 80146B84 00A32825 */  or        $a1, $a1, $v1
/* DD288 80146B88 00451025 */  or        $v0, $v0, $a1
/* DD28C 80146B8C AC820030 */  sw        $v0, 0x30($a0)
/* DD290 80146B90 00191080 */  sll       $v0, $t9, 2
/* DD294 80146B94 30420FFF */  andi      $v0, $v0, 0xfff
/* DD298 80146B98 00021300 */  sll       $v0, $v0, 0xc
/* DD29C 80146B9C 01AF1821 */  addu      $v1, $t5, $t7
/* DD2A0 80146BA0 00031880 */  sll       $v1, $v1, 2
/* DD2A4 80146BA4 30630FFF */  andi      $v1, $v1, 0xfff
/* DD2A8 80146BA8 00431025 */  or        $v0, $v0, $v1
/* DD2AC 80146BAC AC820034 */  sw        $v0, 0x34($a0)
/* DD2B0 80146BB0 02581023 */  subu      $v0, $s2, $t8
/* DD2B4 80146BB4 00021540 */  sll       $v0, $v0, 0x15
/* DD2B8 80146BB8 AC82003C */  sw        $v0, 0x3c($a0)
/* DD2BC 80146BBC 02591021 */  addu      $v0, $s2, $t9
/* DD2C0 80146BC0 2442FFFF */  addiu     $v0, $v0, -1
/* DD2C4 80146BC4 00021080 */  sll       $v0, $v0, 2
/* DD2C8 80146BC8 30420FFF */  andi      $v0, $v0, 0xfff
/* DD2CC 80146BCC 00021300 */  sll       $v0, $v0, 0xc
/* DD2D0 80146BD0 00451025 */  or        $v0, $v0, $a1
/* DD2D4 80146BD4 00C33025 */  or        $a2, $a2, $v1
/* DD2D8 80146BD8 AC890038 */  sw        $t1, 0x38($a0)
/* DD2DC 80146BDC AC880040 */  sw        $t0, 0x40($a0)
/* DD2E0 80146BE0 AC8A0044 */  sw        $t2, 0x44($a0)
/* DD2E4 80146BE4 AC820048 */  sw        $v0, 0x48($a0)
/* DD2E8 80146BE8 24820058 */  addiu     $v0, $a0, 0x58
/* DD2EC 80146BEC AC86004C */  sw        $a2, 0x4c($a0)
/* DD2F0 80146BF0 ACE20000 */  sw        $v0, ($a3)
/* DD2F4 80146BF4 24820060 */  addiu     $v0, $a0, 0x60
/* DD2F8 80146BF8 AC890050 */  sw        $t1, 0x50($a0)
/* DD2FC 80146BFC AC800054 */  sw        $zero, 0x54($a0)
/* DD300 80146C00 ACE20000 */  sw        $v0, ($a3)
/* DD304 80146C04 AC880058 */  sw        $t0, 0x58($a0)
/* DD308 80146C08 08051C75 */  j         .L801471D4
/* DD30C 80146C0C AC8A005C */   sw       $t2, 0x5c($a0)
.L80146C10:
/* DD310 80146C10 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DD314 80146C14 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DD318 80146C18 84420150 */  lh        $v0, 0x150($v0)
/* DD31C 80146C1C 16200002 */  bnez      $s1, .L80146C28
/* DD320 80146C20 0051001A */   div      $zero, $v0, $s1
/* DD324 80146C24 0007000D */  break     7
.L80146C28:
/* DD328 80146C28 2401FFFF */   addiu    $at, $zero, -1
/* DD32C 80146C2C 16210004 */  bne       $s1, $at, .L80146C40
/* DD330 80146C30 3C018000 */   lui      $at, 0x8000
/* DD334 80146C34 14410002 */  bne       $v0, $at, .L80146C40
/* DD338 80146C38 00000000 */   nop
/* DD33C 80146C3C 0006000D */  break     6
.L80146C40:
/* DD340 80146C40 00007812 */   mflo     $t7
/* DD344 80146C44 0000B810 */  mfhi      $s7
/* DD348 80146C48 3C013DD6 */  lui       $at, 0x3dd6
/* DD34C 80146C4C 34217744 */  ori       $at, $at, 0x7744
/* DD350 80146C50 44810000 */  mtc1      $at, $f0
/* DD354 80146C54 3C028015 */  lui       $v0, %hi(D_8014F134)
/* DD358 80146C58 2442F134 */  addiu     $v0, $v0, %lo(D_8014F134)
/* DD35C 80146C5C AFAF0070 */  sw        $t7, 0x70($sp)
/* DD360 80146C60 AFB70038 */  sw        $s7, 0x38($sp)
/* DD364 80146C64 C4420000 */  lwc1      $f2, ($v0)
/* DD368 80146C68 46001080 */  add.s     $f2, $f2, $f0
/* DD36C 80146C6C 0000982D */  daddu     $s3, $zero, $zero
/* DD370 80146C70 19E000B1 */  blez      $t7, .L80146F38
/* DD374 80146C74 E4420000 */   swc1     $f2, ($v0)
/* DD378 80146C78 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* DD37C 80146C7C 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* DD380 80146C80 2642FFFF */  addiu     $v0, $s2, -1
/* DD384 80146C84 30420FFF */  andi      $v0, $v0, 0xfff
/* DD388 80146C88 3C03FD48 */  lui       $v1, 0xfd48
/* DD38C 80146C8C 00431025 */  or        $v0, $v0, $v1
/* DD390 80146C90 3C0BF548 */  lui       $t3, 0xf548
/* DD394 80146C94 356B4A00 */  ori       $t3, $t3, 0x4a00
/* DD398 80146C98 00197880 */  sll       $t7, $t9, 2
/* DD39C 80146C9C AFA20050 */  sw        $v0, 0x50($sp)
/* DD3A0 80146CA0 31E20FFF */  andi      $v0, $t7, 0xfff
/* DD3A4 80146CA4 00021300 */  sll       $v0, $v0, 0xc
/* DD3A8 80146CA8 3C0EE100 */  lui       $t6, 0xe100
/* DD3AC 80146CAC 3C0DF100 */  lui       $t5, 0xf100
/* DD3B0 80146CB0 3C1E1000 */  lui       $fp, 0x1000
/* DD3B4 80146CB4 37DE0400 */  ori       $fp, $fp, 0x400
/* DD3B8 80146CB8 0220A82D */  daddu     $s5, $s1, $zero
/* DD3BC 80146CBC 8FB60030 */  lw        $s6, 0x30($sp)
/* DD3C0 80146CC0 0260A02D */  daddu     $s4, $s3, $zero
/* DD3C4 80146CC4 AFAF0054 */  sw        $t7, 0x54($sp)
/* DD3C8 80146CC8 AFA20058 */  sw        $v0, 0x58($sp)
.L80146CCC:
/* DD3CC 80146CCC 3C013ED6 */  lui       $at, 0x3ed6
/* DD3D0 80146CD0 34217744 */  ori       $at, $at, 0x7744
/* DD3D4 80146CD4 44810000 */  mtc1      $at, $f0
/* DD3D8 80146CD8 44936000 */  mtc1      $s3, $f12
/* DD3DC 80146CDC 00000000 */  nop
/* DD3E0 80146CE0 46806320 */  cvt.s.w   $f12, $f12
/* DD3E4 80146CE4 46006302 */  mul.s     $f12, $f12, $f0
/* DD3E8 80146CE8 00000000 */  nop
/* DD3EC 80146CEC 3C018015 */  lui       $at, %hi(D_8014F134)
/* DD3F0 80146CF0 C420F134 */  lwc1      $f0, %lo(D_8014F134)($at)
/* DD3F4 80146CF4 AFAB0060 */  sw        $t3, 0x60($sp)
/* DD3F8 80146CF8 AFAD0064 */  sw        $t5, 0x64($sp)
/* DD3FC 80146CFC 460C0300 */  add.s     $f12, $f0, $f12
/* DD400 80146D00 AFAE0068 */  sw        $t6, 0x68($sp)
/* DD404 80146D04 0C00A85B */  jal       sin_rad
/* DD408 80146D08 AFB9006C */   sw       $t9, 0x6c($sp)
/* DD40C 80146D0C 3C014040 */  lui       $at, 0x4040
/* DD410 80146D10 44811000 */  mtc1      $at, $f2
/* DD414 80146D14 3C0A8007 */  lui       $t2, %hi(gGameStatusPtr)
/* DD418 80146D18 8D4A419C */  lw        $t2, %lo(gGameStatusPtr)($t2)
/* DD41C 80146D1C 8FAB0060 */  lw        $t3, 0x60($sp)
/* DD420 80146D20 8FAD0064 */  lw        $t5, 0x64($sp)
/* DD424 80146D24 8FAE0068 */  lw        $t6, 0x68($sp)
/* DD428 80146D28 8FB9006C */  lw        $t9, 0x6c($sp)
/* DD42C 80146D2C 85420152 */  lh        $v0, 0x152($t2)
/* DD430 80146D30 46020082 */  mul.s     $f2, $f0, $f2
/* DD434 80146D34 00000000 */  nop
/* DD438 80146D38 44820000 */  mtc1      $v0, $f0
/* DD43C 80146D3C 00000000 */  nop
/* DD440 80146D40 46800020 */  cvt.s.w   $f0, $f0
/* DD444 80146D44 3C028015 */  lui       $v0, %hi(D_8014F130)
/* DD448 80146D48 9442F130 */  lhu       $v0, %lo(D_8014F130)($v0)
/* DD44C 80146D4C 85430150 */  lh        $v1, 0x150($t2)
/* DD450 80146D50 00542021 */  addu      $a0, $v0, $s4
/* DD454 80146D54 46020000 */  add.s     $f0, $f0, $f2
/* DD458 80146D58 00041400 */  sll       $v0, $a0, 0x10
/* DD45C 80146D5C 00021403 */  sra       $v0, $v0, 0x10
/* DD460 80146D60 46000000 */  add.s     $f0, $f0, $f0
/* DD464 80146D64 0062182A */  slt       $v1, $v1, $v0
/* DD468 80146D68 95420150 */  lhu       $v0, 0x150($t2)
/* DD46C 80146D6C 4600020D */  trunc.w.s $f8, $f0
/* DD470 80146D70 44184000 */  mfc1      $t8, $f8
/* DD474 80146D74 10600002 */  beqz      $v1, .L80146D80
/* DD478 80146D78 0080602D */   daddu    $t4, $a0, $zero
/* DD47C 80146D7C 00826023 */  subu      $t4, $a0, $v0
.L80146D80:
/* DD480 80146D80 3C080749 */  lui       $t0, 0x749
/* DD484 80146D84 3508C014 */  ori       $t0, $t0, 0xc014
/* DD488 80146D88 3C090049 */  lui       $t1, 0x49
/* DD48C 80146D8C 3529C014 */  ori       $t1, $t1, 0xc014
/* DD490 80146D90 00163880 */  sll       $a3, $s6, 2
/* DD494 80146D94 02D1B021 */  addu      $s6, $s6, $s1
/* DD498 80146D98 0291A021 */  addu      $s4, $s4, $s1
/* DD49C 80146D9C 26730001 */  addiu     $s3, $s3, 1
/* DD4A0 80146DA0 30E70FFF */  andi      $a3, $a3, 0xfff
/* DD4A4 80146DA4 8FB70030 */  lw        $s7, 0x30($sp)
/* DD4A8 80146DA8 8E040000 */  lw        $a0, ($s0)
/* DD4AC 80146DAC 26E6FFFF */  addiu     $a2, $s7, -1
/* DD4B0 80146DB0 02A63021 */  addu      $a2, $s5, $a2
/* DD4B4 80146DB4 0080282D */  daddu     $a1, $a0, $zero
/* DD4B8 80146DB8 24840008 */  addiu     $a0, $a0, 8
/* DD4BC 80146DBC 24820008 */  addiu     $v0, $a0, 8
/* DD4C0 80146DC0 24830048 */  addiu     $v1, $a0, 0x48
/* DD4C4 80146DC4 00063080 */  sll       $a2, $a2, 2
/* DD4C8 80146DC8 AE040000 */  sw        $a0, ($s0)
/* DD4CC 80146DCC 8FAF0050 */  lw        $t7, 0x50($sp)
/* DD4D0 80146DD0 30C60FFF */  andi      $a2, $a2, 0xfff
/* DD4D4 80146DD4 ACAF0000 */  sw        $t7, ($a1)
/* DD4D8 80146DD8 AE020000 */  sw        $v0, ($s0)
/* DD4DC 80146DDC 24820010 */  addiu     $v0, $a0, 0x10
/* DD4E0 80146DE0 AE020000 */  sw        $v0, ($s0)
/* DD4E4 80146DE4 24820018 */  addiu     $v0, $a0, 0x18
/* DD4E8 80146DE8 AE020000 */  sw        $v0, ($s0)
/* DD4EC 80146DEC 24820020 */  addiu     $v0, $a0, 0x20
/* DD4F0 80146DF0 AE020000 */  sw        $v0, ($s0)
/* DD4F4 80146DF4 24820028 */  addiu     $v0, $a0, 0x28
/* DD4F8 80146DF8 AE020000 */  sw        $v0, ($s0)
/* DD4FC 80146DFC 24820030 */  addiu     $v0, $a0, 0x30
/* DD500 80146E00 AE020000 */  sw        $v0, ($s0)
/* DD504 80146E04 24820038 */  addiu     $v0, $a0, 0x38
/* DD508 80146E08 AE020000 */  sw        $v0, ($s0)
/* DD50C 80146E0C 24820040 */  addiu     $v0, $a0, 0x40
/* DD510 80146E10 AE020000 */  sw        $v0, ($s0)
/* DD514 80146E14 000C1400 */  sll       $v0, $t4, 0x10
/* DD518 80146E18 00021403 */  sra       $v0, $v0, 0x10
/* DD51C 80146E1C 02420018 */  mult      $s2, $v0
/* DD520 80146E20 AE030000 */  sw        $v1, ($s0)
/* DD524 80146E24 8D430154 */  lw        $v1, 0x154($t2)
/* DD528 80146E28 24820050 */  addiu     $v0, $a0, 0x50
/* DD52C 80146E2C AE020000 */  sw        $v0, ($s0)
/* DD530 80146E30 3C020700 */  lui       $v0, 0x700
/* DD534 80146E34 00007812 */  mflo      $t7
/* DD538 80146E38 006F1821 */  addu      $v1, $v1, $t7
/* DD53C 80146E3C ACA30004 */  sw        $v1, 4($a1)
/* DD540 80146E40 AC820004 */  sw        $v0, 4($a0)
/* DD544 80146E44 3C02E600 */  lui       $v0, 0xe600
/* DD548 80146E48 AC820008 */  sw        $v0, 8($a0)
/* DD54C 80146E4C 3C02F400 */  lui       $v0, 0xf400
/* DD550 80146E50 AC820010 */  sw        $v0, 0x10($a0)
/* DD554 80146E54 3C02E700 */  lui       $v0, 0xe700
/* DD558 80146E58 AC820018 */  sw        $v0, 0x18($a0)
/* DD55C 80146E5C 3C02F200 */  lui       $v0, 0xf200
/* DD560 80146E60 00182840 */  sll       $a1, $t8, 1
/* DD564 80146E64 AC820028 */  sw        $v0, 0x28($a0)
/* DD568 80146E68 24A2FFFF */  addiu     $v0, $a1, -1
/* DD56C 80146E6C 00591021 */  addu      $v0, $v0, $t9
/* DD570 80146E70 00021080 */  sll       $v0, $v0, 2
/* DD574 80146E74 30420FFF */  andi      $v0, $v0, 0xfff
/* DD578 80146E78 00021300 */  sll       $v0, $v0, 0xc
/* DD57C 80146E7C 3C03E400 */  lui       $v1, 0xe400
/* DD580 80146E80 00C33025 */  or        $a2, $a2, $v1
/* DD584 80146E84 00461025 */  or        $v0, $v0, $a2
/* DD588 80146E88 AC8B0000 */  sw        $t3, ($a0)
/* DD58C 80146E8C AC80000C */  sw        $zero, 0xc($a0)
/* DD590 80146E90 AC880014 */  sw        $t0, 0x14($a0)
/* DD594 80146E94 AC80001C */  sw        $zero, 0x1c($a0)
/* DD598 80146E98 AC8B0020 */  sw        $t3, 0x20($a0)
/* DD59C 80146E9C AC800024 */  sw        $zero, 0x24($a0)
/* DD5A0 80146EA0 AC89002C */  sw        $t1, 0x2c($a0)
/* DD5A4 80146EA4 AC820030 */  sw        $v0, 0x30($a0)
/* DD5A8 80146EA8 8FB70058 */  lw        $s7, 0x58($sp)
/* DD5AC 80146EAC 00181900 */  sll       $v1, $t8, 4
/* DD5B0 80146EB0 AC8E0038 */  sw        $t6, 0x38($a0)
/* DD5B4 80146EB4 02E71025 */  or        $v0, $s7, $a3
/* DD5B8 80146EB8 AC820034 */  sw        $v0, 0x34($a0)
/* DD5BC 80146EBC 00121140 */  sll       $v0, $s2, 5
/* DD5C0 80146EC0 00431023 */  subu      $v0, $v0, $v1
/* DD5C4 80146EC4 00021400 */  sll       $v0, $v0, 0x10
/* DD5C8 80146EC8 AC82003C */  sw        $v0, 0x3c($a0)
/* DD5CC 80146ECC 02591021 */  addu      $v0, $s2, $t9
/* DD5D0 80146ED0 2442FFFF */  addiu     $v0, $v0, -1
/* DD5D4 80146ED4 00021080 */  sll       $v0, $v0, 2
/* DD5D8 80146ED8 30420FFF */  andi      $v0, $v0, 0xfff
/* DD5DC 80146EDC 00021300 */  sll       $v0, $v0, 0xc
/* DD5E0 80146EE0 00461025 */  or        $v0, $v0, $a2
/* DD5E4 80146EE4 AC8D0040 */  sw        $t5, 0x40($a0)
/* DD5E8 80146EE8 AC9E0044 */  sw        $fp, 0x44($a0)
/* DD5EC 80146EEC AC820048 */  sw        $v0, 0x48($a0)
/* DD5F0 80146EF0 8FAF0054 */  lw        $t7, 0x54($sp)
/* DD5F4 80146EF4 24820058 */  addiu     $v0, $a0, 0x58
/* DD5F8 80146EF8 00AF2821 */  addu      $a1, $a1, $t7
/* DD5FC 80146EFC 30A50FFF */  andi      $a1, $a1, 0xfff
/* DD600 80146F00 00052B00 */  sll       $a1, $a1, 0xc
/* DD604 80146F04 00A72825 */  or        $a1, $a1, $a3
/* DD608 80146F08 AC85004C */  sw        $a1, 0x4c($a0)
/* DD60C 80146F0C AE020000 */  sw        $v0, ($s0)
/* DD610 80146F10 24820060 */  addiu     $v0, $a0, 0x60
/* DD614 80146F14 AC8E0050 */  sw        $t6, 0x50($a0)
/* DD618 80146F18 AC800054 */  sw        $zero, 0x54($a0)
/* DD61C 80146F1C AE020000 */  sw        $v0, ($s0)
/* DD620 80146F20 AC8D0058 */  sw        $t5, 0x58($a0)
/* DD624 80146F24 AC9E005C */  sw        $fp, 0x5c($a0)
/* DD628 80146F28 8FB70070 */  lw        $s7, 0x70($sp)
/* DD62C 80146F2C 0277102A */  slt       $v0, $s3, $s7
/* DD630 80146F30 1440FF66 */  bnez      $v0, .L80146CCC
/* DD634 80146F34 02B1A821 */   addu     $s5, $s5, $s1
.L80146F38:
/* DD638 80146F38 8FAF0038 */  lw        $t7, 0x38($sp)
/* DD63C 80146F3C 11E000A5 */  beqz      $t7, .L801471D4
/* DD640 80146F40 00000000 */   nop
/* DD644 80146F44 3C013ED6 */  lui       $at, 0x3ed6
/* DD648 80146F48 34217744 */  ori       $at, $at, 0x7744
/* DD64C 80146F4C 44810000 */  mtc1      $at, $f0
/* DD650 80146F50 44936000 */  mtc1      $s3, $f12
/* DD654 80146F54 00000000 */  nop
/* DD658 80146F58 46806320 */  cvt.s.w   $f12, $f12
/* DD65C 80146F5C 46006302 */  mul.s     $f12, $f12, $f0
/* DD660 80146F60 00000000 */  nop
/* DD664 80146F64 3C018015 */  lui       $at, %hi(D_8014F134)
/* DD668 80146F68 C420F134 */  lwc1      $f0, %lo(D_8014F134)($at)
/* DD66C 80146F6C 460C0300 */  add.s     $f12, $f0, $f12
/* DD670 80146F70 0C00A85B */  jal       sin_rad
/* DD674 80146F74 AFB9006C */   sw       $t9, 0x6c($sp)
/* DD678 80146F78 02330018 */  mult      $s1, $s3
/* DD67C 80146F7C 3C014040 */  lui       $at, 0x4040
/* DD680 80146F80 44811000 */  mtc1      $at, $f2
/* DD684 80146F84 3C0A8007 */  lui       $t2, %hi(gGameStatusPtr)
/* DD688 80146F88 8D4A419C */  lw        $t2, %lo(gGameStatusPtr)($t2)
/* DD68C 80146F8C 8FB9006C */  lw        $t9, 0x6c($sp)
/* DD690 80146F90 46020082 */  mul.s     $f2, $f0, $f2
/* DD694 80146F94 00000000 */  nop
/* DD698 80146F98 85420152 */  lh        $v0, 0x152($t2)
/* DD69C 80146F9C 85430150 */  lh        $v1, 0x150($t2)
/* DD6A0 80146FA0 44820000 */  mtc1      $v0, $f0
/* DD6A4 80146FA4 00000000 */  nop
/* DD6A8 80146FA8 46800020 */  cvt.s.w   $f0, $f0
/* DD6AC 80146FAC 3C028015 */  lui       $v0, %hi(D_8014F130)
/* DD6B0 80146FB0 9442F130 */  lhu       $v0, %lo(D_8014F130)($v0)
/* DD6B4 80146FB4 00006812 */  mflo      $t5
/* DD6B8 80146FB8 004D2021 */  addu      $a0, $v0, $t5
/* DD6BC 80146FBC 46020000 */  add.s     $f0, $f0, $f2
/* DD6C0 80146FC0 00041400 */  sll       $v0, $a0, 0x10
/* DD6C4 80146FC4 00021403 */  sra       $v0, $v0, 0x10
/* DD6C8 80146FC8 46000000 */  add.s     $f0, $f0, $f0
/* DD6CC 80146FCC 0062182A */  slt       $v1, $v1, $v0
/* DD6D0 80146FD0 95420150 */  lhu       $v0, 0x150($t2)
/* DD6D4 80146FD4 4600020D */  trunc.w.s $f8, $f0
/* DD6D8 80146FD8 44184000 */  mfc1      $t8, $f8
/* DD6DC 80146FDC 10600002 */  beqz      $v1, .L80146FE8
/* DD6E0 80146FE0 0080602D */   daddu    $t4, $a0, $zero
/* DD6E4 80146FE4 00826023 */  subu      $t4, $a0, $v0
.L80146FE8:
/* DD6E8 80146FE8 3C07F548 */  lui       $a3, 0xf548
/* DD6EC 80146FEC 34E74A00 */  ori       $a3, $a3, 0x4a00
/* DD6F0 80146FF0 3C050749 */  lui       $a1, 0x749
/* DD6F4 80146FF4 34A5C000 */  ori       $a1, $a1, 0xc000
/* DD6F8 80146FF8 3C090049 */  lui       $t1, 0x49
/* DD6FC 80146FFC 3529C000 */  ori       $t1, $t1, 0xc000
/* DD700 80147000 3C0B1000 */  lui       $t3, 0x1000
/* DD704 80147004 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* DD708 80147008 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* DD70C 8014700C 356B0400 */  ori       $t3, $t3, 0x400
/* DD710 80147010 2642FFFF */  addiu     $v0, $s2, -1
/* DD714 80147014 30420FFF */  andi      $v0, $v0, 0xfff
/* DD718 80147018 3C03FD48 */  lui       $v1, 0xfd48
/* DD71C 8014701C 8D040000 */  lw        $a0, ($t0)
/* DD720 80147020 00431025 */  or        $v0, $v0, $v1
/* DD724 80147024 0080302D */  daddu     $a2, $a0, $zero
/* DD728 80147028 24840008 */  addiu     $a0, $a0, 8
/* DD72C 8014702C AD040000 */  sw        $a0, ($t0)
/* DD730 80147030 ACC20000 */  sw        $v0, ($a2)
/* DD734 80147034 24820008 */  addiu     $v0, $a0, 8
/* DD738 80147038 AD020000 */  sw        $v0, ($t0)
/* DD73C 8014703C 24820010 */  addiu     $v0, $a0, 0x10
/* DD740 80147040 AD020000 */  sw        $v0, ($t0)
/* DD744 80147044 24820018 */  addiu     $v0, $a0, 0x18
/* DD748 80147048 AD020000 */  sw        $v0, ($t0)
/* DD74C 8014704C 24820020 */  addiu     $v0, $a0, 0x20
/* DD750 80147050 AD020000 */  sw        $v0, ($t0)
/* DD754 80147054 24820028 */  addiu     $v0, $a0, 0x28
/* DD758 80147058 AD020000 */  sw        $v0, ($t0)
/* DD75C 8014705C 24820030 */  addiu     $v0, $a0, 0x30
/* DD760 80147060 AD020000 */  sw        $v0, ($t0)
/* DD764 80147064 24820038 */  addiu     $v0, $a0, 0x38
/* DD768 80147068 AD020000 */  sw        $v0, ($t0)
/* DD76C 8014706C 24820040 */  addiu     $v0, $a0, 0x40
/* DD770 80147070 AD020000 */  sw        $v0, ($t0)
/* DD774 80147074 000C1400 */  sll       $v0, $t4, 0x10
/* DD778 80147078 00021403 */  sra       $v0, $v0, 0x10
/* DD77C 8014707C 24830048 */  addiu     $v1, $a0, 0x48
/* DD780 80147080 02420018 */  mult      $s2, $v0
/* DD784 80147084 AD030000 */  sw        $v1, ($t0)
/* DD788 80147088 8D420154 */  lw        $v0, 0x154($t2)
/* DD78C 8014708C 24830050 */  addiu     $v1, $a0, 0x50
/* DD790 80147090 AD030000 */  sw        $v1, ($t0)
/* DD794 80147094 3C03E700 */  lui       $v1, 0xe700
/* DD798 80147098 00195080 */  sll       $t2, $t9, 2
/* DD79C 8014709C 00007812 */  mflo      $t7
/* DD7A0 801470A0 004F1021 */  addu      $v0, $v0, $t7
/* DD7A4 801470A4 ACC20004 */  sw        $v0, 4($a2)
/* DD7A8 801470A8 3C020700 */  lui       $v0, 0x700
/* DD7AC 801470AC AC820004 */  sw        $v0, 4($a0)
/* DD7B0 801470B0 3C02E600 */  lui       $v0, 0xe600
/* DD7B4 801470B4 AC820008 */  sw        $v0, 8($a0)
/* DD7B8 801470B8 3C02F400 */  lui       $v0, 0xf400
/* DD7BC 801470BC AC870000 */  sw        $a3, ($a0)
/* DD7C0 801470C0 AC80000C */  sw        $zero, 0xc($a0)
/* DD7C4 801470C4 AC820010 */  sw        $v0, 0x10($a0)
/* DD7C8 801470C8 8FB70038 */  lw        $s7, 0x38($sp)
/* DD7CC 801470CC 00183040 */  sll       $a2, $t8, 1
/* DD7D0 801470D0 26E2FFFF */  addiu     $v0, $s7, -1
/* DD7D4 801470D4 00021080 */  sll       $v0, $v0, 2
/* DD7D8 801470D8 30420FFF */  andi      $v0, $v0, 0xfff
/* DD7DC 801470DC 00452825 */  or        $a1, $v0, $a1
/* DD7E0 801470E0 AC830018 */  sw        $v1, 0x18($a0)
/* DD7E4 801470E4 3C03F200 */  lui       $v1, 0xf200
/* DD7E8 801470E8 00491025 */  or        $v0, $v0, $t1
/* DD7EC 801470EC AC82002C */  sw        $v0, 0x2c($a0)
/* DD7F0 801470F0 24C2FFFF */  addiu     $v0, $a2, -1
/* DD7F4 801470F4 00591021 */  addu      $v0, $v0, $t9
/* DD7F8 801470F8 00021080 */  sll       $v0, $v0, 2
/* DD7FC 801470FC 30420FFF */  andi      $v0, $v0, 0xfff
/* DD800 80147100 00021300 */  sll       $v0, $v0, 0xc
/* DD804 80147104 AC830028 */  sw        $v1, 0x28($a0)
/* DD808 80147108 3C03E400 */  lui       $v1, 0xe400
/* DD80C 8014710C 3C09E100 */  lui       $t1, 0xe100
/* DD810 80147110 00CA3021 */  addu      $a2, $a2, $t2
/* DD814 80147114 30C60FFF */  andi      $a2, $a2, 0xfff
/* DD818 80147118 00063300 */  sll       $a2, $a2, 0xc
/* DD81C 8014711C AC850014 */  sw        $a1, 0x14($a0)
/* DD820 80147120 AC80001C */  sw        $zero, 0x1c($a0)
/* DD824 80147124 AC870020 */  sw        $a3, 0x20($a0)
/* DD828 80147128 AC800024 */  sw        $zero, 0x24($a0)
/* DD82C 8014712C 8FAF0030 */  lw        $t7, 0x30($sp)
/* DD830 80147130 8FB70034 */  lw        $s7, 0x34($sp)
/* DD834 80147134 25E5FFFF */  addiu     $a1, $t7, -1
/* DD838 80147138 02E52821 */  addu      $a1, $s7, $a1
/* DD83C 8014713C 00052880 */  sll       $a1, $a1, 2
/* DD840 80147140 30A50FFF */  andi      $a1, $a1, 0xfff
/* DD844 80147144 00A32825 */  or        $a1, $a1, $v1
/* DD848 80147148 00451025 */  or        $v0, $v0, $a1
/* DD84C 8014714C AC820030 */  sw        $v0, 0x30($a0)
/* DD850 80147150 31420FFF */  andi      $v0, $t2, 0xfff
/* DD854 80147154 00021300 */  sll       $v0, $v0, 0xc
/* DD858 80147158 01AF3821 */  addu      $a3, $t5, $t7
/* DD85C 8014715C 00073880 */  sll       $a3, $a3, 2
/* DD860 80147160 30E70FFF */  andi      $a3, $a3, 0xfff
/* DD864 80147164 00471025 */  or        $v0, $v0, $a3
/* DD868 80147168 AC820034 */  sw        $v0, 0x34($a0)
/* DD86C 8014716C 00121140 */  sll       $v0, $s2, 5
/* DD870 80147170 00181900 */  sll       $v1, $t8, 4
/* DD874 80147174 00431023 */  subu      $v0, $v0, $v1
/* DD878 80147178 00021400 */  sll       $v0, $v0, 0x10
/* DD87C 8014717C 3C03F100 */  lui       $v1, 0xf100
/* DD880 80147180 AC82003C */  sw        $v0, 0x3c($a0)
/* DD884 80147184 02591021 */  addu      $v0, $s2, $t9
/* DD888 80147188 2442FFFF */  addiu     $v0, $v0, -1
/* DD88C 8014718C 00021080 */  sll       $v0, $v0, 2
/* DD890 80147190 30420FFF */  andi      $v0, $v0, 0xfff
/* DD894 80147194 00021300 */  sll       $v0, $v0, 0xc
/* DD898 80147198 00451025 */  or        $v0, $v0, $a1
/* DD89C 8014719C 00C73025 */  or        $a2, $a2, $a3
/* DD8A0 801471A0 AC890038 */  sw        $t1, 0x38($a0)
/* DD8A4 801471A4 AC830040 */  sw        $v1, 0x40($a0)
/* DD8A8 801471A8 AC8B0044 */  sw        $t3, 0x44($a0)
/* DD8AC 801471AC AC820048 */  sw        $v0, 0x48($a0)
/* DD8B0 801471B0 24820058 */  addiu     $v0, $a0, 0x58
/* DD8B4 801471B4 AC86004C */  sw        $a2, 0x4c($a0)
/* DD8B8 801471B8 AD020000 */  sw        $v0, ($t0)
/* DD8BC 801471BC 24820060 */  addiu     $v0, $a0, 0x60
/* DD8C0 801471C0 AC890050 */  sw        $t1, 0x50($a0)
/* DD8C4 801471C4 AC800054 */  sw        $zero, 0x54($a0)
/* DD8C8 801471C8 AD020000 */  sw        $v0, ($t0)
/* DD8CC 801471CC AC830058 */  sw        $v1, 0x58($a0)
/* DD8D0 801471D0 AC8B005C */  sw        $t3, 0x5c($a0)
.L801471D4:
/* DD8D4 801471D4 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* DD8D8 801471D8 8FBE00A0 */  lw        $fp, 0xa0($sp)
/* DD8DC 801471DC 8FB7009C */  lw        $s7, 0x9c($sp)
/* DD8E0 801471E0 8FB60098 */  lw        $s6, 0x98($sp)
/* DD8E4 801471E4 8FB50094 */  lw        $s5, 0x94($sp)
/* DD8E8 801471E8 8FB40090 */  lw        $s4, 0x90($sp)
/* DD8EC 801471EC 8FB3008C */  lw        $s3, 0x8c($sp)
/* DD8F0 801471F0 8FB20088 */  lw        $s2, 0x88($sp)
/* DD8F4 801471F4 8FB10084 */  lw        $s1, 0x84($sp)
/* DD8F8 801471F8 8FB00080 */  lw        $s0, 0x80($sp)
/* DD8FC 801471FC D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* DD900 80147200 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* DD904 80147204 03E00008 */  jr        $ra
/* DD908 80147208 27BD00B8 */   addiu    $sp, $sp, 0xb8
