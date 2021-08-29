.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403DC_C5AB1C
/* C5AB1C 802403DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C5AB20 802403E0 AFB10014 */  sw        $s1, 0x14($sp)
/* C5AB24 802403E4 0080882D */  daddu     $s1, $a0, $zero
/* C5AB28 802403E8 AFBF001C */  sw        $ra, 0x1c($sp)
/* C5AB2C 802403EC AFB20018 */  sw        $s2, 0x18($sp)
/* C5AB30 802403F0 AFB00010 */  sw        $s0, 0x10($sp)
/* C5AB34 802403F4 8E30000C */  lw        $s0, 0xc($s1)
/* C5AB38 802403F8 8E050000 */  lw        $a1, ($s0)
/* C5AB3C 802403FC 0C0B1EAF */  jal       evt_get_variable
/* C5AB40 80240400 26100004 */   addiu    $s0, $s0, 4
/* C5AB44 80240404 8E050000 */  lw        $a1, ($s0)
/* C5AB48 80240408 26100004 */  addiu     $s0, $s0, 4
/* C5AB4C 8024040C 0220202D */  daddu     $a0, $s1, $zero
/* C5AB50 80240410 0C0B1EAF */  jal       evt_get_variable
/* C5AB54 80240414 0040902D */   daddu    $s2, $v0, $zero
/* C5AB58 80240418 0220202D */  daddu     $a0, $s1, $zero
/* C5AB5C 8024041C 8E050000 */  lw        $a1, ($s0)
/* C5AB60 80240420 0C0B1EAF */  jal       evt_get_variable
/* C5AB64 80240424 0040882D */   daddu    $s1, $v0, $zero
/* C5AB68 80240428 0040802D */  daddu     $s0, $v0, $zero
/* C5AB6C 8024042C 3C028016 */  lui       $v0, %hi(gCollisionStatus)
/* C5AB70 80240430 2442A550 */  addiu     $v0, $v0, %lo(gCollisionStatus)
/* C5AB74 80240434 84430002 */  lh        $v1, 2($v0)
/* C5AB78 80240438 10710008 */  beq       $v1, $s1, .L8024045C
/* C5AB7C 8024043C 00000000 */   nop
/* C5AB80 80240440 84420004 */  lh        $v0, 4($v0)
/* C5AB84 80240444 10510005 */  beq       $v0, $s1, .L8024045C
/* C5AB88 80240448 00000000 */   nop
/* C5AB8C 8024044C 10700003 */  beq       $v1, $s0, .L8024045C
/* C5AB90 80240450 00000000 */   nop
/* C5AB94 80240454 14500007 */  bne       $v0, $s0, .L80240474
/* C5AB98 80240458 00000000 */   nop
.L8024045C:
/* C5AB9C 8024045C 44920000 */  mtc1      $s2, $f0
/* C5ABA0 80240460 00000000 */  nop
/* C5ABA4 80240464 46800020 */  cvt.s.w   $f0, $f0
/* C5ABA8 80240468 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C5ABAC 8024046C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* C5ABB0 80240470 E440001C */  swc1      $f0, 0x1c($v0)
.L80240474:
/* C5ABB4 80240474 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* C5ABB8 80240478 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* C5ABBC 8024047C 1040000E */  beqz      $v0, .L802404B8
/* C5ABC0 80240480 00000000 */   nop
/* C5ABC4 80240484 0C00EABB */  jal       get_npc_unsafe
/* C5ABC8 80240488 2404FFFC */   addiu    $a0, $zero, -4
/* C5ABCC 8024048C 84430084 */  lh        $v1, 0x84($v0)
/* C5ABD0 80240490 10710003 */  beq       $v1, $s1, .L802404A0
/* C5ABD4 80240494 00000000 */   nop
/* C5ABD8 80240498 14700007 */  bne       $v1, $s0, .L802404B8
/* C5ABDC 8024049C 00000000 */   nop
.L802404A0:
/* C5ABE0 802404A0 C4400038 */  lwc1      $f0, 0x38($v0)
/* C5ABE4 802404A4 44921000 */  mtc1      $s2, $f2
/* C5ABE8 802404A8 00000000 */  nop
/* C5ABEC 802404AC 468010A0 */  cvt.s.w   $f2, $f2
/* C5ABF0 802404B0 46020000 */  add.s     $f0, $f0, $f2
/* C5ABF4 802404B4 E4400038 */  swc1      $f0, 0x38($v0)
.L802404B8:
/* C5ABF8 802404B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* C5ABFC 802404BC 8FB20018 */  lw        $s2, 0x18($sp)
/* C5AC00 802404C0 8FB10014 */  lw        $s1, 0x14($sp)
/* C5AC04 802404C4 8FB00010 */  lw        $s0, 0x10($sp)
/* C5AC08 802404C8 24020002 */  addiu     $v0, $zero, 2
/* C5AC0C 802404CC 03E00008 */  jr        $ra
/* C5AC10 802404D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* C5AC14 802404D4 00000000 */  nop
/* C5AC18 802404D8 00000000 */  nop
/* C5AC1C 802404DC 00000000 */  nop
