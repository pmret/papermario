.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel EnemyTestTarget
/* 1AB898 8027CFB8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1AB89C 8027CFBC AFB3001C */  sw        $s3, 0x1c($sp)
/* 1AB8A0 8027CFC0 0080982D */  daddu     $s3, $a0, $zero
/* 1AB8A4 8027CFC4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1AB8A8 8027CFC8 AFB40020 */  sw        $s4, 0x20($sp)
/* 1AB8AC 8027CFCC AFB20018 */  sw        $s2, 0x18($sp)
/* 1AB8B0 8027CFD0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AB8B4 8027CFD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AB8B8 8027CFD8 8E70000C */  lw        $s0, 0xc($s3)
/* 1AB8BC 8027CFDC 8E050000 */  lw        $a1, ($s0)
/* 1AB8C0 8027CFE0 0C0B1EAF */  jal       get_variable
/* 1AB8C4 8027CFE4 26100004 */   addiu    $s0, $s0, 4
/* 1AB8C8 8027CFE8 0040202D */  daddu     $a0, $v0, $zero
/* 1AB8CC 8027CFEC 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1AB8D0 8027CFF0 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1AB8D4 8027CFF4 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AB8D8 8027CFF8 14820002 */  bne       $a0, $v0, .L8027D004
/* 1AB8DC 8027CFFC 00000000 */   nop      
/* 1AB8E0 8027D000 8E640148 */  lw        $a0, 0x148($s3)
.L8027D004:
/* 1AB8E4 8027D004 0C09A75B */  jal       get_actor
/* 1AB8E8 8027D008 00000000 */   nop      
/* 1AB8EC 8027D00C 8E140000 */  lw        $s4, ($s0)
/* 1AB8F0 8027D010 26100004 */  addiu     $s0, $s0, 4
/* 1AB8F4 8027D014 8E030000 */  lw        $v1, ($s0)
/* 1AB8F8 8027D018 26100004 */  addiu     $s0, $s0, 4
/* 1AB8FC 8027D01C 0260202D */  daddu     $a0, $s3, $zero
/* 1AB900 8027D020 0040902D */  daddu     $s2, $v0, $zero
/* 1AB904 8027D024 AE20018C */  sw        $zero, 0x18c($s1)
/* 1AB908 8027D028 AE230188 */  sw        $v1, 0x188($s1)
/* 1AB90C 8027D02C 8E030000 */  lw        $v1, ($s0)
/* 1AB910 8027D030 26100004 */  addiu     $s0, $s0, 4
/* 1AB914 8027D034 AE230190 */  sw        $v1, 0x190($s1)
/* 1AB918 8027D038 8E050000 */  lw        $a1, ($s0)
/* 1AB91C 8027D03C 0C0B1EAF */  jal       get_variable
/* 1AB920 8027D040 26100004 */   addiu    $s0, $s0, 4
/* 1AB924 8027D044 A622017E */  sh        $v0, 0x17e($s1)
/* 1AB928 8027D048 8E050000 */  lw        $a1, ($s0)
/* 1AB92C 8027D04C 30A20010 */  andi      $v0, $a1, 0x10
/* 1AB930 8027D050 10400004 */  beqz      $v0, .L8027D064
/* 1AB934 8027D054 2403FFDF */   addiu    $v1, $zero, -0x21
/* 1AB938 8027D058 8E220000 */  lw        $v0, ($s1)
/* 1AB93C 8027D05C 0809F423 */  j         .L8027D08C
/* 1AB940 8027D060 34420010 */   ori      $v0, $v0, 0x10
.L8027D064:
/* 1AB944 8027D064 30A20020 */  andi      $v0, $a1, 0x20
/* 1AB948 8027D068 10400005 */  beqz      $v0, .L8027D080
/* 1AB94C 8027D06C 2403FFEF */   addiu    $v1, $zero, -0x11
/* 1AB950 8027D070 8E220000 */  lw        $v0, ($s1)
/* 1AB954 8027D074 00431024 */  and       $v0, $v0, $v1
/* 1AB958 8027D078 0809F424 */  j         .L8027D090
/* 1AB95C 8027D07C 34420020 */   ori      $v0, $v0, 0x20
.L8027D080:
/* 1AB960 8027D080 8E220000 */  lw        $v0, ($s1)
/* 1AB964 8027D084 00431024 */  and       $v0, $v0, $v1
/* 1AB968 8027D088 2403FFDF */  addiu     $v1, $zero, -0x21
.L8027D08C:
/* 1AB96C 8027D08C 00431024 */  and       $v0, $v0, $v1
.L8027D090:
/* 1AB970 8027D090 AE220000 */  sw        $v0, ($s1)
/* 1AB974 8027D094 30A20040 */  andi      $v0, $a1, 0x40
/* 1AB978 8027D098 10400007 */  beqz      $v0, .L8027D0B8
/* 1AB97C 8027D09C 2404FFBF */   addiu    $a0, $zero, -0x41
/* 1AB980 8027D0A0 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AB984 8027D0A4 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AB988 8027D0A8 8C620000 */  lw        $v0, ($v1)
/* 1AB98C 8027D0AC 34420040 */  ori       $v0, $v0, 0x40
/* 1AB990 8027D0B0 0809F433 */  j         .L8027D0CC
/* 1AB994 8027D0B4 AC620000 */   sw       $v0, ($v1)
.L8027D0B8:
/* 1AB998 8027D0B8 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AB99C 8027D0BC 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AB9A0 8027D0C0 8C430000 */  lw        $v1, ($v0)
/* 1AB9A4 8027D0C4 00641824 */  and       $v1, $v1, $a0
/* 1AB9A8 8027D0C8 AC430000 */  sw        $v1, ($v0)
.L8027D0CC:
/* 1AB9AC 8027D0CC 30A20200 */  andi      $v0, $a1, 0x200
/* 1AB9B0 8027D0D0 10400007 */  beqz      $v0, .L8027D0F0
/* 1AB9B4 8027D0D4 2404FDFF */   addiu    $a0, $zero, -0x201
/* 1AB9B8 8027D0D8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AB9BC 8027D0DC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AB9C0 8027D0E0 8C620000 */  lw        $v0, ($v1)
/* 1AB9C4 8027D0E4 34420200 */  ori       $v0, $v0, 0x200
/* 1AB9C8 8027D0E8 0809F441 */  j         .L8027D104
/* 1AB9CC 8027D0EC AC620000 */   sw       $v0, ($v1)
.L8027D0F0:
/* 1AB9D0 8027D0F0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AB9D4 8027D0F4 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AB9D8 8027D0F8 8C430000 */  lw        $v1, ($v0)
/* 1AB9DC 8027D0FC 00641824 */  and       $v1, $v1, $a0
/* 1AB9E0 8027D100 AC430000 */  sw        $v1, ($v0)
.L8027D104:
/* 1AB9E4 8027D104 30A20080 */  andi      $v0, $a1, 0x80
/* 1AB9E8 8027D108 10400007 */  beqz      $v0, .L8027D128
/* 1AB9EC 8027D10C 2404FF7F */   addiu    $a0, $zero, -0x81
/* 1AB9F0 8027D110 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AB9F4 8027D114 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AB9F8 8027D118 8C620000 */  lw        $v0, ($v1)
/* 1AB9FC 8027D11C 34420080 */  ori       $v0, $v0, 0x80
/* 1ABA00 8027D120 0809F44F */  j         .L8027D13C
/* 1ABA04 8027D124 AC620000 */   sw       $v0, ($v1)
.L8027D128:
/* 1ABA08 8027D128 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1ABA0C 8027D12C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1ABA10 8027D130 8C430000 */  lw        $v1, ($v0)
/* 1ABA14 8027D134 00641824 */  and       $v1, $v1, $a0
/* 1ABA18 8027D138 AC430000 */  sw        $v1, ($v0)
.L8027D13C:
/* 1ABA1C 8027D13C 96420428 */  lhu       $v0, 0x428($s2)
/* 1ABA20 8027D140 92230193 */  lbu       $v1, 0x193($s1)
/* 1ABA24 8027D144 A62201A0 */  sh        $v0, 0x1a0($s1)
/* 1ABA28 8027D148 92420426 */  lbu       $v0, 0x426($s2)
/* 1ABA2C 8027D14C A2230194 */  sb        $v1, 0x194($s1)
/* 1ABA30 8027D150 306300FF */  andi      $v1, $v1, 0xff
/* 1ABA34 8027D154 A22201A2 */  sb        $v0, 0x1a2($s1)
/* 1ABA38 8027D158 240200FF */  addiu     $v0, $zero, 0xff
/* 1ABA3C 8027D15C 50620001 */  beql      $v1, $v0, .L8027D164
/* 1ABA40 8027D160 A2200194 */   sb       $zero, 0x194($s1)
.L8027D164:
/* 1ABA44 8027D164 8E220190 */  lw        $v0, 0x190($s1)
/* 1ABA48 8027D168 0240202D */  daddu     $a0, $s2, $zero
/* 1ABA4C 8027D16C 30420F00 */  andi      $v0, $v0, 0xf00
/* 1ABA50 8027D170 00021203 */  sra       $v0, $v0, 8
/* 1ABA54 8027D174 0C09DC7E */  jal       calc_enemy_test_target
/* 1ABA58 8027D178 A2220195 */   sb       $v0, 0x195($s1)
/* 1ABA5C 8027D17C 04400006 */  bltz      $v0, .L8027D198
/* 1ABA60 8027D180 0260202D */   daddu    $a0, $s3, $zero
/* 1ABA64 8027D184 0280282D */  daddu     $a1, $s4, $zero
/* 1ABA68 8027D188 0C0B2026 */  jal       set_variable
/* 1ABA6C 8027D18C 0040302D */   daddu    $a2, $v0, $zero
/* 1ABA70 8027D190 0809F467 */  j         .L8027D19C
/* 1ABA74 8027D194 24020002 */   addiu    $v0, $zero, 2
.L8027D198:
/* 1ABA78 8027D198 240200FF */  addiu     $v0, $zero, 0xff
.L8027D19C:
/* 1ABA7C 8027D19C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1ABA80 8027D1A0 8FB40020 */  lw        $s4, 0x20($sp)
/* 1ABA84 8027D1A4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1ABA88 8027D1A8 8FB20018 */  lw        $s2, 0x18($sp)
/* 1ABA8C 8027D1AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 1ABA90 8027D1B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABA94 8027D1B4 03E00008 */  jr        $ra
/* 1ABA98 8027D1B8 27BD0028 */   addiu    $sp, $sp, 0x28
