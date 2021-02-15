.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ResetActorSounds
/* 19E118 8026F838 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19E11C 8026F83C AFB20018 */  sw        $s2, 0x18($sp)
/* 19E120 8026F840 0080902D */  daddu     $s2, $a0, $zero
/* 19E124 8026F844 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19E128 8026F848 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19E12C 8026F84C AFB10014 */  sw        $s1, 0x14($sp)
/* 19E130 8026F850 AFB00010 */  sw        $s0, 0x10($sp)
/* 19E134 8026F854 8E50000C */  lw        $s0, 0xc($s2)
/* 19E138 8026F858 8E050000 */  lw        $a1, ($s0)
/* 19E13C 8026F85C 0C0B1EAF */  jal       get_variable
/* 19E140 8026F860 26100004 */   addiu    $s0, $s0, 4
/* 19E144 8026F864 0040882D */  daddu     $s1, $v0, $zero
/* 19E148 8026F868 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19E14C 8026F86C 16220002 */  bne       $s1, $v0, .L8026F878
/* 19E150 8026F870 00000000 */   nop
/* 19E154 8026F874 8E510148 */  lw        $s1, 0x148($s2)
.L8026F878:
/* 19E158 8026F878 8E050000 */  lw        $a1, ($s0)
/* 19E15C 8026F87C 26100004 */  addiu     $s0, $s0, 4
/* 19E160 8026F880 0C0B1EAF */  jal       get_variable
/* 19E164 8026F884 0240202D */   daddu    $a0, $s2, $zero
/* 19E168 8026F888 8E050000 */  lw        $a1, ($s0)
/* 19E16C 8026F88C 26100004 */  addiu     $s0, $s0, 4
/* 19E170 8026F890 0240202D */  daddu     $a0, $s2, $zero
/* 19E174 8026F894 0C0B1EAF */  jal       get_variable
/* 19E178 8026F898 0040982D */   daddu    $s3, $v0, $zero
/* 19E17C 8026F89C 8E050000 */  lw        $a1, ($s0)
/* 19E180 8026F8A0 0C0B1EAF */  jal       get_variable
/* 19E184 8026F8A4 0240202D */   daddu    $a0, $s2, $zero
/* 19E188 8026F8A8 0C09A75B */  jal       get_actor
/* 19E18C 8026F8AC 0220202D */   daddu    $a0, $s1, $zero
/* 19E190 8026F8B0 0040202D */  daddu     $a0, $v0, $zero
/* 19E194 8026F8B4 2E620006 */  sltiu     $v0, $s3, 6
/* 19E198 8026F8B8 10400049 */  beqz      $v0, .L8026F9E0
/* 19E19C 8026F8BC 00131080 */   sll      $v0, $s3, 2
/* 19E1A0 8026F8C0 3C01802A */  lui       $at, %hi(jtbl_8029D7D8)
/* 19E1A4 8026F8C4 00220821 */  addu      $at, $at, $v0
/* 19E1A8 8026F8C8 8C22D7D8 */  lw        $v0, %lo(jtbl_8029D7D8)($at)
/* 19E1AC 8026F8CC 00400008 */  jr        $v0
/* 19E1B0 8026F8D0 00000000 */   nop
glabel L8026F8D4_19E1B4
/* 19E1B4 8026F8D4 90830136 */  lbu       $v1, 0x136($a0)
/* 19E1B8 8026F8D8 000310C0 */  sll       $v0, $v1, 3
/* 19E1BC 8026F8DC 00431023 */  subu      $v0, $v0, $v1
/* 19E1C0 8026F8E0 00021080 */  sll       $v0, $v0, 2
/* 19E1C4 8026F8E4 3C018028 */  lui       $at, %hi(bActorSoundTable)
/* 19E1C8 8026F8E8 00220821 */  addu      $at, $at, $v0
/* 19E1CC 8026F8EC 8C221468 */  lw        $v0, %lo(bActorSoundTable)($at)
/* 19E1D0 8026F8F0 AC82019C */  sw        $v0, 0x19c($a0)
/* 19E1D4 8026F8F4 000310C0 */  sll       $v0, $v1, 3
/* 19E1D8 8026F8F8 00431023 */  subu      $v0, $v0, $v1
/* 19E1DC 8026F8FC 00021080 */  sll       $v0, $v0, 2
/* 19E1E0 8026F900 3C018028 */  lui       $at, %hi(bActorSoundTable+4)
/* 19E1E4 8026F904 00220821 */  addu      $at, $at, $v0
/* 19E1E8 8026F908 8C22146C */  lw        $v0, %lo(bActorSoundTable+4)($at)
/* 19E1EC 8026F90C 0809BE78 */  j         .L8026F9E0
/* 19E1F0 8026F910 AC8201A0 */   sw       $v0, 0x1a0($a0)
glabel L8026F914_19E1F4
/* 19E1F4 8026F914 90830136 */  lbu       $v1, 0x136($a0)
/* 19E1F8 8026F918 000310C0 */  sll       $v0, $v1, 3
/* 19E1FC 8026F91C 00431023 */  subu      $v0, $v0, $v1
/* 19E200 8026F920 00021080 */  sll       $v0, $v0, 2
/* 19E204 8026F924 3C018028 */  lui       $at, %hi(bActorSoundTable+8)
/* 19E208 8026F928 00220821 */  addu      $at, $at, $v0
/* 19E20C 8026F92C 8C221470 */  lw        $v0, %lo(bActorSoundTable+8)($at)
/* 19E210 8026F930 AC8201A4 */  sw        $v0, 0x1a4($a0)
/* 19E214 8026F934 000310C0 */  sll       $v0, $v1, 3
/* 19E218 8026F938 00431023 */  subu      $v0, $v0, $v1
/* 19E21C 8026F93C 00021080 */  sll       $v0, $v0, 2
/* 19E220 8026F940 3C018028 */  lui       $at, %hi(bActorSoundTable+12)
/* 19E224 8026F944 00220821 */  addu      $at, $at, $v0
/* 19E228 8026F948 8C221474 */  lw        $v0, %lo(bActorSoundTable+12)($at)
/* 19E22C 8026F94C 0809BE78 */  j         .L8026F9E0
/* 19E230 8026F950 AC8201A8 */   sw       $v0, 0x1a8($a0)
glabel L8026F954_19E234
/* 19E234 8026F954 90820136 */  lbu       $v0, 0x136($a0)
/* 19E238 8026F958 000218C0 */  sll       $v1, $v0, 3
/* 19E23C 8026F95C 00621823 */  subu      $v1, $v1, $v0
/* 19E240 8026F960 00031880 */  sll       $v1, $v1, 2
/* 19E244 8026F964 3C028028 */  lui       $v0, %hi(bActorSoundTable+16)
/* 19E248 8026F968 00431021 */  addu      $v0, $v0, $v1
/* 19E24C 8026F96C 8C421478 */  lw        $v0, %lo(bActorSoundTable+16)($v0)
/* 19E250 8026F970 0809BE78 */  j         .L8026F9E0
/* 19E254 8026F974 AC8201AC */   sw       $v0, 0x1ac($a0)
glabel L8026F978_19E258
/* 19E258 8026F978 90820136 */  lbu       $v0, 0x136($a0)
/* 19E25C 8026F97C 000218C0 */  sll       $v1, $v0, 3
/* 19E260 8026F980 00621823 */  subu      $v1, $v1, $v0
/* 19E264 8026F984 00031880 */  sll       $v1, $v1, 2
/* 19E268 8026F988 3C028028 */  lui       $v0, %hi(bActorSoundTable+20)
/* 19E26C 8026F98C 00431021 */  addu      $v0, $v0, $v1
/* 19E270 8026F990 8C42147C */  lw        $v0, %lo(bActorSoundTable+20)($v0)
/* 19E274 8026F994 0809BE78 */  j         .L8026F9E0
/* 19E278 8026F998 AC8201B0 */   sw       $v0, 0x1b0($a0)
glabel L8026F99C_19E27C
/* 19E27C 8026F99C 90820136 */  lbu       $v0, 0x136($a0)
/* 19E280 8026F9A0 000218C0 */  sll       $v1, $v0, 3
/* 19E284 8026F9A4 00621823 */  subu      $v1, $v1, $v0
/* 19E288 8026F9A8 00031880 */  sll       $v1, $v1, 2
/* 19E28C 8026F9AC 3C028028 */  lui       $v0, %hi(bActorSoundTable+24)
/* 19E290 8026F9B0 00431021 */  addu      $v0, $v0, $v1
/* 19E294 8026F9B4 94421480 */  lhu       $v0, %lo(bActorSoundTable+24)($v0)
/* 19E298 8026F9B8 0809BE78 */  j         .L8026F9E0
/* 19E29C 8026F9BC A48201B4 */   sh       $v0, 0x1b4($a0)
glabel L8026F9C0_19E2A0
/* 19E2A0 8026F9C0 90820136 */  lbu       $v0, 0x136($a0)
/* 19E2A4 8026F9C4 000218C0 */  sll       $v1, $v0, 3
/* 19E2A8 8026F9C8 00621823 */  subu      $v1, $v1, $v0
/* 19E2AC 8026F9CC 00031880 */  sll       $v1, $v1, 2
/* 19E2B0 8026F9D0 3C028028 */  lui       $v0, %hi(bActorSoundTable+0x1A)
/* 19E2B4 8026F9D4 00431021 */  addu      $v0, $v0, $v1
/* 19E2B8 8026F9D8 94421482 */  lhu       $v0, %lo(bActorSoundTable+0x1A)($v0)
/* 19E2BC 8026F9DC A48201B6 */  sh        $v0, 0x1b6($a0)
.L8026F9E0:
/* 19E2C0 8026F9E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19E2C4 8026F9E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19E2C8 8026F9E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 19E2CC 8026F9EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 19E2D0 8026F9F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 19E2D4 8026F9F4 24020002 */  addiu     $v0, $zero, 2
/* 19E2D8 8026F9F8 03E00008 */  jr        $ra
/* 19E2DC 8026F9FC 27BD0028 */   addiu    $sp, $sp, 0x28
