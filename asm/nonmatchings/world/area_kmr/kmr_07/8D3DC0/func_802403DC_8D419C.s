.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403DC_8D419C
/* 8D419C 802403DC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8D41A0 802403E0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8D41A4 802403E4 0080982D */  daddu     $s3, $a0, $zero
/* 8D41A8 802403E8 AFBF0040 */  sw        $ra, 0x40($sp)
/* 8D41AC 802403EC AFB20038 */  sw        $s2, 0x38($sp)
/* 8D41B0 802403F0 AFB10034 */  sw        $s1, 0x34($sp)
/* 8D41B4 802403F4 AFB00030 */  sw        $s0, 0x30($sp)
/* 8D41B8 802403F8 8E720148 */  lw        $s2, 0x148($s3)
/* 8D41BC 802403FC 00A0882D */  daddu     $s1, $a1, $zero
/* 8D41C0 80240400 86440008 */  lh        $a0, 8($s2)
/* 8D41C4 80240404 0C00EABB */  jal       get_npc_unsafe
/* 8D41C8 80240408 00C0802D */   daddu    $s0, $a2, $zero
/* 8D41CC 8024040C 0200202D */  daddu     $a0, $s0, $zero
/* 8D41D0 80240410 0240282D */  daddu     $a1, $s2, $zero
/* 8D41D4 80240414 24030001 */  addiu     $v1, $zero, 1
/* 8D41D8 80240418 AFA30010 */  sw        $v1, 0x10($sp)
/* 8D41DC 8024041C 8E260018 */  lw        $a2, 0x18($s1)
/* 8D41E0 80240420 8E27001C */  lw        $a3, 0x1c($s1)
/* 8D41E4 80240424 0C01242D */  jal       func_800490B4
/* 8D41E8 80240428 0040802D */   daddu    $s0, $v0, $zero
/* 8D41EC 8024042C 1440001D */  bnez      $v0, .L802404A4
/* 8D41F0 80240430 24040002 */   addiu    $a0, $zero, 2
/* 8D41F4 80240434 0200282D */  daddu     $a1, $s0, $zero
/* 8D41F8 80240438 0000302D */  daddu     $a2, $zero, $zero
/* 8D41FC 8024043C 860300A8 */  lh        $v1, 0xa8($s0)
/* 8D4200 80240440 3C013F80 */  lui       $at, 0x3f80
/* 8D4204 80240444 44810000 */  mtc1      $at, $f0
/* 8D4208 80240448 3C014000 */  lui       $at, 0x4000
/* 8D420C 8024044C 44811000 */  mtc1      $at, $f2
/* 8D4210 80240450 3C01C1A0 */  lui       $at, 0xc1a0
/* 8D4214 80240454 44812000 */  mtc1      $at, $f4
/* 8D4218 80240458 2402000F */  addiu     $v0, $zero, 0xf
/* 8D421C 8024045C AFA2001C */  sw        $v0, 0x1c($sp)
/* 8D4220 80240460 44833000 */  mtc1      $v1, $f6
/* 8D4224 80240464 00000000 */  nop       
/* 8D4228 80240468 468031A0 */  cvt.s.w   $f6, $f6
/* 8D422C 8024046C 44073000 */  mfc1      $a3, $f6
/* 8D4230 80240470 27A20028 */  addiu     $v0, $sp, 0x28
/* 8D4234 80240474 AFA20020 */  sw        $v0, 0x20($sp)
/* 8D4238 80240478 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8D423C 8024047C E7A20014 */  swc1      $f2, 0x14($sp)
/* 8D4240 80240480 0C01BFA4 */  jal       fx_emote
/* 8D4244 80240484 E7A40018 */   swc1     $f4, 0x18($sp)
/* 8D4248 80240488 8E4200CC */  lw        $v0, 0xcc($s2)
/* 8D424C 8024048C 8C430000 */  lw        $v1, ($v0)
/* 8D4250 80240490 24020019 */  addiu     $v0, $zero, 0x19
/* 8D4254 80240494 A602008E */  sh        $v0, 0x8e($s0)
/* 8D4258 80240498 2402000E */  addiu     $v0, $zero, 0xe
/* 8D425C 8024049C 08090136 */  j         .L802404D8
/* 8D4260 802404A0 AE030028 */   sw       $v1, 0x28($s0)
.L802404A4:
/* 8D4264 802404A4 8E050018 */  lw        $a1, 0x18($s0)
/* 8D4268 802404A8 8E06000C */  lw        $a2, 0xc($s0)
/* 8D426C 802404AC 0C00EA95 */  jal       npc_move_heading
/* 8D4270 802404B0 0200202D */   daddu    $a0, $s0, $zero
/* 8D4274 802404B4 0200202D */  daddu     $a0, $s0, $zero
/* 8D4278 802404B8 0C00F598 */  jal       func_8003D660
/* 8D427C 802404BC 24050001 */   addiu    $a1, $zero, 1
/* 8D4280 802404C0 9602008E */  lhu       $v0, 0x8e($s0)
/* 8D4284 802404C4 2442FFFF */  addiu     $v0, $v0, -1
/* 8D4288 802404C8 A602008E */  sh        $v0, 0x8e($s0)
/* 8D428C 802404CC 00021400 */  sll       $v0, $v0, 0x10
/* 8D4290 802404D0 14400002 */  bnez      $v0, .L802404DC
/* 8D4294 802404D4 2402000C */   addiu    $v0, $zero, 0xc
.L802404D8:
/* 8D4298 802404D8 AE620070 */  sw        $v0, 0x70($s3)
.L802404DC:
/* 8D429C 802404DC 8FBF0040 */  lw        $ra, 0x40($sp)
/* 8D42A0 802404E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8D42A4 802404E4 8FB20038 */  lw        $s2, 0x38($sp)
/* 8D42A8 802404E8 8FB10034 */  lw        $s1, 0x34($sp)
/* 8D42AC 802404EC 8FB00030 */  lw        $s0, 0x30($sp)
/* 8D42B0 802404F0 03E00008 */  jr        $ra
/* 8D42B4 802404F4 27BD0048 */   addiu    $sp, $sp, 0x48
