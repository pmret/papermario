.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D4_A4F3D4
/* A4F3D4 802403D4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A4F3D8 802403D8 AFB20038 */  sw        $s2, 0x38($sp)
/* A4F3DC 802403DC 0080902D */  daddu     $s2, $a0, $zero
/* A4F3E0 802403E0 AFBF003C */  sw        $ra, 0x3c($sp)
/* A4F3E4 802403E4 AFB10034 */  sw        $s1, 0x34($sp)
/* A4F3E8 802403E8 AFB00030 */  sw        $s0, 0x30($sp)
/* A4F3EC 802403EC 8E510148 */  lw        $s1, 0x148($s2)
/* A4F3F0 802403F0 0C00EABB */  jal       get_npc_unsafe
/* A4F3F4 802403F4 86240008 */   lh       $a0, 8($s1)
/* A4F3F8 802403F8 0040802D */  daddu     $s0, $v0, $zero
/* A4F3FC 802403FC 9602008E */  lhu       $v0, 0x8e($s0)
/* A4F400 80240400 2442FFFF */  addiu     $v0, $v0, -1
/* A4F404 80240404 A602008E */  sh        $v0, 0x8e($s0)
/* A4F408 80240408 00021400 */  sll       $v0, $v0, 0x10
/* A4F40C 8024040C 1C40002B */  bgtz      $v0, .L802404BC
/* A4F410 80240410 00000000 */   nop      
/* A4F414 80240414 0C090028 */  jal       func_802400A0_A4F0A0
/* A4F418 80240418 0240202D */   daddu    $a0, $s2, $zero
/* A4F41C 8024041C 0040202D */  daddu     $a0, $v0, $zero
/* A4F420 80240420 0481001A */  bgez      $a0, .L8024048C
/* A4F424 80240424 2402000F */   addiu    $v0, $zero, 0xf
/* A4F428 80240428 24040002 */  addiu     $a0, $zero, 2
/* A4F42C 8024042C 860300A8 */  lh        $v1, 0xa8($s0)
/* A4F430 80240430 AFA2001C */  sw        $v0, 0x1c($sp)
/* A4F434 80240434 27A20028 */  addiu     $v0, $sp, 0x28
/* A4F438 80240438 0200282D */  daddu     $a1, $s0, $zero
/* A4F43C 8024043C 3C013F80 */  lui       $at, 0x3f80
/* A4F440 80240440 44810000 */  mtc1      $at, $f0
/* A4F444 80240444 3C014000 */  lui       $at, 0x4000
/* A4F448 80240448 44811000 */  mtc1      $at, $f2
/* A4F44C 8024044C 3C01C1A0 */  lui       $at, 0xc1a0
/* A4F450 80240450 44812000 */  mtc1      $at, $f4
/* A4F454 80240454 44833000 */  mtc1      $v1, $f6
/* A4F458 80240458 00000000 */  nop       
/* A4F45C 8024045C 468031A0 */  cvt.s.w   $f6, $f6
/* A4F460 80240460 44073000 */  mfc1      $a3, $f6
/* A4F464 80240464 0000302D */  daddu     $a2, $zero, $zero
/* A4F468 80240468 AFA20020 */  sw        $v0, 0x20($sp)
/* A4F46C 8024046C E7A00010 */  swc1      $f0, 0x10($sp)
/* A4F470 80240470 E7A20014 */  swc1      $f2, 0x14($sp)
/* A4F474 80240474 0C01BFA4 */  jal       fx_emote
/* A4F478 80240478 E7A40018 */   swc1     $f4, 0x18($sp)
/* A4F47C 8024047C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4F480 80240480 8C420000 */  lw        $v0, ($v0)
/* A4F484 80240484 0809012B */  j         .L802404AC
/* A4F488 80240488 AE020028 */   sw       $v0, 0x28($s0)
.L8024048C:
/* A4F48C 8024048C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4F490 80240490 8C420024 */  lw        $v0, 0x24($v0)
/* A4F494 80240494 0C00FB3A */  jal       get_enemy
/* A4F498 80240498 AE020028 */   sw       $v0, 0x28($s0)
/* A4F49C 8024049C 86240008 */  lh        $a0, 8($s1)
/* A4F4A0 802404A0 24030001 */  addiu     $v1, $zero, 1
/* A4F4A4 802404A4 AC43006C */  sw        $v1, 0x6c($v0)
/* A4F4A8 802404A8 AC44007C */  sw        $a0, 0x7c($v0)
.L802404AC:
/* A4F4AC 802404AC 96220076 */  lhu       $v0, 0x76($s1)
/* A4F4B0 802404B0 A602008E */  sh        $v0, 0x8e($s0)
/* A4F4B4 802404B4 24020021 */  addiu     $v0, $zero, 0x21
/* A4F4B8 802404B8 AE420070 */  sw        $v0, 0x70($s2)
.L802404BC:
/* A4F4BC 802404BC 8FBF003C */  lw        $ra, 0x3c($sp)
/* A4F4C0 802404C0 8FB20038 */  lw        $s2, 0x38($sp)
/* A4F4C4 802404C4 8FB10034 */  lw        $s1, 0x34($sp)
/* A4F4C8 802404C8 8FB00030 */  lw        $s0, 0x30($sp)
/* A4F4CC 802404CC 03E00008 */  jr        $ra
/* A4F4D0 802404D0 27BD0040 */   addiu    $sp, $sp, 0x40
