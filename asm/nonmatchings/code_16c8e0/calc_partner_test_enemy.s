.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel calc_partner_test_enemy
/* 1AC85C 8027DF7C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1AC860 8027DF80 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1AC864 8027DF84 3C11800E */  lui       $s1, 0x800e
/* 1AC868 8027DF88 2631C070 */  addiu     $s1, $s1, -0x3f90
/* 1AC86C 8027DF8C AFBF002C */  sw        $ra, 0x2c($sp)
/* 1AC870 8027DF90 AFB40028 */  sw        $s4, 0x28($sp)
/* 1AC874 8027DF94 AFB30024 */  sw        $s3, 0x24($sp)
/* 1AC878 8027DF98 AFB20020 */  sw        $s2, 0x20($sp)
/* 1AC87C 8027DF9C AFB00018 */  sw        $s0, 0x18($sp)
/* 1AC880 8027DFA0 962201A0 */  lhu       $v0, 0x1a0($s1)
/* 1AC884 8027DFA4 862401A0 */  lh        $a0, 0x1a0($s1)
/* 1AC888 8027DFA8 922301A2 */  lbu       $v1, 0x1a2($s1)
/* 1AC88C 8027DFAC 8E3400DC */  lw        $s4, 0xdc($s1)
/* 1AC890 8027DFB0 823201A2 */  lb        $s2, 0x1a2($s1)
/* 1AC894 8027DFB4 A62201A4 */  sh        $v0, 0x1a4($s1)
/* 1AC898 8027DFB8 0C09A75B */  jal       get_actor
/* 1AC89C 8027DFBC A22301A6 */   sb       $v1, 0x1a6($s1)
/* 1AC8A0 8027DFC0 0040982D */  daddu     $s3, $v0, $zero
/* 1AC8A4 8027DFC4 126000CF */  beqz      $s3, .L8027E304
/* 1AC8A8 8027DFC8 2690000C */   addiu    $s0, $s4, 0xc
/* 1AC8AC 8027DFCC 0260202D */  daddu     $a0, $s3, $zero
/* 1AC8B0 8027DFD0 0C099117 */  jal       get_actor_part
/* 1AC8B4 8027DFD4 0240282D */   daddu    $a1, $s2, $zero
/* 1AC8B8 8027DFD8 0040902D */  daddu     $s2, $v0, $zero
/* 1AC8BC 8027DFDC 16400003 */  bnez      $s2, .L8027DFEC
/* 1AC8C0 8027DFE0 2402000C */   addiu    $v0, $zero, 0xc
.L8027DFE4:
/* 1AC8C4 8027DFE4 0809F7F9 */  j         .L8027DFE4
/* 1AC8C8 8027DFE8 00000000 */   nop      
.L8027DFEC:
/* 1AC8CC 8027DFEC 82630214 */  lb        $v1, 0x214($s3)
/* 1AC8D0 8027DFF0 106200C5 */  beq       $v1, $v0, .L8027E308
/* 1AC8D4 8027DFF4 24020008 */   addiu    $v0, $zero, 8
/* 1AC8D8 8027DFF8 8E44007C */  lw        $a0, 0x7c($s2)
/* 1AC8DC 8027DFFC 30820020 */  andi      $v0, $a0, 0x20
/* 1AC8E0 8027E000 144000C1 */  bnez      $v0, .L8027E308
/* 1AC8E4 8027E004 24020006 */   addiu    $v0, $zero, 6
/* 1AC8E8 8027E008 82630218 */  lb        $v1, 0x218($s3)
/* 1AC8EC 8027E00C 2402000E */  addiu     $v0, $zero, 0xe
/* 1AC8F0 8027E010 106200BD */  beq       $v1, $v0, .L8027E308
/* 1AC8F4 8027E014 24020006 */   addiu    $v0, $zero, 6
/* 1AC8F8 8027E018 8E220188 */  lw        $v0, 0x188($s1)
/* 1AC8FC 8027E01C 30420080 */  andi      $v0, $v0, 0x80
/* 1AC900 8027E020 1040000F */  beqz      $v0, .L8027E060
/* 1AC904 8027E024 30820010 */   andi     $v0, $a0, 0x10
/* 1AC908 8027E028 1040000E */  beqz      $v0, .L8027E064
/* 1AC90C 8027E02C 3C031000 */   lui      $v1, 0x1000
/* 1AC910 8027E030 8E620004 */  lw        $v0, 4($s3)
/* 1AC914 8027E034 30420800 */  andi      $v0, $v0, 0x800
/* 1AC918 8027E038 1440000A */  bnez      $v0, .L8027E064
/* 1AC91C 8027E03C 24040108 */   addiu    $a0, $zero, 0x108
/* 1AC920 8027E040 C6000014 */  lwc1      $f0, 0x14($s0)
/* 1AC924 8027E044 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AC928 8027E048 8E06000C */  lw        $a2, 0xc($s0)
/* 1AC92C 8027E04C 8E070010 */  lw        $a3, 0x10($s0)
/* 1AC930 8027E050 0C052757 */  jal       play_sound_at_position
/* 1AC934 8027E054 0000282D */   daddu    $a1, $zero, $zero
/* 1AC938 8027E058 0809F8C2 */  j         .L8027E308
/* 1AC93C 8027E05C 24020004 */   addiu    $v0, $zero, 4
.L8027E060:
/* 1AC940 8027E060 3C031000 */  lui       $v1, 0x1000
.L8027E064:
/* 1AC944 8027E064 8E220188 */  lw        $v0, 0x188($s1)
/* 1AC948 8027E068 34630080 */  ori       $v1, $v1, 0x80
/* 1AC94C 8027E06C 00431024 */  and       $v0, $v0, $v1
/* 1AC950 8027E070 1440001B */  bnez      $v0, .L8027E0E0
/* 1AC954 8027E074 3C031000 */   lui      $v1, 0x1000
/* 1AC958 8027E078 8E42007C */  lw        $v0, 0x7c($s2)
/* 1AC95C 8027E07C 3C030001 */  lui       $v1, 1
/* 1AC960 8027E080 00431024 */  and       $v0, $v0, $v1
/* 1AC964 8027E084 10400016 */  beqz      $v0, .L8027E0E0
/* 1AC968 8027E088 3C031000 */   lui      $v1, 0x1000
/* 1AC96C 8027E08C 8E22018C */  lw        $v0, 0x18c($s1)
/* 1AC970 8027E090 30420004 */  andi      $v0, $v0, 4
/* 1AC974 8027E094 14400012 */  bnez      $v0, .L8027E0E0
/* 1AC978 8027E098 0280202D */   daddu    $a0, $s4, $zero
/* 1AC97C 8027E09C 0C099CAB */  jal       heroes_is_ability_active
/* 1AC980 8027E0A0 24050002 */   addiu    $a1, $zero, 2
/* 1AC984 8027E0A4 1440000E */  bnez      $v0, .L8027E0E0
/* 1AC988 8027E0A8 3C031000 */   lui      $v1, 0x1000
/* 1AC98C 8027E0AC C6000014 */  lwc1      $f0, 0x14($s0)
/* 1AC990 8027E0B0 24040108 */  addiu     $a0, $zero, 0x108
/* 1AC994 8027E0B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AC998 8027E0B8 8E06000C */  lw        $a2, 0xc($s0)
/* 1AC99C 8027E0BC 8E070010 */  lw        $a3, 0x10($s0)
/* 1AC9A0 8027E0C0 0C052757 */  jal       play_sound_at_position
/* 1AC9A4 8027E0C4 0000282D */   daddu    $a1, $zero, $zero
/* 1AC9A8 8027E0C8 24040001 */  addiu     $a0, $zero, 1
/* 1AC9AC 8027E0CC 0C09FEE7 */  jal       dispatch_damage_event_partner_1
/* 1AC9B0 8027E0D0 2405002A */   addiu    $a1, $zero, 0x2a
/* 1AC9B4 8027E0D4 0260202D */  daddu     $a0, $s3, $zero
/* 1AC9B8 8027E0D8 0809F8BB */  j         .L8027E2EC
/* 1AC9BC 8027E0DC 2405001B */   addiu    $a1, $zero, 0x1b
.L8027E0E0:
/* 1AC9C0 8027E0E0 8E220188 */  lw        $v0, 0x188($s1)
/* 1AC9C4 8027E0E4 34630040 */  ori       $v1, $v1, 0x40
/* 1AC9C8 8027E0E8 00431024 */  and       $v0, $v0, $v1
/* 1AC9CC 8027E0EC 14400009 */  bnez      $v0, .L8027E114
/* 1AC9D0 8027E0F0 00000000 */   nop      
/* 1AC9D4 8027E0F4 8E42007C */  lw        $v0, 0x7c($s2)
/* 1AC9D8 8027E0F8 30420002 */  andi      $v0, $v0, 2
/* 1AC9DC 8027E0FC 10400005 */  beqz      $v0, .L8027E114
/* 1AC9E0 8027E100 00000000 */   nop      
/* 1AC9E4 8027E104 8E22018C */  lw        $v0, 0x18c($s1)
/* 1AC9E8 8027E108 30420010 */  andi      $v0, $v0, 0x10
/* 1AC9EC 8027E10C 1040006B */  beqz      $v0, .L8027E2BC
/* 1AC9F0 8027E110 00000000 */   nop      
.L8027E114:
/* 1AC9F4 8027E114 8E230188 */  lw        $v1, 0x188($s1)
/* 1AC9F8 8027E118 30628000 */  andi      $v0, $v1, 0x8000
/* 1AC9FC 8027E11C 10400079 */  beqz      $v0, .L8027E304
/* 1ACA00 8027E120 3C021000 */   lui      $v0, 0x1000
/* 1ACA04 8027E124 00621024 */  and       $v0, $v1, $v0
/* 1ACA08 8027E128 14400036 */  bnez      $v0, .L8027E204
/* 1ACA0C 8027E12C 00000000 */   nop      
/* 1ACA10 8027E130 8E42007C */  lw        $v0, 0x7c($s2)
/* 1ACA14 8027E134 30420010 */  andi      $v0, $v0, 0x10
/* 1ACA18 8027E138 10400015 */  beqz      $v0, .L8027E190
/* 1ACA1C 8027E13C 00000000 */   nop      
/* 1ACA20 8027E140 8E620000 */  lw        $v0, ($s3)
/* 1ACA24 8027E144 30420800 */  andi      $v0, $v0, 0x800
/* 1ACA28 8027E148 14400011 */  bnez      $v0, .L8027E190
/* 1ACA2C 8027E14C 00000000 */   nop      
/* 1ACA30 8027E150 8E22018C */  lw        $v0, 0x18c($s1)
/* 1ACA34 8027E154 30420001 */  andi      $v0, $v0, 1
/* 1ACA38 8027E158 1440000D */  bnez      $v0, .L8027E190
/* 1ACA3C 8027E15C 24040108 */   addiu    $a0, $zero, 0x108
/* 1ACA40 8027E160 C6000014 */  lwc1      $f0, 0x14($s0)
/* 1ACA44 8027E164 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACA48 8027E168 8E06000C */  lw        $a2, 0xc($s0)
/* 1ACA4C 8027E16C 8E070010 */  lw        $a3, 0x10($s0)
/* 1ACA50 8027E170 0C052757 */  jal       play_sound_at_position
/* 1ACA54 8027E174 0000282D */   daddu    $a1, $zero, $zero
/* 1ACA58 8027E178 24040001 */  addiu     $a0, $zero, 1
/* 1ACA5C 8027E17C 0C09FEE7 */  jal       dispatch_damage_event_partner_1
/* 1ACA60 8027E180 2405002A */   addiu    $a1, $zero, 0x2a
/* 1ACA64 8027E184 0260202D */  daddu     $a0, $s3, $zero
/* 1ACA68 8027E188 0809F8BB */  j         .L8027E2EC
/* 1ACA6C 8027E18C 2405001B */   addiu    $a1, $zero, 0x1b
.L8027E190:
/* 1ACA70 8027E190 8E220188 */  lw        $v0, 0x188($s1)
/* 1ACA74 8027E194 3C031000 */  lui       $v1, 0x1000
/* 1ACA78 8027E198 00431024 */  and       $v0, $v0, $v1
/* 1ACA7C 8027E19C 14400019 */  bnez      $v0, .L8027E204
/* 1ACA80 8027E1A0 3C030020 */   lui      $v1, 0x20
/* 1ACA84 8027E1A4 8E42007C */  lw        $v0, 0x7c($s2)
/* 1ACA88 8027E1A8 00431024 */  and       $v0, $v0, $v1
/* 1ACA8C 8027E1AC 10400015 */  beqz      $v0, .L8027E204
/* 1ACA90 8027E1B0 00000000 */   nop      
/* 1ACA94 8027E1B4 8E620000 */  lw        $v0, ($s3)
/* 1ACA98 8027E1B8 30420800 */  andi      $v0, $v0, 0x800
/* 1ACA9C 8027E1BC 14400011 */  bnez      $v0, .L8027E204
/* 1ACAA0 8027E1C0 00000000 */   nop      
/* 1ACAA4 8027E1C4 8E22018C */  lw        $v0, 0x18c($s1)
/* 1ACAA8 8027E1C8 30420080 */  andi      $v0, $v0, 0x80
/* 1ACAAC 8027E1CC 1440000D */  bnez      $v0, .L8027E204
/* 1ACAB0 8027E1D0 24040108 */   addiu    $a0, $zero, 0x108
/* 1ACAB4 8027E1D4 C6000014 */  lwc1      $f0, 0x14($s0)
/* 1ACAB8 8027E1D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACABC 8027E1DC 8E06000C */  lw        $a2, 0xc($s0)
/* 1ACAC0 8027E1E0 8E070010 */  lw        $a3, 0x10($s0)
/* 1ACAC4 8027E1E4 0C052757 */  jal       play_sound_at_position
/* 1ACAC8 8027E1E8 0000282D */   daddu    $a1, $zero, $zero
/* 1ACACC 8027E1EC 24040001 */  addiu     $a0, $zero, 1
/* 1ACAD0 8027E1F0 0C09FEE7 */  jal       dispatch_damage_event_partner_1
/* 1ACAD4 8027E1F4 2405002A */   addiu    $a1, $zero, 0x2a
/* 1ACAD8 8027E1F8 0260202D */  daddu     $a0, $s3, $zero
/* 1ACADC 8027E1FC 0809F8BB */  j         .L8027E2EC
/* 1ACAE0 8027E200 2405001B */   addiu    $a1, $zero, 0x1b
.L8027E204:
/* 1ACAE4 8027E204 82820212 */  lb        $v0, 0x212($s4)
/* 1ACAE8 8027E208 2403000B */  addiu     $v1, $zero, 0xb
/* 1ACAEC 8027E20C 5043001E */  beql      $v0, $v1, .L8027E288
/* 1ACAF0 8027E210 3C031000 */   lui      $v1, 0x1000
/* 1ACAF4 8027E214 82620212 */  lb        $v0, 0x212($s3)
/* 1ACAF8 8027E218 10430005 */  beq       $v0, $v1, .L8027E230
/* 1ACAFC 8027E21C 00000000 */   nop      
/* 1ACB00 8027E220 8E42007C */  lw        $v0, 0x7c($s2)
/* 1ACB04 8027E224 30420080 */  andi      $v0, $v0, 0x80
/* 1ACB08 8027E228 10400017 */  beqz      $v0, .L8027E288
/* 1ACB0C 8027E22C 3C031000 */   lui      $v1, 0x1000
.L8027E230:
/* 1ACB10 8027E230 8E220188 */  lw        $v0, 0x188($s1)
/* 1ACB14 8027E234 3C031000 */  lui       $v1, 0x1000
/* 1ACB18 8027E238 00431024 */  and       $v0, $v0, $v1
/* 1ACB1C 8027E23C 14400012 */  bnez      $v0, .L8027E288
/* 1ACB20 8027E240 00000000 */   nop      
/* 1ACB24 8027E244 8E22018C */  lw        $v0, 0x18c($s1)
/* 1ACB28 8027E248 30420008 */  andi      $v0, $v0, 8
/* 1ACB2C 8027E24C 1440000E */  bnez      $v0, .L8027E288
/* 1ACB30 8027E250 2404037B */   addiu    $a0, $zero, 0x37b
/* 1ACB34 8027E254 C6000014 */  lwc1      $f0, 0x14($s0)
/* 1ACB38 8027E258 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACB3C 8027E25C 8E06000C */  lw        $a2, 0xc($s0)
/* 1ACB40 8027E260 8E070010 */  lw        $a3, 0x10($s0)
/* 1ACB44 8027E264 0C052757 */  jal       play_sound_at_position
/* 1ACB48 8027E268 0000282D */   daddu    $a1, $zero, $zero
/* 1ACB4C 8027E26C 0C09451D */  jal       func_80251474
/* 1ACB50 8027E270 0280202D */   daddu    $a0, $s4, $zero
/* 1ACB54 8027E274 24040001 */  addiu     $a0, $zero, 1
/* 1ACB58 8027E278 0C09FEE7 */  jal       dispatch_damage_event_partner_1
/* 1ACB5C 8027E27C 2405002F */   addiu    $a1, $zero, 0x2f
/* 1ACB60 8027E280 0809F8C2 */  j         .L8027E308
/* 1ACB64 8027E284 2402FFFF */   addiu    $v0, $zero, -1
.L8027E288:
/* 1ACB68 8027E288 8E220188 */  lw        $v0, 0x188($s1)
/* 1ACB6C 8027E28C 34630040 */  ori       $v1, $v1, 0x40
/* 1ACB70 8027E290 00431024 */  and       $v0, $v0, $v1
/* 1ACB74 8027E294 14400019 */  bnez      $v0, .L8027E2FC
/* 1ACB78 8027E298 0260202D */   daddu    $a0, $s3, $zero
/* 1ACB7C 8027E29C 8E42007C */  lw        $v0, 0x7c($s2)
/* 1ACB80 8027E2A0 30420002 */  andi      $v0, $v0, 2
/* 1ACB84 8027E2A4 10400015 */  beqz      $v0, .L8027E2FC
/* 1ACB88 8027E2A8 00000000 */   nop      
/* 1ACB8C 8027E2AC 8E22018C */  lw        $v0, 0x18c($s1)
/* 1ACB90 8027E2B0 30420010 */  andi      $v0, $v0, 0x10
/* 1ACB94 8027E2B4 14400011 */  bnez      $v0, .L8027E2FC
/* 1ACB98 8027E2B8 00000000 */   nop      
.L8027E2BC:
/* 1ACB9C 8027E2BC C6000014 */  lwc1      $f0, 0x14($s0)
/* 1ACBA0 8027E2C0 240400EA */  addiu     $a0, $zero, 0xea
/* 1ACBA4 8027E2C4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACBA8 8027E2C8 8E06000C */  lw        $a2, 0xc($s0)
/* 1ACBAC 8027E2CC 8E070010 */  lw        $a3, 0x10($s0)
/* 1ACBB0 8027E2D0 0C052757 */  jal       play_sound_at_position
/* 1ACBB4 8027E2D4 0000282D */   daddu    $a1, $zero, $zero
/* 1ACBB8 8027E2D8 24040001 */  addiu     $a0, $zero, 1
/* 1ACBBC 8027E2DC 0C09FEE7 */  jal       dispatch_damage_event_partner_1
/* 1ACBC0 8027E2E0 2405002C */   addiu    $a1, $zero, 0x2c
/* 1ACBC4 8027E2E4 0260202D */  daddu     $a0, $s3, $zero
/* 1ACBC8 8027E2E8 2405001C */  addiu     $a1, $zero, 0x1c
.L8027E2EC:
/* 1ACBCC 8027E2EC 0C09DC58 */  jal       dispatch_event_actor
/* 1ACBD0 8027E2F0 00000000 */   nop      
/* 1ACBD4 8027E2F4 0809F8C2 */  j         .L8027E308
/* 1ACBD8 8027E2F8 2402FFFF */   addiu    $v0, $zero, -1
.L8027E2FC:
/* 1ACBDC 8027E2FC 0C09DC58 */  jal       dispatch_event_actor
/* 1ACBE0 8027E300 2405003A */   addiu    $a1, $zero, 0x3a
.L8027E304:
/* 1ACBE4 8027E304 0000102D */  daddu     $v0, $zero, $zero
.L8027E308:
/* 1ACBE8 8027E308 8FBF002C */  lw        $ra, 0x2c($sp)
/* 1ACBEC 8027E30C 8FB40028 */  lw        $s4, 0x28($sp)
/* 1ACBF0 8027E310 8FB30024 */  lw        $s3, 0x24($sp)
/* 1ACBF4 8027E314 8FB20020 */  lw        $s2, 0x20($sp)
/* 1ACBF8 8027E318 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1ACBFC 8027E31C 8FB00018 */  lw        $s0, 0x18($sp)
/* 1ACC00 8027E320 03E00008 */  jr        $ra
/* 1ACC04 8027E324 27BD0030 */   addiu    $sp, $sp, 0x30
