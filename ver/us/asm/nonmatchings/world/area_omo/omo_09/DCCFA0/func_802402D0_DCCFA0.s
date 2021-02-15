.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402D0_DCCFA0
/* DCCFA0 802402D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DCCFA4 802402D4 AFB20028 */  sw        $s2, 0x28($sp)
/* DCCFA8 802402D8 0080902D */  daddu     $s2, $a0, $zero
/* DCCFAC 802402DC AFBF002C */  sw        $ra, 0x2c($sp)
/* DCCFB0 802402E0 AFB10024 */  sw        $s1, 0x24($sp)
/* DCCFB4 802402E4 AFB00020 */  sw        $s0, 0x20($sp)
/* DCCFB8 802402E8 8E50000C */  lw        $s0, 0xc($s2)
/* DCCFBC 802402EC 8E050000 */  lw        $a1, ($s0)
/* DCCFC0 802402F0 0C0B1EAF */  jal       get_variable
/* DCCFC4 802402F4 26100004 */   addiu    $s0, $s0, 4
/* DCCFC8 802402F8 8E050000 */  lw        $a1, ($s0)
/* DCCFCC 802402FC 26100004 */  addiu     $s0, $s0, 4
/* DCCFD0 80240300 0240202D */  daddu     $a0, $s2, $zero
/* DCCFD4 80240304 0C0B1EAF */  jal       get_variable
/* DCCFD8 80240308 0040882D */   daddu    $s1, $v0, $zero
/* DCCFDC 8024030C 0240202D */  daddu     $a0, $s2, $zero
/* DCCFE0 80240310 8E050000 */  lw        $a1, ($s0)
/* DCCFE4 80240314 0C0B1EAF */  jal       get_variable
/* DCCFE8 80240318 0040802D */   daddu    $s0, $v0, $zero
/* DCCFEC 8024031C 0040282D */  daddu     $a1, $v0, $zero
/* DCCFF0 80240320 2402FFFF */  addiu     $v0, $zero, -1
/* DCCFF4 80240324 1222001A */  beq       $s1, $v0, .L80240390
/* DCCFF8 80240328 3C04B60B */   lui      $a0, 0xb60b
/* DCCFFC 8024032C 348460B7 */  ori       $a0, $a0, 0x60b7
/* DCD000 80240330 02240018 */  mult      $s1, $a0
/* DCD004 80240334 001117C3 */  sra       $v0, $s1, 0x1f
/* DCD008 80240338 00005810 */  mfhi      $t3
/* DCD00C 8024033C 01711821 */  addu      $v1, $t3, $s1
/* DCD010 80240340 00031A03 */  sra       $v1, $v1, 8
/* DCD014 80240344 00621823 */  subu      $v1, $v1, $v0
/* DCD018 80240348 00031040 */  sll       $v0, $v1, 1
/* DCD01C 8024034C 00431021 */  addu      $v0, $v0, $v1
/* DCD020 80240350 00021900 */  sll       $v1, $v0, 4
/* DCD024 80240354 00621823 */  subu      $v1, $v1, $v0
/* DCD028 80240358 000318C0 */  sll       $v1, $v1, 3
/* DCD02C 8024035C 02231823 */  subu      $v1, $s1, $v1
/* DCD030 80240360 00640018 */  mult      $v1, $a0
/* DCD034 80240364 00005810 */  mfhi      $t3
/* DCD038 80240368 01631021 */  addu      $v0, $t3, $v1
/* DCD03C 8024036C 00021143 */  sra       $v0, $v0, 5
/* DCD040 80240370 00031FC3 */  sra       $v1, $v1, 0x1f
/* DCD044 80240374 00431023 */  subu      $v0, $v0, $v1
/* DCD048 80240378 00021080 */  sll       $v0, $v0, 2
/* DCD04C 8024037C 3C018024 */  lui       $at, %hi(D_802451AC_DD1E7C)
/* DCD050 80240380 00220821 */  addu      $at, $at, $v0
/* DCD054 80240384 8C2251AC */  lw        $v0, %lo(D_802451AC_DD1E7C)($at)
/* DCD058 80240388 080900E5 */  j         .L80240394
/* DCD05C 8024038C AFA20010 */   sw       $v0, 0x10($sp)
.L80240390:
/* DCD060 80240390 AFA00010 */  sw        $zero, 0x10($sp)
.L80240394:
/* DCD064 80240394 2402FFFF */  addiu     $v0, $zero, -1
/* DCD068 80240398 1202001B */  beq       $s0, $v0, .L80240408
/* DCD06C 8024039C 3C04B60B */   lui      $a0, 0xb60b
/* DCD070 802403A0 348460B7 */  ori       $a0, $a0, 0x60b7
/* DCD074 802403A4 02040018 */  mult      $s0, $a0
/* DCD078 802403A8 001017C3 */  sra       $v0, $s0, 0x1f
/* DCD07C 802403AC 00005810 */  mfhi      $t3
/* DCD080 802403B0 01701821 */  addu      $v1, $t3, $s0
/* DCD084 802403B4 00031A03 */  sra       $v1, $v1, 8
/* DCD088 802403B8 00621823 */  subu      $v1, $v1, $v0
/* DCD08C 802403BC 00031040 */  sll       $v0, $v1, 1
/* DCD090 802403C0 00431021 */  addu      $v0, $v0, $v1
/* DCD094 802403C4 00021900 */  sll       $v1, $v0, 4
/* DCD098 802403C8 00621823 */  subu      $v1, $v1, $v0
/* DCD09C 802403CC 000318C0 */  sll       $v1, $v1, 3
/* DCD0A0 802403D0 02031823 */  subu      $v1, $s0, $v1
/* DCD0A4 802403D4 00640018 */  mult      $v1, $a0
/* DCD0A8 802403D8 00005810 */  mfhi      $t3
/* DCD0AC 802403DC 01631021 */  addu      $v0, $t3, $v1
/* DCD0B0 802403E0 00021143 */  sra       $v0, $v0, 5
/* DCD0B4 802403E4 00031FC3 */  sra       $v1, $v1, 0x1f
/* DCD0B8 802403E8 00431023 */  subu      $v0, $v0, $v1
/* DCD0BC 802403EC 24420008 */  addiu     $v0, $v0, 8
/* DCD0C0 802403F0 00021080 */  sll       $v0, $v0, 2
/* DCD0C4 802403F4 3C018024 */  lui       $at, %hi(D_802451AC_DD1E7C)
/* DCD0C8 802403F8 00220821 */  addu      $at, $at, $v0
/* DCD0CC 802403FC 8C2251AC */  lw        $v0, %lo(D_802451AC_DD1E7C)($at)
/* DCD0D0 80240400 08090103 */  j         .L8024040C
/* DCD0D4 80240404 AFA20014 */   sw       $v0, 0x14($sp)
.L80240408:
/* DCD0D8 80240408 AFA00014 */  sw        $zero, 0x14($sp)
.L8024040C:
/* DCD0DC 8024040C 2402FFFF */  addiu     $v0, $zero, -1
/* DCD0E0 80240410 10A2001B */  beq       $a1, $v0, .L80240480
/* DCD0E4 80240414 3C04B60B */   lui      $a0, 0xb60b
/* DCD0E8 80240418 348460B7 */  ori       $a0, $a0, 0x60b7
/* DCD0EC 8024041C 00A40018 */  mult      $a1, $a0
/* DCD0F0 80240420 000517C3 */  sra       $v0, $a1, 0x1f
/* DCD0F4 80240424 00005810 */  mfhi      $t3
/* DCD0F8 80240428 01651821 */  addu      $v1, $t3, $a1
/* DCD0FC 8024042C 00031A03 */  sra       $v1, $v1, 8
/* DCD100 80240430 00621823 */  subu      $v1, $v1, $v0
/* DCD104 80240434 00031040 */  sll       $v0, $v1, 1
/* DCD108 80240438 00431021 */  addu      $v0, $v0, $v1
/* DCD10C 8024043C 00021900 */  sll       $v1, $v0, 4
/* DCD110 80240440 00621823 */  subu      $v1, $v1, $v0
/* DCD114 80240444 000318C0 */  sll       $v1, $v1, 3
/* DCD118 80240448 00A31823 */  subu      $v1, $a1, $v1
/* DCD11C 8024044C 00640018 */  mult      $v1, $a0
/* DCD120 80240450 00005810 */  mfhi      $t3
/* DCD124 80240454 01631021 */  addu      $v0, $t3, $v1
/* DCD128 80240458 00021143 */  sra       $v0, $v0, 5
/* DCD12C 8024045C 00031FC3 */  sra       $v1, $v1, 0x1f
/* DCD130 80240460 00431023 */  subu      $v0, $v0, $v1
/* DCD134 80240464 24420010 */  addiu     $v0, $v0, 0x10
/* DCD138 80240468 00021080 */  sll       $v0, $v0, 2
/* DCD13C 8024046C 3C018024 */  lui       $at, %hi(D_802451AC_DD1E7C)
/* DCD140 80240470 00220821 */  addu      $at, $at, $v0
/* DCD144 80240474 8C2251AC */  lw        $v0, %lo(D_802451AC_DD1E7C)($at)
/* DCD148 80240478 08090121 */  j         .L80240484
/* DCD14C 8024047C AFA20018 */   sw       $v0, 0x18($sp)
.L80240480:
/* DCD150 80240480 AFA00018 */  sw        $zero, 0x18($sp)
.L80240484:
/* DCD154 80240484 0000482D */  daddu     $t1, $zero, $zero
/* DCD158 80240488 27A80010 */  addiu     $t0, $sp, 0x10
/* DCD15C 8024048C 0100502D */  daddu     $t2, $t0, $zero
.L80240490:
/* DCD160 80240490 24060001 */  addiu     $a2, $zero, 1
/* DCD164 80240494 0100382D */  daddu     $a3, $t0, $zero
/* DCD168 80240498 25450004 */  addiu     $a1, $t2, 4
.L8024049C:
/* DCD16C 8024049C 8CE40000 */  lw        $a0, ($a3)
/* DCD170 802404A0 8CA30000 */  lw        $v1, ($a1)
/* DCD174 802404A4 0064102A */  slt       $v0, $v1, $a0
/* DCD178 802404A8 10400003 */  beqz      $v0, .L802404B8
/* DCD17C 802404AC 24C60001 */   addiu    $a2, $a2, 1
/* DCD180 802404B0 ACE30000 */  sw        $v1, ($a3)
/* DCD184 802404B4 ACA40000 */  sw        $a0, ($a1)
.L802404B8:
/* DCD188 802404B8 28C20003 */  slti      $v0, $a2, 3
/* DCD18C 802404BC 1440FFF7 */  bnez      $v0, .L8024049C
/* DCD190 802404C0 24A50004 */   addiu    $a1, $a1, 4
/* DCD194 802404C4 25290001 */  addiu     $t1, $t1, 1
/* DCD198 802404C8 29220002 */  slti      $v0, $t1, 2
/* DCD19C 802404CC 1440FFF0 */  bnez      $v0, .L80240490
/* DCD1A0 802404D0 25080004 */   addiu    $t0, $t0, 4
/* DCD1A4 802404D4 8FA30014 */  lw        $v1, 0x14($sp)
/* DCD1A8 802404D8 8FA20010 */  lw        $v0, 0x10($sp)
/* DCD1AC 802404DC 14620007 */  bne       $v1, $v0, .L802404FC
/* DCD1B0 802404E0 00000000 */   nop
/* DCD1B4 802404E4 8FA20018 */  lw        $v0, 0x18($sp)
/* DCD1B8 802404E8 14620008 */  bne       $v1, $v0, .L8024050C
/* DCD1BC 802404EC 24020002 */   addiu    $v0, $zero, 2
/* DCD1C0 802404F0 24020003 */  addiu     $v0, $zero, 3
/* DCD1C4 802404F4 08090144 */  j         .L80240510
/* DCD1C8 802404F8 AE4200AC */   sw       $v0, 0xac($s2)
.L802404FC:
/* DCD1CC 802404FC 8FA20018 */  lw        $v0, 0x18($sp)
/* DCD1D0 80240500 54620003 */  bnel      $v1, $v0, .L80240510
/* DCD1D4 80240504 AE4000AC */   sw       $zero, 0xac($s2)
/* DCD1D8 80240508 24020002 */  addiu     $v0, $zero, 2
.L8024050C:
/* DCD1DC 8024050C AE4200AC */  sw        $v0, 0xac($s2)
.L80240510:
/* DCD1E0 80240510 8FA30014 */  lw        $v1, 0x14($sp)
/* DCD1E4 80240514 AE4300B0 */  sw        $v1, 0xb0($s2)
/* DCD1E8 80240518 8FBF002C */  lw        $ra, 0x2c($sp)
/* DCD1EC 8024051C 8FB20028 */  lw        $s2, 0x28($sp)
/* DCD1F0 80240520 8FB10024 */  lw        $s1, 0x24($sp)
/* DCD1F4 80240524 8FB00020 */  lw        $s0, 0x20($sp)
/* DCD1F8 80240528 24020002 */  addiu     $v0, $zero, 2
/* DCD1FC 8024052C 03E00008 */  jr        $ra
/* DCD200 80240530 27BD0030 */   addiu    $sp, $sp, 0x30
