.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80150718
.double 3.2

glabel D_80150720
.double 255.0

glabel D_80150728
.double 14.4

.section .text

glabel msg_draw_choice_pointer
/* BD678 80126F78 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* BD67C 80126F7C AFB00038 */  sw        $s0, 0x38($sp)
/* BD680 80126F80 0080802D */  daddu     $s0, $a0, $zero
/* BD684 80126F84 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BD688 80126F88 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BD68C 80126F8C 3C0316C1 */  lui       $v1, 0x16c1
/* BD690 80126F90 AFBF0058 */  sw        $ra, 0x58($sp)
/* BD694 80126F94 AFB70054 */  sw        $s7, 0x54($sp)
/* BD698 80126F98 AFB60050 */  sw        $s6, 0x50($sp)
/* BD69C 80126F9C AFB5004C */  sw        $s5, 0x4c($sp)
/* BD6A0 80126FA0 AFB40048 */  sw        $s4, 0x48($sp)
/* BD6A4 80126FA4 AFB30044 */  sw        $s3, 0x44($sp)
/* BD6A8 80126FA8 AFB20040 */  sw        $s2, 0x40($sp)
/* BD6AC 80126FAC AFB1003C */  sw        $s1, 0x3c($sp)
/* BD6B0 80126FB0 94440134 */  lhu       $a0, 0x134($v0)
/* BD6B4 80126FB4 34636C17 */  ori       $v1, $v1, 0x6c17
/* BD6B8 80126FB8 000410C2 */  srl       $v0, $a0, 3
/* BD6BC 80126FBC 00430019 */  multu     $v0, $v1
/* BD6C0 80126FC0 241700FF */  addiu     $s7, $zero, 0xff
/* BD6C4 80126FC4 24160048 */  addiu     $s6, $zero, 0x48
/* BD6C8 80126FC8 0000C010 */  mfhi      $t8
/* BD6CC 80126FCC 00181082 */  srl       $v0, $t8, 2
/* BD6D0 80126FD0 00021840 */  sll       $v1, $v0, 1
/* BD6D4 80126FD4 00621821 */  addu      $v1, $v1, $v0
/* BD6D8 80126FD8 00031100 */  sll       $v0, $v1, 4
/* BD6DC 80126FDC 00431023 */  subu      $v0, $v0, $v1
/* BD6E0 80126FE0 000210C0 */  sll       $v0, $v0, 3
/* BD6E4 80126FE4 00822023 */  subu      $a0, $a0, $v0
/* BD6E8 80126FE8 920304F8 */  lbu       $v1, 0x4f8($s0)
/* BD6EC 80126FEC 24020007 */  addiu     $v0, $zero, 7
/* BD6F0 80126FF0 10620006 */  beq       $v1, $v0, .L8012700C
/* BD6F4 80126FF4 3088FFFF */   andi     $t0, $a0, 0xffff
/* BD6F8 80126FF8 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BD6FC 80126FFC 3C030002 */  lui       $v1, 2
/* BD700 80127000 00431024 */  and       $v0, $v0, $v1
/* BD704 80127004 1040000F */  beqz      $v0, .L80127044
/* BD708 80127008 00000000 */   nop
.L8012700C:
/* BD70C 8012700C 920304EE */  lbu       $v1, 0x4ee($s0)
/* BD710 80127010 86020456 */  lh        $v0, 0x456($s0)
/* BD714 80127014 8604045A */  lh        $a0, 0x45a($s0)
/* BD718 80127018 00031840 */  sll       $v1, $v1, 1
/* BD71C 8012701C 02031821 */  addu      $v1, $s0, $v1
/* BD720 80127020 00441021 */  addu      $v0, $v0, $a0
/* BD724 80127024 946504D0 */  lhu       $a1, 0x4d0($v1)
/* BD728 80127028 8604045C */  lh        $a0, 0x45c($s0)
/* BD72C 8012702C 0045A021 */  addu      $s4, $v0, $a1
/* BD730 80127030 86020458 */  lh        $v0, 0x458($s0)
/* BD734 80127034 946304DC */  lhu       $v1, 0x4dc($v1)
/* BD738 80127038 00441021 */  addu      $v0, $v0, $a0
/* BD73C 8012703C 08049C4C */  j         .L80127130
/* BD740 80127040 0043A821 */   addu     $s5, $v0, $v1
.L80127044:
/* BD744 80127044 920204ED */  lbu       $v0, 0x4ed($s0)
/* BD748 80127048 3C013FF0 */  lui       $at, 0x3ff0
/* BD74C 8012704C 44811800 */  mtc1      $at, $f3
/* BD750 80127050 44801000 */  mtc1      $zero, $f2
/* BD754 80127054 86030456 */  lh        $v1, 0x456($s0)
/* BD758 80127058 920604EE */  lbu       $a2, 0x4ee($s0)
/* BD75C 8012705C 920504EC */  lbu       $a1, 0x4ec($s0)
/* BD760 80127060 8604045C */  lh        $a0, 0x45c($s0)
/* BD764 80127064 44820000 */  mtc1      $v0, $f0
/* BD768 80127068 00000000 */  nop
/* BD76C 8012706C 46800021 */  cvt.d.w   $f0, $f0
/* BD770 80127070 00063040 */  sll       $a2, $a2, 1
/* BD774 80127074 02063021 */  addu      $a2, $s0, $a2
/* BD778 80127078 00052840 */  sll       $a1, $a1, 1
/* BD77C 8012707C 02052821 */  addu      $a1, $s0, $a1
/* BD780 80127080 46220000 */  add.d     $f0, $f0, $f2
/* BD784 80127084 3C014018 */  lui       $at, 0x4018
/* BD788 80127088 44811800 */  mtc1      $at, $f3
/* BD78C 8012708C 44801000 */  mtc1      $zero, $f2
/* BD790 80127090 8602045A */  lh        $v0, 0x45a($s0)
/* BD794 80127094 94C704D0 */  lhu       $a3, 0x4d0($a2)
/* BD798 80127098 00621821 */  addu      $v1, $v1, $v0
/* BD79C 8012709C 00673821 */  addu      $a3, $v1, $a3
/* BD7A0 801270A0 94A204D0 */  lhu       $v0, 0x4d0($a1)
/* BD7A4 801270A4 46200020 */  cvt.s.d   $f0, $f0
/* BD7A8 801270A8 46000021 */  cvt.d.s   $f0, $f0
/* BD7AC 801270AC 46220003 */  div.d     $f0, $f0, $f2
/* BD7B0 801270B0 46200020 */  cvt.s.d   $f0, $f0
/* BD7B4 801270B4 00621821 */  addu      $v1, $v1, $v0
/* BD7B8 801270B8 00671823 */  subu      $v1, $v1, $a3
/* BD7BC 801270BC 44833000 */  mtc1      $v1, $f6
/* BD7C0 801270C0 00000000 */  nop
/* BD7C4 801270C4 468031A0 */  cvt.s.w   $f6, $f6
/* BD7C8 801270C8 46003182 */  mul.s     $f6, $f6, $f0
/* BD7CC 801270CC 00000000 */  nop
/* BD7D0 801270D0 86020458 */  lh        $v0, 0x458($s0)
/* BD7D4 801270D4 94C304DC */  lhu       $v1, 0x4dc($a2)
/* BD7D8 801270D8 00441021 */  addu      $v0, $v0, $a0
/* BD7DC 801270DC 94A404DC */  lhu       $a0, 0x4dc($a1)
/* BD7E0 801270E0 00431821 */  addu      $v1, $v0, $v1
/* BD7E4 801270E4 00441021 */  addu      $v0, $v0, $a0
/* BD7E8 801270E8 00431023 */  subu      $v0, $v0, $v1
/* BD7EC 801270EC 44822000 */  mtc1      $v0, $f4
/* BD7F0 801270F0 00000000 */  nop
/* BD7F4 801270F4 46802120 */  cvt.s.w   $f4, $f4
/* BD7F8 801270F8 46002102 */  mul.s     $f4, $f4, $f0
/* BD7FC 801270FC 00000000 */  nop
/* BD800 80127100 44871000 */  mtc1      $a3, $f2
/* BD804 80127104 00000000 */  nop
/* BD808 80127108 468010A0 */  cvt.s.w   $f2, $f2
/* BD80C 8012710C 46061080 */  add.s     $f2, $f2, $f6
/* BD810 80127110 44830000 */  mtc1      $v1, $f0
/* BD814 80127114 00000000 */  nop
/* BD818 80127118 46800020 */  cvt.s.w   $f0, $f0
/* BD81C 8012711C 46040000 */  add.s     $f0, $f0, $f4
/* BD820 80127120 4600120D */  trunc.w.s $f8, $f2
/* BD824 80127124 44144000 */  mfc1      $s4, $f8
/* BD828 80127128 4600020D */  trunc.w.s $f8, $f0
/* BD82C 8012712C 44154000 */  mfc1      $s5, $f8
.L80127130:
/* BD830 80127130 00082080 */  sll       $a0, $t0, 2
/* BD834 80127134 00882021 */  addu      $a0, $a0, $t0
/* BD838 80127138 00042080 */  sll       $a0, $a0, 2
/* BD83C 8012713C 00882023 */  subu      $a0, $a0, $t0
/* BD840 80127140 00042040 */  sll       $a0, $a0, 1
/* BD844 80127144 2484010E */  addiu     $a0, $a0, 0x10e
/* BD848 80127148 00042400 */  sll       $a0, $a0, 0x10
/* BD84C 8012714C 0C00A4F5 */  jal       cosine
/* BD850 80127150 00042403 */   sra      $a0, $a0, 0x10
/* BD854 80127154 3C013FF0 */  lui       $at, 0x3ff0
/* BD858 80127158 44811800 */  mtc1      $at, $f3
/* BD85C 8012715C 44801000 */  mtc1      $zero, $f2
/* BD860 80127160 46000021 */  cvt.d.s   $f0, $f0
/* BD864 80127164 46220000 */  add.d     $f0, $f0, $f2
/* BD868 80127168 3C013FE0 */  lui       $at, 0x3fe0
/* BD86C 8012716C 44811800 */  mtc1      $at, $f3
/* BD870 80127170 44801000 */  mtc1      $zero, $f2
/* BD874 80127174 00000000 */  nop
/* BD878 80127178 46220002 */  mul.d     $f0, $f0, $f2
/* BD87C 8012717C 00000000 */  nop
/* BD880 80127180 3C018015 */  lui       $at, %hi(D_80150718)
/* BD884 80127184 D4220718 */  ldc1      $f2, %lo(D_80150718)($at)
/* BD888 80127188 46220002 */  mul.d     $f0, $f0, $f2
/* BD88C 8012718C 00000000 */  nop
/* BD890 80127190 26B50001 */  addiu     $s5, $s5, 1
/* BD894 80127194 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BD898 80127198 44941000 */  mtc1      $s4, $f2
/* BD89C 8012719C 00000000 */  nop
/* BD8A0 801271A0 468010A1 */  cvt.d.w   $f2, $f2
/* BD8A4 801271A4 46201080 */  add.d     $f2, $f2, $f0
/* BD8A8 801271A8 3C030002 */  lui       $v1, 2
/* BD8AC 801271AC 00431024 */  and       $v0, $v0, $v1
/* BD8B0 801271B0 4620120D */  trunc.w.d $f8, $f2
/* BD8B4 801271B4 44144000 */  mfc1      $s4, $f8
/* BD8B8 801271B8 1040003E */  beqz      $v0, .L801272B4
/* BD8BC 801271BC 2694FFFE */   addiu    $s4, $s4, -2
/* BD8C0 801271C0 92020512 */  lbu       $v0, 0x512($s0)
/* BD8C4 801271C4 3C014047 */  lui       $at, 0x4047
/* BD8C8 801271C8 44811800 */  mtc1      $at, $f3
/* BD8CC 801271CC 44801000 */  mtc1      $zero, $f2
/* BD8D0 801271D0 44820000 */  mtc1      $v0, $f0
/* BD8D4 801271D4 00000000 */  nop
/* BD8D8 801271D8 46800021 */  cvt.d.w   $f0, $f0
/* BD8DC 801271DC 46220002 */  mul.d     $f0, $f0, $f2
/* BD8E0 801271E0 00000000 */  nop
/* BD8E4 801271E4 3C018015 */  lui       $at, %hi(D_80150720)
/* BD8E8 801271E8 D4220720 */  ldc1      $f2, %lo(D_80150720)($at)
/* BD8EC 801271EC 46201001 */  sub.d     $f0, $f2, $f0
/* BD8F0 801271F0 3C0141E0 */  lui       $at, 0x41e0
/* BD8F4 801271F4 44811800 */  mtc1      $at, $f3
/* BD8F8 801271F8 44801000 */  mtc1      $zero, $f2
/* BD8FC 801271FC 00000000 */  nop
/* BD900 80127200 4620103E */  c.le.d    $f2, $f0
/* BD904 80127204 00000000 */  nop
/* BD908 80127208 45030005 */  bc1tl     .L80127220
/* BD90C 8012720C 46220001 */   sub.d    $f0, $f0, $f2
/* BD910 80127210 4620020D */  trunc.w.d $f8, $f0
/* BD914 80127214 44034000 */  mfc1      $v1, $f8
/* BD918 80127218 08049C8D */  j         .L80127234
/* BD91C 8012721C 00000000 */   nop
.L80127220:
/* BD920 80127220 3C028000 */  lui       $v0, 0x8000
/* BD924 80127224 4620020D */  trunc.w.d $f8, $f0
/* BD928 80127228 44034000 */  mfc1      $v1, $f8
/* BD92C 8012722C 00000000 */  nop
/* BD930 80127230 00621825 */  or        $v1, $v1, $v0
.L80127234:
/* BD934 80127234 92020512 */  lbu       $v0, 0x512($s0)
/* BD938 80127238 3C018015 */  lui       $at, %hi(D_80150728)
/* BD93C 8012723C D4220728 */  ldc1      $f2, %lo(D_80150728)($at)
/* BD940 80127240 44820000 */  mtc1      $v0, $f0
/* BD944 80127244 00000000 */  nop
/* BD948 80127248 46800021 */  cvt.d.w   $f0, $f0
/* BD94C 8012724C 46220002 */  mul.d     $f0, $f0, $f2
/* BD950 80127250 00000000 */  nop
/* BD954 80127254 3C014052 */  lui       $at, 0x4052
/* BD958 80127258 44811800 */  mtc1      $at, $f3
/* BD95C 8012725C 44801000 */  mtc1      $zero, $f2
/* BD960 80127260 00000000 */  nop
/* BD964 80127264 46201001 */  sub.d     $f0, $f2, $f0
/* BD968 80127268 3C0141E0 */  lui       $at, 0x41e0
/* BD96C 8012726C 44811800 */  mtc1      $at, $f3
/* BD970 80127270 44801000 */  mtc1      $zero, $f2
/* BD974 80127274 00000000 */  nop
/* BD978 80127278 4620103E */  c.le.d    $f2, $f0
/* BD97C 8012727C 00000000 */  nop
/* BD980 80127280 45010005 */  bc1t      .L80127298
/* BD984 80127284 0060B82D */   daddu    $s7, $v1, $zero
/* BD988 80127288 4620020D */  trunc.w.d $f8, $f0
/* BD98C 8012728C 44034000 */  mfc1      $v1, $f8
/* BD990 80127290 08049CAD */  j         .L801272B4
/* BD994 80127294 0060B02D */   daddu    $s6, $v1, $zero
.L80127298:
/* BD998 80127298 46220001 */  sub.d     $f0, $f0, $f2
/* BD99C 8012729C 3C028000 */  lui       $v0, 0x8000
/* BD9A0 801272A0 4620020D */  trunc.w.d $f8, $f0
/* BD9A4 801272A4 44034000 */  mfc1      $v1, $f8
/* BD9A8 801272A8 00000000 */  nop
/* BD9AC 801272AC 00621825 */  or        $v1, $v1, $v0
/* BD9B0 801272B0 0060B02D */  daddu     $s6, $v1, $zero
.L801272B4:
/* BD9B4 801272B4 3C0AE300 */  lui       $t2, 0xe300
/* BD9B8 801272B8 354A1001 */  ori       $t2, $t2, 0x1001
/* BD9BC 801272BC 3C0BF500 */  lui       $t3, 0xf500
/* BD9C0 801272C0 356B0100 */  ori       $t3, $t3, 0x100
/* BD9C4 801272C4 3C0C0703 */  lui       $t4, 0x703
/* BD9C8 801272C8 358CC000 */  ori       $t4, $t4, 0xc000
/* BD9CC 801272CC 3C0FE200 */  lui       $t7, 0xe200
/* BD9D0 801272D0 35EF001C */  ori       $t7, $t7, 0x1c
/* BD9D4 801272D4 3C0D0050 */  lui       $t5, 0x50
/* BD9D8 801272D8 35AD4240 */  ori       $t5, $t5, 0x4240
/* BD9DC 801272DC 3C10FCFF */  lui       $s0, 0xfcff
/* BD9E0 801272E0 361097FF */  ori       $s0, $s0, 0x97ff
/* BD9E4 801272E4 3C0EFF2D */  lui       $t6, 0xff2d
/* BD9E8 801272E8 35CEFEFF */  ori       $t6, $t6, 0xfeff
/* BD9EC 801272EC 3C132828 */  lui       $s3, 0x2828
/* BD9F0 801272F0 36732800 */  ori       $s3, $s3, 0x2800
/* BD9F4 801272F4 3C128010 */  lui       $s2, %hi(D_800FBB60)
/* BD9F8 801272F8 2652BB60 */  addiu     $s2, $s2, %lo(D_800FBB60)
/* BD9FC 801272FC 0240202D */  daddu     $a0, $s2, $zero
/* BDA00 80127300 24050010 */  addiu     $a1, $zero, 0x10
/* BDA04 80127304 00A0302D */  daddu     $a2, $a1, $zero
/* BDA08 80127308 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* BDA0C 8012730C 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* BDA10 80127310 24070002 */  addiu     $a3, $zero, 2
/* BDA14 80127314 3C09E700 */  lui       $t1, 0xe700
/* BDA18 80127318 8D030000 */  lw        $v1, ($t0)
/* BDA1C 8012731C 3C118010 */  lui       $s1, %hi(D_800FBBE0)
/* BDA20 80127320 2631BBE0 */  addiu     $s1, $s1, %lo(D_800FBBE0)
/* BDA24 80127324 0060102D */  daddu     $v0, $v1, $zero
/* BDA28 80127328 24630008 */  addiu     $v1, $v1, 8
/* BDA2C 8012732C AD030000 */  sw        $v1, ($t0)
/* BDA30 80127330 AC490000 */  sw        $t1, ($v0)
/* BDA34 80127334 AC400004 */  sw        $zero, 4($v0)
/* BDA38 80127338 24620008 */  addiu     $v0, $v1, 8
/* BDA3C 8012733C AD020000 */  sw        $v0, ($t0)
/* BDA40 80127340 34028000 */  ori       $v0, $zero, 0x8000
/* BDA44 80127344 AC620004 */  sw        $v0, 4($v1)
/* BDA48 80127348 00651021 */  addu      $v0, $v1, $a1
/* BDA4C 8012734C AC6A0000 */  sw        $t2, ($v1)
/* BDA50 80127350 AD020000 */  sw        $v0, ($t0)
/* BDA54 80127354 3C02FD10 */  lui       $v0, 0xfd10
/* BDA58 80127358 AC620008 */  sw        $v0, 8($v1)
/* BDA5C 8012735C 24620018 */  addiu     $v0, $v1, 0x18
/* BDA60 80127360 AC71000C */  sw        $s1, 0xc($v1)
/* BDA64 80127364 AD020000 */  sw        $v0, ($t0)
/* BDA68 80127368 3C02E800 */  lui       $v0, 0xe800
/* BDA6C 8012736C AC620010 */  sw        $v0, 0x10($v1)
/* BDA70 80127370 24620020 */  addiu     $v0, $v1, 0x20
/* BDA74 80127374 AC600014 */  sw        $zero, 0x14($v1)
/* BDA78 80127378 AD020000 */  sw        $v0, ($t0)
/* BDA7C 8012737C 3C020700 */  lui       $v0, 0x700
/* BDA80 80127380 AC62001C */  sw        $v0, 0x1c($v1)
/* BDA84 80127384 24620028 */  addiu     $v0, $v1, 0x28
/* BDA88 80127388 AC6B0018 */  sw        $t3, 0x18($v1)
/* BDA8C 8012738C AD020000 */  sw        $v0, ($t0)
/* BDA90 80127390 3C02E600 */  lui       $v0, 0xe600
/* BDA94 80127394 AC620020 */  sw        $v0, 0x20($v1)
/* BDA98 80127398 24620030 */  addiu     $v0, $v1, 0x30
/* BDA9C 8012739C AC600024 */  sw        $zero, 0x24($v1)
/* BDAA0 801273A0 AD020000 */  sw        $v0, ($t0)
/* BDAA4 801273A4 3C02F000 */  lui       $v0, 0xf000
/* BDAA8 801273A8 AC620028 */  sw        $v0, 0x28($v1)
/* BDAAC 801273AC 24620038 */  addiu     $v0, $v1, 0x38
/* BDAB0 801273B0 AC6C002C */  sw        $t4, 0x2c($v1)
/* BDAB4 801273B4 AD020000 */  sw        $v0, ($t0)
/* BDAB8 801273B8 24620040 */  addiu     $v0, $v1, 0x40
/* BDABC 801273BC AC690030 */  sw        $t1, 0x30($v1)
/* BDAC0 801273C0 AC600034 */  sw        $zero, 0x34($v1)
/* BDAC4 801273C4 AD020000 */  sw        $v0, ($t0)
/* BDAC8 801273C8 24620048 */  addiu     $v0, $v1, 0x48
/* BDACC 801273CC AC6F0038 */  sw        $t7, 0x38($v1)
/* BDAD0 801273D0 AC6D003C */  sw        $t5, 0x3c($v1)
/* BDAD4 801273D4 AD020000 */  sw        $v0, ($t0)
/* BDAD8 801273D8 24620050 */  addiu     $v0, $v1, 0x50
/* BDADC 801273DC AC700040 */  sw        $s0, 0x40($v1)
/* BDAE0 801273E0 AC6E0044 */  sw        $t6, 0x44($v1)
/* BDAE4 801273E4 AD020000 */  sw        $v0, ($t0)
/* BDAE8 801273E8 3C02FA00 */  lui       $v0, 0xfa00
/* BDAEC 801273EC AC620048 */  sw        $v0, 0x48($v1)
/* BDAF0 801273F0 32C200FF */  andi      $v0, $s6, 0xff
/* BDAF4 801273F4 00531025 */  or        $v0, $v0, $s3
/* BDAF8 801273F8 AC62004C */  sw        $v0, 0x4c($v1)
/* BDAFC 801273FC 02871021 */  addu      $v0, $s4, $a3
/* BDB00 80127400 00A21004 */  sllv      $v0, $v0, $a1
/* BDB04 80127404 00A21007 */  srav      $v0, $v0, $a1
/* BDB08 80127408 AFA20014 */  sw        $v0, 0x14($sp)
/* BDB0C 8012740C 02A71021 */  addu      $v0, $s5, $a3
/* BDB10 80127410 00A21004 */  sllv      $v0, $v0, $a1
/* BDB14 80127414 00A21007 */  srav      $v0, $v0, $a1
/* BDB18 80127418 AFA20018 */  sw        $v0, 0x18($sp)
/* BDB1C 8012741C 2402000A */  addiu     $v0, $zero, 0xa
/* BDB20 80127420 2410012C */  addiu     $s0, $zero, 0x12c
/* BDB24 80127424 AFA2001C */  sw        $v0, 0x1c($sp)
/* BDB28 80127428 AFA20020 */  sw        $v0, 0x20($sp)
/* BDB2C 8012742C 240200DC */  addiu     $v0, $zero, 0xdc
/* BDB30 80127430 AFA00010 */  sw        $zero, 0x10($sp)
/* BDB34 80127434 AFB00024 */  sw        $s0, 0x24($sp)
/* BDB38 80127438 0C04BB25 */  jal       draw_image_with_clipping
/* BDB3C 8012743C AFA20028 */   sw       $v0, 0x28($sp)
/* BDB40 80127440 0240202D */  daddu     $a0, $s2, $zero
/* BDB44 80127444 24050010 */  addiu     $a1, $zero, 0x10
/* BDB48 80127448 00A0302D */  daddu     $a2, $a1, $zero
/* BDB4C 8012744C 24070002 */  addiu     $a3, $zero, 2
/* BDB50 80127450 00B41004 */  sllv      $v0, $s4, $a1
/* BDB54 80127454 00A21007 */  srav      $v0, $v0, $a1
/* BDB58 80127458 AFA20018 */  sw        $v0, 0x18($sp)
/* BDB5C 8012745C 00B51004 */  sllv      $v0, $s5, $a1
/* BDB60 80127460 00A21007 */  srav      $v0, $v0, $a1
/* BDB64 80127464 AFA2001C */  sw        $v0, 0x1c($sp)
/* BDB68 80127468 24020014 */  addiu     $v0, $zero, 0x14
/* BDB6C 8012746C AFA20020 */  sw        $v0, 0x20($sp)
/* BDB70 80127470 AFA20024 */  sw        $v0, 0x24($sp)
/* BDB74 80127474 240200C8 */  addiu     $v0, $zero, 0xc8
/* BDB78 80127478 AFA2002C */  sw        $v0, 0x2c($sp)
/* BDB7C 8012747C 32E200FF */  andi      $v0, $s7, 0xff
/* BDB80 80127480 AFA00010 */  sw        $zero, 0x10($sp)
/* BDB84 80127484 AFB10014 */  sw        $s1, 0x14($sp)
/* BDB88 80127488 AFB00028 */  sw        $s0, 0x28($sp)
/* BDB8C 8012748C 0C04BA68 */  jal       draw_ci_image_with_clipping
/* BDB90 80127490 AFA20030 */   sw       $v0, 0x30($sp)
/* BDB94 80127494 8FBF0058 */  lw        $ra, 0x58($sp)
/* BDB98 80127498 8FB70054 */  lw        $s7, 0x54($sp)
/* BDB9C 8012749C 8FB60050 */  lw        $s6, 0x50($sp)
/* BDBA0 801274A0 8FB5004C */  lw        $s5, 0x4c($sp)
/* BDBA4 801274A4 8FB40048 */  lw        $s4, 0x48($sp)
/* BDBA8 801274A8 8FB30044 */  lw        $s3, 0x44($sp)
/* BDBAC 801274AC 8FB20040 */  lw        $s2, 0x40($sp)
/* BDBB0 801274B0 8FB1003C */  lw        $s1, 0x3c($sp)
/* BDBB4 801274B4 8FB00038 */  lw        $s0, 0x38($sp)
/* BDBB8 801274B8 03E00008 */  jr        $ra
/* BDBBC 801274BC 27BD0060 */   addiu    $sp, $sp, 0x60
