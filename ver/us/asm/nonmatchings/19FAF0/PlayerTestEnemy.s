.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlayerTestEnemy
/* 1A2FD0 802746F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A2FD4 802746F4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1A2FD8 802746F8 0080902D */  daddu     $s2, $a0, $zero
/* 1A2FDC 802746FC AFBF0020 */  sw        $ra, 0x20($sp)
/* 1A2FE0 80274700 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1A2FE4 80274704 AFB10014 */  sw        $s1, 0x14($sp)
/* 1A2FE8 80274708 AFB00010 */  sw        $s0, 0x10($sp)
/* 1A2FEC 8027470C 8E50000C */  lw        $s0, 0xc($s2)
/* 1A2FF0 80274710 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1A2FF4 80274714 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1A2FF8 80274718 8E130000 */  lw        $s3, ($s0)
/* 1A2FFC 8027471C 26100004 */  addiu     $s0, $s0, 4
/* 1A3000 80274720 8E020000 */  lw        $v0, ($s0)
/* 1A3004 80274724 26100004 */  addiu     $s0, $s0, 4
/* 1A3008 80274728 AE220188 */  sw        $v0, 0x188($s1)
/* 1A300C 8027472C 8E020000 */  lw        $v0, ($s0)
/* 1A3010 80274730 26100004 */  addiu     $s0, $s0, 4
/* 1A3014 80274734 AE22018C */  sw        $v0, 0x18c($s1)
/* 1A3018 80274738 8E020000 */  lw        $v0, ($s0)
/* 1A301C 8027473C 26100004 */  addiu     $s0, $s0, 4
/* 1A3020 80274740 AE220190 */  sw        $v0, 0x190($s1)
/* 1A3024 80274744 8E050000 */  lw        $a1, ($s0)
/* 1A3028 80274748 0C0B1EAF */  jal       evt_get_variable
/* 1A302C 8027474C 26100004 */   addiu    $s0, $s0, 4
/* 1A3030 80274750 A622017E */  sh        $v0, 0x17e($s1)
/* 1A3034 80274754 A2200198 */  sb        $zero, 0x198($s1)
/* 1A3038 80274758 8E100000 */  lw        $s0, ($s0)
/* 1A303C 8027475C 24020030 */  addiu     $v0, $zero, 0x30
/* 1A3040 80274760 32030030 */  andi      $v1, $s0, 0x30
/* 1A3044 80274764 54620004 */  bnel      $v1, $v0, .L80274778
/* 1A3048 80274768 32020010 */   andi     $v0, $s0, 0x10
/* 1A304C 8027476C 8E220000 */  lw        $v0, ($s1)
/* 1A3050 80274770 0809D1EE */  j         .L802747B8
/* 1A3054 80274774 34420030 */   ori      $v0, $v0, 0x30
.L80274778:
/* 1A3058 80274778 10400004 */  beqz      $v0, .L8027478C
/* 1A305C 8027477C 2403FFDF */   addiu    $v1, $zero, -0x21
/* 1A3060 80274780 8E220000 */  lw        $v0, ($s1)
/* 1A3064 80274784 0809D1ED */  j         .L802747B4
/* 1A3068 80274788 34420010 */   ori      $v0, $v0, 0x10
.L8027478C:
/* 1A306C 8027478C 32020020 */  andi      $v0, $s0, 0x20
/* 1A3070 80274790 10400005 */  beqz      $v0, .L802747A8
/* 1A3074 80274794 2403FFEF */   addiu    $v1, $zero, -0x11
/* 1A3078 80274798 8E220000 */  lw        $v0, ($s1)
/* 1A307C 8027479C 00431024 */  and       $v0, $v0, $v1
/* 1A3080 802747A0 0809D1EE */  j         .L802747B8
/* 1A3084 802747A4 34420020 */   ori      $v0, $v0, 0x20
.L802747A8:
/* 1A3088 802747A8 8E220000 */  lw        $v0, ($s1)
/* 1A308C 802747AC 00431024 */  and       $v0, $v0, $v1
/* 1A3090 802747B0 2403FFDF */  addiu     $v1, $zero, -0x21
.L802747B4:
/* 1A3094 802747B4 00431024 */  and       $v0, $v0, $v1
.L802747B8:
/* 1A3098 802747B8 AE220000 */  sw        $v0, ($s1)
/* 1A309C 802747BC 32020040 */  andi      $v0, $s0, 0x40
/* 1A30A0 802747C0 10400007 */  beqz      $v0, .L802747E0
/* 1A30A4 802747C4 2404FFBF */   addiu    $a0, $zero, -0x41
/* 1A30A8 802747C8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A30AC 802747CC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A30B0 802747D0 8C620000 */  lw        $v0, ($v1)
/* 1A30B4 802747D4 34420040 */  ori       $v0, $v0, 0x40
/* 1A30B8 802747D8 0809D1FD */  j         .L802747F4
/* 1A30BC 802747DC AC620000 */   sw       $v0, ($v1)
.L802747E0:
/* 1A30C0 802747E0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A30C4 802747E4 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A30C8 802747E8 8C430000 */  lw        $v1, ($v0)
/* 1A30CC 802747EC 00641824 */  and       $v1, $v1, $a0
/* 1A30D0 802747F0 AC430000 */  sw        $v1, ($v0)
.L802747F4:
/* 1A30D4 802747F4 32020200 */  andi      $v0, $s0, 0x200
/* 1A30D8 802747F8 10400007 */  beqz      $v0, .L80274818
/* 1A30DC 802747FC 2404FDFF */   addiu    $a0, $zero, -0x201
/* 1A30E0 80274800 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A30E4 80274804 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A30E8 80274808 8C620000 */  lw        $v0, ($v1)
/* 1A30EC 8027480C 34420200 */  ori       $v0, $v0, 0x200
/* 1A30F0 80274810 0809D20B */  j         .L8027482C
/* 1A30F4 80274814 AC620000 */   sw       $v0, ($v1)
.L80274818:
/* 1A30F8 80274818 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A30FC 8027481C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A3100 80274820 8C430000 */  lw        $v1, ($v0)
/* 1A3104 80274824 00641824 */  and       $v1, $v1, $a0
/* 1A3108 80274828 AC430000 */  sw        $v1, ($v0)
.L8027482C:
/* 1A310C 8027482C 32020080 */  andi      $v0, $s0, 0x80
/* 1A3110 80274830 10400007 */  beqz      $v0, .L80274850
/* 1A3114 80274834 2404FF7F */   addiu    $a0, $zero, -0x81
/* 1A3118 80274838 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A311C 8027483C 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A3120 80274840 8C620000 */  lw        $v0, ($v1)
/* 1A3124 80274844 34420080 */  ori       $v0, $v0, 0x80
/* 1A3128 80274848 0809D219 */  j         .L80274864
/* 1A312C 8027484C AC620000 */   sw       $v0, ($v1)
.L80274850:
/* 1A3130 80274850 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A3134 80274854 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A3138 80274858 8C430000 */  lw        $v1, ($v0)
/* 1A313C 8027485C 00641824 */  and       $v1, $v1, $a0
/* 1A3140 80274860 AC430000 */  sw        $v1, ($v0)
.L80274864:
/* 1A3144 80274864 32020800 */  andi      $v0, $s0, 0x800
/* 1A3148 80274868 10400007 */  beqz      $v0, .L80274888
/* 1A314C 8027486C 2404F7FF */   addiu    $a0, $zero, -0x801
/* 1A3150 80274870 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A3154 80274874 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A3158 80274878 8C620000 */  lw        $v0, ($v1)
/* 1A315C 8027487C 34420800 */  ori       $v0, $v0, 0x800
/* 1A3160 80274880 0809D227 */  j         .L8027489C
/* 1A3164 80274884 AC620000 */   sw       $v0, ($v1)
.L80274888:
/* 1A3168 80274888 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A316C 8027488C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A3170 80274890 8C430000 */  lw        $v1, ($v0)
/* 1A3174 80274894 00641824 */  and       $v1, $v1, $a0
/* 1A3178 80274898 AC430000 */  sw        $v1, ($v0)
.L8027489C:
/* 1A317C 8027489C 0C09A75B */  jal       get_actor
/* 1A3180 802748A0 8E440148 */   lw       $a0, 0x148($s2)
/* 1A3184 802748A4 94430428 */  lhu       $v1, 0x428($v0)
/* 1A3188 802748A8 A62301A0 */  sh        $v1, 0x1a0($s1)
/* 1A318C 802748AC 92230193 */  lbu       $v1, 0x193($s1)
/* 1A3190 802748B0 90420426 */  lbu       $v0, 0x426($v0)
/* 1A3194 802748B4 A2230194 */  sb        $v1, 0x194($s1)
/* 1A3198 802748B8 306300FF */  andi      $v1, $v1, 0xff
/* 1A319C 802748BC A22201A2 */  sb        $v0, 0x1a2($s1)
/* 1A31A0 802748C0 240200FF */  addiu     $v0, $zero, 0xff
/* 1A31A4 802748C4 50620001 */  beql      $v1, $v0, .L802748CC
/* 1A31A8 802748C8 A2200194 */   sb       $zero, 0x194($s1)
.L802748CC:
/* 1A31AC 802748CC 8E220190 */  lw        $v0, 0x190($s1)
/* 1A31B0 802748D0 30420F00 */  andi      $v0, $v0, 0xf00
/* 1A31B4 802748D4 00021203 */  sra       $v0, $v0, 8
/* 1A31B8 802748D8 0C09C5D5 */  jal       calc_player_test_enemy
/* 1A31BC 802748DC A2220195 */   sb       $v0, 0x195($s1)
/* 1A31C0 802748E0 04400006 */  bltz      $v0, .L802748FC
/* 1A31C4 802748E4 0240202D */   daddu    $a0, $s2, $zero
/* 1A31C8 802748E8 0260282D */  daddu     $a1, $s3, $zero
/* 1A31CC 802748EC 0C0B2026 */  jal       evt_set_variable
/* 1A31D0 802748F0 0040302D */   daddu    $a2, $v0, $zero
/* 1A31D4 802748F4 0809D240 */  j         .L80274900
/* 1A31D8 802748F8 24020002 */   addiu    $v0, $zero, 2
.L802748FC:
/* 1A31DC 802748FC 240200FF */  addiu     $v0, $zero, 0xff
.L80274900:
/* 1A31E0 80274900 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1A31E4 80274904 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1A31E8 80274908 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A31EC 8027490C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A31F0 80274910 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A31F4 80274914 03E00008 */  jr        $ra
/* 1A31F8 80274918 27BD0028 */   addiu    $sp, $sp, 0x28
