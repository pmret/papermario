.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_320C50
/* 320C50 802BD100 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 320C54 802BD104 2404FFFC */  addiu     $a0, $zero, -4
/* 320C58 802BD108 AFB10014 */  sw        $s1, 0x14($sp)
/* 320C5C 802BD10C 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 320C60 802BD110 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 320C64 802BD114 AFBF0018 */  sw        $ra, 0x18($sp)
/* 320C68 802BD118 0C00EABB */  jal       get_npc_unsafe
/* 320C6C 802BD11C AFB00010 */   sw       $s0, 0x10($sp)
/* 320C70 802BD120 8E230000 */  lw        $v1, ($s1)
/* 320C74 802BD124 0040802D */  daddu     $s0, $v0, $zero
/* 320C78 802BD128 30624000 */  andi      $v0, $v1, 0x4000
/* 320C7C 802BD12C 10400010 */  beqz      $v0, .L802BD170
/* 320C80 802BD130 3C020004 */   lui      $v0, 4
/* 320C84 802BD134 C6220054 */  lwc1      $f2, 0x54($s1)
/* 320C88 802BD138 00621024 */  and       $v0, $v1, $v0
/* 320C8C 802BD13C 10400006 */  beqz      $v0, .L802BD158
/* 320C90 802BD140 26040038 */   addiu    $a0, $s0, 0x38
/* 320C94 802BD144 3C013F00 */  lui       $at, 0x3f00
/* 320C98 802BD148 44810000 */  mtc1      $at, $f0
/* 320C9C 802BD14C 00000000 */  nop
/* 320CA0 802BD150 46001082 */  mul.s     $f2, $f2, $f0
/* 320CA4 802BD154 00000000 */  nop
.L802BD158:
/* 320CA8 802BD158 44061000 */  mfc1      $a2, $f2
/* 320CAC 802BD15C 8E2700A0 */  lw        $a3, 0xa0($s1)
/* 320CB0 802BD160 0C00A7E7 */  jal       add_vec2D_polar
/* 320CB4 802BD164 26050040 */   addiu    $a1, $s0, 0x40
/* 320CB8 802BD168 C6200080 */  lwc1      $f0, 0x80($s1)
/* 320CBC 802BD16C E600000C */  swc1      $f0, 0xc($s0)
.L802BD170:
/* 320CC0 802BD170 26240028 */  addiu     $a0, $s1, 0x28
/* 320CC4 802BD174 3C02802C */  lui       $v0, %hi(D_802BFF18)
/* 320CC8 802BD178 8C42FF18 */  lw        $v0, %lo(D_802BFF18)($v0)
/* 320CCC 802BD17C 3C013EAE */  lui       $at, 0x3eae
/* 320CD0 802BD180 3421147B */  ori       $at, $at, 0x147b
/* 320CD4 802BD184 44810000 */  mtc1      $at, $f0
/* 320CD8 802BD188 C6020038 */  lwc1      $f2, 0x38($s0)
/* 320CDC 802BD18C 3C064000 */  lui       $a2, 0x4000
/* 320CE0 802BD190 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 320CE4 802BD194 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 320CE8 802BD198 04420001 */  bltzl     $v0, .L802BD1A0
/* 320CEC 802BD19C 00021023 */   negu     $v0, $v0
.L802BD1A0:
/* 320CF0 802BD1A0 44822000 */  mtc1      $v0, $f4
/* 320CF4 802BD1A4 00000000 */  nop
/* 320CF8 802BD1A8 46802120 */  cvt.s.w   $f4, $f4
/* 320CFC 802BD1AC 00031080 */  sll       $v0, $v1, 2
/* 320D00 802BD1B0 46002102 */  mul.s     $f4, $f4, $f0
/* 320D04 802BD1B4 00000000 */  nop
/* 320D08 802BD1B8 E6220028 */  swc1      $f2, 0x28($s1)
/* 320D0C 802BD1BC C600003C */  lwc1      $f0, 0x3c($s0)
/* 320D10 802BD1C0 3C014120 */  lui       $at, 0x4120
/* 320D14 802BD1C4 44811000 */  mtc1      $at, $f2
/* 320D18 802BD1C8 00431021 */  addu      $v0, $v0, $v1
/* 320D1C 802BD1CC 46020000 */  add.s     $f0, $f0, $f2
/* 320D20 802BD1D0 00021080 */  sll       $v0, $v0, 2
/* 320D24 802BD1D4 00431023 */  subu      $v0, $v0, $v1
/* 320D28 802BD1D8 46040000 */  add.s     $f0, $f0, $f4
/* 320D2C 802BD1DC 000218C0 */  sll       $v1, $v0, 3
/* 320D30 802BD1E0 00431021 */  addu      $v0, $v0, $v1
/* 320D34 802BD1E4 E620002C */  swc1      $f0, 0x2c($s1)
/* 320D38 802BD1E8 C6000040 */  lwc1      $f0, 0x40($s0)
/* 320D3C 802BD1EC 000210C0 */  sll       $v0, $v0, 3
/* 320D40 802BD1F0 E6200030 */  swc1      $f0, 0x30($s1)
/* 320D44 802BD1F4 3C07800B */  lui       $a3, %hi(gCameras+0x6C)
/* 320D48 802BD1F8 00E23821 */  addu      $a3, $a3, $v0
/* 320D4C 802BD1FC 8CE71DEC */  lw        $a3, %lo(gCameras+0x6C)($a3)
/* 320D50 802BD200 0C00A7E7 */  jal       add_vec2D_polar
/* 320D54 802BD204 26250030 */   addiu    $a1, $s1, 0x30
/* 320D58 802BD208 8FBF0018 */  lw        $ra, 0x18($sp)
/* 320D5C 802BD20C 8FB10014 */  lw        $s1, 0x14($sp)
/* 320D60 802BD210 8FB00010 */  lw        $s0, 0x10($sp)
/* 320D64 802BD214 03E00008 */  jr        $ra
/* 320D68 802BD218 27BD0020 */   addiu    $sp, $sp, 0x20
