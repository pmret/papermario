.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024037C_A5629C
/* A5629C 8024037C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A562A0 80240380 AFB10014 */  sw        $s1, 0x14($sp)
/* A562A4 80240384 0080882D */  daddu     $s1, $a0, $zero
/* A562A8 80240388 AFBF0018 */  sw        $ra, 0x18($sp)
/* A562AC 8024038C AFB00010 */  sw        $s0, 0x10($sp)
/* A562B0 80240390 8E30000C */  lw        $s0, 0xc($s1)
/* A562B4 80240394 8E050000 */  lw        $a1, ($s0)
/* A562B8 80240398 0C0B1EAF */  jal       get_variable
/* A562BC 8024039C 26100004 */   addiu    $s0, $s0, 4
/* A562C0 802403A0 0220202D */  daddu     $a0, $s1, $zero
/* A562C4 802403A4 8E050000 */  lw        $a1, ($s0)
/* A562C8 802403A8 0C0B1EAF */  jal       get_variable
/* A562CC 802403AC 0040882D */   daddu    $s1, $v0, $zero
/* A562D0 802403B0 0040802D */  daddu     $s0, $v0, $zero
/* A562D4 802403B4 3C038016 */  lui       $v1, %hi(gCollisionStatus)
/* A562D8 802403B8 2463A550 */  addiu     $v1, $v1, %lo(gCollisionStatus)
/* A562DC 802403BC 84620002 */  lh        $v0, 2($v1)
/* A562E0 802403C0 10500004 */  beq       $v0, $s0, .L802403D4
/* A562E4 802403C4 00000000 */   nop
/* A562E8 802403C8 84620004 */  lh        $v0, 4($v1)
/* A562EC 802403CC 14500007 */  bne       $v0, $s0, .L802403EC
/* A562F0 802403D0 00000000 */   nop
.L802403D4:
/* A562F4 802403D4 44910000 */  mtc1      $s1, $f0
/* A562F8 802403D8 00000000 */  nop
/* A562FC 802403DC 46800020 */  cvt.s.w   $f0, $f0
/* A56300 802403E0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* A56304 802403E4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* A56308 802403E8 E440001C */  swc1      $f0, 0x1c($v0)
.L802403EC:
/* A5630C 802403EC 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* A56310 802403F0 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* A56314 802403F4 1040000D */  beqz      $v0, .L8024042C
/* A56318 802403F8 00000000 */   nop
/* A5631C 802403FC 0C00EABB */  jal       get_npc_unsafe
/* A56320 80240400 2404FFFC */   addiu    $a0, $zero, -4
/* A56324 80240404 0040182D */  daddu     $v1, $v0, $zero
/* A56328 80240408 84620084 */  lh        $v0, 0x84($v1)
/* A5632C 8024040C 14500007 */  bne       $v0, $s0, .L8024042C
/* A56330 80240410 00000000 */   nop
/* A56334 80240414 C4600038 */  lwc1      $f0, 0x38($v1)
/* A56338 80240418 44911000 */  mtc1      $s1, $f2
/* A5633C 8024041C 00000000 */  nop
/* A56340 80240420 468010A0 */  cvt.s.w   $f2, $f2
/* A56344 80240424 46020000 */  add.s     $f0, $f0, $f2
/* A56348 80240428 E4600038 */  swc1      $f0, 0x38($v1)
.L8024042C:
/* A5634C 8024042C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A56350 80240430 8FB10014 */  lw        $s1, 0x14($sp)
/* A56354 80240434 8FB00010 */  lw        $s0, 0x10($sp)
/* A56358 80240438 24020002 */  addiu     $v0, $zero, 2
/* A5635C 8024043C 03E00008 */  jr        $ra
/* A56360 80240440 27BD0020 */   addiu    $sp, $sp, 0x20
