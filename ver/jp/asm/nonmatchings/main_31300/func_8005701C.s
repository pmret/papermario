.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005701C
/* 3241C 8005701C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 32420 80057020 AFB50024 */  sw        $s5, 0x24($sp)
/* 32424 80057024 00C0A82D */  daddu     $s5, $a2, $zero
/* 32428 80057028 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3242C 8005702C 00A0982D */  daddu     $s3, $a1, $zero
/* 32430 80057030 AFB40020 */  sw        $s4, 0x20($sp)
/* 32434 80057034 00E0A02D */  daddu     $s4, $a3, $zero
/* 32438 80057038 308400FF */  andi      $a0, $a0, 0xff
/* 3243C 8005703C 00041140 */  sll       $v0, $a0, 5
/* 32440 80057040 00441023 */  subu      $v0, $v0, $a0
/* 32444 80057044 3C038008 */  lui       $v1, %hi(D_80078E24)
/* 32448 80057048 8C638E24 */  lw        $v1, %lo(D_80078E24)($v1)
/* 3244C 8005704C 00021080 */  sll       $v0, $v0, 2
/* 32450 80057050 AFBF0028 */  sw        $ra, 0x28($sp)
/* 32454 80057054 AFB20018 */  sw        $s2, 0x18($sp)
/* 32458 80057058 AFB10014 */  sw        $s1, 0x14($sp)
/* 3245C 8005705C AFB00010 */  sw        $s0, 0x10($sp)
/* 32460 80057060 8C63001C */  lw        $v1, 0x1c($v1)
/* 32464 80057064 93B20043 */  lbu       $s2, 0x43($sp)
/* 32468 80057068 00628021 */  addu      $s0, $v1, $v0
/* 3246C 8005706C 8E050064 */  lw        $a1, 0x64($s0)
/* 32470 80057070 8E030068 */  lw        $v1, 0x68($s0)
/* 32474 80057074 00A3102A */  slt       $v0, $a1, $v1
/* 32478 80057078 14400029 */  bnez      $v0, .L80057120
/* 3247C 8005707C 26110048 */   addiu    $s1, $s0, 0x48
/* 32480 80057080 3C028008 */  lui       $v0, %hi(D_80078151)
/* 32484 80057084 24428151 */  addiu     $v0, $v0, %lo(D_80078151)
/* 32488 80057088 90420000 */  lbu       $v0, ($v0)
/* 3248C 8005708C 1440000E */  bnez      $v0, .L800570C8
/* 32490 80057090 AE030064 */   sw       $v1, 0x64($s0)
/* 32494 80057094 3C048008 */  lui       $a0, %hi(D_80078E30)
/* 32498 80057098 24848E30 */  addiu     $a0, $a0, %lo(D_80078E30)
/* 3249C 8005709C 8603004E */  lh        $v1, 0x4e($s0)
/* 324A0 800570A0 84820080 */  lh        $v0, 0x80($a0)
/* 324A4 800570A4 00620018 */  mult      $v1, $v0
/* 324A8 800570A8 00004012 */  mflo      $t0
/* 324AC 800570AC 000813C3 */  sra       $v0, $t0, 0xf
/* 324B0 800570B0 A6020050 */  sh        $v0, 0x50($s0)
/* 324B4 800570B4 84820080 */  lh        $v0, 0x80($a0)
/* 324B8 800570B8 00620018 */  mult      $v1, $v0
/* 324BC 800570BC 00004012 */  mflo      $t0
/* 324C0 800570C0 08015C52 */  j         .L80057148
/* 324C4 800570C4 000813C3 */   sra      $v0, $t0, 0xf
.L800570C8:
/* 324C8 800570C8 8602004C */  lh        $v0, 0x4c($s0)
/* 324CC 800570CC 8603004E */  lh        $v1, 0x4e($s0)
/* 324D0 800570D0 00021040 */  sll       $v0, $v0, 1
/* 324D4 800570D4 3C018008 */  lui       $at, %hi(D_80078E30)
/* 324D8 800570D8 00220821 */  addu      $at, $at, $v0
/* 324DC 800570DC 84228E30 */  lh        $v0, %lo(D_80078E30)($at)
/* 324E0 800570E0 00620018 */  mult      $v1, $v0
/* 324E4 800570E4 8603004C */  lh        $v1, 0x4c($s0)
/* 324E8 800570E8 00004012 */  mflo      $t0
/* 324EC 800570EC 000813C3 */  sra       $v0, $t0, 0xf
/* 324F0 800570F0 A6020050 */  sh        $v0, 0x50($s0)
/* 324F4 800570F4 2402007F */  addiu     $v0, $zero, 0x7f
/* 324F8 800570F8 00431023 */  subu      $v0, $v0, $v1
/* 324FC 800570FC 00021040 */  sll       $v0, $v0, 1
/* 32500 80057100 8603004E */  lh        $v1, 0x4e($s0)
/* 32504 80057104 3C018008 */  lui       $at, %hi(D_80078E30)
/* 32508 80057108 00220821 */  addu      $at, $at, $v0
/* 3250C 8005710C 84228E30 */  lh        $v0, %lo(D_80078E30)($at)
/* 32510 80057110 00620018 */  mult      $v1, $v0
/* 32514 80057114 00004012 */  mflo      $t0
/* 32518 80057118 08015C52 */  j         .L80057148
/* 3251C 8005711C 000813C3 */   sra      $v0, $t0, 0xf
.L80057120:
/* 32520 80057120 86040050 */  lh        $a0, 0x50($s0)
/* 32524 80057124 8606005A */  lh        $a2, 0x5a($s0)
/* 32528 80057128 0C015F2D */  jal       func_80057CB4
/* 3252C 8005712C 96070058 */   lhu      $a3, 0x58($s0)
/* 32530 80057130 86040052 */  lh        $a0, 0x52($s0)
/* 32534 80057134 8E050064 */  lw        $a1, 0x64($s0)
/* 32538 80057138 86060060 */  lh        $a2, 0x60($s0)
/* 3253C 8005713C 9607005E */  lhu       $a3, 0x5e($s0)
/* 32540 80057140 0C015F2D */  jal       func_80057CB4
/* 32544 80057144 A6020050 */   sh       $v0, 0x50($s0)
.L80057148:
/* 32548 80057148 A6020052 */  sh        $v0, 0x52($s0)
/* 3254C 8005714C 86220008 */  lh        $v0, 8($s1)
/* 32550 80057150 14400002 */  bnez      $v0, .L8005715C
/* 32554 80057154 24020001 */   addiu    $v0, $zero, 1
/* 32558 80057158 A6220008 */  sh        $v0, 8($s1)
.L8005715C:
/* 3255C 8005715C 8622000A */  lh        $v0, 0xa($s1)
/* 32560 80057160 14400004 */  bnez      $v0, .L80057174
/* 32564 80057164 00131400 */   sll      $v0, $s3, 0x10
/* 32568 80057168 24020001 */  addiu     $v0, $zero, 1
/* 3256C 8005716C A622000A */  sh        $v0, 0xa($s1)
/* 32570 80057170 00131400 */  sll       $v0, $s3, 0x10
.L80057174:
/* 32574 80057174 00021403 */  sra       $v0, $v0, 0x10
/* 32578 80057178 00420018 */  mult      $v0, $v0
/* 3257C 8005717C 328200FF */  andi      $v0, $s4, 0xff
/* 32580 80057180 324300FF */  andi      $v1, $s2, 0xff
/* 32584 80057184 AE20001C */  sw        $zero, 0x1c($s1)
/* 32588 80057188 AE350020 */  sw        $s5, 0x20($s1)
/* 3258C 8005718C A6220004 */  sh        $v0, 4($s1)
/* 32590 80057190 00004012 */  mflo      $t0
/* 32594 80057194 000813C3 */  sra       $v0, $t0, 0xf
/* 32598 80057198 A6220006 */  sh        $v0, 6($s1)
/* 3259C 8005719C 00031040 */  sll       $v0, $v1, 1
/* 325A0 800571A0 3C018008 */  lui       $at, %hi(D_80078E30)
/* 325A4 800571A4 00220821 */  addu      $at, $at, $v0
/* 325A8 800571A8 94228E30 */  lhu       $v0, %lo(D_80078E30)($at)
/* 325AC 800571AC A622000C */  sh        $v0, 0xc($s1)
/* 325B0 800571B0 2402007F */  addiu     $v0, $zero, 0x7f
/* 325B4 800571B4 00431023 */  subu      $v0, $v0, $v1
/* 325B8 800571B8 00021040 */  sll       $v0, $v0, 1
/* 325BC 800571BC 3C038008 */  lui       $v1, %hi(D_80078E30)
/* 325C0 800571C0 00621821 */  addu      $v1, $v1, $v0
/* 325C4 800571C4 94638E30 */  lhu       $v1, %lo(D_80078E30)($v1)
/* 325C8 800571C8 24020001 */  addiu     $v0, $zero, 1
/* 325CC 800571CC AE220024 */  sw        $v0, 0x24($s1)
/* 325D0 800571D0 A623000E */  sh        $v1, 0xe($s1)
/* 325D4 800571D4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 325D8 800571D8 8FB50024 */  lw        $s5, 0x24($sp)
/* 325DC 800571DC 8FB40020 */  lw        $s4, 0x20($sp)
/* 325E0 800571E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 325E4 800571E4 8FB20018 */  lw        $s2, 0x18($sp)
/* 325E8 800571E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 325EC 800571EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 325F0 800571F0 03E00008 */  jr        $ra
/* 325F4 800571F4 27BD0030 */   addiu    $sp, $sp, 0x30
