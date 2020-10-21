.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402CC_BCEEBC
/* BCEEBC 802402CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCEEC0 802402D0 AFB10014 */  sw        $s1, 0x14($sp)
/* BCEEC4 802402D4 0080882D */  daddu     $s1, $a0, $zero
/* BCEEC8 802402D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* BCEECC 802402DC AFB00010 */  sw        $s0, 0x10($sp)
/* BCEED0 802402E0 0C00EAD2 */  jal       get_npc_safe
/* BCEED4 802402E4 8E24014C */   lw       $a0, 0x14c($s1)
/* BCEED8 802402E8 0040802D */  daddu     $s0, $v0, $zero
/* BCEEDC 802402EC 8E230074 */  lw        $v1, 0x74($s1)
/* BCEEE0 802402F0 24020001 */  addiu     $v0, $zero, 1
/* BCEEE4 802402F4 10620036 */  beq       $v1, $v0, .L802403D0
/* BCEEE8 802402F8 28620002 */   slti     $v0, $v1, 2
/* BCEEEC 802402FC 10400005 */  beqz      $v0, .L80240314
/* BCEEF0 80240300 24020002 */   addiu    $v0, $zero, 2
/* BCEEF4 80240304 10600007 */  beqz      $v1, .L80240324
/* BCEEF8 80240308 00000000 */   nop      
/* BCEEFC 8024030C 0809010F */  j         .L8024043C
/* BCEF00 80240310 00000000 */   nop      
.L80240314:
/* BCEF04 80240314 10620036 */  beq       $v1, $v0, .L802403F0
/* BCEF08 80240318 00000000 */   nop      
/* BCEF0C 8024031C 0809010F */  j         .L8024043C
/* BCEF10 80240320 00000000 */   nop      
.L80240324:
/* BCEF14 80240324 0C00A67F */  jal       rand_int
/* BCEF18 80240328 240400B4 */   addiu    $a0, $zero, 0xb4
/* BCEF1C 8024032C 24040032 */  addiu     $a0, $zero, 0x32
/* BCEF20 80240330 3C01C396 */  lui       $at, 0xc396
/* BCEF24 80240334 44810000 */  mtc1      $at, $f0
/* BCEF28 80240338 2442001E */  addiu     $v0, $v0, 0x1e
/* BCEF2C 8024033C A602008E */  sh        $v0, 0x8e($s0)
/* BCEF30 80240340 0C00A67F */  jal       rand_int
/* BCEF34 80240344 E6000040 */   swc1     $f0, 0x40($s0)
/* BCEF38 80240348 3C0142A0 */  lui       $at, 0x42a0
/* BCEF3C 8024034C 44811000 */  mtc1      $at, $f2
/* BCEF40 80240350 44820000 */  mtc1      $v0, $f0
/* BCEF44 80240354 00000000 */  nop       
/* BCEF48 80240358 46800020 */  cvt.s.w   $f0, $f0
/* BCEF4C 8024035C 46020000 */  add.s     $f0, $f0, $f2
/* BCEF50 80240360 0C00A64D */  jal       func_80029934
/* BCEF54 80240364 E600003C */   swc1     $f0, 0x3c($s0)
/* BCEF58 80240368 46000000 */  add.s     $f0, $f0, $f0
/* BCEF5C 8024036C 3C014000 */  lui       $at, 0x4000
/* BCEF60 80240370 44811000 */  mtc1      $at, $f2
/* BCEF64 80240374 00000000 */  nop       
/* BCEF68 80240378 46020000 */  add.s     $f0, $f0, $f2
/* BCEF6C 8024037C 24040064 */  addiu     $a0, $zero, 0x64
/* BCEF70 80240380 0C00A67F */  jal       rand_int
/* BCEF74 80240384 E6000018 */   swc1     $f0, 0x18($s0)
/* BCEF78 80240388 28420032 */  slti      $v0, $v0, 0x32
/* BCEF7C 8024038C 10400007 */  beqz      $v0, .L802403AC
/* BCEF80 80240390 00000000 */   nop      
/* BCEF84 80240394 3C014387 */  lui       $at, 0x4387
/* BCEF88 80240398 44810000 */  mtc1      $at, $f0
/* BCEF8C 8024039C 00000000 */  nop       
/* BCEF90 802403A0 E6000038 */  swc1      $f0, 0x38($s0)
/* BCEF94 802403A4 080900F1 */  j         .L802403C4
/* BCEF98 802403A8 E600000C */   swc1     $f0, 0xc($s0)
.L802403AC:
/* BCEF9C 802403AC 3C01C387 */  lui       $at, 0xc387
/* BCEFA0 802403B0 44810000 */  mtc1      $at, $f0
/* BCEFA4 802403B4 3C0142B4 */  lui       $at, 0x42b4
/* BCEFA8 802403B8 44811000 */  mtc1      $at, $f2
/* BCEFAC 802403BC E6000038 */  swc1      $f0, 0x38($s0)
/* BCEFB0 802403C0 E602000C */  swc1      $f2, 0xc($s0)
.L802403C4:
/* BCEFB4 802403C4 24020001 */  addiu     $v0, $zero, 1
/* BCEFB8 802403C8 0809010F */  j         .L8024043C
/* BCEFBC 802403CC AE220074 */   sw       $v0, 0x74($s1)
.L802403D0:
/* BCEFC0 802403D0 9602008E */  lhu       $v0, 0x8e($s0)
/* BCEFC4 802403D4 2442FFFF */  addiu     $v0, $v0, -1
/* BCEFC8 802403D8 A602008E */  sh        $v0, 0x8e($s0)
/* BCEFCC 802403DC 00021400 */  sll       $v0, $v0, 0x10
/* BCEFD0 802403E0 14400016 */  bnez      $v0, .L8024043C
/* BCEFD4 802403E4 24020002 */   addiu    $v0, $zero, 2
/* BCEFD8 802403E8 0809010F */  j         .L8024043C
/* BCEFDC 802403EC AE220074 */   sw       $v0, 0x74($s1)
.L802403F0:
/* BCEFE0 802403F0 8E050018 */  lw        $a1, 0x18($s0)
/* BCEFE4 802403F4 8E06000C */  lw        $a2, 0xc($s0)
/* BCEFE8 802403F8 0C00EA95 */  jal       npc_move_heading
/* BCEFEC 802403FC 0200202D */   daddu    $a0, $s0, $zero
/* BCEFF0 80240400 C6020038 */  lwc1      $f2, 0x38($s0)
/* BCEFF4 80240404 3C01C38C */  lui       $at, 0xc38c
/* BCEFF8 80240408 44810000 */  mtc1      $at, $f0
/* BCEFFC 8024040C 00000000 */  nop       
/* BCF000 80240410 4600103C */  c.lt.s    $f2, $f0
/* BCF004 80240414 00000000 */  nop       
/* BCF008 80240418 45030008 */  bc1tl     .L8024043C
/* BCF00C 8024041C AE200074 */   sw       $zero, 0x74($s1)
/* BCF010 80240420 3C01438C */  lui       $at, 0x438c
/* BCF014 80240424 44810000 */  mtc1      $at, $f0
/* BCF018 80240428 00000000 */  nop       
/* BCF01C 8024042C 4602003C */  c.lt.s    $f0, $f2
/* BCF020 80240430 00000000 */  nop       
/* BCF024 80240434 45030001 */  bc1tl     .L8024043C
/* BCF028 80240438 AE200074 */   sw       $zero, 0x74($s1)
.L8024043C:
/* BCF02C 8024043C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCF030 80240440 8FB10014 */  lw        $s1, 0x14($sp)
/* BCF034 80240444 8FB00010 */  lw        $s0, 0x10($sp)
/* BCF038 80240448 24020002 */  addiu     $v0, $zero, 2
/* BCF03C 8024044C 03E00008 */  jr        $ra
/* BCF040 80240450 27BD0020 */   addiu    $sp, $sp, 0x20
