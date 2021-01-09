.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_9AE720
/* 9AE720 80240020 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* 9AE724 80240024 3C06E300 */  lui       $a2, 0xe300
/* 9AE728 80240028 34C60A01 */  ori       $a2, $a2, 0xa01
/* 9AE72C 8024002C 3C07D9C0 */  lui       $a3, 0xd9c0
/* 9AE730 80240030 34E7F9FB */  ori       $a3, $a3, 0xf9fb
/* 9AE734 80240034 3C09D9FF */  lui       $t1, 0xd9ff
/* 9AE738 80240038 3529FFFF */  ori       $t1, $t1, 0xffff
/* 9AE73C 8024003C 3C080020 */  lui       $t0, 0x20
/* 9AE740 80240040 35080005 */  ori       $t0, $t0, 5
/* 9AE744 80240044 3C0AD700 */  lui       $t2, 0xd700
/* 9AE748 80240048 354A0002 */  ori       $t2, $t2, 2
/* 9AE74C 8024004C 3C0BE300 */  lui       $t3, 0xe300
/* 9AE750 80240050 356B0F00 */  ori       $t3, $t3, 0xf00
/* 9AE754 80240054 3C0CE300 */  lui       $t4, 0xe300
/* 9AE758 80240058 358C0C00 */  ori       $t4, $t4, 0xc00
/* 9AE75C 8024005C 3C0DE300 */  lui       $t5, 0xe300
/* 9AE760 80240060 35AD1201 */  ori       $t5, $t5, 0x1201
/* 9AE764 80240064 3C0EE300 */  lui       $t6, 0xe300
/* 9AE768 80240068 35CE1801 */  ori       $t6, $t6, 0x1801
/* 9AE76C 8024006C 3C0FE300 */  lui       $t7, 0xe300
/* 9AE770 80240070 35EF0D01 */  ori       $t7, $t7, 0xd01
/* 9AE774 80240074 AFB000C0 */  sw        $s0, 0xc0($sp)
/* 9AE778 80240078 3C10E300 */  lui       $s0, 0xe300
/* 9AE77C 8024007C 36101402 */  ori       $s0, $s0, 0x1402
/* 9AE780 80240080 AFB300CC */  sw        $s3, 0xcc($sp)
/* 9AE784 80240084 3C13E300 */  lui       $s3, 0xe300
/* 9AE788 80240088 36731700 */  ori       $s3, $s3, 0x1700
/* 9AE78C 8024008C AFB400D0 */  sw        $s4, 0xd0($sp)
/* 9AE790 80240090 3C14E200 */  lui       $s4, 0xe200
/* 9AE794 80240094 36941E01 */  ori       $s4, $s4, 0x1e01
/* 9AE798 80240098 AFB200C8 */  sw        $s2, 0xc8($sp)
/* 9AE79C 8024009C 27B20040 */  addiu     $s2, $sp, 0x40
/* 9AE7A0 802400A0 0240202D */  daddu     $a0, $s2, $zero
/* 9AE7A4 802400A4 AFB500D4 */  sw        $s5, 0xd4($sp)
/* 9AE7A8 802400A8 3C150001 */  lui       $s5, 1
/* 9AE7AC 802400AC AFB100C4 */  sw        $s1, 0xc4($sp)
/* 9AE7B0 802400B0 3C11800A */  lui       $s1, %hi(D_8009A66C)
/* 9AE7B4 802400B4 2631A66C */  addiu     $s1, $s1, %lo(D_8009A66C)
/* 9AE7B8 802400B8 36B51630 */  ori       $s5, $s5, 0x1630
/* 9AE7BC 802400BC AFBF00D8 */  sw        $ra, 0xd8($sp)
/* 9AE7C0 802400C0 F7B600E8 */  sdc1      $f22, 0xe8($sp)
/* 9AE7C4 802400C4 F7B400E0 */  sdc1      $f20, 0xe0($sp)
/* 9AE7C8 802400C8 8E220000 */  lw        $v0, ($s1)
/* 9AE7CC 802400CC 3C03E700 */  lui       $v1, 0xe700
/* 9AE7D0 802400D0 0040282D */  daddu     $a1, $v0, $zero
/* 9AE7D4 802400D4 24420008 */  addiu     $v0, $v0, 8
/* 9AE7D8 802400D8 AE220000 */  sw        $v0, ($s1)
/* 9AE7DC 802400DC ACA30000 */  sw        $v1, ($a1)
/* 9AE7E0 802400E0 24430008 */  addiu     $v1, $v0, 8
/* 9AE7E4 802400E4 ACA00004 */  sw        $zero, 4($a1)
/* 9AE7E8 802400E8 AE230000 */  sw        $v1, ($s1)
/* 9AE7EC 802400EC 24430010 */  addiu     $v1, $v0, 0x10
/* 9AE7F0 802400F0 AC460000 */  sw        $a2, ($v0)
/* 9AE7F4 802400F4 AC400004 */  sw        $zero, 4($v0)
/* 9AE7F8 802400F8 AE230000 */  sw        $v1, ($s1)
/* 9AE7FC 802400FC 24430018 */  addiu     $v1, $v0, 0x18
/* 9AE800 80240100 AC470008 */  sw        $a3, 8($v0)
/* 9AE804 80240104 AC40000C */  sw        $zero, 0xc($v0)
/* 9AE808 80240108 AE230000 */  sw        $v1, ($s1)
/* 9AE80C 8024010C 24430020 */  addiu     $v1, $v0, 0x20
/* 9AE810 80240110 AC490010 */  sw        $t1, 0x10($v0)
/* 9AE814 80240114 AC480014 */  sw        $t0, 0x14($v0)
/* 9AE818 80240118 AE230000 */  sw        $v1, ($s1)
/* 9AE81C 8024011C 2403FFFF */  addiu     $v1, $zero, -1
/* 9AE820 80240120 AC43001C */  sw        $v1, 0x1c($v0)
/* 9AE824 80240124 24430028 */  addiu     $v1, $v0, 0x28
/* 9AE828 80240128 AC4A0018 */  sw        $t2, 0x18($v0)
/* 9AE82C 8024012C AE230000 */  sw        $v1, ($s1)
/* 9AE830 80240130 24430030 */  addiu     $v1, $v0, 0x30
/* 9AE834 80240134 AC4B0020 */  sw        $t3, 0x20($v0)
/* 9AE838 80240138 AC400024 */  sw        $zero, 0x24($v0)
/* 9AE83C 8024013C AE230000 */  sw        $v1, ($s1)
/* 9AE840 80240140 3C030008 */  lui       $v1, 8
/* 9AE844 80240144 AC43002C */  sw        $v1, 0x2c($v0)
/* 9AE848 80240148 24430038 */  addiu     $v1, $v0, 0x38
/* 9AE84C 8024014C AC4C0028 */  sw        $t4, 0x28($v0)
/* 9AE850 80240150 AE230000 */  sw        $v1, ($s1)
/* 9AE854 80240154 24032000 */  addiu     $v1, $zero, 0x2000
/* 9AE858 80240158 AC4D0030 */  sw        $t5, 0x30($v0)
/* 9AE85C 8024015C AC430034 */  sw        $v1, 0x34($v0)
/* 9AE860 80240160 24430040 */  addiu     $v1, $v0, 0x40
/* 9AE864 80240164 AE230000 */  sw        $v1, ($s1)
/* 9AE868 80240168 240300C0 */  addiu     $v1, $zero, 0xc0
/* 9AE86C 8024016C AC43003C */  sw        $v1, 0x3c($v0)
/* 9AE870 80240170 24430048 */  addiu     $v1, $v0, 0x48
/* 9AE874 80240174 AC4E0038 */  sw        $t6, 0x38($v0)
/* 9AE878 80240178 AE230000 */  sw        $v1, ($s1)
/* 9AE87C 8024017C 24430050 */  addiu     $v1, $v0, 0x50
/* 9AE880 80240180 AC4F0040 */  sw        $t7, 0x40($v0)
/* 9AE884 80240184 AC400044 */  sw        $zero, 0x44($v0)
/* 9AE888 80240188 AE230000 */  sw        $v1, ($s1)
/* 9AE88C 8024018C 24030C00 */  addiu     $v1, $zero, 0xc00
/* 9AE890 80240190 AC500048 */  sw        $s0, 0x48($v0)
/* 9AE894 80240194 AC43004C */  sw        $v1, 0x4c($v0)
/* 9AE898 80240198 AC530050 */  sw        $s3, 0x50($v0)
/* 9AE89C 8024019C 3C138024 */  lui       $s3, %hi(func_80243090_8B3100)
/* 9AE8A0 802401A0 26733090 */  addiu     $s3, $s3, %lo(func_80243090_8B3100)
/* 9AE8A4 802401A4 24430058 */  addiu     $v1, $v0, 0x58
/* 9AE8A8 802401A8 AC400054 */  sw        $zero, 0x54($v0)
/* 9AE8AC 802401AC AC540058 */  sw        $s4, 0x58($v0)
/* 9AE8B0 802401B0 AC40005C */  sw        $zero, 0x5c($v0)
/* 9AE8B4 802401B4 8E650010 */  lw        $a1, 0x10($s3)
/* 9AE8B8 802401B8 8E660014 */  lw        $a2, 0x14($s3)
/* 9AE8BC 802401BC 8E670018 */  lw        $a3, 0x18($s3)
/* 9AE8C0 802401C0 24420060 */  addiu     $v0, $v0, 0x60
/* 9AE8C4 802401C4 AE230000 */  sw        $v1, ($s1)
/* 9AE8C8 802401C8 0C019E40 */  jal       guTranslateF
/* 9AE8CC 802401CC AE220000 */   sw       $v0, ($s1)
/* 9AE8D0 802401D0 27B00080 */  addiu     $s0, $sp, 0x80
/* 9AE8D4 802401D4 8E65001C */  lw        $a1, 0x1c($s3)
/* 9AE8D8 802401D8 3C013F80 */  lui       $at, 0x3f80
/* 9AE8DC 802401DC 4481B000 */  mtc1      $at, $f22
/* 9AE8E0 802401E0 4480A000 */  mtc1      $zero, $f20
/* 9AE8E4 802401E4 4406B000 */  mfc1      $a2, $f22
/* 9AE8E8 802401E8 4407A000 */  mfc1      $a3, $f20
/* 9AE8EC 802401EC 0200202D */  daddu     $a0, $s0, $zero
/* 9AE8F0 802401F0 0C019EC8 */  jal       guRotateF
/* 9AE8F4 802401F4 E7B40010 */   swc1     $f20, 0x10($sp)
/* 9AE8F8 802401F8 0200202D */  daddu     $a0, $s0, $zero
/* 9AE8FC 802401FC 0240282D */  daddu     $a1, $s2, $zero
/* 9AE900 80240200 0C019D80 */  jal       guMtxCatF
/* 9AE904 80240204 0240302D */   daddu    $a2, $s2, $zero
/* 9AE908 80240208 8E650020 */  lw        $a1, 0x20($s3)
/* 9AE90C 8024020C 4406A000 */  mfc1      $a2, $f20
/* 9AE910 80240210 4407B000 */  mfc1      $a3, $f22
/* 9AE914 80240214 0200202D */  daddu     $a0, $s0, $zero
/* 9AE918 80240218 0C019EC8 */  jal       guRotateF
/* 9AE91C 8024021C E7B40010 */   swc1     $f20, 0x10($sp)
/* 9AE920 80240220 0200202D */  daddu     $a0, $s0, $zero
/* 9AE924 80240224 0240282D */  daddu     $a1, $s2, $zero
/* 9AE928 80240228 0C019D80 */  jal       guMtxCatF
/* 9AE92C 8024022C 0240302D */   daddu    $a2, $s2, $zero
/* 9AE930 80240230 8E650024 */  lw        $a1, 0x24($s3)
/* 9AE934 80240234 4406A000 */  mfc1      $a2, $f20
/* 9AE938 80240238 0200202D */  daddu     $a0, $s0, $zero
/* 9AE93C 8024023C E7B60010 */  swc1      $f22, 0x10($sp)
/* 9AE940 80240240 0C019EC8 */  jal       guRotateF
/* 9AE944 80240244 00C0382D */   daddu    $a3, $a2, $zero
/* 9AE948 80240248 0200202D */  daddu     $a0, $s0, $zero
/* 9AE94C 8024024C 0240282D */  daddu     $a1, $s2, $zero
/* 9AE950 80240250 0C019D80 */  jal       guMtxCatF
/* 9AE954 80240254 0240302D */   daddu    $a2, $s2, $zero
/* 9AE958 80240258 8E650028 */  lw        $a1, 0x28($s3)
/* 9AE95C 8024025C 8E66002C */  lw        $a2, 0x2c($s3)
/* 9AE960 80240260 8E670030 */  lw        $a3, 0x30($s3)
/* 9AE964 80240264 0C019DF0 */  jal       guScaleF
/* 9AE968 80240268 0200202D */   daddu    $a0, $s0, $zero
/* 9AE96C 8024026C 0200202D */  daddu     $a0, $s0, $zero
/* 9AE970 80240270 0240282D */  daddu     $a1, $s2, $zero
/* 9AE974 80240274 0C019D80 */  jal       guMtxCatF
/* 9AE978 80240278 0240302D */   daddu    $a2, $s2, $zero
/* 9AE97C 8024027C 0240202D */  daddu     $a0, $s2, $zero
/* 9AE980 80240280 3C108007 */  lui       $s0, %hi(D_800741F0)
/* 9AE984 80240284 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* 9AE988 80240288 3C12800A */  lui       $s2, %hi(D_8009A674)
/* 9AE98C 8024028C 2652A674 */  addiu     $s2, $s2, %lo(D_8009A674)
/* 9AE990 80240290 96050000 */  lhu       $a1, ($s0)
/* 9AE994 80240294 8E420000 */  lw        $v0, ($s2)
/* 9AE998 80240298 00052980 */  sll       $a1, $a1, 6
/* 9AE99C 8024029C 00B52821 */  addu      $a1, $a1, $s5
/* 9AE9A0 802402A0 0C019D40 */  jal       guMtxF2L
/* 9AE9A4 802402A4 00452821 */   addu     $a1, $v0, $a1
/* 9AE9A8 802402A8 3C03DA38 */  lui       $v1, 0xda38
/* 9AE9AC 802402AC 34630002 */  ori       $v1, $v1, 2
/* 9AE9B0 802402B0 8E220000 */  lw        $v0, ($s1)
/* 9AE9B4 802402B4 96040000 */  lhu       $a0, ($s0)
/* 9AE9B8 802402B8 0040282D */  daddu     $a1, $v0, $zero
/* 9AE9BC 802402BC 24420008 */  addiu     $v0, $v0, 8
/* 9AE9C0 802402C0 AE220000 */  sw        $v0, ($s1)
/* 9AE9C4 802402C4 3082FFFF */  andi      $v0, $a0, 0xffff
/* 9AE9C8 802402C8 00021180 */  sll       $v0, $v0, 6
/* 9AE9CC 802402CC ACA30000 */  sw        $v1, ($a1)
/* 9AE9D0 802402D0 8E430000 */  lw        $v1, ($s2)
/* 9AE9D4 802402D4 00551021 */  addu      $v0, $v0, $s5
/* 9AE9D8 802402D8 00621821 */  addu      $v1, $v1, $v0
/* 9AE9DC 802402DC 3C028000 */  lui       $v0, 0x8000
/* 9AE9E0 802402E0 00621821 */  addu      $v1, $v1, $v0
/* 9AE9E4 802402E4 ACA30004 */  sw        $v1, 4($a1)
/* 9AE9E8 802402E8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 9AE9EC 802402EC 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 9AE9F0 802402F0 24020008 */  addiu     $v0, $zero, 8
/* 9AE9F4 802402F4 AE620008 */  sw        $v0, 8($s3)
/* 9AE9F8 802402F8 94620134 */  lhu       $v0, 0x134($v1)
/* 9AE9FC 802402FC 24840001 */  addiu     $a0, $a0, 1
/* 9AEA00 80240300 30430003 */  andi      $v1, $v0, 3
/* 9AEA04 80240304 14600003 */  bnez      $v1, .L80240314
/* 9AEA08 80240308 A6040000 */   sh       $a0, ($s0)
/* 9AEA0C 8024030C 080900CC */  j         .L80240330
/* 9AEA10 80240310 24020025 */   addiu    $v0, $zero, 0x25
.L80240314:
/* 9AEA14 80240314 2C620002 */  sltiu     $v0, $v1, 2
/* 9AEA18 80240318 14400005 */  bnez      $v0, .L80240330
/* 9AEA1C 8024031C 24020026 */   addiu    $v0, $zero, 0x26
/* 9AEA20 80240320 2C620003 */  sltiu     $v0, $v1, 3
/* 9AEA24 80240324 14400002 */  bnez      $v0, .L80240330
/* 9AEA28 80240328 24020027 */   addiu    $v0, $zero, 0x27
/* 9AEA2C 8024032C 24020024 */  addiu     $v0, $zero, 0x24
.L80240330:
/* 9AEA30 80240330 AE62000C */  sw        $v0, 0xc($s3)
/* 9AEA34 80240334 8E650008 */  lw        $a1, 8($s3)
/* 9AEA38 80240338 8E66000C */  lw        $a2, 0xc($s3)
/* 9AEA3C 8024033C 0C0B7811 */  jal       func_802DE044
/* 9AEA40 80240340 27A40030 */   addiu    $a0, $sp, 0x30
/* 9AEA44 80240344 27A50018 */  addiu     $a1, $sp, 0x18
/* 9AEA48 80240348 0000302D */  daddu     $a2, $zero, $zero
/* 9AEA4C 8024034C 27A70040 */  addiu     $a3, $sp, 0x40
/* 9AEA50 80240350 8E640000 */  lw        $a0, ($s3)
/* 9AEA54 80240354 8FA80030 */  lw        $t0, 0x30($sp)
/* 9AEA58 80240358 8FA90034 */  lw        $t1, 0x34($sp)
/* 9AEA5C 8024035C 97AA003A */  lhu       $t2, 0x3a($sp)
/* 9AEA60 80240360 97AB003E */  lhu       $t3, 0x3e($sp)
/* 9AEA64 80240364 8FA30038 */  lw        $v1, 0x38($sp)
/* 9AEA68 80240368 240200FF */  addiu     $v0, $zero, 0xff
/* 9AEA6C 8024036C A3A20028 */  sb        $v0, 0x28($sp)
/* 9AEA70 80240370 000317C2 */  srl       $v0, $v1, 0x1f
/* 9AEA74 80240374 00621821 */  addu      $v1, $v1, $v0
/* 9AEA78 80240378 00031843 */  sra       $v1, $v1, 1
/* 9AEA7C 8024037C 8FA2003C */  lw        $v0, 0x3c($sp)
/* 9AEA80 80240380 00031823 */  negu      $v1, $v1
/* 9AEA84 80240384 AFA80018 */  sw        $t0, 0x18($sp)
/* 9AEA88 80240388 AFA9001C */  sw        $t1, 0x1c($sp)
/* 9AEA8C 8024038C A7AA0020 */  sh        $t2, 0x20($sp)
/* 9AEA90 80240390 A7AB0022 */  sh        $t3, 0x22($sp)
/* 9AEA94 80240394 A7A30024 */  sh        $v1, 0x24($sp)
/* 9AEA98 80240398 00021FC2 */  srl       $v1, $v0, 0x1f
/* 9AEA9C 8024039C 00431021 */  addu      $v0, $v0, $v1
/* 9AEAA0 802403A0 00021043 */  sra       $v0, $v0, 1
/* 9AEAA4 802403A4 0C04EBDC */  jal       func_8013AF70
/* 9AEAA8 802403A8 A7A20026 */   sh       $v0, 0x26($sp)
/* 9AEAAC 802403AC 3C05D838 */  lui       $a1, 0xd838
/* 9AEAB0 802403B0 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 9AEAB4 802403B4 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 9AEAB8 802403B8 8C620000 */  lw        $v0, ($v1)
/* 9AEABC 802403BC 34A50002 */  ori       $a1, $a1, 2
/* 9AEAC0 802403C0 0040202D */  daddu     $a0, $v0, $zero
/* 9AEAC4 802403C4 24420008 */  addiu     $v0, $v0, 8
/* 9AEAC8 802403C8 AC620000 */  sw        $v0, ($v1)
/* 9AEACC 802403CC 24020040 */  addiu     $v0, $zero, 0x40
/* 9AEAD0 802403D0 AC850000 */  sw        $a1, ($a0)
/* 9AEAD4 802403D4 AC820004 */  sw        $v0, 4($a0)
/* 9AEAD8 802403D8 8FBF00D8 */  lw        $ra, 0xd8($sp)
/* 9AEADC 802403DC 8FB500D4 */  lw        $s5, 0xd4($sp)
/* 9AEAE0 802403E0 8FB400D0 */  lw        $s4, 0xd0($sp)
/* 9AEAE4 802403E4 8FB300CC */  lw        $s3, 0xcc($sp)
/* 9AEAE8 802403E8 8FB200C8 */  lw        $s2, 0xc8($sp)
/* 9AEAEC 802403EC 8FB100C4 */  lw        $s1, 0xc4($sp)
/* 9AEAF0 802403F0 8FB000C0 */  lw        $s0, 0xc0($sp)
/* 9AEAF4 802403F4 D7B600E8 */  ldc1      $f22, 0xe8($sp)
/* 9AEAF8 802403F8 D7B400E0 */  ldc1      $f20, 0xe0($sp)
/* 9AEAFC 802403FC 03E00008 */  jr        $ra
/* 9AEB00 80240400 27BD00F0 */   addiu    $sp, $sp, 0xf0
