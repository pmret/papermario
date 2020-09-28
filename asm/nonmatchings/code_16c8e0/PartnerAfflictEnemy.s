.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PartnerAfflictEnemy
/* 1AE8E4 80280004 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1AE8E8 80280008 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AE8EC 8028000C 0080902D */  daddu     $s2, $a0, $zero
/* 1AE8F0 80280010 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1AE8F4 80280014 AFB40020 */  sw        $s4, 0x20($sp)
/* 1AE8F8 80280018 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1AE8FC 8028001C AFB10014 */  sw        $s1, 0x14($sp)
/* 1AE900 80280020 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AE904 80280024 8E440148 */  lw        $a0, 0x148($s2)
/* 1AE908 80280028 0C09A75B */  jal       get_actor
/* 1AE90C 8028002C 8E50000C */   lw       $s0, 0xc($s2)
/* 1AE910 80280030 8E140000 */  lw        $s4, ($s0)
/* 1AE914 80280034 26100004 */  addiu     $s0, $s0, 4
/* 1AE918 80280038 8E030000 */  lw        $v1, ($s0)
/* 1AE91C 8028003C 26100004 */  addiu     $s0, $s0, 4
/* 1AE920 80280040 0240202D */  daddu     $a0, $s2, $zero
/* 1AE924 80280044 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1AE928 80280048 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1AE92C 8028004C 0040982D */  daddu     $s3, $v0, $zero
/* 1AE930 80280050 AE230188 */  sw        $v1, 0x188($s1)
/* 1AE934 80280054 8E030000 */  lw        $v1, ($s0)
/* 1AE938 80280058 26100004 */  addiu     $s0, $s0, 4
/* 1AE93C 8028005C AE23018C */  sw        $v1, 0x18c($s1)
/* 1AE940 80280060 8E030000 */  lw        $v1, ($s0)
/* 1AE944 80280064 26100004 */  addiu     $s0, $s0, 4
/* 1AE948 80280068 AE230190 */  sw        $v1, 0x190($s1)
/* 1AE94C 8028006C 8E050000 */  lw        $a1, ($s0)
/* 1AE950 80280070 0C0B1EAF */  jal       get_variable
/* 1AE954 80280074 26100004 */   addiu    $s0, $s0, 4
/* 1AE958 80280078 8E230190 */  lw        $v1, 0x190($s1)
/* 1AE95C 8028007C 0240202D */  daddu     $a0, $s2, $zero
/* 1AE960 80280080 00621825 */  or        $v1, $v1, $v0
/* 1AE964 80280084 AE230190 */  sw        $v1, 0x190($s1)
/* 1AE968 80280088 8E050000 */  lw        $a1, ($s0)
/* 1AE96C 8028008C 0C0B1EAF */  jal       get_variable
/* 1AE970 80280090 26100004 */   addiu    $s0, $s0, 4
/* 1AE974 80280094 A622017E */  sh        $v0, 0x17e($s1)
/* 1AE978 80280098 A2200198 */  sb        $zero, 0x198($s1)
/* 1AE97C 8028009C 8E100000 */  lw        $s0, ($s0)
/* 1AE980 802800A0 24020030 */  addiu     $v0, $zero, 0x30
/* 1AE984 802800A4 32030030 */  andi      $v1, $s0, 0x30
/* 1AE988 802800A8 54620004 */  bnel      $v1, $v0, .L802800BC
/* 1AE98C 802800AC 32020010 */   andi     $v0, $s0, 0x10
/* 1AE990 802800B0 8E220000 */  lw        $v0, ($s1)
/* 1AE994 802800B4 080A003F */  j         .L802800FC
/* 1AE998 802800B8 34420030 */   ori      $v0, $v0, 0x30
.L802800BC:
/* 1AE99C 802800BC 10400004 */  beqz      $v0, .L802800D0
/* 1AE9A0 802800C0 2403FFDF */   addiu    $v1, $zero, -0x21
/* 1AE9A4 802800C4 8E220000 */  lw        $v0, ($s1)
/* 1AE9A8 802800C8 080A003E */  j         .L802800F8
/* 1AE9AC 802800CC 34420010 */   ori      $v0, $v0, 0x10
.L802800D0:
/* 1AE9B0 802800D0 32020020 */  andi      $v0, $s0, 0x20
/* 1AE9B4 802800D4 10400005 */  beqz      $v0, .L802800EC
/* 1AE9B8 802800D8 2403FFEF */   addiu    $v1, $zero, -0x11
/* 1AE9BC 802800DC 8E220000 */  lw        $v0, ($s1)
/* 1AE9C0 802800E0 00431024 */  and       $v0, $v0, $v1
/* 1AE9C4 802800E4 080A003F */  j         .L802800FC
/* 1AE9C8 802800E8 34420020 */   ori      $v0, $v0, 0x20
.L802800EC:
/* 1AE9CC 802800EC 8E220000 */  lw        $v0, ($s1)
/* 1AE9D0 802800F0 00431024 */  and       $v0, $v0, $v1
/* 1AE9D4 802800F4 2403FFDF */  addiu     $v1, $zero, -0x21
.L802800F8:
/* 1AE9D8 802800F8 00431024 */  and       $v0, $v0, $v1
.L802800FC:
/* 1AE9DC 802800FC AE220000 */  sw        $v0, ($s1)
/* 1AE9E0 80280100 32020040 */  andi      $v0, $s0, 0x40
/* 1AE9E4 80280104 10400007 */  beqz      $v0, .L80280124
/* 1AE9E8 80280108 2404FFBF */   addiu    $a0, $zero, -0x41
/* 1AE9EC 8028010C 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AE9F0 80280110 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AE9F4 80280114 8C620000 */  lw        $v0, ($v1)
/* 1AE9F8 80280118 34420040 */  ori       $v0, $v0, 0x40
/* 1AE9FC 8028011C 080A004E */  j         .L80280138
/* 1AEA00 80280120 AC620000 */   sw       $v0, ($v1)
.L80280124:
/* 1AEA04 80280124 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AEA08 80280128 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AEA0C 8028012C 8C430000 */  lw        $v1, ($v0)
/* 1AEA10 80280130 00641824 */  and       $v1, $v1, $a0
/* 1AEA14 80280134 AC430000 */  sw        $v1, ($v0)
.L80280138:
/* 1AEA18 80280138 32020200 */  andi      $v0, $s0, 0x200
/* 1AEA1C 8028013C 10400007 */  beqz      $v0, .L8028015C
/* 1AEA20 80280140 2404FDFF */   addiu    $a0, $zero, -0x201
/* 1AEA24 80280144 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AEA28 80280148 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AEA2C 8028014C 8C620000 */  lw        $v0, ($v1)
/* 1AEA30 80280150 34420200 */  ori       $v0, $v0, 0x200
/* 1AEA34 80280154 080A005C */  j         .L80280170
/* 1AEA38 80280158 AC620000 */   sw       $v0, ($v1)
.L8028015C:
/* 1AEA3C 8028015C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AEA40 80280160 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AEA44 80280164 8C430000 */  lw        $v1, ($v0)
/* 1AEA48 80280168 00641824 */  and       $v1, $v1, $a0
/* 1AEA4C 8028016C AC430000 */  sw        $v1, ($v0)
.L80280170:
/* 1AEA50 80280170 32020080 */  andi      $v0, $s0, 0x80
/* 1AEA54 80280174 10400007 */  beqz      $v0, .L80280194
/* 1AEA58 80280178 2404FF7F */   addiu    $a0, $zero, -0x81
/* 1AEA5C 8028017C 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AEA60 80280180 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AEA64 80280184 8C620000 */  lw        $v0, ($v1)
/* 1AEA68 80280188 34420080 */  ori       $v0, $v0, 0x80
/* 1AEA6C 8028018C 080A006A */  j         .L802801A8
/* 1AEA70 80280190 AC620000 */   sw       $v0, ($v1)
.L80280194:
/* 1AEA74 80280194 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AEA78 80280198 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AEA7C 8028019C 8C430000 */  lw        $v1, ($v0)
/* 1AEA80 802801A0 00641824 */  and       $v1, $v1, $a0
/* 1AEA84 802801A4 AC430000 */  sw        $v1, ($v0)
.L802801A8:
/* 1AEA88 802801A8 32020800 */  andi      $v0, $s0, 0x800
/* 1AEA8C 802801AC 10400007 */  beqz      $v0, .L802801CC
/* 1AEA90 802801B0 2404F7FF */   addiu    $a0, $zero, -0x801
/* 1AEA94 802801B4 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AEA98 802801B8 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AEA9C 802801BC 8C620000 */  lw        $v0, ($v1)
/* 1AEAA0 802801C0 34420800 */  ori       $v0, $v0, 0x800
/* 1AEAA4 802801C4 080A0078 */  j         .L802801E0
/* 1AEAA8 802801C8 AC620000 */   sw       $v0, ($v1)
.L802801CC:
/* 1AEAAC 802801CC 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AEAB0 802801D0 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AEAB4 802801D4 8C430000 */  lw        $v1, ($v0)
/* 1AEAB8 802801D8 00641824 */  and       $v1, $v1, $a0
/* 1AEABC 802801DC AC430000 */  sw        $v1, ($v0)
.L802801E0:
/* 1AEAC0 802801E0 96620428 */  lhu       $v0, 0x428($s3)
/* 1AEAC4 802801E4 92230193 */  lbu       $v1, 0x193($s1)
/* 1AEAC8 802801E8 A62201A0 */  sh        $v0, 0x1a0($s1)
/* 1AEACC 802801EC 92620426 */  lbu       $v0, 0x426($s3)
/* 1AEAD0 802801F0 A2230194 */  sb        $v1, 0x194($s1)
/* 1AEAD4 802801F4 306300FF */  andi      $v1, $v1, 0xff
/* 1AEAD8 802801F8 A22201A2 */  sb        $v0, 0x1a2($s1)
/* 1AEADC 802801FC 240200FF */  addiu     $v0, $zero, 0xff
/* 1AEAE0 80280200 50620001 */  beql      $v1, $v0, .L80280208
/* 1AEAE4 80280204 A2200194 */   sb       $zero, 0x194($s1)
.L80280208:
/* 1AEAE8 80280208 8E220190 */  lw        $v0, 0x190($s1)
/* 1AEAEC 8028020C 30420F00 */  andi      $v0, $v0, 0xf00
/* 1AEAF0 80280210 00021203 */  sra       $v0, $v0, 8
/* 1AEAF4 80280214 0C09F8CA */  jal       calc_partner_damage_enemy
/* 1AEAF8 80280218 A2220195 */   sb       $v0, 0x195($s1)
/* 1AEAFC 8028021C 0440000B */  bltz      $v0, .L8028024C
/* 1AEB00 80280220 0240202D */   daddu    $a0, $s2, $zero
/* 1AEB04 80280224 0280282D */  daddu     $a1, $s4, $zero
/* 1AEB08 80280228 0C0B2026 */  jal       set_variable
/* 1AEB0C 8028022C 0040302D */   daddu    $a2, $v0, $zero
/* 1AEB10 80280230 0C0B1069 */  jal       does_script_exist_by_ref
/* 1AEB14 80280234 0240202D */   daddu    $a0, $s2, $zero
/* 1AEB18 80280238 0040182D */  daddu     $v1, $v0, $zero
/* 1AEB1C 8028023C 10600004 */  beqz      $v1, .L80280250
/* 1AEB20 80280240 240200FF */   addiu    $v0, $zero, 0xff
/* 1AEB24 80280244 080A0094 */  j         .L80280250
/* 1AEB28 80280248 24020002 */   addiu    $v0, $zero, 2
.L8028024C:
/* 1AEB2C 8028024C 240200FF */  addiu     $v0, $zero, 0xff
.L80280250:
/* 1AEB30 80280250 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1AEB34 80280254 8FB40020 */  lw        $s4, 0x20($sp)
/* 1AEB38 80280258 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1AEB3C 8028025C 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AEB40 80280260 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AEB44 80280264 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AEB48 80280268 03E00008 */  jr        $ra
/* 1AEB4C 8028026C 27BD0028 */   addiu    $sp, $sp, 0x28
